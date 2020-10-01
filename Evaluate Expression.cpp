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

/**
 * The idea is that a operator works on it's previous two operands. So we store the elements in a stack and when we encounter a
 * operator, we apply in on the last two elements of the stack, while popping them. Then we store the result in the stack.
 * Finally we return the top element of the stack
**/

int Solution::evalRPN(vector<string> &A) {
    stack<int> numbers;
    int num1, num2, result;
    char tempc;
    for(int i=0; i<A.size();i++)
    {
        if(!(A[i]=="+" || A[i]=="-" || A[i]=="/" ||A[i]=="*")) numbers.push(stoi(A[i]));
        else
        {
            num2=numbers.top();
            numbers.pop();
            num1=numbers.top();
            numbers.pop();
            result=operations(num1, num2, A[i]);
            numbers.push(result);
        }
    }
    return numbers.top();
}
