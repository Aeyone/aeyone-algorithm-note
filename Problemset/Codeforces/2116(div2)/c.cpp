#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;
const int inf = 0x7f7f7f7f;
const i64 infll = 0x3f3f3f3f3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int target = a[0];
	for(int i = 1; i < n; i ++)
		target = __gcd(target, a[i]);

	int cnt = 0;
	for(int i = 0; i < n; i ++)
		cnt += (a[i] == target);

	if(cnt){
		cout << n - cnt << '\n';
		return;
	}

	queue<int> q;
	vector<int> f(5010, inf);
	q.push(0);
	f[0] = 0;
	while(q.size()){
		auto t = q.front();
		q.pop();

		for(int i = 0; i < n; i ++){
			int x = __gcd(t, a[i]);
			if(f[x] > f[t] + 1){
				f[x] = f[t] + 1;
				q.push(x);
			}
		}
	}
	cout << f[target] - 1 + n - 1 << '\n';
	// cout << target << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}