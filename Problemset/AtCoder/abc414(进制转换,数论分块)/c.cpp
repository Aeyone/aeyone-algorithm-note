#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 a, n;
	cin >> a >> n;

	auto check = [&](string s)->bool{
		int l = 0, r = s.size() - 1;
		bool ok = true;
		while(l < r)
			ok &= (s[l ++] == s[r --]);
		return ok;
	};

	auto toBase = [&](i64 num, int base)->string{
		if(num == 0)
			return "0";
		string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string res;
		while(num){
			res += idx[num % base];
			num /= base;
		}
		reverse(res.begin(), res.end());
		return res;
	};

	i64 ans = 0;
	for(int k = 0; k <= 999999; k ++){
		string s1 = to_string(k);
		string s2 = s1;
		reverse(s2.begin(), s2.end());

		string res = s1 + s2;
		int x = 0;
		while(x <= 10){
			i64 num = stoll(res);
			if(num > n)
				break;
			if(num <= n && check(toBase(num, a)))
				ans += num;
			if(k == 0)
				res = to_string(x);
			else
				res = s1 + to_string(x) + s2;
			x ++;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}