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
const int wMax = 1e5 + 7;
long long dp[wMax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector < array <long long , 2> > knapsack;
	array <long long , 2> a;
	long long n, w , val , wgth , ans;
	memset(dp , 0 , sizeof(dp));
	cin >> n >> w;
	for(long long i = 0; n > i; i++){
		cin >> wgth >> val;
		a[0] = wgth;
		a[1] = val;
		knapsack.push_back(a);
	}
	dp[0] = 0;
	ans = -1;
	for(long long i = 0; n > i; i++){
		for(long long j = w; j >= 0; j--){
			if(j >= knapsack[i][0]){
				dp[j] = max(dp[j - knapsack[i][0]] + knapsack[i][1] , dp[j]);
				ans = max(dp[j] , ans);
			}
			else{
				break;
			}
		}
	}
	cout<<ans<<"\n";

}