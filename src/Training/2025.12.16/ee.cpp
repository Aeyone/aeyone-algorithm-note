#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = (i128)a * a % p) if(b & 1){
		res = (i128)a * res % p;
	}
	return res;
}

template<class T>
struct Frac {
    T num;
    T den;
    Frac(T num_, T den_) : num(num_), den(den_) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num_) : Frac(num_, 1) {}
    explicit operator double() const {
        return 1. * num / den;
    }
    Frac &operator+=(const Frac &rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator-=(const Frac &rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator*=(const Frac &rhs) {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac &operator/=(const Frac &rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac &rhs) {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac &rhs) {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac &rhs) {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac &rhs) {
        return lhs /= rhs;
    }
    friend Frac operator-(const Frac &a) {
        return Frac(-a.num, a.den);
    }
    friend bool operator==(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator!=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator<(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator>(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator<=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator>=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
    friend std::ostream &operator<<(std::ostream &os, Frac x) {
        T g = std::gcd(x.num, x.den);
        if (x.den == g) {
            return os << x.num / g;
        } else {
            return os << x.num / g << "/" << x.den / g;
        }
    }
};

void solve() {
	int n, c;
	cin >> n >> c;
	c --;
	i64 sum = 0;
	vector<i64> a(n), u(n), idx(n);
	iota(u.begin(), u.end(), 0);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	a[c] ++;
	sort(u.begin(), u.end(), [&](const int &x, const int &y)->bool{
		return (a[x] > a[y]);
	});
	for (int i = 0; i < n; i ++) {
		idx[u[i]] = i;
	}
	vector<vector<Frac<i64>>> p(2, vector<Frac<i64>>(n, Frac<i64>(0, 1)));
	p[1][idx[c]] = Frac<i64>(1, 1);
	for (int cnt = 1; cnt <= 100; cnt ++) {
		p[cnt & 1 ^ 1].assign(n, Frac<i64>(0, 1));
    	Frac<i64> ans(0, 1);
		for (int i = 0; i < n; i ++) {
			ans += cnt * p[cnt & 1][i] * Frac<i64>(a[u[i]] - 1, sum);
			i64 tot = 0;
			for (int j = 0; a[u[j]] > a[u[i]]; j ++) {
				tot += a[u[j]];
				p[cnt & 1 ^ 1][j] += p[cnt & 1][i] * Frac<i64>(a[u[j]], sum);
			}
			p[cnt & 1 ^ 1][i] += p[cnt & 1][i] * Frac<i64>(sum - tot, sum);
		}
		cerr << "ans = " << ans << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}