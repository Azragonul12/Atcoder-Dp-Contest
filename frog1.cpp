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
const int nMax = 1e5 + 7;
long long dp[nMax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , l;
	vector <long long> stones;
	cin >> n;
	for(long long i = 0; n > i; i++){
		cin >> l;
		stones.push_back(l);
	}
	dp[0] = 0;
	dp[1] = abs(stones[0] - stones[1]);
	for(long long i = 2; n > i; i++){
		dp[i] = min(dp[i - 1] + abs(stones[i] - (stones[i-1])) , dp[i - 2] + abs(stones[i] - (stones[i-2])));
	}
	cout<<dp[n-1];
	
	
}