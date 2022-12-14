//
//  MathFuncs.cpp
//  calculator
//
//  Created by Jedidiah Uchenna on 10.12.2022.
//

#include "MathFuncs.hpp"

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
    return (num1/num2);
}
double ln(double num1,int num2); //base 
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
    if(num) return num * permu(num -1);
    return 1;
}
//for sin, cos and tan num1 is in radians
double sin(double num, int n)
{       static double pw = 1, pem = 1;
        double temp;
        if (n == 1){
            pw = num;
            return num;
        }
        else
        {
             temp = sin(num,n-2);
             pw *= num * num * (-1);
             pem *= (n-1) * n;
             return temp + (pw/pem);
        }
}
double cos(double num)
{
    return sin(1.57079633-num);
}
double tan(double num)
{
    return sin(num)/cos(num);
}
