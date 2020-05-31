#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

using namespace std;

vector<int> order(vector<int> &A, vector<int> &B)
{
    map<int, int> infronts;
    for(int i=0; i<A.size(); i++) infronts[A[i]]=B[i];
    vector<int> line(A.size(),INT_MIN);
    for(auto itr=infronts.begin(); itr!=infronts.end(); itr++)
    {
        int count=0, i=0;
        while(count!=itr->second)
        {
            if(line[i]<0) count++;
            i++;
        }
        while(line[i]>=0)
        {
            i++;
        }
        line[i]=itr->first;
    }
    return line;
}

int main()
{
    int n, temp;
    vector<int> heights, infrontofs;
    cout<<"Enter the number of people in the queue: "; cin>>n;
    cout<<"Enter the heights of the people: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        heights.push_back(temp);
    }
    cout<<"Enter the number of people taller than them, who are in-front of them resp.: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        infrontofs.push_back(temp);
    }
    cout<<"The heights you entered are: "; for(int i=0; i<n; i++) cout<<heights[i]<<" ";
    cout<<endl;
    cout<<"The respective number of taller people in-front are: "; for(int i=0; i<n; i++) cout<<infrontofs[i]<<" ";
    cout<<endl;
    vector<int> result=order(heights,infrontofs);
    for(int i=0; i<result.size();i++) cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
