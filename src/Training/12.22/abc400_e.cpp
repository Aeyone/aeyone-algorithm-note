#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

const int N = 2e6;
int p[N + 1], vis[N + 1], psiz;

void build(){
	for(int i = 2; i <= N; i ++){
		if(!vis[i]){
			p[psiz ++] = i;
		}
		for(int j = 0; j < psiz && p[j] <= N / i; j ++){
			vis[p[j] * i] = true;
			if(i % p[j] == 0){
				break;
			}
		}
	}
}

void solve() {
	i64 a;
	cin >> a;
	for(int i = 0; p[i] <= a / p[i]	 && i < psiz; i ++) {

	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	build();
	cin >> _;
	while (_ --){
		solve();
	}
}