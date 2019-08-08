#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int searchPivot(vector<int> &A)
{
    int ret=0;
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]<A[i-1])
        {
            ret=i; break;
        }
    }
    return ret;
}

int arrayIndex(vector<int> &A, int k, int i)
{
    int ret;
    if(i+k<A.size()) ret=(i)+k;
    else ret=(i+k)-A.size();
    return ret;
}

int binarySearch(vector<int> &A, int B)
{
    //int ret=-1;
    int start=0, last=A.size()-1, mid;
    int k=searchPivot(A),arr_mid;
    while(start<=last)
    {
        mid=(start+last)/2;
        arr_mid=arrayIndex(A,k,mid);
        if(A[arr_mid]==B) return arr_mid;
        else if(A[arr_mid]<B) start=mid+1;
        else last=mid-1;
    }
    return -1;
}

int main()
{
    vector<int> vect;
    int n, temp;
    cout<<"Enter the size of vector: "; cin>>n;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The vector you entered is: ";
    for(int i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    int k=searchPivot(vect);
    cout<<"Elements have been shifted by: "<<k<<endl;
    cout<<"The vector is: ";
    for(int i=0; i<vect.size(); i++)
    {
        cout<<arrayIndex(vect,k,i)<<" ";
    }
    cout<<endl;
    cout<<"Enter your search number: "; int x; cin>>x;
    int result=binarySearch(vect,x);
    cout<<"Result: "<<result<<endl;
}
