#include <iostream>

int get_change(int m) {
  //write your code here
  int mincoin[m] = {0};

  for (int i = 0; i <= m; i++){
    if (i>=4){
        mincoin[i] = mincoin[i-1]+1;
        if (mincoin[i-3]<=mincoin[i-1]) mincoin[i] = mincoin[i-3]+1;
        if (mincoin[i-4]<=mincoin[i-3]) mincoin[i] = mincoin[i-4]+1;

    }
        //mincoin[i] = std::min(mincoin[i-1],mincoin[i-3],mincoin[i-4])+1;
    else if (i>=3)
        mincoin[i] = std::min(mincoin[i-1],mincoin[i-3])+1;
    else if (i>=1)
        mincoin[i] = mincoin[i-1]+1;
  }



  return mincoin[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
