#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    private:
        vector<int> v;
    public:
        vector<int> returnHeap() {
            return v;
        }
        int top() {
            return v[0];
        }
        void heapifyUp(int i) {
            int parent = (i - 1) / 2;
            while (i > 0 && v[parent] > v[i]) {
                int temp = v[parent];
                v[parent] = v[i];
                v[i] = temp;
                i = parent;
                parent = (i - 1) / 2;
            }
        }
        void heapifyDown(int i) {
            int child = 2 * i + 1;
            if (child > v.size()) {
                return;
            }
            if (child + 1 < v.size() && v[child] > v[child + 1]) {
                child++;
            }
            if (v[i] > v[child]) {
                int temp = v[i];
                v[i] = v[child];
                v[child] = temp;
                heapifyDown(child);
            }
        }
        void insert(int val) {
            v.push_back(val);
            int curr_child = v.size() - 1;
            heapifyUp(curr_child);
        }
        void remove() {
            int temp = v[0];
            v[0] = v[v.size() - 1];
            v[v.size() - 1] = temp;
            v.pop_back();
            heapifyDown(0);
        }
};

int main() {
    MinHeap heap;
    for (int i = 1; i <= 9; i++) {
        heap.insert(i);
    }
    for (int i = 0; i < heap.returnHeap().size(); i++) {
        cout << heap.returnHeap()[i] << " ";
    }
    for (int i = 0; i < heap.returnHeap().size(); i++) {
        heap.remove();
    }
}