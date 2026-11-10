#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<class T>
struct SegmentTree {
	struct Info {
		T min = INF;
		friend Info operator+(const Info& l, const Info& r) {
			return {
				std::min(l.min, r.min)
			};
		}
	};
	int n;
	vector<Info> info;

	SegmentTree(int n = 0) { init(n); }

	void init(int n) {
		this->n = n;
		info.assign(n << 2, Info());
	}

	void pushup(int p) {
		info[p] = info[2 * p] + info[2 * p + 1];
	}

	void build(int p, int l, int r, const vector<T>& a) {
		if (l == r) {
			info[p] = {a[l]};
			return;
		}
		int mid = (l + r) / 2;
		build(2 * p, l, mid, a);
		build(2 * p + 1, mid + 1, r, a);
		pushup(p);
	}

	void modify(int p, int l, int r, int x, T val) {
		if (x <= l && r <= x) {
			info[p].min = std::min(info[p].min, val);
			return;
		}
		int mid = (l + r) / 2;
		if (x <= mid) modify(2 * p, l, mid, x, val);
		if (x > mid) modify(2 * p + 1, mid + 1, r, x, val);
		pushup(p);
	}

	Info query(int p, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) {
			return info[p];
		}
		Info res {};
		int mid = (l + r) / 2;
		if (ql <= mid) res = res + query(2 * p, l, mid, ql, qr);
		if (qr > mid) res = res + query(2 * p + 1, mid + 1, r, ql, qr);
		return res;
	}

	void build(const vector<T>& a) { // 1-based
		build(1, 1, n, a);
	}

	void modify(int x, T val) {
		modify(1, 1, n, x, val);
	}

	Info query(int ql, int qr) {
		if (qr < ql) return {INF};
		return query(1, 1, n, ql, qr);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	vector<int> tot;
	for (auto &[l, r] : a) {
		cin >> l >> r;
		tot.push_back(r);
	}
	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());

	int N = tot.size();

	auto idx = [&](int x)-> int {
		return lower_bound(tot.begin(), tot.end(), x) - tot.begin() + 1;
	};

	SegmentTree<int> st(N);
	vector<int> dp(n, INF);
	dp[0] = 1;
	st.modify(idx(a[0][1]), 1ll);

	int pre = idx(a[0][0]);
	for (int i = 1; i < n; i ++) {
		auto [l, r] = a[i];
		dp[i] = min(dp[i], st.query(max(pre, idx(l)), N).min);

		int x = st.query(pre, idx(r) - 1).min + 1;
		st.modify(idx(r), x);
		dp[i] = min(dp[i], x);
		
		pre = max(pre, idx(l));
	}
	cout << dp[n - 1] << '\n';
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