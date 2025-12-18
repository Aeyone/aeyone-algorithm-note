#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int N = 2e5;
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
	vector<array<int, 2>> a(n);
	vector<bool> pv(psiz);
	auto divide = [&](int x, int sign)->bool{
		for(int i = 0; i < psiz && p[i] <= x / p[i]; i ++){
			if(x % p[i] == 0){
				if(pv[vis[p[i]]]){
					return true;
				}
				if(sign){
					pv[vis[p[i]]] = true;
				}
			}
			while(x % p[i] == 0){
				x /= p[i];
			}
		}
		if(x > 1){
			if(pv[vis[x]]){
				return true;
			}
			if(sign){
				pv[vis[x]] = true; 
			}
		}
		return false;
	};
	bool ok = false;
	for(int i = 0; i < n; i ++){
		cin >> a[i][1];
		ok |= divide(a[i][1], 1);
	}
	for(int i = 0; i < n; i ++){
		cin >> a[i][0];
	}
	if(ok){
		cout << 0 << '\n';
		return;
	}
	sort(a.begin(), a.end());
	i64 ans = (a[0][1] & 1 ? a[0][0] : 0) + (a[1][1] & 1 ? a[1][0] : 0);
	for(int i = 0; i < psiz; i ++){
		if(!pv[i] || a[0][1] % p[i] == 0){
			continue;
		}
		ans = min(ans, (i64)a[0][0] * (p[i] - (a[0][1] % p[i])));
	}
	for(auto [cost, x] : a){
		if(divide(x + 1, 0)){
			ans = min(ans, (i64)cost);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	build();
	for(int i = 0; i < psiz; i ++){
		vis[p[i]] = i;
	}
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}