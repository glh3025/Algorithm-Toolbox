#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence2(int n) {
  std::vector<int> minop(n+1);
  minop[0]=0;
  minop[1]=0;
  if(n>=2){
      for (int i = 2; i<=n; i++){
        minop[i] = minop[i-1]+1;
        if(i%2==0 && minop[i/2]<=minop[i-1]) minop[i] = minop[i/2]+1;
        if(i%3==0 && minop[i/3]<=minop[i/2]) minop[i] = minop[i/3]+1;

      }
  }
  std::vector<int> sequence2(minop[n]+1);
  sequence2[0]=1;
  if(n>=2){
      int currentop = minop[n];
      int prei = n;
      int j = minop[n];
      for (int i = n; i>=2; i--){
        if (minop[i]==currentop && (i==prei || i==prei-1 || (i==prei/2&&prei%2==0) || (i==prei/3&&prei%3==0))){
            sequence2[j--]=i;
            currentop--;
            prei = i;
        }
      }
    }
  return sequence2;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence2(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
