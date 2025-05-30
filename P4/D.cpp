#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

typedef long long ll;

using namespace std;

struct Point {
    int x, y;
};

vector<Point> points_by_x;
vector<Point> points_by_y;
int point_number;

inline ll dist(const Point& a, const Point& b) {
    ll dx = ll(b.x - a.x);
    ll dy = ll(b.y - a.y);
    return dx*dx + dy*dy;
}

// takes start and end as a range [start, end) so without last index
// returns pair of closest points
pair<Point, Point> closest_points(int start, int end, const vector<Point>& Py) {
    int n = end - start;

    // base cases:
    if (n == 2) return {points_by_x[start], points_by_x[start + 1]};
    if (n == 3) {
        // d(1,2) < d(2,3)?
        if (dist(points_by_x[start], points_by_x[start + 1]) < dist(points_by_x[start + 1], points_by_x[start + 2])) {
            // d(1,2) < d(1,3)?
            if (dist(points_by_x[start], points_by_x[start + 1]) < dist(points_by_x[start], points_by_x[start + 2])) {
                return {points_by_x[start], points_by_x[start + 1]};
            }
            // d(1,2) >= d(1,3)
            else {
                return {points_by_x[start], points_by_x[start + 2]};
            }
        }
        // d(1,2) >= d(2,3) and d(1,3) > d(2,3) 
        else if (dist(points_by_x[start], points_by_x[start + 2]) > dist(points_by_x[start + 1], points_by_x[start + 2])) {
            return {points_by_x[start + 1], points_by_x[start + 2]};
        }
        else return {points_by_x[start], points_by_x[start + 2]};
    }

    // divide
    int mid = start + n/2;
    int mid_x = points_by_x[mid].x;
    vector<Point> PyL, PyR;
    PyL.reserve(mid - start);
    PyR.reserve(end - mid);
    for (auto &p : Py) {
        // exactly (mid - start) points in PyL
        if (p.x < mid_x || (p.x == mid_x && PyL.size() < size_t(mid - start)))
            PyL.push_back(p);
        else
            PyR.push_back(p);
    }
    auto [min1, min2] = closest_points(start, mid, PyL);
    auto [r1, r2] = closest_points(mid, end, PyR);

    ll min_d = dist(min1, min2);
    ll temp = dist(r1, r2);
    if (min_d > temp) {
        min_d = temp;
        min1 = r1;
        min2 = r2;
    }

    // combine
    vector<Point> S;
    S.reserve(Py.size());
    for (auto &p : Py) {
        ll dx = ll(p.x) - mid_x;
        if (dx*dx < min_d)
            S.push_back(p);
    }
    int s_size = (int)S.size();
    for (int i = 0; i < s_size; ++i) {
        for (int j = i+1; j < s_size && j <= i+7; ++j) {
            ll maybe = dist(S[i], S[j]);
            if (maybe < min_d) {
                min_d = maybe;
                min1 = S[i];
                min2 = S[j];
            }
        }
    }
    return {min1, min2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> point_number;
    points_by_x.resize(point_number);
    for (int i = 0; i < point_number; ++i) {
        cin >> points_by_x[i].x >> points_by_x[i].y;
    }
    points_by_y = points_by_x;

    sort(
        points_by_x.begin(),
        points_by_x.end(),
        [](const Point& a, const Point& b) {
            return a.x < b.x;
        }
    );
    sort(
        points_by_y.begin(),
        points_by_y.end(),
        [](const Point& a, const Point& b) {
            return a.y < b.y;
        }
    );

    auto [point1, point2] = closest_points(0, point_number, points_by_y); 
    cout << point1.x << " " << point1.y << "\n" << point2.x << " " << point2.y;
    return 0;
}