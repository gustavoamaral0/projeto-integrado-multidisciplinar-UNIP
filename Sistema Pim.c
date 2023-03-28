#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char nome[100], doc[20], telefone[15], email[50], hora[6];
    int dia, mes, ano;
}FichaVisita;

typedef struct{
    char nome[100], doc[20], telefone[15], email[50], hora[6], motivo[200];
    int dia, mes, ano;
}FichaReuniao;

typedef struct{
    char nome[100], telefone[20], endereco[50], registro[5];
    int dia, mes, ano;
}funcionario;

int CadastroVisita(FichaVisita *p, int n, int i){
    int op, verif;

    do{
        printf("\n\tAGENDAMENTO DE VISITA\n\n");
        fflush(stdin);
        printf("Informe o nome da(o) %iº pessoa: ", i+1);
        gets((p+i)->nome);
        printf("Informe o documento do(a) %s: ", (p+i)->nome);
        gets((p+i)->doc);
        printf("Informe o telefone de contado com o (DDD) do(a) %s: ", (p+i)->nome);
        gets((p+i)->telefone);
        printf("Informe o e-mail do(a) %s: ", (p+i)->nome);
        gets((p+i)->email);
        printf("Dia da visita: ");
        scanf("%i", &(p+i)->dia);
        printf("Mês: ");
        scanf("%i", &(p+i)->mes);
        printf("Ano: ");
        scanf("%i", &(p+i)->ano);
        printf("Horário: ");
        scanf("%s", &(p+i)->hora);
        i++;
        printf("\n----------------------------------------------------------\n\n");

        do{
            printf("\nDeseja continuar cadastrando? S(sim), N(não): ");
            verif = getche();
            verif = tolower(verif);
            fflush(stdin);
            system("cls");
            if(verif != 's' && verif != 'n')
                printf("\nOpção Inválida. Escolha a opção novamente!\n");
        }while(verif != 's' && verif != 'n');
        system("cls");

    }while(verif == 's');

    return i;
}


int CadastroReuniao(FichaReuniao *q, int n, int j){
    int verif;

    do{
        printf("\n\tAGENDAMENTO DE REUNIÃO\n\n");
        fflush(stdin);
        printf("Informe o %iº nome: ", j+1);
        gets((q+j)->nome);
        printf("Informe o documento do(a) %s: ", (q+j)->nome);
        gets((q+j)->doc);
        printf("Informe o telefone de contado com o (DDD) do(a) %s: ", (q+j)->nome);
        gets((q+j)->telefone);
        printf("Informe o e-mail do(a) %s: ", (q+j)->nome);
        gets((q+j)->email);
        printf("Dia da visita: ");
        scanf("%i", &(q+j)->dia);
        printf("Mês: ");
        scanf("%i", &(q+j)->mes);
        printf("Ano: ");
        scanf("%i", &(q+j)->ano);
        printf("Horário: ");
        scanf("%s", &(q+j)->hora);
        fflush(stdin);
        printf("Infome o motivo da reunião: ");
        gets((q+j)->motivo);
        j++;
        printf("\n----------------------------------------------------------\n\n");

        do{
            printf("\nDeseja continuar cadastrando? S(sim), N(não): ");
            verif = getche();
            verif = tolower(verif);
            fflush(stdin);
            system("cls");
            if(verif != 's' && verif != 'n')
                printf("\nOpção Inválida. Escolha a opção novamente!\n");
        }while(verif != 's' && verif != 'n');
        system("cls");

    }while(verif == 's');

    return j;
}


int CadastroFuncionario(funcionario *r, int m, int y){
    int op, soma;
    char verif;

    do{
        printf("\n\tCADASTRO DE FUNCIONÁRIO\n\n");
        fflush(stdin);
        printf("Informe o %iº nome: ", y+1);
        gets((r+y)->nome);
        printf("Informe o telefone de contado com o (DDD) do(a) %s: ", (r+y)->nome);
        gets((r+y)->telefone);
        printf("Informe o endereço do(a) %s: ", (r+y)->nome);
        gets((r+y)->endereco);
        printf("Dia de entrada: ");
        scanf("%i", &(r+y)->dia);
        printf("Mês de entrada: ");
        scanf("%i", &(r+y)->mes);
        printf("Ano de entrada: ");
        scanf("%i", &(r+y)->ano);
        fflush(stdin);
        printf("Informe o numero de Registro do(a) %s da seguinte forma (as 2 primereira letra do nome, mais o numero de entrdada: ", (r+y)->nome);
        gets((r+y)->registro);
        y++;
        printf("\n----------------------------------------------------------\n\n");

        do{
            printf("\nDeseja continuar cadastrando? S(sim), N(não): ");
            verif = getche();
            verif = tolower(verif);
            fflush(stdin);
            system("cls");
            if(verif != 's' && verif != 'n')
                printf("\nOpção Inválida. Escolha a opção novamente!\n");
        }while(verif != 's' && verif != 'n');
        system("cls");

    }while(verif == 's');
    system("cls");

return y;
}


