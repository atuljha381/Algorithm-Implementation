#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
	return ((a>b)?a:b);
}
int lcs(char *A,char *B,int m,int n)
{
	int L[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0)
				L[i][j]=0;
			
			else if(A[i - 1]==B[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
				
			else	
				L[i][j]=max(L[i - 1][j], L[i][j - 1]);
		}
	}
	return L[m][n];
}
main()
{
	char X[]="AGGTAB";
	char Y[]="GXTXAYB";
	int m=strlen(X);
	int n=strlen(Y);
	
	cout<<"Length of LCS is: "<<lcs(X,Y,m,n);
	
}

