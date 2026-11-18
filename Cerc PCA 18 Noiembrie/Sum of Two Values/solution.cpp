//Sum of Two values de pe cses
//https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

using namespace std;

unsigned long long k, sum;
unsigned int n, x;

int main() {
    vector<pair<unsigned int, unsigned int>> nrs;

    cin >> n >> k;
    for (unsigned int i = 0; i < n; i++) {
        cin >> x;
        nrs.push_back({x, i});
    }

    sort(nrs.begin(), nrs.end());

    unsigned int i = 0, j = nrs.size()-1;

    while (i < j) {
        sum = nrs[i].first + nrs[j].first;
        if (sum == k)
            break;
        if (sum < k)
            i++;
        else
            j--;
    }
    if (sum == k)
        if (nrs[i].second < nrs[j].second)
            cout << nrs[i].second + 1 << ' ' << nrs[j].second + 1;
        else
            cout << nrs[j].second + 1 << ' ' << nrs[i].second + 1;
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}