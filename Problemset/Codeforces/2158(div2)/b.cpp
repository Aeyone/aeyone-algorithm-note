#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n), cnt(2 * n + 1);
	for(int i = 0; i < 2 * n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	sort(cnt.begin(), cnt.end(), greater<int>{});
	if(cnt[0] == 2 * n){
		cout << 2 * (n & 1) << '\n';
		return ;
	}
	int odd = 0, cnt0 = 0, cnt2 = 0;
	for(int i = 0; i < cnt.size() && cnt[i] > 0; i ++){
		if(cnt[i] & 1){
			odd ++;
		}else{
			if(cnt[i] % 4 == 0){
				cnt0 ++;
			}else{
				cnt2 ++;
			}
		}
	}
	if(odd == 0){
		cout << 2 * (cnt0 + cnt2) - 2 * (cnt0 & 1) << '\n';
	}else{
		cout << odd + 2 * (cnt0 + cnt2) << '\n';
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