#include <stdio.h>
#include <string.h>
#include <locale.h>
#define QTD_CARACTERES 200
#define QTD_VEICULOS 3


struct veiculo{
    char marca[QTD_CARACTERES];
    char modelo[QTD_CARACTERES];
    int ano_fabricacao;
    char placa[QTD_CARACTERES];
};

void menu(){
	printf("--->ESCOLHA UMA DAS OPÇÕES\n\n");
    printf("1. Listar veículos \n");
    printf("2. Inserir veículo \n");
    printf("3. Filtrar por ano \n");
    printf("4. Filtrar por ano igual ou maior \n");
    printf("5. Filtrar por modelo \n");
    printf("6. Finalizar programa \n\n");
    printf("--->Digite a opção desejada: \n");
}

int cadastrar_veiculo(struct veiculo *veiculos, int qtd_cadastros){

    if (qtd_cadastros == QTD_VEICULOS){
        return -1;
    }

    char marca[QTD_CARACTERES];
    char modelo[QTD_CARACTERES];
    int ano_fabricacao;
    char placa[QTD_CARACTERES];

    printf("Informe a marca: \n");
    scanf("%s", &marca);
    printf("Informe o modelo: \n");
    scanf("%s", &modelo);
    printf("Informe o ano de fabricação: \n");
    scanf("%d", &ano_fabricacao);
    printf("Informe a placa: \n");
    scanf("%s", &placa);

    if (qtd_cadastros == 0){
        memcpy(veiculos[qtd_cadastros].marca, marca, sizeof(marca));
        memcpy(veiculos[qtd_cadastros].modelo, modelo, sizeof(modelo));
        veiculos[qtd_cadastros].ano_fabricacao = ano_fabricacao;
        memcpy(veiculos[qtd_cadastros].placa, placa, sizeof(placa));


    }else{
        char temp_marca[QTD_CARACTERES], temp_modelo[QTD_CARACTERES], temp_placa[QTD_CARACTERES];
        int temp_ano_fabricacao;
        char temp_marca2[QTD_CARACTERES], temp_modelo2[QTD_CARACTERES], temp_placa2[QTD_CARACTERES];
        int temp_ano_fabricacao2;
        int find_pos = 0;

		int i;
        for (i = 0; i < qtd_cadastros; i++){


            if (find_pos == 0){
                if (ano_fabricacao <= veiculos[i].ano_fabricacao){
                    //indica que achamos a posição correta para a inserção
                    find_pos = 1;

                    //faz uma copia dos dados que já estavam naquela posição para que n perdermos eles
                    memcpy(temp_marca, veiculos[i].marca, sizeof(veiculos[i].marca));
                    memcpy(temp_modelo, veiculos[i].modelo, sizeof(veiculos[i].modelo));
                    temp_ano_fabricacao = veiculos[i].ano_fabricacao;
                    memcpy(temp_placa, veiculos[i].placa, sizeof(veiculos[i].placa));



                    //escreve os dados atuias na posição em questão
                    memcpy(veiculos[i].marca, marca, sizeof(marca));
                    memcpy(veiculos[i].modelo, modelo, sizeof(modelo));
                    veiculos[i].ano_fabricacao = ano_fabricacao;
                    memcpy(veiculos[i].placa, placa, sizeof(placa));

                    qtd_cadastros++;

                    continue;
                }
            }else{
                //processo para jogar tds os dados uma posição a frere


                //faz uma copia dos dados que já estavam naquela posição para que n perdermos eles
                memcpy(temp_marca2, veiculos[i].marca, sizeof(veiculos[i].marca));
                memcpy(temp_modelo2, veiculos[i].modelo, sizeof(veiculos[i].modelo));
                temp_ano_fabricacao2 = veiculos[i].ano_fabricacao;
                memcpy(temp_placa2, veiculos[i].placa, sizeof(veiculos[i].placa));

                //Salva os dados copiados da posição passada na posição atual
                memcpy(veiculos[i].marca, temp_marca, sizeof(temp_marca));
                memcpy(veiculos[i].modelo, temp_modelo, sizeof(temp_modelo));
                veiculos[i].ano_fabricacao = temp_ano_fabricacao;
                memcpy(veiculos[i].placa, temp_placa, sizeof(temp_placa));


                memcpy(temp_marca, temp_marca2, sizeof(temp_marca2));
                memcpy(temp_modelo, temp_modelo2, sizeof(temp_modelo2));
                temp_ano_fabricacao = temp_ano_fabricacao2;
                memcpy(temp_placa, temp_placa2, sizeof(temp_placa2));

            }
        }

        //Caso em que será adicionado na ultima posição do vetor
        if (find_pos == 0){
            memcpy(veiculos[qtd_cadastros].marca, marca, sizeof(marca));
            memcpy(veiculos[qtd_cadastros].modelo, modelo, sizeof(modelo));
            veiculos[qtd_cadastros].ano_fabricacao = ano_fabricacao;
            memcpy(veiculos[qtd_cadastros].placa, placa, sizeof(placa));
        }
    }

    return 1;

}

