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

void Merge(vector<int> &A, int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
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

void MergeSortRecursion(vector<int> &A, int left, int right)    // 递归实现的归并排序(自顶向下)
{
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
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
