#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;

void solve() {
	int n;
	cin >> n;
	vector<pii> a(n);
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		a[i] = {x, i + 1};
	}
	sort(a.begin(), a.end());

	vector<i64> s(n), res;
	s[0] = a[0].first;
	for(int i = 1; i < n; i ++)
		s[i] = s[i - 1] + a[i].first;

	res.push_back(a[n - 1].second);
	for(int i = n - 2; i >= 0; i --){
		if(s[i] >= a[i + 1].first)
			res.push_back(a[i].second);
		else
			break;
	}

	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for(auto e : res)
		cout << e << " ";
	cout << '\n';
}

signed main(){
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}