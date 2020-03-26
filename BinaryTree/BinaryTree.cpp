/* 
 * File:   BinaryTree.cpp
 * Author: Abhishek Mule
 * Basic Implementation of BinaryTree 
 * Created on 22 March, 2020, 7:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>

#include "stack.h"
using namespace std;

typedef struct NODE{
    int data;
    struct NODE *left;
    struct NODE *right;
    NODE(){
        left = right = NULL; 
    }
}NODE;

class BinaryTree{
private :
    NODE * root;
public :
    BinaryTree(){
        root = NULL;
    }
    
    void insert(int d){
        NODE * new_node = new NODE;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->data = d;
        if (root == NULL){
            root = new_node;
        }else {
            NODE * ptr;
            NODE * parent;
            ptr = root;
            while (ptr != NULL){
                parent = ptr;
                if (d > ptr->data)
                    ptr = ptr->right;
                else if (d <= ptr->data)
                    ptr = ptr->left;
            }
            if (d > parent->data)
                parent->right = new_node;
            else
                parent->left = new_node;
        }
    }
    void InorderPrint(){
        cout << "Inorder : ";
        InorderNodePrint(root);
        cout << endl;
    }
    void PreOrderPrint(){
        cout << "PreOrder : ";
        PrerderNodePrint(root);
        cout << endl;
    }
    void PrerderNodePrint(NODE * ptr){
        if (ptr != NULL){
            PrerderNodePrint(ptr->left);
            PrerderNodePrint(ptr->right);
            cout << ptr->data << " ";
        }
    }
    
    void InorderNodePrint(NODE *ptr){
        if (ptr!=NULL){
            InorderNodePrint(ptr->left);
            cout << ptr->data << " ";
            InorderNodePrint(ptr->right);
        }
    }
    
    void PostOrderPrint(){
        cout << "PostOrder : ";
        PostNodePrint(root);
        cout << endl;
    }
    void PostNodePrint(NODE * ptr){
        if (ptr!=NULL){
            cout << ptr->data << " ";
            PostNodePrint(ptr->left);
            PostNodePrint(ptr->right);
        }
    }
    
    void InorderNonRecursive(){
        
    { 
    stack<NODE *> s; 
    NODE *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL) 
        { 
            s.push(curr); 
            curr = curr->left; 
        } 
  
        curr = s.top(); 
        s.pop();
  
        
        cout << curr->data << " "; 
  
        curr = curr->right; 
  
    }
     }
    }
};

int main(void) {
    BinaryTree B;
    int choice; 
    int val;
    cout << "\t\tBINARY TREE "<<endl<<endl;
    while(true){
        cout << "1] Insert \n2] Inorder Traversal\n3] Preorder Traversal\n4] Postorder Traversal\n5] EXIT "<< endl;
        cout << "Choice : ";
        cin >> choice;
        if (choice == 5){
            break;
        }else {
            switch(choice){
                case 1:
                    cout << "Value : ";
                    cin >> val;
                    B.insert(val);
                    break;
                case 2:
                    B.InorderPrint();
                    break;
                case 3:
                    B.PreOrderPrint();
                    break;
                case 4:
                    B.PostOrderPrint();
                    break;
            }
        }
    }
    
    return 0;
}

