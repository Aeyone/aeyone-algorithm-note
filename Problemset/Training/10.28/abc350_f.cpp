#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> stk, to(n, -1);
	for(int i = 0; i < n; i ++){
		if(s[i] == '('){
			stk.push_back(i);
		}else if(s[i] == ')'){
			to[i] = stk.back();
			to[stk.back()] = i;
			stk.pop_back();
		}
	}
	auto dfs = [&](auto &&self, int x, int t, int st)->void{
		if(t == 0){
			while(x < n){
				if(to[x] != -1){
					if(s[x] == '('){
						self(self, to[x] - 1, !t, x);
						x = to[x] + 1;
					}else{
						return;
					}
				}else{
					cout << s[x];
					x ++;
				}
			}
		}else{
			while(x > st){
				if(x > st && to[x] != -1){
					if(s[x] == ')'){
						self(self, to[x] + 1, !t, x);
						x = to[x] - 1;
					}else{
						return;
					}
				}else{
					s[x] = (s[x] < 'a' ? s[x] + ('a' - 'A') : s[x] - ('a' - 'A'));
					cout << s[x];
					x --;
				}
			}
		}
	};
	dfs(dfs, 0, 0, -1);
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}