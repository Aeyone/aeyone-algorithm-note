#include <bits/stdc++.h>

#define endl '\n'

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
typedef pair<ll, int> pli;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pli> vpli;
typedef vector<pss> vpss;
typedef vector<ti3> vti3;
typedef vector<tl3> vtl3;
typedef vector<tld3> vtld3;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pll> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpll;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<ll, ll> mll;
typedef map<ll, bool> mlb;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<char, bool> mcb;
typedef map<string, int> msi;
typedef map<string, ll> msl;
typedef map<int, bool> mib;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

std::mt19937_64 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

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
bool test = 1;

void init () {}
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


void solve () {
    int n, m;
    cin >> n >> m;
    vs g (n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    vvi vis (n, vi (m, 0));
    vpii a, b;
    queue<pii> q;
    q.push ({ 0, 0 });
    vis[0][0] = true;
    while (!q.empty ()) {
        auto [x, y] = q.front ();
        q.pop ();
        bool ok = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#' || vis[nx][ny])continue;
            q.push ({ nx, ny });
            vis[nx][ny] = true;
            ok = false;
        }
        if(ok){
            a.pb ({ x, y });
        }
    }
    if (vis[n - 1][m - 1]) {
        cout << 0 << endl;
        return;
    }

    q.push ({ n - 1,m - 1 });
    vis[n - 1][m - 1] = true;
    while (!q.empty ()) {
        auto [x, y] = q.front ();
        q.pop ();
        bool ok = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#' || vis[nx][ny])continue;
            q.push ({ nx, ny });
            vis[nx][ny] = true;
            ok = false;
        }
        if(ok){
            b.pb ({ x, y });
        }
    }
    // cout << a.size() << ' ' << b.size() << '\n';
    int ans = inf;
    for (int i = 0;i < a.size ();i++) {
        for (int j = 0;j < b.size ();j++) {
            ans = min (ans, abs (a[i].ft - b[j].ft) + abs (a[i].sd - b[j].sd));
        }
    }
    cout << ans - 1 << endl;





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
// 链接：