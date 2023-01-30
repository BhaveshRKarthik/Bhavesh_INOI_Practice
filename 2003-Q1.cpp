// Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<vector<bool>> B(M, vector<bool>(N)); // Board: is-wall
    bool tmp;
    for (auto& l: B) {
        for (int i = 0; i < N; ++i) {
            cin >> tmp;
            l[i] = tmp;
        }
    }

    queue<pair<int, int>> Q;
    int CC = 0;
    int Cmax = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!B[i][j]) {
                Q.emplace(i, j);
                int Ccnt = 0;
                while (!Q.empty()) {
                    auto f = Q.front();
                    if (B[f.first][f.second]) {
                        Q.pop();
                        continue;
                    }

                    if (!B[f.first + 1][f.second]) Q.emplace(f.first + 1, f.second);
                    if (!B[f.first - 1][f.second]) Q.emplace(f.first - 1, f.second);
                    if (!B[f.first][f.second + 1]) Q.emplace(f.first, f.second + 1);
                    if (!B[f.first][f.second - 1]) Q.emplace(f.first, f.second - 1);
                    
                    B[f.first][f.second] = true;

                    Q.pop();
                    Ccnt++;
                }
                CC++;
                Cmax = max(Cmax, Ccnt);
            }
        }
    }

    cout << CC << endl << Cmax << endl;
}
