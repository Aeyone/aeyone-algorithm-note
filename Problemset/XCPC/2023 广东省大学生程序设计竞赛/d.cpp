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

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	i64 ans = 0;
	priority_queue<int> heap;
	for(int i = 0; i < n; i ++){
		int x, y;
		cin >> x >> y;
		ans += x;
		heap.push(y - x);
	}
	if(n == 1){
		ans += heap.top();
		heap.pop();
	}
	for(int p = 0; p < m - n && heap.size() > 0; p ++){
		int x = heap.top();
		heap.pop();
		if(x <= 0){
			break;
		}
		ans += x;
		if(heap.size() == 1){
			ans = max(ans + heap.top(), ans - x);
			break;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}