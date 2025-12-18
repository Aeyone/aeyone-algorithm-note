#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 1e5 + 10;
int son[N][26];
i64 cnt[N];
int idx;

void insert(string str){
    int p = 0;
    for(int i = 0; i < str.size(); i ++){
        int u = str[i] - 'a';
        if(!son[p][u]){
            son[p][u] = ++ idx;
        }//如果没有路 则开辟一条路，idx记录当前数据下标
        p = son[p][u]; //一定是在有路的前提下，进入下一条路
        cnt[p] ++;
    }
}

i64 query(string str){
    int p = 0;
    i64 res = 0;
    for(int i = 0; i < str.size(); i ++){
        int u = str[i] - 'a';
        if(!son[p][u]){
            return res;
        }
        p = son[p][u];
        res += cnt[p];
    }
    return res;
}

void solve() {
	int n;
	cin >> n;
	vector<string> g(2 * n);
	for(int i = 0; i < 2 * n; i ++){
		cin >> g[i];
	}
	sort(g.begin(), g.end());
	vector<string> a, b;
	for(int i = 0; i < 2 * n; i ++){
		if(i & 1){
			a.push_back(g[i]);
		}else{
			b.push_back(g[i]);
		}
	}
	for(int i = 0; i < n; i ++){
		insert(b[i]);
	}
	i64 ans = 0;
	for(int i = 0; i < n; i ++){
		ans += query(a[i]);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}