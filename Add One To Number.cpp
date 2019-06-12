//This solution follows Kadane's algorithm to find the maximum contiguous subarray

#include<iostream>
#include<vector>
#include<cmath>



using namespace std;

vector<int> vectToInt(vector<int> &A)
{
	vector<int> vect;
	vect.insert(vect.begin(),A.begin(),A.end());
	int i=vect.size()-1;
	vect[i]+=1;
	while(i>0)
	{
		if(vect[i]==10)
		{ vect[i]=0; vect[i-1]+=1;i--;}
		else break;
	}
	if (vect[0]==10) {vect[0]=0;vect.insert(vect.begin(),1);}
	else
	{
		vector<int>::iterator it=vect.begin();
		while(it!=vect.end() && *it==0) {vect.erase(it); it++;}
	}
	return vect;
}



int main()
{
	cout<<"Enter the length of the array: \n";
	int n,temp; cin>>n;
	vector<int> vect;
	cout<<"Input: ";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	cout<<"vectors: \n";
	for(int i=0;i<vect.size();++i)
	{cout<<vect[i]<<"\n";}
	vector<int> ret;
	ret=vectToInt(vect);
	cout<<"Result: \n";
	for(int i=0;i<ret.size();i++)
	{
		cout<<ret[i]<<"\n";
	}
	return 0;
}
