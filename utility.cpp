//
//  utility.cpp
//  calculator
//
//  Created by Jedidiah Uchenna on 15.12.2022.
//

#include "utility.hpp"
#include "stack.hpp"
#include "MathFuncs.hpp"
#include <iostream>

void helpFunc()
{
    std::cout << "Rules:\n"
        << "This calculator can perform: +, -, *, /, sin, cos, tan, !, ^, operations\n"
        << "both * and x can be used as multiplication sign\n"
        << "log and square root would be added later\n"
        << "angles in radians\n"
        << "enclose negative numbers in a bracket eg, -3 -> (-3)\n"
        << "for power of, use ^ eg, 5 ^ 2\n"
        << "do not use more than one space between any symbols\n"
        << "only one decimal symbol should be used at a time. 2.5 + 3.5 or 2,5 + 3,5 not 2.5 + 3,5\n\n";
}
//function to input if character is a mathematical operand
bool isOpreand(const char& op)
{
    const char operands[] = "+-*x/sct^!()";
    for(int i = 0; i < sizeof(operands); i++) if(operands[i] == op) return true;
    return false;
}
bool isDigit(const char& ch)
{
    if((ch >= '0' && ch <= '9') || (ch == '.' || ch == ',')) return true;
    return false;
}
//function returns the out stack precedence of a maths operator
int outStackPre(const char& op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 3;
    if(op == 's' || op == 'c' || op == 't') return 6;
    if(op == '^' ) return 8;
    if(op == '!') return 10;
    if(op == 'm') return 12;
    if(op == '(') return 13;
    if(op == ')') return 0;
    return -1; //returns -1 for no out stack presedence
}
//function return the in stack precedence of a maths operator
int inStackPre(const char& op)
{
    if(op == '+' || op == '-') return 2;
    if(op == '*' || op == '/') return 4;
    if(op == 's' || op == 'c' || op == 't') return 5;
    if(op == '^' ) return 7;
    if(op == '!') return 9;
    if(op == 'm') return 11;
    if(op == '(') return 0;
    return -1; //returns -1 for no in stack presedence
}
double charsToNum(const std::string& mainStr, int i)
{
    std::string tempStr = "";
    while(mainStr[i] != ' ') tempStr.push_back(mainStr[i++]);
    return std::stod(tempStr);
}
std::string createPostfix(const std::string& input)
{
    LL::Stack<char> r;
    std::string post;
    char dotOrComma = '0';
    for(int i = 0; i < input.size(); i++)
    {
        if(isDigit(input[i]))
        {
            //number of decimals in a number
            int noDeci = 0;
            i--;
            do
            {
                i++;
                if(input[i] == '.' || input[i] == ',')
                {
                    post.push_back('.');
                    noDeci++;
                    if(noDeci > 1) throw std::invalid_argument("error: wrong placement of decimals\n");
                    if(dotOrComma == '0') dotOrComma = input[i];
                    if(dotOrComma != '0' && dotOrComma != input[i])
                        throw std::invalid_argument("error: useage of both dot and comma in expression\n");
                }
                else post.push_back(input[i]);
                
            }while(isDigit(input[i+1]));
            
            
            
            post.push_back(' ');
        }
        else if(isOpreand(input[i]))
        {
            char current = input[i];
            //if statement for handling negetive numbers
            if(current == '-') {if(input[i-1] == '(' || (input[i-2] == '(' && input[i-1] == ' ')) current = 'm';}
            else if(current == 'x') current = '*';
            while(!r.isEmpty() && outStackPre(current) < inStackPre(r.sTop())) post.push_back(r.pop());
            if(!r.isEmpty() && outStackPre(current) == inStackPre(r.sTop())) r.pop();
            else if(r.isEmpty() || outStackPre(current) > inStackPre(r.sTop())) r.push(current);
            
            if(current == 's'){if(input[i+1] == 'i' && input[i+2] == 'n') i +=2;
                                else throw std::invalid_argument("error: wrong input for sin\n");}
            else if(current == 'c'){if(input[i+1] == 'o' && input[i+2] == 's') i +=2;
                                    else throw std::invalid_argument("error: wrong input for cos\n");}
            else if(current == 't'){if(input[i+1] == 'a' && input[i+2] == 'n') i +=2;
                                    else throw std::invalid_argument("error: wrong input for tan\n");}
        }
        else if(input[i] == ' ')
        {
            if(input[i+1] == ' ') throw std::invalid_argument("error: only one space allowed\n");
        }
        else if(input[i] == '=')
        {
            if(input[i+1] == '\0') continue;
            if(input[i+1] == ' ' && input[i+2] == '\0') continue;
            throw std::invalid_argument("error: wrong placement of =\n");
        }
        else throw std::invalid_argument("error: invalid operand or digit\n");
    }
    while (!r.isEmpty()) post.push_back(r.pop());
    return post;
}

double sovlePostFix(const std::string& post)
{
    LL::Stack<double> solve;
    for(int i = 0; i < post.size(); i++)
    {
        if(isDigit(post[i]))
        {
            solve.push(charsToNum(post, i));
            while(post[i] != ' ') i++;
        }
        else
        {
            if(post[i] == '+') {double r = solve.pop(); solve.push(add(solve.pop() , r));}
            else if(post[i] == '-') {double r = solve.pop(); solve.push(sub(solve.pop() , r));}
            else if(post[i] == '*') {double r = solve.pop(); solve.push(mul(solve.pop() , r));}
            else if(post[i] == '/') {double r = solve.pop(); solve.push(div(solve.pop() , r));}
            else if(post[i] == 's') {solve.push(sin(solve.pop()));}
            else if(post[i] == 'c') {solve.push(cos(solve.pop()));}
            else if(post[i] == 't') {solve.push(tan(solve.pop()));}
            else if(post[i] == '^') {int r = solve.pop(); solve.push(pow(solve.pop(), r));}
            else if(post[i] == '!') {solve.push(permu((int)solve.pop()));}
            else if(post[i] == 'm') {solve.push(0 - solve.pop());}
            else throw std::invalid_argument("error: non matching brackets\n");
        }
    }
    if (solve.getSize() != 1) throw std::invalid_argument("error: non matching inputs\n");
    return solve.pop();
}

double solve(const std::string& input)
{
    return sovlePostFix(createPostfix(input));
}
