#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int longValidSub(string &A)
{
   stack<int> indices;
   indices.push(-1);
   int count=0;
   for(int i=0; i<A.size(); i++)
   {
       if(A[i]=='(') indices.push(i);
       else
       {
           indices.pop();
           if(indices.empty()==true) indices.push(i);
           else count=max(count,i-indices.top());
       }
   }
   return count;
}

int main()
{
    cout<<"Enter your string: ";
    string str;
    cin>>str;
    cout<<"The string you entered is: "<<str<<endl;
    int result=longValidSub(str);
    cout<<"Result: "<<result<<endl;
    return 0;
}
