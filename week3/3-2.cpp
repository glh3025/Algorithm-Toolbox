#include <iostream>
#include <vector>

//using std::vector;

double get_optimal_value(int n, int capacity, int weights[], int values[]) {
  double value = 0.0;

  // write your code here
    for (int i = n-1;i>=0;i--)
    {
        if (capacity < 0.1e-5) return value;
        int a = std::min(weights[i],capacity);
        value += a * (double)values[i]/(double)weights[i];
        weights[i] -= a;
        capacity -= a;

    }




  return value;
}

void InsertionSort(int n, int weights[], int values[])
{
    //int n = weights.size();
    for (int i = 1; i < n; i++)         // ����ץ�˿�������
    {
        double get = (double)values[i]/(double)weights[i];                 // ����ץ��һ���˿���
        int getw = weights[i];
        int getv = values[i];
        int j = i - 1;                  // ���������ϵ�����������õ�
        while (j >= 0 && (double)values[j]/(double)weights[j] > get)    // ��ץ�����������ƴ���������бȽ�
        {
            values[j + 1] = values[j];            // ��������Ʊ�ץ�����ƴ󣬾ͽ�������
            weights[j + 1] = weights[j];
            j--;
        }
        weights[j + 1] = getw; // ֱ�������Ʊ�ץ������С(��������)����ץ�����Ʋ��뵽�������ұ�(���Ԫ�ص���Դ���δ�䣬���Բ����������ȶ���)
        values[j + 1] = getv;
    }
}



int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
//  vector<int> values(n);
//  vector<int> weights(n);
  int values[n];
  int weights[n];
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  InsertionSort(n, weights, values);
  double optimal_value = get_optimal_value(n, capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << values[i] << weights[i];
  }
  return 0;
}
