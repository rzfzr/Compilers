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
string input = "1+(2+3)"

string debug(string message){
    if(isDebugging){
         cout<<message<<endl;
    }
    return message;
}

    
}

