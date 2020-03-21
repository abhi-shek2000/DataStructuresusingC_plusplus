/* 
 * File:   stack.h
 * Author: Abhishek Mule
 * Basic implementation of QUEUE
 * Created on 10 March, 2020, 4:26 PM
 */

#include <iostream>

using namespace std;

class QUEUE{
private:
    struct NODE{
        int data;
        struct NODE *next;
        struct NODE *prev;
    };
    struct NODE *front;
    struct NODE *rear;
public:
    QUEUE(){
        front = NULL;
        rear = NULL;
    }
    
    void enqueue(int d){
        struct NODE *newNode = new NODE;
        newNode->data = d;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (front == NULL && rear == NULL){
            front = newNode;
            rear = newNode;
        }else {
            struct NODE *ptr = new NODE;
            ptr = rear;
            ptr->prev = newNode;
            newNode->next = ptr;
            rear = newNode;
        }
    }
    
    void print_queue(){
        struct NODE *ptr = new NODE;
        ptr = rear;
        if (front != NULL){
        do{
            cout << ptr->data << " ";
            ptr = ptr->next;
        }while(ptr != NULL);
        cout << endl<<endl;
        }
        else{
            cout << "Queue Empty ! "<<endl;
        }
        }
    
    void dequeue(){ 
        struct NODE *ptr = new NODE;
        ptr = front;
        if (front->prev != NULL){
        front = front->prev;
        front ->next = NULL;
        //delete ptr;
        ptr = NULL;
        }
        else {
            front = NULL;
            ptr = NULL;
            rear = NULL;
        }
    }
    
};

/*
 * 
 */
int main(void) {
    QUEUE Q;
    cout << "\tBASIC QUEUE OPEARTIONS ! "<<endl;
    int choice;
    int value;
    cout <<endl<<endl;
    while (choice != 4){
    cout << "1] Enqueue\n2] Dequeue\n3] Print \n4] EXIT"<<endl;
    cout << "Choice : ";
    cin >> choice;
    switch(choice){
        case 1:
            cout << "Enter Value : ";
            cin >> value;
            Q.enqueue(value);
            break;
        case 2:
            Q.dequeue();
            break;
        case 3:
            Q.print_queue();
            break;
    }
    }
    return 0;
}