void VisualizarReuniao(FichaReuniao *q, int n, int j){
     int op, verif, dia, mes, ano, tip, aux;
     bool achou = false;
	 aux = j; // guarda a posção de j em aux para quando voltar pro programa principal nao perder a referencia de i;

     do{
        printf("\n\tVISUALIZAÇÃO DOS AGENDAMENTOS DE REUNIÕES!!\n");
        printf("\n[1] Busca por Data.");
        printf("\n[2] Visualizar todas as reuniões.");
        printf("\n[0] Voltar ao Menu.");
        printf("\n\n----------------------------------------------------------\n\n");
        printf("\nEscolha uma opção: ");
        scanf("%i", &op);
        fflush(stdin);
        system("cls");

        switch(op){
            case 1: printf("\n\tBUSCA POR DATA\n");
                    printf("\nDica: Informe uma data neste modelo: 11/11/2022\n\n");
                    printf("Digite o dia: ");
                    scanf("%i", &dia);
                    printf("Digite o mês: ");
                    scanf("%i", &mes);
                    printf("Digite o ano: ");
                    scanf("%i", &ano);
                    fflush(stdin);
                    system("cls");
                    achou = false;

                    printf("\n\tVISUALIZAR AGENDA DO DIA %i/%i/%i\n\n", dia, mes, ano);
                    for (j = 0; j < aux; j++){
                        if ((q+j)->dia == dia && (q+j)->mes == mes && (q+j)->ano == ano){
                            printf("Nome: %s\n", (q+j)->nome);
                            printf("Documento: %s\n", (q+j)->doc);
                            printf("Telefone: %s\n", (q+j)->telefone);
                            printf("E-mail: %s\n", (q+j)->email);
                            printf("Agendado para: %i/%i/%i as %s horas\n", (q+j)->dia, (q+j)->mes, (q+j)->ano, (q+j)->hora);
                            printf("\n----------------------------------------------------------\n\n");
                            achou = true;
                        }
                    }
                    if(achou == false)
                        printf("Nenhum agendamento para a data escolhida\n\n");

                    system("pause");
                    system("cls");
                    break;

            case 2: for (j = 0; j < aux ; j++){
                        printf("Nome: %s\n", (q+j)->nome);
                        printf("Documento: %s\n", (q+j)->doc);
                        printf("Telefone: %s\n", (q+j)->telefone);
                        printf("E-mail: %s\n", (q+j)->email);
                        printf("Agendado para: %i/%i/%i as %s hora\n", (q+j)->dia, (q+j)->mes, (q+j)->ano, (q+j)->hora);
                        printf("O motivo da reunião é: %s\n", (q+j)->motivo);
                        printf("\n----------------------------------------------------------\n\n");
                     }

             system("pause");
             system("cls");
          }
     }while(op != 0);
}


