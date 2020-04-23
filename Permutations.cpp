    #include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

void backtracking(vector<vector<int>> &ret, int ind, vector<int> &A)
{
    if(ind==A.size())
    {
        ret.push_back(A);
        return;
    }
    for(int i=ind; i<A.size(); i++)
    {
        swap(A[i],A[ind]);
        backtracking(ret,ind+1,A);
        swap(A[i],A[ind]);
    }
}

vector<vector<int>> permute(vector<int> &A)
{
    vector<vector<int>> ret;
    backtracking(ret,0,A);
    return ret;
}

int main()
{
    int n, temp;
    vector<int> vect;
    cout<<"Enter the number of integers you want: "; cin>>n;
    cout<<"Enter the integers: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The numbers you entered are: "<<endl;
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    vector<vector<int>> result=permute(vect);
    cout<<"Results:"<<endl;
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
