#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

vector<int> arrayIntersect(vector<int> &A, vector<int> &B)
{
    vector<int> ret; int i=0, j=0;
    while(i<A.size() && j<B.size() && A[i]<=B[B.size()-1] && B[j]<=A[A.size()-1])
    {
        //cout<<"i: "<<i<<" j: "<<j<<" A[i]: "<<A[i]<<" B[j]: "<<B[j]<<endl;
        if(A[i]==B[j])
        {
            ret.push_back(A[i]);
            i++;
            j++;
        }
        if(A[i]<B[j]) i++;
        if(A[i]>B[j]) j++;
    }
    return ret;
}

int main()
{
    cout<<"Enter the size of the two arrays: ";
    int m,n, temp; cin>>m>>n;
    vector<int> A,B;
    cout<<"Input A: ";
    for(int i=0; i<m; i++)
    {
        cin>>temp;
        A.push_back(temp);
    }
    cout<<"Input B: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        B.push_back(temp);
    }
    cout<<"The vectors you entered are: \n";
    cout<<"A: "; for(int i=0;i<A.size(); i++) cout<<A[i]<<" ";
    cout<<endl;
    cout<<"B: "; for(int i=0;i<B.size(); i++) cout<<B[i]<<" ";
    cout<<endl;
    vector<int> result=arrayIntersect(A,B);
    cout<<"Result: ";
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
