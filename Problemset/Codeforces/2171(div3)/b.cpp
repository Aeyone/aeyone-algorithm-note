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
	vector<int> a(n);
	for(auto &e : a){
		cin >> e;
	}
	int ans = 0;
	if(a[0] == -1 && a[n - 1] != -1){
		a[0] = a[n - 1];
		ans = 0;
	}else if(a[n - 1] == -1 && a[0] != -1){
		a[n - 1] = a[0];
		ans = 0;
	}else if(a[n - 1] != -1 && a[0] != -1){
		ans = a[n - 1] - a[0];
	}
	cout << abs(ans) << '\n';
	for(auto e : a){
		if(e == -1){
			cout << 0 << ' ';
		}else{
			cout << e << ' ';
		}
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}