void VisualizarVisita(FichaVisita *p, int n, int i){
    int op, verif, dia, mes, ano, tip, aux;
    bool achou = false;
    aux = i; // guarda a posção de i em aux para quando voltar pro programa principal nao perder a referencia de i;

    do{
        printf("\n\tVISUALIZAÇÃO DOS AGENDAMENTOS DE VISITAS!!\n");
        printf("\n[1] Busca por Data.");
        printf("\n[2] Visualizar todas as visitas cadastradas.");
        printf("\n[0] Voltar ao Menu.");
        printf("\n\n----------------------------------------------------------\n\n");
        printf("\nEscolha uma opção: ");
        scanf("%i", &op);
        fflush(stdin);
        system("cls");

        switch(op){
            case 1: printf("\n\tBUSCA POR DATA\n");
                    printf("\nDica: Informe uma data neste modelo: 11/11/2022\n\n");
                    printf("Digite o dia: ");
                    scanf("%i", &dia);
                    printf("Digite o mês: ");
                    scanf("%i", &mes);
                    printf("Digite o ano: ");
                    scanf("%i", &ano);
                    fflush(stdin);
                    system("cls");
                    achou = false;

                    printf("\n\tVISUALIZAR AGENDA DO DIA %i/%i/%i\n\n", dia, mes, ano);
                    for (i = 0; i < aux; i++){
                        if ((p+i)->dia == dia && (p+i)->mes == mes && (p+i)->ano == ano){
                            printf("Nome: %s\n", (p+i)->nome);
                            printf("Documento: %s\n", (p+i)->doc);
                            printf("Telefone: %s\n", (p+i)->telefone);
                            printf("E-mail: %s\n", (p+i)->email);
                            printf("Agendado para: %i/%i/%i as %s horas\n", (p+i)->dia, (p+i)->mes, (p+i)->ano, (p+i)->hora);
                            printf("\n----------------------------------------------------------\n\n");
                            achou = true;
                        }
                    }
                    if(achou == false)
                        printf("Nenhum agendamento para a data escolhida\n\n");

                    system("pause");
                    system("cls");
                    break;



            case 2: for (i = 0; i < aux ; i++){
                        printf("\nNome: %s\n", (p+i)->nome);
                        printf("Documento: %s\n", (p+i)->doc);
                        printf("Telefone: %s\n", (p+i)->telefone);
                        printf("E-mail: %s\n", (p+i)->email);
                        printf("Agendado para: %i/%i/%i as %s horas\n", (p+i)->dia, (p+i)->mes, (p+i)->ano, (p+i)->hora);
                        printf("\n----------------------------------------------------------\n\n");
                    }

            system("pause");
            system("cls");
        }

     }while(op != 0);
}


void VisualizarFuncionario(funcionario *r, int m, int y){
    int op, verif, dia, mes, ano, tip, aux;
    bool achou = false;
    aux = y; // guarda a posção de y em aux para quando voltar pro programa principal nao perder a referencia de i;

    do{
        printf("\n\tVISUALIZAÇÃO DOS FUNCIONARIOS\n");
        printf("\n[1] Busca por Data");
        printf("\n[2] Visualizar todos os funcionarios cadastradas");
        printf("\n[0] Voltar ao Menu");
        printf("\n\n----------------------------------------------------------\n\n");
        printf("\nEscolha uma opção: ");
        scanf("%i", &op);
        fflush(stdin);
        system("cls");

        switch(op){
            case 1: printf("\n\tBUSCA POR DATA\n");
                    printf("\nDica: Informe uma data neste modelo: 11/11/2022\n\n");
                    printf("Digite o dia: ");
                    scanf("%i", &dia);
                    printf("Digite o mês: ");
                    scanf("%i", &mes);
                    printf("Digite o ano: ");
                    scanf("%i", &ano);
                    fflush(stdin);
                    system("cls");
                    achou = false;

                    printf("\n\tVISUALIZAR FUNCIONARIOS CONTRATAODS NO DIA %i/%i/%i\n\n", dia, mes, ano);
                    for (y = 0; y < aux; y++){
                        if ((r+y)->dia == dia && (r+y)->mes == mes && (r+y)->ano == ano){
                            printf("\nNome: %s\n", (r+y)->nome);
                            printf("Numero de Registro: %s\n", (r+y)->registro);
                            printf("Endereço: %s\n", (r+y)->endereco);
                            printf("Telefone: %s\n", (r+y)->telefone);
                            printf("Data de entrada: %i/%i/%i\n", (r+y)->dia, (r+y)->mes, (r+y)->ano);
                            printf("\n----------------------------------------------------------\n\n");
                            achou = true;
                        }
                    }
                    if(achou == false)
                        printf("Nenhum agendamento para a data escolhida\n\n");

                    system("pause");
                    system("cls");
                    break;

            case 2: for (y = 0; y < aux ; y++){
                    printf("\nNome: %s\n", (r+y)->nome);
                    printf("Numero de Registro: %s\n", (r+y)->registro);
                    printf("Endereço: %s\n", (r+y)->endereco);
                    printf("Telefone: %s\n", (r+y)->telefone);
                    printf("Data de entrada: %i/%i/%i\n", (r+y)->dia, (r+y)->mes, (r+y)->ano);
                    printf("\n----------------------------------------------------------\n\n");
                   }

            system("pause");
            system("cls");
        }

     }while(op != 0);
}


