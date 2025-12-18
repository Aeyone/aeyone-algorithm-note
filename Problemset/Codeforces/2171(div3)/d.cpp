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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	priority_queue<int> heap;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		heap.push(a[i]);
	}
	DSU dsu(n + 1);
	DSU dsu1(n + 1);
	vector<int> stk;
	vector<array<int, 2>> ans;
	for(int i = 0; i < n; i ++){
		while(heap.size() && heap.top() >= a[i]){
			dsu.merge(a[i], heap.top());
			heap.pop();
		}
		while(stk.size() && stk.back() < a[i]){
			dsu.merge(a[i], stk.back());
			dsu1.merge(a[i], stk.back());
			ans.push_back({a[i], stk.back()});
			stk.pop_back();
		}
		stk.push_back(a[i]);
	}
	vector<int> mn(n + 1, INF);
	for(int i = 0; i < n; i ++){
		int f = dsu1.find(a[i]);
		mn[f] = min(mn[f], a[i]);
	}
	vector<int> stk2;
	while(stk.size()){
		int x = stk.back();
		int f = dsu1.find(x);
		while(stk2.size() && mn[f] < stk2.back()){
			ans.push_back({stk2.back(), mn[f]});
			stk2.pop_back();
		}
		stk2.push_back(x);
		stk.pop_back();
	}
	if(dsu.size(1) == n){
		cout << "Yes" << '\n';
		for(auto [x, y] : ans){
			cout << x << ' ' << y << '\n';
		}
	}else{
		cout << "No" << '\n';
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