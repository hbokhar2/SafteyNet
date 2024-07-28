/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h" 

int main(void)
{
    CyGlobalIntEnable;
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();

    int ii = 0;
    uint16 ADCResult = ADC_SAR_Seq_1_GetResult16(0);
    
    ADC_SAR_Seq_1_Enable();
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT);
    

    /*Place your initialization/startup code here (e.g. MyInst_Start()) */
    
   

    for(;;){
        /* Place your application code here. */
        CyDelay(10);
        
        if (ADCResult > 100 && Switch1_Read() == 0){
            Speaker_Write(1);
            Red1_Write(1); 
            Blue1_Write(0);    /* Red */
            Green1_Write(1);  

            Red2_Write(0);
            Blue2_Write(0);   
            Green2_Write(0);
            CyDelay(500);
        }else{
            Red1_Write(0); 
            Blue1_Write(0);    /* Red */
            Green1_Write(1);  

            Red2_Write(0);
            Blue2_Write(0);   
            Green2_Write(1); 
        }
        
        for(ii = 0; ii < 255; ii++){        /* Flashing */
            PWM_2_WriteCompare(ii);
            PWM_1_WriteCompare(ii);
            CyDelay(5);
        }
        for(ii = 255; ii > 0; ii--){               /* Flashing */
            PWM_2_WriteCompare(ii);
            PWM_1_WriteCompare(ii);
            CyDelay(5);
        }

        for(ii = 0; ii < 255; ii++){            /* Flashing */
            PWM_2_WriteCompare(ii);
            PWM_1_WriteCompare(ii);
            CyDelay(5);
        }
        for(ii = 255; ii > 0; ii--){          /* Flashing */
            PWM_2_WriteCompare(ii);
            PWM_1_WriteCompare(ii);
            CyDelay(5);
        }
        PWM_3_WriteCompare(250);
        }
        
    }


/* [] END OF FILE */
