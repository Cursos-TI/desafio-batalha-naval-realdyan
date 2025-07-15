#include <stdio.h>
#include <stdlib.h> //Adicionado para usar a função abs() para o losango

// Constantes para deixar o código mais legível
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3 // Usaremos '3' para representar qualquer navio.
#define AREA_AFETADA 5 // Area Afetada pela habildiade
#define TAMANHO_HABILIDADE 5 // NOVO: Tamanho padrão para as matrizes de habilidade

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
    char navio4_orientacao = 'D'; // 'D' = DIAGONAL
    

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

    // --- Posicionamento do Navio 3 (só se não houve erro com o navio 2
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

            // NOVO: CORREÇÃO DE BUG. Esta lógica estava usando navio3_orientacao por engano.
            if (navio4_orientacao == 'D')
            {
                coluna_atual += i;
                linha_atual += i;
            }
            else if (navio4_orientacao == 'H') {
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
            
            // VALIDAÇÃO DE SOBREPOSIÇÃO
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


// =========================================================================

// NOVO: InÍCIO DO BLOco DE HABILIDADES

// Habilidades

    // --- Habilidade 1: Cone ---
    printf("\n... Aplicando Habilidade Cone ...\n");
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int cone_origem_linha = 2;
    int cone_origem_coluna = 7;
    int centro_habilidade = TAMANHO_HABILIDADE / 2;

    // padrão do cone na sua matriz temporária
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i <= centro_habilidade && abs(j - centro_habilidade) <= i) {
                habilidade_cone[i][j] = 1; // 1 = parte do padrão
            }
        }
    }

    // Aplicando o padrão do cone no tabuleiro principal
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_cone[i][j] == 1) { // Se esta parte do padrão deve ser desenhada
                int linha_tabuleiro = cone_origem_linha - centro_habilidade + i;
                int coluna_tabuleiro = cone_origem_coluna - centro_habilidade + j;

                // Validação para não desenhar fora do tabuleiro 10x10
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = AREA_AFETADA;
                }
            }
        }
    }


    // -Habilidade 2: Cruz
    printf("... Aplicando Habilidade Cruz ...\n");
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int cruz_origem_linha = 8;
    int cruz_origem_coluna = 8;

    // Gerando o padrão da cruz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro_habilidade || j == centro_habilidade) {
                habilidade_cruz[i][j] = 1;
            }
        }
    }

    // Aplicando a cruz no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_cruz[i][j] == 1) {
                int linha_tabuleiro = cruz_origem_linha - centro_habilidade + i;
                int coluna_tabuleiro = cruz_origem_coluna - centro_habilidade + j;
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = AREA_AFETADA;
                }
            }
        }
    }

    // --- Habilidade 3: Octaedro (Losango
    printf("... Aplicando Habilidade Octaedro ...\n");
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int octaedro_origem_linha = 5;
    int octaedro_origem_coluna = 2;

    // Gerando o padrão do losango
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro_habilidade) + abs(j - centro_habilidade) <= centro_habilidade) {
                habilidade_octaedro[i][j] = 1;
            }
        }
    }
    
    // Aplicando o losango no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_octaedro[i][j] == 1) {
                int linha_tabuleiro = octaedro_origem_linha - centro_habilidade + i;
                int coluna_tabuleiro = octaedro_origem_coluna - centro_habilidade + j;
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = AREA_AFETADA;
                }
            }
        }
    }
// =========================================================================
// Novo fIM DO BLOCO DE HABILIDADES



    // -Tabuleiro Final
    printf("\n--- Tabuleiro Final ---\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%s ", coluna[j]); // Cabeçalho da coluna
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); //formatação para alinhar números de 1 e 2 dígitos
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            
            //IMPRESSÃOPARA INCLUIR A AREA_AFETADA
            if (tabuleiro[i][j] == AGUA) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == AREA_AFETADA) {
                printf("5 "); // Área Afetada
            }
        }
        printf("\n");
    }

    return 0;
}