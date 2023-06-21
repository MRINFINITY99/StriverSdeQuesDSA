#include<bits/stdc++.h>
using namespace std;

//sum of first n numbers
//1.prameterized
int fp(int i,int sum){
    if(i==0){
        cout<<sum;
        return;
    }
    fp(i-1,sum+i);
}

//2.functional
int ff(int i){
    if(i==0) return 0;
    return i+ff(i-1);
}

//factorial of N
int fun(int i){
    if(i==0)return 1;
    return i*fun(i-1);
}