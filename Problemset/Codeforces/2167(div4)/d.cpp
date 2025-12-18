#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
const int N = 100;
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
	int n;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < psiz; i ++){
		for(int j = 0; j < n; j ++){
			if(a[j] % p[i] == 0){
				while(a[j] % p[i] == 0){
					a[j] /= p[i];
				}
			}else{
				cout << p[i] << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	build();
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}