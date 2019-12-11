#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

using namespace std;

int maxIndex(vector<int> &A)
{
    int ret;
    vector<int>::iterator itr;
    itr=max_element(A.begin(),A.end());
    ret=itr-A.begin();
    return ret;
}

int nchoc(vector<int> &A, int B)
{
    int ret=0,ind;
    for(int i=0; i<B; i++)
    {
        ind=maxIndex(A);
        ret=(ret+A[ind])%div;
        A[ind]=floor(A[ind]/2);
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
