#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    Data dataNascimento;
} Pessoa;

int dataMaisRecente(Data d1, Data d2) {
    if (d1.ano > d2.ano) return 1;
    if (d1.ano < d2.ano) return 0;
    if (d1.mes > d2.mes) return 1;
    if (d1.mes < d2.mes) return 0;
    return d1.dia > d2.dia;
}

int main() {
    Pessoa pessoas[6];
    int i;
    int mais_nova = 0;
    int mais_velha = 0;

    for (i = 0; i < 6; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);

        printf("Digite a data de nascimento da pessoa %d (dd mm aaaa): ", i + 1);
        scanf("%d %d %d", &pessoas[i].dataNascimento.dia, &pessoas[i].dataNascimento.mes, &pessoas[i].dataNascimento.ano);

        getchar();  
    }

    for (i = 1; i < 6; i++) {
        if (dataMaisRecente(pessoas[i].dataNascimento, pessoas[mais_nova].dataNascimento)) {
            mais_nova = i;
        }
        if (!dataMaisRecente(pessoas[i].dataNascimento, pessoas[mais_velha].dataNascimento) && !dataMaisRecente(pessoas[mais_velha].dataNascimento, pessoas[i].dataNascimento)) {
            mais_velha = i;
        }
    }

    printf("\nPessoa mais nova:\n");
    printf("Nome: %s", pessoas[mais_nova].nome);

    printf("\nPessoa mais velha:\n");
    printf("Nome: %s", pessoas[mais_velha].nome);

    return 0;
}
