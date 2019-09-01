#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

/** Question: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

 **           push(x) – Push element x onto stack.
 **           pop() – Removes the element on top of the stack.
 **           top() – Get the top element.
 **           getMin() – Retrieve the minimum element in the stack.
 ** Note that all the operations have to be constant time operations.
 **
 ** Questions to ask the interviewer :
 **
 ** Q: What should getMin() do on empty stack?
 ** A: In this case, return -1.
 **
 ** Q: What should pop do on empty stack?
 ** A: In this case, nothing.
 **
 ** Q: What should top() do on empty stack?
 ** A: In this case, return -1
 **/

stack<int> main_stack;
stack<int> mini;

MinStack::MinStack() {
    while(!main_stack.empty() && !mini.empty())
    {
        main_stack.pop();
        mini.pop();
    }
    while(!main_stack.empty())
    {
        main_stack.pop();
        //mini.pop();
    }
    while(!mini.empty())
    {
        //main_stack.pop();
        mini.pop();
    }
    mini.push(INT_MAX);
}

void MinStack::push(int x) {
    main_stack.push(x);
    if(x<=mini.top()) mini.push(x);
}

void MinStack::pop() {
    if(!main_stack.empty())
    {
        int topping=main_stack.top();
        main_stack.pop();
        if(topping==mini.top()) mini.pop();
    }
}

int MinStack::top() {
    if(main_stack.empty()) return -1;
    else return main_stack.top();
}

int MinStack::getMin() {
    if(main_stack.empty()) return -1;
    else return mini.top();
}
