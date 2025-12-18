/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	if(s == t){
		cout << 0 << '\n';
		return;
	}
	if(s[0] != t[0]){
		cout << -1 << '\n';
		return;
	}
	n = s.size();
	string s0 = s;
	vector<int> la(26, -1);
	vector<vector<int>> ne(n + 1, vector<int>(26, -1));
	la[s0[0] - 'a'] = 0;
	ne[0][s0[0] - 'a'] = la[s0[0] - 'a'];
	for(int i = 1; i < n; i ++){
		int u = s0[i] - 'a';
		ne[i] = ne[i - 1];
		la[u] = i;
		ne[i][u] = la[u];
	}
	vector<int> tar(n, -1);
	int cur = n - 1;
	bool ok = true;
	for(int i = n - 1; i >= 0; i --){
		int u = t[i] - 'a';
		cur = min(cur, i);
		if(ne[cur][u] == -1){
			cout << -1 << '\n';
			return;
		}
		tar[ne[cur][u]] = max(tar[ne[cur][u]], i);
		ok &= (cur - ne[cur][u] <= k);
		cur = ne[cur][u];
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	vector<string> v;
	while(v.size() < k){
		string s0 = s;
		vector<int> to = tar;
		for(int i = 0; i < n; i ++){
			if(to[i] == -1){
				continue;
			}
			if(to[i] > i){
				tar[i + 1] = to[i];
				s[i + 1] = s0[i];
			}
		}
		v.push_back(s);
		if(s == t){
			break;
		}
	}
	if(v.back() == t){
		cout << v.size() << '\n';
		for(auto e : v){
			cout << e << '\n';
		}
	}else{
		cout << -1 << '\n';
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