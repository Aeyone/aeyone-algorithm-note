#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int q;
	cin >> q;
	const int N = 5e5 + 10;
	vector<vector<int>> son1(N, vector<int>(26, -1)), son2(N, vector<int>(26, -1));
	vector<int> cnt1(N), cnt2(N);
	int idx1 = 1, idx2 = 1;
	auto insert1 = [&](string &x)->void{ //X中插入x
		int p = 0;
		for(auto e : x) {
			int u = e - 'a';
			if(son1[p][u] == -1) {
				son1[p][u] = idx1 ++;
			}
			p = son1[p][u];
		}
		cnt1[p] ++;
	};
	auto query1 = [&](string &y)->bool{ //X中查询y
		int p = 0;
		for(auto e : y) {
			int u = e - 'a';
			if(son1[p][u] == -1) {
				return false;
			}
			p = son1[p][u];
			if(cnt1[p] > 0) {
				return true;
			}
		}
		return false;
	};
	auto insert2 = [&](string &y)->void{ //Y中插入y
		int p = 0;
		for(auto e : y) {
			int u = e - 'a';
			if(son2[p][u] == -1) {
				son2[p][u] = idx2 ++;
			}
			p = son2[p][u];
			cnt2[p] ++;
		}
	};
	auto query2 = [&](string &x)->int{ //Y中查询x
		int p = 0;
		for(auto e : x) {
			int u = e - 'a';
			if(son2[p][u] == -1) {
				return 0;
			}
			p = son2[p][u];
		}
		for(int i = 0; i < 26; i ++) { //任何以该x为前缀的路径都应该去掉
			son2[p][i] = -1;
		}
		int res = cnt2[p];
		p = 0;
		for(auto e : x) {
			int u = e - 'a';
			p = son2[p][u];
			cnt2[p] -= res;
		}
		return res;
	};

	int cur = 0;
	while(q --) {
		int t;
		string s;
		cin >> t >> s;
		if(t == 1) {
			insert1(s);
			cur -= query2(s);
		}else{
			if(!query1(s)) {//如果y的某个前缀出现在X中过 就不插入
				insert2(s);
				cur ++;
			}
		}
		cout << cur << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}