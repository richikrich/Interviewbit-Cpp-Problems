//Outputs the maxinmum positive subarray

#include<iostream>
#include<vector>

using namespace std;

vector<int> maxspace(vector<int> &A)
{
	vector<int> ret;
	int it_1=-1; int it_2=-1; int maxsum=0; int it_1_temp=-1; int it_2_temp=-1; int sum_temp=0;
	if (A[0]>=0)
	{
		it_1_temp=0; it_2_temp=0;
		it_1=it_1_temp; it_2=it_2_temp;
		sum_temp=A[0];
		maxsum=sum_temp;
	}
	for(int i=1;i<A.size();i++)
	{
		if (A[i]>=0)
		{
			if(A[i-1]>=0) 
			{
				it_2_temp+=1;
				sum_temp+=A[i];
			}
			else
			{
				it_1_temp=i;
				it_2_temp=i;
				sum_temp=A[i];
			}
		}
		if (A[i]<0)
		{
			if((it_2_temp-it_1_temp)>(it_2-it_1))
			{
				it_1=it_1_temp;
				it_2=it_2_temp;
				maxsum=sum_temp;
				//sum_temp=0;
			}
			else if((it_2_temp-it_1_temp)==(it_2-it_1))
			{
				if (sum_temp>=maxsum)
				{
					it_1=it_1_temp;
					it_2=it_2_temp;
					maxsum=sum_temp;
				}
			}
		}
	}
	if(A[A.size()-1]>=0)
	{
		if((it_2_temp-it_1_temp)>(it_2-it_1))
		{
			it_1=it_1_temp;
			it_2=it_2_temp;
			//maxsum=sum_temp;
		}
		else if((it_2_temp-it_1_temp)==(it_2-it_1))
		{
			if (sum_temp>=maxsum)
			{
				it_1=it_1_temp;
				it_2=it_2_temp;
				//maxsum=sum_temp;
			}
		}
	}
	if(it_1>=0 && it_2>=0)
	{
		for(int i=it_1;i<=it_2;i++)
		{
			ret.push_back(A[i]);
		}
	}
	else
	{
		ret.push_back(-1);
	}
	return ret;
	
} 

int main()
{
	cout<<"================== Prints maximum positive subarray and prints '-1' if no such subarray exists =================="; int n, temp;
	cout<<"\nArray size: \n"; cin >> n;
	vector<int> vect;
	cout<<"Input: \n";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vect.push_back(temp);
	}
	//vect.push_back(1);vect.push_back(2);vect.push_back(5);vect.push_back(-7);vect.push_back(2);vect.push_back(3);
	vector<int> A;
	cout<<"\n"<<vect.size()<<"\n";
	cout<<"vector: \n";
	for(int i=0;i<vect.size();++i)
	{cout<<vect[i]<<" ";}
	//vector<vector<int>> ans=maxspace(vect);
	/*for(int i=0;i<ans.size();++i)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<"\n ";
		}
		cout<<"\n";
	}*/
	cout<<"\noutput: \n";
	A=maxspace(vect);
	for(int i=0;i<A.size();i++)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}
