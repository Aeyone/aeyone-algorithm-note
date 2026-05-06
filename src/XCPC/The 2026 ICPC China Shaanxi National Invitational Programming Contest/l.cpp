#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    string ans = "";
    
    // 1. 先贴到最右侧
    for (int i = 0; i < n; ++i) {
        ans += "R";
    }
    
    // 2. 来回进行对角线扫描
    bool go_left = true;
    // 每次扫描需要 2n 步 (n次 D + L 或 D + R)
    // 保证总长度不超过 30n
    while (ans.length() + 2 * n <= 30 * n) {
        for (int i = 0; i < n; ++i) {
            ans += "D";
            if (go_left) {
                ans += "L";
            } else {
                ans += "R";
            }
        }
        go_left = !go_left; // 翻转方向
    }
    
    // 输出总移动次数及操作序列
    cout << ans.length() << endl;
    cout << ans << endl;
    
    return 0;
}