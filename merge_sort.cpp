#include<bits/stdc++.h>
using namespace std;
void merge(int *a,int low,int high,int mid)
{
	int i,j,k,temp[high-low+1];
	i=low;
	k=0;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j]){
			temp[k]=a[i];
			i++;
			k++;
		}
		else{
			temp[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=mid){
		temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=high){
		temp[k]=a[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++){
		a[i]=temp[i-low];
	}
}
void mergesort(int *a,int low,int high)
{
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,high,mid);
	}	
}

main()
{
	int n;
	cout<<"Size of array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements in array"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	mergesort(arr,0,n-1);;
	cout<<"Sorted array"<<endl;
	for(int i=0;i<n;i++){
		cout<<"-"<<arr[i];
	}
	return 0;
}
