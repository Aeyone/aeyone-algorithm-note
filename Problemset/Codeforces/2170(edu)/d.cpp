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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int cnt = 0, tot = 0, sum = 0;
	for(int l = 0, r = 0; l < n; l = r){
		while(l < n && s[l] == s[r]){
			r ++;
		}
		if(r < n && s[l] == '?' && (s[r] == 'V' || s[r] == 'X')){
			cnt ++;
		}
		if(s[l] == 'I')
	}
	while(q --){
		int i, v, x;
		cin >> i >> v >> x;
		int de = min(i, cnt);

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