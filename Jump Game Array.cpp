#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int> &A)
{
    if(A.size()==1) return true;
    if(A[0]==0) return false;
    vector<bool> isit;//A.size(),false};
    isit.push_back(true);
    for(int i=0; i<A.size()-1; i++) isit.push_back(false);
    int j;
    for(int i=0;i<A.size();i++)
    {
        if(isit[i])
        {
            j=0;
            while(j<=A[i] && i+j<A.size())
            {
                if(!isit[i+j]) isit[i+j]=true;
                j++;
            }
        }
    }
    return isit[A.size()-1];
}


int main()
{
    cout<<"Enter the number of elements: ";
    int n, temp; cin>>n;
    vector<int> vect;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The vector you entered is: ";
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" ";
    cout<<endl;
    bool result=canJump(vect);
    if(result) cout<<"Can do"<<endl;
    else cout<<"No can do"<<endl;
    return 0;
}
