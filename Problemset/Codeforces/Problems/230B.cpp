#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e6 + 10;

int p[N];
bool vis[N], hp[N];

void prime(){
	int idx = 0;
	for(int i = 2; i <= N; i ++){
		if(!vis[i])
			p[idx ++] = i, hp[i] = true;
		for(int j = 0; p[j] <= N / i; j ++){
			vis[i * p[j]] = true;
			if(i % p[j] == 0)
				break;
		}
	}
}

void solve() {
	int n;
	cin >> n;
	prime();
	vector<i64> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(auto e : a){
		if(sqrt(e) != (int)sqrt(e)){
			cout << "NO" << '\n';
			continue;
		}
		if(hp[(int)sqrt(e)])
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	// int _;
	// cin >> _;
	// while (_ --)
		solve();
}