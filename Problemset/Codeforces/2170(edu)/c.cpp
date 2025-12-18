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

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	multiset<int> q, r;
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		q.insert(x);
	}

	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		r.insert(x);
	}
	int cnt = 0;
	
	for(auto e : r){
		auto it = q.upper_bound((k - e) / (e + 1));
		if(it != q.begin()){
			q.erase(--it);
			cnt ++;
		}
	}

	cout << cnt << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}