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

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	int x = 0;
	cin >> x;
	set<int> st = {0, x};
	i64 cur = x * 2;
	cout << cur << '\n';
	for(int i = 1; i < n; i ++){
		int x;
		cin >> x;
		auto lo = --st.lower_bound(x);
		auto hi = st.upper_bound(x);
		if(hi == st.end()){
			int la = *lo;
			int back = (la - *prev(lo));
			cur -= back;
			cur += (x - la) + min(x - la, back);
		}else{
			int ne = *hi, la = *lo;
			int front = INFLL, back = INFLL;
			if(hi != --st.end()){
				front = (*next(hi) - ne);
			}
			if(lo != st.begin()){
				back = (la - *prev(lo));
			}
			cur -= (min(front, ne - la) + min(back, ne - la));
			cur += min(front, ne - x) + min(back, x - la) + min(x - la, ne - x);
		}
		st.insert(x);
		cout << cur << '\n';
	}
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