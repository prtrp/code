```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // se x e' minore di 10, oppure x finisce con 0 e != 0
        // allora significa che non eè palindroma 
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;

        // finche x e' maggiore di reversed
        while (x > reversed) {
            // reversed sara uguale a x moltiplicate per 10, piu il resto della divisione per 10
            reversed = reversed * 10 + x %10;
            // diminuisco x di 10
            x /= 10;
        }

        // qui uso nel caso in cui ho x ha numeri che compone pari o dispari
        return x == reversed || x == reversed / 10;
    }
}
```
# esempio di un valore:
x = 1221 -> reversed = 1 x = 122 -> reversed = 12 x = 12 -> true
