#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int findRow(vector<vector<int>> &A, int B)
{
    int ret;
    int start=0, last=A.size()-1;
    int j=0;
    while(start<=last)
    {
        int mid=(start+last)/2;
        if(A[mid][j]==B) return mid;
        else if (A[mid][j]>B) last=mid-1;
        else
        {
            start=mid+1;
            ret=mid;
        }
    }
    return ret;
}

bool searchRow(vector<vector<int>> &A, int B)
{
    int row=findRow(A,B);
    if(A[row][0]==B) return true;
    bool ret=false;
    int start=0, last=A[row].size();
    while(start<=last)
    {
        int mid=(start+last)/2;
        cout<<"Mid: "<<mid<<endl;
        if(A[row][mid]==B)
        {
            ret=true;
            break;
        }
        else if(A[row][mid]>B) last=mid-1;
        else start=mid+1;
    }
    return ret;
}


int main()
{
    int m,n;
    cout<<"Enter the dimensions of your matrix: "; cin>>m>>n;
    vector<vector<int>> vect; vector<int> temp; int temp_in;
    cout<<"Input: \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>temp_in;
            temp.push_back(temp_in);
        }
        vect.push_back(temp);
        temp.clear();
    }
    cout<<"The matrix is: \n";
    for(int i=0; i<vect.size();i++)
    {
        for(int j=0; j<vect[i].size();j++)
        {
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }
    int x;
    cout<<"Enter your target: "; cin>>x;
    int row=findRow(vect, x);
    cout<<"Row number: "<<row<<endl;
    bool result=searchRow(vect,x);
    cout<<"Result: "<<result<<endl;
    //cout<<"Result: "<<result<<endl;
}
