#include <cstdio>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include "../myLexical.cpp"

using namespace std;

// token lookahead;
void nope()
{
    cout << "nope" << endl;
}
float output;

int vars[255];
void next(token current, token last, token laster){ //, token laster
    

    current = next_token();
    
    debug("lst: "+to_string(last.getNum())+"("+ last.getType() + 
    ") cur: " +to_string(current.getNum())+"("+ current.getType()+")");
    
    if (current.type == VAR){
        
        if (last.type == EMPTY){ //first so just increment
            output = vars[current.getValue()];
        }
        if (last.type == SIGN){
            if (last.getValue() == '+'){
                output += vars[current.getValue()];
            }else if (last.getValue() == '-'){
                output -= vars[current.getValue()];
            }
            if (last.getValue() == '='){
                if (laster.type == VAR){
                    vars[laster.getValue()] = vars[current.getValue()];
                }
            }
        }
    }
    if (current.type == SIGN){
        if (last.type == EMPTY){ //first cant be SIGN
            nope();
        }
    }
    else if (current.type == INT || current.type==FLOAT){
        if (last.type == EMPTY){ //first so just increment
            output = current.getNum();
            // nope();
        }
        if (last.type == SIGN){ //todo: use the actual sign
            if (last.getValue() == '+'){
                output += current.getNum();
            }
            else if (last.getValue() == '-'){
                output -= current.getNum();
            }
            if (last.getValue() == '='){
                if (laster.type == VAR){
                    vars[laster.getValue()] = current.getValue();
                }
            }
        }
    }

    if (current.type == EOF){
        if (last.type == VAR){
            if (laster.type == ERR){

                output = vars[last.getValue()];
            }
        }
        if (laster.getValue() != '='){
            cout << output << endl;
        }
    }else{
        next(current, current, last);
    }
    // else {
    //     printf("Syntax error on x\n");
    //     exit(1);
    // }
}


int main(){
    token empty;
    // input="11+22";
    input="1.2+3.4";
    cout<<"input: "<<input<<endl;
    while (input != "exit"){
        // cin >> input;
        output = 0;
        pos = 0;
        next(empty, empty, empty);
        input="exit";
    }
}
