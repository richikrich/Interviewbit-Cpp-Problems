#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

vector<long long int> rightGreater(vector<int> &A)
{
    vector<long long int> ret(A.size(),0);
    stack<int> s;
    for(int i=0; i<A.size(); i++) //what we are doing here is creating a stack to store the indices of the elements starting from 0
    {                             //if an element greater than the element at last checked index is found, it will store the index
            while(!s.empty() && A[i]>A[s.top()]) //of that element and delete all indices from that stack, for which it is greater and then
            {                     //store it's index. Thus it is also ensured that the nearest index with greater value is stored.
                int k=s.top();    //Everytime a greater element is found, it's index is stored at the index of the returned vector where the last element
                s.pop();            //was found, i.e., the element it's nearest from.
                ret[k]=i;
            }
            s.push(i);
    }
    return ret;
}

vector<long long int> leftGreater(vector<int> &A)
{
    vector<long long int> ret(A.size(),0);
    stack<int> s;
    for(int i=A.size()-1; i>=0; i--) //what we are doing here is creating a stack to store the indices of the elements starting from 0
    {                             //if an element greater than the element at last checked index is found, it will store the index
            while(!s.empty() && A[i]>A[s.top()]) //of that element and delete all indices from that stack, for which it is greater and then
            {                     //store it's index. Thus it is also ensured that the nearest index with greater value is stored.
                int k=s.top();    //Everytime a greater element is found, it's index is stored at the index of the returned vector where the last element
                s.pop();            //was found, i.e., the element it's nearest from.
                ret[k]=i;
            }
            s.push(i);
    }
    return ret;
}

int maxspProd(vector<int> &A)
{
    long long int ret=0;
    vector<long long int> left=leftGreater(A);
    vector<long long int> right=rightGreater(A);
    for(int i=0; i<A.size(); i++)
    {
        if(ret<(left[i]*right[i])) ret=left[i]*right[i];
    }
    return (ret%1000000007);
}

int main()
{
	cout<<"Enter the number of inputs in your vector: \n";
	int n; cin>>n; int temp;
	vector<int> vect;
	cout<<"\nEnter: ";
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
    int result=maxspProd(vect);
    cout<<"Result: "<<result<<endl;
	return 0;
}
