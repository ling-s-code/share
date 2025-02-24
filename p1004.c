#include <stdio.h> 
#include <math.h>
int a[11][11];
int dp[11][11][11][11];
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int n;
	scanf("%d", &n);
	while(1)
	{	
		int x, y, z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==y&y==z&z==0) break;
		else a[x][y]=z;
	}
	int i, j, k, l;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				for(l=1;l<=n;l++)
				{
					dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+a[i][j]+a[k][l];
					if(i==k&&j==l) dp[i][j][k][l] -= a[i][j];
				}	
			}
		}
	}
	printf("%d",dp[n][n][n][n]);
	return 0;
} 