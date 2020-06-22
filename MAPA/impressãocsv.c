#include <stdio.h>
#include <string.h>

//Função de Impressão do CSV
void process_field(int field_count, char *value) {
    if (field_count == 0) {
        printf("GID:\t");
    }
    if (field_count == 1) {
        printf("CO-CEP:\t");
    }
    if (field_count == 2) {
        printf("UF:\t");
    }
    if (field_count == 3) {
        printf("Cidade:\t");
    }
    if (field_count == 4) {
        printf("No-Fantasia:\t");
    }
    if (field_count == 5) {
        printf("No-Bairro:\t");
    }
    if (field_count == 6) {
        printf("Nu-Endereco:\t");
    }
    if (field_count == 7) {
        printf("No-Logradouro:\t");
    }
    if (field_count == 8) {
        printf("Nu-Telefone:\t");
    }
    if (field_count == 9) {
        printf("Ano-UPA-Func:\t");
    }
    if (field_count == 10) {
        printf("Mes-UPA-Func:\t");
    }
    if (field_count == 11) {
        printf("Fonte-Recurso:\t");
    }
    if (field_count == 12) {
        printf("Porte:\t");
    }
    printf("%s\n", value);
}

int main(void) {
    char buf[1024];
    char token[1024];

    int conta_linha = 0;
    int conta_coluna = 0;
    int token_pos = 0;
    int i = 0;

    //Abertura do Arquivo CSV
    FILE *fp = fopen("upaemfuncionamento.csv", "r");

    //Mensagem de Erro caso não seja possivel Abrir o Arquivo
    if (!fp) {
        printf("Não Foi Possivel Abrir o Arquivo\n");
        return 0;
    }


    while (fgets(buf, 1024, fp)) {
        conta_linha++;

        if (conta_linha == 1) {
            continue;
        }

        conta_coluna = 0;
        i = 0;
        do {
            token[token_pos++] = buf[i];

            if (buf[i] == ',' || buf[i] == '\n') {
                token[token_pos - 1] = 0;
                token_pos = 0;
                process_field(conta_coluna++, token);
            }

        } while (buf[++i]);

        printf("\n");
    }

    fclose(fp);

    return 0;
}
