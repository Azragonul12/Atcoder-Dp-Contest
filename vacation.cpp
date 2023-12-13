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
#include<array>
using namespace std;
const long long nMax = 1e5 + 7;
long long dp[nMax][3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , x , y , z;
	vector < array < long long , 3> > vacations;
	array <long long , 3> a;
	cin >> n;
	for(long long i = 0; n > i; i++){
		cin>> x >> y >> z;
		a[0] = x;
		a[1] = y;
		a[2] = z;
		vacations.push_back(a);

	}
	for(long long i = 1; n>= i; i++){
		dp[i][0] = max(dp[i-1][1] , dp[i-1][2]) + vacations[i-1][0];
		dp[i][1] = max(dp[i-1][0] , dp[i-1][2]) + vacations[i-1][1];
		dp[i][2] = max(dp[i-1][1] , dp[i-1][0]) + vacations[i-1][2];
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	cout << max(dp[n][0] , max(dp[n][1] , dp[n][2]));
	
}