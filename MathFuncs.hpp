//
//  MathFuncs.hpp
//  calculator
//
//  Created by Jedidiah Uchenna on 10.12.2022.
//

#ifndef MathFuncs_hpp
#define MathFuncs_hpp

#include <stdio.h>

double add(double , double );
double sub(double ,double );
double mul(double ,double );
double div(double ,double );
//double log(double ,int ); //base 10
double pow(double ,int );
int permu(int );
//for sin, cos and tan num1 is in radians
double sin(double num1, int = 51);
double cos(double num1);
double tan(double num1);

#endif /* MathFuncs_hpp */
