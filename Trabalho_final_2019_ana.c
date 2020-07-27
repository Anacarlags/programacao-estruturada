//------------------------------ BIBLIOTECAS ------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//------------------------------ CONSTANTES ------------------------------//

#define MAX_CLIENTES 10
#define MAX_CONTAS 20

//------------------------------ ESTRUTURAS ------------------------------//

//Estrutura para Cliente
typedef struct 
{
	char nome[100];
	char cpf[50];
	char endereco[100];
	char telefone[12];
	char email[50];
	int num_contas ;
}tCliente;

//Estrutura para Conta
typedef struct {
	int agencia;
	int conta;
	float saldo;
	char cpf[50];
}tConta;

//------------------------------ PROTÓTIPO DAS FUNÇÕES ------------------------------//

/********************************************/
/*			MANIPULAR ARQUIVOS				*/
/********************************************/

//Carrega os dados dos clientes que estão nos arquivos binários
//Parâmetros: o vetor de Clientes, o vetor de Contas, um ponteiro para a quantidade de clientes
//	e um ponteiro para a quantidade de contas
//Retorno: Verdadeiro se foi possível abrir os arquivos, falso se não
bool carregarDados(tCliente*, tConta*, int*, int* );

//Escreve os dados do programa nos arquivos
//Parâmetros: O vetor de clientes, vetor de contas, a quantidade de clientes e a quantidade de contas
//Retorno: void
void escreverArquivos(tCliente*, tConta*, int, int);

/********************************************/
/*					MENUS					*/
/********************************************/

//Primeiro menu a ser exibido
//Parâmetros: void
//Retorno: a opção escolhida pelo usuário
int menuPrincipal(void);

//Menu para fazer alterações no vetor de clientes
//Parâmetros: o vetor de Clientes e a quantidade de clientes
//Retorno: void
void menu_cliente(tCliente*, int*);

//Menu para fazer alterações em um cliente específico, está dentro do menu Cliente
//Parâmetros: o vetor de Clientes e o cpf do cliente
//Retorno: void
void menu_alterarCliente(tCliente*, char*);

//Menu para fazer alterações no vetor de contas
//Parâmetros: o vetor de Clientes e a quantidade de contas
//Retorno: void
void menu_conta(tCliente*, tConta*, int*);

//Menu para fazer alterações em uma conta específica, está dentro do menu Conta
//Parâmetros: o vetor de Clientes, o vetor de contas, o numero da agencia e o numero da conta
//Retorno: void
void menu_alterarConta(tCliente*, tConta*, int, int);

//Menu para fazer movimentações nas contas
//Parâmetros: o vetor de Clientes e o vetor de Contas
//Retorno: void
void menu_movimento(tCliente*, tConta*);

//Menu para exibir relatórios sobre contas
//Parâmetros: o vetor de Clientes, o vetor de Contas, a quantidade de clientes e a quantidade de contas
//Retorno: void
void menu_relatorio(tCliente*, tConta*, int, int);

//Menu para pesquisar contas com saldo menor, igual ou maior a determinado valor
//Parâmetros: o vetor de Clientes, o vetor de Contas, o valor, um booleano se deseja imprimir a lista
// e a quantidade de contas
//Retorno: void
void menu_pesquisaValor(tCliente*, tConta*, int, bool, int);

/********************************************/
/*				OPÇÔES CLIENTE				*/
/********************************************/

//Cadastra um cliente novo
//Parâmetros: o vetor de Clientes e o ponteiro para a quantidade de clientes
//Retorno: void
void cadastrarCliente(tCliente*, int*);

//Verifica se o CPF dado já está cadastrado
//Parâmetros: o vetor de Clientes e uma string que é o CPF
//Retorno: Se o CPF já existe a função retorna True, se não existe retorna False
bool existeCPF(tCliente*, char*);

//Retorna o índice de um cliente no vetor de Clientes a partir de um CPF
//Atenção: Essa função é chamada apenas quando já é certeza que o cliente existe
//Parâmetros: o vetor de Clientes e o cpf
//Retorno: o índice do cliente (inteiro positivo)
int buscaCPF(tCliente*, char*);

//Altera as informações de um cliente já cadastrado
//Parâmetros: o vetor de Clientes
//Retorno: void
void alterarCliente(tCliente*);

//Altera o nome do cliente de dado CPF
//Parâmetros: o vetor de Clientes e uma string que é o CPF
//Retorno: void
void alterarNome(tCliente*, char*);

//Altera o CPF do cliente de dado CPF
//Parâmetros: o vetor de Clientes e uma string que é o CPF
//Retorno: void
void alterarCPFCliente(tCliente*, char*);

//Altera o endereco do cliente de dado CPF
//Parâmetros: o vetor de Clientes e uma string que é o CPF
//Retorno: void
void alterarEndereco(tCliente*, char*);

//Altera o telefone do cliente de dado CPF
//Parâmetros: o vetor de Clientes e uma string que é o CPF
//Retorno: void
void alterarTelefone(tCliente*, char*);

//Altera o email do cliente de dado CPF
//Parâmetros: o vetor de Clientes e uma string que é o CPF
//Retorno: void
void alterarEmail(tCliente*, char*);

/********************************************/
/*				OPÇÔES CONTA				*/
/********************************************/

//Cadastra uma conta nova
//Parâmetros: o vetor de Clientes, o vetor de contas e o ponteiro para a quantidade de contas
//Retorno: void
void cadastrarConta(tCliente*, tConta*, int*);

//Verifica se a conta dada já existe
//Parâmetros: o vetor de Contas, o numero da agencia e o numero da conta
//Retorno: true se a conta já existe, false se não existe
bool existeConta(tConta*, int, int);

//Retorna o índice de uma conta no vetor de Contas a partir do numero de agencia e numero de conta
//Atenção: Essa função é chamada apenas quando já é certeza que a conta existe
//Parâmetros: o vetor de Contas, o numero da agencia e o numero da conta
//Retorno: o índice do conta (inteiro positivo)
int buscaConta(tConta*, int, int);

