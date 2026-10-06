#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long

signed main(int argc, char *argv[]) {
    int id = argc > 1 ? atoi(argv[1]) : 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
    	cin >> a[i];
    }
    int N;
    cin >> N;

    auto check = [&](int x)-> int {
    	cout << "? " << x << endl;
    	cout.flush();
    	char op;
		cin >> op;
		int xx;
		cin >> xx;
    	cout << upper_bound(a.begin(), a.end(), x) - a.begin() << endl;
    	cout.flush();
    	int cnt;
    	cin >> cnt;
    	return cnt;
    };

    if (id == 0) {
    	int l = LLONG_MIN, r = LLONG_MAX;
    	int ans = 0;
    	while (l <= r) {
    		int mid = (i128(l) + i128(r)) / 2;
    		if (check(mid) >= (N + 1) / 2) {
    			ans = mid, r = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}
    	cout << "! " << ans << endl;
    	cout.flush();
    	char op;
		cin >> op;
		int xx;
		cin >> xx;
    	cout << ans << endl;
    	cout.flush();
    } else {
    	while (1) {
    		char op;
    		cin >> op;
    		int x;
    		cin >> x;
    		if (op == '?') {
    			cout << upper_bound(a.begin(), a.end(), x) - a.begin() << endl;
    			cout.flush();
    		} else {
    			cout << x << endl;
    			cout.flush();
    			break;
    		}
    	}
    }
    return 0;
}