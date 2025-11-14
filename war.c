

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    Estrutura básica de um território.
    Será usada no mapa e nas missões.
*/
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

/* -----------------------------------------------------------
   Função: atribuirMissao
   Objetivo: sortear uma missão e copiar para o destino.
   Parâmetros:
      destino  -> ponteiro para missão do jogador
      missoes  -> vetor de strings com as missões disponíveis
      total    -> quantidade de missões
-------------------------------------------------------------*/
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

/* -----------------------------------------------------------
   Função: verificarMissao
   Objetivo: verificar se o jogador cumpriu sua missão.
   (Aqui implementamos uma lógica simples inicial)
-------------------------------------------------------------*/
int verificarMissao(char* missao, Territorio* mapa, int tamanho) {

    // Exemplo simples: se missão contém "3 territórios"
    // e o jogador tem cor "azul", ele deve possuir 3 territórios.
    if (strstr(missao, "3 territorios") != NULL) {
        int count = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "azul") == 0) {
                count++;
            }
        }
        return (count >= 3);
    }

    // Outras missões podem ser adicionadas aqui
    return 0;
}

/* -----------------------------------------------------------
   Função: atacar
   Objetivo: simular ataque entre dois territórios.
   - Cada lado rola um dado (1 a 6).
   - Se atacante vence, ele conquista o território.
   - Se perde, atacante perde 1 tropa.
-------------------------------------------------------------*/
void atacar(Territorio* atacante, Territorio* defensor) {

    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\nAtaque inválido! Não é possível atacar território aliado.\n");
        return;
    }

    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\nDado atacante: %d | Dado defensor: %d\n", dadoA, dadoD);

    if (dadoA > dadoD) {
        printf("Ataque bem-sucedido! O território foi conquistado.\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
    } else {
        printf("Ataque falhou! Atacante perdeu 1 tropa.\n");
        atacante->tropas -= 1;
    }
}

/* -----------------------------------------------------------
   Exibe missão do jogador uma única vez
-------------------------------------------------------------*/
void exibirMissao(char* missao) {
    printf("\n===== SUA MISSÃO =====\n%s\n\n", missao);
}

/* -----------------------------------------------------------
   Libera memória alocada dinamicamente
-------------------------------------------------------------*/
void liberarMemoria(char* missaoJogador, Territorio* mapa) {
    free(missaoJogador);
    free(mapa);
}

/* -----------------------------------------------------------
                       FUNÇÃO PRINCIPAL
-------------------------------------------------------------*/
int main() {
    srand(time(NULL));

    // Missões pré-definidas
    char* missoes[] = {
        "Conquistar 3 territorios seguidos",
        "Eliminar todas as tropas vermelhas",
        "Controlar todos os territorios do norte",
        "Manter 5 territorios ao final de um turno",
        "Destruir 2 territorios verdes"
    };

    int totalMissoes = 5;

    // Alocação dinâmica da missão do jogador
    char* missaoJogador = (char*)malloc(100 * sizeof(char));

    // Sorteio da missão
    atribuirMissao(missaoJogador, missoes, totalMissoes);

    // Exibição da missão (apenas no início)
    exibirMissao(missaoJogador);

    // Criação do mapa (5 territórios, exemplo)
    Territorio* mapa = (Territorio*)calloc(5, sizeof(Territorio));

    // Inicialização de exemplo (pode ser substituída)
    strcpy(mapa[0].nome, "Alfa");  strcpy(mapa[0].cor, "azul"); mapa[0].tropas = 3;
    strcpy(mapa[1].nome, "Beta");  strcpy(mapa[1].cor, "vermelha"); mapa[1].tropas = 4;
    strcpy(mapa[2].nome, "Gama");  strcpy(mapa[2].cor, "azul"); mapa[2].tropas = 2;
    strcpy(mapa[3].nome, "Delta"); strcpy(mapa[3].cor, "verde"); mapa[3].tropas = 5;
    strcpy(mapa[4].nome, "Sigma"); strcpy(mapa[4].cor, "azul"); mapa[4].tropas = 1;

    int turno = 1;

    // Loop de turnos (simplificado)
    while (1) {
        printf("\n===== TURNO %d =====\n", turno);

        // Verificar missão silenciosamente
        if (verificarMissao(missaoJogador, mapa, 5)) {
            printf("\n🎉 VOCÊ CUMPRIU SUA MISSÃO! PARABÉNS! 🎉\n");
            break;
        }

        // Exemplo de ataque automático para demonstração
        if (turno == 2)
            atacar(&mapa[0], &mapa[1]);

        turno++;

        if (turno > 6) {
            printf("\nFim da simulação.\n");
            break;
        }
    }

    // Liberação de memória
    liberarMemoria(missaoJogador, mapa);

    return 0;
}