//Altera uma conta existente
//Parâmetros: o vetor de Clientes e o vetor de contas
//Retorno: void
void alterarConta(tCliente*, tConta*);

//Altera o numero da agencia de dada conta
//Parâmetros: o vetor de Contas, o numero da agencia e o numero da conta
//Retorno: void
void alterarNumeroAgencia(tConta*, int, int);

//Altera o numero da conta de dada conta
//Parâmetros: o vetor de Contas, o numero da agencia e o numero da conta
//Retorno: void
void alterarNumeroConta(tConta*, int, int);

//Altera o cpf de dada conta
//Parâmetros: o vetor de Clientes, o vetor de Contas, o numero da agencia e o numero da conta
//Retorno: void
void alterarCPFConta(tCliente*, tConta*, int, int);

//Remove uma conta
//Parâmetros: o vetor de Clientes, o vetor de Contas e o ponteiro para a quantidade de contas
//Retorno: void
void removerConta(tCliente*, tConta*, int*);

/********************************************/
/*			OPÇÔES MOVIMENTO				*/
/********************************************/

//Deposita um valor em uma conta
//Parâmetros: o vetor de contas
//Retorno: void
void deposito(tConta*);

//Saca valor de uma conta
//Parâmetros: o vetor de contas
//Retorno: void
void saque(tConta*);

//Transfere dinheiro entre contas
//Parâmetros: o vetor de contas
//Retorno: void
void transferencia(tConta*);

/********************************************/
/*			OPÇÔES RELATORIO				*/
/********************************************/

//Mostra o saldo de um único cliente
//Parâmetros: o vetor de Contas
//Retorno: void
void saldo(tConta*);

//Lista todas as contas de um cliente
//Parâmetros: o vetor de Clientes e o vetor de contas
//Retorno: void
void contasCliente(tCliente*, tConta*);

//Dados dos clientes com saldo inferior, superior ou igual a um valor
//Parâmetros: o vetor de Clientes, vetor de contas e a quantidade de contas
//Retorno: void
void dadosClientesSaldo(tCliente*, tConta*, int);

//Dados dos clientes com saldo superior a um valor
//Parâmetros: o vetor de Clientes, vetor de contas, valor, a opção se deseja ou não imprimir o arquivo e a quantidade de contas
//Retorno: void
void valorMaior(tCliente*, tConta*, int, bool, int);

//Dados dos clientes com saldo superior a um valor
//Parâmetros: o vetor de Clientes, vetor de contas, valor, a opção se deseja ou não imprimir o arquivo e a quantidade de contas
//Retorno: void
void valorIgual(tCliente*, tConta*, int, bool, int);

//Dados dos clientes com saldo superior a um valor
//Parâmetros: o vetor de Clientes, vetor de contas, valor, a opção se deseja ou não imprimir o arquivo e a quantidade de contas
//Retorno: void
void valorMenor(tCliente*, tConta*, int, bool, int);

//Pergunta se o usuario deseja imprimir um arquivo
//Parâmetros: void
//Retorno: true se a resposta for sim e false se a resposta for não
bool imprimirArquivo();

//Fecha um arquivo e imprime na tela se os dados foram salvos com sucesso ou nao
//Parâmetros: um ponteiro para o arquivo
//Retorno: void
void fecharArquivo(FILE*);

//Lista todos os clientes
//Parâmetros: o vetor de Clientes e a quantidade de clientes
//Retorno: void
void listaClientes(tCliente*, int);

//Lista todos as contas
//Parâmetros: o vetor de Clientes, o vetor de Contas e a quantidade de contas
//Retorno: void
void listaContas(tCliente*, tConta*, int);

//Lista todos os clientes e suas contas
//Parâmetros: o vetor de Clientes, vetor de contas, a quantidade de clientes e a quantidade de contas
//Retorno: void
void listaClientesContas(tCliente*, tConta*, int, int);

//Listar os dados cadastrais de todos clientes de uma agencia(ativos) ordenados pelo CPF
//Parâmetros: o vetor de Clientes, o vetor de contas e a quantidade de clientes
//Retorno: void
void listaClientesAgencia(tCliente*, tConta*, int);

//|--------------------------------------------------------------------------------------|//
//|---------------------------------------- MAIN ----------------------------------------|//
//|--------------------------------------------------------------------------------------|//

int main(){
	tCliente vCliente[MAX_CLIENTES];
	tConta vConta[MAX_CONTAS];
	int op;
	int quantCliente;
	int quantConta;
	
	if (!carregarDados(vCliente, vConta, &quantCliente, &quantConta))
		return 0;

	do{
		op = menuPrincipal();
		switch(op)
		{
		case 1: menu_cliente(vCliente, &quantCliente);
			break;
		case 2: menu_conta(vCliente, vConta, &quantConta);
			break;
		case 3: menu_movimento(vCliente, vConta);
			break;
		case 4: menu_relatorio(vCliente, vConta, quantCliente, quantConta);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA\n\n");
			break;
		}
		
	}while(op !=0);
	
	escreverArquivos(vCliente, vConta, quantCliente, quantConta);
	
	return 0;
}

//------------------------------ IMPLEMENTAÇÃO DAS FUNÇÕES ------------------------------//

/********************************************/
/*			MANIPULAR ARQUIVOS				*/
/********************************************/

