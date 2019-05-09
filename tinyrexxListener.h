
// Generated from tinyrexx.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "tinyrexxParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by tinyrexxParser.
 */
class  tinyrexxListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(tinyrexxParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(tinyrexxParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(tinyrexxParser::StatementContext *ctx) = 0;
  virtual void exitStatement(tinyrexxParser::StatementContext *ctx) = 0;

  virtual void enterAssign(tinyrexxParser::AssignContext *ctx) = 0;
  virtual void exitAssign(tinyrexxParser::AssignContext *ctx) = 0;

  virtual void enterPrint(tinyrexxParser::PrintContext *ctx) = 0;
  virtual void exitPrint(tinyrexxParser::PrintContext *ctx) = 0;

  virtual void enterInput(tinyrexxParser::InputContext *ctx) = 0;
  virtual void exitInput(tinyrexxParser::InputContext *ctx) = 0;

  virtual void enterTest(tinyrexxParser::TestContext *ctx) = 0;
  virtual void exitTest(tinyrexxParser::TestContext *ctx) = 0;

  virtual void enterW_loop(tinyrexxParser::W_loopContext *ctx) = 0;
  virtual void exitW_loop(tinyrexxParser::W_loopContext *ctx) = 0;

  virtual void enterDo_loop(tinyrexxParser::Do_loopContext *ctx) = 0;
  virtual void exitDo_loop(tinyrexxParser::Do_loopContext *ctx) = 0;

  virtual void enterIf_st(tinyrexxParser::If_stContext *ctx) = 0;
  virtual void exitIf_st(tinyrexxParser::If_stContext *ctx) = 0;

  virtual void enterA_expr(tinyrexxParser::A_exprContext *ctx) = 0;
  virtual void exitA_expr(tinyrexxParser::A_exprContext *ctx) = 0;

  virtual void enterA_op(tinyrexxParser::A_opContext *ctx) = 0;
  virtual void exitA_op(tinyrexxParser::A_opContext *ctx) = 0;

  virtual void enterR_op(tinyrexxParser::R_opContext *ctx) = 0;
  virtual void exitR_op(tinyrexxParser::R_opContext *ctx) = 0;

  virtual void enterB_op(tinyrexxParser::B_opContext *ctx) = 0;
  virtual void exitB_op(tinyrexxParser::B_opContext *ctx) = 0;

  virtual void enterTerminate(tinyrexxParser::TerminateContext *ctx) = 0;
  virtual void exitTerminate(tinyrexxParser::TerminateContext *ctx) = 0;


};

