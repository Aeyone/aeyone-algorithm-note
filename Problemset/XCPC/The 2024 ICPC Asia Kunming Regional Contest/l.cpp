#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i ++){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int cnta = count(a.begin(), a.end(), 1);
	int cntb = count(b.begin(), b.end(), 1);
	int atk = (cnta > 0);
	for(int i = cnta; i < n; i ++){
		a[i] --;
		atk ++;
	}
	//如果a数组攻击无法产生爆炸，那么需要贪心的地将b数组中最小的打掉，产生爆炸
	//如果打不掉，则无解
	int bom = 0;
	int p1 = 0, p2 = 0;
	if(cnta == 0){
		if(atk >= b[0]){
			atk -= b[0], b[0] = 0, bom = 1, p2 ++;
		}else{
			cout << "NO" << '\n';
			return;
		}
	}else{
		p1 = cnta;
		bom = cnta;
	}
	while(p1 < n || p2 < m){
		while(p1 < n && a[p1] <= bom){
			a[p1 ++] = 0, bom ++;
		}
		bool ok = false;
		while(p2 < m && b[p2] <= bom){
			b[p2 ++] = 0, bom ++;
			ok = true;
		}
		if(!ok){
			if(p2 < m){
				if(atk >= b[p2] - bom){
					atk -= (b[p2] - bom), b[p2] = 0, bom ++, p2 ++;
				}else{
					cout << "NO" << '\n';
					return;
				}
			}else{
				break;
			}
		}
	}
	if(p2 == m){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
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