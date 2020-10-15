#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int costFill(vector<vector<int> > &A, vector<vector<int> > &costs, int M, int N)
{
    if(costs[M][N]!=-1) return costs[M][N];

    int ans=0, a, b;
    if(M-1>=0 && N-1>=0) ans+=A[M][N]+min(costFill(A, costs,M-1,N), costFill(A, costs,M,N-1));
    else if (M-1<0) ans+=A[M][N]+costFill(A,costs,M,N-1);
    else ans+=A[M][N]+costFill(A,costs,M-1,N);

    costs[M][N]=ans;
    return ans;
}

int Solution::minPathSum(vector<vector<int> > &A) {
    int M=A.size(), N=A[0].size();
    if(M==0 || N==0) return 0;
    vector<vector<int> > costs; vector<int > temp(N, -1);
    for(int i=0; i<M; i++) costs.push_back(temp);
    costs[0][0]=A[0][0];
    int ret=costFill(A, costs,M-1, N-1);
    return ret;
}
