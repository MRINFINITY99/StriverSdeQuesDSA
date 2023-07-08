#include<bits/stdc++.h>
using namespace std;

int buySellFees(vector<int>&values,int fee,int n){
    int aheadNotBuy,aheadBuy,curBuy,curNotBuy;
    aheadNotBuy=aheadBuy=0;
    for(int ind=n-1;ind>=0;ind--){
    
                curNotBuy=max(values[ind]-fee+aheadBuy,
                            0+aheadNotBuy);
                curBuy=max(-values[ind]+aheadNotBuy,
                            0+aheadBuy);
        aheadBuy=curBuy;
        aheadNotBuy=curNotBuy;
    }
    return aheadBuy;
}