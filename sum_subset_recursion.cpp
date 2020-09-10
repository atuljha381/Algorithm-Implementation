#include<bits/stdc++.h>
using namespace std;

int isSubset(int arr[],int n,int sum)
{
	int res,i=0;
	res=sum-arr[0];
	if(arr==res){
			return true;
		}	
	else{
		while(i<n)
		{
				i++;
				res=res-arr[i];
		}
	}
}
int main()
{
	int n=4;
	int arr[n]={2,5,7,15};
	int sum=17;
	
	if(isSubset(arr,n,sum)!=arr)
		return false;
}
