#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	set<int> st;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		st.insert(a[i]);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	map<int, bool> vis;
	vector<int> b;
	for(int i = 0; i < a.size(); i ++){
		if(vis[a[i]]){
			continue;
		}
		for(int j = 2; j * a[i] <= k; j ++){
			if(st.find(j * a[i]) == st.end()){
				cout << -1 << '\n';
				return;
			}else{
				vis[j * a[i]] = true;
			}
		}
		b.push_back(a[i]);
	}
	cout << b.size() << '\n';
	for(auto e : b){
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}