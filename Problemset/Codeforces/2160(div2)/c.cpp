#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

string lltos(i64 num, int base){
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
}

void solve() {
	int n;
	cin >> n;
	string s = lltos(n, 2);
	reverse(s.begin(), s.end());
	int idx = 0, siz = s.size();
	while(idx < siz && s[idx] == '0'){
		s += "0";
		idx ++;
	}
	string s1 = s;
	reverse(s.begin(), s.end());
	bool ok = true;
	for(int i = 0; i < s.size(); i ++){
		ok &= (s1[i] == s[i]);
	}
	if(s.size() & 1){
		ok &= (s[s.size() / 2] == '0');
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