int BuscarDocVisita(FichaVisita *p, int n, int i, int opcao){
	char doc[20];
	int op, aux, verif;
	bool achou = false;
	aux = i; // guarda a posção de i em aux para quando voltar pro programa principal nao perder a referencia de i;

	printf("\n\tBUSCA POR CPF/CNPJ\n");
	printf("\nInforme o número do documento: ");
	gets(doc);
    system("cls");

	for (i = 0; i <= aux && achou == false; i++){
		if (strcmp(doc, (p+i)->doc) == 0){
			achou = true;
            printf("\n\tBUSCA POR CPF/CNPJ\n\n");
            printf("Nome: %s\n", (p+i)->nome);
            printf("Documento: %s\n", (p+i)->doc);
            printf("Telefone: %s\n", (p+i)->telefone);
            printf("E-mail: %s\n", (p+i)->email);
            printf("Agendado para dia %i/%i/%i as %s\n", (p+i)->dia, (p+i)->mes, (p+i)->ano, (p+i)->hora);
		}
	}
	i--; // i esta ganhando uma posição, entao volta uma posição


    if (achou == false){
        printf("\nDocumento %s não encontrado. Informe um documento válido! \n\n", doc);
        system("pause");
    }

    else{
        do{
            printf("\n----------------------------------------------------------\n\n");
            printf("\nDeseja editar? S(sim), N(não).");
            verif = getche();
            verif = tolower(verif);
            fflush(stdin);
            system("cls");
            if(verif != 's' && verif != 'n')
                printf("\nOpção Inválida. Escolha a opção novamente!\n");
        }while(verif != 's' && verif != 'n');
        system("cls");
    }

    if(verif == 's'){
        do{
            fflush(stdin);
            printf("\n\tEditar Dados\n");
            printf("\n----------------------------------------------------------\n\n");
            printf("Nome: %s\n", (p+i)->nome);
            printf("Documento: %s\n", (p+i)->doc);
            printf("Telefone: %s\n", (p+i)->telefone);
            printf("E-mail: %s\n", (p+i)->email);
            printf("Agendado para dia %i/%i/%i as %s\n", (p+i)->dia, (p+i)->mes, (p+i)->ano, (p+i)->hora);
            printf("\n----------------------------------------------------------\n\n");

            printf("Qual dado quer editar:\n");
            printf("[1] Editar Nome\n");
            printf("[2] Editar Documento\n");
            printf("[3] Editar Telefone\n");
            printf("[4] Editar E-mail\n");
            printf("[5] Editar Data\n");
            printf("[0] Sair\n");
            printf("\n----------------------------------------------------------\n\n");
            printf("\nEscolha uma opção: ");
            scanf("%i", &op);
            system("cls");

            switch (op){
                case 1: fflush(stdin);
                        printf("\nInforme o novo nome: ");
                        gets((p+i)->nome);
                        system("cls");
                        break;

                case 2: fflush(stdin);
                        printf("\nInforme o novo documento do(a) %s: ", (p+i)->nome);
                        gets((p+i)->doc);
                        system("cls");
                        break;

                case 3: fflush(stdin);
                        printf("\nInforme o novo telefone de contado com o (DDD) do(a) %s: ", (p+i)->nome);
                        gets((p+i)->telefone);
                        system("cls");
                        break;

                case 4: fflush(stdin);
                        printf("\nInforme o novo e-mail do(a) %s: ", (p+i)->nome);
                        gets((p+i)->email);
                        system("cls");
                        break;

                case 5: fflush(stdin);
                        printf("\nInforme o novo dia: ");
                        scanf("%i", &(p+i)->dia);
                        printf("\nMês: ");
                        scanf("%i", &(p+i)->mes);
                        printf("\nAno: ");
                        scanf("%i", &(p+i)->ano);
                        printf("\nHorário: ");
                        scanf("%s", &(p+i)->hora);
                        system("cls");
                        break;

                case 0: printf("\n\tDados alterados com Sucesso\n\n");
                        printf("\nNome: %s\n", (p+i)->nome);
                        printf("Documento: %s\n", (p+i)->doc);
                        printf("Telefone: %s\n", (p+i)->telefone);
                        printf("E-mail: %s\n", (p+i)->email);
                        printf("Agendado para dia %i/%i/%i as %s\n", (p+i)->dia, (p+i)->mes, (p+i)->ano, (p+i)->hora);
                        printf("\n----------------------------------------------------------\n\n");
                        break;

                default: printf("\nEssa opção não existe. Escolha uma opção válida!");
            }

        }while(op != 0);

        system("pause");
    }

    system("cls");
    i = aux; //retorna a posição de aux para i, pois foi inicializado i com 0 dentro do for
    return i;
}


