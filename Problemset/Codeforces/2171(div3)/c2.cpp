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
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++){
		cin >> b[i];
	}
	for(int bit = 30; bit >= 0; bit --){
		int c1 = 0, c2 = 0;
		int la = 0;
		for(int i = 0; i < n; i ++){
			c1 ^= (a[i] >> bit & 1);
		}
		for(int i = 0; i < n; i ++){
			c2 ^= (b[i] >> bit & 1);
			if((a[i] >> bit & 1) ^ (b[i] >> bit & 1) & 1){
				la = i + 1;
			}
		}
		if(c1 != c2){
			if(la & 1){
				cout << "Ajisai" << '\n';
			}else{
				cout << "Mai" << '\n';
			}
			return;
		}
	}
	cout << "Tie" << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}	