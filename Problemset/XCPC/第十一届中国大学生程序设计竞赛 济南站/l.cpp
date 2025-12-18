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
	int n, m;
	cin >> n >> m;
	vector<int> a(2 * n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<int> f(2 * n, -1);
	int idx = n;
	for(int i = 0; i < 2 * n; i ++){
		if(f[i ^ 1] == -1){
			a[idx] = max(a[i], a[i ^ 1]);
			f[i] = idx ++;
		}else{
			f[i] = f[i ^ 1];
		}
		// for(int i = 0; i < 2 * n - 1; i ++){
		// 	cout << a[i] << ' ';
		// }
		// cout << '\n';
	}
	Fenwick<int> fw(n + 1);
	for(int i = n; i < 2 * n; i ++){
		fw.add(i - n + 1, a[i]);
	}
	while(m --){
		char c;
		cin >> c;
		if(c == 'A'){
			int l, r;
			cin >> l >> r;
			cout << fw.sum(r) - fw.sum(l - 1) << '\n';
		}
		if(c == 'C'){
			int x, y;
			cin >> x >> y;
			x --, y --;
			swap(a[x], a[y]);
			while(f[x] != 2 * n - 1){
				int d = max(a[x], a[x ^ 1]) - a[f[x]];
				fw.add(f[x] - n + 1, d); 
				a[f[x]] += d;
				x = f[x];
			}
			while(f[y] != 2 * n - 1){
				int d = max(a[y], a[y ^ 1]) - a[f[y]];
				fw.add(f[y] - n + 1, d);
				a[f[y]] += d;
				y = f[y];
			}
		}
		cout << "a: ";
		for(int i = 0; i < 2 * n - 1; i ++){
			cout << a[i] << ' ';
		}
		cout << '\n';
		for(int i = 1; i < n; i ++){
			cout << fw.sum(i) - fw.sum(i - 1) << ' ';
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}