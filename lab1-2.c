/*******************************************************************************
* Copyright (C) 2020 TUSUR, FB
* File              : Source.c
* Compiler          : Microsoft Visual Studio 2015
* Version           : 14.0.5
* Created File      : 23.02.2020
* Last modified     : 9.06.2020
*
* Support mail      : chernoffilya1997@mail.ru
*
* Description       : a program for counting the number of ones and zeros
*					  in the binary representation of numbers in an array
                  
*******************************************************************************/

#include "main.h" 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdint.h>
#include "mstn_clk.h" 
#include "mstn_led.h" 
#include "mstn_adc.h" 
#include "mstn_button.h" 
#include "mstn_usb.h" 
#define N 10

int8_t A[N] = { 1,2,3,4,5,6,7,8,8,8 };
int8_t quantity01A[2];
void counter01(int8_t Ainput[], int8_t size_A, int8_t quantity01A[])
{
    for (int8_t i = 0; i < size_A; i++)
    {
        int8_t temp = A[i];
         int8_t byte_size = 8;  
        for (int8_t j = 0; j < byte_size; j++)
        {
            if (temp % 2 == 0)
            {
                quantity01A[0]++;
            }
            else
            {
                quantity01A[1]++; 
            }                   
            temp = temp / 2;         
        }
    }
   
}

int main(int argc, char *argv[]) 
{
	counter01(A, N, quantity01A);
    printf("0 count %d   ", quantity01A[0]);
    printf("1 count %d   ", quantity01A[1]);
   
    BTN_UserButtonInit();
    while(1) 
    {
        if ((BTN_UserButtonRead() == PRESSED))
        {
			counter01(A, N, quantity01A);
			printf("0 count %d   ", quantity01A[0]);
			printf("1 count %d   ", quantity01A[1]);
            
            for (int i=0;i<quantity01A[0];++i){
            LED_SetGreenState(TURN_ON); 
            Delay (1000); 
            LED_SetGreenState(TURN_OFF); 
            Delay (1000);
            }
            for (int i=0;i<quantity01A[1];++i){
            LED_SetRedState(TURN_ON); 
            Delay (1000); 
            LED_SetRedState(TURN_OFF); 
            Delay (1000);
            }
        }   
    }
return EXIT_SUCCESS; 
}