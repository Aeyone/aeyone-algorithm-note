#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	if(!(n & 1)){
		int cur = 1;
		for(int i = 0; i < n; i ++){
			cout << cur << " ";
			cur += (i & 1);
		}
		cout << '\n';
	}else if(n > 26){
		vector<int> res(n);
		res[0] = 1, res[9] = 1, res[25] = 1;
		int cur = 2;
		for(int i = 1; i < 9; i ++){
			res[i] = cur;
			cur += !(i & 1);
		}
		for(int i = 10; i < 25; i ++){
			res[i] = cur;
			cur += (i & 1);
		}
		swap(res[24], res[22]);
		for(int i = 26; i < n; i ++){
			res[i] = cur;
			cur += !(i & 1);
		}
		for(auto e : res){
			cout << e << ' ';
		}
		cout << '\n';
	}else{
		cout << -1 << '\n';
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