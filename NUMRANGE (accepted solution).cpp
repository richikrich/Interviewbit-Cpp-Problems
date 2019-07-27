#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
//Note that a single element is a valid answer. My earlier solution did provide correct answer if single element was not valid, but was O(n^2)
//This next solution is better in terms of time complexity.
int numrange(vector<int> &A, int B, int C)
{
    int i=0, j=0, sum=0, counter=0;
    while(i<A.size())
    {
        sum+=A[j]; //This step is pretty self explanatory
        if(sum>=B && sum<=C)
        {
            counter++;
            j++;
        }
        else if (sum<B) j++; //Sum is less than lower limit: add another element from the right.
        else if (sum>C) //Sum is greater than upper limit: sum has reached saturation for i. Time to move on!
        {
            i++;
            j=i;
            sum=0;
        }
        if(j==A.size()) //Terminating criteria for j.
        {
            i++;
            j=i;
            sum=0;
        }
    }
    return counter;
}

int main()
{
    vector<int> vect;
    cout<<"Enter the number of inputs you want: ";
    int n; cin>>n;
    int temp;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        vect.push_back(temp);
    }
    cout<<"The vector you entered is: ";
    for(int i=0; i<n; i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter your limits: ";
    int a; cin>>a;
    int b; cin>>b;
    cout<<"The limits you entered are: ("<<a<<","<<b<<")"<<endl;
    int result=numrange(vect,a,b);
    cout<<"Result: "<<result<<endl;
}
