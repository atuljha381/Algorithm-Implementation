#include<bits/stdc++.h>
using namespace std;
int max_get(int *arr,int n)
{
	int max=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
void count_sort(int *arr,int n,int dig)
{
	int array[n];
	int i,count[10]={0};
	for(i=0;i<n;i++){
		count[(arr[i]/dig)%10]++;
	}
	
	for(i=1;i<10;i++){
		count[i]+=count[i-1];
	}
	
	for(i=n-1;i>=0;i--){
		array[count[(arr[i]/dig)%10]-1]=arr[i];
		count[(arr[i]/dig)%10]--;
	}
	
	for(i=0;i<n;i++){
		arr[i]=array[i];
	}
}

void radix_sort(int *arr,int n)
{
	int m ;
	m = max_get(arr,n); 
	for (int dig = 1; m/dig > 0; dig *= 10) 
        count_sort(arr, n, dig); 
}

void print(int *arr, int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 

int main() 
{ 
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    radix_sort(arr, n); 
    cout<<"sorted array"<<endl;
    print(arr, n); 
    return 0; 
} 