bool carregarDados(tCliente* vCliente, tConta* vConta, int* quantCliente, int* quantConta) {
	FILE* fCliente;
	FILE* fConta;
	
	tCliente cliente;
	tConta conta;
	
	*quantCliente = 0;
	*quantConta = 0;
	
	fCliente = fopen("cliente.dat", "rb");
	fConta = fopen("conta.dat", "rb");	

	//Verifica se os arquivos binários foram abertos com sucesso
	if (fCliente == NULL || fConta == NULL)
	{
    	printf("Problemas na abertura do arquivo\n");
    	return false;
	}
	
	while(fread(&cliente, sizeof(tCliente), 1, fCliente))
	{
		strcpy(vCliente[*quantCliente].nome, cliente.nome);
		strcpy(vCliente[*quantCliente].cpf, cliente.cpf);
		strcpy(vCliente[*quantCliente].endereco, cliente.endereco);
		strcpy(vCliente[*quantCliente].telefone, cliente.telefone);
		strcpy(vCliente[*quantCliente].email, cliente.email);
		vCliente[*quantCliente].num_contas = cliente.num_contas;
		
		++(*quantCliente);
	}
	
	while(fread(&conta, sizeof(tConta), 1, fConta))
	{
		vConta[*quantConta].agencia = conta.agencia;
		vConta[*quantConta].conta = conta.conta;
		vConta[*quantConta].saldo = conta.saldo;
		strcpy(vConta[*quantConta].cpf, conta.cpf);
		
		++(*quantConta);
	}
	
	fclose(fCliente);
	fclose(fConta);

	return true;
}

void escreverArquivos(tCliente* vCliente, tConta* vConta, int quantCliente, int quantConta){
	FILE* fCliente;
	FILE* fConta;
	
	tCliente cliente;
	tConta conta;
	
	fCliente = fopen("cliente.dat", "wb");
	fConta = fopen("conta.dat", "wb");	

	//Verifica se os arquivos binários foram abertos com sucesso
	if (fCliente == NULL || fConta == NULL)
	{
    	printf("Problemas no salvamento dos dados.\n");
    	return;
	}
	
	int i;
	//Escrita no arquivo de clientes
	for (i = 0; i < quantCliente; ++i)
	{
		strcpy(cliente.nome, vCliente[i].nome);
		strcpy(cliente.cpf, vCliente[i].cpf);
		strcpy(cliente.endereco, vCliente[i].endereco);
		strcpy(cliente.telefone, vCliente[i].telefone);
		strcpy(cliente.email, vCliente[i].email);
		cliente.num_contas = vCliente[i].num_contas;

		fwrite(&cliente, sizeof(tCliente), 1, fCliente);
	}

	for (i = 0; i < quantConta; ++i)
	{
		conta.agencia = vConta[i].agencia;
		conta.conta = vConta[i].conta;
		conta.saldo = vConta[i].saldo;
		strcpy(conta.cpf, vConta[i].cpf);

		fwrite(&conta, sizeof(tConta), 1, fConta);
	}
	
	fclose(fCliente);
	fclose(fConta);
}

/********************************************/
/*					MENUS					*/
/********************************************/

int menuPrincipal(){
	int op;

	printf("MENU PRINCIPAL\n"
		"1 - Cliente\n"
		"2 - Conta\n"
		"3 - Movimento\n"
		"4 - Relatorio\n"
		"0 - Sair\n");
	scanf("%d", &op);
	while ((getchar()) != '\n'); //Usado para limpar o buffer
	
	return op;	
}

void menu_cliente(tCliente* vCliente, int *quantCliente){
	int op;
	
	do{	
		printf("MENU CLIENTE\n"
    		"1 - Cadastrar Cliente\n"	//FUNCIONALIDADE 1)
    		"2 - Alterar Cliente\n"		//FUNCIONALIDADE 2)
    		"0 - Sair\n");
	    scanf("%d", &op);
	    while ((getchar()) != '\n');
		switch(op)
		{
		case 1: cadastrarCliente(vCliente, quantCliente);
			break;
		case 2: alterarCliente(vCliente);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA\n\n");
			break;
		}
	}while(op != 0);	
}

void menu_alterarCliente(tCliente* vCliente, char* cpf){
	int op;

	do{	
		printf("MENU ALTERAR CLIENTE\n"
			"Voce deseja alterar qual campo?\n"
    		"1 - Nome\n"
    		"2 - CPF\n"
    		"3 - Endereco\n"
    		"4 - Telefone Principal\n"
    		"5 - E-mail Principal\n"
    		"0 - Sair\n");
	    scanf("%d", &op);
	    while ((getchar()) != '\n');

		switch(op)
		{
		case 1: alterarNome(vCliente, cpf);
			break;
		case 2: alterarCPFCliente(vCliente, cpf);
			break;
		case 3: alterarEndereco(vCliente, cpf);
			break;
		case 4: alterarTelefone(vCliente, cpf);
			break;
		case 5: alterarEmail(vCliente, cpf);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA\n\n");
			break;
		}
	}while(op != 0);	
}

void menu_conta(tCliente* vCliente, tConta* vConta, int* quantConta){
	int op;

	do{	
		printf("MENU CONTA\n"
    		"1 - Cadastrar Conta\n"		//FUNCIONALIDADE 3)
    		"2 - Alterar Conta\n"		//FUNCIONALIDADE 4)
    		"3 - Remover Conta\n"		//FUNCIONALIDADE 5)
    		"0 - Sair\n");
	    scanf("%d", &op);
	    while ((getchar()) != '\n');

		switch(op)
		{
		case 1: cadastrarConta(vCliente, vConta, quantConta);
			break;
		case 2: alterarConta(vCliente, vConta);
			break;
		case 3: removerConta(vCliente, vConta, quantConta);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA\n\n");
			break;
		}
	}while(op != 0);	
}

void menu_alterarConta(tCliente* vCliente, tConta* vConta, int agencia, int conta){
	int op;
	do{	
		printf("MENU ALTERAR CONTA\n"
			"Voce deseja alterar qual campo?\n"
    		"1 - Numero da Agencia\n"
    		"2 - Numero da Conta\n"
    		"3 - CPF\n"
    		"0 - Sair\n");
	    scanf("%d", &op);
	    while ((getchar()) != '\n');

		switch(op)
		{
		case 1: alterarNumeroAgencia(vConta, agencia, conta);
			break;
		case 2: alterarNumeroConta(vConta, agencia, conta);
			break;
		case 3: alterarCPFConta(vCliente, vConta, agencia, conta);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA\n\n");
			break;
		}
	}while(op != 0);	
}

