#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans;

    ans += string(n, 'D');

    for (int i = 0; i < n; i++) {
        ans += "URDDRD";
    }

    for (int i = 0; i < n; i++) {
        ans += "ULDDLD";
    }

    cout << ans.size() << '\n';
    cout << ans << '\n';

    return 0;
}