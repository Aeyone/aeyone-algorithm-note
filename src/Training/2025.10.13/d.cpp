#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n), cnt(n + 1), res(n + 1);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	multiset<int> st;
	for(int i = 0; i <= n; i ++){
		int x = cnt[i];
		while(x > 1){
			st.insert(i);
			x --;
		}
	}
	sort(a.begin(), a.end());
	int mex = 0, ok = false;
	for(int i = 0; i < n; i ++){
		mex += (a[i] == mex);
		ok |= (i < a[i]);
		if(ok){
			res[i + 1] = -1;
		}
	}
	for(int i = mex + 1; i <= n; i ++){
		if(res[i] == -1){
			break;
		}
		res[i] = res[i - 1];
		if(cnt[i - 1] > 0){
			continue;
		}
		auto it = st.lower_bound(i);
		if(it != st.begin()){
			-- it;
			res[i] += (i - 1 - *it);
			st.erase(it);
		}
	}
	for(int i = 0; i <= n; i ++){
		cout << (res[i] == -1 ? -1 : res[i] + cnt[i]) << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}