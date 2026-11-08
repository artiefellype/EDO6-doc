# Programação em C no EDO6

Sim, a controladora EDO6 pode ser programada em C. O KaziCode não apenas mostra
um editor: ele inclui os arquivos de suporte da placa, compila o programa, gera
o binário e o transfere para o controlador.

Este guia foi escrito a partir do perfil padrão `EV6` do KaziCode 1.0.31 e dos
arquivos `.c`, `.elf` e `.bin` existentes neste repositório.

> [!IMPORTANT]
> Use o perfil `EV6` com esta controladora. Os perfis `EV6+` e `V9` têm formas
> de transferência ou microcontroladores diferentes. Em especial, o `V9` usa um
> STM32F407/Cortex-M4 e não deve ser confundido com o EDO6 documentado aqui.

## Primeiro programa

No menu superior do KaziCode:

1. altere o modo de blocos para `Codeock`;
2. selecione a linguagem `C`;
3. confirme que o modelo da controladora está como `EV6`;
4. crie ou abra um projeto.

Um programa mínimo segue esta estrutura:

```c
#define _TASK_1_ 1

#include "KYLib.h"
#include "stm32f10x.h"
#include "taskMange.h"

void task1(void) {
    SetMotor(1, -40);
    SetMotor(2, -40);
    SetWaitForTime(2.0f);
    SetMotor(1, 0);
    SetMotor(2, 0);
}
```

`_TASK_1_` informa ao arquivo `taskMange.h` que a função `task1` deve ser
criada como uma tarefa do FreeRTOS. O suporte fornecido pelo KaziCode prevê até
oito tarefas, de `task1` a `task8`, habilitadas pelas macros correspondentes.

As funções de alto nível, como `SetMotor`, `SetWaitForTime` e
`Get_Colour_Data`, pertencem à `KYLib`.

Um exemplo real pode ser consultado em
[`line-follow.c`](../../aulas/aula_04-sensores/CODIGO-sensor_de_cores_e_luz/sensor-de-cor/code/line-follow.c).

## O que acontece ao compilar

Para o perfil `EV6`, o KaziCode executa estas etapas:

1. salva o código do projeto em um arquivo `.c`;
2. compila para ARM Cortex-M3 com `arm-none-eabi-gcc`;
3. liga o objeto do usuário com `KYLib`, FreeRTOS, inicialização do STM32 e os
   demais objetos fornecidos pelo KaziCode;
4. usa `stm32_flash.ld` para posicionar o programa na região reservada;
5. gera um `.elf` e o converte em `.bin` com `arm-none-eabi-objcopy`;
6. copia o `.bin` para o armazenamento removível da controladora.

Os principais parâmetros observados no KaziCode 1.0.31 são:

```text
-mcpu=cortex-m3
-mthumb
-Os
-DF_CPU=72000000UL
-ffunction-sections
-fdata-sections
-std=gnu99
```

O linker do perfil `EV6` descreve um STM32F10x de alta densidade com 512 KiB de
flash e 64 KiB de RAM. A região destinada ao programa começa em `0x08070000` e
tem 64 KiB.

> [!WARNING]
> Não substitua o linker script por um projeto STM32 genérico. Gravar um binário
> no endereço errado pode sobrescrever o firmware que recebe e executa os
> projetos do usuário.

## Posso usar outra ferramenta?

Sim. O compilador usado é o GNU Arm Embedded Toolchain, então o código pode ser
editado em VS Code, Eclipse, STM32CubeIDE ou outro editor. Existem dois níveis de
integração:

### Outro editor, KaziCode para compilar e enviar

É o caminho mais simples. Edite o `.c` na ferramenta de sua preferência e use o
KaziCode para compilar e transferir. Assim, as bibliotecas e o layout de memória
continuam sendo os fornecidos para o kit.

### Compilação completamente externa

Também é possível, desde que o projeto externo utilize os mesmos elementos do
perfil `EV6` instalado com o KaziCode:

- headers em `resources/app/compiler/gcc/h`;
- objetos pré-compilados em `resources/app/compiler/gcc/o`;
- linker script `resources/app/compiler/gcc/o/stm32_flash.ld`;
- `arm-none-eabi-gcc` e `arm-none-eabi-objcopy`;
- os mesmos parâmetros de arquitetura e frequência;
- cópia do `.bin` final para o volume da controladora.

O fluxo equivalente, com caminhos abreviados, é:

```text
arm-none-eabi-gcc [flags do EV6] -I <kazicode>/compiler/gcc/h -c projeto.c
arm-none-eabi-gcc [flags do EV6] -T <kazicode>/compiler/gcc/o/stm32_flash.ld \
  <kazicode>/compiler/gcc/o/*.o projeto.o -lm -o projeto.elf
arm-none-eabi-objcopy -O binary projeto.elf projeto.bin
```

Isso não é o mesmo que criar um projeto STM32 vazio: `KYLib`, FreeRTOS, o
startup e os objetos do firmware fazem parte do ambiente esperado pelo EDO6.

## Arquivos gerados

| Extensão | Função |
| --- | --- |
| `.c` | código-fonte do projeto |
| `.o` | código do usuário compilado |
| `.elf` | programa ligado, com metadados e símbolos |
| `.bin` | imagem copiada para a controladora |

Mantenha o `.c` como fonte principal. Os arquivos `.elf` e `.bin` podem ser
recriados pelo mesmo ambiente de compilação.

## Limites conhecidos

- a API pública da `KYLib` está declarada nos headers, mas parte da implementação
  é distribuída apenas como objeto compilado;
- os arquivos do pacote mencionam STM32F103ZE e STM32F103VET6 em pontos
  diferentes; confirme o componente físico antes de usar um gravador externo;
- no Linux, o toolchain ARM precisa estar instalado no sistema e disponível no
  `PATH`;
- a transferência normal do perfil `EV6` é feita pelo volume USB da
  controladora, não por ST-Link.
