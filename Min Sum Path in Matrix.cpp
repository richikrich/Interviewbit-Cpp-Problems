#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

/**int minPathRecursion(vector<vector<int> > &A, int r, int c)
{
    if(r<0 || c<0) return INT_MAX;
    if(r==0 && c==0) return A[r][c];
    else return (min(min(minPathRecursion(A,r-1,c),minPathRecursion(A,r,c-1)),minPathRecursion(A,r-1,c-1)))+A[r][c];
}
This is computationally very heavy ;_;
Instead we'll use dynamic programming
**/

int minPathSum(vector<vector<int> > &A)
{
    int r=A.size(); int c=A[0].size();
    //cout<<r<<" "<<c<<endl;
    vector<vector<int> > cost;
    vector<int> temp(c,0);
    for(int i=0; i<r; i++) cost.push_back(temp);
    cost[0][0]=A[0][0];
    if(r>1)
    {for(int i=1; i<r; i++) cost[i][0]=cost[i-1][0]+A[i][0];}
    if(c>1)
    {for(int i=1; i<c; i++) cost[0][i]=cost[0][i-1]+A[0][i];}
    if(r>1 && c>1)
    {for(int i=1; i<r; i++)
    {
        for(int j=1; j<c; j++)
        {
            cost[i][j]=A[i][j]+min(cost[i-1][j],cost[i][j-1]);
        }
    }}
    return cost[r-1][c-1];
}

int main()
{
    cout<<"Enter the dimensions of your string (row column): ";
    int m,n, tempo; cin>>m>>n;
    vector<vector<int>> vect;
    vector<int> temp;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>tempo;
            temp.push_back(tempo);
        }
        vect.push_back(temp);
        temp.clear();
    }
    cout<<"The matrix you entered is: "<<endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++) cout<<vect[i][j]<<" ";
        cout<<endl;
    }

    int result=minPathSum(vect);
    cout<<"Result: "<<result<<endl;
    return 0;
}
