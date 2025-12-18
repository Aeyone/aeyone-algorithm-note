#include <bits/stdc++.h>
#define int long long
#define ll long long
#define debug(x) cerr << #x << "=" << x << "\n"
#define debug2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define all(v) v.begin(), v.end()
#define all1(v) v.begin() + 1, v.end()

using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (!n)
    {
        cout << "x\n";
        return;
    }
    string s;
    vector<int> cnt(35);
    cnt[1] = n;
    for(int i = 2; i < 32; i ++){
        cnt[i] = cnt[i - 1] / ((1ll << i) - 1) * ((1ll << (i - 1)) - 1);
        cnt[i - 1] -= cnt[i] / ((1ll << (i - 1)) - 1) * ((1ll << i) - 1);
    }
    int ans = 0;
    for (int i = 1; i < 32; i++)
    {   
        s += 'a';
        for (int j = 0; j < cnt[i]; j++){
            s += "h";
        }
    }
    while(s.back() == 'a'){
        s.pop_back();
    }
    s += "ehhehnun";
    reverse(all(s));
    cout << s << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(10);
    int _ = 1;
    cin >> _ ;
    while (_--)
        solve();
    return 0;
}