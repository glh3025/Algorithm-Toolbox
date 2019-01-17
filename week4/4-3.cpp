#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

struct M2
{
    int m1;
    int m2;
};

M2 partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  M2 m;
   m.m1 = l;
   m.m2 = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] == x) {
      m.m2++;
      swap(a[i], a[m.m2]);
    }
    else if (a[i] < x) {

      m.m1++;
      m.m2++;
    swap(a[i], a[m.m1]);
      if (m.m1 != m.m2) swap(a[i], a[m.m2]);
    }
  }
  swap(a[l], a[m.m1]);
  return m;
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  M2 m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.m1-1);
  randomized_quick_sort(a, m.m2+1 , r);

//  int m = partition2(a, l, r);
//
//  randomized_quick_sort(a, l, m - 1);
//  randomized_quick_sort(a, m + 1, r);

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    //a[i]=1 + rand() % (20);
    //std::cout << a[i] << ' ';
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  std::cout << '\n';
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
