//find the largest number and smalllest number in the array
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	set<int> s;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		s.insert(num);
	}
	set<int>::iterator set(s.begin());
	advance(set,0);
	cout<<*set<<" ";
	advance(set,n-1);
	cout<<*set;
}
