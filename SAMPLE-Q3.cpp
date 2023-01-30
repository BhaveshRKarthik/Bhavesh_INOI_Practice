// SAMPLE-Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1.00";
        return 0;
    }
    set<int> rems{1};
    cout << "0.";
    int endpoint = -1, rem = 1;
    while (true) {
        rem *= 10;
        cout << rem / n;
        rem %= n;
        if (rem == endpoint) break;
        
        if (rems.count(rem) && endpoint == -1)
            endpoint = rem;
        
        rems.insert(rem);

    }
}
