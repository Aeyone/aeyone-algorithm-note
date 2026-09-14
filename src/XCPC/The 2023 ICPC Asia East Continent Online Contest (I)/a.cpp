#include <bits/stdc++.h>

#define ft first
#define sd second

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define sort_all(x) sort(all(x))
#define sort_all1(x) sort(all1(x))
#define reverse_all(x) reverse(all(x))
#define reverse_all1(x) reverse(all1(x))

#define setp(x) fixed << setprecision(x)

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

static mt19937_64 rng (chrono::steady_clock::now ().time_since_epoch ().count ());
#define randInt(l, r) (uniform_int_distribution<int>((l),(r))(rng))

/*#####################################BEGIN#####################################*/

const int mod = 1e9 + 7;
bool test = 0;

void init () {}

struct sc {
    string s;
    int a;
    int b;
    int c;
};

bool cmp (sc s1, sc s2) {
    if (s1.c == s2.c)return s1.a < s2.a;
    return s1.c < s2.c;
}


void solve () {
    int n, m;
    cin >> n >> m;
    map<string, int>mp1, mp2;
    vector<string>v;
    for (int i = 1, cur = 1;i <= n;i++) {
        string s;
        cin >> s;
        v.pb (s);
        if (mp1.find (s) == mp1.end ())mp1[s] = cur++;
    }

    for (int i = 1, cur = 1;i <= m;i++) {
        string s;
        cin >> s;
        v.pb (s);
        if (mp2.find (s) == mp2.end ())mp2[s] = cur++;
    }
    sort (all (v));
    unq_all (v);
    vector<sc>ans (v.size ());

    for (int i = 0;i < v.size ();i++) {
        string s = v[i];
        int a = mp1[s];if (a == 0)a = inf;
        int b = mp2[s];if (b == 0)b = inf;
        int c = min (a, b);
        ans[i] = { s,a,b,c };
    }

    sort (all (ans), cmp);

    for (int i = 0;i < ans.size ();i++) {
        cout << ans[i].s << "\n";
    }

}

signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int _ = 1;
    if (test) cin >> _;

    init ();
    while (_--) {
        solve ();
    }

    return 0;
}

/*######################################END######################################*/