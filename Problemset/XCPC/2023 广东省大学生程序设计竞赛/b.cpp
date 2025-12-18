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

void solve() {//单调队列优化dp
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<array<int, 2>> v(m), seg;
	for(int i = 0; i < m; i ++){
		cin >> v[i][0] >> v[i][1];
	}
	sort(v.begin(), v.end(), [](const array<int, 2> &a, const array<int, 2> &b)->bool{
		return (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
	});
	for(int i = 0; i < m; i ++){
		while(seg.size() && seg[seg.size() - 1][1] >= v[i][1]){
			seg.pop_back();
		}
		seg.push_back({v[i][0], v[i][1]});
	}
	m = seg.size();
	vector<i64> dp(n + 1, INFLL);
	dp[0] = 0;
	deque<int> q;
	for(int i = 1, cur = -1, la = 0; i <= n; i ++){
		if(cur + 1 < m && i == seg[cur + 1][0]){
			while(q.size() && dp[q.back()] >= dp[i - 1]){
				q.pop_back();
			}
			q.push_back(i - 1);
			dp[i] = dp[q.front()] + a[i];
			cur ++;
			if(la < m && i == seg[la][1]){
				while(q.size() && q.front() < seg[la][0]){
					q.pop_front();
				}
				la ++;
			}
			continue;
		}
		if(cur >= la){
			dp[i] = min(dp[i - 1], dp[q.front()] + a[i]);
		}else{
			dp[i] = dp[i - 1];
		}
		if(la < m && i == seg[la][1]){
			while(q.size() && q.front() < seg[la][0]){
				q.pop_front();
			}
			la ++;
		}
	}
	cout << dp[n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}