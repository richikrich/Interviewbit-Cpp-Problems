#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

//multiple unbounded knapsack problem
int knapSack(const vector<int> &B, const vector<int> &C, int F, int dish, vector<vector<int >> &DP) //top-down unbounded knapsack
{
    if(DP[dish][F]!=-1) return DP[dish][F];
    int ret=0;
    if(B[dish-1]<=F) DP[dish][F]=min(knapSack(B,C,F,dish-1,DP),C[dish-1]+knapSack(B,C,F-B[dish-1],dish,DP));
    else DP[dish][F]=knapSack(B,C,F,dish-1,DP);
    ret=DP[dish][F];
    return ret;
}

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    //friends=A, dish=B, dish_cost=C
    int W=*max_element(A.begin(), A.end()); //maximum capacity
    vector<vector<int> > DP;
    vector<int> temp(W+1,-1); temp[0]=0;
    for(int i=0; i<=B.size(); i++) DP.push_back(temp);
    for(int j=1; j<DP[0].size(); j++) DP[0][j]=10000000; //taking a suitable large integer since if zero capacity item means it'll never fill the knapsack
    /*for(int i=0; i<DP.size(); i++)
    {
        for(int j=0; j<DP[i].size(); j++) cout<<DP[i][j]<<" ";
        cout<<endl;
    }
    //return 0;*/
    int ret=0;
    for(int i=0; i<A.size(); i++) ret+=knapSack(B,C,A[i],B.size(),DP);
    return ret;
}
