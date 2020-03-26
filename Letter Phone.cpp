#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

using namespace std;

vector<string> keys{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void backtracking(vector<string> &ret, int i, string digits, string temp)
{
    int k=(int) digits[i] - (int) '0';
    string str=keys[k];
    for(int j=0; j<str.size(); j++)
    {
        temp.push_back(str[j]);
        if(i==digits.size()-1)
            ret.push_back(temp);
        else
            backtracking(ret,i+1,digits,temp);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string A)
{
    vector<string> ret;
    string temp;
    backtracking(ret,0,A,temp);
    return ret;
}

int main()
{
    string digits;
    cout<<"Enter your string of digits: "; cin>>digits;
    cout<<"The digits you input is: "<<digits<<endl;
    vector<string> result=letterCombinations(digits);
    cout<<"Results: ";
    for(int i=0; i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
