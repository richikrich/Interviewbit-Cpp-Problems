#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

using namespace std;

void recursion_func(vector<int> &ans,vector<vector<int>> &ret,int index,int n,int k)
{
    if(ans.size()==k)
    {
        //cout<<true<<endl;
        ret.push_back(ans);
        return;
    }
    for(int i=index; i<=n; i++) ///The first time we enter this loop it will enter the first element of each combination
    {
        ans.push_back(i);
        recursion_func(ans,ret,i+1,n,k); ///The next element of each combination
        ans.pop_back(); ///Removes the last element to make space for new element
    }
    //return;
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ret;
    vector<int> ans;
    recursion_func(ans,ret,1,n,k);
    return ret;
}

int main()
{
    int n, k;
    cout<<"Enter your number of integers you want to consider: "; cin>>n;
    cout<<"Enter the size of your combinations: "; cin>>k;
    /**Inputs**/
    cout<<"The number of integers you want is: "<<n<<endl<<"The size of your combinations will be: "<<k<<endl;
    /***/
    /**Results**/
    vector<vector<int>> result=combine(n,k);
    cout<<"Results: "<<endl;
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++) cout<<result[i][j]<<" ";
        cout<<endl;
    }
    /****/
    return 0;
}
