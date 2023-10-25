#include <iostream>
#include <conio.h>

struct Pilha {
    int dado;
    struct Pilha *prox;
};

typedef struct Pilha pilha;
typedef pilha *pilhaPtr;

void menu() {
    std::cout << "Escolha a opcao:\n";
    std::cout << "1 - PUSH: Empilhar um ou mais valores na Pilha\n";
    std::cout << "2 - POP: Retirar o ultimo valor da Pilha\n";
    std::cout << "3 - REMOVE: Retira qualquer valor da pilha\n";
    std::cout << "4 - IMPRIME: Imprime a pilha\n";
    std::cout << "5 - Para fechar o programa\n";
}

void push(pilhaPtr *topo, int info) {
    auto novo = (pilhaPtr) malloc(sizeof(pilha));

    if (novo != nullptr) {
        novo->dado = info;
        novo->prox = *topo;
        *topo = novo;
    } else {
        std::cout << info << " nao inserido. Sem memoria disponivel.\n";
    }
}

int pop(pilhaPtr *topo) {
    pilhaPtr aux = *topo;
    int valor = (*topo)->dado;
    *topo = (*topo)->prox;
    delete(aux);
    return valor;
}

int vazia(pilhaPtr topo) {
    return topo == nullptr;
}

void remove(pilhaPtr *topo, int valor) {
    pilhaPtr pilhaAux = nullptr, pilha = *topo;
    int i = 0;

    while (i != 1 && pilha != nullptr) {
        if (pilha->dado == valor)
            i = 1;
        else
            pilha = pilha->prox;
    }

    if (i == 1) {
        while ((*topo)->dado != valor)
            push(&pilhaAux, pop(topo));

        pop(topo);

        while (pilhaAux != nullptr)
            push(topo, pop(&pilhaAux));

        std::cout << "\nValor \" " << valor << "\" removido da pilha.\n";
    } else
        std::cout << "Valor \\" << valor << "\" nao encontrado na pilha!\n";
}

void imprimePilha(pilhaPtr aux) {
    std::cout << "\n";

    if (aux == nullptr) {
        std::cout << "A pilha esta vazia!\n";
        std::cout << "\nPressione enter para voltar ao menu.";
        getch();
    } else {
        std::cout << "Pilha:";

        while (aux != nullptr) {
            std::cout << " " << aux->dado << " ";
            aux = aux->prox;
        }

        std::cout << "\nPressione enter para voltar ao menu.";
        getch();
    }
}

int main() {
    pilhaPtr P = nullptr;
    int opcao, quantidadeDados, i, valor;

    menu();
    std::cin >> opcao;

    do {
        switch (opcao) {
            case 1:
                std::cout << "Quantidade de dados a inserir:";
                std::cin >> quantidadeDados;

                for (i = 0; i < quantidadeDados; i++) {
                    std::cout << "\nEscreva o valor do " << i + 1 << ":";
                    std::cin >> valor;
                    push(&P, valor);
                }

                imprimePilha(P);
                break;
            case 2:
                if (!vazia(P))
                    std::cout << "Valor desempilhado \"" << pop(&P) << "\".\n";

                imprimePilha(P);
                break;
            case 3:
                std::cout << "Valor a ser removido:\n";
                std::cin >> valor;
                remove(&P, valor);
                imprimePilha(P);
                break;
            case 4:
                imprimePilha(P);
                break;
            case 5:
                delete(P);
                break;
            default:
                std::cout << "Opcao invalida!\n";
                menu();
                break;
        }

        if (opcao != 5) {
            std::cout << "\n";
            menu();
            std::cin >> opcao;
        }
    } while (opcao != 5);
}
