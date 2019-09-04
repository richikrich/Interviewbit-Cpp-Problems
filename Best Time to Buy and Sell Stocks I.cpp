#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int maxProfit(const vector<int> &A) {
    if(A.size()<=1) return 0;
    int min=A[0],profit=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]<min) min=A[i];
        else if(A[i]-min>profit) profit=A[i]-min;
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
