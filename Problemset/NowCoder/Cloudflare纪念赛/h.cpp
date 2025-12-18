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
	int n, hp;
	cin >> n >> hp;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	int l = 0, r = 2 * n, ans = -1;
	auto check = [&](int x)->bool{
		priority_queue<pair<int, int>> heap;
		i64 sum = 0;
		for(int i = 1; i <= min(n, x); i ++){
			sum += a[i];
			heap.push({a[i], i});
		}
		i64 mx = sum;
		for(int i = x; i >= x / 2; i --){
			if(i <= n){
				sum -= a[i];
			}
			while(heap.size() && heap.top().second >= i){
				heap.pop();
			}
			if(heap.size()){
				sum += heap.top().first;
				heap.pop();
			}
			mx = max(mx, sum);
		}
		return (mx >= hp);
	};

	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid, r = mid - 1;
		}else{
			l = mid + 1;
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