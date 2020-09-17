#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int Solution::longestConsecutive(const vector<int> &A) {
    if(A.size()==1 || A.size()==0) return A.size();
    set<int> counter;
    for(int i=0; i<A.size(); i++) counter.insert(A[i]);
    //for(auto itr=counter.begin(); itr!=counter.end(); itr++) cout<<*itr<<" ";
    //using a set instead of duplicating the array and sorting as repeated elements are counted as one
    set<int>::iterator j;
    j=++counter.begin();
    int temp=(*counter.begin()), num=1, num_max=INT_MIN;
    while(j!=counter.end())
    {
        if((*j)==(temp+1))
        {
            num++;
        }
        else
        {
            num_max=max(num, num_max);
            num=1;
        }
        temp=(*j);
        j++;
    }
    num_max=max(num, num_max);
    return num_max;
}
