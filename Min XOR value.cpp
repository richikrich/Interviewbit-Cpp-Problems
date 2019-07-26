#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
/* It is observed that for any 3 given integers A<B<C; XOR(A,C) will always be greater than XOR(A,B) or XOR(A,C).
** Therefore, a simple approach we can use for the given set of integers is to sort the integers and calculate consequent pairwise
** XOR. The minimum will be found among these.
**P.S.: Doesn't seem to give good results for negative integers, but then again, handling negative integers on binary can be
**tricky.*/

int minXOR(vector<int> &A)
{
    int ret=INT_MAX;
    sort(A.begin(), A.end());
    for(int i=0; i<A.size()-1; i++)
    {
        if((A[i]^A[i+1])<ret) ret=(A[i]^A[i+1]);
    }
    return ret;
}

int main()
{
    vector<int> vect;
    cout<<"Enter the number of integers: \n";
    int n, temp; cin>>n;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The vector you entered is: \n";
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    /*cout<<"The pairwise XOR values are: \n";
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<": ";
        for(int j=0; j<vect.size(); j++)
        {
            cout<<(vect[i]^vect[j])<<" ";
        }
        cout<<endl;
    }*/
    cout<<"Result: ";
    int result=minXOR(vect);
    cout<<result<<endl;
    return 0;
}
