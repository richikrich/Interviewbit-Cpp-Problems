#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    /**Note here that if we simply start from the tallest person, inserting each
     * decreasing height person into his position in the vector as given in the second array,
     * we'll get the correct output!
     **/
    map<int, int> peopleBefore;
    int n=A.size();
    vector<int> ret;
    for(int i=0; i<n; i++) peopleBefore[A[i]]=B[i];
    for(auto it=peopleBefore.rbegin(); it!=peopleBefore.rend(); it++)
    {
        ret.insert(ret.begin()+(it->second),it->first);
    }
    return ret;
}

