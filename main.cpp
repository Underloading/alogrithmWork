#include <bits/stdc++.h>
const int MAXN = 1e4 + 5;
int n, arr[MAXN];
#define LL long long
#define mod %
#include "turing.h"
#include "recursive.h"
#include "functionStack.h"

using namespace std;

inline int find (int l, int r, int x) {
    int mid = (l + r) >> 1;
    if (arr[mid] == x) {
        return mid;
    } else if (arr[mid] < x) {
        return find (l, mid - 1, x);
    } else {
        return find (mid + 1, r, x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort (arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << endl;
    for (int i = 1; i <= n; i++) {
        turing.arr[i].type = 1;
        turing.arr[i].num = arr[i];
    }
    turing.arr[n + 1] = tuElement (0, 0, "$");
    turing.arr[n + 2] = tuElement (1, 1, "");
    turing.arr[n + 3] = tuElement (1, n, "");
    turing.arr[n + 4] = tuElement (0, 0, "$");
    TuringMachine Origin = turing;
    turing.cnt = n + 4;
    turing.print ();
    while (true) {
        turing = Origin;
        int findX;
        cin >> findX;
        if (findX == -1)
            break;
        turing.cnt = n + 5;
        turing.arr[n + 5] = tuElement (1, findX, "");
        turing.print ();
        turing.binSearch (findX);
        cout << "movTot = " << turing.moveTot << endl;
    }
    while (true) {
        int findX;
        cin >> findX;
        if (findX == -1)
            break;
        int findPos = sys.execute (findX);
        if (findPos == -1) {
            cout << "Don't find " << findX << endl;
        }
    }
    return 0;
}
