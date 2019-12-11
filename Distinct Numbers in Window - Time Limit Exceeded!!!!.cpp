#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

using namespace std;

vector<int> distinctWindow (vector<int> &A, int B)
{
    map<int, int> counter;
    vector<int> ret;
    int j;
    for(int i=0; i<A.size()-B+1; i++)
    {
        j=0;
        while(j<B)
        {
            counter[A[i+j]]++;
            j++;
        }
        cout<<endl<<counter.size()<<endl;
        ret.push_back(counter.size());
        counter.clear();
    }
    return ret;
}

int main()
{
    int n, temp, k;
    vector<int> vect;
    cout<<"Enter the number of elements in your array: "; cin>>n;
    cout<<"Enter your array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"Enter the window size: "; cin>>k;
    /**Inputs**/
    cout<<"Your preferred window size is: "<<k<<" \nThe array you entered is: ";
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" ";
    cout<<endl;
    /***/
    /**Results**/
    vector<int> results=distinctWindow(vect,k);
    cout<<"Results: ";
    for(int i=0; i<results.size(); i++) cout<<results[i]<<" ";
    cout<<endl;
    /****/
    return 0;
}
