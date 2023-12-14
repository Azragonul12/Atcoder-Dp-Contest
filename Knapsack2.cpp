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
#include<array>
#include<bitset>
using namespace std;
const int nMax = 105;
const long long valMax = 1e5 + 7;
long long dp[valMax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector < array <long long , 2> > knapsack;
	array <long long , 2> a;
	long long n, w , val , wgth , ans , valm;
	valm = 0;
	cin >> n >> w;
	for(long long i = 0; n > i; i++){
		cin >> wgth >> val;
		a[0] = wgth;
		a[1] = val;
		valm += val;
		knapsack.push_back(a);
	}
	dp[0] = 0;
	ans = -1;
	for(long long i = 1; valm >= i; i++){
		dp[i] = 1e9 + 7;
	}
	
	for(long long i = 0; n > i; i++){
		for(long long j = valm; j >= 0; j--){
			if(j >= knapsack[i][1]){
				dp[j] = min(dp[j - knapsack[i][1]] + knapsack[i][0] , dp[j]);
			}
			else{
				break;
			}
		}
	}
	for(long long i = 1; valm >= i; i++){
		if(dp[i] <= w){
			ans = max(ans , i);
		}
	}
	cout<<ans<<"\n";

}