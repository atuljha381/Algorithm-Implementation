#include<bits/stdc++.h>
using namespace std;

bool isSubset(int arr[],int n,int sum)
{
	int i,j;
	bool subset[n+1][sum+1];
	
	for(i=0;i<=n;i++){
		subset[i][0]=true;
	}
	
	for(i=1;i<=sum;i++){
		subset[0][i]=false;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			if(j<arr[i-1]){
				subset[i][j]=subset[i-1][j];
			}
			if(j>=arr[i-1]){
				subset[i][j]=subset[i-1][j] || subset[i-1][j-arr[i-1]];
			}
		}
	}
	return subset[n][sum];
}

main()
{
	int arr[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 9; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (isSubset(arr, n, sum) == true) 
        cout<<"Found a subset with given sum"<<endl; 
    else
        cout<<"No subset with given sum"<<endl; 
    return 0; 
}
