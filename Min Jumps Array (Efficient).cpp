#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int minJumps(vector<int> &A)
{
    int n=A.size();
    if(n==1) return 1;
    if(A[0]==0) return -1;
    int max_reach=A[0], steps=A[0], jumps=1;
    for(int i=1; i<n; i++)
    {
        if(i==n-1) return jumps;
        max_reach=max(max_reach,i+A[i]);
        steps--;
        if(steps==0)
        {
            jumps+=1;
            steps=max_reach-i;
            if(i>=max_reach) return -1;
        }
    }
    return -1;
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
    int result=minJumps(vect);
    cout<<"Results: "<<result<<endl;

    return 0;
}
