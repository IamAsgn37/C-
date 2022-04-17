//binary search using recursive method
#include<bits/stdc++.h>
using namespace std;
int bin(int a[],int s,int start,int end)
{
	if(end>=start)
	{
		int mid=start+(end-start)/2;
		if(a[mid]==s)
			return mid;
		else if(a[mid]>s)
			return bin(a,s,mid+1,end);
		else
			return bin(a,s,start,end-1);
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