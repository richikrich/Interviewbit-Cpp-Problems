#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

bool diffK(vector<int> &A, int k)
{
    int i=0, j, n=A.size();
    while(i<A.size()-1 && A[i]+k<=A[n-1])
    {
        j=i+1;
        while(j<A.size() && A[i]+k>=A[j])
        {
            if(A[j]==A[i]+k) return true;
            else j++;
        }
        i++;
    }
    return false;
}

int main()
{
    int n, temp, k;
    vector<int> vect;
    cout<<"Length of vector: "; cin>>n;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>> temp;
        vect.push_back(temp);
    }
    cout<<"Vector you entered is: ";
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" "; cout<<endl;
    cout<<"Required difference: "; cin>>k;
    bool result=diffK(vect, k);
    if(result) cout<<"YES";
    else cout<<"NO";
    return 0;
}
