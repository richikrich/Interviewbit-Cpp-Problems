#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int operations(int a, int b, string c)
{
    if(c=="+") return(a+b);
    if(c=="-") return(a-b);
    if(c=="/") return(a/b);
    if(c=="*") return(a*b);
}

/**The idea is that a operator works on it's previous two operands. So we store the elements in a stack and when we encounter a
 **operator, we apply in on the last two elements of the stack, while popping them. Then we store the result in the stack.
 **Finally we return the top element of the stack**/

int revPolish(vector<string> &A)
{
    stack<int> characters;
    int temp1, temp2, ret;
    char tempc;
    for(int i=0; i<A.size();i++)
    {
        if(A[i]=="+" || A[i]=="-" || A[i]=="/" ||A[i]=="*")
        {
            temp1=characters.top();
            characters.pop();
            temp2=characters.top();
            characters.pop();
            ret=operations(temp2, temp1, A[i]);
            characters.push(ret);
        }
        else
        {
            //tempc=A[i];
            characters.push(stoi(A[i]));
        }
    }
    return characters.top();
}

int main()
{
    vector<string> vect;
    cout<<"Enter the size of vector: "; int n; cin>>n;
    cout<<"Input: "; string temp;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The vector you entered is: ";
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" ";
    int result=revPolish(vect);
    cout<<endl<<"Result: "<<result;
    return 0;
}
