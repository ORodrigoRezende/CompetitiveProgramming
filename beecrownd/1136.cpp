#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int N, B;
    while (cin >> N >> B && (N != 0 || B != 0)) {
        vector<int> bolas(B);
        for (int i = 0; i < B; i++) {
            cin >> bolas[i];
        }

        set<int> difs;
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                difs.insert(abs(bolas[i] - bolas[j]));
            }
        }

        bool completo = true;
        for (int i = 0; i <= N; i++) {
            if (difs.count(i) == 0) { // usa count() em vez de find()
                completo = false;
                break;
            }
        }

        cout << (completo ? "Y" : "N") << '\n';
    }
    return 0;
}