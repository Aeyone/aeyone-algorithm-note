#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct DSU {
	vector<int> f, siz;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool cmp(int x, int y) {
		return find(x) == find(y);
	}
	
	bool merge(int x, int y) {//将y合并至x中
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	
	int size(int x) {
		return siz[find(x)];
	}
};

int main(int argc, char *argv[]) {
    int id = argc > 1 ? atoi(argv[1]) : 0;
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> edge(m);
    for (auto &[u, v] : edge) {
    	cin >> u >> v;
    }

    cout << m << endl;
	for (auto [u, v] : edge) {
    	cout << u << ' ' << v << endl;
    }

    if (id != 0) {
    	int x;
    	cin >> x;
    	cout << x << endl;
    } else {
    	DSU d(n + 1);
    	for (int k = 1; k <= 3; k ++) {
	    	int m1;
	    	cin >> m1;
	    	for (int i = 0; i < m1; i ++) {
	    		int u, v;
	    		cin >> u >> v;
		    	edge.push_back({u, v});
	    	}
    	}
    	for (auto [u, v] : edge) {
    		d.merge(u, v);
    	}
    	int cnt = 0;
    	for (int i = 1; i <= n; i ++) {
    		cnt += (d.find(i) == i);
    	}
    	cout << cnt << endl;
    }
    return 0;
}

