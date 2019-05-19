grammar tinyrexx;

program   : statement+;
          
statement : assign | print | input | w_loop | terminate | if_st | do_loop;

assign    : ID '=' a_expr ;
print     : 'say' a_expr ;
input     : 'pull' ID ;
test	  : a_expr r_op a_expr | '(' test ')' | test b_op test | a_expr | NOT a_expr | NOT '(' test ')' | test r_op test;
w_loop    : 'do' 'while' test body 'end' ;
do_loop	  : 'do' assign 'to' a_expr body 'end';
if_st	  : 'if' test 'then' 'do' body 'end' ELSE 'do' body 'end' | 'if' test 'then' 'do' body 'end';
body	  : statement+;

a_expr    : ID | NUMBER | '(' a_expr ')' | a_expr a_op a_expr | MINUS a_expr ;
a_op      : MINUS | PLUS | MUL | DIV | MOD;
r_op      : EQUAL | LT | LEQ | GT | GEQ ;
b_op	  : AND | OR;
terminate : 'exit' a_expr;

MINUS     : '-' ;
PLUS      : '+' ;
MUL       : '*' ;
DIV       : '/' ;
MOD		  : '%';
EQUAL     : '==' ;
LT        : '<' ;
LEQ       : '<=' ;
GT        : '>' ;
GEQ       : '>=' ;
AND	  : '&';
OR	  : '|';
NOT	  : '\\'; //sarebbe il \ ovvero il diverso
ELSE	  : 'else';
ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;
WS        : [ \n\t]+ -> skip;
ErrorChar : . ;

//test      : '(' test ')' | test b_op test | b_expr;
//b_expr  : '(' b_expr ')' | b_expr b_op b_expr | a_expr | NOT b_expr; // ridondante , a_expr r_op a_expr
