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
#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, k;
	cin >> n >> k;
	int c1 = n % k, c2 = k - (n % k);
	
	bool ok = false;
	for(int x = 0; x <= c1; x ++){
		for(int y = 0; y <= c2; y ++){
			ok |= (x * (n / k + 1) + y * (n / k) == n / 2);
		}
		// int y = (n / 2) - x * (n / k + 1);`
		// cout << "y = " << y << '\n';
		// ok |= (y >= 0 && y <= c2 * (n / k));
	}	
	if(ok){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
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