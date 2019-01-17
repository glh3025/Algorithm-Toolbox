#include <iostream>
#include <vector>

using std::vector;

long long number_of_inversions = 0;

long long Merge(vector<int> &A, int left, int mid, int right)// �ϲ��������ź��������A[left...mid]��A[mid+1...right]
{
    long long cnt = 0;
    int len = right - left + 1;
    int *temp = new int[len];       // �����ռ�O(n)
    int index = 0;
    int i = left;                   // ǰһ�������ʼԪ��
    int j = mid + 1;                // ��һ�������ʼԪ��
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
        //temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // ���Ⱥű�֤�鲢������ȶ���
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
void MergeSortRecursion(vector<int> &A, int left, int right)    // �ݹ�ʵ�ֵĹ鲢����(�Զ�����)
{
    //long long number_of_inversions = 0;
    if (left == right)    // ������������г���Ϊ1ʱ���ݹ鿪ʼ���ݣ�����merge����
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
