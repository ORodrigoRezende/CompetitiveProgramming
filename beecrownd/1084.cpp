#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, D;
    while (cin >> N >> D, N != 0 && D != 0) {
        string s;
        cin >> s;

        int apagar = D;
        string saida;

        for (char c : s) {
            while (!saida.empty() && apagar > 0 && saida.back() < c) {
                saida.pop_back();
                apagar--;
            }
            saida.push_back(c);
        }

        saida.resize(N - D);

        cout << saida << "\n";
    }
    return 0;
}
