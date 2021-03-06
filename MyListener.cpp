// Generated from tinyrexx.g4 by ANTLR 4.7
#include <iostream>
#include <typeinfo>
#include "MyListener.h"

using namespace std;

MyListener::MyListener(const std::set<std::string> &ids) {
    vars = ids;
}


void MyListener::enterProgram(tinyrexxParser::ProgramContext *ctx) {
    cout << "#include <iostream>" << endl << endl
         << "using namespace std;" << endl << endl
         << "int main() {" << endl;
    indent += 4;
    // Dichiara le variabili usate in tutto il programma:w
    for (auto name : vars) {
        cout << string(indent, ' ') << "int " << name << " = 0;" << endl;
    }

}

void MyListener::exitProgram(tinyrexxParser::ProgramContext *ctx) {
    cout << "}" << endl;
}


void MyListener::enterBody(tinyrexxParser::BodyContext *ctx) {
	indent += 4;	
	cout <<" {" << endl;	
}

void MyListener::exitBody(tinyrexxParser::BodyContext *ctx) {
    tinyrexxParser::If_stContext* parent = dynamic_cast<tinyrexxParser::If_stContext*>(ctx->parent);
    indent -= 4;		
    cout << string(indent, ' ') << "}" << endl;
	if (parent != nullptr && parent->body().size() == 2 && ctx == parent->body()[0]) {
        cout << string(indent, ' ') << "else" << endl;
        if (parent->ELSE() != NULL) {
            cout << string(indent-1, ' ');
        }
	}
}


void MyListener::enterAssign(tinyrexxParser::AssignContext * ctx) {
    string name = ctx->ID()->getText(); // che variabile stiamo assegnando?
    if (dynamic_cast<tinyrexxParser::Do_loopContext*>(ctx->parent)) {
		cout << name << " = ";
	} else {
		cout << string(indent, ' ') << name << " = " ; //scrive rientrato di n spazi 'var =' 
    }
}

void MyListener::exitAssign(tinyrexxParser::AssignContext * ctx) {
    cout << ";";
    if (!dynamic_cast<tinyrexxParser::Do_loopContext*>(ctx->parent)){
		cout << endl;
	}
}


void MyListener::enterPrint(tinyrexxParser::PrintContext * ctx) {
    cout << string(indent, ' ') << "cout << " ;    
}

void MyListener::exitPrint(tinyrexxParser::PrintContext * ctx) {
    cout << " << endl;" << endl;
}


void MyListener::exitInput(tinyrexxParser::InputContext * ctx) {
    string name = ctx->ID()->getText();
    cout << string(indent, ' ') << "cin >> " << name << ";" << endl;
}


void MyListener::enterA_expr(tinyrexxParser::A_exprContext * ctx) {
    tinyrexxParser::Do_loopContext* parent = dynamic_cast<tinyrexxParser::Do_loopContext*>(ctx->parent);
    if (parent) {
		cout << " " << parent->assign()->ID()->getText() << " < ";
	}

    // controllo in quale caso sono
    if(ctx->ID() != NULL) {
        // caso ID semplice
        cout << ctx->ID()->getText();//scrivo l'ID
    } else if(ctx->NUMBER() != NULL) {
        // caso valore numerico semplice
        cout << ctx->NUMBER()->getText();//scrivo il valore numerico semlplice
    } else if(ctx->MINUS() !=  NULL) {
        // caso operatore - unario
        cout << "-" ; //scrivo il carattere '-'
    } else if(ctx->a_op() != NULL) {
        // caso operatore binario: gestito da enterA_op
    } else {
        // caso parentesi
        cout << "(" ; //scrivo il carattere '('
    }
}

