#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

using namespace std;

vector<int> dNums (vector<int> &A, int B)
{
    map<int, int> counter;
    vector<int> ret;
    int distinct=0; ///counts number of distinct elements in the window
    ///initializing the map
    for(int i=0; i<B; i++)
    {
        if(counter[A[i]]==0) distinct++;
        counter[A[i]]++;
    }
    ret.push_back(distinct);
    ///'distinct' now counts the number of distinct elements in the first 'B' elements and the map 'counter' counts their occurences
    ///Now we start sliding the window
    for(int i=B; i<A.size(); i++)
    {
        /**Discounting the first element of the previous window as it no long exists in this window**/
        if(counter[A[i-B]]==1) distinct--; ///If it had occurred only once in the window, we remove it's count from 'distinct'
        counter[A[i-B]]--; ///Discounting one occurrence from the counting map
        if(counter[A[i]]==0) distinct++; ///That is, new distinct element
        counter[A[i]]++; ///Counting the new elements occurrence
        ret.push_back(distinct);
    }
    return ret;
}

int main()
{
    int n, temp, k;
    vector<int> vect;
    cout<<"Enter the number of elements in your array: "; cin>>n;
    cout<<"Enter your array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"Enter the window size: "; cin>>k;
    /**Inputs**/
    cout<<"Your preferred window size is: "<<k<<" \nThe array you entered is: ";
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" ";
    cout<<endl;
    /***/
    /**Results**/
    vector<int> results=dNums(vect,k);
    cout<<"Results: ";
    for(int i=0; i<results.size(); i++) cout<<results[i]<<" ";
    cout<<endl;
    /****/
    return 0;
}
