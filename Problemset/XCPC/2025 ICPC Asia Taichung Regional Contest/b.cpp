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
	int n, m, l, x, y;
	cin >> n >> m >> l >> x >> y;
	vector<array<int, 2>> bus(n), p(m);
	for(int i = 0; i < n; i ++){
		cin >> bus[i][0] >> bus[i][1];
	}
	for(int i = 0; i < m; i ++){
		cin >> p[i][0];
		p[i][1] = i;
	}
	sort(bus.begin(), bus.end());
	sort(p.begin(), p.end());

	vector<double> ans(m);
	priority_queue<pair<int, int>> heap;
	for(int i = 0, idx = 0; i < m; i ++){
		while(idx < n && bus[idx][0] <= p[i][0]){
			heap.push({(x - y) * bus[idx][1] + y * bus[idx][0], bus[idx][1]});
			idx ++;
		}
		while(heap.size() && heap.top().second <= p[i][0]){
			heap.pop();
		}
		ans[p[i][1]] = double(l - p[i][0]) / y;
		if(heap.size()){
			// cout << "top = " << heap.top().first << '\n';
			ans[p[i][1]] = min(
				ans[p[i][1]], 
				ans[p[i][1]] + double(p[i][0]) / y - (double)heap.top().first / (x * y)
			);
		}
	}
	for(int i = 0; i < m; i ++){
		printf("%.8f\n", ans[i]);
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}