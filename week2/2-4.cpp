#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int lcm_fast(int a, int b) {
//    if (a>=b){
//        for (int i = 1; i<= b; ++i){
//            if (((long long)i*a) %b == 0)
//                return (long long)i*a;
//        }
//    }
//    else{
//        for (int i = 1; i<= a; ++i){
//            if (((long long)i*b) %a == 0)
//                return (long long)i*b;
//        }
//    }
//    return (long long) a * b;
    int b2=0;
    if (b!=0){
        b2=a%b;
        return lcm_fast(b,b2);
    }
    return a;
}

int main() {
  int a, b;
  int gcd;
  std::cin >> a >> b;
  gcd = lcm_fast(a, b);

  std::cout << (long long) a * b / gcd << std::endl;
  return 0;
}
