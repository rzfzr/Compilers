#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "mini_lex.cpp"

using namespace std;

token lookahead;
void nope(){
    cout<<"nope"<<endl;
}
int output;
void next(token last){//, token laster


    lookahead = next_token();
    
    
    int current = lookahead.type;
    int value = lookahead.value;
    // int temp = 0;
    cout<<"next: current: "<<token_name(current)<<" last: "<<token_name(last.type)<<endl;
    if (current == SIGN) {
        if(last.type ==ERR){//first cant be SIGN
            nope();
        }
    
    }else if(current == NUM){
        if(last.type ==ERR){//first so just increment
            output = value  ;
        }
        if(last.type == SIGN){//todo: use the actual sign
            output +=value;
            
        }
        
    }
    
    // if(last.type==ERR)
        
    
     if (current == EOF){
        printf("\nSuccess.\n");
        exit(1);
    }
    // else {
    //     printf("Syntax error on x\n");
    //     exit(1);
    // }
    cout<<"end: "<<output<<endl;
          next(lookahead);
}


int main(){
    
    input="2+5+10";
    cout<<"input: "<<input<<endl;
    
    output=0;
    
    token x;
    x.type=ERR;
    next(x);
}
