#pragma once

#include "antlr4-runtime.h"
#include "tinyrexxParser.h"
#include "tinyrexxBaseListener.h"

/**
 * This class defines a concrete listener for a parse tree produced by tinyrexxParser.
 */
class  MyListener : public tinyrexxBaseListener {
private:
  int indent = 0; //numero di caratteri per identare il codice
  std::set<std::string> vars; // nomi delle variabili

public:
  MyListener(const std::set<std::string> &ids);
    
  void enterProgram(tinyrexxParser::ProgramContext * ctx);
  void exitProgram(tinyrexxParser::ProgramContext * ctx);

  //void enterStatement(tinyrexxParser::StatementContext * ctx); 
  //void exitStatement(tinyrexxParser::StatementContext * ctx); 
  void enterBody(tinyrexxParser::BodyContext *ctx);
  void exitBody(tinyrexxParser::BodyContext *ctx);

  void enterAssign(tinyrexxParser::AssignContext * ctx);
  void exitAssign(tinyrexxParser::AssignContext * ctx);

  void enterPrint(tinyrexxParser::PrintContext * ctx);
  void exitPrint(tinyrexxParser::PrintContext * ctx);

  void exitInput(tinyrexxParser::InputContext * ctx);

  void enterW_loop(tinyrexxParser::W_loopContext * ctx);
  void exitW_loop(tinyrexxParser::W_loopContext * ctx);

  //TODO: rifare
  void enterTest(tinyrexxParser::TestContext * ctx);
  void exitTest(tinyrexxParser::TestContext * ctx);

  void enterA_expr(tinyrexxParser::A_exprContext * ctx);
  void exitA_expr(tinyrexxParser::A_exprContext * ctx);

  //TODO: controllare
  void enterTerminate(tinyrexxParser::TerminateContext * ctx);
  void exitTerminate(tinyrexxParser::TerminateContext * ctx);

  //TODO
  void enterDo_loop(tinyrexxParser::Do_loopContext * ctx);
  void exitDo_loop(tinyrexxParser::Do_loopContext * ctx);

  //TODO
  void enterIf_st(tinyrexxParser::If_stContext * ctx);
  void exitIf_st(tinyrexxParser::If_stContext * ctx);

  void exitB_op(tinyrexxParser::B_opContext * ctx);

  void exitA_op(tinyrexxParser::A_opContext * ctx);
  void exitR_op(tinyrexxParser::R_opContext * ctx);

};

