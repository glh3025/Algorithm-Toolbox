#include <iostream>
#include <vector>

using std::vector;

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void BubbleSort(int A[], int n)
{
    for (int j = 0; j < n - 1; j++)         // 每次最大元素就像气泡一样"浮"到数组的最后
    {
        for (int i = 0; i < n - 1 - j; i++) // 依次比较相邻的两个元素,使较大的那个向后移
        {
            if (A[i] > A[i + 1])            // 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
            {
                Swap(A, i, i + 1);
            }
        }
    }
}

int partition3(int A[], int n) {
  //write your code here
  if (n<3) return 0;
  BubbleSort(A, n);
  int sum = 0;
  for (int i = 0; i < n; i++) sum+=A[i];
  if (sum % 3 != 0) return 0;
  //for (int i = 0; i < n; i++) std::cout << A[i] << ' ';

    int N = n + 1;
    int M = sum/3 + 1;
    int** value = new int*[N];
    for(int i = 0; i < N; ++i)
      value[i] = new int[M];

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            value[i][j] = 0;

    int val = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= sum/3; j++){
            value[i][j] = value[i-1][j];
            if (A[i-1]<=j){
                val = value[i-1][j-A[i-1]] + A[i-1];
                if (value[i][j]<val) value[i][j]=val;
            }
        }
    }
    if (value[n][M-1] != M-1) return 0;

//    for (int i = 0; i < n; i++){
//        std::cout << A[i] << ' ';
//    }
//    std::cout << '\n';
//        for (int i = 0; i < N; i++){
//            for (int j = 0; j < M; j++){
//                std::cout << value[i][j] << ' ';
//            }
//            std::cout << '\n';
//        }

    int solution[n] = {0};
    int currentSum = M-1;
    int numUsed = 0;
    for (int i = n; i >= 1; i--){
        if (value[i-1][currentSum-A[i-1]] == value[i][currentSum] - A[i-1]){
            solution[i-1] = 1;
            currentSum -= A[i-1];
            numUsed++;
        }
    }

    int n2 = n-numUsed;
    int A2[n2];
    int j = 0;
    for (int i = 0; i < n; i++){
        if (solution[i] == 0){
            A2[j] = A[i];
            j++;
        }
    }
//    for (int i = 0; i < n2; i++){
//        std::cout << A2[i] << ' ';
//    }
//    std::cout << '\n';

    int N2 = n2+1;
    int M2 = M;

    int** value2 = new int*[N2];
    for(int i = 0; i < N2; ++i)
      value2[i] = new int[M2];

    for(int i = 0; i < N2; ++i)
        for(int j = 0; j < M2; ++j)
            value2[i][j] = 0;

    int val2 = 0;

    for (int i = 1; i <= n2; i++){
        for (int j = 1; j <= sum/3; j++){
            value2[i][j] = value2[i-1][j];
            if (A2[i-1]<=j){
                val2 = value2[i-1][j-A2[i-1]] + A2[i-1];
                if (value2[i][j]<val2) value2[i][j]=val2;
            }
        }
    }
    if (value2[n2][M2-1] != M2-1) return 0;

  return 1;
}


int main() {
  int n;
  std::cin >> n;
  //vector<int> A(n);
  int A[n];
  for (size_t i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A, n) << '\n';
}
