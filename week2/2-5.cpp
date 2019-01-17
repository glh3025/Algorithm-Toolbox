#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
long long get_fibonacci_huge_fast(long long n, long long m) {

    long long previous = 0;
    long long current  = 1;
    long long i;

    for (i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%m;
        previous = current%m;
        current = (tmp_previous + current)%m;
        if (current % m == 0 && previous % m ==1) break;
    }
    long long period = i+2;

    long long fnumlist[period] = {0};
    fnumlist[0] = 0;
    fnumlist[1] = 1;
    for (long long j = 2;j<period;++j){
        fnumlist[j] = (fnumlist[j-1]+fnumlist[j-2])%m;
    }
//return period;
   // return fnumlist[n % period]%m;
    //if (period<50)
        return fnumlist[n % period]%m;
    //return get_fibonacci_huge_fast(n % period, m);
    //return 99;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
