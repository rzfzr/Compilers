
# -----------------------------------------------------------------------------
# gramaticaDoDella.py


# Para o seminário: Duração de 20 minutos.

# Descrição da ferramenta
# Instalação e uso da ferramenta
# Aplicação da ferramenta na gramática de exemplo
# Considerações da equipe sobre a ferramenta
# Para o texto: Formato livre

# Descrever os tópicos do seminário
# Disponibilizar sites e material de apoio para o estudo da ferramenta
#
# <prog>  ::= <cmd> eol | <prog> <cmd> eol
# <cmd>   ::= <io> | <if>
# <io>    ::= read id | write id | id = id
# <if>    ::= if <cond> then <block> | if <cond> then <block> else <block>
# <cond>  ::= (id) | (id==id)
# <block> ::= begin <cmd> end
#

# if (isTrue) then begin read pos end 

# -----------------------------------------------------------------------------



reserved = {
  'if'   : 'IF',
  'then' : 'THEN',
  'else' : 'ELSE',
  'begin': 'BEGIN',
  'end'  : 'END',
  'read' : 'READ'
}

# tokens += list(reserved.values())

tokens = (
    'PROG',
    'CMD',
    'IO',
    'ID',

    'IF',
    'THEN',
    'ELSE',

    'COND',
    'BLOCK',
    'BEGIN',
    'END',

    'LPAREN',
    'RPAREN',

    'NUMBER',
    'PLUS','MINUS','TIMES','DIVIDE',
    'EQUALS',
    )
    
_id    = r'[a-zA-Z_][a-zA-Z0-9_]*'

t_EQUALS  = r'='

_lparen  = r'\('
_rparen  = r'\)'
_cond   = _lparen +_id+ _rparen

_io    = r'read|write' + _id  #r'write '+ _id  
_if   = r'if'# + _cond + r'then' + _block
_then = r'then'
_else = r'else'

_begin = r'begin'
_end  =  r'end'
_cmd  = _io
# _prog = _cmd + _id
_block  = _begin+_cmd+_end



from ply.lex import TOKEN

@TOKEN(_cond)
def t_COND(t):
    return t

@TOKEN(_block)
def t_BLOCK(t):
    return t

@TOKEN(_then)
def t_THEN(t):
    return t

@TOKEN(_else)
def t_ELSE(t):
    return t

@TOKEN(_begin)
def t_BEGIN(t):
    return t

@TOKEN(_end)
def t_END(t):
    return t


@TOKEN(_io)
def t_IO(t):
    return t

@TOKEN(_if)
def t_IF(t):
    return t

@TOKEN(_id)
def t_ID(t):
    return t

    # r'read'
    # t.value=t.value
    # r'[a-zA-Z_][a-zA-Z0-9_]*'
    # print(t)
    # t.value = t.value
# var _cmd

# t_NAME    = r'[a-zA-Z_][a-zA-Z0-9_]*'
    # try:
    #     t.value = int(t.value)
    # except ValueError:
    #     print("Integer value too large %d", t.value)
    #     t.value = 0






# def t_NUMBER(t):
#     r'\d+'
#     try:
#         t.value = int(t.value)
#     except ValueError:
#         print("Integer value too large %d", t.value)
#         t.value = 0
#     return t








# Ignored characters
t_ignore = " \t"

def t_newline(t):
    r'\n+'
    t.lexer.lineno += t.value.count("\n")
    
def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)
    
# Build the lexer
import ply.lex as lex
lexer = lex.lex()

# Parsing rules

# precedence = (
#     ('left','PLUS','MINUS'),
#     ('left','TIMES','DIVIDE'),
#     ('right','UMINUS'),
#     )

# dictionary of names
names = { }

def p_statement_assign(t):
    'statement : ID EQUALS expression'
    names[t[1]] = t[3]

def p_statement_expr(t):
    'statement : expression'
    print(t[1])

def p_expression_binop(t):
    '''expression : expression PLUS expression
                  | expression MINUS expression
                  | expression TIMES expression
                  | expression DIVIDE expression'''
    if t[2] == '+'  : t[0] = t[1] + t[3]
    elif t[2] == '-': t[0] = t[1] - t[3]
    elif t[2] == '*': t[0] = t[1] * t[3]
    elif t[2] == '/': t[0] = t[1] / t[3]

# def p_expression_uminus(t):
#     'expression : MINUS expression %prec UMINUS'
#     t[0] = -t[2]

def p_expression_group(t):
    'expression : LPAREN expression RPAREN'
    t[0] = t[2]

def p_expression_if(t):
    'expression : IF'
    t[0] = t[1]

def p_expression_cond(t):
    'expression : COND'
    t[0] = t[1]


def p_expression_id(t):
    'expression : ID'
    try:
        t[0] = names[t[1]]
    except LookupError:
        print("Undefined id '%s'" % t[1])
        t[0] = 0

def p_error(t):
    print("Syntax error at '%s'" % t.value)

import ply.yacc as yacc
parser = yacc.yacc()



myInput="if (isTrue) then begin write test end"
lexer.input(myInput)

while True:
    # tok = lexer.token()
    # if not tok:
    #     break
    # print(tok)
    try:
        # s = input('GOGOGO> ') 
        s = myInput
    except EOFError:
        break
    parser.parse(s)