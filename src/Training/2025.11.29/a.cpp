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
	int n, x;
	cin >> n >> x;
	x --;
	vector<int> cnt(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		cnt[u] ++, cnt[v] ++;
	}
	if(cnt[x] <= 1){
		cout << "Ayush" << '\n';
		return;
	}
	if(n & 1){
		cout << "Ashish" << '\n';
	}else{
		cout << "Ayush" << '\n';
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