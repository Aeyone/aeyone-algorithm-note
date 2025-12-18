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
	string s;
	cin >> s;
	int l, r, u, d;
	l = count(s.begin(), s.end(), 'L');
	r = count(s.begin(), s.end(), 'R');
	u = count(s.begin(), s.end(), 'U');
	d = count(s.begin(), s.end(), 'D');
	if((u == 0 && d == 0) || (l == 0 && r == 0) ){
		cout << max({l, r, u, d}) + 1 << '\n';
	}else if(u == d && l == r){
		cout << n << '\n';
	}else{
		cout << n + 1 << '\n';
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