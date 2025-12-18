#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < n; i ++)
		cin >> b[i];

	bool ok = false;
	vector<pii> res;
	while(!ok){
		for(int i = 0; i < n; i ++){
			if(!(a[i] & 1)){
				if(b[i] & 1){
					swap(a[i], b[i]);
					res.push_back({3, i + 1});
					break;
				}else if(i + 1 < n){
					swap(a[i], a[i + 1]);
					res.push_back({1, i + 1});
				}
			}
		}
		for(int i = n - 1; i >= 0; i --){
			if(!(a[i] & 1)){
				if(b[i] & 1){
					swap(a[i], b[i]);
					res.push_back({3, i + 1});
					break;
				}else if(i - 1 >= 0){
					swap(a[i - 1], a[i]);
					res.push_back({1, i});
				}
			}
		}
		bool flag = true;
		for(int i = 0; i < n; i ++)
			flag &= (a[i] & 1);
		ok = flag;
	}
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n - i - 1; j ++){
			if(a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
				res.push_back({1, j + 1});
			}
		}
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n - i - 1; j ++){
			if(b[j] > b[j + 1]){
				swap(b[j], b[j + 1]);
				res.push_back({2, j + 1});
			}
		}
	cout << res.size() << '\n';
	for(auto [x, y] : res)
		cout << x << ' ' << y << '\n';
	// for(auto e : a)
	// 	cout << e << ' ';
	// cout << '\n';
	// for(auto e : b)
	// 	cout << e << ' ';
	// cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}