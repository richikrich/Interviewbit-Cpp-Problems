#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

/*We start with the last elements of each of the vectors. Since sorted, these are the largest elements of the arrays. Thereafter
**if we want to decrease the difference, we will try reducing the max of the three, i.e., going to its previous elements and if
**the new difference is less, update the absolute difference value*/

int minAbsDiff(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int i=A.size()-1, j=B.size()-1, k=C.size()-1, diff, min_diff=INT_MAX, max_int, min_int;
    while(i>=0 && j>=0 && k>=0)
    {
        max_int=max(max(A[i],B[j]),C[k]);
        min_int=min(min(A[i],B[j]),C[k]);
        diff=max_int-min_int;
        min_diff=min(diff,min_diff);
        if(A[i]==max_int) i--;
        else if(B[j]==max_int) j--;
        if(C[k]==max_int) k--;
    }
    return min_diff;
}

int main()
{
    vector<int> A,B,C;
    int a,b,c, temp;
    cout<<"Enter the size of your vectors: "; cin>>a>>b>>c;
    cout<<"A: ";
    for(int i=0; i<a; i++)
    {
        cin>>temp;
        A.push_back(temp);
    }
    cout<<"B: ";
    for(int i=0; i<b; i++)
    {
        cin>>temp;
        B.push_back(temp);
    }
    cout<<"C: ";
    for(int i=0; i<c; i++)
    {
        cin>>temp;
        C.push_back(temp);
    }
    cout<<"The vectors you entered are: \n";
    cout<<"A: "; for(int i=0; i<A.size(); i++) cout<<A[i]<<" "; cout<<endl;
    cout<<"B: "; for(int i=0; i<B.size(); i++) cout<<B[i]<<" "; cout<<endl;
    cout<<"C: "; for(int i=0; i<C.size(); i++) cout<<C[i]<<" "; cout<<endl;
    int result=minAbsDiff(A,B,C);
    cout<<"Result: "<<result<<endl;
    cout<<endl;
}
