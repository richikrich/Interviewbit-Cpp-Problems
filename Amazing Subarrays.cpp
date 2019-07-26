#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

bool isVowel(char x)
{
    if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U')
        return true;
    return false;
}

int amazingSubarrays(string A)
{
    int ret=0;
    for(int i=0; i<A.size(); i++)
    {
        if(isVowel(A[i])) ret+=(A.size()-i);
    }
    return ret%10003;
}

int main()
{
    string s;
    cout<<"Enter your string: \n";
    cin>>s;
    cout<<"The string you entered is: "<<s<<endl;
    int result=amazingSubarrays(s);
    cout<<"Result: "<<result<<endl;
    return 0;
}
