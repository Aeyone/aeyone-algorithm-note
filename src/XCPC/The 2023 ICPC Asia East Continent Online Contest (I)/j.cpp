#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const double pi = acos(-1);

struct Point{
	double x, y;
};

struct Line {
	Point a, b;
};

double dis(Point a, Point b) { // 两点间距离
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Manhattan(Point a, Point b) { // 两点间距离
	return abs(a.x - b.x) + abs(a.y - b.y);
}	

double Atan2(Line p) { // 返回线段的 arctan 值
	return atan2(p.b.y - p.a.y, p.b.x - p.a.x);
}

void solve() {
	Point a1, a2, b1, b2;
	cin >> a1.x >> a1.y >> a2.x >> a2.y;
	cin >> b1.x >> b1.y >> b2.x >> b2.y;
	Point c1, c2;
	c1.x = (a1.x + a2.x) / 2;
	c1.y = (a1.y + a2.y) / 2;

	c2.x = (b1.x + b2.x) / 2;
	c2.y = (b1.y + b2.y) / 2;

	double r1 = dis(a1, a2) / 2, r2 = dis(b1, b2) / 2;
	double R = dis(c1, c2);

	Line L;
	double k = Atan2(L);
	double l = k + pi / 2, r = k + 3 * pi / 2;
	if (c1.x > c2.x) {
		l = k - pi / 2, r = k + pi / 2;
		L = {c2, c1};
	} else {
		L = {c1, c2};
	}


	auto calc = [&](double beta)-> double {
		Point y = {c2.x + r2 * cos(beta), c2.y + r2 * sin(beta)};
		return Manhattan(c1, y);
	};

	while (r - l >= 1e-8) {
		double m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
		double ans1 = calc(m1), ans2 = calc(m2);
		if (ans1 > ans2) {
			l = m1;
		} else if (ans1 < ans2) {
			r = m2;
		} else {
			l = m1, r = m2;
		}
	}

	cout << calc(l) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}