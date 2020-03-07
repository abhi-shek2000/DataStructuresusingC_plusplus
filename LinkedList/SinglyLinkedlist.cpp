/* 
 * File:   Linkedlist.cpp
 * Author: Abhishek Mule
 * Nick Name: technical_geek
 Here is implementation of data Structure singly linked list using C++
 It includes operation of adding new elements at any position / deleting elements at any position
 & also accessing elements
 *
 * Created on 6 March, 2020, 8:11 PM
 */

#include <iostream>
using namespace std;
//Definition of NODE of our linked list


//Linked list
class linkedList{
private :
    struct NODE{
    int data;
    struct NODE *next;
    };
    struct NODE *head;
public:
    linkedList(){
        head = NULL;
    }
    void add_new_Node(int d){
        struct NODE * newnode = new NODE;
        struct NODE * ptr = new NODE;
        newnode->data = d;
        newnode->next = NULL;
        if (head == NULL){
            head = newnode;
        }else{
            ptr = head;
            while (ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
    void print_list(){
        struct NODE * ptr = new NODE;
        ptr = head;
        cout<<endl<<endl;
        while(ptr != NULL){
            cout << ptr->data<<" ";
            ptr = ptr->next;
        }
        cout <<endl<<endl;
    }
    
    void delete_element(){
        int pos;
        int i;
        cout << "Enter position : ";
        cin >> pos;
        struct NODE * ptr = new NODE;
        struct NODE * temp = new NODE;
        ptr = head;
        if (pos != 0){
        for(i = 1; i < pos; i++){
            ptr = ptr->next; 
        }
        temp = ptr;
        ptr = ptr->next;
        temp->next = ptr->next;
        delete ptr;
        ptr = NULL;
        }else if(pos == 0){
            head = head->next;
            delete ptr;
        }    
    }
    
    void insert(int d){
        int pos;
        int i;
        cout << "Enter position : ";
        cin >> pos;
        struct NODE * newNode = new NODE;
        newNode->data = d;
        struct NODE * ptr = new NODE;
        struct NODE * temp = new NODE;
        ptr = head;
        if (pos != 0){
        for (i=1;i<pos;i++){
            ptr = ptr->next;
        }
        temp = ptr;
        ptr = ptr->next;
        newNode->next = ptr;
        temp->next = newNode;
        delete temp;
        delete ptr;
        }
        else if(pos == 0){
            ptr = head;
            head = newNode;
            newNode->next = ptr;
            
        }
    }
    
};
/*
 * 
 */
int main(void) {
    linkedList L;
    int value;
    int choice;
    cout<<endl<<endl;
    while (choice != 5){
        cout<<"1] Append element \n2] Insert in between \n3] Delete \n4] Print \n5] EXIT "<<endl;
        cout<< "\tChoose your choice : ";
        cin>> choice;
        cout<<endl<<endl;
        switch(choice){
            case 1:
                cout << "\t\t Enter Value (int) : ";
                cin >> value;
                L.add_new_Node(value);
                break;
            case 2:
                cout << "\t\t Enter Value (int) : ";
                cin >> value;
                L.insert(value);
                break;
            case 3:
                L.delete_element();
                break;
            case 4:
                L.print_list();
                break;
        }
    }
    return 0;
}

