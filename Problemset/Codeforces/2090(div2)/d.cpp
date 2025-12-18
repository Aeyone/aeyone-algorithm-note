#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 300300;
int p[N], vis[N], idx;

bool isprime(i64 x){
	if(x <= 1)
		return false;
	bool res = true;
	for(i64 i = 2; i <= x / i; i ++){
		res &= (x % i != 0);
		if(!res)
			break;
	}
	return res;
}

void getPrime(int n){
	for(int i = 2; i <= n; i ++){
		if(!vis[i])
			p[++ idx] = i;
		for(int j = 1; p[j] <= n / i; j ++){
			vis[i * p[j]] = true;
			if(i % p[j] == 0)
				break;
		} 
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> res(n + 1);
	res[1] = 2;
	res[2] = 1;
	i64 sum = 3;
	set<i64> st;
	for(int i = 3; i <= n; i ++)
		st.insert(i);
		// res[i] = i;

	int u = 1;
	for(int i = 3; i <= n; i ++){
		int tmp = *st.begin();
		if(isprime((sum + tmp + i - 1) / i)){
			res[i] = tmp;
		}else{
			while(p[u] < (sum + tmp + i - 1) / i)
				u ++;
			i64 target = (i64)i * (p[u] - 1) - sum + 1;
			auto it = st.upper_bound(target - 1);
			if(it == st.end())
				res[i] = *(--st.end());
			else
				res[i] = *it;
		}
		st.erase(res[i]);
		sum += res[i];

	}
	// int cnt = 0;
	// sum = 0;
	// for(int i = 1; i <= n; i ++){
	// 	sum += p[i];
	// 	int x = (sum + i - 1) / i;
	// 	if(isprime(x))
	// 		cnt ++;
	// 	// cout << sum << ' ';
	// }
	// // cout << '\n';
	// // cout << cnt << '\n';
	for(int i = 1; i <= n; i ++)
		cout << res[i] << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	getPrime(N);
	while (_ --)
		solve();
}