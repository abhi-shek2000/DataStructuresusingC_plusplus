/* 
 * File:   ParenthesisCheck.cpp
 * Author: Abhishek Mule
 *
 * Created on 8 March, 2020, 6:49 PM
 */

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

/*
 * 
 */
int main(void) {
    STACK <char> S;
    string exp;
    cout << "\t Expression : ";
    cin >> exp;
    int i;
    i = 0;
    int brack_no;
    while (i < exp.length()){
        if (exp[i] == '{'){
            S.push(exp[i]);
        }else if(exp[i] == '['){
            S.push(exp[i]);
        }else if(exp[i] == '('){
            S.push(exp[i]);
        }
        else if (exp[i] == '}'){
            if (S.pop() == '{'){
                
            }else {
                cout << "\tInvalid Brackets Check Expression Again ! "<<endl;
                break;
            }
        }
        else if(exp[i] == ']'){
            if (S.pop() == '['){
                
            }else {
                cout << "\tInvalid Brackets Check Expression Again ! "<<endl;
                break;
            }
        }else if(exp[i] == ')'){
            if (S.pop() == '('){
                
            }else {
                cout << "\tInvalid Brackets Check Expression Again ! "<<endl;
                break;
            }
        }
        
        i += 1;
        if (i == exp.length()){
            if (!S.isEmpty()){
                cout << "\tInvalid Brackets Check Expression Again ! "<<endl;
                break;
            }else{
                cout << "\tParenthesis Checked No error :) "<<endl;
            }
        }
    }
    
    return 0;
}

