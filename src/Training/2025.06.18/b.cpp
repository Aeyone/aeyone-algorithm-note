#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	vector<priority_queue<int, vector<int>, greater<int>>> h(2);
	int siz = 0;
	for(int i = 0; i < n; i ++){
		int x = s[i] - '0';
		if(h[!x].size() == 0)
			h[x].push(siz), a[i] = siz + 1, siz ++;
		else{
			int t = h[!x].top();
			h[!x].pop();
			h[x].push(t), a[i] = t + 1;
		}
	}
	cout << siz << '\n';
	for(auto e : a)
		cout << e << ' ';
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