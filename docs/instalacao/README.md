# Downloads do KaziCode

Os links originais do fabricante deixaram de funcionar. Os arquivos abaixo
foram recuperados para preservação e conferidos antes da publicação, mas não
foram produzidos por este projeto.

> [!WARNING]
> O instalador do Windows não possui assinatura digital. Confira o checksum
> antes de executá-lo e nunca desative o antivírus para concluir a instalação.

## Arquivos disponíveis

| Sistema | Arquivo | Versão interna | Estado |
| --- | --- | --- | --- |
| Windows x64 | `KaziCode-1.0.31-windows-x64.rar` | 1.0.31 | arquivo íntegro; executável não assinado |
| Linux x64 | `KaziCode-1.0.31-linux-x64.zip` | 1.0.31 | estrutura do pacote conferida |
| Linux ARM64 | — | — | indisponível: a cópia recuperada estava truncada |

Os arquivos válidos serão publicados na
[release do KaziCode 1.0.31](https://github.com/artiefellype/EDO6-doc/releases/tag/kazicode-1.0.31).

### SHA-256

```text
b9791d94848bdb36db8655a4059e49f78f59467baa3efd5e88c9c84e8561315a  KaziCode-1.0.31-windows-x64.rar
cba615feb20e0de7bf907524698ededda89f718a6808c7225dd65a2c3eee7d59  KaziCode-1.0.31-linux-x64.zip
```

Renomear um arquivo não altera seu conteúdo nem o checksum. O pacote Windows
foi encontrado com o nome `KaziCode Setup 1.0.32_en.rar`, mas o instalador, os
metadados e o aplicativo dentro dele informam a versão **1.0.31**. Preferimos
publicá-lo com o nome correto e registrar aqui a divergência.

## Como conferir o checksum

### Windows (PowerShell)

```powershell
Get-FileHash .\KaziCode-1.0.31-windows-x64.rar -Algorithm SHA256
```

### Linux

```bash
sha256sum KaziCode-1.0.31-linux-x64.zip
```

O valor exibido deve ser exatamente igual ao correspondente na tabela acima.

## Validações realizadas

- os arquivos foram abertos e tiveram sua estrutura interna inspecionada;
- a versão foi conferida nos metadados do executável e no `package.json`;
- o executável Windows foi identificado como não assinado;
- os três pacotes recebidos foram verificados pelo Microsoft Defender em 8 de
  novembro de 2026, sem detecções registradas;
- o pacote ARM64 falhou na leitura por estar truncado e foi descartado da
  publicação.

Uma verificação antimalware não é garantia absoluta. Os checksums servem para
confirmar que o arquivo baixado é exatamente o mesmo que foi analisado aqui.

## Instalação

- [Windows](./windows.md)
- [Linux x64](./linux.md)

## E o `scratch-gui Setup 1.0.0`?

Não encontramos esse instalador como um produto separado. O KaziCode 1.0.31
já inclui sua interface derivada do Scratch 3 e as extensões necessárias para a
controladora. O Scratch comum, sozinho, não possui essas extensões nem o fluxo de
compilação e transferência do EDO6.

## Origem e licença

Os pacotes foram recuperados em outubro de 2026 depois que os links de
`file.kazi.ai` passaram a retornar erro. Os metadados do aplicativo declaram a
versão 1.0.31 e licença BSD-3-Clause. Esta cópia é mantida como espelho
comunitário, sem garantia e sem vínculo com o fabricante.
