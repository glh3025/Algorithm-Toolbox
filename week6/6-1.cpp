#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight2(int W, const vector<int> &w) {

    int N = w.size()+1;
    int M = W+1;
    int** value = new int*[N];
    for(int i = 0; i < N; ++i)
      value[i] = new int[M];

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            value[i][j] = 0;

    //int value[w.size()+1][W+1] = {0};
    //for (int j = 0; j <= W; j++) value[0][j] = 0;
    int val = 0;

    for (int i = 1; i <= w.size(); i++){
        for (int j = 1; j <= W; j++){
            value[i][j] = value[i-1][j];
            if (w[i-1]<=j){
                val = value[i-1][j-w[i-1]] +w[i-1];
                if (value[i][j]<val) value[i][j]=val;
            }
        }
    }
//    vector<vector<int>> value(w.size());
//    for (int i = 0; i < value.size(); i++) value[i].resize(W);
//    for (int i = 0; i < w.size(); i++) value[i][0] = 0;
//    for (int i = 0; i < W; i++) value[0][i] = 0;

//    for (int i = 0; i <= w.size(); i++){
//        for (int j = 0; j <= W; j++){
//            std::cout << value[i][j] << ' ';
//        }
//        std::cout << '\n';
//    }

//    for(int i = 0; i < N; ++i)
//        delete [] value[i];
//    delete [] value;

    return value[w.size()][W];

}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  std::cout << optimal_weight2(W, w) << '\n';

}
