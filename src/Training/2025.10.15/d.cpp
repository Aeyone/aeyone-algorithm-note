#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	if(k == 1){
		cout << "YES" << '\n';
		return;
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	map<int, int> mp;
	while(b.size() >= k){
		mp[b.back()] ++;
		b.pop_back();
	}
	int x = -1, cnt = INF;
	if(mp.find(b.back()) != mp.end()){
		x = b.back();
		cnt = mp[x];
	}
	vector<int> v1, v2;
	for(int i = 0; i < n; i ++){
		if(a[i] == x || mp.find(a[i]) == mp.end()){
			v1.push_back(a[i]);
		}
		if(mp.find(a[i]) == mp.end()){
			v2.push_back(a[i]);
		}
	}
	int len1 = v1.size(), len2 = v2.size();
	if(len2 == 0){
		cout << "YES" << '\n';
		return;
	}
	vector<int> v3 = v2;
	reverse(v3.begin(), v3.end());
	if(v3 != v2){
		cout << "NO" << '\n';
		return;
	}
	int l = 0, r = len1 - 1, need = 0;
	while(l <= r){
		while(l < len1 && v1[l] == x && v1[l] != v1[r]){
			l ++, need ++;
		}
		while(r >= 0 && v1[r] == x && v1[l] != v1[r]){
			r --, need ++;
		}
		l ++, r --;
	}
	if(need > cnt){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
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