/*
 *Author : Abhishek Mule
 *Nick Name : technical_geek
 *Welcome this is a short program showing the implementation of static arrays
  This program includes creating an array / accessing its elements / Adding new elements 
  at the end, in the middle, at the beginning of array and also 
 *deleting elements at the end, in the middle, at the beginning
  Created DATE : 06/03/2020   
 */

#include<iostream>
using namespace std;

int main(void){
    //One dimentional array
    int array[11];
    int i;
    int cnt;
    short int n;
    short int pos;
    int value;
    int temp;
    cout << "Enter Number of elements you want in array : ";
    cin >> n;
    //Adding elements to the array
    cout << "Enter Elements : ";
    for(i=0; i < n; i++){
        cin>>array[i];
    }
    //Printing the added elements
    cout<<"Added Elements are : \t";
    for(i=0; i< n; i++){
        cout << array[i] << " ";
    }
    //deleting element at the end
    //We cant actually deallocate memory of an array in C++ which is statically created
    //So here the logic is we print values till n - 1 "Yes it's that simple :p"
    n -= 1;
    cout<< "\n \n" ;
    cout << "Array After deletion of last element : \t ";
    for(i=0; i< n; i++){
        cout << array[i] << " ";
    }
    
    //Deleting element from middle
    //Here the logic is we replace all the elements from the position entered with element at next position(Pretty Simple !)
    cout << "\nEnter position to delete : ";
    cin >> pos;
    if (pos == n){
        n -= 1;
    }
    else if(pos < n && pos >= 0){
        for (i = pos;i < n-1;i++){
            array[i] = array[i+1];
        }
        n -= 1;
    }
    cout << "\nArray after deletion : \t ";
    for(i=0; i< n; i++){
        cout << array[i] << " ";
    }
    
    //Adding elements in middle of array
    //Here logic is similar to the logic of deletion
    
    cout << "\nEnter position to add : ";
    cin >> pos;
    cout << "\nEnter Value : ";
    cin >> value;
    if(pos > sizeof(array)/sizeof(int)){
        cerr<< "Position exceeds length of array";
    }
    else{
        for(i = n; i >= pos; i--){
            array[i+1] = array[i];
        }
        array[pos] = value;
    }
    n += 1;
    for(i=0; i< n; i++){
        cout << array[i] << " ";
    }
    
}
