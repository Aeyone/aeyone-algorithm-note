#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;
const int mod = 998244353;

int qmi(int a, int b){
	int res = 1;
	while(b){
		if(b & 1)
			res = (i64)a * res % mod;
		b >>= 1;
		a = (i64)a * a % mod;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> p(n), q(n), r(n);
	for(int i = 0; i < n; i ++)
		cin >> p[i];
	for(int i = 0; i < n; i ++)
		cin >> q[i];

	priority_queue<pii> h1, h2;

	for(int j = 0; j < n; j ++){
		h1.push({p[j], j});
		h2.push({q[j], j});

		int t1 = h1.top().first;
		int t2 = h2.top().first;

		int d1 = q[j - h1.top().second];
		int d2 = p[j - h2.top().second];
		if(t1 > t2 || (t1 == t2 && d1 >= d2))
			r[j] = (qmi(2, t1) % mod + qmi(2, d1) % mod) % mod;
		else if(t1 < t2 || (t1 == t2 && d1 < d2))
			r[j] = (qmi(2, t2) % mod + qmi(2, d2) % mod) % mod;
	}
	for(auto e : r)
		cout << e << " ";
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}