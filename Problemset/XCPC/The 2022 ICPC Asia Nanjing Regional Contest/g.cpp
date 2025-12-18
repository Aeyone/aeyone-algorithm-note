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
	int n;
	cin >> n;
	vector<int> a(n + 1), pre(n + 1);
	pre[0] = 1;
	bool ok = true;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i] + (a[i] == 0);
		ok &= (pre[i] > 0);
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	int suf = INF;
	for(int i= n; i >= 1; i --){
		suf = min(suf, pre[i]);
		if(a[i] == 0){
			if(suf >= 3){
				suf -= 2, a[i] = -1;
			}else{
				a[i] = 1;
			}
		}
	}
	int cnt = 1, lev = 1;
	for(int i = 1; i <= n; i ++){
		if(a[i] == 1){
			cnt ++, lev ++;
		}
		if(a[i] == -1){
			cnt --;
		}
	}
	int g = __gcd(cnt, lev);
	cout << lev / g << ' ' << cnt / g << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}