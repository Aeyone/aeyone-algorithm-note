#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 5e5 + 10;
vector<int> temp;

i64 merge_sort(vector<int> &q, int l, int r){
    if (l >= r)
        return 0;

    int mid = (l + r) >> 1;
    i64 res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else {
            temp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = q[i++];
    while (j <= r)
        temp[k++] = q[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        q[i] = temp[k];

    return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto &e : a)
		cin >> e;
	for(auto &e : b)
		cin >> e;
	temp.assign(n + 1, 0);
	int ca = merge_sort(a, 0, n - 1) & 1;
	temp.assign(n + 1, 0);
	int cb = merge_sort(b, 0, n - 1) & 1;
	if(ca ^ cb == 1)
		cout << "A";
	else
		cout << "B";

	for(int i = 0; i < n - 1; i ++){
		char sign;
		cin >> sign;
		int l, r, d;
		cin >> l >> r >> d;
		int tmp = ((i64)(r - l) * d) & 1;
		if(sign == 'A')
			ca ^= tmp;
		else
			cb ^= tmp;
		
		if(ca ^ cb == 1)
			cout << "A";
		else
			cout << "B";
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}