#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "../myLexical.cpp"

using namespace std;

void list();
void term();
void x();
void match(int);
void print(char);

token lookahead;

void print_char(char c)
{
    printf("%c ", c);
}

void print_int(int i)
{
    printf("%d ", i);
}

void list()
{
    term();
    x();
}

void x()
{
    if (lookahead.type == SIGN)
    {
        int value = lookahead.value;
        match(SIGN);
        term();
        print_char((char)value);
        x();
    }
    else if (lookahead.type == EOF)
    {
        printf("\nSuccess.\n");
    }
    else
    {
        printf("Syntax error on x\n");
        exit(1);
    }
}

void term()
{
    if (lookahead.type == NUM)
    {
        print_int(lookahead.value);
        match(NUM);
    }
    else
    {
        printf("Syntax error on term\n");
        exit(1);
    }
}

void match(int type)
{
    if (lookahead.type == type)
    {
        lookahead = next_token();
    }
    else
    {
        printf("Match error");
    }
}

int main()
{
    input = "123+321 -  111";
    lookahead = next_token();
    list();
}
