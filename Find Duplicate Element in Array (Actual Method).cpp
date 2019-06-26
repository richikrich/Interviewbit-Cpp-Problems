#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h> 


using namespace std;
//also tried by declaring a vector of '1's, but it was taking more space than a vector of boolean entries, and exceeded memory limit. This is obvious when you consider bool has one-bit storage requirement, 
//in contrast to 32-bit of integers.
int findLargest(const vector<int> &A)
{
	vector <bool> v(A.size());
    fill(v.begin(), v.end(), true);
    for(int i=0;i<A.size();i++)
    {
        if(v[A[i]])
        {
            v[A[i]]=false;
        }
        
        else
        {    
			return A[i];
		}
	}
}


int main()
{
	cout<<"Enter the number of inputs: \n"; 
	int n; cin>>n;
	cout<<"Enter the numbers: \n";
	vector<int> vect; int temp;
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	cout<<"The vector you entered: \n";
	for(int i=0; i<vect.size(); i++)
	{
		cout<<vect[i]<<" ";
	}
	cout<<"\n";
	int x=findLargest(vect);
	cout<<x;
	return 0;
}
