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

struct Hash {
	static const u64 P = 131;
	int n;
	vector<u64> h, p; // h[i]存储字符串前i个字母的哈希值, p[i]存储 P^i mod 2^64
	string s;

	Hash () {};
	Hash (int n, string &s) {
		init(n, s);
	}

	void init (int n, string &s) {
		this->n = n, this->s = s;
		h.assign(n + 1, 0);
		p.assign(201, 0);
		p[0] = 1;
		for (int i = 1; i <= 200; i ++) {
			p[i] = p[i - 1] * P;
		}
		for (int i = 1; i <= n; i ++) {
			h[i] = h[i - 1] * P + (s[i]);
		}
	}
	
	// 计算子串 str[l ~ r] 的哈希值
	u64 get (int l, int r) {
		return h[r] - h[l - 1] * p[r - l + 1];
	}
};
const int M = 5000;

u64 g[M][M], gg[26][M];

void solve() {
	string s, t;
	cin >> s >> t;
	int n = t.size(), m = s.size();
	s = " " + s;
	t = " " + t;
	Hash h(n, t);

	unordered_map<u64, int> mp, siz;
	mp[0] = 1;
	siz[0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			siz[h.get(i, j)] = j - i + 1;
			mp[h.get(i, j)] = 0;
		}
	}

	int N = mp.size();
	vector<u64> tot;
	for (auto &[s, id] : mp) {
		tot.push_back(s);
	}
	sort(tot.begin(), tot.end());
	for (int i = 0; i < N; i ++) {
		mp[tot[i]] = i;
	}

	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			u64 s1 = tot[i], s2 = tot[j];
			int len1 = siz[s1], len2 = siz[s2];

			u64 str = s1 * h.p[len2] + s2;
			if (mp.find(str) != mp.end()) {
				int idx = mp[str];
				g[i][j] = idx;
			} else {
				g[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < 26; i ++) {
		char c = 'a' + i;
		for (int j = 0; j < N; j ++) {
			u64 str = tot[j] * h.P + c;
			if (mp.find(str) != mp.end()) {
				int idx = mp[str];
				gg[i][j] = idx;
			} else {
				gg[i][j] = 0;
			}
		}
	}

	vector<int> la(N);
	la[0] = 1;
	for (int i = 1; i <= m; i ++) {
		vector<int> cur(N);
		cur[0] = 1;
		for (int j = 0; j < N; j ++) {
			for (int k = 0; k < N; k ++) {
				int idx1 = g[j][k];
				int merid = gg[s[i] - 'a'][j];
				int idx2 = (merid == 0 ? 0 : g[merid][k]);
				if (idx1) {
					cur[idx1] = (cur[idx1] + la[j] * la[k] % MOD) % MOD;
				}
				if (idx2) {
					cur[idx2] = (cur[idx2] + la[j] * la[k] % MOD) % MOD;
				}
			}
		}
		la = cur;
	}
	cout << la[mp[h.get(1, n)]] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}
