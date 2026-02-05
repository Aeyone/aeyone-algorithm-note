#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

string to_string(i64 num, int base){
	if(num == 0){
		return "0";
	}
	string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while(num){
		res += idx[num % base];
		num /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

void solve() {
	i64 l, r;
	cin >> l >> r;
	i64 ans = 0;
	string s = to_string(r, 10);
	for (int i = 0; i < s.size(); i ++) {
		string str = s;
		if (str[i] - '0' > 0) {
			str[i] --;
			for (int j = i + 1; j < s.size(); j ++) {
				str[j] = '9';
			}
			if (stoll(str) < l) {
				continue;
			}
			reverse(str.begin(), str.end());
			while (str.size() > 1 && str.back() == '0') {
				str.pop_back();
			}
			i64 x = stoll(str);
			ans = max(ans, x);
		}
	}
	reverse(s.begin(), s.end());
	while (s.size() > 1 && s.back() == '0') {
		s.pop_back();
	}
	i64 x = stoll(s);
	ans = max(ans, x);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}