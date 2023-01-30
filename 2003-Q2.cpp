// Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numeric>

using namespace std;

struct fraction {
	long long n, d;

	inline bool operator >(const fraction& other) const { return n * other.d > d * other.n; }

	inline fraction operator-(const fraction& other) {
		return fraction(n*other.d - d*other.n, d*other.d);
	}
};

inline ostream& operator<<(ostream& os, const fraction& f) {
	os << f.n << ' ' << f.d;
	return os;
}

int main() { int M; cin >> M; while (M--) {
	fraction X;
	cin >> X.n >> X.d;

	fraction lowdiff(2, 1), highdiff(2, 1), low, high;

	for (int i = 1; i < 100; ++i) {
		for (int j = 1; j < i; ++j) {
			fraction f{ j, i };
			if (f > X) {
				if (highdiff > (f - X)) {
					highdiff = f - X;
					high = f;
				}
				f.n--;
				if (lowdiff > (X - f)) {
					lowdiff = X - f;
					low = f;
				}
				break;
			}
		}
	}

	cout << low << ' ' << high << endl;

} }
