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

i64 qmi(i64 a, i64 b, int p){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p){
		if(b & 1)
			res = a * res % p;
	}
	return res;
}

void solve() {//gcd & lcm 数论
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> cnt(200001);
	vector<int> need(200001, n);
	auto divide = [&](int x)->void{
		for(int i = 2; i <= x / i; i ++){
			int tot = 0;
			while(x % i == 0){
				x /= i;
				tot ++;
			}
			cnt[i].push_back(tot);
			need[i] --;
			sort(cnt[i].begin(), cnt[i].end());
			while(cnt[i].size() > 2){
				cnt[i].pop_back();
			}
		}
		if(x > 1){
			cnt[x].push_back(1);
			need[x] --;
			sort(cnt[x].begin(), cnt[x].end());
			while(cnt[x].size() > 2){
				cnt[x].pop_back();
			}
		}
	};
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		divide(a[i]);
	}
	i64 g = 1;
	for(int i = 2; i <= 200001; i ++){
		if(!cnt[i].size()){
			continue;
		}
		need[i] = min(2, need[i]);
		while(need[i]){
			cnt[i].push_back(0);
			need[i] --;
		}
		sort(cnt[i].begin(), cnt[i].end());
		g *= qmi(i, cnt[i][1], INFLL);
	}
	cout << g << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}