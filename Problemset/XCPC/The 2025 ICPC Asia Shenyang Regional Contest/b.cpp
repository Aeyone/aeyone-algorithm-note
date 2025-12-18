/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int>> g(n, vector<int>(m));
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> g[i][j];
			mp[g[i][j]] ++;
		}
	}
	vector<int> alls;
	i64 ans = mp[0] * b;
	for(auto [e, c] : mp){
		if(e == 0){
			continue;
		}
		ans += c * a;
		alls.push_back(c);
	}
	if(alls.size() == 0){
		cout << 0 << '\n';
		return;
	}
	sort(alls.begin(), alls.end(), greater<int>{});
	i64 cur = ans - alls[0] * a;
	ans = min(ans - alls[0] * a, ans - mp[0] * b);
	for(int i = 1; i < alls.size(); i ++){
		cur -= alls[i] * a;
		cur += (i * alls[i] + mp[0]) * b;
		ans = min(ans, cur);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}