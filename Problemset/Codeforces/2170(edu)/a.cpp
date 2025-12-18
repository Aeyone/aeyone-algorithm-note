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
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			int sum = (i - 1) * n + j;
			for(int k = 0; k < 4; k ++){
				int x = i + dx[k], y = j + dy[k];
				if(x < 1 || x > n || y < 1 || y > n){
					continue;
				}
				sum += (x - 1) * n + y;
			}
			ans = max(ans, sum);
		}
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