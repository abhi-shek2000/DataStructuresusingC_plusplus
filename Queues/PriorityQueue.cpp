/* 
 * File:   stack.h
 * Author: Abhishek Mule
 * Basic implementation of Priority QUEUE
 * Created on 21 March, 2020, 12:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

typedef struct NODE{
    string name;
    int prio;
    struct NODE * next;
    struct NODE * prev;
}NODE;

class Priority_Queue{
private :
    NODE * front;
    NODE * rear;
public :
    Priority_Queue(){
        front = NULL;
        rear = NULL;
    }
    
    void enqueue(int prio){
        NODE * new_node = new NODE;
        new_node->next = NULL;
        new_node->prev = NULL;
        cout << "Name : ";
        cin >> new_node->name;
        new_node->prio = prio;
        if (front == NULL && rear == NULL){
            front = new_node;
            rear = new_node;
        }else {
            NODE *ptr = rear;
            ptr->prev = new_node;
            new_node->next = ptr;
            rear = new_node;
        }
    }
    
    void print (){
        string type;
        
        int cnt = 0;
        NODE * ptr = new NODE;
        ptr = front;
        cout << endl;
        while (ptr != NULL){
            switch(ptr->prio){
                case 1:
                    type = "Needs to be treated immediately ";
                    break;
                case 2:
                    type = "Very High ";
                    break;
                case 3:
                    type = "High";
                    break;
                case 4:
                    type = "Moderate";
                    break;
                case 5:
                    type = "Low";
                    break;  
            }
            cnt += 1;
            cout << cnt << "]" << ptr->name << " " << "( " << type << ") " << endl;
            ptr = ptr->prev;
        }
        cout << endl <<endl;
    }
    
    void dequeue(){
        NODE * ptr;
        ptr = new NODE;
        string type;
        ptr = front;
        switch(ptr->prio){
                case 1:
                    type = "Needed to be treated immediately ";
                    break;
                case 2:
                    type = "Very High ";
                    break;
                case 3:
                    type = "High";
                    break;
                case 4:
                    type = "Moderate";
                    break;
                case 5:
                    type = "Low";
                    break;  
            }
        cout << endl;
        cout << "Patient Discharged : " << ptr->name << " ( " << type << ") "<<endl;
        front = ptr->prev;
                
    }
    
    void insert(int pr){
        NODE * new_node;
        int flag = 0;
        new_node = new NODE;
        new_node->prio = pr;
        cout << "Name : ";
        cin >> new_node->name;
        NODE * ptr = new NODE;
        ptr = rear;
        while (ptr->prio > pr){
            if (ptr->next == NULL){
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 1){
            if (ptr->prio > pr){
                ptr->next = new_node;
                new_node->prev = ptr;
                new_node->next = NULL;
                front = new_node;
            }
        }
        else {
        ptr->prev->next = new_node;
        new_node->prev = ptr->prev;
        new_node->next = ptr;
        ptr->prev = new_node;
        }
        }
    
    int get_prev_prio(){
        NODE * ptr = new NODE;
        ptr = rear;
        if (ptr != NULL){
        return ptr->prio;
        }
        else {
            return -1;
        }
    }
    
};

int main(){
    Priority_Queue P;
    int prio;
    int choice;
    while (choice != 4)  {
        cout << "\tPatients Priority : \n\t\t1] Need to be treated immediately \n\t\t2] Very High \n\t\t3] High \n\t\t4] Moderate "
                "\n\t\t5] Low "<<endl;
        cout << "1] Register new patient\n2] Check list of patients \n3] Treat Patient \n4] EXIT" << endl;
        cout << "Choice : ";
        cin >> choice;
        if (choice == 4){
            break;
        }
        switch(choice){
            case 1 :
                cout << "Enter Priority : ";
                cin >> prio;
                if (P.get_prev_prio() > prio){
                    P.insert(prio);
                }else{
                    P.enqueue(prio);
                }
                break;
            case 2:
                cout << endl << "LIST OF PATIENTS " ;
                P.print();
                break;
            case 3:
                P.dequeue();
                cout << endl;
                break;
        }
    }
}