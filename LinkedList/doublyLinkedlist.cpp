/* 
 * File:   Linkedlist.cpp
 * Author: Abhishek Mule
 * Nick Name: technical_geek
 Here is implementation of data Structure doubly linked list using C++
 It includes operation of adding new elements at any position / deleting elements at any position
 & also accessing elements
 * Created on 6 March, 2020, 11:19 PM
 */

#include <iostream>

using namespace std;

//definition of doubly Linked List
class DoublyLinkedList{
private:
    struct NODE{
        int data;
        struct NODE *next;
        struct NODE *previous;
    };
    struct NODE *head;
    struct NODE *tail;
    
public :
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    void append(int d){
        struct NODE *newNode = new NODE;
        newNode->next = NULL;
        newNode->previous = NULL;
        newNode->data = d;
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            struct NODE *ptr = new NODE;
            ptr = head;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->previous = ptr;
            tail = newNode;
        }
    }
    
    void traverse_leftToright(){
        struct NODE *ptr = new NODE;
        ptr = head;
        cout<<endl<<endl;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout <<endl<<endl;
        delete ptr;
    }
    
    void traverse_rightToleft(){
        struct NODE *ptr = new NODE;
        ptr = tail;
        cout<<endl<<endl;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->previous;
        }
        cout <<endl<<endl;
        delete ptr;
    }
    
    void insert(int d){
        
        struct NODE *newNode = new NODE;
        newNode->data = d;
        struct NODE *ptr = new NODE;
        ptr = head;
        int pos,i;
        cout << endl<< "Enter Position : ";
        cin >> pos;
        if (pos != 0){
        for (i = 0;i < pos;i++){
            ptr = ptr->next;
        }
        newNode->next=ptr;
        newNode->previous=ptr->previous;
        ptr->previous->next=newNode;
        ptr->previous=newNode;
        ptr = NULL;
        delete ptr;
        }
        else if (pos == 0){
            ptr = head;
            head = newNode;
            newNode->previous = NULL;
            newNode->next = ptr;
            ptr->previous = newNode;
            ptr = NULL;
            delete ptr;
        }
    }
    
    void delete_element(){
        int pos;
        int i;
        struct NODE *ptr = new NODE;
        cout << endl<< "Enter Position to Delete : ";
        cin >> pos;
        if (pos != 0){
            ptr = head;
            for(i = 0; i < pos; i++){
                ptr = ptr->next;
            }
            ptr->previous->next = ptr->next;
            ptr->next->previous = ptr->previous;
        }
        else if(pos == 0){
            ptr = head;
            head = ptr->next;
            ptr->next->previous = NULL;
        }
    }
};
/*
 * 
 */
int main(void) {
    DoublyLinkedList D;
   int value;
    int choice;
    cout<<endl<<endl;
    while (choice != 6){
        cout<<"1] Append element \n2] Insert in between \n3] Delete \n4] Print from left to right \n5] Print from right to left \n6] EXIT "<<endl;
        cout<< "\tChoose your choice : ";
        cin>> choice;
        cout<<endl<<endl;
        switch(choice){
            case 1:
                cout << "\t\t Enter Value (int) : ";
                cin >> value;
                D.append(value);
                break;
            case 2:
                cout << "\t\t Enter Value (int) : ";
                cin >> value;
                D.append(value);
                break;
            case 3:
                D.delete_element();
                break;
            case 4:
                D.traverse_leftToright();
                break;
            case 5:
                D.traverse_rightToleft();
        }
    }
    return 0;
}

