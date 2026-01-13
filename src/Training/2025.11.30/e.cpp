#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
const double pi = acos(-1);
const double dinf = 1e18, eps = 1e-10;

int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    Point operator+(Point B) { return Point(x + B.x, y + B.y); } // 向量加法
    Point operator-(Point B) { return Point(x - B.x, y - B.y); } // 向量减法
    Point operator*(double k) { return Point(x * k, y * k); }    // 向量乘法
    Point operator/(double k) { return Point(x / k, y / k); }    // 向量除法

    bool operator==(Point B) { return sgn(x - B.x) == 0 && sgn(y - B.y) == 0; } // 判断向量是否相等
};
struct Line {
    Point a, b;
};

double Atan2(Line p) { // 返回线段的 arctan 值
    return atan2(p.b.y - p.a.y, p.b.x - p.a.x);
}
double dis(Point a, Point b) { // 两点间距离的平方
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve() {
	Point s1, t1, s2, t2;
	cin >> s1.x >> s1.y >> t1.x >> t1.y;
	cin >> s2.x >> s2.y >> t2.x >> t2.y;
	Line l1 = {s1, t1}, l2 = {s2, t2};

	double theta1 = Atan2(l1), theta2 = Atan2(l2);
	if(sgn(dis(s1, t1)) == 0){
		theta1 = dinf;
	}
	if(sgn(dis(s2, t2)) == 0){
		theta2 = dinf;
	}
	// cerr << theta1 * 180 / pi << ' ' << theta2 * 180 / pi << '\n';
	double mx1 = sqrt(dis(s1, t1)), mx2 = sqrt(dis(s2, t2));

	auto check = [&](double dist)->double{//返回行动距离为dist时的两点距离
		Point ss1 = s1, ss2 = s2;
		if(theta1 != dinf){
			ss1.x = s1.x + min(mx1, dist) * cos(theta1);
			ss1.y = s1.y + min(mx1, dist) * sin(theta1);
		}
		if(theta2 != dinf){
			ss2.x = s2.x + min(mx2, dist) * cos(theta2);
			ss2.y = s2.y + min(mx2, dist) * sin(theta2);
		}
		return dis(ss1, ss2);
	};

	double l = 0, r = min(mx1, mx2);
	while(r - l > 1e-10){
		double m1 = l + (r - l) / 3, m2 = l + 2.0 * (r - l) / 3;
		double ans1 = check(m1), ans2 = check(m2);
		if(ans1 > ans2){
			l = m1;
		}else if(ans1 < ans2){
			r = m2;
		}else{
			l = m1, r = m2;
		}
	}
	double ans = sqrt(check(l));
 	l = min(mx1, mx2), r = max(mx1, mx2);
	while(r - l > 1e-10){
		double m1 = l + (r - l) / 3, m2 = l + 2.0 * (r - l) / 3;
		double ans1 = check(m1), ans2 = check(m2);
		if(ans1 > ans2){
			l = m1;
		}else if(ans1 < ans2){
			r = m2;
		}else{
			l = m1, r = m2;
		}
	}
	cout << min(ans, sqrt(check(l))) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}