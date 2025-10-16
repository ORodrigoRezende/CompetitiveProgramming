#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAM 1001
#define ASCII_MAX 128

typedef struct {
    char ascii;
    unsigned short frequencia;
} dados;

void quickSortInterno(dados *caractere, int inicio, int fim);
void quickSort(dados *caractere, int tam);
void insertionSort(dados *caractere, unsigned short tam);

int main() {
    char texto[MAX_TAM];
    int z = 0;

    while (fgets(texto, sizeof(texto), stdin) != NULL) {
        size_t len = strlen(texto);
        if (len > 0 && texto[len - 1] == '\n') {
            texto[len - 1] = '\0';
        }

        // Contador de frequência para caracteres ASCII
        int contador[ASCII_MAX] = {0};
        for (int i = 0; texto[i]; i++) {
            contador[(unsigned char)texto[i]]++;
        }

        // Preenche vetor de structs com os caracteres presentes
        dados caractere[MAX_TAM];
        int k = 0;
        for (int i = 0; i < ASCII_MAX; i++) {
            if (contador[i] > 0) {
                caractere[k].ascii = i;
                caractere[k].frequencia = contador[i];
                k++;
            }
        }

        // Ordenações: primeiro por ASCII decrescente, depois por frequência crescente
        quickSort(caractere, k);
        insertionSort(caractere, k);

        // Impressão da quebra de linha entre os casos
        if (z)
            printf("\n");
        else
            z = 1;

        for (int i = 0; i < k; i++) {
            printf("%hhd %hu\n", caractere[i].ascii, caractere[i].frequencia);
        }
    }

    return 0;
}

void quickSortInterno(dados *caractere, int inicio, int fim) {
    if (inicio < fim) {
        int i = inicio, j = fim;
        dados pivo = caractere[(i + j) / 2], temp;

        while (i <= j) {
            while (caractere[i].ascii > pivo.ascii) i++;
            while (caractere[j].ascii < pivo.ascii) j--;

            if (i <= j) {
                temp = caractere[i];
                caractere[i] = caractere[j];
                caractere[j] = temp;
                i++; j--;
            }
        }

        quickSortInterno(caractere, inicio, j);
        quickSortInterno(caractere, i, fim);
    }
}

void quickSort(dados *caractere, int tam) {
    quickSortInterno(caractere, 0, tam - 1);
}

void insertionSort(dados *caractere, unsigned short tam) {
    for (int i = 1; i < tam; i++) {
        dados pivo = caractere[i];
        int j = i - 1;
        while (j >= 0 && caractere[j].frequencia > pivo.frequencia) {
            caractere[j + 1] = caractere[j];
            j--;
        }
        caractere[j + 1] = pivo;
    }
}
