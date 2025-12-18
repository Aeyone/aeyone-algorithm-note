	/*
	                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
	             __.'              ~.   .~              `.__
	           .'//   A    C    之   \./  之    真    理   \`.
	         .'//                     |                     \`.
	       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
	     .'//.-"                 `-.  |  .-'                 "-.\`.
	   .'//______.============-..   \ | /   ..-============.______\`.
	 .'______________________________\|/______________________________`.
	*/
	#include <bits/stdc++.h>
	using namespace std;

	using i64 = long long;

	#define INF 0x7f7f7f7f
	#define INFLL 0x7f7f7f7f7f7f7f7fLL

	const int MOD = 998244353;

	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), cnt(m);
		for(int i = 0; i < n; i ++){
			cin >> a[i];
			cnt[a[i] % m] = (cnt[a[i] % m] + 1) % m;
		}
		if(n > m){
			cout << 0 << '\n';
			return;
		}
		vector<vector<int>> mi(m, vector<int>(m));
		for(int i = 0; i < m; i ++){
			mi[i][0] = 1;
		}
		for(int i = 0; i < m; i ++){
			for(int j = 1; j < m; j ++){
				mi[i][j] = mi[i][j - 1] * i % m;
			}
		}
		sort(a.begin(), a.end());
		i64 ans = 1;
		for(int i = 0; i < n; i ++){
			a[i] %= m;
			cnt[a[i]] = (cnt[a[i]] - 1) % m;
			for(int j = 0; j < m; j ++){
				ans = ans * mi[(j + m - a[i]) % m][cnt[j]] % m;
			}
		}
		cout << ans << '\n';
	}

	signed main() {
		ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int _ = 1;
		// cin >> _;
		while (_ --){
			solve();
		}
	}