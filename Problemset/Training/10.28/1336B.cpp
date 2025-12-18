#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//比较有趣的数学题
	int nr, ng, nb;
	cin >> nr >> ng >> nb;
	vector<int> r(nr), g(ng), b(nb);
	for(auto &e : r){
		cin >> e;
	}
	for(auto &e : g){
		cin >> e;
	}
	for(auto &e : b){
		cin >> e;
	}
	sort(r.begin(), r.end());
	sort(g.begin(), g.end());
	sort(b.begin(), b.end());

	auto find = [&](vector<int> &a, vector<int> &b, int x)->array<int, 2>{
		int p = -1, q = -1;
		auto it1 = lower_bound(a.begin(), a.end(), x);
		auto it2 = upper_bound(b.begin(), b.end(), x);
		if(it1 != a.end()){
			p = *it1;
		}
		if(it2 != b.begin()){
			q = *(-- it2);
		}
		return {p, q};
	};

	auto getAns = [&](i64 x, i64 y, i64 z)->i64{
		i64 a = (x - y);
		i64 b = (y - z);
		i64 c = (z - x);
		return (a * a + b * b + c * c);
	};
	i64 ans = INFLL;
	auto work = [&](vector<int> &arr, vector<int> &a, vector<int> &b)->void{
		for(int i = 0; i < arr.size(); i ++){
			auto [x1, y1] = find(a, b, arr[i]);
			auto [x2, y2] = find(b, a, arr[i]);
			if(x1 != -1 && y1 != -1){
				ans = min(ans, getAns(arr[i], x1, y1));
			}
			if(x2 != -1 && y2 != -1){
				ans = min(ans, getAns(arr[i], x2, y2));
			}
		}
	};
	work(r, g, b);
	work(g, r, b);
	work(b, r, g);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}