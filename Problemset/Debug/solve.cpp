#include <bits/stdc++.h>

#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define sort_all(x) sort(all(x))
#define sort1_all(x) sort(all1(x))
#define reverse_all(x) reverse(all(x))
#define reverse1_all(x) reverse(all1(x))

#define setp(x) fixed<<setprecision(x)

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<vi> vvi;
typedef vector<vl> vvl;


static mt19937_64 rng (
    chrono::steady_clock::now ().time_since_epoch ().count ()
);

#define randInt(l, r) ( uniform_int_distribution<int>((l),(r))(rng) )//int类型
#define randll(l, r) ( uniform_int_distribution<ll>((l),(r))(rng) )//ll类型



template <typename T>
inline T read () {
    T x = 0;
    int y = 1;
    char ch = getchar ();
    while (ch > '9' || ch < '0') {
        if (ch == '-')
            y = -1;
        ch = getchar ();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar ();
    }
    return x * y;
}

template <typename T>
inline void write (T x) {
    if (x < 0) {
        putchar ('-');
        x = -x;
    }
    if (x >= 10) {
        write (x / 10);
    }
    putchar (x % 10 + '0');
}

/*#####################################BEGIN#####################################*/
bool test = 0;


const ll mod = 998244353;

const int N = 64;

ll c[N][N];

void init () {
    // c[a][b] 表示从a个苹果中选b个的方案数
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;

        }
    }
}


void solve () {
    ll n, k;
    cin >> n >> k;

    if (n < (1ll << k)) {
        cout << 0 << "\n";
        return;
    }


    bitset<64> a (n);

    ll cnt_sum = 0, t = k;
    for (ll cur = 0, i = 63;i >= 0;i--) {
        //剩下的只能全部填1或0
        if (t == 0) {
            cnt_sum = (cnt_sum + 1) % mod;
            break;
        }
        if (t == i + 1) {
            cur += (1ll << t) - 1;
            if (cur <= n)cnt_sum = (cnt_sum + 1) % mod;
            break;
        }
        if (a[i]) {
            //设当前位为0,则后续所有值都会比它小
            cnt_sum = (cnt_sum + c[i][t]) % mod;
            //设当前位为1，消耗掉一个k
            cur += (1ll << i);
            t--;
        }
    }

    //135030899
    //135030900

    ll ans = 0, ans2 = 0;
    for (ll cur = 0, i = 63;i >= 0;i--) {
        //剩下全部填1或0
        if (k == 0) {
            break;
        }
        if (k == i + 1) {
            cur += (1ll << t) - 1;
            if (cur <= n)ans = (ans + (1ll << k) - 1) % mod;
            break;
        }
        if (a[i]) {
            //设当前位为0,则后续所有值都会比它小
            if (i > 0 && k > 0) {
                ans = (ans + ((1ll << i) - 1) * c[i - 1][k - 1] % mod) % mod;
            }

            //设当前位为1，消耗掉一个k
            cur += 1ll << i;
            cnt_sum = (cnt_sum + mod - c[i][k]) % mod;
            ans = (ans + (1ll << i) * cnt_sum) % mod;

            k--;
        }
    }

    cout << ans << "\n";



}



int main () {
    ios::sync_with_stdio (false), std::cin.tie (0), std::cout.tie (0);
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    int _ = 1;
    if (test)cin >> _;
    init ();
    while (_--) {
        solve ();
    }
    return 0;
}

/*######################################END######################################*/

// 链接：ds