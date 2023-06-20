#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    private:
        vector<pair<string, int>> v;
    public:
        vector<pair<string, int>> returnPQ() {
            return v;
        }
        pair<string, int> top() {
            return v[0];
        }
        void insert(string x, int weight) {
            pair<string, int> p = {x, weight};
            v.push_back(p);
            int idx = v.size() - 1;
            while (idx > 0 && v[idx].second > v[(idx - 1) / 2].second) {
                v[idx] = v[(idx - 1) / 2];
                v[(idx - 1) / 2] = p;
                idx = (idx - 1) / 2;
            }
        }
        void remove() {
            v[0] = v[v.size() - 1];
            v.resize(v.size() - 1);
            int idx = 0;
            int left = 0;
            int right = 0;
            int biggest = 0;
            while ((2 * idx + 1) < v.size() - 1) {
                left = 2 * idx + 1;
                right = idx;
                if ((2 * idx + 2) < v.size() - 1) {
                    right = 2 * idx + 2;
                }
                biggest = max(v[right].second, v[left].second);
                if (biggest > v[idx].second && biggest == v[right].second) {
                    pair<string, int> temp = v[right];
                    v[right] = v[idx];
                    v[idx] = temp;
                    idx = right;
                } else if (biggest > v[idx].second && biggest == v[left].second) {
                    pair<string, int> temp = v[left];
                    v[left] = v[right];
                    v[idx] = temp;
                    idx = left;
                } else {
                    return;
                }
            }
        }
};

int main() {
    PriorityQueue pq;
    pq.insert("a", 4);
    pq.insert("b", 2);
    pq.insert("c", 8);
    pq.insert("d", 4);
    pq.insert("e", 1);
    pq.insert("f", 0);
    pq.insert("g", 1);
    vector<pair<string, int>> v =  pq.returnPQ();
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << ", " << v[i].second << endl;
    }
    cout << endl;
    cout <<  pq.top().first << ", " <<  pq.top().second << endl;
    cout << endl;
    pq.remove();
    v =  pq.returnPQ();
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ", " << v[i].second << endl;
    }
}