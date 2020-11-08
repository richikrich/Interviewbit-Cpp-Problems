#include<iostream>
#include<vector>

/* 
 * Note: abs(A[i]-A[j])+abs(j-i), basically boils down to: 
 * 1. (A[i]-i)-(A[j]-[j]) 
 * 2. -(A[i]-i)+(A[j]-[j]) 
 * 3. (A[i]+i)-(A[j]+j) 
 * 4. -(A[i]+i)+(A[j]+j)
 * That is, the maximum differenc is the maximum of two values: max((A[i] + i) – (A[j] + j)) and max((A[i] – i) – (A[j] – j)). 
 * */

using namespace std;

int maxArr(vector<int> &A)
{
	int max1=-999; int min1=999;
	int max2=-999; int min2=999;
	int temp1, temp2;
	for(int i=0;i<A.size();i++)
	{
		max1=max(max1,A[i]-i);
		max2=max(max1,A[i]+i);
		min1=min(min1,A[i]-i);
		min2=min(min1,A[i]+i); 
	}
	return max(max1-min1,max2-min2);
}


int main()
{
	cout<<"Enter the number of elements: \n";
	int n,temp; cin>>n;
	vector<int> vect;
	cout<<"Inputs: ";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	cout<<"vector: \n";
	for(int i=0;i<vect.size();++i)
	{cout<<vect[i]<<" ";}
	cout<<"\nThe result is: "<<maxArr(vect);
	return 0;
}
