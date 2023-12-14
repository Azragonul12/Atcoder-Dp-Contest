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
const long long nMax = 1e5 + 7;
vector <long long> adj[nMax];
int vis[nMax];
long long dp[nMax];
void dfs(long long curNum){
		vis[curNum]  = 1;
		for(long long i = 0; adj[curNum].size() > i; i++){
			if(vis[adj[curNum][i]] == 0){
				dfs(adj[curNum][i]);
			}
			dp[curNum] = max(dp[curNum] , dp[adj[curNum][i]] + 1);
		}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , m , x , y;
	cin>> n >> m;
	memset(vis , 0 , sizeof(vis));
	memset(dp , 0 , sizeof(dp));
	for(long long i = 0; m > i;i++){
		cin>> x >> y;
		adj[x-1].push_back(y-1);
	}
	y = -1;
	for(long long i = 0; n > i;i++){
		if(vis[i] == 0){
			dfs(i);
		}
		y = max(dp[i] , y);

	}
	cout << y;

}