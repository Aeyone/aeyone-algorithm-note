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
	int c1 = 0, c2 = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		c1 ^= (a[i] & 1);
	}
	int la = 0;
	for(int i = 0; i < n; i ++){
		cin >> b[i];
		c2 ^= (b[i] & 1);
		if(a[i] ^ b[i] & 1){
			la = i + 1;
		}
	}
	if(c1 == c2){
		cout << "Tie" << '\n';
		return;
	}
	if(la & 1){
		cout << "Ajisai" << '\n';
	}else{
		cout << "Mai" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}	