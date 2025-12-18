#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int>> a(2);
	for(int l = 0, r = 0; l < n; l = r){
		while(r < n && s[l] == s[r]){
			r ++;
		}
		a[s[l] - '0'].push_back(r - l);
	}
	if(a[0].size() == 0 || a[1].size() == 0){
		cout << 0 << '\n';
		return;
	}
	int mx0 = *max_element(a[0].begin(), a[0].end());
	int sum0 = count(s.begin(), s.end(), '0');
	int mx1 = *max_element(a[1].begin(), a[1].end());
	int sum1 = n - sum0;
	cout << min(sum0 + 2 * (sum1 - mx1), sum1 + 2 * (sum0 - mx0)) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}