#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string a, b;
    if (!(cin >> a >> b)) return;

    int n = a.length();
    int m = b.length();
    int i = 0, j = 0;
    int parts = 0;
    bool possible = true;

    while (i < n && j < m) {
        int curA = a[i] - '0';
        int curB = b[j] - '0';
        int x = i, y = j;
        bool found = false;

        while (x < n && y < m) {
            if (curA == curB) {
                found = true;
                break;
            } else if (curA < curB) {
                x++;
                if (x < n) {
                    curA = (curA + (a[x] - '0')) % 10;
                }
            } else {
                y++;
                if (y < m) {
                    curB = (curB + (b[y] - '0')) % 10;
                }
            }
        }

        if (!found && curA == curB) {
            found = true;
        }

        if (found) {
            parts++;
            i = x + 1;
            j = y + 1;
        } else {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << "\n";
        return;
    }

    // Check remaining characters in a
    if (i < n) {
        int remA = 0;
        for (int k = i; k < n; k++) {
            remA = (remA + (a[k] - '0')) % 10;
        }
        if (remA != 0) {
            cout << -1 << "\n";
            return;
        }
    }

    // Check remaining characters in b
    if (j < m) {
        int remB = 0;
        for (int k = j; k < m; k++) {
            remB = (remB + (b[k] - '0')) % 10;
        }
        if (remB != 0) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << parts << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
