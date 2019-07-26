#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
/* Clearly if there is a pre-existing palindrome sequence, it has to be at the front, or it is useless. */
bool isPalindrome(string A, int j) //Checks if a sub-string from i=0 to i=j is palindrome.
{
    int i=0;
    while(i<=j)
    {
        if(A[i]!=A[j]) return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int solve(string A)
{
    int palSize;
    for(int j=A.size()-1; j>=0; j--)
    {
        if(isPalindrome(A,j))
        {
            palSize=(A.size()-1-j);
            return palSize;
        }
    }
}

int main()
{
    string s;
    cout<<"Enter your string: \n";
    cin>>s;
    cout<<"The string you entered is: "<<s<<endl;
    int result=solve(s);
    cout<<"Result: "<<result<<endl;
    return 0;
}
