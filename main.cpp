#include <bits/stdc++.h>
const int MAXN = 1e6 + 5;
int n, arr[MAXN];
#define LL long long
#define mod %
#include "turing.h"
#include "recursive.h"

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
        turing.arr[i] = tuElement (1, arr[i], "");
    }
    while (true) {
        int findX;
        cin >> findX;
        sys.execute (findX);
    }
    return 0;
}
