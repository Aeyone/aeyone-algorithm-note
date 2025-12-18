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

#define int long long
#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int N = 1 << __lg(b) + 1;
	vector<vector<array<int, 2>>> g(N);
	for(int i = 0; i < N; i ++){
		int u = (i ^ b) % N, v = (i + b) % N;
		g[i].push_back({u, 0});
		g[i].push_back({v, 1});
	}
	vector<vector<int>> dis(N, vector<int>(b, INFLL));
	queue<array<int, 2>> q;
	q.push({a, a % N});
	dis[a % N][a % b] = a;
	while(q.size()){
		auto [st, u] = q.front();
		q.pop();
		for(auto [e, op] : g[u]){
			int w = (op ? (dis[st % N][st % b] + b) : (dis[st % N][st % b] ^ b));
			int v = (op ? (st + b) : (st ^ b));
			if(dis[v % N][v % b] > w){
				dis[v % N][v % b] =  w;
				q.push({(op ? (st + b) : (st ^ b)), e});
			}
		}
	}
	bool ok = false;
	for(int i = 0; i < N; i ++){
		ok |= (dis[i][c % b] <= c);
	}
	if(ok){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
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