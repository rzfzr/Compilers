#include "cstdio"
#include "string"
#include "iostream"
#include "cstdlib"
#include <sstream>
#include <cctype>

#include <boost/any.hpp>

#define INT     256
#define FLOAT   257

#define SIGN    333
#define ERR     666
#define EMPTY   999
#define VAR     555

using namespace std;

bool isDebugging = true;

struct token {//default = int
    token():type(EMPTY){}//initialize type
    int type ;
    // int value;
    union{
      float     valueF;
      double    valueD;
      int       valueI;
    }value;
    // float getValue(float i){
    //     return value.valueF;
    // }
    int getValue(){
        switch(type){
            case INT    :return value.valueI;
            case SIGN    :return value.valueI;
            case ERR    :return value.valueI;
            case VAR    :return value.valueI;
            case EMPTY    :return value.valueI;
        }
        
        // return (float)value.valueI;
        // cout<<"Failed getting value, shouldn't you be using getNum? Dumbass";
    }
    
    void setNum(float newValue){
        if(roundf(newValue)==newValue){//its a int
            value.valueI=(int)newValue;
            type=INT;
        }else{
            value.valueF=newValue;
            type=FLOAT;
        }
    }
    
    float getNum(){
        switch(type){
            case INT    :return (float)value.valueI;
            case FLOAT  :return value.valueF;
            case SIGN    :return (float)value.valueI;
            case ERR    :return (float)value.valueI;
            case VAR    :return (float)value.valueI;
            case EMPTY    :return (float)value.valueI;
        }
        
        // return (float)value.valueI;
        cout<<"NOT_A_NUM";
    }
    string getType(){
        switch (type){
            case INT   :return "INT";
            case FLOAT :return "FLOAT";
            case SIGN  :return "SIGN";
            case ERR   :return "ERR";
            case VAR   :return "VAR";
            case EMPTY :return "EMPTY";
        }
        return  ("NOT_A_TYPE");
    }
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
    while(peek == ' '){//found space get next
        peek = get_char();
    }
    if (isdigit(peek)){
        // tokenFloat tf;
        
        bool isFloat=false;
        int  afterDot = 0;
        int  beforeDot=0;
        
        
        do {
            if(peek=='.'){
                isFloat=true;
                debug("before dot: "+to_string(afterDot));
                beforeDot=afterDot;
                afterDot=0;
            } 
            afterDot = afterDot * 10 + atoi(&peek);
            peek = get_char();
        } while (isdigit(peek)||peek=='.');
            t.setNum(afterDot);
            // t.value=afterDot;
            
            
            if(isFloat){
                debug("after dot: "+to_string(afterDot));
                string temp =to_string(beforeDot)+"."+to_string(afterDot);
                float tempFloat =stof(temp);
                t.setNum(tempFloat);
                debug("new FLOAT: "+to_string(t.getNum()));
            }else{
                t.setNum(afterDot);
            debug("new INT: "+to_string(afterDot));
                // tf.value = afterDot;
                
            }
            
            c = peek;
            
            return t;
                   
    } 
    
    else if (peek=='='||peek == '+' || peek == '-'){
        t.setNum(peek);
        // t.value=peek;
        t.type = SIGN;
    }else if(isalpha(peek)){
        // t.type=VAR;
        // t.value=peek;
    } 
    
    else if (peek == EOF) {
        t.type = EOF;
    } else {
        t.type = ERR;
    }
    
    
    return t;
}

