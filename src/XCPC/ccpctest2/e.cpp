#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

int main(int argc, char *argv[]) {
    int id = argc > 1 ? atoi(argv[1]) : 0;
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto &e : a) cin >> e;
    sort(a.begin(), a.end());

    if (id == 0) {
    	cout << n << endl;
    	for (auto e : a) cout << e << ' ';
		cout << endl;
		int x;
		cin >> x;
		cout << x << endl;
    } else {
    	int n1;
    	cin >> n1;
    	vector<i64> b(n1);
    	for (auto &e : b) cin >> e;

    	bool ok = true;
    	for (int i = 0; i < n; i ++) {
    		ok &= (a[i] == b[i]);
    	}
    	cout << ok << endl;
    }

    return 0;
}
