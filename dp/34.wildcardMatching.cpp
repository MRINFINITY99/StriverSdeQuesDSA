#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string&pattern,string&text,vector<vector<int>>&dp){
    if(i==0 && j==0)return true;
    if(i==0 && j>0)return false;
    if(j==0 && i>0){
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(pattern[i-1]==pattern[j-1] || pattern[i-1]=='?')
        return dp[i][j]= f(i-1,j-1,pattern,text,dp);
    if(pattern[i-1]=='*'){
        return dp[i][j]= f(i-1,j,pattern,text,dp)
                | f(i,j-1,pattern,text,dp);
    }
    return dp[i][j]=false;
}

bool wildcardMatching(string pattern,string text){
    int n=pattern.size();
    int m=text.size();
    vector<bool>prev(m+1,false),cur(m+1,false);
    prev[0]=true;
    //here we assign the 0th row with false 
    for(int j=1;j<=m;j++){
        prev[j]=false;
    }    
    
    for(int i=1;i<=n;i++){
        //here the assigning values to 1st row is start 
        //we will assign the value in 1st row 
        bool flag=true;
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1]!='*'){
                flag=false;
                break;
            }
        }
        cur[0]=flag;
        for(int j=1;j<=n;j++){
            if(pattern[i-1]==pattern[j-1] || pattern[i-1]=='?')
                return cur[j]= prev[j-1];
            else if(pattern[i-1]=='*'){
                return cur[j]= prev[j] | cur[j-1];
            }
            else cur[j]=false;
        }
        prev=cur;
    }

    return prev[m];
}


//tabulation
// bool wildcardMatching(string pattern,string text){
//     int n=pattern.size();
//     int m=text.size();
//     vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
//     dp[0][0]=true;
//     for(int j=1;j<=m;j++){
//         dp[0][j]=false;
//     }
//     for(int i=1;i<=n;i++){
//         bool flag=true;
//         for(int ii=1;ii<=i;ii++){
//             if(pattern[ii-1]!='*'){
//                 flag=false;
//                 break;
//             }
//         }
//         dp[i][0]=flag;
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(pattern[i-1]==pattern[j-1] || pattern[i-1]=='?')
//                 return dp[i][j]= dp[i-1][j-1];
//             else if(pattern[i-1]=='*'){
//                 return dp[i][j]= dp[i-1][j] | dp[i][j-1];
//             }
//             else dp[i][j]=false;
//         }
//     }

//     return dp[n][m];
// }