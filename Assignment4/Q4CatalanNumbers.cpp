#include <bits/stdc++.h>
using namespace std;
/*The Catalan numbers are a mathematical sequence of numbers. The nth Catalan number is defined 
as (2n)! / (n+1)!n!. Given a non-negative integer n, return the Catalan numbers 0-n.*/

int returnCatalanNumber(int num) {
    if (num <= 1) {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < num; i++) {
        res += returnCatalanNumber(i) * returnCatalanNumber(num - i - 1);
    }
    return res;
}
 
int main() {
    cout << returnCatalanNumber(1) << " " << returnCatalanNumber(5) << endl;
}