#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

vector<int> InsertionSort(vector<int> a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)         // 类似抓扑克牌排序
    {
        int get = a[i];                 // 右手抓到一张扑克牌
        int j = i - 1;                  // 拿在左手上的牌总是排序好的
        while (j >= 0 && a[j] > get)    // 将抓到的牌与手牌从右向左进行比较
        {
            a[j + 1] = a[j];            // 如果该手牌比抓到的牌大，就将其右移
            j--;
        }
        a[j + 1] = get; // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
    }
    return a;
}


int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  a = InsertionSort(a);
  b = InsertionSort(b);
  std::cout << max_dot_product(a, b) << std::endl;
}
