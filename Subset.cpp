#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

void backtracking(vector<int> &A, vector<vector<int>> &ret, vector<int> &subset, int index)
{
    ret.push_back(subset);
    for(int i=index; i<A.size(); i++)
    {
        subset.push_back(A[i]);
        backtracking(A,ret,subset,i+1);
        subset.pop_back();
    }
    return;
}

vector<vector<int>> subsets(vector<int> &A)
{
    vector<vector<int>> ret;
    vector<int> subset;
    int ind=0;
    backtracking(A,ret,subset,ind);
    return ret;
}


int main()
{
    int n, temp;
    vector<int> vect;
    cout<<"Enter the length of your array: "; cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    vector<vector<int>> result=subsets(vect);
    cout<<"Result: \n";
    for(int i=0; i<result.size(); i++)
    {
        cout<<"[ ";
        for(int j=0; j<result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;
    return 0;
}
