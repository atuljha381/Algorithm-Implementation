#include<bits/stdc++.h>
using namespace std;
int matrixchainorder(int a[],int i,int j)
{
	if(i==j)
	 return 0;
	
	int k,count;
	int min = INT_MAX;
	
	for(k=i;k<j;k++){
		count = matrixchainorder(a,i,k) + matrixchainorder(a,k+1,j) + a[i-1]*a[k]*a[j];
		
		if(count<min){
			min = count;
		}
	}
	return min;
}

main()
{
	int arr[]= {20,30,40,50};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Minimum multiplication for matrix multiplication is: "<<matrixchainorder(arr,1,n-1);
}

