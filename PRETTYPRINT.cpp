#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> prettyPrint(int A)
{
    vector<vector<int>> ret;
    int len=A*2-1;
    vector<int> temp(len,0);
    for(int i=0;i<len; i++)
    {
        ret.push_back(temp);
    }
    int input;
    for(int i=0;i<=(int)len/2;i++)
    {
        for(int j=0; j<=(int)len/2; j++)
        {
            input=max(A-i,A-j);
            ret[i][j]=input;
            ret[i][(len-1)-j]=input;
            ret[(len-1)-i][j]=input;
            ret[(len-1)-i][(len-1)-j]=input;
        }
    }
    return ret;
}

int main()
{
    int n;
    cout<<"Enter your number: "; cin>>n;
    vector<vector<int>> result=prettyPrint(n);
    cout<<"Result: \n";
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
