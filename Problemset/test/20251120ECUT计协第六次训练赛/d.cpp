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
	string s;
	cin >> s;
	if(s == "()"){
		cout << "NO" << '\n';
		return;
	}
	int n = s.size();
	string s1, s2;
	for(int i = 0; i < n; i ++){
		s1 += "()";
		s2 += "(";
	}
	for(int i = 0; i < n; i ++){
		s2 += ")";
	}
	bool ok = false;
	for(int i = 0; i <= n; i ++){
		ok |= (s == s2.substr(i, n));
	}
	cout << "YES" << '\n';
	if(ok){
		cout << s1 << '\n';
	}else{
		cout << s2 << '\n';
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