int BuscarDocReuniao(FichaReuniao *q, int n, int j, int opcao){
	char doc[20], verif;
	int op, aux;
	bool achou = false;
	aux = j; // guarda a posção de j em aux para quando voltar pro programa principal nao perder a referencia de i;

	printf("\n\tBUSCA POR CPF/CNPJ\n");
	printf("\nInforme o número do documento: ");
	gets(doc);
    system("cls");

	for (j = 0; j <= aux && achou == false; j++){
		if (strcmp(doc, (q+j)->doc) == 0){
			achou = true;
            printf("\n\tBUSCA POR CPF/CNPJ\n\n");
            printf("Nome: %s\n", (q+j)->nome);
            printf("Documento: %s\n", (q+j)->doc);
            printf("Telefone: %s\n", (q+j)->telefone);
            printf("E-mail: %s\n", (q+j)->email);
            printf("Agendado para dia %i/%i/%i as %s", (q+j)->dia, (q+j)->mes, (q+j)->ano, (q+j)->hora);
            printf("\nO motivo da reunião é: %s\n\n", (q+j)->motivo);
		}
	}
	j--; // j esta ganhando uma posição, entao volta uma posição


    if (achou == false){
        printf("\nDocumento %s não encontrado. Informe um documento válido! \n\n", doc);
        system("pause");
    }

    else{
        do{
            printf("\n----------------------------------------------------------\n\n");
            printf("\nDeseja editar? S(sim), N(não).");
            verif = getche();
            verif = tolower(verif);
            fflush(stdin);
            system("cls");
            if(verif != 's' && verif != 'n')
                printf("\nOpção Inválida. Escolha a opção novamente!\n");
        }while(verif != 's' && verif != 'n');
        system("cls");
    }

    if(verif == 's'){
        do{
            fflush(stdin);
            printf("\n\tEditar Dados\n");
            printf("\n----------------------------------------------------------\n\n");
            printf("Nome: %s\n", (q+j)->nome);
            printf("Documento: %s\n", (q+j)->doc);
            printf("Telefone: %s\n", (q+j)->telefone);
            printf("E-mail: %s\n", (q+j)->email);
            printf("Agendado para dia %i/%i/%i as %s", (q+j)->dia, (q+j)->mes, (q+j)->ano, (q+j)->hora);
            printf("\nO motivo da reunião é:%s\n", (q+j)->motivo);
            printf("\n----------------------------------------------------------\n\n");

            printf("Qual dado quer editar:\n");
            printf("[1] Editar Nome\n");
            printf("[2] Editar Documento\n");
            printf("[3] Editar Telefone\n");
            printf("[4] Editar E-mail\n");
            printf("[5] Editar Data\n");
            printf("[0] Sair\n");
            printf("\n----------------------------------------------------------\n\n");
            printf("\nEscolha uma opção: ");
            scanf("%i", &op);
            system("cls");

            switch (op){
                case 1: fflush(stdin);
                        printf("\nInforme o novo nome: ");
                        gets((q+j)->nome);
                        system("cls");
                        break;

                case 2: fflush(stdin);
                        printf("\nInforme o novo documento do(a) %s: ", (q+j)->nome);
                        gets((q+j)->doc);
                        system("cls");
                        break;

                case 3: fflush(stdin);
                        printf("\nInforme o novo telefone de contado com o (DDD) do(a) %s: ", (q+j)->nome);
                        gets((q+j)->telefone);
                        system("cls");
                        break;

                case 4: fflush(stdin);
                        printf("\nInforme o novo e-mail do(a) %s: ", (q+j)->nome);
                        gets((q+j)->email);
                        system("cls");
                        break;

                case 5: fflush(stdin);
                        printf("\nInforme o novo dia: ");
                        scanf("%i", &(q+j)->dia);
                        printf("\nMês: ");
                        scanf("%i", &(q+j)->mes);
                        printf("\nAno: ");
                        scanf("%i", &(q+j)->ano);
                        printf("\nHorário: ");
                        scanf("%s", &(q+j)->hora);
                        system("cls");
                        break;

                case 0: printf("\n\tDados alterados com Sucesso\n\n");
                        printf("\n\nNome: %s\n", (q+j)->nome);
                        printf("Documento: %s\n", (q+j)->doc);
                        printf("Telefone: %s\n", (q+j)->telefone);
                        printf("E-mail: %s\n", (q+j)->email);
                        printf("Agendado para dia %i/%i/%i as %s", (q+j)->dia, (q+j)->mes, (q+j)->ano, (q+j)->hora);
                        printf("\nO motivo da reunião é:%s\n", (q+j)->motivo);
                        printf("\n----------------------------------------------------------\n\n");
                        break;

                default: printf("\nEssa opção não existe. Escolha uma opção válida!");
            }

        }while(op != 0);

        system("pause");
    }

    system("cls");
    j = aux; //retorna a posição de aux para j, pois foi inicializado j com 0 dentro do for
    return j;
}


