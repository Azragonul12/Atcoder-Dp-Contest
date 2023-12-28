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
const long long nMax = 100;
const long long kMax = 1e5 + 7;
long long dp[kMax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector < long long> stones;
	long long n ,k , a , mnt , flag;
	cin >> n >> k;
	for(long long i = 0; n > i; i++){
		cin>> a;
		stones.push_back(a);
	}
	dp[0] = -1;
	for(long long i = 1; k >= i ; i++){
		flag = -1;
		for(long long j = 0; n > j; j++){
			if(i - stones[j] >= 0){
				if(dp[i - stones[j]] == -1){
					flag = 0;
				}
			}
			else{
				break;
			}
		}
		dp[i] = flag;

	}
	if(dp[k] == 0){
		cout<< "First\n";
	}
	else{
		cout<<"Second \n";
	}
	
}