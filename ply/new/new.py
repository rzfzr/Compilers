import ply.lex as lex
import ply.yacc as yacc
import sys

reserved = {
  'if'   : 'IF',
  'then' : 'THEN',
  'else' : 'ELSE',
  'begin': 'BEGIN',
  'end'  : 'END',
  'read' : 'READ',
  'write' : 'WRITE'
}

tokens = [
    'IO',
    'PROG',
    'CMD',

    'COND',

    'BLOCK',

    'LPAREN',
    'RPAREN',

    'EQUALS',
    'VAR'
    ] + list(reserved.values())



t_IO    = r'read|write'  #+ _id  #r'write '+ _id  
t_IF   = r'if'# + _cond + r'then' + _block
# t_THEN = r'then'
# t_ELSE = r'else'

# t_BEGIN = r'begin'
# t_END =  r'end'

t_LPAREN  = r'\('
t_RPAREN  = r'\)'

t_EQUALS = R'\='


t_ignore = " \t"

def t_VAR(t):
    r'[a-zA-Z_][a-zA-Z0-9_]*'
    t.type='VAR'
    if t.value in reserved:
        t.type = reserved[ t.value ]
    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)


def t_error(t):
    print("Erro '%s'" % t.value[0])
    t.lexer.skip(1)


lexer = lex.lex()




myInput="if (isTrue) then begin read test end"
# lexer.input(myInput)

# while True:
#     tok = lexer.token()
#     if not tok:
#         break
#     print(tok)




def p_prog(p):#OK
    
    '''
    prog : cmd eol
    | prog cmd eol
    
    '''
    print('Passou!')
    # print(p[1])# print cmd ou prog

def p_cmd(p):#OK
    '''
    cmd : io
    | if
    
    '''
    p[0] = p[1]


def p_if(p):#OK
    '''
    if : IF cond THEN block
        | IF cond THEN block ELSE block
    
    '''
    p[0] = p[1]

def p_cond(p):#OK
    '''
    cond : LPAREN VAR RPAREN
        | LPAREN VAR EQUALS VAR RPAREN
    
    '''
    p[0] = p[1]
    

def p_io(p):#OK
    '''
    io : READ VAR
    | WRITE VAR
    | VAR EQUALS VAR
    
    '''
    p[0] = p[1]


def p_block(p):#OK
    '''
    block : BEGIN cmd END
    
    '''
    p[0] = p[1]

def p_eol(p):#OK??
    '''
    eol :

    '''
    p[0] = None



parser = yacc.yacc()


while True:
    try:
        # s=myInput
        s=input('')
    except EOFError:
        break
    parser.parse(s)