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
long long dp[3001][3001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str , str1;
	long long l , r;
	long long flag = 0;
	cin>> str >> str1;
	l = str.length();
	r = str1.length();
	for(long long i = 0; l >= i;i++){
		for(long long j = 0; r >= j;j++){
			if(i != 0 && j != 0){
				if(str[i-1] == str1[j-1]){
					dp[i][j] = (dp[i-1][j-1] + 1);
				}
				else{
					dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
				}
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	string ans = "";
	while(l > 0 && r > 0){
		if(str[l-1] == str1[r-1]){
			ans+= str[l-1];
			l--;
			r--;
		}
		else{
			if(dp[l-1][r] > dp[l][r-1]){
				l--;
			} 
			else{
				r--;
			}
		}
	}
	reverse(ans.begin() , ans.end());
	cout<< ans;
	
}