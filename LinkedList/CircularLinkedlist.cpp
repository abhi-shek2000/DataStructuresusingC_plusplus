/* 
 * File:   CircularLinkedlist.cpp
 * Author: Abhishek Mule
 * Nick Name: technical_geek
 Here is implementation of data Structure Circular linked list using C++
 It includes operation of adding new elements at any position / deleting elements at any position
 & also accessing elements
 * Created on 8 March, 2020, 12:54 PM
 */

#include <iostream>

using namespace std;

class CircularLinkedList{
private:
    struct NODE{
        int data;
        struct NODE *next;
    };
    struct NODE *head;
public:
    CircularLinkedList(){
        head = NULL;
    }
    void append(int d){
        struct NODE *newNode =  new NODE;
        newNode->data = d;
        if (head == NULL){
            head = newNode;
            newNode->next = head;
        }
        else{
            struct NODE *ptr =  new NODE;
            ptr = head;
            while (ptr->next!= head){
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = head;
        }
    }
    
    void print(){
        struct NODE *ptr = new NODE;
        ptr = head;
        int cnt = 0;
        cout <<endl<<endl<< ptr->data<< " ";
        ptr = ptr->next;
        while (ptr != head){
            cout << ptr->data<<" ";
            ptr = ptr->next;
        }
        cout <<endl<<endl;
    }
    int len(){
        struct NODE *ptr =  new NODE;
        ptr = head;
        int cnt= 1;
        if (head == NULL){
            return 0;
        }else{
        while (ptr->next != head){
            ptr = ptr->next;
            cnt += 1;
        }
        return cnt;
        }
    }
    
    void delete_element(){
        struct NODE *ptr = new NODE;
        int pos;
        int i;
        cout << "Enter position to insert : ";
        cin >> pos;
        ptr = head;
        for (i = 0; i < pos-1 ; i++){
            ptr = ptr->next;
        }
        struct NODE *temp = new NODE;
        temp = ptr;
        ptr = ptr->next;
        temp->next = ptr->next;
        delete ptr;
    }
    void insert(int d){
        struct NODE *ptr = new NODE;
        struct NODE *newNode = new NODE;
        int pos;
        int i;
        cout << "Enter position to insert : ";
        cin >> pos;
        newNode->data = d;
        if (pos != 0 && pos <= len()){
            cout << len()<<endl;
            ptr = head;
            for (i=0; i < pos-1; i++){
                
                ptr = ptr->next;
                
            }
            cout <<endl<<endl;
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        else if (pos == 0){
            cout << "\tUnable to insert "<<endl;
            return;
        }
        else if (pos > len()){
            cout << "\t Use the append option !"<<endl;
        }
    }
    
    
};

/*
 * 
 */
int main(void) {
    CircularLinkedList C;
    int value;
    int choice;
    cout<<endl<<endl;
    while (choice != 6){
        cout<<"1] Append element \n2] Insert in between \n3] Delete \n4] Print \n5] get length \n6] EXIT"<<endl;
        cout<< "\tChoose your choice : ";
        cin>> choice;
        cout<<endl<<endl;
        switch(choice){
            case 1:
                cout << "\t\t Enter Value (int) : ";
                cin >> value;
                C.append(value);
                break;
            case 2:
                cout << "\t\t Enter Value (int) : ";
                cin >> value;
                C.insert(value);
                break;
            case 3:
                C.delete_element();
                break;
            case 4:
                C.print();
                break;
            case 5:
                cout<<endl<<"\tLength : "<<C.len()<<endl;
                break;
        }
    }
    return 0;
}

