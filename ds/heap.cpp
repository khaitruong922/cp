#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void heapify(int i, int n) {
  int left = i * 2 + 1;
  int right = i * 2 + 2;
  int smallest = i;
  if (left < n && v[left] > v[smallest]) {
    smallest = left;
  }

  if (right < n && v[right] > v[smallest]) {
    smallest = right;
  }
  if (smallest != i) {
    swap(v[smallest], v[i]);
    heapify(smallest, n);
  }
}

void buildHeap() {
  int n = v.size();
  for (int i = n / 2 - 1; i >= 0; --i) heapify(i, n);
}

void heapSort() {
  buildHeap();
  int n = v.size();
  for (int i = n - 1; i > 0; --i) {
    swap(v[0], v[i]);
    heapify(0, i);
  }
}

void printVec() {
  for (auto x : v) cout << x << " ";
  cout << endl;
}

void push(int x) {
  v.push_back(x);
  int n = v.size();
  int i = n - 1;
  while (i > 0 && v[(i - 1) / 2] < v[i]) {
    swap(v[(i - 1) / 2], v[i]);
    i = (i - 1) / 2;
  }
}

void pop() {
  int n = v.size();
  if (n == 0) return;
  v[0] = v[n - 1];
  v.pop_back();
  heapify(0, n);
}

int main() {
  v = {7, 12, 6, 10, 17, 15, 2, 4};
  heapSort();
  printVec();
}
