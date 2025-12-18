#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

double log3(int x) {
    return log(x) / log(3);
}

void solve() {
	int n, k, num = 0;
	cin >> n >> k;
	vector<int> cnt(31);
	cnt[0] = n;
	for(int i = 1; i <= 30; i ++){
		i64 sum = 0;
		for(auto e : cnt)
			sum += e;
		if((sum - k) <= 0)
			break;

		for(int j = i - 1; j >= 0; j --){
			int tmp = (pow(3, i) - pow(3, j));
			int d = (sum - k + tmp - 1) / tmp;
			if(cnt[j] >= d * pow(3, i)){
				cnt[j] -= d * pow(3, i);
				sum -= d * pow(3, i);
				cnt[i] += d;
				sum += d;
				if((sum - k) <= 0)
					break;
			}
		}
	}
	i64 sum = 0;
	for(auto e : cnt)
		sum += e;
	if(sum - k > 0){
		cout << -1 << '\n';
		return;
	}
	i64 ans = 0;
	for(int i = 0; i <= 30; i ++){
		ans += (i64)cnt[i] * (pow(3, i + 1) + (i64)i * pow(3, i - 1));
	}
	cout << ans << '\n';
	// cout  << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}