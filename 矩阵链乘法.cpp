#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
const int INF=1e7+10;
int n;
int dp[1010][1010];
int a[maxn], s[1010][1010];
void matrix_chain_mul(){
	printf("过程:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=INF;
		}
	}
	printf("区间长 = %d\n", 1);
	for(int i = 1; i <= n; ++ i) {
		dp[i][i] = 0; s[i][i] = i;
		printf("m[%d, %d] = %d  s[%d, %d] = %d\n", i, i, dp[i][i], i, i, s[i][i]);
	}
	printf("\n");
	for(int i = 2; i <= n; ++ i) {
		printf("区间长 = %d\n", i);
		for(int j = i; j <= n; ++ j) {
			int l = j - i + 1;
			for(int k = s[l][j - 1]; k <= s[l + 1][j]; ++ k) {
				int tmp = dp[l][k] + dp[k + 1][j] + a[l - 1] * a[k] * a[j];
				if(dp[l][j] > tmp){
					dp[l][j] = tmp;
					s[l][j] = k; 
				}
			}
			printf("m[%d, %d] = %-6d  s[%d, %d] = %d\n", l, j, dp[l][j], l, j, s[l][j]);
		}
		printf("\n");
	} 
}

void dfs(int l, int r) {
	if(l == r) printf("A%d", l);
	else {
		printf("(");
		dfs(l, s[l][r]);
		dfs(s[l][r] + 1, r);
		printf(")");
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i <= n; ++ i) scanf("%d", &a[i]);	
	matrix_chain_mul(); 
	printf("m[%d, %d] = %d\n", 1, n, dp[1][n]);
	puts("实际算式:");
	dfs(1, n);
	puts("");
	return 0;
}

/*
6
5 9 8 2 4 5 9

5 
2 5 12 9 5 10

7 
8 2 7 5 6 3 9 8 
*/

