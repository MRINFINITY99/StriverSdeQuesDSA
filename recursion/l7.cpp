#include<bits/stdc++.h>
using namespace std;

//all possible subsequence whose sum equal to sum
void printS(int ind,vector<int>&ds,int s,int sum,int arr[],int n){
    if(ind==n){
        if(s==sum){
            for(auto it:ds)cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    printS(ind+1,ds,s,sum,arr,n);
    s-=arr[ind];
    ds.pop_back();
    printS(ind+1,ds,s,sum,arr,n);
}

//print only one subsequence 
bool printS2(int ind,vector<int>&ds,int s,int sum,int arr[],int n){
    if(ind==n){
        if(s==sum){
            for(auto it:ds)cout<<it<<" ";
            cout<<endl;
            return true;
        }
        else return false;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(printS2(ind+1,ds,s,sum,arr,n)==true){return true;}
    s-=arr[ind];
    ds.pop_back();
    if(printS2(ind+1,ds,s,sum,arr,n)==true){return true;}
    return false;
}

//count the no. of possible subsequence
int printS3(int ind,vector<int>&ds,int s,int sum,int arr[],int n){
    if(ind==n){
        if(s>=sum)return 0;
        if(s==sum)return 1;
        else return 0;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    int l=printS3(ind+1,ds,s,sum,arr,n);
    s-=arr[ind];
    ds.pop_back();
    int r=printS3(ind+1,ds,s,sum,arr,n);
    return l+r;
}

int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    cout<<printS3(0,ds,0,sum,arr,n);
    return 0;
}