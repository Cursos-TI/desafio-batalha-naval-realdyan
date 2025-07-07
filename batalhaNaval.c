#include <stdio.h>

// Constantes para deixar o código mais legível
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3 // Usaremos '3' para representar qualquer navio.

int main() {

    char * coluna[10] = {"A","B","C","D","E","F","G","H","I","J"};
    int linha[10] = {1,2,3,4,5,6,7,8,9,10};

    // Declara e inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    int erro_detectado = 0; // Flag para parar se um erro ocorrer

    // --- Definição dos Navios ---
    // Navio 1: Horizontal, tamanho 3, começando em (1, 1)
    int navio1_linha = 1;
    int navio1_coluna = 1;
    int navio1_tamanho = 3;
    char navio1_orientacao = 'H'; // 'H' = Horizontal

    // Navio 2: Vertical, tamanho 3, começando em (3, 5)
    int navio2_linha = 3; //3 teste sobre
    int navio2_coluna = 5; //5
    int navio2_tamanho = 3;
    char navio2_orientacao = 'V'; // 'V' = Vertical

    // Navio 3: Horizontal, tamanho 3, começando em (7, 3)
    int navio3_linha = 7;
    int navio3_coluna = 3;
    int navio3_tamanho = 3;
    char navio3_orientacao = 'D'; // 'D' = DIAGONAL

    // Navio 4: Vertical, tamanho 3, começando em (2, 1)
    int navio4_linha = 2;
    int navio4_coluna = 1;
    int navio4_tamanho = 3;
    char navio4_orientacao = 'D'; // 'D' = Vertical
    

    // --- Posicionamento do Navio 1 ---
    printf("Posicionando Navio 1...\n");
    for (int i = 0; i < navio1_tamanho; i++) {
        int linha_atual = navio1_linha;
        int coluna_atual = navio1_coluna;

        if (navio1_orientacao == 'H') {
            coluna_atual += i;
        } else {
            linha_atual += i;
        }

        // VALIDAÇÃO DE LIMITES (Feita ANTES de acessar o tabuleiro)
        if (linha_atual >= TAMANHO_TABULEIRO || coluna_atual >= TAMANHO_TABULEIRO) {
            printf("ERRO: Navio 1 fora dos limites em [%d][%d]!\n", linha_atual, coluna_atual);
            erro_detectado = 1;
            break; // Sai do loop do navio 1
        }
        
        // Se a validação passou, posiciona o navio
        tabuleiro[linha_atual][coluna_atual] = NAVIO;
        printf("Navio 1 posicionado em [%d][%d]\n", linha_atual, coluna_atual);
    }

    // --- Posicionamento do Navio 2 (só se não houve erro com o navio 1) ---
    if (!erro_detectado) {
        printf("\nPosicionando Navio 2...\n");
        for (int i = 0; i < navio2_tamanho; i++) {
            int linha_atual = navio2_linha;
            int coluna_atual = navio2_coluna;

            if (navio2_orientacao == 'H') {
                coluna_atual += i;
            } else {
                linha_atual += i;
            }

            // VALIDAÇÃO DE LIMITES
            if (linha_atual >= TAMANHO_TABULEIRO || coluna_atual >= TAMANHO_TABULEIRO) {
                printf("ERRO: Navio 2 fora dos limites em [%d][%d]!\n", linha_atual, coluna_atual);
                erro_detectado = 1;
                break;
            }
            
            // VALIDAÇÃO DE SOBREPOSIÇÃO (A lógica correta!)
            if (tabuleiro[linha_atual][coluna_atual] != AGUA) {
                printf("ERRO DE SOBREPOSIÇÃO: Navio 2 tenta ocupar a posição [%d][%d] que já tem um navio!\n", linha_atual, coluna_atual);
                erro_detectado = 1;
                break; // Para de posicionar este navio
            }

            // Se tudo estiver OK, posiciona o navio
            tabuleiro[linha_atual][coluna_atual] = NAVIO;
            printf("Navio 2 posicionado em [%d][%d]\n", linha_atual, coluna_atual);
        }
    }

    // --- Posicionamento do Navio 3 (só se não houve erro com o navio 2) ---
    if (!erro_detectado) {
        printf("\nPosicionando Navio 3...\n");
        for (int i = 0; i < navio3_tamanho; i++) {
            int linha_atual = navio3_linha;
            int coluna_atual = navio3_coluna;

            if (navio3_orientacao == 'D')
            {
                coluna_atual += i;
                linha_atual += i;
            }
            else if (navio3_orientacao == 'H') {
                coluna_atual += i;
            } else {
                linha_atual += i;
            }

            // VALIDAÇÃO DE LIMITES
            if (linha_atual >= TAMANHO_TABULEIRO || coluna_atual >= TAMANHO_TABULEIRO) {
                printf("ERRO: Navio 3 fora dos limites em [%d][%d]!\n", linha_atual, coluna_atual);
                erro_detectado = 1;
                break;
            }
            
            // VALIDAÇÃO DE SOBREPOSIÇÃO (A lógica correta!)
            if (tabuleiro[linha_atual][coluna_atual] != AGUA) {
                printf("ERRO DE SOBREPOSIÇÃO: Navio 3 tenta ocupar a posição [%d][%d] que já tem um navio!\n", linha_atual, coluna_atual);
                erro_detectado = 1;
                break; // Para de posicionar este navio
            }

            // Se tudo estiver OK, posiciona o navio
            tabuleiro[linha_atual][coluna_atual] = NAVIO;
            printf("Navio 3 posicionado em [%d][%d]\n", linha_atual, coluna_atual);
        }
    }
    
    // --- Posicionamento do Navio 4 (só se não houve erro com o navio 3) ---
    if (!erro_detectado) {
        printf("\nPosicionando Navio 4...\n");
        for (int i = 0; i < navio4_tamanho; i++) {
            int linha_atual = navio4_linha;
            int coluna_atual = navio4_coluna;

            if (navio3_orientacao == 'D')
            {
                coluna_atual += i;
                linha_atual += i;
            }
            else if (navio3_orientacao == 'H') {
                coluna_atual += i;
            } else {
                linha_atual += i;
            }

            // VALIDAÇÃO DE LIMITES
            if (linha_atual >= TAMANHO_TABULEIRO || coluna_atual >= TAMANHO_TABULEIRO) {
                printf("ERRO: Navio 4 fora dos limites em [%d][%d]!\n", linha_atual, coluna_atual);
                erro_detectado = 1;
                break;
            }
            
            // VALIDAÇÃO DE SOBREPOSIÇÃO (A lógica correta!)
            if (tabuleiro[linha_atual][coluna_atual] != AGUA) {
                printf("ERRO DE SOBREPOSIÇÃO: Navio 4 tenta ocupar a posição [%d][%d] que já tem um navio!\n", linha_atual, coluna_atual);
                erro_detectado = 1;
                break; // Para de posicionar este navio
            }

            // Se tudo estiver OK, posiciona o navio
            tabuleiro[linha_atual][coluna_atual] = NAVIO;
            printf("Navio 4 posicionado em [%d][%d]\n", linha_atual, coluna_atual);
        }
    }


    // --- Exibe o Tabuleiro Final ---
    printf("\n--- Tabuleiro Final ---\n");
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%s ", coluna[j]); // Cabeçalho da coluna
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Cabeçalho da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf("0 "); // Água
            } else {
                printf("%i ", NAVIO); // Navio
            }
        }
        printf("\n");
    }

    return 0;
}
