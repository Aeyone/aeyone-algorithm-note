#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int a, b;
	cin >> a >> b;
	int c = b - a;
	cout << c << '\n';
	if (c <= 0) {
		cout << "hai sheng ma?" << '\n';
	} else if (c <= 250) {
		cout << "nin tai cong ming le!" << '\n';
	} else {
		cout << "jiu ting tu ran de..." << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}