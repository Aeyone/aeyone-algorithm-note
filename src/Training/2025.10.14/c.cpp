#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//无聊双指针
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a;
	for(int l = 0, r = 0; l < n; l = r){
		while(r < n && s[r] == s[l]){
			r ++;
		}
		a.push_back(r - l);
	}
	n = a.size();
	vector<pair<int, int>> b(n);
	for(int i = 0; i < n; i ++){
		b[i] = {a[i], i};
	}
	reverse(b.begin(), b.end());
	int cnt = 0;
	for(int i = 0; i < n; i ++){
		cnt ++;
		while(b.size() && (b.back().first == 1 || b.back().second < i)){
			b.pop_back();
		}
		if(b.size()){
			b.back().first --;
		}else{
			i ++;
		}
	}
	cout << cnt << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}