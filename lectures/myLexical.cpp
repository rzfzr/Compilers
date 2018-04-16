#include "cstdio"
#include "string"
#include "iostream"
#include "cstdlib"
#include <sstream>

#define NUM     256
#define SIGN    257
#define ERR     666
#define EMPTY   999
#define VAR     555

using namespace std;


bool isDebugging;


struct token {
    int type ;
    int value;
};

string input;
int pos = 0;
char c = EOF;


string debug(string message){
    if(isDebugging){
         cout<<message<<endl;
    }
    return message;
}

string token_name(int t){
    switch (t)
    {
        case NUM    :return "NUM";
        case SIGN   :return "SIGN";
        case ERR    :return "ERR";
        case VAR    :return "VAR";
        case EMPTY  :return"EMPTY";
        
    }
    return  ("NOT_A_TYPE");
    
}

char get_char(){
    if (pos < input.length()){
        return input[pos++];
    } else {
        return EOF;
    }
}



token next_token(){
    token t;
    char peek;
    if (c == EOF){
        peek = get_char();
    }else {
        peek = c;
        c = EOF;
    }
    while(peek ==' ' ){//found space get next
        peek = get_char();
    }
    if (isdigit(peek)){
        int v = 0;
        do {
            v = v * 10 + atoi(&peek);
            peek = get_char();
        } while (isdigit(peek)||peek=='.');
        t.type = NUM;
        t.value = v;
        debug("new NUM: "+to_string(v));
        c = peek;
    } else if (peek=='='||peek == '+' || peek == '-'){
        t.type = SIGN;
        t.value=peek;
    }else if(isalpha(peek)){
        t.type=VAR;
        t.value=peek;
        
    } 
    
    
    else if (peek == EOF) {
        t.type = EOF;
    } else {
        t.type = ERR;
    }
    return t;
}
