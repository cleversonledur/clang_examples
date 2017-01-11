
class TransformatorRecursiveASTVisitor
    : public RecursiveASTVisitor<TransformatorRecursiveASTVisitor>
{

 public:
  TransformatorRecursiveASTVisitor(Rewriter &R) : Rewrite(R) { }
  CallExpr * firstFunctionCall = nullptr;
  FunctionDecl * firstFunctionDecl = nullptr;
  bool insideMain = false;
  //visitors declarations...
  bool VisitFunctionDecl(FunctionDecl *E);
  bool VisitDeclRefExpr(DeclRefExpr *E);
  bool VisitCallExpr(CallExpr *E);
  bool VisitorCXXOperatorCallExpr( const CXXOperatorCallExpr *E);
  Rewriter &Rewrite;
};


bool TransformatorRecursiveASTVisitor::VisitFunctionDecl(FunctionDecl *E)
{
    if(firstFunctionDecl==nullptr){
        firstFunctionDecl=E;
        std::string struct_declaration = "typedef struct{\n";
        for(unsigned int i = 0; i< argument_list.size();i++){
            std::cout << "Inserting trasformation " << i << "\n";

            struct_declaration = struct_declaration + "\t" + argument_type[i];
            struct_declaration = struct_declaration + " " + argument_list[i] + ";\n";
        }
        struct_declaration = struct_declaration + "}data_t;\n";

        Rewrite.InsertTextBefore(E->getSourceRange().getBegin(),struct_declaration);
        return true;

    }
    //FunctionDecl *func = E->getDirectCallee(); //gives you callee   function
    std::string funcName = E->getNameInfo().getName().getAsString();
    if(funcName == "main"){
        std::cout << "Inside main function...\n";
        insideMain = true;
    }else{
        std::cout << "Other function: " << funcName << " ...\n";
        insideMain = false;
    }
    return true;
}

bool TransformatorRecursiveASTVisitor::VisitCallExpr(CallExpr *E)
{
    if(insideMain){
        if(firstFunctionCall==nullptr){
            firstFunctionCall = E;
            std::string code;
            for(std::vector<std::string>::iterator it = argument_list.begin(); it!=argument_list.end(); ++it){
                code = code + "d->";
                code = code + *it;
                code = code + " = ";
                code = code + *it;
                code = code + ";\n";
            }
            Rewrite.InsertTextBefore(E->getExprLoc(),code);
            Rewrite.InsertTextBefore(E->getExprLoc(),"data_t *d = new data_t[1];\n\t");
        }
    }
    return true;
}

bool TransformatorRecursiveASTVisitor::VisitorCXXOperatorCallExpr(const CXXOperatorCallExpr *E){
    llvm::errs() << "Visiting cxxoperatorcall" << "\n";
        return true;
}

bool TransformatorRecursiveASTVisitor::VisitDeclRefExpr(DeclRefExpr *E)
{
    //std::cout << "\nDeclRefExpr:" << E->getNameInfo().getAsString() << " Line: " << E->getExprLoc().printToString() << std::endl;
    if(insideMain){
        std::string name = E->getNameInfo().getAsString();
        if (std::find(argument_list.begin(), argument_list.end(), name) != argument_list.end()){
            std::string arg_adapt = "d->";
            Rewrite.InsertTextBefore(E->getExprLoc(),arg_adapt);
        }
    }
    return true;
}

class TransformatorConsumer : public ASTConsumer
{
 public:

  TransformatorConsumer(Rewriter &Rewrite) : rv(Rewrite) { }
  virtual bool HandleTopLevelDecl(DeclGroupRef d);

  TransformatorRecursiveASTVisitor rv;
};

bool TransformatorConsumer::HandleTopLevelDecl(DeclGroupRef d)
{
  typedef DeclGroupRef::iterator iter;

  for (iter b = d.begin(), e = d.end(); b != e; ++b)
  {
    rv.TraverseDecl(*b);
  }

  return true; // keep going
}