void menu_movimento(tCliente* vCliente, tConta* vConta){ 
	int op;

	do{	
		printf("MENU MOVIMENTO\n"
    		"1 - Deposito\n"		//FUNCIONALIDADE 7)
    		"2 - Saque\n"			//FUNCIONALIDADE 8)
    		"3 - Transferencia\n"	//FUNCIONALIDADE 9)
    		"0 - Sair\n");
	    scanf("%d", &op);
	    while ((getchar()) != '\n');

		switch(op)
		{
		case 1: deposito(vConta);
			break;
		case 2: saque(vConta);
			break;
		case 3: transferencia(vConta);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA\n\n");
			break;
		}
	}while(op != 0);	
}

void menu_relatorio(tCliente* vCliente, tConta* vConta, int quantCliente, int quantConta){
	int op;

	do{	
		printf("MENU RELATORIOS\n"
			"1 - Saldo\n"																							//FUNCIONALIDADE 6)
    		"2 - Contas de um cliente\n"																			//FUNCIONALIDADE 10)
    		"3 - Dados dos clientes com saldo inferior, superior ou igual a um valor\n"								//FUNCIONALIDADE 11)
    		"4 - Lista os dados cadastrais de todos clientes (ativos ou nao)\n"										//FUNCIONALIDADE 12)
    		"5 - Listar as informacoes de todas as contas\n"														//FUNCIONALIDADE 13)
    		"6 - Listar as informacoes de todos os clientes (inclusive as informacoes referentes as suas contas)\n" //FUNCIONALIDADE 14)
    		"7 - Listar os dados cadastrais de todos clientes de uma agencia(ativos) ordenados pelo CPF\n"			//FUNCIONALIDADE 15)
    		"0 - Sair\n");
	    scanf("%d", &op);
	    while ((getchar()) != '\n');
	    
		switch(op)
		{
		case 1: saldo(vConta);
			break;
		case 2: contasCliente(vCliente, vConta);
			break;
		case 3: dadosClientesSaldo(vCliente, vConta, quantConta);
			break;
		case 4: listaClientes(vCliente, quantCliente);
			break;
		case 5: listaContas(vCliente, vConta, quantConta);
			break;
		case 6: listaClientesContas(vCliente, vConta, quantCliente, quantConta);
			break;
		case 7: listaClientesAgencia(vCliente, vConta, quantCliente);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA\n\n");
			break;
		}
	}while(op != 0);	
}

void menu_pesquisaValor(tCliente* vCliente, tConta* vConta, int valor, bool imprimirArquivo, int quantConta) {
	int op;

	do{	
		printf("Voce deseja a informacao das contas com valor:\n"
    		"1 - Maior\n"
    		"2 - Igual\n"
    		"3 - Menor\n"
    		"0 - Sair\n");
	    scanf("%d", &op);
	    while ((getchar()) != '\n');

		switch(op)
		{
		case 1: valorMaior(vCliente, vConta, valor, imprimirArquivo, quantConta);
			break;
		case 2: valorIgual(vCliente, vConta, valor, imprimirArquivo, quantConta);
			break;
		case 3: valorMenor(vCliente, vConta, valor, imprimirArquivo, quantConta);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA\n\n");
			break;
		}
	}while(op != 0);
}

/********************************************/
/*				OPÇÔES CLIENTE				*/
/********************************************/

void cadastrarCliente(tCliente* vCliente, int* quantCliente) {
	tCliente cliente;

	printf("Insira o nome do Cliente:\n");
	//[A-Z a-z] serve para ler strings com espaços
	scanf("%[A-Z a-z]", cliente.nome);
	while ((getchar()) != '\n');

	printf("Insira o CPF do Cliente:\n");
	scanf("%s", cliente.cpf);
	while ((getchar()) != '\n');

	if(existeCPF(vCliente, cliente.cpf)) {
		printf("CLIENTE JA CADASTRADO!\n");
		return;
	}

	printf("Insira o endereco do cliente:\n");
	scanf("%[A-Z a-z]", cliente.endereco);
	while ((getchar()) != '\n');

	printf("Insira o telefone principal do cliente:\n");
	scanf("%[A-Z a-z]", cliente.telefone);
	while ((getchar()) != '\n');

	printf("Insira o email principal do cliente:\n");
	scanf("%[A-Z a-z]", cliente.email);
	while ((getchar()) != '\n');
	
	strcpy(vCliente[*quantCliente].nome, cliente.nome);
	strcpy(vCliente[*quantCliente].cpf, cliente.cpf);
	strcpy(vCliente[*quantCliente].endereco, cliente.endereco);
	strcpy(vCliente[*quantCliente].telefone, cliente.telefone);
	strcpy(vCliente[*quantCliente].email, cliente.email);
	vCliente[*quantCliente].num_contas = 0;
		
	++(*quantCliente);
}

bool existeCPF(tCliente* vCliente, char* cpf) {
	int i;
	for (i = 0; i < MAX_CLIENTES; ++i)
	{
		if (strcmp(vCliente[i].cpf, cpf) == 0)
		{
			return true;
		}
	}
	return false;
}

int buscaCPF(tCliente* vCliente, char* cpf) {
	int i;
	for (i = 0; i < MAX_CLIENTES; ++i)
	{
		if (strcmp(vCliente[i].cpf, cpf) == 0)
		{
			return i;
		}
	}
return 0;	
}

void alterarCliente(tCliente* vCliente) {
	char cpf[50];

	printf("Digite o CPF do Cliente que deseja alterar:\n");
	scanf("%s", cpf);
	while ((getchar()) != '\n');

	if (existeCPF(vCliente, cpf))
	{
		menu_alterarCliente(vCliente, cpf);
	}
	else {
		printf("O CPF NAO ESTA CADASTRADO!\n");
	}
}

void alterarNome(tCliente* vCliente, char* cpf) {
	int i = buscaCPF(vCliente, cpf);

	printf("Digite o novo nome do Cliente:\n");
	scanf("%[A-Z a-z]", vCliente[i].nome);
	while ((getchar()) != '\n');
}

