#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector<i64> a;
const int N = 1e3;
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
	auto check = [&](i64 x)->bool{
		int tot = 0;
		for(int i = 0; i < psiz; i ++) {
			int cnt = 0;
			while(x % p[i] == 0) {
				x /= p[i];
				cnt ++;
			}
			tot += (cnt > 0);
			if(tot == 2) {
				return (x == 1);
			}
		}
		return (tot == 1 && x > 1);
	};
	for(int i = 0; i <= 1e6; i ++) {
		if(check(i + 2)){
			a.push_back(1ll * (i + 2) * (i + 2));
		}
	}
}

void solve() {
	i64 n;
	cin >> n;
	i64 x = *(-- upper_bound(a.begin(), a.end(), n));
	cout << x << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	build();
	while (_ --){
		solve();
	}
}