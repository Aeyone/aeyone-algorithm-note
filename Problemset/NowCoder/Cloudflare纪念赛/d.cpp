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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> a;
	for(int l = 0, r = 0; l < n; l = r){
		while(r < n && s[l] == s[r]){
			r ++;
		}
		a.push_back(r - l);
	}
	i64 ans = 0;
	if(k != 1){
		for(int i = 0; i + k - 1 < a.size(); i ++){
			ans += (a[i] * a[i + k - 1]);
		}
	}else{
		for(auto e : a){
			ans += e * (e + 1) / 2;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}