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

#define int long long
#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, k, m, c, d;
	cin >> n >> k >> m >> c >> d;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}

	auto check = [&](int x)->bool{
		vector<int> f(n + 1);
		for(int i = 0; i < n; i ++){
			if(a[i] >= x){
				f[m - 1] ++;
				continue;
			}
			int R = min(m - 1, i);
			int mn = a[i] + c, mx = a[i] + c + R * d;
			if(mx < x){
				continue;
			}
			f[max(m - 1, i)] ++;
			if(mn >= x){//最小值都大于x，那么只有出去的时候才需要减一
				f[min(n, i + m)] --;
			}else{
				int cnt = (x - mn + d - 1) / d;
				f[min(n, i + m - cnt)] --;
			}
		}
		int cnt = 0;
		bool ok = false;
		for(int i = m - 1; i <= n; i ++){
			cnt += f[i];
			ok |= (cnt >= k);
		}
		return ok;
	};

	int l = 0, r = INFLL, ans = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid, l = mid + 1;
		}else{
			r = mid - 1;
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