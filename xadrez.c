#include <stdio.h>

// Defino quantas casas cada peça vai se mover no meu programa
#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8
#define CASAS_CAVALO_VERTICAL 2
#define CASAS_CAVALO_HORIZONTAL 1

// Função que faz a torre se mover usando recursão
// A torre só anda em linha reta, então estou fazendo ela ir pra direita
void mover_torre_recursivo(int casas_restantes) {
    // Se já andou todas as casas, para de chamar a função
    if (casas_restantes <= 0) {
        return;
    }
    
    printf("Direita\n");
    
    // Chama ela mesma com uma casa a menos - uma recursão
    mover_torre_recursivo(casas_restantes - 1);
}

void mover_torre() {
    printf("=== MOVIMENTO DA TORRE ===\n");
    printf("Torre movendo %d casas para a direita:\n", CASAS_TORRE);
    
    mover_torre_recursivo(CASAS_TORRE);
    printf("\n");
}

// O bispo anda na diagonal, então vou fazer ele ir pra "cima direita"
void mover_bispo_vertical_recursivo(int movimentos_verticais, int movimentos_horizontais) {
    if (movimentos_verticais <= 0) {
        return;
    }
    
    // Para cada movimento vertical, faz um movimento horizontal também (diagonal)
    for (int horizontal = 0; horizontal < movimentos_horizontais; horizontal++) {
        printf("Cima Direita\n");
    }
    
    mover_bispo_vertical_recursivo(movimentos_verticais - 1, movimentos_horizontais);
}

void mover_bispo() {
    printf("=== MOVIMENTO DO BISPO ===\n");
    printf("Bispo movendo %d casas na diagonal (cima e direita):\n", CASAS_BISPO);
    
    mover_bispo_vertical_recursivo(CASAS_BISPO, 1);
    printf("\n");
}

// A rainha pode andar para qualquer direção, ela vai andar pra esquerda
void mover_rainha_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return;
    }
    
    printf("Esquerda\n");
    
    mover_rainha_recursivo(casas_restantes - 1);
}

void mover_rainha() {
    printf("=== MOVIMENTO DA RAINHA ===\n");
    printf("Rainha movendo %d casas para a esquerda:\n", CASAS_RAINHA);
    
    mover_rainha_recursivo(CASAS_RAINHA);
    printf("\n");
}

// O cavalo é o mais complicado - ele anda em "L"
// Primeiro 2 casas para cima, depois 1 casa para direita

void mover_cavalo() {
    printf("=== MOVIMENTO DO CAVALO ===\n");
    printf("Cavalo movendo em 'L' (%d casas para cima, %d casa para direita):\n", 
           CASAS_CAVALO_VERTICAL, CASAS_CAVALO_HORIZONTAL);
    
    int fase_movimento = 1;
    int total_movimentos_executados = 0;
    int max_movimentos_total = CASAS_CAVALO_VERTICAL + CASAS_CAVALO_HORIZONTAL;
    
    // Uso um loop para controlar as 2 fases do movimento em L
    for (int ciclo = 1; ciclo <= 2; ciclo++) {
        
        int movimentos_fase_atual = 0;
        int limite_movimentos_fase = 0;
        
        if (ciclo == 1) {
            // Primeira fase: vai para cima
            limite_movimentos_fase = CASAS_CAVALO_VERTICAL;
            fase_movimento = 1;
        } else {
            // Segunda fase: vai para direita
            limite_movimentos_fase = CASAS_CAVALO_HORIZONTAL;
            fase_movimento = 2;
        }
        
        while (movimentos_fase_atual < limite_movimentos_fase) {
            
            if (total_movimentos_executados >= max_movimentos_total) {
                break;
            }
            
            if (fase_movimento == 1) {
                printf("Cima\n");
                movimentos_fase_atual++;
                total_movimentos_executados++;
                
                if (movimentos_fase_atual == limite_movimentos_fase) {
                    continue;
                }
                
            } else if (fase_movimento == 2) {
                printf("Direita\n");
                movimentos_fase_atual++;
                total_movimentos_executados++;
                
                if (movimentos_fase_atual == limite_movimentos_fase) {
                    break;
                }
            }
        }
        
        if (total_movimentos_executados >= max_movimentos_total) {
            break;
        }
    }
    printf("\n");
}

// Função principal - chama todas as outras funções para mostrar os movimentos
int main() {
    printf("SIMULADOR AVANÇADO DE MOVIMENTACAO DE PECAS DE XADREZ\n");
    printf("====================================================\n\n");
    
    mover_torre();
    mover_bispo();
    mover_rainha();
    mover_cavalo();
    
    printf("Simulacao avançada concluida com sucesso!\n");
    
    return 0;
}

// - Esse código foi feito até o "Nível Mestre"!