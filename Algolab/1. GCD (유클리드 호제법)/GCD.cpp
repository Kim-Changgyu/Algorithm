#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
        
    return gcd(b, a%b);
}

int main() {
    int t, m, n;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> m >> n;
        
        cout << gcd(m, n) << endl;
    }
    
    return 0;
}