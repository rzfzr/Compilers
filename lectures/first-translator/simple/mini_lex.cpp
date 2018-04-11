#include "cstdio"
#include "string"
#include "iostream"
#include "cstdlib"
#define NUM     256
#define SIGN    257
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
    }
    return "YOUR MOM";
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
    
    while(peek ==' ' ){
        // cout<<"found space"<<endl;
        peek = get_char();
    }
    
    
    
    if (isdigit(peek)){ //tratar inteiros e reais
        int v = 0;
        do {
            v = v * 10 + atoi(&peek);
            peek = get_char();
        } while (isdigit(peek));
        t.type = NUM;
        t.value = v;
        c = peek;
    } else if (peek == '+' || peek == '-'){
        t.type = SIGN;
        t.value=peek;
    } else if (peek == EOF) {
        t.type = EOF;
    } else {
        t.type = ERR;
    }
    return t;
}

// int main() {
//     input = "123+321-12+2";
//     token lookahead = next_token();
//     while (lookahead.type!=EOF){
//         cout << "<"<< token_name(lookahead.type);
//         if (lookahead.type == NUM)
//             cout << "," << lookahead.value;
//         cout <<">"<< endl;
//         lookahead = next_token();
//     }
// }
