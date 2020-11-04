/*#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
	return ((a>b)?a:b);
}
int lcs(char *x,char *y,int m,int n)
{
	if(m==0||n==0){
		return 0;
	}
	else if(x[m-1]==y[n-1]){
		return 1+lcs(x,y,m-1,n-1);
	}
	else{
		return max(lcs(x,y,m,n-1),lcs(x,y,m-1,n));
	}
}
main()
{
	char X[]="AGGTAB";
	char Y[]="GXTXAYB";
	int m=strlen(X);
	int n=strlen(Y);
	
	cout<<"Length of LCS is: "<<lcs(X,Y,m,n);
	
}*/

#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
	return ((a>b)?a:b);
}
void lcs(char *A,char *B,int m,int n)
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
	int index=L[m][n];
	char seq[index+1];
	seq[index]='\0';
	int i=m,j=n;
	
	while(i>0 && j>0){
		
		if(A[i-1]==B[j-1]){
			seq[index-1]=A[i-1];
			i--;
			j--;
			index--;
		}
		
		else if(L[i-1][j]>L[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	cout<<"LCS of "<<A<<" and "<<B<<" is "<<seq<<endl;
	cout<<"With a length of "<<L[m][n]<<endl;
}
main()
{
	char X[]="AGGTAB";
	char Y[]="GXTXAYB";
	int m=strlen(X);
	int n=strlen(Y);
	
	//cout<<"Length of LCS is: "
	lcs(X,Y,m,n);
	
}

