#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

/*To find the only number that does not have duplicates, we calculate the total XOR of all consecutive elements start from 0.
**Note that (0^X)=X. Except the element occurring once the bits of all the other elements occur twice and therefore cancel out,
**leaving behind the singly occurring number. For eg. (1011^1010)^1011=1010!!
*/

int singleNumber(vector<int> &A)
{
    int ret=0;
    for(int i=0; i<A.size();i++) ret=ret^A[i];
    return ret;
}
/* Simple!! :) */
int main()
{
    cout<<"No. of inputs: ";
    int n, temp; cin>>n;
    vector<int> vect;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    int result=singleNumber(vect);
    cout<<"Result: "<<result;
    return 0;
}
