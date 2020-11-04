#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
	return (a>b)?a:b;
}

int dynamic(int Capacity,int wt[],int val[],int n)
{
	int i,j;
	int K[n+1][Capacity+1];
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=Capacity;j++)
		{
			if(i==0||j==0)
				K[i][j]=0;
			else if (wt[i - 1] <= j) 
                K[i][j] = max( 
                    val[i - 1] + K[i - 1][j - wt[i - 1]], 
                    K[i - 1][j]); 
            else
                K[i][j] = K[i - 1][j];  
				
		}
	}
	return K[n][Capacity];
}
int main()
{
	int val[]={70,80,90};
	int weight[]={20,30,40};
	
	int Capacity=60;
	int n=sizeof(val)/sizeof(val[0]);
	//cout<<recursive(Capacity,weight,val,n);
	cout<<dynamic(Capacity,weight,val,n);
	return 0;
}



/*int recursive(int Capacity,int w[],int v[],int n)
{
	if(n==0||Capacity==0)
		return 0;
	
	if(w[n]<=Capacity){
		return max(v[n]+recursive(Capacity-w[n],w,v,n-1),recursive(Capacity,w,v,n-1));
	}
	else{
		return recursive(Capacity,w,v,n-1);
	}
}*/
