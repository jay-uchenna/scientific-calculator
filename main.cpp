//
//  main.cpp
//  calculator
//
//  Created by Jedidiah Uchenna on 10.12.2022.
//

#include <iostream>
#include <string>
#include "utility.hpp"


int main(int argc, const char * argv[])
{
    std::string parseStr;
    std::cout << "Welcome to Jay's scientific calculator\n press q to exit at anytime\n\n";
    std::cout << "press h to view rules or any key to continue: ";
    std::getline(std::cin, parseStr);
    if (parseStr[0] == 'h' || parseStr[0] == 'H') helpFunc();
    do
    {
        std::cout << "cal: ";
        std::string input;
        std::getline(std::cin, input);
        if(input[input.size()-1] == 'q') break;
        double ans;
        bool correctAns = true;
        try {
            ans = solve(input);
        }
        catch (...) {
            std::cerr << "error, press h for rules, q to exit, or any key to try again: ";
            std::getline(std::cin, parseStr);
            if (parseStr[0] == 'h' || parseStr[0] == 'H') helpFunc();
            correctAns = false;
        }
        if(correctAns)std::cout << "= " << ans << "\n";
        
    }while(parseStr[0] != 'Q' && parseStr[0] != 'q');
    return 0;
}
