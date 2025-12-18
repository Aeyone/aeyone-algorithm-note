#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {//可用于清空树状数组，并重新定义大小
        n = n_;
        a.assign(n + 1, T{});//下标为从1开始，需要初始化大小为n + 1
    }

    void add(int x, const T &v) {//单点修改(下标为从1开始)
        while(x <= n)
            a[x] += v, x += x & -x;
    }
    
    T sum(int x) {//查询1~x的和(下标为从1开始)
        T ans{};
        while(x > 0)
            ans += a[x], x -= x & -x;
        return ans;
    }
};

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		a[i] = (s[i] == '1');
	}
	int ans = 1;
	for(int len = n; len >= 1; len --){
		Fenwick<int> fw(n + 1);
		for(int i = 0; i <= n - len; i ++){
			if((a[i] + fw.sum(i + 1)) % 2 == 0){
				fw.add(i + 1, 1), fw.add(i + len + 1, -1);
			}
		}
		bool ok = true;
		for(int i = n - len + 1; i < n; i ++){
			ok &= ((a[i] + fw.sum(i + 1)) & 1);
		}
		if(ok){
			ans = len;
			break;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}