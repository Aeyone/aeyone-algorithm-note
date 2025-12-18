#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		cnt += (a[i] != i);
	}
	if(n == 2 || (s == "Alice" && cnt == 2)){
		cout << "Alice" << '\n';
		return;
	}
	if(n == 3 && s == "Bob" && cnt == 3){
		cout << "Alice" << '\n';
		return;
	}
	cout << "Bob" << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}