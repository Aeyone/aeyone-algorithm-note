#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

i64 qmi(i64 a, i64 b, int p){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p){
		if(b & 1)
			res = a * res % p;
	}
	return res;
}

void solve() {//沟槽的模拟
	int n, q;
	cin >> n >> q;
	vector<array<int, 2>> A(n + 1), B(n + 1);
	A[n] = B[n] = {INF, -1};
	vector<int> idxA(n), idxB(n);
	for(int i = 0; i < n; i ++){
		cin >> A[i][0];
		A[i][1] = i;
	}
	for(int i = 0; i < n; i ++){
		cin >> B[i][0];
		B[i][1] = i;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	i64 mul = 1;
	for(int i = 0; i < n; i ++){
		mul = mul * min(A[i][0], B[i][0]) % MOD;
		idxA[A[i][1]] = i;
		idxB[B[i][1]] = i;
	}
	cout << mul << ' ';
	auto work = [&](vector<array<int, 2>> &a, vector<array<int, 2>> &b, vector<int> &idx, int x)->void{
		int u = idx[x];
		int v = (--upper_bound(a.begin(), a.end(), array<int, 2>{a[u][0], INF})) - a.begin();
		int y = a[v][1];
		mul = mul * qmi(min(a[u][0], b[u][0]), MOD - 2, MOD) % MOD;
		if(u != v){
			mul = mul * qmi(min(a[v][0], b[v][0]), MOD - 2, MOD) % MOD;
		}
		a[u][0] ++;
		if(a[u][0] > a[v][0]){
			swap(a[u], a[v]);
			swap(idx[x], idx[y]);
		}
		mul = mul * min(a[u][0], b[u][0]) % MOD;
		if(u != v){
			mul = mul * min(a[v][0], b[v][0]) % MOD;
		}
	};
	while(q --){
		int o, x;
		cin >> o >> x;
		if(o == 1){
			work(A, B, idxA, x - 1);
		}
		if(o == 2){
			work(B, A, idxB, x - 1);
		}
		cout << mul << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}