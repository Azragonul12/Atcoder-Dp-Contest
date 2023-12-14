#include<iostream>
#include<vector>
#include<iomanip>
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
const long long nMax = 3001;
double dp[nMax][nMax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	double p , count;
	count = 0;
	vector < double> prob;
	cin>> n;
	for(long long i = 0;  n > i; i++){
		cin>>p;
		prob.push_back(p);
	}
	dp[0][0] = 1;
	for(long long i = 1;  n >= i; i++){
		for(long long j = 0;  i >= j; j++){
			if(j > 0){
				dp[i][j] = ((dp[i-1][j-1] * prob[i-1]) + (dp[i-1][j] * (1 - prob[i-1])));
			}
			else{
				dp[i][j] = (dp[i-1][j] * (1 - prob[i-1]));
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<"\n";
	}
		for(long long j = ((n + 1) / 2);  n >= j; j++){
			count += dp[n][j];
		}
		cout<<setprecision(10) << count;
	

	
}