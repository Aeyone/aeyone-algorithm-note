#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;
const int N = 20000;
int num[650], dp[N];//total = 632	

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int s = 0, n = 632;
	for(int i = 1; i <= n; i ++)
		s += i, num[i] = s;

	memset(dp, 0x3f, sizeof dp);
	vector<vector<int>> data(N + 1);
	dp[0] = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = num[i]; j <= N - 10; j ++){
			if(dp[j] > dp[j - num[i]] + i + 1){
				dp[j] = dp[j - num[i]] + i + 1;
				data[j] = data[j - num[i]];
				data[j].push_back(i);
			}
		}
	}
	int _ = 1;
	cin >> _;
	while (_ --){
		int k;
		cin >> k;
		string s;
		for(auto e : data[k]){
			int x = e;
			while(x --)
				s += "1";
			s += "0";
		}
		s.pop_back();
		cout << s << '\n';
	}
}