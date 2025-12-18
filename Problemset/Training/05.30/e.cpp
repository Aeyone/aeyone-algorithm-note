#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	vector<string> s(3);
	cin >> s[0] >> s[1] >> s[2];
	pair<int, char> cnt[3] = {{0, 'A'},{0,'B'},{0,'C'}};
	for(int i = 0; i < 3; i ++){
		if(s[i][1] == '>')
			cnt[s[i][0] - 'A'].first ++;
		else
			cnt[s[i][2] - 'A'].first ++;
	}
	sort(cnt, cnt + 3);
	if(cnt[0].first == 1 && cnt[1].first == 1){
		cout << "Impossible\n";
		return;
	}
	for(int i = 0; i < 3; i ++)
		cout << cnt[i].second;
	cout << '\n';
}	

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}