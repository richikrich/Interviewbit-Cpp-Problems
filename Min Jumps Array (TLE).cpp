#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int minJumps(vector<int> &A)
{
    int n=A.size(), j;
    if(A[0]==0) return -1;
    vector<int> jumps(n,0);
    for(int i=0; i<n-1; i++)
    {
        if(jumps[n-1]!=0) return jumps[n-1];
        if(jumps[i]!=0 || i==0){
        j=1;
        while(j<=A[i] && i+j<=n-1)
        {
            if(jumps[i+j]==0) jumps[i+j]=jumps[i]+1;
            else jumps[i+j]=min(jumps[i+j],jumps[i]+1);
            j++;
        }}
    }
    if(jumps[n-1]==0) return -1;
    else return jumps[n-1];
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
