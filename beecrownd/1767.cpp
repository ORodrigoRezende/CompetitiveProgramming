#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k = 50;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> pacotes(n);
        for (int i = 0; i < n; i++)
            cin >> pacotes[i].f >> pacotes[i].s;

        vector<vector<int>> dp_brinquedo(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> dp_peso(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp_brinquedo[i][j] = dp_brinquedo[i - 1][j];
                dp_peso[i][j] = dp_peso[i - 1][j];
                if (pacotes[i - 1].s <= j) {
                    int brinquedos = dp_brinquedo[i - 1][j - pacotes[i - 1].s] + pacotes[i - 1].f;
                    int peso = dp_peso[i - 1][j - pacotes[i - 1].s] + pacotes[i - 1].s;
                    if (brinquedos > dp_brinquedo[i][j] ||
                       (brinquedos == dp_brinquedo[i][j] && peso < dp_peso[i][j])) {
                        dp_brinquedo[i][j] = brinquedos;
                        dp_peso[i][j] = peso;
                    }
                }
            }
        }

        int j = k, usados = 0;
        for (int i = n; i > 0; i--) {
            if (dp_brinquedo[i][j] != dp_brinquedo[i - 1][j] ||
                dp_peso[i][j] != dp_peso[i - 1][j]) {
                usados++;
                j -= pacotes[i - 1].s;
            }
        }

        cout << dp_brinquedo[n][k] << " brinquedos\n";
        cout << "Peso: " << dp_peso[n][k] << " kg\n";
        cout << "sobra(m) " << n - usados << " pacote(s)\n\n"; // <- linha em branco até no último caso
    }

    return 0;
}
