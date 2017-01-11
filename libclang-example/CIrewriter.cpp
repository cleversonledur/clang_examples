
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <vector>
#include <system_error>
#include <iostream>
#include <algorithm>
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/IntrusiveRefCntPtr.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/FileSystem.h"

#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Basic/TargetOptions.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Lex/Preprocessor.h"
#include "clang/Lex/Lexer.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/Parse/ParseAST.h"
#include "clang/Rewrite/Frontend/Rewriters.h"
#include "clang/Rewrite/Core/Rewriter.h"

using namespace clang;

std::vector<std::string> argument_list;
std::vector<std::string> argument_type;

#include "InfoCollector.h"
#include "Transformator.h"

int main(int argc, char **argv)
{
  
  if (argc < 2)
  {
     llvm::errs() << "Usage: CIrewriter <options> <filename>\n";
     return 1;
  }

  // Get filename
  std::string fileName(argv[argc - 1]);

  CompilerInstance compiler;
  DiagnosticOptions diagnosticOptions;
  compiler.createDiagnostics();
  //compiler.createDiagnostics(argc, argv);

  // Create an invocation that passes any flags to preprocessor
  CompilerInvocation *Invocation = new CompilerInvocation;
  CompilerInvocation::CreateFromArgs(*Invocation, argv + 1, argv + argc,
                                      compiler.getDiagnostics());
  compiler.setInvocation(Invocation);

  // Set default target triple
    std::shared_ptr<clang::TargetOptions> pto = std::make_shared<clang::TargetOptions>();
  pto->Triple = llvm::sys::getDefaultTargetTriple();
    TargetInfo *pti = TargetInfo::CreateTargetInfo(compiler.getDiagnostics(), pto);
  compiler.setTarget(pti);

  compiler.createFileManager();
  compiler.createSourceManager(compiler.getFileManager());

  // Allow C++ code to get rewritten
  LangOptions langOpts;
  //langOpts.GNUMode = 1; 
  //langOpts.CXXExceptions = 1; 
  //langOpts.RTTI = 1; 
  //langOpts.Bool = 1; 
  //langOpts.CPlusPlus = 1; 
  Invocation->setLangDefaults(langOpts,
                              clang::IK_CXX,
                              clang::LangStandard::lang_cxx1y);

  compiler.createPreprocessor(clang::TU_Complete);
  compiler.getPreprocessorOpts().UsePredefines = false;

  compiler.createASTContext();

  // Initialize rewriter
  Rewriter Rewrite;
  Rewrite.setSourceMgr(compiler.getSourceManager(), compiler.getLangOpts());

  const FileEntry *pFile = compiler.getFileManager().getFile(fileName);
    compiler.getSourceManager().setMainFileID( compiler.getSourceManager().createFileID( pFile, clang::SourceLocation(), clang::SrcMgr::C_User));
  compiler.getDiagnosticClient().BeginSourceFile(compiler.getLangOpts(),
                                                &compiler.getPreprocessor());

  InfoCollectorConsumer infoCollectorAstConsumer(Rewrite);
  TransformatorConsumer transformatorConsumer(Rewrite); 

  // Convert <file>.c to <file_out>.c
  std::string outName (fileName);
  size_t ext = outName.rfind(".");
  if (ext == std::string::npos)
     ext = outName.length();
  outName.insert(ext, "_out");

  llvm::errs() << "Output to: " << outName << "\n";
  std::error_code OutErrorInfo;
  std::error_code ok;
  llvm::raw_fd_ostream outFile(llvm::StringRef(outName), OutErrorInfo, llvm::sys::fs::F_None);

  if (OutErrorInfo == ok)
  {
    // Parse the AST
    ParseAST(compiler.getPreprocessor(), &infoCollectorAstConsumer, compiler.getASTContext());
    compiler.getDiagnosticClient().EndSourceFile();

    ParseAST(compiler.getPreprocessor(), &transformatorConsumer, compiler.getASTContext());
    compiler.getDiagnosticClient().EndSourceFile();


    // Now output rewritten source code
    const RewriteBuffer *RewriteBuf =
      Rewrite.getRewriteBufferFor(compiler.getSourceManager().getMainFileID());
    outFile << std::string(RewriteBuf->begin(), RewriteBuf->end());
    std::cout << std::string(RewriteBuf->begin(), RewriteBuf->end()) << std::endl;
  }
  else
  {
    llvm::errs() << "Cannot open " << outName << " for writing\n";
  }

  outFile.close();

  return 0;
}

