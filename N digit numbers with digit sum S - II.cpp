#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int recursive(vector<vector<int> > &DP, int A, int B)
{
    int ret=0;
    if(A==0)
    {
        if(B==0) return 1;
        else return 0;
    }

    if(DP[A][B]!=-1) return DP[A][B];

    for(int i=0; i<=9; i++)
    {
        if(B-i>=0) ret=(ret+recursive(DP,A-1,B-i))%1000000007;
    }
    DP[A][B]=ret;
    return DP[A][B];
}

int Solution::solve(int A, int B) {
    vector<vector<int> > DP; vector<int> temp(B,-1);
    for(int i=0; i<A; i++) DP.push_back(temp);

    int ret=0;
    for(int i=1; i<=9; i++)
    {
        if(B-i>=0) ret=(ret+recursive(DP,A-1,B-i))%1000000007;
    }

    return ret;
}
