/* 
 * File:   StringReverse.cpp
 * Author: Abhishek Mule
 *
 * Created on 8 March, 2020, 10:47 PM
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
    string s;
    cout << "\tEnter string : ";
    cin >> s;
    int i = 0;
    while (i < s.length()){
        S.push(s[i]);
        i ++;
    }
    i = 0;
    cout << "\tReverse : ";
    while (!S.isEmpty()){
        cout << S.pop();
    }
    
    return 0;
}

