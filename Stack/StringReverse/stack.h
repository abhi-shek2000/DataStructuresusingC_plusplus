/* 
 * File:   stack.h
 * Author: Abhishek Mule
 * Include this header file if you want to use stack in your program
 *
 * Created on 8 March, 2020, 6:47 PM
 */

#ifndef STACK_H
#define	STACK_H

#include <iostream>

using namespace std;
template <class T>

class STACK{
    private:
        struct NODE{
            T data;
            struct NODE *next;
        };
        struct NODE *top;
    public:
        STACK(){
            top = NULL;
        }
        
        void push(T d){
            struct NODE *newNODE = new NODE;
            newNODE->data = d;
            newNODE->next = top;
            top = newNODE;
        }
            
        T pop(){
            if (top == NULL){
                cout <<endl<< "\tStack is empty !"<<endl;
                return 0;
            }else if(top != NULL){
                T temp;
                temp = top->data;
                top = top->next;
                return temp;
            }
        }
        
        T peep(){
            if (top == NULL){
                cout <<endl<< "\tStack is empty !"<<endl;
            }
            else if (top != NULL){
                T temp;
                temp = top->data;
                return temp;
            }
        }
        
        bool isEmpty(){
            if (top == NULL){
                return true;
            }else{
                return false;
            }
        }
        
        int size(){
            struct NODE *ptr = new NODE;
            ptr = top;
            int cnt = 0;
            while (ptr != NULL){
                ptr = ptr->next;
                cnt += 1;
            }
            return cnt;
        }
        
        
};


#endif	/* STACK_H */

