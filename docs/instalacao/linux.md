# Instalação no Linux x64

O pacote recuperado para Linux é portátil: ele não traz um instalador separado.

> [!NOTE]
> A cópia ARM64 recebida estava truncada e não foi publicada. Estas instruções
> são para computadores Linux **x86-64**.

## 1. Baixe e confira o arquivo

Baixe [`KaziCode-1.0.31-linux-x64.zip`](https://github.com/artiefellype/EDO6-doc/releases/download/kazicode-1.0.31/KaziCode-1.0.31-linux-x64.zip)
na [release do projeto](https://github.com/artiefellype/EDO6-doc/releases/tag/kazicode-1.0.31)
e confira o [SHA-256 publicado](./README.md#sha-256).

## 2. Extraia e execute

```bash
unzip KaziCode-1.0.31-linux-x64.zip
cd scratch-en-linux
chmod +x kazicode
./kazicode
```

## 3. Prepare a compilação em C

No Linux, o KaziCode procura `arm-none-eabi-gcc` e
`arm-none-eabi-objcopy` no `PATH`. Instale o toolchain ARM para sua distribuição.
Em sistemas baseados em Debian ou Ubuntu, normalmente:

```bash
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi
```

Confirme a instalação:

```bash
arm-none-eabi-gcc --version
arm-none-eabi-objcopy --version
```

## 4. Conecte a controladora

O perfil `EV6` procura um pequeno dispositivo de armazenamento removível e
copia o `.bin` gerado para o ponto em que ele estiver montado.

Antes de abrir o KaziCode:

1. ligue a controladora;
2. conecte o cabo USB;
3. confirme que um novo volume removível foi montado;
4. mantenha o perfil `EV6` selecionado.

Se a controladora aparecer no sistema, mas o KaziCode não encontrá-la, registre
a saída dos comandos abaixo ao abrir um issue:

```bash
lsblk -o NAME,SIZE,TYPE,RM,MOUNTPOINTS
uname -m
```

Não desconecte o cabo enquanto o arquivo estiver sendo transferido.
