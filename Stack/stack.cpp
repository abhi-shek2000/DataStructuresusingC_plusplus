/* 
 * File:   Stack.cpp
 * Author: Abhishek Mule
 * Nick Name: technical_geek
 Here is implementation of data Structure Stack using C++
 Here Stack is implemented using Linked List
 * Created on 8 March, 2020, 6:02 PM
 */

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

int main(void) {
    STACK <int> S;
    int value;
    int choice;
    cout<<endl<<endl;
    while (choice != 6){
        cout<<"1] Push \n2] Pop \n3] Peep \n4] Size \n5] isEmpty \n6] EXIT"<<endl;
        cout<< "\tChoose your choice : ";
        cin>> choice;
        cout<<endl<<endl;
        switch(choice){
            case 1:
                cout << "\t\t Enter Value (int) : ";
                cin >> value;
                S.push(value);
                break;
            case 2:
                cout <<endl<<S.pop()<<endl;
                break;
            case 3:
                cout << endl<<S.peep()<<endl;
                break;
            case 4:
                cout << endl << "\tSize : "<< S.size() <<endl;
                break;
            case 5:
                if (S.isEmpty()){
                    cout << "Empty "<<endl;
                }else {
                    cout << "Not Empty "<<endl;
                }
                break;
        }
    }
    
    return 0;
}