int BuscarReFuncionario(funcionario *r, int m, int y, int opcao){
    char doc[20];
	int op, aux, verif;
	bool achou = false;
	aux = y; // guarda a posção de y em aux para quando voltar pro programa principal nao perder a referencia de i;

	printf("\n\tBUSCA POR RE DE FUNCIONARIO\n");
	printf("\nInforme o número do RE: ");
	gets(doc);
    system("cls");

	for (y = 0; y <= aux && achou == false; y++){
		if (strcmp(doc, (r+y)->registro) == 0){
			achou = true;
            printf("\n\tBUSCA POR RE DE FUNCIONARIO\n\n");
            printf("Nome: %s.\n", (r+y)->nome);
            printf("Numero de Registro: %s.\n", (r+y)->registro);
            printf("Endereço: %s.\n", (r+y)->endereco);
            printf("Telefone: %s.\n", (r+y)->telefone);
            printf("Data de entrada %i/%i/%i.\n\n", (r+y)->dia, (r+y)->mes, (r+y)->ano);
		}
	}
	y--; // j esta ganhando uma posição, entao volta uma posição


    if (achou == false){
        printf("\nDocumento %s não encontrado. Informe um documento válido! \n\n", doc);
        system("pause");
    }

    else{
        do{
            printf("\n----------------------------------------------------------\n\n");
            printf("\nDeseja editar? S(sim), N(não).");
            verif = getche();
            verif = tolower(verif);
            fflush(stdin);
            system("cls");
            if(verif != 's' && verif != 'n')
                printf("\nOpção Inválida. Escolha a opção novamente!\n");
        }while(verif != 's' && verif != 'n');
        system("cls");
    }

    if(verif == 's'){
        do{
            fflush(stdin);
            printf("\n\tEditar Dados\n");
            printf("\n----------------------------------------------------------\n\n");
            printf("Nome: %s.\n", (r+y)->nome);
            printf("Numero de Registro: %s.\n", (r+y)->registro);
            printf("Endereço: %s.\n", (r+y)->endereco);
            printf("Telefone: %s.\n", (r+y)->telefone);
            printf("Data de entrada %i/%i/%i.\n", (r+y)->dia, (r+y)->mes, (r+y)->ano);
            printf("\n----------------------------------------------------------\n\n");

            printf("Qual dado quer editar:\n");
            printf("[1] Editar Nome\n");
            printf("[2] Editar número de Registro\n");
            printf("[3] Editar Endereço\n");
            printf("[4] Editar Telefone\n");
            printf("[5] Editar Data de entrada\n");
            printf("[0] Sair\n");
            printf("\n----------------------------------------------------------\n\n");
            printf("\nEscolha uma opção: ");
            scanf("%i", &op);
            system("cls");

            switch (op){
                case 1: fflush(stdin);
                        printf("\nInforme o novo nome: ");
                        gets((r+y)->nome);
                        system("cls");
                        break;

                case 2: fflush(stdin);
                        printf("\nInforme o novo numero de registro do(a) %s: ", (r+y)->nome);
                        gets((r+y)->registro);
                        system("cls");
                        break;

                case 3: fflush(stdin);
                        printf("\nInforme o novo telefone de contado com o (DDD) do(a) %s: ", (r+y)->nome);
                        gets((r+y)->telefone);
                        system("cls");
                        break;

                case 4: fflush(stdin);
                        printf("\nInforme o novo endereço do(a) %s: ", (r+y)->nome);
                        gets((r+y)->endereco);
                        system("cls");
                        break;

                case 5: fflush(stdin);
                        printf("\nInforme o novo dia: ");
                        scanf("%i", &(r+y)->dia);
                        printf("\nMês: ");
                        scanf("%i", &(r+y)->mes);
                        printf("\nAno: ");
                        scanf("%i", &(r+y)->ano);
                        system("cls");
                        break;

                case 0: printf("\n\tDados alterados com Sucesso\n\n");
                        printf("\n\nNome: %s.\n", (r+y)->nome);
                        printf("Numero de Registro: %s.\n", (r+y)->registro);
                        printf("Endereço: %s.\n", (r+y)->endereco);
                        printf("Telefone: %s.\n", (r+y)->telefone);
                        printf("Data de entrada %i/%i/%i.\n", (r+y)->dia, (r+y)->mes, (r+y)->ano);
                        printf("\n----------------------------------------------------------\n\n");
                        break;

                default: printf("\nEssa opção não existe. Escolha uma opção válida!");
            }

        }while(op != 0);

        system("pause");
    }

    system("cls");
    y = aux; //retorna a posição de aux para j, pois foi inicializado j com 0 dentro do for
    return y;
}


