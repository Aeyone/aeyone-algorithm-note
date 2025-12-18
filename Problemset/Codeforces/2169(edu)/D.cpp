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
	i64 X, y, k;
	cin >> X >> y >> k;
	if(y == 1){
		cout << -1 << '\n';
		return;
	}
	i64 cur = k;
	i64 add = (cur - 1) / (y - 1);
	if(add == 0){
		cout << k << '\n';
		return;
	}
	i64 x = max(1ll, ((add + 1) * (y - 1) - cur + add - 1) / add);
	while(X - x >= 0 && x != 0){
		X -= x;
		cur = cur + x * add;
		add = (cur - 1) / (y - 1);
		x = max(1ll, ((add + 1) * (y - 1) - cur + add - 1) / add);
		if(cur > 1e12){
			cout << -1 << '\n';
			return;
		}
	}
	i64 ans = cur + X * add;
	cout << (ans <= 1e12 ? ans : -1ll) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}