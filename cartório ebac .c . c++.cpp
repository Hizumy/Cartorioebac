#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(file, "%s,", cpf);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    fprintf(file, "%s,", nome);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    fprintf(file, "%s,", sobrenome);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    fprintf(file, "%s", cargo);

    fclose(file);
    printf("Registro salvo com sucesso.\n");

    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
        return 1;
    }

    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("\nEssas s�o informa��es sobre o usu�rio:\n");
        printf("%s", conteudo);
    }

    fclose(file);
    return 0;
}

int deletar() {
    char cpf[40];
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Arquivo deletado com sucesso.\n");
    } else {
        printf("Erro ao deletar o arquivo. Ele pode n�o existir.\n");
    }
    return 0;
}

int main() {
    int opcao = 0;

    setlocale(LC_ALL, "Portuguese");

    while (1) {
        printf("### Cart�rio da Ebac ###\n\n");
        printf("Escolha a op��o desejada no menu:\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Op��o: ");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            default:
                printf("Esta op��o n�o est� dispon�vel\n");
                system("pause");
                break;
        }
    }

    return 0;
}

