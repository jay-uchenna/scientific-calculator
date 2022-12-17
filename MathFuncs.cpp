//
//  MathFuncs.cpp
//  calculator
//
//  Created by Jedidiah Uchenna on 10.12.2022.
//

#include "MathFuncs.hpp"
#include <iostream>

double add(double num1, double num2)
{
    return (num1 + num2);
}
double sub(double num1,double num2)
{
    return (num1 - num2);
}
double mul(double num1,double num2)
{
    return (num1 * num2);
}
double div(double num1,double num2)
{
    if(num2 == 0) throw std::runtime_error("error: result of div by 0 is undifined\n");
    return (num1/num2);
}
double ln(double num1,int num2); //base e
//returns num to power toPow
double pow(double num,int toPow)
{
    if(toPow < 0)
    {
        num = 1 / num;
        toPow *= -1;
    }
    if(toPow) return num * pow(num,toPow-1);
    return 1;
}
int permu(int num)
{
    if(num > 0) return num * permu(num -1);
    if(num == 0)return 1;
    throw std::invalid_argument("error: permutation of negative numbers not posible\n");
}
//funtion to solve for sine using Taylor Series
//angle in radians
double sin(double angleRed, int n)
{
    static double pw = 1, pem = 1;
    if (n == 51) {pw = 1; pem = 1;}
    double temp;
    if (n == 1){
        pw = angleRed;
        return angleRed;
    }
    else
    {
         temp = sin(angleRed,n-2);
         pw *= angleRed * angleRed * (-1);
         pem *= (n-1) * n;
         return temp + (pw/pem);
    }
}
//funtion to ensure angle to be calculated by cos function is less than 2 Pi
double Pi = 3.14159265359;
double dr(double num)
{
    if(num < (2 * Pi)) return num;
    return dr(num-(2 * Pi));
}
double cos(double num)
{
    //using the formula cos (-x) = cos x
    if(num < 0) num *= -1;
    num = dr(num);
    //using the formula cos (x) = sin((pi/2) - x)
    return sin((Pi/2)-num);
}
double tan(double num)
{
    //using the formula tan x = (sin x)/(cos x)
    return div(sin(num),cos(num));
}
