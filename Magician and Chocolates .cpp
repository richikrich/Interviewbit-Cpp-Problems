#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

using namespace std;

int nchoc(vector<int> &A, int B)
{
    priority_queue<int> pQueue;
    long long int ret=0;
    int top;
    for(int i=0; i<A.size(); i++)
    {
        pQueue.push(A[i]);
    }
    for(int i=0; i<B; i++)
    {
        top=pQueue.top();
        pQueue.pop();
        ret=(ret+top)%div;
        pQueue.push(floor(top/2));
    }
    return ret;
}

int main()
{
    int n, k, temp;
    vector<int> A;
    cout<<"Enter the number of bags: "; cin>>n;
    cout<<"Enter the amount of time kid has: "; cin>>k;
    cout<<"Enter the number of chocolates in each bag: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        A.push_back(temp);
    }
    ///Inputs:
    cout<<"Your inputs are: \nNumber of bags: "<<n<<" \nAmount of time: "<<k<<" \nNumber of chocolates in the bags: ";
    for(int i=0; i<A.size(); i++) cout<<A[i]<<" ";
    cout<<endl;
    ///
    /**Results**/
    int result;
    result=nchoc(A,k);
    cout<<result<<endl;
    /****/
    return 0;
}
