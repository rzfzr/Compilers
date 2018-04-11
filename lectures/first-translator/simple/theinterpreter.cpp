#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "mini_lex.cpp"

using namespace std;

// token lookahead;
void nope(){
    cout<<"nope"<<endl;
}
int output;

int vars[255];
int var_global;
void next(token current,token last,token laster){//, token laster


    current = next_token();
    
    
    // int current.type = lookahead.type;
    // int value = lookahead.value;
    // int temp = 0;
    // cout<<"next: current: "<<token_name(current.type)<<" last: "<<token_name(last.type)<<endl;
    if(current.type==VAR){
        // var_pos=var_global;
        // var_global++;
        
        if(last.type ==ERR){//first so just increment
            output = vars[current.value]  ;
            // nope();
        }
        if(last.type == SIGN){//todo: use the actual sign
           if(last.value=='+'){
                output +=vars[current.value];
           }else if(last.value=='-'){
                output -=vars[current.value];
           }if(last.value=='='){
               if(laster.type==VAR){
                    vars[laster.value]=vars[current.value];
                   
               }
           }
               
            
        }
    }
    
    if (current.type == SIGN) {
        if(last.type ==ERR){//first cant be SIGN
            nope();
        }
    
    }else if(current.type == NUM){
        if(last.type ==ERR){//first so just increment
            output = current.value  ;
            // nope();
        }
        if(last.type == SIGN){//todo: use the actual sign
           if(last.value=='+'){
                output +=current.value;
           }else if(last.value=='-'){
                output -=current.value;
           }if(last.value=='='){
               if(laster.type==VAR){
                    vars[laster.value]=current.value;
                   
               }
           }
               
            
        }
        
    }
    
    // if(last.type==ERR)
        
    
     if (current.type == EOF){
         if(last.type==VAR){
             if(laster.type==ERR){
                 
                output=vars[last.value];
             }
         }
         
         if(laster.value!='='){
            cout<<output<<endl;
             
         }
    // cout    <<"end: "
        // printf("\nSuccess.\n");
        // exit(1);
    }else{
          next(current,current,last);
        
    }
    // else {
    //     printf("Syntax error on x\n");
    //     exit(1);
    // }
}


int main(){
    
    // char c = 'y';
    // cout<<(int)c;
    
        token x;
        x.type=ERR;
        
        var_global=0;
    while(input!="exit"){
        
    cin >>input;
    output=0;pos=0;
    // input ="x=4";
    // input="2+5+10";
    // cout<<"input: "<<input<<endl;
    
        next(x,x,x);
    }
    
}
