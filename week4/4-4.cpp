#include <iostream>
#include <vector>

using std::vector;

long long number_of_inversions = 0;

long long Merge(vector<int> &A, int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    long long cnt = 0;
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j]){
            temp[index] = A[i];
            index++;
            i++;
        }
        else{
            temp[index] = A[j];
            index++;
            j++;
            cnt+=mid-i+1;
        }
        //temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
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
    return cnt;
}
void MergeSortRecursion(vector<int> &A, int left, int right)    // 递归实现的归并排序(自顶向下)
{
    //long long number_of_inversions = 0;
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;// number_of_inversions;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    number_of_inversions += Merge(A, left, mid, right);
   return;// number_of_inversions;
}

//long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
//  long long number_of_inversions = 0;
//  if (right <= left + 1) return number_of_inversions;
//  size_t ave = left + (right - left) / 2;
//  number_of_inversions += get_number_of_inversions(a, b, left, ave);
//  number_of_inversions += get_number_of_inversions(a, b, ave, right);
//  //write your code here
//
//  return number_of_inversions;
//}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  //vector<int> b(a.size());
  MergeSortRecursion(a,0, a.size()-1);
  std::cout << number_of_inversions << '\n';
}
