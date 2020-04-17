#include <iostream>
#include <limits>
#include <vector>
#include <math.h>
using namespace std;

vector <int> split(const string &s){
    string str(s);
    vector <int> vec;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ",start)) != string::npos ){
        vec.push_back(stoi(str.substr(start,end-start)));
        start = end + 1;
    }
    vec.push_back(stoi(str.substr(start)));
    return vec;
}

void merge(vector<int> &vec, int p, int q, int r){
    vector<int> L;
    vector<int> R;
    for(int i = p; i <= q; i++){
        L.push_back(vec[i]);
    }
    L.push_back(999999);
    for(int i = q+1; i <= r; i++){
        R.push_back(vec[i]);
    }
    R.push_back(999999);
//    for (auto i : L){
//        cout << i << " ";
//    }
//    cout << endl;
//    for (auto i : R){
//        cout << i << " ";
//    }
//    cout << endl;
    size_t i = 0;
    size_t j = 0;
    
    for (int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            vec[k] = L[i];
            i ++;
        }else{
            vec[k] = R[j];
            j ++;
        }
    }
    
}

void mergeSort(vector<int> &vec, int p, int r){
    if (p < r){
        int q = floor((p+r)/2);
        mergeSort(vec,p,q);
        mergeSort(vec,q+1,r);
        merge(vec,p,q,r);
    }
    
}

int main(){
    vector <int> vec;
    string s;
    cout << "Enter integers to sort : ";
    getline(cin,s);
    vec = split(s);
    int size = vec.size() - 1;
    mergeSort(vec,0,size);
    cout << "Sorted integers are : ";
    for (auto i : vec){
        cout << " " << i << " " ;
    }
}