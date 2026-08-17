# Requisitos e critérios de aceite

## 1. Objetivo

Esta seção define os requisitos funcionais e não funcionais esperados para a primeira versão do `simpleBash`, além dos critérios de aceite que validam se a entrega atende ao objetivo inicial do projeto.

---

## 2. Requisitos funcionais

### RF-01: leitura de comandos
O sistema deve permitir que o usuário digite comandos no terminal.

**Critério de aceite:**
- ao iniciar o shell, o usuário consegue digitar uma instrução na linha de comando;
- a entrada é capturada corretamente.

### RF-02: execução de comandos externos
O sistema deve conseguir executar comandos externos do sistema operacional.

**Critério de aceite:**
- ao digitar `ls`, `pwd` ou similar, o shell executa o programa;
- a saída do comando aparece no terminal.

### RF-03: execução de comandos internos
O sistema deve implementar pelo menos comandos internos básicos, como `cd`, `exit` e `pwd`.

**Critério de aceite:**
- `cd` altera o diretório atual do shell;
- `exit` encerra a aplicação;
- `pwd` exibe o diretório atual.

### RF-04: tratamento de entrada vazia
O sistema não deve falhar ao receber uma linha vazia.

**Critério de aceite:**
- ao pressionar Enter sem texto, o shell retorna ao prompt sem erro crítico.

### RF-05: tratamento de comando inválido
Quando o usuário digitar um comando inexistente, o shell deve informar de forma clara.

**Critério de aceite:**
- uma mensagem de erro é exibida ao usuário;
- o shell permanece em execução.

### RF-06: loop principal
O sistema deve manter um ciclo de execução até que o usuário escolha sair.

**Critério de aceite:**
- após executar um comando, o shell retorna ao prompt;
- a aplicação continua funcionando até `exit`.

---

## 3. Requisitos não funcionais

### RNF-01: clareza da arquitetura
O código deve ser organizado em módulos com responsabilidades bem definidas.

**Critério de aceite:**
- a lógica de parsing está separada da lógica de execução;
- o código fica fácil de entender e manter.

### RNF-02: simplicidade
A solução deve ser didática e adequada ao nível inicial do projeto.

**Critério de aceite:**
- estruturas são simples;
- o código evita complexidade desnecessária.

### RNF-03: compatibilidade com ambientes Unix/Linux
O projeto deve ser executado em ambientes baseados em Unix/Linux.

**Critério de aceite:**
- o programa compila e executa em ambiente Linux sem ajustes complexos.

---

## 4. Critérios de aceite da entrega inicial

A entrega inicial será considerada concluída quando:

1. o shell compila sem erros utilizando `make`;
2. o programa inicia no terminal e exibe um prompt;
3. comandos externos básicos funcionam corretamente;
4. comandos internos básicos `cd`, `pwd` e `exit` funcionam;
5. comando inválido gera mensagem de erro sem quebrar o shell;
6. estrutura do projeto está documentada e organizada em módulos;
7. a documentação em `/doc` comunica claramente a proposta e a arquitetura do sistema.

---

## 5. Critérios de qualidade

A implementação deve respeitar os seguintes critérios:

- uso de nomenclatura clara;
- funções pequenas e com objetivo bem definido;
- tratamento de erros simples, porém consistente;
- organização dos arquivos em `include/` e `src/`;
- documentação mínima de cada módulo.

---

## 6. Conclusão

Os requisitos e critérios de aceite definidos neste documento orientam a implementação e a validação da primeira versão do shell. Com esses critérios, a equipe ou o estudante consegue avaliar se a solução atendeu ao objetivo inicial do projeto e se a base está pronta para evoluir.
