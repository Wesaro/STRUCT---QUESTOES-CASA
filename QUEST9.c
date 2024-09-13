#include <stdio.h>

typedef struct {
    char nome[100];
    char esporte[50];
    int idade;
    float altura;
} Atleta;

int main() {
    Atleta atletas[5];
    int i;
    int atleta_mais_velho = 0;
    int atleta_mais_alto = 0;

    for (i = 0; i < 5; i++) {
        printf("Digite o nome do atleta %d: ", i + 1);
        fgets(atletas[i].nome, sizeof(atletas[i].nome), stdin);

        printf("Digite o esporte do atleta %d: ", i + 1);
        fgets(atletas[i].esporte, sizeof(atletas[i].esporte), stdin);

        printf("Digite a idade do atleta %d: ", i + 1);
        scanf("%d", &atletas[i].idade);

        printf("Digite a altura do atleta %d (em metros): ", i + 1);
        scanf("%f", &atletas[i].altura);

        getchar(); 
    }

    for (i = 1; i < 5; i++) {
        if (atletas[i].idade > atletas[atleta_mais_velho].idade) {
            atleta_mais_velho = i;
        }
        if (atletas[i].altura > atletas[atleta_mais_alto].altura) {
            atleta_mais_alto = i;
        }
    }

    printf("\nAtleta mais velho:\n");
    printf("Nome: %s", atletas[atleta_mais_velho].nome);
    printf("Idade: %d\n", atletas[atleta_mais_velho].idade);

    printf("\nAtleta mais alto:\n");
    printf("Nome: %s", atletas[atleta_mais_alto].nome);
    printf("Altura: %.2f metros\n", atletas[atleta_mais_alto].altura);

    return 0;
}
