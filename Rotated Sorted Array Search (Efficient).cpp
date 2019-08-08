#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int searchPivot(vector<int> &A, int start, int last) //Binary Search to get Pivot!!
{
    int mid=(start+last)/2;
    if(start>last) return -1;
    if(A[mid]>A[0] && A[mid+1]<A[mid]) return mid; //Pivot
    else if(A[mid]<A[0]) return searchPivot(A,start,mid-1); //If element is less that A[0], pivot must be before it
    else return searchPivot(A,mid+1,last); //Search right subarray
}

int arrayIndex(vector<int> &A, int k, int i)
{
    int ret;
    if(i+(k+1)<A.size()) ret=i+k+1;
    else ret=(i+k+1)-A.size();
    return ret;
}

int rotatedSearch(vector<int> &A, int B)
{
    int start=0, last=A.size()-1, mid;
    int k=searchPivot(A,start,last),arr_mid;
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
    cout<<"Enter no. of elements: "; int n, temp; cin>>n;
    vector<int> vect;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The vector you entered is: ";
    for(int i=0; i<n; i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    /*cout<<"Search pivot:  ";
    int pivot=searchPivot(vect,0,n-1); if(pivot==-1) cout<<"Not rotated\n"; else cout<<pivot<<endl;
    cout<<"Indices positions: ";
    for(int i=0; i<vect.size(); i++)
    {
        cout<<arrayIndex(vect,pivot,i)<<" ";
    }
    cout<<endl;*/
    cout<<"Number you want to search: "; int x; cin>>x;
    int result=rotatedSearch(vect,x);
    cout<<"Result: "<<result;
    return 0;
}