void main(){
    setlocale(LC_ALL, "Portuguese");
    FichaVisita *p;
    FichaReuniao *q;
    funcionario *r;
    int n = 1000, m = 100, opcao, i = 0, j = 0, y =0, a, c;
    char verif, usuario[50], senha[50], sair[5];

    p = malloc(n * sizeof(FichaVisita));
    while(!p){ //equivale ao comando if(p == NULL)
        printf("\nErro: memória insuficiente para alocação!");
        printf("\nEntre com uma quantidade menor de novos cadastro: ");
        scanf("%i", &n);
        p = realloc(p, n * sizeof(FichaVisita));
    }

    q = malloc(n * sizeof(FichaReuniao));
    while(!p){ //equivale ao comando if(p == NULL)
        printf("\nErro: memória insuficiente para alocação!");
        printf("\nEntre com uma quantidade menor de novos cadastro: ");
        scanf("%i", &n);
        q = realloc(q, n * sizeof(FichaReuniao));
    }

     r = malloc(m * sizeof(funcionario));
    while(!p){ //equivale ao comando if(p == NULL)
        printf("\nErro: memória insuficiente para alocação!");
        printf("\nEntre com uma quantidade menor de novos cadastro: ");
        scanf("%i", &m);
        r = realloc(r, m * sizeof(funcionario));
    }

    do{
        a = 0;
        printf("\n\t*-*-*-*-*-*-*-*-*-LOGIN-*-*-*-*-*-*-*-*-*-*\n\n");
        strcpy(senha, "0");
        fflush(stdin);
        printf("Usuário: ");
        gets(usuario);
        strlwr(usuario);
        fflush(stdin);
        printf("Senha: ");
        do{
            c=getch();
            if(isprint(c)){        //Analisa se o valor de c é imprimível
                senha[a] = c;      //se for, armazena o caracter em a
                a++;
                printf("*");       //Imprimindo apenas o asterisco *
            }
            else if(c==8&&a){      // 8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
                senha[a]='\0';     // \0 é um caracter nulo
                a--;
                printf("\b \b");   // Apagando o caractere digitado
            }
            senha[a] = '\0';       // a recebe um caracter nulo qnd não é teclado nenhuma tecla

        }while(c != 13);           //13 é o valor de ENTER na tabela ASCII

        system("cls");

        if((strcmp(usuario, "user") == 0) && (strcmp(senha, "12345") == 0)){
            do{
                printf("\n\t****MENU PRINCIPAL****\n\n");
                printf("[1] Agendamento de Visita.\n");
                printf("[2] Agendamento de Reuniões.\n");
                printf("[3] Visualizar Agendamentos de Visitas, por data ou todos agendados.\n");
                printf("[4] Visualizar Agendamentos de Reuniões, por data ou todos agendados.\n");
                printf("[5] Visualizar cadastro de funcionario, por data de contratação ou todos contratados.\n");
                printf("[6] Realizar busca por (CPF/CNPJ) e edição das Visitas.\n");
                printf("[7] Realizar busca por (CPF/CNPJ) e edição das Reuniões.\n");
                printf("[0] Encerrar o programa.\n");
                printf("\n----------------------------------------------------------\n\n");
                printf("\nEscolha uma opção: ");
                scanf("%i", &opcao);
                fflush(stdin);
                system("cls");//comando que limpa a tela

                switch(opcao){
                    case 1: i = CadastroVisita(p, n, i);
                        break;

                    case 2: j = CadastroReuniao(q, n, j);
                        break;

                    case 3: VisualizarVisita(p, n, i);
                        break;

                    case 4: VisualizarReuniao(q, n, j);
                        break;

                    case 5: VisualizarFuncionario(r, m, y);
                        break;

                    case 6: i = BuscarDocVisita(p, n, i, opcao);
                        break;

                    case 7: j = BuscarDocReuniao(q, n, j, opcao);
                        break;

                    case 0: printf("Você escolheu sair do programa. Até mais!!\n\n");
                        break;

                    default: printf("\nEssa opção não existe. Escolha uma opção válida!\n");

                }

            }while(opcao != 0);

        }

        else if((strcmp(usuario, "admin") == 0) && (strcmp(senha, "admin123") == 0)){
            do{
                printf("\n\t****MENU PRINCIPAL****\n\n");
                printf("[1] Agendamento de Visita.\n");
                printf("[2] Agendamento de Reuniões.\n");
                printf("[3] Cadastro de funcionarios.\n");
                printf("[4] Visualizar Agendamentos de Visitas, por data ou todos agendados.\n");
                printf("[5] Visualizar Agendamentos de Reuniões, por data ou todos agendados.\n");
                printf("[6] Visualizar cadastro de funcionario, por data de contratação ou todos contratados.\n");
                printf("[7] Realizar busca por (CPF/CNPJ) e edição das Visitas.\n");
                printf("[8] Realizar busca por (CPF/CNPJ) e edição das Reuniões.\n");
                printf("[9] Realizar busca por RE e edição de alterar dados de funcionario.\n");
                printf("[10] Apagar agendamentos feitos.\n");
                printf("[0] Encerrar o programa.\n");
                printf("\n----------------------------------------------------------\n\n");
                printf("\nEscolha uma opção: ");
                scanf("%i", &opcao);
                fflush(stdin); //limpa o buffer do teclado
                system("cls"); //comando que limpa a tela

                switch(opcao){

                    case 1: i = CadastroVisita(p, n, i);
                        break;

                    case 2: j = CadastroReuniao(q, n, j);
                        break;

                    case 3: y = CadastroFuncionario(r, m, y);
                        break;

                    case 4: VisualizarVisita(p, n, i);
                        break;

                    case 5: VisualizarReuniao(q, n, j);
                        break;

                    case 6: VisualizarFuncionario(r, m, y);
                        break;

                    case 7: i = BuscarDocVisita(p, n, i, opcao);
                        break;

                    case 8: j = BuscarDocReuniao(q, n, j, opcao);
                        break;

                    case 9: y = BuscarReFuncionario(r, m, y, opcao);
                        break;

                    case 10: do{
                                printf("\nApagar os agendamentos feitos!\n");
                                printf("[1] Agendamentos de Visitas.\n");
                                printf("[2] Agendamentos de Reuniões.\n");
                                printf("[3] Cadastros de Funcionarios.\n");
                                printf("[0] Voltar\n");
                                printf("Escolha uma opção: ");
                                scanf("%i", &opcao);
                                system("cls");

                                switch(opcao){

                                    case 1: free(p);
                                        p = malloc(n * sizeof(FichaVisita));
                                        printf("\n\nAgendamentos de Visitas apagados!\n\n");
                                        i = 0;
                                        system("pause");
                                        system("cls");
                                        break;

                                    case 2: free(q);
                                        q = malloc(n * sizeof(FichaReuniao));
                                        printf("\n\nAgendamentos de Reuniões apagados!\n\n");
                                        j = 0;
                                        system("pause");
                                        system("cls");
                                        break;

                                    case 3: free(r);
                                        r = malloc(n * sizeof(FichaReuniao));
                                        printf("\n\nAgendamentos de Reuniões apagados!\n\n");
                                        y = 0;
                                        system("pause");
                                        system("cls");
                                        break;

                                    default: printf("\nEssa opção não existe. Escolha uma opção válida!");

                                }

                            }while(opcao != 0);
                            opcao = 1;
                            break;



                    case 0: printf("Você escolheu sair do programa. Até mais!!\n\n");
                        break;

                    default: printf("\nEssa opção não existe. Escolha uma opção válida!\n");
                }

            }while(opcao != 0);

        }

        else printf("\nUsuário ou senha inválidos.\n");


        printf("\nPara encerrar o programa digite (exit). Para logar novamente aperte qualquer tecla.\n");
        gets(sair);
        strlwr(sair);
        system("cls");

    }while(strcmp(sair, "exit") != 0);

	free(p);
	free(q);
	free(r);
}
