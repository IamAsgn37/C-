//binary search using iterative
#include<bits/stdc++.h>
using namespace std;
int bin(int a[],int s,int start,int end)
{
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		if(a[mid]==s)
			return mid;
		else if (a[mid]>s)
			start=mid+1;
		else
			end=mid-1;
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int s;
	cin>>s;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int result=bin(a,s,0,n-1);
	if(result==-1)
		cout<<"NOT found";
	else
		cout<<"found";

}