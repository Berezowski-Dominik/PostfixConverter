// PostfixConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Construct a function that, when given a string containing an expression in infix notation, will return an identical expression in postfix notation.

The operators used will be +, -, *, /, and ^ with left-associativity of all operators but ^.

The precedence of the operators (most important to least) are : 1) parentheses, 2) exponentiation, 3) times/divide, 4) plus/minus.

The operands will be single-digit integers between 0 and 9, inclusive.

Parentheses may be included in the input, and are guaranteed to be in correct pairs.

I use this algorytm:    https://pl.wikipedia.org/wiki/Odwrotna_notacja_polska#Algorytm_konwersji_z_notacji_infiksowej_do_ONP

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string to_postfix(string infix)
{
    string ReturnValue = "";
    vector <char> Char;
    map <char, int> Operator = { {'+',1},{'-',1},{'*',2},{'/',2},{'^',3} };

    for (int i = 0; i < infix.length(); i++)
    {
        if (48 <= infix[i] && infix[i] <= 57) { ReturnValue += infix[i]; }
        else if (40 == infix[i]) { Char.push_back(infix[i]); }
        else if (41 == infix[i])
        {
            while (Char.back() != 40)
            {
                ReturnValue += Char.back();
                Char.pop_back();
            }
            Char.pop_back();
        }
        else
        {
            if (Char.empty() == false)
            {
                while (Operator[Char.back()] >= Operator[infix[i]])
                {
                    ReturnValue += Char.back();
                    Char.pop_back();
                    if (Char.empty() == true)
                        break;
                }
            }
            Char.push_back(infix[i]);
        }
    }

    while (!Char.empty())
    {
        ReturnValue += Char.back();
        Char.pop_back();
    }

    return ReturnValue;
}

int main()
{
    //cout << to_postfix("2+7*5") << endl;
    cout << to_postfix(("5+(6-2)*9+3^(7-1)")) << endl;
    cout << to_postfix("(5-4-1)+9/5/2-7/1/7") << endl;
}
