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
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<vector<i64>> f(n, vector<i64>(32));
	priority_queue<i64> heap;
	i64 ans = INFLL;
	for(int i = 0; i < n; i ++){
		f[i][0] = __lg(a[i]);
		heap.push(f[i][0]);
		while(heap.size() > n - m){
			heap.pop();
		}
		i64 sum = 0;
		while(heap.size() > 0){
			sum += heap.top();
			heap.pop();
		}
		ans = min(ans, sum);
	}
	i64 cur = 1;
	for(int i = 1; i <= 31; i ++){
		for(int j = 0; j < 2; j ++){
			i64 d = 0;
			for(int k = 0; k < n; k ++){
				int LOG = __lg(a[k]);
				if(LOG >= i){
					d += ((a[k] >> (LOG - i) & 1) ^ j);
				}else{
					d += (a[k] << (i - LOG)) - a[k] + j;
				}
			}
			f[k]
		}
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