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
	int a, b, c;
	cin >> a >> b >> c;
	if(c != a + 1){
		cout << -1 << '\n';
		return;
	}
	int cur = 1, cnt = 0;
	while(max(a, b) > 0){
		if(a >= cur){
			a -= cur;
			cur *= 2;
		}else{
			b = max(0, b - (cur - a));
			cur += a;
			a = 0;
		}
		cnt ++;
		if(a == 0 && b != 0){
			cnt += (b + cur - 1) / cur;
			break;
		}
	}
	cout << cnt << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}