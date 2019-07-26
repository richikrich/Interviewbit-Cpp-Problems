#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int lengthOfLast(string A)
{
    int j=A.size()-1;
    while(A[j]==' ') j--; //iterates over trailing spaces.
    if(j<0) return 0;
    int k=j;
    while(A[k]!=' ' && k>=0)
    {
        k--;
    }
    return (j-k);
}

int main()
{
    string s;
    cout<<"Enter your string: \n";
    getline(cin,s);
    cout<<"The string you entered is '"<<s<<"' of length "<<s.size()<<endl;
    int result=lengthOfLast(s);
    cout<<"Result: "<<result<<endl;
    /*string trim=removeTrailSpaces(s);
    cout<<"New: '"<<trim<<"'"<<endl;*/
    return 0;
}
