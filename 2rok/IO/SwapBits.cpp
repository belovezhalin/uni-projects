//Anhelina Belavezha
#include <iostream>
using namespace std;

unsigned int swapbits(unsigned int x) {
    for(int i = 0; i < 32; i += 2) {
        unsigned int bit_i = (x >> i) & 1;
        unsigned int bit_iplus1 = (x >> (i + 1)) & 1;
        if(bit_i != bit_iplus1) {
            x ^= (1 << i) | (1 << (i + 1));
        }
    }
    return x;
}

int main() {
    unsigned int x = 23; 
    cout << "Original: " << x << endl;
    cout << "Modified: " << swapbits(x) << endl;
    return 0;
}
