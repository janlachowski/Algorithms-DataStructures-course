#include <iostream>
// #include <array>
// #include <vector>

using namespace std;

// szybki bezpośredni dostęp w O(1), co prawda kosztem pamięci :/
bool forbidden[512] = {false};

// pierwsza tabela 32x32 el. reprezentuje stary stan, a druga nowy
// 32x32 reprezentuje binarnie pokolorowanie ostatnich 2 kolumn planszy
int dp[2][32][32] = {0};

// funkcja łączy trzy kolumny (reprezentowane jako liczby z przedziału 0-31)
// w jedną liczbę, której reprezentacja binarna to kolejne wiersze 3 kolumn
unsigned int combineColumns(int a, int b, int c) {
    unsigned int result = 0;
    // przetwarzamy 5 wierszy (wiersz 0 = górny, wiersz 4 = dolny)
    for (int row = 0; row < 5; ++row) {
        result <<= 3;
        // wiersz 0 odpowiada bitowi o indeksie 4, więc bit z danej kolumny:
        int bitA = (a >> (4 - row)) & 1;
        int bitB = (b >> (4 - row)) & 1;
        int bitC = (c >> (4 - row)) & 1;
        // łączymy bity w jeden 3-bitowy blok – najpierw bit z kolumny a, potem b, na końcu c
        int rowValue = (bitA << 2) | (bitB << 1) | bitC;
        // uzupełniamy wynik tym 3-bitowym blokiem
        result |= rowValue;
    }
    return result;
}

void count_possibilities(int first) {
    // na początku zerujemy aktualny bufor dp[first]
    for (int j = 0; j < 32; j++) {
        for (int option = 0; option < 32; option++) {
            dp[first][j][option] = 0;
        }
    }
    // następnie iterujemy po wszystkich stanach poprzednich (i, j)
    // i wszystkich opcjach nowej kolumny (option)
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            // jeżeli dp[prev][i][j] wynosi 0, to pomijamy, żeby bez sensu nie iterować
            if (dp[(first + 1) % 2][i][j] == 0) continue;
            for (int option = 0; option < 32; option++) {
                unsigned int possible_arrangement = combineColumns(i, j, option);
                // sprawdzamy trzy okna 3x3: górne, środkowe i dolne
                if ( forbidden[possible_arrangement >> 6] ||
                     forbidden[(possible_arrangement >> 3) % 512] ||
                     forbidden[possible_arrangement % 512] ) {
                    // trójka jest niepoprawna – nie dodajemy nic.
                    continue;
                }
                else {
                    dp[first][j][option] += dp[(first + 1) % 2][i][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p, m;
    cin >> n >> p >> m;
    // wczytanie zakazanych wzorców
    for (int i = 0; i < p; i++) {
        int pattern = 0; // zmienna do przechowywania 9-bitowego kodu wzoru
        for (int row = 0; row < 3; row++) {
            string line;
            cin >> line;
            // przetwarzamy każdy znak w wierszu
            for (int col = 0; col < 3; col++) {
                pattern = (pattern << 1) | ((line[col] == 'x') ? 1 : 0);
            }
        }
        forbidden[pattern] = true;
    }
    // inicjowanie tablicy dp
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            dp[0][i][j] = 1;
        }
    }
    // dynamicznie zliczamy wszystkie możliwości kolorowania dla kolejnych kolumn (z mod)
    for (int col = 3; col <= n; col++) {
        int first = col % 2;
        count_possibilities(first);
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                dp[first][i][j] %= m;
            }
        }
    }
    // zliczamy wszystkie możliwości z każdego ustawienia ostatnich 2 kolumn
    int answer = 0;
    int last = n % 2;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            answer += dp[last][i][j];
        }
        answer %= m;
    }
    cout << answer;
    return 0;
}