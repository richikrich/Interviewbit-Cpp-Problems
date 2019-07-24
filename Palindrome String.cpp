#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

string simplifyString(string &A)
{
    string ret;
    for(int i=0; i<A.size(); i++)
    {
        if(isalnum(A[i]))
        {
            if(A[i]>='A' && A[i]<='Z') ret.push_back((char)((int)A[i]+32));
            else ret.push_back(A[i]);
        }
    }
    return ret;
}

bool isPalindrome(string &A)
{
    //bool ret=false;
    string result=simplifyString(A);
    int i=0, j=result.size()-1;
    while(i<=j)
    {
        if(result[i]==result[j])
        {
            i++; j--;
        }
        else return false;
    }
    return true;
}


int main()
{
    string str;
    cout<<"Enter your string: \n";
    getline(cin, str);
    bool result;
    cout<<"The string you entered is: \n";
    cout<<str<<endl;
    result=isPalindrome(str);
    cout<<"Result: "<<result<<endl;
    /*char ch='x';
    if(isalnum(ch)) cout<<"Nice ra! \n";
    else cout<<"Kya be??! \n";*/
}
