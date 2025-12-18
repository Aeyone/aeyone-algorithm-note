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
	vector<i64> a(n), cnt(n + 1);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	i64 mx = *max_element(cnt.begin(), cnt.end()), ans = 0;
	for(int i = 1; i <= n; i ++){
		if(cnt[i] == 0){
			continue;
		}
		i64 sum = cnt[i], cur = cnt[i];
		for(int j = i + 1; j <= n; j ++){
			if(cnt[j] == 0){
				continue;
			}
			ans = (ans + cur * cnt[j] % MOD) % MOD;
			sum += cnt[j];
			if(sum >= mx){
				cur = cur * (cnt[j] + 1) % MOD;
			}else{
				cur = cur *
			}
		}
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