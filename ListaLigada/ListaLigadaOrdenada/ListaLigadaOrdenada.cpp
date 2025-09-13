#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada Ordenada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		NO* atual = primeiro;
		NO* anterior = NULL;

		while (atual != NULL && atual->valor < novo->valor) {

			anterior = atual;
			atual = atual->prox;
		}

		if (atual != NULL && atual->valor == novo->valor) {

			cout << "O elemento ja existe na lista \n";
			free(novo);

		}

		else {
			if (anterior == NULL) {
				primeiro = novo;
			}

			else {
				anterior->prox = novo;
				novo->prox = atual;
			}
		}
	}
}

void excluirElemento()
{
	int numero;

	cout << "Digite o numero a ser excluido: ";
	cin >> numero;

	if (posicaoElemento(numero) == NULL) {
		cout << "NAO ENCONTRADO" << endl;
	}

	else if (primeiro->valor == numero) {
		NO* excluir = primeiro;
		primeiro = primeiro->prox;
		free(excluir);
		cout << "Elemento excluido." << endl;
	}

	else {
		NO* atual = posicaoElemento(numero);
		NO* anterior = NULL;

		while (aux != atual) {
			anterior = aux;
			aux = aux->prox;
		}

		anterior->prox = atual->prox;
		free(atual);
		cout << "Elemento excluido." << endl;
	}
}

void buscarElemento()
{
	int numero;

	cout << "Digite o elemento a ser buscado: ";
	cin >> numero;
	
	if (primeiro == NULL) {
		cout << "A lista está vazia" << endl;
	}

	else {

		NO* aux = primeiro;
		while (aux->prox != NULL) {
			if (aux->valor == numero) {
				cout << "ENCONTRADO" << endl;
				return;
			}

			else if (aux->valor > numero) {
				cout << "ELEMENTO NAO ENCONTRADO" << endl;
				return;
			}
			else {
				cout << "ELEMENTO NAO ENCONTRADO" << endl;
			}
		}

	}
}


