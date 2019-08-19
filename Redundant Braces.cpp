#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
#include<stack>

using namespace std;

bool reduntantBrackets(string A)
{
    stack<char>str_stack; bool ret; char top;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]!=')') str_stack.push(A[i]);
        else
        {
            top=str_stack.top();
            ret=true;
            str_stack.pop();
            if(top=='(') return ret;
            while(top!='(')
            {
                if(top=='+'||top=='-'||top=='*'||top=='/') ret=false;
                top=str_stack.top();
                str_stack.pop();
            }
            if(ret==true) return true;
        }
    }
    return false;
    /*while(!str_stack.empty())
    {
        cout<<str_stack.top();
        str_stack.pop();
    }*/
    return false;
}

int main()
{
    string str;
    cout<<"Enter your string: "; cin>>str;
    cout<<"The string is: "<<str<<endl;
    bool result=reduntantBrackets(str);
    cout<<"Result: "<<result;
    //cout<<result;
}
