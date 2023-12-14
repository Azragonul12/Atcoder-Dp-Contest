#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<numeric>
#include<utility>
#include<set>
#include<bitset>
using namespace std;
const long long modulo = 1e9 + 7;
int grid[1000][1000];
long long dp[1000][1000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long h , w;
	string str;
	cin>> h >> w;
	memset(dp , 0 , sizeof(dp));
	for(long long i = 0; h > i; i++){
		cin>> str;
		for(long long j = 0; w > j; j++){
			if(str[j] == '#'){
				grid[i][j] = 1;
			}
			else{
				grid[i][j] = 0;
			}
		}
	}
	dp[0][0] = 1;
	for(long long i = 0; h > i; i++){
		for(long long j = 0; w > j; j++){
			if(grid[i][j] == 0){
				if(j > 0 && i > 0){
					if(grid[i][j - 1] == 0 && grid[i - 1][j] == 0){
						dp[i][j] = ((dp[i][j-1] + dp[i-1][j]) % modulo);
					}
					else{
						if(grid[i][j - 1] == 0){
							dp[i][j] = dp[i][j-1];
						}
						if(grid[i - 1][j] == 0){
							dp[i][j] = dp[i - 1][j];
						}
					}
				}
				else{
					if(j > 0){
						if(grid[i][j - 1] == 0){
							dp[i][j] = dp[i][j-1];
						}
					}
					if(i > 0){
						if(grid[i - 1][j] == 0){
							dp[i][j] = dp[i - 1][j];
						}
					}
				}
			}
		}
	}
	cout<<dp[h-1][w-1];

}