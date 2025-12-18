#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<int, bool> st, vis;
	for(int i = 0; i < s.size(); i ++)
		if(s[i] == '1')
			st[i + 1] = true;
	
	queue<int> q;
	int x = (1 << n) - 1;
	if(!st[x])
		q.push(x);
	vis[x] = true;
	while(q.size()){
		int now = q.front();
		q.pop();
		for(int i = 0; (now >> i) > 0; i ++){
			if((now >> i) & 1){
				int tmp = now - (1 << i);
				if(!st[tmp] && !vis[tmp])
					q.push(tmp), vis[tmp] = true;
			}
		}
	}
	if(vis[0])
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}