void alterarCPFCliente(tCliente* vCliente, char* cpf) {
	int i = buscaCPF(vCliente, cpf);
	char cpfNovo[50];

	printf("Digite o novo CPF do Cliente:\n");
	scanf("%s", cpfNovo);
	while ((getchar()) != '\n');

	if (existeCPF(vCliente, cpfNovo)) {
		printf("O CPF JA ESTA CADASTRADO!\n");
	}
	else {
		strcpy(vCliente[i].cpf, cpfNovo);
	}
}

void alterarEndereco(tCliente* vCliente, char* cpf) {
	int i = buscaCPF(vCliente, cpf);

	printf("Digite o novo endereco do Cliente:\n");
	scanf("%[A-Z a-z]", vCliente[i].endereco);
	while ((getchar()) != '\n');
}

void alterarTelefone(tCliente* vCliente, char* cpf) {
	int i = buscaCPF(vCliente, cpf);

	printf("Digite o novo telefone do Cliente:\n");
	scanf("%s", vCliente[i].telefone);
	while ((getchar()) != '\n');
}

void alterarEmail(tCliente* vCliente, char* cpf) {
	int i = buscaCPF(vCliente, cpf);

	printf("Digite o novo email do Cliente:\n");
	scanf("%s", vCliente[i].email);
	while ((getchar()) != '\n');
}

/********************************************/
/*				OPÇÔES CONTA				*/
/********************************************/

void cadastrarConta(tCliente* vCliente, tConta* vConta, int* quantConta) {
	tConta contaNova;
	int indiceCliente;

	//Não pode ser cadastrada um conta em CPF inexistente
	printf("Insira o CPF do Cliente:\n");
	scanf("%s", contaNova.cpf);
	while ((getchar()) != '\n');
	if(!existeCPF(vCliente, contaNova.cpf)) {
		printf("O CPF NAO ESTA CADASTRADO!\n");
		return;
	}

	//Não podem existir duas contas iguais (com mesmo numero de agencia e conta)
	printf("Insira numero da agencia da conta:\n");
	scanf("%i", &(contaNova.agencia));
	while ((getchar()) != '\n');

	printf("Insira numero da conta:\n");
	scanf("%i", &(contaNova.conta));
	while ((getchar()) != '\n');

	if (existeConta(vConta, contaNova.agencia, contaNova.conta)) {
		printf("CONTA JA CADASTRADA!\n");
		return;
	}

	printf("Insira o saldo da conta:\n");
	scanf("%f", &(contaNova.saldo));
	while ((getchar()) != '\n');
	
	strcpy(vConta[*quantConta].cpf, contaNova.cpf);
	vConta[*quantConta].agencia = contaNova.agencia;
	vConta[*quantConta].conta = contaNova.conta;
	vConta[*quantConta].saldo = contaNova.saldo;

	++(*quantConta);
	indiceCliente = buscaCPF(vCliente, contaNova.cpf);
	++vCliente[indiceCliente].num_contas;
}

bool existeConta(tConta* vConta, int agencia, int contaNumero) {
	tConta conta;
	
	int i;
	for (i = 0; i < MAX_CONTAS; ++i)
	{
		if (conta.agencia == agencia && conta.conta == contaNumero)
		{
			return true;
		}
	}

	return false;
}

int buscaConta(tConta* vConta, int agencia, int contaNumero) {
	tConta conta;
	int i;
	for (i = 0; i < MAX_CONTAS; ++i)
	{
		if (conta.agencia == agencia && conta.conta == contaNumero)
		{
			return i;
		}
	}
return 0;	
}

void alterarConta(tCliente* vCliente, tConta* vConta) {
	int agencia;
	int conta;

	printf("Insira o numero da Agencia da conta da qual deseja alterar:\n");
	scanf("%i", &agencia);
	while ((getchar()) != '\n');

	printf("Insira o numero da Conta:\n");
	scanf("%i", &conta);
	while ((getchar()) != '\n');

	if (!existeConta(vConta, agencia, conta)) {
		printf("CONTA INVALIDA!\n");
	}
	else {
		menu_alterarConta(vCliente, vConta, agencia, conta);
	}
}

void alterarNumeroAgencia(tConta* vConta, int agencia, int conta) {
	int agenciaNova;
	int indiceConta;

	printf("Digite o novo numero da Agencia:\n");
	scanf("%i", &agenciaNova);
	while ((getchar()) != '\n');

	if(existeConta(vConta, agenciaNova, conta)) {
		printf("CONTA JA CADASTRADA!\n");
	}
	else {
		indiceConta = buscaConta(vConta, agencia, conta);
		vConta[indiceConta].agencia = agenciaNova;
	}
}

void alterarNumeroConta(tConta* vConta, int agencia, int conta) {
	int contaNova;
	int indiceConta;

	printf("Digite o novo numero da Conta:\n");
	scanf("%i", &contaNova);
	while ((getchar()) != '\n');

	if(existeConta(vConta, agencia, contaNova)) {
		printf("CONTA JA CADASTRADA!\n");
	}
	else {
		indiceConta = buscaConta(vConta, agencia, conta);
		vConta[indiceConta].conta = contaNova;
	}
}

void alterarCPFConta(tCliente* vCliente, tConta* vConta, int agencia, int conta) {
	char cpfNovo[50];
	char cpfAntigo[50];
	int indiceClienteNovo;
	int indiceClienteAntigo;
	int indiceConta;

	//Verifica se o CPF novo já está cadastrado em algum cliente existente.
	printf("Digite o novo CPF da conta:\n");
	scanf("%s", cpfNovo);
	while ((getchar()) != '\n');

	if (!existeCPF(vCliente, cpfNovo)) {
		printf("O CPF NAO ESTA CADASTRADO!\n");
	}
	else {
		indiceConta = buscaConta(vConta, agencia, conta);
		strcpy(cpfAntigo, vConta[indiceConta].cpf);
		strcpy(vConta[indiceConta].cpf, cpfNovo);

		//Diminui o numero de contas do cpf antigo e incrementa no cpf novo
		indiceClienteAntigo = buscaCPF(vCliente, cpfAntigo);
		indiceClienteNovo = buscaCPF(vCliente, cpfNovo);

		--vCliente[indiceClienteAntigo].num_contas;
		++vCliente[indiceClienteNovo].num_contas;
	}
}

