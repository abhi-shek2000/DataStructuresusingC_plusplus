/* 
 * File:   working.cpp
 * Author: Abhishek Mule
 * Nick Name: technical_geek
 Welcome this is a short program showing the implementation of dynamic arrays
 This program includes creating an array / accessing its elements / Adding new elements 
 at the end, in the middle, at the beginning of array and also 
 deleting elements at the end, in the middle, at the beginning
 * Created on 6 March, 2020, 2:56 PM
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int* resize(int *p,size_t n){
    int *resized_arr;
    resized_arr = new int[n-1];
    int i;
    int value;
    for (i = 0;i < n-1;i++){
        resized_arr[i] = p[i];
    }
    delete p;
    p = NULL;
    return resized_arr;
}

int* incre_size(int *p,int n){
    int *resized_arr;
    resized_arr = new int[n+1];
    int i;
    int value;
    for (i = 0;i < n;i++){
        resized_arr[i] = p[i];
    }
    delete p;
    p = NULL;
    return resized_arr;
}
int main(void) {
    //Dynamically creating array of integers
    int *ptr;
    //int i;
    short int i;
    size_t n;
    cout <<"Enter Size of array : ";
    cin >>n;
    int pos;
    int value;
    ptr = new int[n];
    //Accepting elements
    cout <<"Enter elements : ";
    for(i=0 ;i<n; i++){
        cin >>ptr[i]; 
    }
    cout<<endl;
    //printing elements
    for(i=0 ;i<n; i++){
        cout << ptr[i] << ' '; 
    }
    //deleting last element from array 
    //Here logic is very simple create a function in that function create a new dynamic array of size one less than this
    ptr = resize(ptr,n);
    n -= 1;
    cout<<endl;
    for(i=0 ;i<n; i++){
        cout << ptr[i] << ' '; 
    }
    cout<<endl;
    //deleting element from middle of array
    cout<<"Enter position to delete : ";
    cin>>pos;
    if (pos==n){
        ptr = resize(ptr,n);
        n -= 1;
    }else{
        for(i = pos; i < n-1; i++){
            ptr[i] = ptr[i+1];
        }
        ptr = resize(ptr,n);
        n -= 1;
    }
    cout<<endl;
    for(i=0 ;i<n; i++){
        cout << ptr[i] << ' '; 
    }
    
    // Adding element to the array
    cout <<endl<< "Enter position to add element : ";
    cin >> pos;
    cout << "Enter Value : ";
    cin >> value;
    ptr = incre_size(ptr,n);
    n += 1;
    for (i = n; i >pos; i--){
        ptr[i] = ptr[i-1];
    }
    ptr[pos] = value;
    cout<<endl;
    for(i=0 ;i<n; i++){
        cout << ptr[i] << ' '; 
    }
    
}

