// Travis Cassell
// Assignment # 2
// Program Generator
// CS 311_01
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

// Array for upper characters
char upperChar[] = {'A','B','C','D','E','F','G','H','I','J',
                    'K','L','M','N','O','P','Q','R','S','T',
                    'U','V','W','X','Y','Z'};
// Array for lower characters
char lowerChar[] = {'a','b','c','d','e','f','g','h','i','j',
                    'k','l','m','n','o','p','q','r','s','t',
                    'u','v','w','x','y','z'};
// Array for digits
int digits[10] = {0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};

// Function prototypes
void stat_list(int);
void stat(int);
void cmpd_stat();
void if_stat(int);
void iter_stat(int);
void assgn_stat();
void decl_stat(int);
void exp(int);
char op(int);
string _type(int);
void _id();
void _const();
void char_digit_seq(int);
void digit_seq(int);
char _char(int, int);
int digit(int);

// Main logic for program
int main()
{
    // Seed for random # generator
    srand(time(0));
    // Display main() function and call stat_list method to
    // Begin program generator
    cout << "int main()" << endl;
    cout << "{" << endl;
    stat_list(rand() % 2);
    cout << "return 0;" << endl;
    cout << "}" << endl;

return 0;
}

// ***************************************************************
// * FUNCTION DEFINITIONS ******************************************
// ***************************************************************
// All functions are written from assignment productions,
// I wrote a function for each and called them from
// Inside of each other, causing a chain of code to
// Be created
// ***************************************************************

void stat_list(int x)
{
    if (x == 1)
    {
        stat(rand() % 5);
    }
    else
    {
        stat_list(rand() % 2);
        stat(rand() % 5);
    }
}

void stat(int x)
{
    if (x == 1)
    {
        cmpd_stat();
    }
    else if (x == 2)
    {
        if_stat(rand() % 6);
    }
    else if (x == 3)
    {
        iter_stat(rand() % 2);
    }
    else if (x == 4)
    {
        assgn_stat();
    }
    else
    {
        decl_stat(rand() % 2);
    }
}

void cmpd_stat()
{
    cout << "{" << endl;
    stat_list(rand() % 2);
    cout << "}" << endl;
}

void if_stat(int x)
{
    // if ( <exp> ) <stat>
    if (x == 1)
    {
        cout << "if (";
        exp(rand() % 3);
        cout << ")" << endl;
        stat(rand() % 5);
    }
    // if ( <exp> ) <cmpd_stat>
    else if (x == 2)
    {
        cout << "if (";
        exp(rand() % 3);
        cout << ")" << endl;
        cmpd_stat();
    }
    // if ( <exp> ) <stat> else <stat>
    else if (x == 3)
    {
        cout << "if (";
        exp(rand() % 3);
        cout << ")" << endl;
        stat(rand() % 5);
        cout << "else" << endl;
        stat(rand() % 5);
    }
    // if ( <exp> ) <cmpd_stat> else <stat>
    else if (x == 4)
    {
        cout << "if (";
        exp(rand() % 3);
        cout << ")" << endl;
        cmpd_stat();
        cout << "else" << endl;
        stat(rand() % 5);
    }
    // if ( <exp> ) <stat> else <cmpd_stat>
    else if (x == 5)
    {
        cout << "if (";
        exp(rand() % 3);
        cout << ")" << endl;
        stat(rand() % 5);
        cout << "else" << endl;
        cmpd_stat();
    }
    // if ( <exp> ) <cmpd_stat> else <cmpd_stat>
    else
    {
        cout << "if (";
        exp(rand() % 3);
        cout << ")" << endl;
        cmpd_stat();
        cout << "else" << endl;
        cmpd_stat();
    }
}

void iter_stat(int x)
{
    if (x == 1)
    {
        cout << "while ( ";
        exp(rand() % 3);
        cout << " )" << endl;
        stat(rand() % 5);
    }
    else
    {
        cout << "while (";
        exp(rand() % 3);
        cout << ")" << endl;
        cmpd_stat();
    }
}

void assgn_stat()
{
    _id();
    cout << " = ";
    exp(rand() % 3);
}

void decl_stat(int x)
{
    if (x == 1)
    {
        cout << _type(rand() % 2) << " ";
        _id();
    }
    else
    {
        cout << _type(rand() % 2) << " ";
        assgn_stat();
    }
}

void exp(int x)
{
    if (x == 1)
    {
        exp(rand() % 3);
        cout << op(rand() % 4);
        exp(rand() % 3);
    }
    else if (x == 2)
    {
        _id();
    }
    else
    {
        _const();
    }
}
    
char op(int x)
{
    if (x == 1)
    {
        return '+';
    }
    else if (x == 2)
    {
        return '-';
    }
    else if (x == 3)
    {
        return '*';
    }
    else
    {
        return '/';
    }
}

string _type(int x)
{
    if (x == 1)
    {
        return "int";
    }
    else
    {
        return "double";
    }
}

void _id()
{
    cout << _char(rand() % 3, rand() % 25);
    char_digit_seq(rand() % 3);
}

void _const()
{
    cout << digit(rand() % 10);
    digit_seq(rand() % 2);
}

void char_digit_seq(int x)
{
    if (x == 1)
    {
        return;
    }
    else if (x == 2)
    {
        cout << _char(rand() % 3, rand() % 25);
        char_digit_seq(rand() % 3);
    }
    else
    {
        cout << digit(rand() % 10);
        char_digit_seq(rand() % 3);
    }
}

void digit_seq(int x)
{
    if (x == 1)
    {
        return;
    }
    else
    {
        cout << digit(rand() % 10);
        digit_seq(rand() % 2);
    }
}

char _char(int x, int y)
{
    if (x == 1)
    {
        return upperChar[y];
    }
    else if (x == 2)
    {
        return lowerChar[y];
    }
    else
    {
        return '_';
    }
}

int digit(int i)
{
    return digits[i];
}
