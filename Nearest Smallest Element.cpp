#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
#include<stack>

using namespace std;

vector<int> nearestSmallest(vector<int> &A)
{
    vector<int> ret;
    stack<int> small;
    small.push(INT_MAX);
    for(int i=0; i<A.size();i++)
    {
        if(small.top()<A[i]) ret.push_back(small.top());
        else
        {
            while(!small.empty() && small.top()>=A[i])
            {
                small.pop();
            }
            if(small.empty()) ret.push_back(-1);
            else ret.push_back(small.top());
        }
        small.push(A[i]);
    }
    return ret;
}

int main()
{
    vector<int> vect; int n, temp;
    cout<<"Enter the size of your vector: "; cin>>n;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The vector is: ";
    for(int i=0; i<vect.size();i++) cout<<vect[i]<<" ";
    cout<<endl;
    vector<int> result=nearestSmallest(vect);
    cout<<"Result: ";
    for(int i=0; i<result.size();i++) cout<<result[i]<<" ";
    cout<<endl;
    //cout<<"Result: "<<result;
    return 0;
}
