#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int maxProfit(const vector<int> &A) {
if(A.size()<=1) return 0;
    int i=0, j, profit=0;
    while(i<A.size()-1)
    {
        while(i<A.size()-1 && A[i]>=A[i+1]) i++;
        //cout<<i<<" "<<A[i]<<" ";
        if(i==A.size()-1) break;
        j=i+1;
        while(j<A.size() && A[j]>=A[j-1]) j++;
        //cout<<j-1<<" "<<A[j-1]<<" ";
        profit+=A[j-1]-A[i];
        //cout<<profit<<endl;
        i=j;
    }
    return profit;
}

int main()
{
    cout<<"Enter the number of days market you want to consider: ";
    int n, temp; cin>>n;
    vector<int> vect;
    cout<<"Data: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The data you entered is: "<<endl;
    for(int j=0; j<n; j++) cout<<vect[j]<<" ";
    cout<<endl;
    int result=maxProfit(vect);
    cout<<"Result: "<<result<<endl;
    return 0;
}
