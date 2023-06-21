#include<bits/stdc++.h>
using namespace std;

//print name n times 
void f(int i,int n){
    if(i>n)return;
    cout<<"raj";
    f(i+1,n);
}

//print linearly 1 to n
void f1(int i,int n){
    if(i>n)return;
    cout<<i;
    f(i+1,n);
}

//print n to 1
void f2(int i,int n){
    if(i<1)return;
    cout<<i;
    f2(i-1,n);
}

//print from 1 to n(backtrack)
void f3(int i,int n){
    if(i<1)return;
    f(i-1,n);
    cout<<i;
}

//print from n to 1
void f4(int i,int n){
    if(i>=n)return;
    f(i+1,n);
    cout<<i;
}