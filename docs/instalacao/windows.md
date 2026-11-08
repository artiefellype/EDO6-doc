# Instalação no Windows

## 1. Baixe e confira o arquivo

Baixe `KaziCode-1.0.31-windows-x64.rar` na
[release do projeto](https://github.com/artiefellype/EDO6-doc/releases/tag/kazicode-1.0.31)
e confira o [SHA-256 publicado](./README.md#sha-256).

## 2. Extraia o instalador

Abra o `.rar` com uma ferramenta compatível. Dentro dele está o arquivo:

```text
KaziCode Setup 1.0.31.exe
```

O nome do pacote original mencionava 1.0.32, mas o executável e o aplicativo
declaram a versão 1.0.31.

## 3. Instale o KaziCode

Execute o instalador e siga as telas apresentadas. Ele não possui assinatura
digital, portanto o Windows pode mostrar um alerta de origem desconhecida.
Confira o checksum do arquivo e mantenha a proteção do sistema ativada.

## 4. Conecte a controladora

1. Ligue a controladora EDO6.
2. Conecte-a ao computador pelo cabo USB.
3. Aguarde o Windows reconhecer um pequeno dispositivo de armazenamento
   removível.
4. Abra o KaziCode e mantenha selecionado o perfil `EV6` para os exemplos deste
   repositório.

Ao enviar um programa em C, o KaziCode gera um arquivo `.bin` e o copia para
esse dispositivo. Não desconecte o cabo durante a transferência.

## Problemas comuns

### A controladora não aparece

- teste outra porta USB e, se possível, outro cabo de dados;
- confira se a controladora está ligada;
- feche e abra novamente o KaziCode depois de conectar o equipamento;
- verifique se surgiu uma nova unidade removível no Explorador de Arquivos.

### O programa compila, mas não é transferido

O perfil `EV6` procura o armazenamento removível da controladora. Confira se a
unidade continua montada e se há apenas uma controladora conectada.

### O Windows bloqueou o instalador

Não desative o antivírus. Confirme primeiro o SHA-256 e registre no issue a
mensagem exata apresentada pelo Windows.
