#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

/*The idea is to start search from the top-right corner. If it's lesser than the target, we can discard the row as all the other
 *elements will be smaller. If the elements is greater, we can discard the column as all the elements remaining in the column will
 *greater. Carry on till you find a match or return 0. I was trying to use binary search, but this has O(n) time complexity */

 bool searchMatrix(vector<vector<int>> &A, int B)
 {
     int rows=A.size()-1, cols=A[0].size()-1;
     if(A[0][0]>B || A[rows][cols]<B) return false;
     else if(A[0][0]==B || A[rows][cols]==B) return true;
     int i=0, j=cols;
     while(i<=rows && j>=0)
     {
         //cout<<A[i][j]<<endl;
         if(A[i][j]==B) return true;
         else if(A[i][j]<B) i++;
         else j--;
     }
     return false;
 }


int main()
{
    int m,n;
    cout<<"Enter the dimensions of your matrix: "; cin>>m>>n;
    vector<vector<int>> vect; vector<int> temp; int temp_in;
    cout<<"Input: \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>temp_in;
            temp.push_back(temp_in);
        }
        vect.push_back(temp);
        temp.clear();
    }
    cout<<"The matrix is: \n";
    for(int i=0; i<vect.size();i++)
    {
        for(int j=0; j<vect[i].size();j++)
        {
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }
    int x;
    cout<<"Enter target value: "; cin>>x;
    bool result=searchMatrix(vect,x);
    cout<<"Result: "<<result<<endl;
    //cout<<"Result: "<<result<<endl;
}
