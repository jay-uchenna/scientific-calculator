//
//  MathFuncs.hpp
//  calculator
//
//  Created by Jedidiah Uchenna on 10.12.2022.
//

#ifndef MathFuncs_hpp
#define MathFuncs_hpp

//use to improve the accurecy of the sine function, the higher the more accurate.
//it should always be an odd number > 0;
#define ACCURECY 51

double add(double , double );
double sub(double ,double );
double mul(double ,double );
double div(double ,double );
//double log(double ,int ); //base 10
double pow(double ,int );
int permu(int );
//for sin, cos and tan num1 is in radians
double sin(double num1, int = ACCURECY);
double cos(double num1);
double tan(double num1);

#endif /* MathFuncs_hpp */
