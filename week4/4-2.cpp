#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
//  if (left == right) return -1;
//  if (left + 1 == right) return a[left];
  //write your code here
  int cnt = 1;
    for(int i = 1; i<right; i++){
        if (a[i] == a[i-1]){
            cnt++;
            if (cnt>a.size()/2) return 1;
        }
        else cnt = 1;
    }

  return 0;
}

void Merge(vector<int> &A, int left, int mid, int right)// �ϲ��������ź��������A[left...mid]��A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // �����ռ�O(n)
    int index = 0;
    int i = left;                   // ǰһ�������ʼԪ��
    int j = mid + 1;                // ��һ�������ʼԪ��
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // ���Ⱥű�֤�鲢������ȶ���
    }
    while (i <= mid)
    {
        temp[index++] = A[i++];
    }
    while (j <= right)
    {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
}

void MergeSortRecursion(vector<int> &A, int left, int right)    // �ݹ�ʵ�ֵĹ鲢����(�Զ�����)
{
    if (left == right)    // ������������г���Ϊ1ʱ���ݹ鿪ʼ���ݣ�����merge����
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  MergeSortRecursion(a,0, a.size()-1);

  std::cout << get_majority_element(a, 0, a.size()) << '\n';

//  std::cout << '\n';
//  for (int i = 0; i< a.size(); ++i){
//    std::cout << a[i];
//  }

}
