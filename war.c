
#include <stdio.h>
#include <string.h>

/*
    Struct Territorio:
    Armazena o nome do território, a cor do exército e a quantidade de tropas.
*/
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {

    // Vetor para armazenar 5 territórios
    Territorio territorios[5];

    printf("===== Cadastro de Territórios =====\n\n");

    // Entrada dos dados
    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);

        printf("Digite o nome do território: ");
        scanf("%s", territorios[i].nome);

        printf("Digite a cor do exército: ");
        scanf("%s", territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Exibição dos dados cadastrados
    printf("===== Territórios Cadastrados =====\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
