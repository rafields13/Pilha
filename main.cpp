#include <iostream>

struct Pilha {
    char dado;
    struct Pilha *prox;
};

typedef struct Pilha pilha;
typedef pilha *pilhaPtr;

void push(pilhaPtr *topo, char info) {
    auto novo = (pilhaPtr) malloc(sizeof(pilha));

    if (novo != nullptr) {
        novo->dado = info;
        novo->prox = *topo;
        *topo = novo;
    } else
        std::cout << "Elemento \"" << info << "\" nao inserido. Sem memoria disponivel.\n";
}

char pop(pilhaPtr *topo) {
    pilhaPtr aux = *topo;
    char valor = (*topo)->dado;
    *topo = (*topo)->prox;
    free(aux);

    return valor;
}

int vazia(pilhaPtr topo) {
    return topo == nullptr;
}

bool verificaExpressao(const std::string &expressao) {
    pilhaPtr P = nullptr;

    for (char caractere: expressao) {
        if (caractere == '(' || caractere == '[' || caractere == '{')
            push(&P, caractere);
        else if (caractere == ')' || caractere == ']' || caractere == '}') {
            if (vazia(P))
                return false;

            char topo = pop(&P);

            if ((caractere == ')' && topo != '(') || (caractere == ']' && topo != '[') ||
                (caractere == '}' && topo != '{'))
                return false;
        }
    }

    return vazia(P);
}

int main() {
    std::string expressao;
    std::cout << "Digite a expressao a ser verificada:";
    getline(std::cin, expressao);

    verificaExpressao(expressao) ? std::cout << "A expressao e valida.\n" : std::cout << "A expressao e invalida.\n";

    return 0;
}
