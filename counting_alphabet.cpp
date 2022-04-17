//count the alphabet
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	int a[26]={0};
	int d;
	for(int i=0;i<str.size();i++)
	{
		d=str[i]-'a';
		a[d]++;
	}
	for(int i=0;i<26;i++)
	{
		if(a[i]!=0)
			cout<<(char)(i+'a')<<" "<<a[i]<<endl;
	}
}