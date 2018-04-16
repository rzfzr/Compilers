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
int output;

int vars[255];
void next(token current, token last, token laster)
{ //, token laster

    current = next_token();

    debug("last: " + token_name(last.type) + "    current: " + token_name(current.type));
    if (current.type == VAR)
    {
        if (last.type == EMPTY)
        { //first so just increment
            output = vars[current.value];
        }
        if (last.type == SIGN)
        {
            if (last.value == '+')
            {
                output += vars[current.value];
            }
            else if (last.value == '-')
            {
                output -= vars[current.value];
            }
            if (last.value == '=')
            {
                if (laster.type == VAR)
                {
                    vars[laster.value] = vars[current.value];
                }
            }
        }
    }
    if (current.type == SIGN)
    {
        if (last.type == EMPTY)
        { //first cant be SIGN
            nope();
        }
    }
    else if (current.type == NUM)
    {
        if (last.type == EMPTY)
        { //first so just increment
            output = current.value;
            // nope();
        }
        if (last.type == SIGN)
        { //todo: use the actual sign
            if (last.value == '+')
            {
                output += current.value;
            }
            else if (last.value == '-')
            {
                output -= current.value;
            }
            if (last.value == '=')
            {
                if (laster.type == VAR)
                {
                    vars[laster.value] = current.value;
                }
            }
        }
    }

    if (current.type == EOF)
    {
        if (last.type == VAR)
        {
            if (laster.type == ERR)
            {

                output = vars[last.value];
            }
        }
        if (laster.value != '=')
        {
            cout << output << endl;
        }
    }
    else
    {
        next(current, current, last);
    }
    // else {
    //     printf("Syntax error on x\n");
    //     exit(1);
    // }
}

int main()
{
    // isDebugging=true;

    token empty;
    empty.type = EMPTY;

    // cout<<2.5<<endl;
    while (input != "exit")
    {
        cin >> input;
        output = 0;
        pos = 0;
        next(empty, empty, empty);
    }
}
