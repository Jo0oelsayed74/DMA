#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

#include "../include/MRCC_Interface.h"
#include "../include/MSTK_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MDMA_Interface.h"

void LED_ON();

int main(void) {
    //2 Arrays of CPU
    u32 array1[500];
    u32 array2[500];

    //2 Arrays of DMA
    u32 array3[500];
    u32 array4[500];

    //initialization values of array1 and array3
    for (u16 i = 0; i < 500; i++) {
        array1[i] = i + 1;
        array3[i] = 1000 - i;
    }

    MRCC_voidInit();
    MSTK_voidInit();

    MRCC_voidEnablePeripheral(RCC_AHB1, RCC_AHB1_GPIOA);
    MRCC_voidEnablePeripheral(RCC_AHB1, RCC_AHB1_DMA2);

    MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN0, GPIO_PUSH_PULL, GPIO_HIGH_SPEED);

    MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT);
    MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN2, GPIO_PUSH_PULL, GPIO_HIGH_SPEED);

    MNVIC_voidEnablePeripheralInterrupt(DMA_Stream0);

    DMA2_Init();

    DMA2_SetStreamConfigration(0, 0, array3, array4, 4, 500);
    /* first argument : DMA stream number
     * Second argument : DMA channel number
     * Third argument : The source address for the DMA transfer
     * Fourth argument : The destination address for the DMA transfer
     * Fifth argument : The data size in bytes
     * sixth argument : Number of data transfers to be performed
     * */

    DMA2_SetCallBack(0, LED_ON);

    DMA2_enableStream(0);

    for (u16 i = 0; i < 500; i++) {
        array2[i] = array1[i];
    }

    //Delay 500 milliseconds
    MSTK_voidDelayms(500);
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
}

void LED_ON(void) {
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_HIGH);
    //Delay 1000 milliseconds
    MSTK_voidDelayms(1000);
}
