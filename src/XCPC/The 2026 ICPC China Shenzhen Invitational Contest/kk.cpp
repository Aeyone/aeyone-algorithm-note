#include <bits/stdc++.h>
#define MOD 998244353
typedef long long LL;
using namespace std;

void dfs(int idx, LL d, LL phi_nd, LL g_d, LL m, LL &ans, const vector<pair<LL, int>> &fac)
{
	if (idx == fac.size())
	{
		ans = (ans + (d % MOD) * (phi_nd % MOD) % MOD * ((m / g_d + 1) % MOD)) % MOD;
		return;
	}
	LL p = fac[idx].first;
	int a = fac[idx].second;
	LL cur_p = 1, cur_g = 1;
	for (int i = 0; i <= a; ++i)
	{
		LL phi_f = 1;
		if (a - i > 0)
		{
			LL pw = 1;
			for (int j = 0; j < a - i - 1; ++j)
				pw *= p;
			phi_f = pw * (p - 1);
		}
		dfs(idx + 1, d * cur_p, phi_nd * phi_f, g_d * cur_g, m, ans, fac);
		if (i < a)
		{
			cur_p *= p;
			if ((i + 1) % 2 != 0)
				cur_g *= p;
		}
	}
}
LL t, n, m;
int main()
{
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &m);
		vector<pair<LL, int>> fac;
		LL tmp = n;
		for (LL i = 2; i * i <= tmp; ++i)
			if (tmp % i == 0)
			{
				int cnt = 0;
				while (tmp % i == 0)
					cnt++, tmp /= i;
				fac.push_back({i, cnt});
			}
		if (tmp > 1)
			fac.push_back({tmp, 1});
		LL ans = 0;
		dfs(0, 1, 1, 1, m, ans, fac);
		printf("%lld\n", ans);
	}
	return 0;
}