void listar_veiculos(struct veiculo *veiculos, int qtd_cadastros){
	
		int i;
    for (i = 0; i < qtd_cadastros; i++ ){
        printf("VEÍCULO: %d \n", i);
        printf("Marca: %s \n", veiculos[i].marca);
        printf("Modelo: %s \n", veiculos[i].modelo);
        printf("Ano: %d \n", veiculos[i].ano_fabricacao);
        printf("Placa: %s \n\n\n", veiculos[i].placa);
    }
}


void filtro_ano(struct veiculo *veiculos, int qtd_cadastros){

    int ano;

    printf("Informe o ano de fabricação para a busca: \n");
    scanf("%d", &ano);
    
	int i;
    for (i = 0; i < qtd_cadastros; i++ ){
        if  (veiculos[i].ano_fabricacao == ano){
            printf("VEÍCULO: %d \n", i);
            printf("Marca: %s \n", veiculos[i].marca);
            printf("Modelo: %s \n", veiculos[i].modelo);
            printf("Ano: %d \n", veiculos[i].ano_fabricacao);
            printf("Placa: %s \n\n\n", veiculos[i].placa);
        }

    }

}

void filtro_ano_igual_maior(struct veiculo *veiculos, int qtd_cadastros){

    int ano;

    printf("Informe o ano de fabricação para a busca: \n");
    scanf("%d", &ano);

	int i;
    for (i = 0; i < qtd_cadastros; i++ ){
        if  (veiculos[i].ano_fabricacao >= ano){
            printf("VEÍCULO: %d \n", i);
            printf("Marca: %s \n", veiculos[i].marca);
            printf("Modelo: %s \n", veiculos[i].modelo);
            printf("Ano: %d \n", veiculos[i].ano_fabricacao);
            printf("Placa: %s \n\n\n", veiculos[i].placa);
        }

    }

}


void filtro_modelo(struct veiculo *veiculos, int qtd_cadastros){

    char modelo[QTD_CARACTERES];

    printf("Informe o modelo para a busca: \n");
    scanf("%s", &modelo);
	
	int i;
    for (i = 0; i < qtd_cadastros; i++ ){
        if  (strcmp(veiculos[i].modelo, modelo) == 0){
            printf("VEÍCULO: %d \n", i);
            printf("Marca: %s \n", veiculos[i].marca);
            printf("Modelo: %s \n", veiculos[i].modelo);
            printf("Ano: %d \n", veiculos[i].ano_fabricacao);
            printf("Placa: %s \n\n\n", veiculos[i].placa);
        }
    }
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
    int opcao;
    int qtd_cadastros = 0;
    struct veiculo veiculos[QTD_VEICULOS];

    while (1){
        menu();
        scanf("%d", &opcao);

        if (opcao == 6){
            break;
        }else if (opcao > 6 || opcao < 1){
            printf("Opção não existe!");
        }else{
            if (opcao == 2){
                int cheq = cadastrar_veiculo(veiculos, qtd_cadastros);
                if (cheq == 1)
                    qtd_cadastros++;
                else
                    printf("Não há mais espaço para cadastrar! \n\n");


            }else if (opcao == 1){
                listar_veiculos(veiculos, qtd_cadastros);
            }else if (opcao == 3){
                filtro_ano(veiculos, qtd_cadastros);
            }else if (opcao == 4){
                filtro_ano_igual_maior(veiculos, qtd_cadastros);
            }else if (opcao == 5){
                filtro_modelo(veiculos, qtd_cadastros);
            }
        }
    }

}
