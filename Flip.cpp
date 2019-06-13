#include<iostream>
#include<vector>


using namespace std;

vector<int> flip(string A) //We basically need to ifnd the indices between which the difference in the number of '1's and '0's is highest
{
	int l_i=0, r_i=0, sum=0, l_temp=0, r_temp=0, sum_temp=0;
	for(int i=0; i<A.size();i++)
	{
		r_temp=i;
		if(sum_temp<0)
		{
			sum_temp=0;
			l_temp=i;
		
		}
		if(A[i]=='0')
		{
			sum_temp+=1;
		}
		else
		{
			sum_temp-=1;
		}
		if (sum_temp>sum)
		{
			sum=sum_temp;
			l_i=l_temp;
			r_i=r_temp;
		}
	} 
	vector<int> ret;
	if (l_i==0 && r_i==0 && A[0]=='1') return ret;
	else
	{
		ret.push_back(l_i+1);
		ret.push_back(r_i+1);
		return ret;
	}
}

int main()
{
	string s;
	cout<<"Enter your binary string: \n"; cin>>s;
	cout<<"The string you entered is: "<<s;
	vector<int> v=flip(s);
	cout<<"\nRequired set of indices is: ";
	for(int i=0; i<v.size(); i++)
	{
		cout<<"\n"<<v[i];
	}
	return 0;
}
