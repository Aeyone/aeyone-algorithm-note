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
	int n, m;
	cin >> n >> m;
	multiset<int> st, a;
	vector<array<int, 2>> B(m), b;
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		a.insert(x);
	}
	for(int i = 0; i < m; i ++){
		cin >> B[i][0];
	}
	for(int i = 0; i < m; i ++){
		cin >> B[i][1];
	}
	for(auto [e, c] : B){
		if(c == 0){
			st.insert(e);
		}else{
			b.push_back({e, c});
		}
	}
	int ans = 0;
	sort(b.begin(), b.end(), greater<array<int, 2>>{});
	while(b.size() && b.back()[0] <= *(--a.end())){
		auto it = a.lower_bound(b.back()[0]);
		int x = *it;
		a.erase(it);
		x = max(x, b.back()[1]);
		a.insert(x);
		b.pop_back();
		ans ++;
	}
	while(a.size() && st.size()){
		auto it = st.upper_bound(*(--a.end()));
		if(it == st.begin()){
			break;
		}
		st.erase(-- it);
		a.erase((--a.end()));
		ans ++;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}