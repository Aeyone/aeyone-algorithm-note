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
	string s;
	cin >> s;
	int n = s.size();
	if(n == 1){
		cout << 1 << '\n';
		return;
	}
	bool ok = false;
	for(int i = 0; i < n - 1; i ++){
		string str = s.substr(i, 2);
		ok |= (str == "*<" || str == ">*" || str == "><" || str == "**");
	}
	if(ok){
		cout << -1 << '\n';
		return;
	}
	vector<int> v;
	int add = 0;
	for(int l = 0, r = 0; l < n; l = r){
		while(r < n && s[r] == s[l]){
			r ++;
		}
		if(s[l] != '*'){
			v.push_back(r - l);
		}else{
			add = r - l;
		}
	}
	cout << *max_element(v.begin(), v.end()) + add << '\n';;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}