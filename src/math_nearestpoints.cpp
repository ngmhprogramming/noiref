#include <bits/stdc++.h>
using namespace std;

struct pt {
    long long x, y;
    int id;
};

struct cmp_x {
    bool operator()(const pt &a, const pt &b) const {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

struct cmp_y {
    bool operator()(const pt &a, const pt &b) const {
        return a.y < b.y;
    }
};

vector<pt> a, t;
long long mindist;
pair<int, int> best_pair;

// Square Distance
inline long long dist2(const pt &a, const pt &b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// Compare and update
inline void update(const pt &a, const pt &b) {
    long long d = dist2(a, b);
    if (d < mindist) {
        mindist = d;
        best_pair = {a.id, b.id};
    }
}

void rec(int l, int r) {
	/// Handle small case naively
    if (r - l <= 3) {
        for (int i = l; i < r; i++)
            for (int j = i + 1; j < r; j++)
                update(a[i], a[j]);
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    long long midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m,
          a.begin() + m, a.begin() + r,
          t.begin(), cmp_y());
    copy(t.begin(), t.begin() + (r - l), a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; i++) {
        long long dx = a[i].x - midx;
        if (dx * dx < mindist) {
            for (int j = tsz - 1; j >= 0; j--) {
                long long dy = a[i].y - t[j].y;
                if (dy * dy >= mindist) break;
                update(a[i], t[j]);
            }
            t[tsz++] = a[i];
        }
    }
}

// Remember to check for duplicates
sort(a.begin(), a.end(), cmp_x());
mindist = LLONG_MAX;
best_pair = {0, 1};
rec(0, N);