void removerConta(tCliente* vCliente, tConta* vConta, int* quantConta) {
	int agencia;
	int conta;
	int indiceConta;
	int indiceCliente;

	printf("Insira o numero da Agencia da conta da qual deseja alterar:\n");
	scanf("%i", &agencia);
	while ((getchar()) != '\n');

	printf("Insira o numero da Conta:\n");
	scanf("%i", &conta);
	while ((getchar()) != '\n');

	if (!existeConta(vConta, agencia, conta)) {
		printf("CONTA INVALIDA!\n");
	}
	else {
		indiceConta = buscaConta(vConta, agencia, conta);
		vConta[indiceConta].agencia = 0;
		vConta[indiceConta].conta = 0;
		strcpy(vConta[indiceConta].cpf, "");
		vConta[indiceConta].saldo = 0;

		--(*quantConta);
		indiceCliente = buscaCPF(vCliente, vConta[indiceConta].cpf);
		--vCliente[indiceCliente].num_contas;
	}
}

/********************************************/
/*			OPÇÔES MOVIMENTO				*/
/********************************************/

void deposito(tConta* vConta) {
	int agencia;
	int contaNumero;
	int saldo;
	int indiceConta;

	printf("Informe a agencia da conta para Deposito:\n");
	scanf("%i", &agencia);
	while ((getchar()) != '\n');

	printf("Informe o numero da conta para Deposito:\n");
	scanf("%i", &contaNumero);
	while ((getchar()) != '\n');

	if (!existeConta(vConta, agencia, contaNumero))
	{
		printf("CONTA INVALIDA!\n");
		return;
	}

	printf("Informe o valor do deposito:\n");
	scanf("%i", &saldo);
	while ((getchar()) != '\n');

	indiceConta = buscaConta(vConta, agencia, contaNumero);
	vConta[indiceConta].saldo += saldo;
}

void saque(tConta* vConta) {
	int agencia;
	int contaNumero;
	int saque;
	int indiceConta;

	printf("Informe a agencia da conta para Saque:\n");
	scanf("%i", &agencia);
	while ((getchar()) != '\n');

	printf("Informe o numero da conta para Saque:\n");
	scanf("%i", &contaNumero);
	while ((getchar()) != '\n');

	if (!existeConta(vConta, agencia, contaNumero))
	{
		printf("CONTA INVALIDA!\n");
		return;
	}

	indiceConta = buscaConta(vConta, agencia, contaNumero);

	printf("Informe o valor do Saque:\n");
	scanf("%i", &saque);
	while ((getchar()) != '\n');

	if(saque > vConta[indiceConta].saldo) {
		printf("SALDO INSUFICIENTE.\n");
		return;
	}
	
	vConta[indiceConta].saldo -= saque;
}

void transferencia(tConta* vConta) {
	int agenciaOrigem;
	int contaOrigem;
	int agenciaDestino;
	int contaDestino;
	int indiceContaOrigem;
	int indiceContaDestino;
	int valor;

	printf("Informe a agencia da conta Origem:\n");
	scanf("%i", &agenciaOrigem);
	while ((getchar()) != '\n');

	printf("Informe o numero da conta Origem:\n");
	scanf("%i", &contaOrigem);
	while ((getchar()) != '\n');

	if (!existeConta(vConta, agenciaOrigem, contaOrigem))
	{
		printf("CONTA ORIGEM INVALIDA!\n");
		return;
	}

	printf("Informe a agencia da conta Destino:\n");
	scanf("%i", &agenciaDestino);
	while ((getchar()) != '\n');

	printf("Informe o numero da conta Destino:\n");
	scanf("%i", &contaDestino);
	while ((getchar()) != '\n');

	if (!existeConta(vConta, agenciaDestino, contaDestino))
	{
		printf("CONTA DESTINO INVALIDA!\n");
		return;
	}

	printf("Informe o valor da Transferencia:\n");
	scanf("%i", &valor);
	while ((getchar()) != '\n');

	indiceContaOrigem = buscaConta(vConta, agenciaOrigem, contaOrigem);
	if (valor > vConta[indiceContaOrigem].saldo)
	{
		printf("SALDO INSUFICIENTE!\n");
		return;
	}

	indiceContaDestino = buscaConta(vConta, agenciaDestino, agenciaOrigem);
	vConta[indiceContaOrigem].saldo -= valor;
	vConta[indiceContaDestino].saldo += valor;
}

/********************************************/
/*			OPÇÔES RELATORIO				*/
/********************************************/

void saldo(tConta* vConta) {
	int agencia;
	int conta;
	int indiceConta;

	printf("Informe o numero da Agencia para ver o saldo:\n");
	scanf("%i", &agencia);
	while ((getchar()) != '\n');

	printf("Informe o numero da Conta para ver o saldo:\n");
	scanf("%i", &conta);
	while ((getchar()) != '\n');

	if (!existeConta(vConta, agencia, conta))
	{
		printf("CONTA INVALIDA!\n");
		return;
	}

	indiceConta = buscaConta(vConta, agencia, conta);
	printf("SALDO DA CONTA: %.2f\n", vConta[indiceConta].saldo);
}

void contasCliente(tCliente* vCliente, tConta* vConta) {
	char cpf[50];

	printf("Informe o CPF do Cliente\n");
	scanf("%s", cpf);
	while ((getchar()) != '\n');

	if (!existeCPF(vCliente, cpf))
	{
		printf("O CPF NAO ESTA CADASTRADO!\n");
		return;
	}

	int i;
	for (i = 0; i < MAX_CONTAS; ++i)
	{
		if (strcmp(vConta[i].cpf, cpf) == 0)
		{
			printf("CPF: %s\n"
				"Agencia: %i\n"
				"Numero da Conta: %i\n"
				"Saldo: %.2f\n\n", vConta[i].cpf, vConta[i].agencia, vConta[i].conta, vConta[i].saldo);
		}
	}

}

