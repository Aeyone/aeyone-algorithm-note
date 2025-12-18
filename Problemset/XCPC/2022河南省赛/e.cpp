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
	string s;
	cin >> s;
	vector<array<int, 26>> pre(n + 1);
	s = "x" + s;
	for(int i = 1; i <= n; i ++){
		pre[i] = pre[i - 1];
		pre[i][s[i] - 'a'] ++;
	}
	int l = -1;
	char L = '#';
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < 26; j ++){
			if(pre[i][j] == 5){
				l = i, L = 'a' + j;
				break;
			}
		}
		if(l != -1){
			break;
		}
	}
	int r = -1;
	char R = '#';
	for(int i = n; i >= 2; i --){
		for(int j = 0; j < 26; j ++){
			if(pre[n][j] - pre[i][j] == 5){
				r = i, R = 'a' + j;
				break;
			}
		}
		if(r != -1){
			break;
		}
	}
	char mid = '#';
	if(l < r){
		for(int i = 0; i < 26; i ++){
			if(pre[r][i] - pre[l][i] >= 7){
				mid = 'a' + i;
				break;
			}
		}
	}
	if(l >= r || mid == '#' || L == '#' || R == '#'){
		cout << "none" << '\n';
		return;
	}
	cout << string(5, L) + string(7, mid) + string(5, R) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}