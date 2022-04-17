//to reverse the array using recursion
#include<bits/stdc++.h>
using namespace std;
void reverse(int a[],int start,int end)
{
	if(start==end)
		return;
	int temp=a[start];
	a[start]=a[end];
	a[end]=temp;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	reverse(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}