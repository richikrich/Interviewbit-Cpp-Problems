#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int removeDuplicatesSorted(vector<int> &A)
{
    vector<int> ret;
    int j=1;
    ret.push_back(A[0]);
    while(j<A.size())
    {
        if(A[j]==ret[ret.size()-1]) j++;
        else
        {
            ret.push_back(A[j]);
            j++;
        }
    }
    A=ret;
    return A.size();
}

int main()
{
    int n, temp;
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
    //cout<<"Required difference: "; cin>>k;
    int result=removeDuplicatesSorted(vect);
    cout<<"Resultant length: "<<result<<endl;
    cout<<"Resultant array: ";
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" "; cout<<endl;
    return 0;
}
