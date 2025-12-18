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
	string a, b;
	cin >> a >> b;
	string c = a;
	a += c;
	int ans = INF;
	auto kmp = [&](string s, string p)->void{
		int n = p.size(), m = s.size();
		s = " " + s;
		p = " " + p;
		vector<int> ne(n + 1);
		for(int i = 2, j = 0; i <= n; i ++){
	        while(j && p[i] != p[j + 1]){
	            j = ne[j];
	        }
	        if(p[i] == p[j + 1]){
	            j ++;
	        }
	        ne[i] = j;
	    }
	    for(int i = 1, j = 0; i <= m; i ++){
	        while(j && s[i] != p[j + 1]){
	            j = ne[j];
	        }
	        if(s[i] == p[j + 1]) {
	            j ++ ;
	        }
	        if(j == n){
	            ans = min(ans, min(i - n, i));
	            j = ne[j];
	        }
	    }
	};
	kmp(a, b);
	cout << (ans == INF ? -1 : ans) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}