void dadosClientesSaldo(tCliente* vCliente, tConta* vConta, int quantConta) {
	int valor;

	printf("Qual valor voce deseja pesquisar?\n");
	scanf("%i", &valor);
	while ((getchar()) != '\n');

	menu_pesquisaValor(vCliente, vConta, valor, imprimirArquivo(), quantConta);
}

void valorMaior(tCliente* vCliente, tConta* vConta, int valor, bool imprimirArquivoBoolean, int quantConta) {
	int indiceCliente;
	FILE* arquivo;

	if (imprimirArquivoBoolean) {
		arquivo = fopen("dadosContas.txt", "w");
	}

	int i;
	for (i = 0; i < quantConta; ++i) {
		if (vConta[i].saldo > valor) {
			indiceCliente = buscaCPF(vCliente, vConta[i].cpf);
			printf("Nome do cliente: %s\n"
				"CPF: %s\n"
				"Numero da conta: %i\n"
				"Numero da agencia: %i\n"
				"Saldo: %.2f\n\n", vCliente[indiceCliente].nome, vConta[i].cpf, vConta[i].conta, vConta[i].agencia, vConta[i].saldo);
			if (imprimirArquivoBoolean) {
				//fprintf imprime os valores no arquivo texto
				fprintf(arquivo, "Nome do cliente: %s\n"
				"CPF: %s\n"
				"Numero da conta: %i\n"
				"Numero da agencia: %i\n"
				"Saldo: %.2f\n\n", vCliente[indiceCliente].nome, vConta[i].cpf, vConta[i].conta, vConta[i].agencia, vConta[i].saldo);
			}
		}
	}

	if (imprimirArquivoBoolean) {
		//fclose(arquivo) retorna 0 se os dados foram gravados com sucesso, e EOF (final de arquivo) se não foram
		fecharArquivo(arquivo);
	}
}

void valorIgual(tCliente* vCliente, tConta* vConta, int valor, bool imprimirArquivoBoolean, int quantConta) {
	int indiceCliente;
	FILE* arquivo;

	if (imprimirArquivoBoolean) {
		arquivo = fopen("dadosContas.txt", "w");
	}

	int i;
	for (i = 0; i < quantConta; ++i) {
		if (vConta[i].saldo == valor) {
			indiceCliente = buscaCPF(vCliente, vConta[i].cpf);
			printf("Nome do cliente: %s\n"
				"CPF: %s\n"
				"Numero da conta: %i\n"
				"Numero da agencia: %i\n"
				"Saldo: %.2f\n\n", vCliente[indiceCliente].nome, vConta[i].cpf, vConta[i].conta, vConta[i].agencia, vConta[i].saldo);
			if (imprimirArquivoBoolean) {
				//fprintf imprime os valores no arquivo texto
				fprintf(arquivo, "Nome do cliente: %s\n"
				"CPF: %s\n"
				"Numero da conta: %i\n"
				"Numero da agencia: %i\n"
				"Saldo: %.2f\n\n", vCliente[indiceCliente].nome, vConta[i].cpf, vConta[i].conta, vConta[i].agencia, vConta[i].saldo);
			}
		}
	}

	if (imprimirArquivoBoolean) {
		//fclose(arquivo) retorna 0 se os dados foram gravados com sucesso, e EOF (final de arquivo) se não foram
		fecharArquivo(arquivo);
	}
}

void valorMenor(tCliente* vCliente, tConta* vConta, int valor, bool imprimirArquivoBoolean, int quantConta) {
	int indiceCliente;
	FILE* arquivo;

	if (imprimirArquivoBoolean) {
		arquivo = fopen("dadosContas.txt", "w");
	}

	int i;
	for (i = 0; i < quantConta; ++i) {
		if (vConta[i].saldo < valor) {
			indiceCliente = buscaCPF(vCliente, vConta[i].cpf);
			printf("Nome do cliente: %s\n"
				"CPF: %s\n"
				"Numero da conta: %i\n"
				"Numero da agencia: %i\n"
				"Saldo: %.2f\n\n", vCliente[indiceCliente].nome, vConta[i].cpf, vConta[i].conta, vConta[i].agencia, vConta[i].saldo);
			if (imprimirArquivoBoolean) {
				//fprintf imprime os valores no arquivo texto
				fprintf(arquivo, "Nome do cliente: %s\n"
				"CPF: %s\n"
				"Numero da conta: %i\n"
				"Numero da agencia: %i\n"
				"Saldo: %.2f\n\n", vCliente[indiceCliente].nome, vConta[i].cpf, vConta[i].conta, vConta[i].agencia, vConta[i].saldo);
			}
		}
	}

	if (imprimirArquivoBoolean) {
		//fclose(arquivo) retorna 0 se os dados foram gravados com sucesso, e EOF (final de arquivo) se não foram
		fecharArquivo(arquivo);
	}
}

bool imprimirArquivo() {
	char imprimirArquivo;

	while(1) {
		printf("Deseja imprimir em um arquivo?\nS - sim\nN - nao\n");
		scanf("%c", &imprimirArquivo);
		while ((getchar()) != '\n');

		if (imprimirArquivo != 'S' && imprimirArquivo != 'N' && imprimirArquivo != 's' && imprimirArquivo != 'n')
		{
			printf("OPCAO INVALIDA, DIGITE NOVAMENTE.\n");
		}
		else {
			break;
		}
	}

	//Se a resposta for sim, então retorna true, senão retorna false
	return (imprimirArquivo == 'S' || imprimirArquivo == 's');
}

void fecharArquivo(FILE* arquivo) {
	if (fclose(arquivo) == 0) {
		printf("DADOS GRAVADOS COM SUCESSO!\n");
	}
	else {
		printf("NAO FOI POSSIVEL SALVAR OS DADOS!\n");
	}
}

