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
	string s1 = s.substr(0, n - 2), s2 = s.substr(2, n - 2);
	if(s.back() == '1'){
		s1.back() = (s1.back() == '1' ? '0' : '1');
	}
	reverse(s1.begin(), s1.end());
	while(s1.size() > 1 && s1.back() == '0'){
		s1.pop_back();
	}
	reverse(s1.begin(), s1.end());

	if(s.front() == '1'){
		s2.back() = (s2.back() == '1' ? '0' : '1');
	}
	reverse(s2.begin(), s2.end());
	while(s2.size() > 1 && s2.back() == '0'){
		s2.pop_back();
	}
	if(s[0] == '0' && s[1] == '1' && s2.size() >= s1.size()){
		int cur = 2, idx = 0, mx = -1;
		while(cur < n - 1 && s[cur] == '0' && idx < s2.size()){
			if(s2[idx] == '0'){
				mx = idx;
			}
			idx ++, cur ++;
		}
		if(mx != -1){
            s2[mx] = '1';
        }
	}
	reverse(s2.begin(), s2.end());
	// cout << "s1 = " << s1 << '\n';
	// cout << "s2 = " << s2 << '\n';
	if(s1.size() == s2.size()){
		cout << max(s1, s2) << '\n';
	}else{
		cout << (s1.size() > s2.size() ? s1 : s2) << '\n';
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