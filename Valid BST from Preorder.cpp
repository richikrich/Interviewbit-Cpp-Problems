#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

int Solution::solve(vector<int> &A) {
    /* when we get a greater number basically it is the right node in the tree.
    ** so we'll store the last node as root and if any consecutive element is smaller,
    ** false
    */
    stack<int> roots;
    //roots.push(INT_MIN);
    int root=INT_MIN;

    for(int i=0; i<A.size(); i++)
    {
        if(A[i]<root) return 0; //this will imply that the element to the right of the last
                                //previously found root is smaller and hence return false.
        //Note: put the !empty() condition first because C++ checks in that order and will
        //      will give segmentation error for empty stack otherwise.
        while(!roots.empty() && A[i]>roots.top()) //basically finding out where the
        {                                          //next split is.
            root=roots.top();
            roots.pop();
        }
        roots.push(A[i]); //here if stack is empty this element is the right node of the root
    }                      //otherwise it's the right node of last removed element
    return 1;
}
