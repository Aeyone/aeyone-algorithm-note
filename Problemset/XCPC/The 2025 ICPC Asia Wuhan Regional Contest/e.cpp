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
	vector<int> a(n), b(n);
	int ca = 0, cb = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		ca += (a[i] & 1);
	}
	for(int i = 0; i < n; i ++){
		cin >> b[i];
		cb += (b[i] & 1);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	bool oka = false;
	for(int i = 0; i < n - 1; i ++){
		oka |= (a[i] == a[i + 1] - 1);
	}
	bool okb = false;
	for(int i = 0; i < n - 1; i ++){
		okb |= (b[i] == b[i + 1] - 1);
	}
	if(a == b || (ca == cb && oka && okb)){
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