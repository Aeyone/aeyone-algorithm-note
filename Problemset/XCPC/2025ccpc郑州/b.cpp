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
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 1e9 + 7;

void solve() {
	int l, w, h;
	cin >> l >> w >> h;
	int p, q, r;
	cin >> p >> q >> r;
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int tot = 1ll * (p + 1) * (q + 1) * (r + 1);
	if(n % tot != 0){
		cout << 0 << '\n';
		return;
	}
	sort(a.begin(), a.end(), [](const array<int, 3> &a, const array<int, 3> &b)->bool {
		return a[0] < b[0];
	});
	
	int ans = 1;
	int n1 = n / (p + 1);
	vector<vector<array<int, 3>>> b(p + 1); //x轴切p刀
	for(int l = 0, r = 0, cnt = 0; l < n; l = r, cnt ++) {
		while(r < n && r - l < n1){ //一共p + 1块，所以每一块大小为n / (p - 1)
			b[cnt].push_back(a[r]);
			r ++;
		}
		if(r < n){
			ans = ans * max(0ll, a[r][0] - a[r - 1][0]) % MOD;
		}
	}
	for(auto &v : b){
		sort(v.begin(), v.end(), [](const array<int, 3> &a, const array<int, 3> &b)->bool {
			return a[1] < b[1];
		});
	}
	vector<vector<vector<array<int, 3>>>> c(q + 1, vector<vector<array<int, 3>>>(p + 1));//y轴一共切q刀
	int n2 = n1 / (q + 1);
	for(int l = 0, r = 0, cnt = 0; l < n1; l = r, cnt ++){
		while(r < n1 && r - l < n2){
			for(int i = 0; i <= p; i ++){
				c[cnt][i].push_back(b[i][r]);
			}
			r ++;
		}
		if(r < n1){
			int mx = 0, mn = INF;
			for(int i = 0; i <= p; i ++){
				mx = max(mx, b[i][r - 1][1]);
				mn = min(mn, b[i][r][1]);
			}
			ans = ans * max(0ll, mn - mx) % MOD;
		}
	}
	int n3 = n2 / (r + 1);
	for(int i = 0; i <= q; i ++){
		for(int j = 0; j <= p; j ++){
			sort(c[i][j].begin(), c[i][j].end(), [](const array<int, 3> &a, const array<int, 3> &b)->bool {
				return a[2] < b[2];
			});
		}
	}
	for(int l = 0, r = 0; l < n2; l = r){
		while(r < n2 && r - l < n3){
			r ++;
		}
		if(r < n2){
			int mx = 0, mn = INF;
			for(int i = 0; i <= q; i ++){
				for(int j = 0; j <= p; j ++){
					mx = max(mx, c[i][j][r - 1][2]);
					mn = min(mn, c[i][j][r][2]);
				}
			}
			ans = ans * max(0ll, mn - mx) % MOD;
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