void listaClientes(tCliente* vCliente, int quantCliente) {
	FILE* arquivo;
	bool imprimirArquivoBoolean = imprimirArquivo();

	if (imprimirArquivoBoolean)
	{
		arquivo = fopen("listaClientes.txt", "w");
	}

	int i;
	for (i = 0; i < quantCliente; ++i)
	{
		printf("Nome do Cliente: %s\n"
			"CPF: %s\n"
			"Endereco: %s\n"
			"Telefone principal: %s\n"
			"Email principal: %s\n"
			"Numero de Contas: %i\n\n", vCliente[i].nome, vCliente[i].cpf, vCliente[i].endereco, vCliente[i].telefone, vCliente[i].email, vCliente[i].num_contas);
		if (imprimirArquivoBoolean)
		{
			//fprintf imprime as informações no arquivo de texto
			fprintf(arquivo, "Nome do Cliente: %s\n"
			"CPF: %s\n"
			"Endereco: %s\n"
			"Telefone principal: %s\n"
			"Email principal: %s\n"
			"Numero de Contas: %i\n\n", vCliente[i].nome, vCliente[i].cpf, vCliente[i].endereco, vCliente[i].telefone, vCliente[i].email, vCliente[i].num_contas);
		}
	}

	if (imprimirArquivoBoolean) {
		//fclose(arquivo) retorna 0 se os dados foram gravados com sucesso, e EOF (final de arquivo) se não foram
		fecharArquivo(arquivo);
	}
}

void listaContas(tCliente* vCliente, tConta* vConta, int quantConta) {
	int indiceCliente;
	FILE* arquivo;
	bool imprimirArquivoBoolean = imprimirArquivo();

	if (imprimirArquivoBoolean) {
		arquivo = fopen("listaContas.txt", "w");
	}

	int i;
	for (i = 0; i < quantConta; ++i) {
		indiceCliente = buscaCPF(vCliente, vConta[i].cpf);
		printf("Nome do cliente: %s\n"
			"CPF: %s\n"
			"Numero da conta: %i\n"
			"Numero da agencia: %i\n"
			"Saldo: %.2f\n\n", vCliente[indiceCliente].nome, vConta[i].cpf, vConta[i].conta, vConta[i].agencia, vConta[i].saldo);
		if (imprimirArquivoBoolean) {
			//fprintf imprime os valores no arquivo texto
			fprintf(arquivo, "Nome do cliente: %s\n"
			"CPF: %s\n"
			"Numero da conta: %i\n"
			"Numero da agencia: %i\n"
			"Saldo: %.2f\n\n", vCliente[indiceCliente].nome, vConta[i].cpf, vConta[i].conta, vConta[i].agencia, vConta[i].saldo);
		}
	}

	if (imprimirArquivoBoolean) {
		//fclose(arquivo) retorna 0 se os dados foram gravados com sucesso, e EOF (final de arquivo) se não foram
		fecharArquivo(arquivo);
	}
}

void listaClientesContas(tCliente* vCliente, tConta* vConta, int quantCliente, int quantConta) {
	FILE* arquivo;
	bool imprimirArquivoBoolean = imprimirArquivo();

	if (imprimirArquivoBoolean) {
		arquivo = fopen("listaClientes.txt", "w");
	}

	int i;
	for (i = 0; i < quantCliente; ++i) {
		printf("Nome do Cliente: %s\n"
			"CPF: %s\n"
			"Endereco: %s\n"
			"Telefone principal: %s\n"
			"Email principal: %s\n"
			"Numero de Contas: %i\n", vCliente[i].nome, vCliente[i].cpf, vCliente[i].endereco, vCliente[i].telefone, vCliente[i].email, vCliente[i].num_contas);
		if (imprimirArquivoBoolean) {
			//fprintf imprime as informações no arquivo de texto
			fprintf(arquivo, "Nome do Cliente: %s\n"
			"CPF: %s\n"
			"Endereco: %s\n"
			"Telefone principal: %s\n"
			"Email principal: %s\n"
			"Numero de Contas: %i\n", vCliente[i].nome, vCliente[i].cpf, vCliente[i].endereco, vCliente[i].telefone, vCliente[i].email, vCliente[i].num_contas);
		}
		if (vCliente[i].num_contas == 0) {
			printf("CONTAS: \nO Cliente nao possui nenhuma conta.\n\n");
			fprintf(arquivo, "CONTAS: \nO Cliente nao possui nenhuma conta.\n\n");
		}
		else {
			printf("CONTAS: \n");
			fprintf(arquivo, "CONTAS: \n");

			int j;
			for (j = 0; j < quantConta; ++j)
			{
				if (strcmp(vCliente[i].cpf, vConta[j].cpf) == 0)
				{
					printf("Agencia: %i\n"
						"Numero da Conta: %i\n"
						"Saldo: %.2f\n\n", vConta[j].agencia, vConta[j].conta, vConta[j].saldo);
					fprintf(arquivo, "Agencia: %i\n"
						"Numero da Conta: %i\n"
						"Saldo: %.2f\n\n", vConta[j].agencia, vConta[j].conta, vConta[j].saldo);
				}
			}
		}
	}

	if (imprimirArquivoBoolean) {
		//fclose(arquivo) retorna 0 se os dados foram gravados com sucesso, e EOF (final de arquivo) se não foram
		fecharArquivo(arquivo);
	}
}

void listaClientesAgencia(tCliente* vCliente, tConta* vConta, int quantCliente) {
	int agencia;

	printf("Digite o numero da agencia: \n");
	scanf("%i", &agencia);
	while ((getchar()) != '\n');

	int i;
	int j; //O índice do cliente que possui uma conta nessa agencia
	for (i = 0; i < quantCliente; ++i) {
		if (vConta[i].agencia == agencia) {
			j = buscaCPF(vCliente, vConta[i].cpf);
			printf("Nome do Cliente: %s\n"
			"CPF: %s\n"
			"Endereco: %s\n"
			"Telefone principal: %s\n"
			"Email principal: %s\n"
			"Numero de Contas: %i\n\n", vCliente[j].nome, vCliente[j].cpf, vCliente[j].endereco, vCliente[j].telefone, vCliente[j].email, vCliente[j].num_contas);
		}
	}
}