#include <iostream>

using namespace std;

int main() {
    /* k = dolars first banana */
    /* n = soldiers dolar */
    /* w = bananas soldier wants */
    long long k, n, w;
    cin >> k >> n >> w;

    long long finalMoney = (k * (w * (w + 1) / 2));
    
    cout << ((finalMoney - n) > 0 ? (finalMoney - n) : 0) << "\n";
    return 0;
}