void MyListener::exitA_expr(tinyrexxParser::A_exprContext * ctx) {
    // controllo in quale caso sono
    if(ctx->ID() != NULL) {
        // caso ID semplice
    } else if(ctx->NUMBER() != NULL) {
        // caso valore numerico semplice
    } else if(ctx->MINUS() !=  NULL) {
        // caso operatore - unario
    } else if(ctx->a_op() != NULL) {
        // caso operatore binario: gestito da exitA_op
    } else {
        // caso parentesi
        cout << ")" ; //unica differenza de enterA_expr che chiude la parentesi aperta
    }

    tinyrexxParser::Do_loopContext* parent = dynamic_cast<tinyrexxParser::Do_loopContext*>(ctx->parent);
    if (parent) {
		cout <<"; " << parent->assign()->ID()->getText() << "++)";
	}
}


//in questo caso basta implementare solo l'exit 
void MyListener::exitA_op(tinyrexxParser::A_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->PLUS() != NULL) {
        cout << " + ";
    } else if(ctx->MINUS() != NULL) {
        cout << " - ";
    } else if(ctx->MUL() != NULL) {
        cout << " * ";
    } else if(ctx->DIV() != NULL) {
        cout << " / ";
    } else if(ctx->MOD() != NULL) {
		cout << " % ";
    }
}


void MyListener::exitR_op(tinyrexxParser::R_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->EQUAL() != NULL) {
        cout << " == ";
    } else if(ctx->LT() != NULL) {
        cout << " < ";
    } else if(ctx->LEQ() != NULL) {
        cout << " <= ";
    } else if(ctx->GT() != NULL) {
        cout << " > ";
    } else if(ctx->GEQ() != NULL) {
        cout << " >= ";
    }
}


void MyListener::enterW_loop(tinyrexxParser::W_loopContext * ctx) {
    cout << string(indent, ' ') << "while";
}

void MyListener::exitW_loop(tinyrexxParser::W_loopContext * ctx) {
}


void MyListener::enterTest(tinyrexxParser::TestContext * ctx) {
    if (dynamic_cast<tinyrexxParser::If_stContext *>(ctx->parent) || dynamic_cast<tinyrexxParser::W_loopContext *>(ctx->parent)) {
	    cout << "(";
    }
    if (ctx->r_op() == nullptr && ctx->b_op() == nullptr && ctx->a_expr().size() == 0 && ctx->NOT() == nullptr) {
		cout << "(";
	}

    if (ctx->NOT() != nullptr) {
	    cout << "!";
	    if (ctx->a_expr().size() == 0) {
		    cout << "(";
        }
    }
}

void MyListener::exitTest(tinyrexxParser::TestContext * ctx) {
    if (dynamic_cast<tinyrexxParser::If_stContext *>(ctx->parent) || dynamic_cast<tinyrexxParser::W_loopContext *>(ctx->parent)) {
	    cout << ")";
    }

    if (ctx->r_op() == nullptr && ctx->b_op() == nullptr && ctx->a_expr().size() == 0 && ctx->NOT() == nullptr) {
		cout << ")";
	}

    if (ctx->NOT() != nullptr) {
	    if (ctx->a_expr().size() == 0) {
		    cout << ")";
        }
    }
}


void MyListener::enterTerminate(tinyrexxParser::TerminateContext * ctx) {
	cout << string(indent, ' ') << "return ";
}

void MyListener::exitTerminate(tinyrexxParser::TerminateContext * ctx) {
	cout << ";" << endl;
}


void MyListener::enterIf_st(tinyrexxParser::If_stContext * ctx) {
	cout << string(indent, ' ') << "if ";
}

void MyListener::exitIf_st(tinyrexxParser::If_stContext * ctx) {
}


void MyListener::enterDo_loop(tinyrexxParser::Do_loopContext * ctx) {
	cout << string(indent, ' ') << "for (";
}

void MyListener::exitDo_loop(tinyrexxParser::Do_loopContext * ctx) {
}


void MyListener::exitB_op(tinyrexxParser::B_opContext * ctx) {
	if(ctx->AND() != NULL) {
        cout << " && ";
    } else if(ctx->OR() != NULL) {
    	cout << " || ";
	}
}
