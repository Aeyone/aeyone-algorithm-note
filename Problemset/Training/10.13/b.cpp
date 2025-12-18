#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//有趣的构造题
	int n;
	cin >> n;
	int st = 2;
	while((i64)st * st < n){
		st *= st;
	}
	vector<array<int, 2>> v;
	int ed = n;
	while(ed > 2){
		for(int i = ed - 1; i > st; i --){
			v.push_back({i, ed});
		}
		v.push_back({ed, st});
		v.push_back({ed, st});
		ed = st;
		st = sqrt(st);
	}
	cout << v.size() << '\n';
	for(auto [x, y] : v){
		cout << x << ' ' << y << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}