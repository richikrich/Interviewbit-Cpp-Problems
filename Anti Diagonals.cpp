#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> antiDiagonal(vector<vector<int>> &A)
{
    vector<vector<int>> ret; vector<int> temp;
    int len=A.size(); int n=(A.size()*2)-1;
    for(int i=0;i<n;i++)
    {
        for(int j=max(0,i-len+1);j<min(len,i+1);j++)
        {
            temp.push_back(A[j][i-j]);
        }
        ret.push_back(temp);
        temp.clear();
    }
    return ret;
}

int main()
{
    cout<<"Enter the dimension for your array: \n";
    int n, temp_in; cin>>n;
    vector<vector<int>> vect; vector<int> temp;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter row: \n";
        for(int j=0; j<n; j++)
        {
            cin>>temp_in;
            temp.push_back(temp_in);
        }
        vect.push_back(temp);
        temp.clear();
    }
    cout<<"The vector you entered is: \n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<vect[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Result: \n";
    vector<vector<int>> result=antiDiagonal(vect);
    for(int i=0; i<result.size();i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
