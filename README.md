# Exercício Pilha

Um exemplo de utilização de pilha consiste em avaliar uma expressão aritmética segundo a utilização dos parênteses “()”, colchetes “[]” e chaves “{}”.  O problema consiste em criar uma pilha de caracteres. O programa recebe uma sequência de caracteres que representa uma expressão aritmética genérica, por exemplo: {A*(A+B)}. A expressão é lida caracter a caracter da esquerda para direita. Quando um caracter de abertura é encontrado “(”, “[”, ou “{” esse caracter é empilhado. Quando um caracter de fechamento é encontrado “)”,. “]”ou “}” o elemento do topo da pilha é comparado. Se o elemento do topo da pilha é representa a abertura do respectivo fechamento, então o elemento é desempilhado. Quando o final da expressão é obtido, se a pilha está vazia, então a expressão está correta, caso contrário a expressão está incorreta como na Figura.
 
## 1.	

Simule a ação do algoritmo de verificação de “()”, “{}” e “[]” em nas expressões aritméticas a seguir e verifique o resultado da avaliação (se a expressão é válida ou não):

### a)

- (A + B})

### b)

- {[A + B] – [(C - D)]

### c)

- (A + B) – {C + D} – [F + G]


### d)

- ((H) * {([J + K])})


### e)

- (((A)))
