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

void solve() {//简单计数题
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	map<int, i64> sum, la, cur;
	i64 ans = 0;
	for(int i = 1; i <= n; i ++){
		ans += cur[a[i]] * (n - i + 1);
		sum[a[i]] += (i - la[a[i]]);
		cur[a[i]] += sum[a[i]];
		la[a[i]] = i;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}