#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n,x,ans=0;
	cin>>n>>x;
	while(n/2<x){
		if(n%4!=0&&n%2==0){
			x-=n/2-1;
			n-=n/2-1;
		}else{
			x-=n/2;
			n-=n/2;
		}
		ans++;
	}
	cout<<ans+(x!=0)<<endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}