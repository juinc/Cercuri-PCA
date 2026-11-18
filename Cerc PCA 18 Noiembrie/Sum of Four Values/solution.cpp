//Sum of Four Values de pe cses
//https://cses.fi/problemset/task/1642

#include <bits/stdc++.h>
using namespace std;

unsigned int n, i2, i3, i, j;
unsigned long long k;
bool found = false;

vector<pair<unsigned int, unsigned int>> nrs;

pair<int, int> twoSum(unsigned int start, unsigned int end, unsigned long long target){
    while (start < end) {
        unsigned long long sum = nrs[start].first + nrs[end].first;

        if (sum == target)
            return {start, end};

        if (sum < target)
            start++;
        else
            end--;
    }

    return {-1, -1};
}

int main() {
    cin >> n >> k;

    if (n < 4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (unsigned int i = 0; i < n; i++) {
        unsigned int x;
        cin >> x;
        nrs.push_back({x, i});
    }

    sort(nrs.begin(), nrs.end());

    for (i = 0; i < n; i++) {
        for (j = i + 3; j < n; j++) {
            auto res = twoSum(i + 1, j - 1, k - nrs[i].first - nrs[j].first);

            if (res.first != -1) {
                found = true;
                i2 = res.first;
                i3 = res.second;
                break;
            }
        }

        if (found)
            break;
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << nrs[i].second + 1 << ' ' << nrs[i2].second + 1 << ' ' << nrs[i3].second + 1 << ' ' << nrs[j].second + 1 << '\n';

    return 0;
}