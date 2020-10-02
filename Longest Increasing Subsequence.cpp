#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int Solution::lis(const vector<int> &A) {
    vector<int> LIS(A.size(),1);
    int maxim=1;
    for(int i=1; i<A.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[i]>A[j])
            {
                if(LIS[i]<=LIS[j])
                {
                    LIS[i]=LIS[j]+1;
                    maxim=max(LIS[i],maxim);
                }
            }
        }
    }
    return maxim;
}
