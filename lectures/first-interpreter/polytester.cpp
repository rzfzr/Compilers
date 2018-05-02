#include <cstdio>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include "../myLexical.cpp"

using namespace std;


void printValue(token t){
    // cout<<"value: "<<t.getValue()<<endl;
    
}


int main(){
    token test,test1;
    // test.type=FLOAT;
    // test.setInt(5);
    // test1.setFloat(5.22);
    
    // test.value=2;
    
    test.setNum();
    
    //float f =
    cout<<test.getNum()<<" "<<test.getType();
    
    
    // cout<<endl<<test1.getValue(3.3f);
    // cout<<"value: "<<f<<endl;
    // cout<<"type: "<<test.getType()<<endl;
    // test.value.valueF=2.5;
    // printValue(test);
    // test.value.valueI=2;
    // printValue(test);
    // cout <<"main.get "<<mainToken.getValue()<<endl;
}

