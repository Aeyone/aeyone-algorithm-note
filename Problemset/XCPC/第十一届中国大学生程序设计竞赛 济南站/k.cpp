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
	int n;
	cin >> n;
	vector<int> a(n), cnt(n + 1);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	vector<int> tot1, tot2;
	for(int i = 1; i <= n; i ++){
		if(cnt[i] == 0){
			tot2.push_back(i);
		}
	}

	int ans = 0;
	if(cnt[a[0]] == 2){
		ans ++;
		cnt[a[0]] -= 2;
	}else{
		tot1.push_back(a[0]);
	}
	vector<int> b(n), vis(n + 1);
	for(int i = 1; i < n; i ++){
		if(cnt[a[i]] == 2){
			if(!vis[a[i]]){
				vis[a[i]] = tot2.back();
				tot2.pop_back();
			}
			b[i - 1] = vis[a[i]];
		}
		if(cnt[a[i]] == 1){
			if(tot1.size()){
				b[i - 1] = tot1.back();
				tot1.pop_back();
			}
			tot1.push_back(a[i]);
		}
	}
	if(tot1.size()){
		b[n - 1] = tot1.back();
		tot1.pop_back();
	}

	for(int i = 0; i < n; i ++){
		if(b[i] != 0){
			continue;
		}
		if(tot2.size()){
			b[i] = tot2.back();
			tot1.push_back(b[i]);
			tot2.pop_back();
		}else{
			b[i] = tot1.back();
			tot1.pop_back();
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i ++){
		cout << b[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}