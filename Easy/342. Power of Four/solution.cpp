#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n==0) return false;
        if(n%4==0) return isPowerOfFour(n/4);
        else return false;
}

int main() {
    cout <<  isPowerOfFour(0);
    return 0;
}