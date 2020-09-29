#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int Solution::solve(string A) {
    /**
      *Since the palindromic sequence does not need to be contiguous, we can check if A[i]==A[j] and if that is so add 2 to
      *the length of the longest palindromic sequence before that. If that is not so, the longest palindromic sequence in the
      *interval [i,j] will be the maximum of that between [i+1,j] and [i,j-1].
    **/
    int n=A.size(), j;
    vector<vector<int>> LPS;
    vector<int> rows(n,0);
    for(int i=0; i<n; i++) LPS.push_back(rows);
    for(int diff=0; diff<n; diff++)
    {
        for(int i=0; i<n; i++)
        {
            j=i+diff;
            if(j<n)
            {
                if(diff==0) LPS[i][j]=1;
                else if(diff==1)
                {
                    if(A[i]==A[j]) LPS[i][j]=2;
                    else LPS[i][j]=1;
                }
                else
                {
                    if(A[i]==A[j]) LPS[i][j]=LPS[i+1][j-1]+2;
                    else LPS[i][j]=max(LPS[i+1][j], LPS[i][j-1]);
                }
            }
        }
    }
    /*for(int i=0; i<LPS.size(); i++)
    {
        for(int j=0; j<LPS[i].size(); j++) cout<<LPS[i][j]<<" ";
        cout<<endl;
    }*/

    return LPS[0][n-1];
}
