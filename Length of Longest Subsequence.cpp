#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

vector<int> incrSubLen(vector<int> &A)
{
    vector<int> lenIncr(A.size(),1); ///initiate length of increasing subsequences to 1 for all elements
    for(int i=1; i<A.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[j]<A[i]) lenIncr[i]=max(lenIncr[i],lenIncr[j]+1);
        }
    }
    return lenIncr;
}

vector<int> decrSubLen(vector<int> &A)
{
    vector<int> lenDecr(A.size(),1); ///initiate length of increasing subsequences to 1 for all elements
    int n=A.size();
    for(int i=n-2; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {
            if(A[j]<A[i]) lenDecr[i]=max(lenDecr[i],lenDecr[j]+1);
        }
    }
    return lenDecr;
}

int lenSubSeq(vector<int> &A)
{
    vector<int> lenIncr=incrSubLen(A), lenDecr=decrSubLen(A);
    int ret=0;
    for(int i=0; i<A.size(); i++) ret=max(ret,lenIncr[i]+lenDecr[i]-1);
    return ret;
}

int main()
{
    int n, temp;
    vector<int> vect;
    cout<<"Enter the length of your array: "; cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    int result=lenSubSeq(vect);
    cout<<"Result: "<<result<<" ";
    return 0;
}
