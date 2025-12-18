#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;

	vector<int> st; 
	int h = 0;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == ','){
			int x = stoi(s.substr(h, i - h));
			st.push_back(x);
			// cout << x << '\n';
			h = i + 1;
		}
	}

	int x = stoi(s.substr(h, s.size() - h ));
	st.push_back(x);

	sort(st.begin(), st.end());

	// for(int e : st)
	// 	cout << e << '\n';

	int ed = st[0];
	string res;
	for(int i = 1; i < st.size(); i ++){
		if(st[i] - st[i - 1] <= 1)
			continue;
		if(st[i] - st[i - 1] > 1){
			if(st[i - 1] == ed)
				res += to_string(ed) + ",";
			else
				res += to_string(ed) + "-" + to_string(st[i - 1]) + ",";
			ed = st[i];
		}
		// cout << st[i] - st[i - 1] << '\n';
	}
	if(st[st.size() - 1] == ed)
		res += to_string(ed);
	else
		res += to_string(ed) + "-" + to_string(st[st.size() - 1]);

	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}