#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cnt(30);
	for(auto e : s){
		cnt[e - 'a'] ++;
	}
	int mn = inf, c = n, d = 0;
	for(int i = 1; i <= n; i ++){
		if(n % i != 0 || n / i > 26){
			continue;
		}
		priority_queue<int> heap;
		for(int j = 0; j < 26; j ++) {
			if(cnt[j] == 0){
				continue;
			}
			heap.push(i - cnt[j]);
			if(heap.size() > n / i){
				heap.pop();
			}
		}
		int D = n / i - heap.size();
		int sum = D * i;
		while(heap.size() && heap.top() > 0){
			sum += heap.top();
			heap.pop();
		}
		if(sum < mn){
			mn = sum, c = i, d = D;
		}
	}
	cout << mn << '\n';
	vector<int> vis(26);
	priority_queue<pair<int, int>> heap;
	for(int j = 0; j < 26; j ++){
		if(cnt[j] == 0 && d == 0){
			continue;
		}
		vis[j] = true;
		heap.push({c - cnt[j], j});
		if(heap.size() > n / c){
			vis[heap.top().second] = false;
			heap.pop();
		}
		d -= (cnt[j] == 0);
	}
	// for(int i = 0; i < 26; i ++){
	// 	if(vis[i]){
	// 		cout << (char)('a' + i) << ' ';
	// 	}
	// }
	// cout << '\n';
	int pos = 0;
	while(pos < 26 && (!vis[pos] || cnt[pos] >= c)){
		pos ++;
	}
	for(int i = 0; i < n; i ++){
		if(pos == 26){
			break;
		}
		int u = s[i] - 'a';
		if(vis[u] && cnt[u] <= c){
			continue;
		}
		cnt[u] --;
		s[i] = 'a' + pos;
		cnt[pos] ++;
		while(pos < 26 && (!vis[pos] || cnt[pos] >= c)){
			pos ++;
		}
	}
	// sort(s.begin(), s.end());
	cout << s << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}