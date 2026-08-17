# Roadmap e marcos

## 1. Visão geral

Este documento organiza a evolução do projeto `simpleBash` em marcos incrementais. A ideia é partir de uma base funcional e evoluir gradativamente, conforme o conhecimento e as capacidades do sistema.

---

## 2. Marco 1: base do shell

**Objetivo:** construir a estrutura mínima do projeto.

**Entregas esperadas:**
- shell com loop principal;
- leitura de comandos do terminal;
- compilação com `Makefile`;
- organização inicial em `src/` e `include/`;
- documentação inicial da arquitetura.

**Critério de aceite:**
- o programa inicia e permanece em execução em modo interativo.

---

## 3. Marco 2: execução de comandos externos

**Objetivo:** permitir que o shell execute programas do sistema operacional.

**Entregas esperadas:**
- uso de `fork()` e `execvp()`;
- execução de comandos como `ls`, `pwd`, `echo`;
- retorno da saída para o terminal;
- tratamento básico de erro.

**Critério de aceite:**
- comandos externos executam corretamente e retornam ao prompt.

---

## 4. Marco 3: comandos internos básicos

**Objetivo:** implementar funcionalidades próprias do shell.

**Entregas esperadas:**
- `cd`;
- `pwd`;
- `exit`;
- `help` (opcional nesta fase).

**Critério de aceite:**
- comandos internos alteram o estado do shell de forma correta.

---

## 5. Marco 4: melhorias de interação

**Objetivo:** melhorar a experiência do usuário.

**Entregas esperadas:**
- tratamento de linha vazia;
- mensagens de erro mais claras;
- melhor organização do prompt;
- suporte a caminhos relativos e absolutos.

**Critério de aceite:**
- shell continua funcional mesmo diante de entradas inesperadas.

---

## 6. Marco 5: extensões avançadas

**Objetivo:** expandir o shell conforme evolução do projeto.

**Entregas esperadas:**
- redirecionamento de entrada e saída;
- pipes;
- execução em segundo plano;
- histórico de comandos;
- suporte a variáveis de ambiente.

**Critério de aceite:**
- novas funcionalidades são integradas sem quebrar a arquitetura base.

---

## 7. Critério geral de evolução

A evolução do projeto deve seguir um princípio simples: cada novo marco deve reforçar a base já construída, sem comprometer a clareza da arquitetura e a estabilidade da solução.

---

## 8. Conclusão

O roadmap do `simpleBash` parte de uma base mínima e funcional, com evolução planejada em etapas para garantir que cada funcionalidade seja compreendida, testada e integrada de forma consistente.
