//
//  main.cpp
//  calculator
//
//  Created by Jedidiah Uchenna on 10.12.2022.
//

#include <iostream>
#include "stack.hpp"
#include "MathFuncs.hpp"
#include <string>

//function to check if character is a mathematical operand
bool isOpreand(char op)
{
    switch(op)
    {
        case '+':
        case '-':
        case '/':
        case '*':
        case 'l':
        case 's':
        case 'c':
        case 't':
        case '^':
        case '!':
        //case '-': ;
        case '(':
        case ')': return true;
        default: return false;
    }
}
bool isDigit(char ch)
{
    if((ch >= '0' && ch <= '9') || (ch == '.' || ch == ',')) return true;
    return false;
}
//function returns the out stack precedence of a maths operator
int outStackPre(char op)
{
    switch(op)
    {
        case '+':
        case '-': return 1;
        case '/':
        case '*': return 3;
        case 'l':
        case 's':
        case 'c':
        case 't': return 6;
        case '^': return 8;
        case '!': return 10;
        //case '-': return 12;
        case '(': return 13;
        case ')': return 0;
        default: return -1;
    }
}
//function return the in stack precedence of a maths operator
int inStackPre(char op)
{
    switch(op)
    {
        case '+':
        case '-': return 2;
        case '/':
        case '*': return 4;
        case 'l':
        case 's':
        case 'c':
        case 't': return 5;
        case '^': return 7;
        case '!': return 9;
        //case '-': return 12;
        case '(': return 0;
        default: return -1;
    }
}
void charsToStrNum(std::string* NumStr, char charDigit)
{
    NumStr->push_back(charDigit);
}
//function return a double number when given a string
double strToNum(std::string* NumStr)
{
    return std::stod(*NumStr);
}


int main(int argc, const char * argv[])
{
    // insert code here...
    LL::Stack<char> r;
    std::string post;
    std::string check;
    std::cout << "calculate:\n";
    //std::cin >> check;
    check = "1*(3,5/3/7/4)*sin3";
    for(int i = 0; check[i] !='\0'; i++)
    {
        if(isDigit(check[i]))
        {
            //number of decimals in number
            int noDeci = 0;
            if(check[i] == ',') post.push_back('.');
            else post.push_back(check[i]);
            if(check[i] == '.' || check[i] == ',') noDeci++;
            while(isDigit(check[i+1]))
            {
                if(check[++i] == ',') post.push_back('.');
                else post.push_back(check[i]);
                if(check[i] == '.' || check[i] == ',') noDeci++;
                if(noDeci > 1) return 1; //error, non valid number entered
            }
            post.push_back(' ');
        }
        else if(isOpreand(check[i]))
        {
            while(!r.isEmpty() && outStackPre(check[i]) < inStackPre(r.sTop())) post.push_back(r.pop());
            if(!r.isEmpty() && outStackPre(check[i]) == inStackPre(r.sTop())) r.pop();
            else if(r.isEmpty() || outStackPre(check[i]) > inStackPre(r.sTop())) r.push(check[i]);
        }
    }
    while (!r.isEmpty()) post.push_back(r.pop());
       
    LL::Stack<double> solve;
    for(int i = 0; post[i] != '\0'; i++)
    {
        check.clear();
        if(isDigit(post[i]))
        {
            while(post[i] != ' ') charsToStrNum(&check, post[i++]);
            solve.push(strToNum(&check));
        }
        else
        {
            if(post[i] == '+') {double r = solve.pop(); solve.push(solve.pop() + r);}
            else if(post[i] == '-') {double r = solve.pop(); solve.push(solve.pop() - r);}
            else if(post[i] == '*') {double r = solve.pop(); solve.push(solve.pop() * r);}
            else if(post[i] == '/') {double r = solve.pop(); solve.push(solve.pop() / r);}
            //else if(post[i] == 'l') {solve.push(log(solve.pop(),21));}
            else if(post[i] == 's') {solve.push(sin(solve.pop()));}
            else if(post[i] == 'c') {solve.push(cos(solve.pop()));}
            else if(post[i] == 't') {solve.push(tan(solve.pop()));}
            else if(post[i] == '^') {int r = solve.pop(); solve.push(pow(solve.pop(), r));}
            else if(post[i] == '!') {solve.push(permu((int)solve.pop()));}
        }
    }
    std::cout << solve.pop() << "\n";
    
    return 0;
}
