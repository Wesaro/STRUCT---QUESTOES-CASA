#include <stdio.h>

typedef struct {
    int matricula;
    char nome[100];
    float notas[3];
} Aluno;

float calcularMedia(Aluno a) {
    return (a.notas[0] + a.notas[1] + a.notas[2]) / 3.0;
}

int main() {
    Aluno alunos[5];
    int i, aluno_com_maior_media = 0;
    float maior_media = 0;

    for (i = 0; i < 5; i++) {
        printf("Digite o número de matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        getchar();  // Limpa o buffer do '\n'

        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';  

        printf("Digite a nota da primeira prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notas[0]);

        printf("Digite a nota da segunda prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notas[1]);

        printf("Digite a nota da terceira prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notas[2]);

        getchar(); 
    }


    for (i = 0; i < 5; i++) {
        float media = calcularMedia(alunos[i]);
        if (media > maior_media) {
            maior_media = media;
            aluno_com_maior_media = i;
        }
    }


    printf("\nAluno com a maior média:\n");
    printf("Nome: %s\n", alunos[aluno_com_maior_media].nome);
    printf("Notas: %.2f, %.2f, %.2f\n",
           alunos[aluno_com_maior_media].notas[0],
           alunos[aluno_com_maior_media].notas[1],
           alunos[aluno_com_maior_media].notas[2]);

    return 0;
}
