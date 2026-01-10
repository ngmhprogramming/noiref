#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
    int id; // original index
};

// Include Convex Hull code here

// Squared Distance
ll dist2(const pt &a, const pt &b) {
    ll dx = (ll)(a.x - b.x);
    ll dy = (ll)(a.y - b.y);
    return dx * dx + dy * dy;
}

// Rotating Calipers
pair<int, int> farthestPair(const vector<pt> &hull) {
    int n = hull.size();
    if (n == 1) return {hull[0].id, hull[0].id};
    if (n == 2) return {hull[0].id, hull[1].id};

    ll best = 0;
    pair<int, int> ans = {hull[0].id, hull[1].id};

    int j = 1;
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        while (true) {
            int nj = (j + 1) % n;
            ll cur = llabs(
                (ll)(hull[ni].x - hull[i].x) * (hull[j].y - hull[i].y)
              - (ll)(hull[ni].y - hull[i].y) * (hull[j].x - hull[i].x)
            );
            ll nxt = llabs(
                (ll)(hull[ni].x - hull[i].x) * (hull[nj].y - hull[i].y)
              - (ll)(hull[ni].y - hull[i].y) * (hull[nj].x - hull[i].x)
            );
            if (nxt > cur) j = nj;
            else break;
        }

        ll d1 = dist2(hull[i], hull[j]);
        if (d1 > best) {
            best = d1;
            ans = {hull[i].id, hull[j].id};
        }

        ll d2 = dist2(hull[ni], hull[j]);
        if (d2 > best) {
            best = d2;
            ans = {hull[ni].id, hull[j].id};
        }
    }
    return ans;
}

convexHull(pts, false);
pair<int, int> ans = farthestPair(pts);