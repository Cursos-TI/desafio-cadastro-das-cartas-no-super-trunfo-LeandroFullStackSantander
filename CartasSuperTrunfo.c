#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 50

typedef struct {
    char estado;          // Estado: uma letra de 'A' a 'H'
    char codigo[5];      // Código da Carta: A01, B03, etc.
    char nomeCidade[100]; // Nome da Cidade
    int populacao;       // População da cidade
    float area;          // Área em km²
    float pib;           // PIB da cidade
    int pontosTuristicos;// Número de Pontos Turísticos
} Carta;

void inserirDados(Carta *carta) {
    printf("Insira o estado (A-H): ");
    scanf(" %c", &carta->estado);
    
    printf("Insira o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    printf("Insira o nome da cidade: ");
    getchar(); // Limpa o buffer para evitar problemas com fgets
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0; // Remove a nova linha

    printf("Insira a população: ");
    scanf("%d", &carta->populacao);
    
    printf("Insira a área (em km²): ");
    scanf("%f", &carta->area);
    
    printf("Insira o PIB: ");
    scanf("%f", &carta->pib);
    
    printf("Insira o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void exibirDados(Carta carta) {
    printf("\nDados da Carta:\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    Carta cartas[2];

    for (int i = 0; i < 2; i++) {
        printf("\n--- Inserindo dados da carta %d ---\n", i + 1);
        inserirDados(&cartas[i]);
    }

    for (int i = 0; i < 2; i++) {
        exibirDados(cartas[i]);
    }

    return 0;
}
