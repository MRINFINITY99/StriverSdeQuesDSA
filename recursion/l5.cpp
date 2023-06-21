#include<bits/stdc++.h>
using namespace std;

//multiple recursion call
//fibonacci no.

int fun(int i){
    if(i<=1){return i;}
    int last=fun(i-1);
    int slast=fun(i-2);
    return last+slast;
}