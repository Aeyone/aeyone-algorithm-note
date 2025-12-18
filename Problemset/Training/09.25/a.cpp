#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> cnt(n + 1);//以i为父节点的
	cnt[n] = 1;
	for(int i = 1; i < n; i ++){
		int v;
		cin >> v;
		v --;
		cnt[v] ++;
	}
	sort(cnt.begin(), cnt.end(), greater<int>{});
	priority_queue<int> heap;
	int T = 0;
	for(auto e : cnt){
		if(e == 0){
			break;
		}
		heap.push(e + T);
		T ++;
	}
	while(T < heap.top()){
		int now = heap.top();
		heap.pop();
		T ++, now --;
		heap.push(now);
	}
	cout << max(T, heap.top()) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}