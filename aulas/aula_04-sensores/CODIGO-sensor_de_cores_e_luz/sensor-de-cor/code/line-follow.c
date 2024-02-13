#define _TASK_1_ 1
#include "KYLib.h"
#include "stm32f10x.h"
#include "taskMange.h"
void task1(void){
  if((((Get_Colour_Data(1,1))==(0)))||(((Get_Colour_Data(1,1))==(7)))) {
    SetMotor(1,-40);
    SetMotor(2,-30);
  } else {
    SetMotor(1,-30);
    SetMotor(2,-40);
  }
}
