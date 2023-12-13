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
	long long n , l , k , y;
	vector <long long> stones;
	cin >> n >> k;
	for(long long i = 0; n > i; i++){
		cin >> l;
		stones.push_back(l);
	}
	dp[0] = 0;
	for(long long i = 1; n > i; i++){
		y = 1e9 + 7;
		for(long long j = 1; k >= j ; j++){
			if(i - j >= 0){
				y = min(y , dp[i - j] + abs(stones[i] - stones[i - j]));
			}
			else{
				break;
			}
		}
		dp[i] = y;
	}
	cout<<dp[n-1];
	
	
}