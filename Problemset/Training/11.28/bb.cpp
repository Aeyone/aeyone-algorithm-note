#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <climits>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    
    vector<vector<vector<int>>> dp(h, vector<vector<int>>(w, vector<int>(4, INT_MAX)));
    deque<tuple<int, int, int, int>> dq;
    dq.push_back({0, 0, -1, 1});
    int cnt = 0;
    while (!dq.empty()) {
    	cnt ++;
        auto [c, pre_x, pre_y, dir] = dq.front();
        dq.pop_front();
        
        int x = pre_x + dx[dir];
        int y = pre_y + dy[dir];
        if (!(0 <= x && x < h && 0 <= y && y < w)) {
            continue;
        }
        
        for (int ndir = 0; ndir < 4; ndir++) {
            if ((dir ^ ndir) == 2) {
                continue;
            }
            
            int cost;
            if (s[x][y] == 'A' && (dir ^ ndir) == 0) {
                cost = 0;
            } else if (s[x][y] == 'B' && (dir ^ ndir) == 1) {
                cost = 0;
            } else if (s[x][y] == 'C' && (dir ^ ndir) == 3) {
                cost = 0;
            } else {
                cost = 1;
            }
            
            if (c + cost < dp[x][y][ndir]) {
                dp[x][y][ndir] = c + cost;
                if (cost == 0) {
                    dq.push_front({dp[x][y][ndir], x, y, ndir});
                } else {
                    dq.push_back({dp[x][y][ndir], x, y, ndir});
                }
            }
        }
    }
    cout << "cnt = " << cnt << '\n';
    cout << dp[h - 1][w - 1][1] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}