#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

int query(vector<int> &a){
	cout << "? " << a.size() << ' ';
	for(auto e : a){
		cout << e << ' ';
	}
	cout << endl;
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n;
	cin >> n;
	n *= 2;
	vector<int> que = {1}, res(n + 1);
	for(int i = 2; i <= n; i ++){
		que.push_back(i);
		int x = query(que);
		if(x != 0){
			res[i] = x;
			que.pop_back();
		}
	}
	que.clear();
	for(int i = 1; i <= n; i ++){
		if(res[i] != 0){
			que.push_back(i);
		}
	}
	for(int i = 1; i <= n; i ++){
		if(res[i] != 0){
			continue;
		}
		que.push_back(i);
		res[i] = query(que);
		que.pop_back();
	}
	cout << "! " << ' ';
	for(int i = 1; i <= n; i ++){
		cout << res[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	// ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}