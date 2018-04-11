#include "cstdio"
#include "string"
#include "iostream"
#include "cstdlib"
#define NUM     256
#define SIGN    1111
// #define PLUS    257
// #define MINUS   258
#define ERR     666

using namespace std;

struct token {
    int type;
    int value;
};

string input;
int pos = 0;
char c = EOF;

string token_name(int t){
    switch (t)
    {
        case NUM: return "NUM";
        case SIGN: return "SIGN";
        // case PLUS: return "PLUS";
        // case MINUS: return "MINUS";
    }
    return "HEISENBERG";
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
    }
    else {
        peek = c;
        c = EOF;
    }
    //tratar espaços
    if (isdigit(peek)){ //tratar inteiros e reais
        int v = 0;
        do {
            v = v * 10 + atoi(&peek);
            peek = get_char();
        } while (isdigit(peek));
        t.type = NUM;
        t.value = v;
        c = peek;
    } else if (peek == '+' ||peek=='-'){
        t.type = SIGN;
        t.value=peek;
        // cout<<"found a sign: "<< ((char)t.value)<<endl;
    } else if (peek == EOF) {
        t.type = EOF;
    } else {
        t.type = ERR;
    }
    return t;
}
