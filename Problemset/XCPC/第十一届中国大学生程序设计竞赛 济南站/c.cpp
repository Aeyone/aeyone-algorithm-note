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
	int m;
	cin >> m;
	vector<int> a(m), back(1e6 + 1, -1);
	for(int i = 0; i < m; i ++){
		cin >> a[i];
	}
	for(int i = 1; i < m; i ++){
		back[a[i]] = a[i - 1];
	}
	int N;
	cin >> N;
	while(N --){
		int n;
		cin >> n;
		vector<int> cnt(1e6 + 1);
		for(int i = 0; i < n; i ++){
			int x;
			cin >> x;
			if(back[x] != -1 && cnt[back[x]] > 0){
				cnt[back[x]] --;
				cnt[x] ++;
			}
			if(x == a[0]){
				cnt[x] ++;
			}
		}
		cout << cnt[a[m - 1]] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}