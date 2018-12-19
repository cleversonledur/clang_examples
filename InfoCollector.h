class InfoCollectorRecursiveASTVisitor
    : public RecursiveASTVisitor<InfoCollectorRecursiveASTVisitor>
{

 public:
  CallExpr *firstFunctionCall=nullptr;

  InfoCollectorRecursiveASTVisitor(Rewriter &R) : Rewrite(R) { }
  bool VisitCallExpr(CallExpr *E);

  void InstrumentStmt(Stmt *s);
  bool VisitStmt(Stmt *s);
  bool VisitFunctionDecl(FunctionDecl *f);
  

  Rewriter &Rewrite;
};


bool InfoCollectorRecursiveASTVisitor::VisitCallExpr(CallExpr *E)
{
    if(firstFunctionCall==nullptr){
      firstFunctionCall = E;
      for(int i=0, j=E->getNumArgs(); i<j; i++)
      {
          argument_list.push_back(((DeclRefExpr*)E->getArg(i))->getNameInfo().getName().getAsString());
          argument_type.push_back(((DeclRefExpr*)E->getArg(i))->getDecl()->getType().getAsString());
      }
    }
    return true;
}

bool InfoCollectorRecursiveASTVisitor::VisitStmt(Stmt *s)
{
  return true; // returning false aborts the traversal
}

bool InfoCollectorRecursiveASTVisitor::VisitFunctionDecl(FunctionDecl *f)
{
  return true; // returning false aborts the traversal
}


class InfoCollectorConsumer : public ASTConsumer
{
 public:

  InfoCollectorConsumer(Rewriter &Rewrite) : rv(Rewrite) { }
  virtual bool HandleTopLevelDecl(DeclGroupRef d);

  InfoCollectorRecursiveASTVisitor rv;
};


bool InfoCollectorConsumer::HandleTopLevelDecl(DeclGroupRef d)
{
  typedef DeclGroupRef::iterator iter;

  for (iter b = d.begin(), e = d.end(); b != e; ++b)
  {
    rv.TraverseDecl(*b);
  }

  return true; // keep going
}