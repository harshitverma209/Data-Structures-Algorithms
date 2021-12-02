#include<iostream>
#include<vector>
using namespace std;
long long mixtures(vector<int> v, int i, int j, long long dp[500][500])
{
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	long long res = INT_MAX;

	for (int k = i; k < j; k++)
	{
		long long ans = mixtures(v, i, k, dp) + mixtures(v, k + 1, j, dp);
		ans += ( ( (v[k] - (i > 0 ? v[i - 1] : 0) ) % 100 ) * ((v[j] - v[k]) % 100) );
		res = min(res, ans);
	}

	return dp[i][j] = res;
}

long long minimumSmoke(vector<int> v)
{
	long long dp[500][500];
	memset(dp, -1, sizeof dp);

	int n = v.size();
	for (int i = 1; i < n; i++)
	{
		v[i] += v[i - 1]; //cumulative sum
	}
    for(auto r:dp){
        for(auto c:r){
            cout<<c<<"\t";
        }
        cout<<endl;
    }
	long long ans = mixtures(v, 0, n - 1, dp);
	return ans;
}
int main(){
    vector<int> mixtures={20,40,60};
    long l=minimumSmoke(mixtures);

    return 0;
}