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
    for (int i = 1; i < n; i++)         // ����ץ�˿�������
    {
        int get = a[i];                 // ����ץ��һ���˿���
        int j = i - 1;                  // ���������ϵ�����������õ�
        while (j >= 0 && a[j] > get)    // ��ץ�����������ƴ���������бȽ�
        {
            a[j + 1] = a[j];            // ��������Ʊ�ץ�����ƴ󣬾ͽ�������
            j--;
        }
        a[j + 1] = get; // ֱ�������Ʊ�ץ������С(��������)����ץ�����Ʋ��뵽�������ұ�(���Ԫ�ص���Դ���δ�䣬���Բ����������ȶ���)
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
