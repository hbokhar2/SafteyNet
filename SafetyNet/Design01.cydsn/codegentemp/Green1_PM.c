/*******************************************************************************
* File Name: Green1.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Green1.h"

static Green1_BACKUP_STRUCT  Green1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Green1_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Green1_SUT.c usage_Green1_Sleep_Wakeup
*******************************************************************************/
void Green1_Sleep(void)
{
    #if defined(Green1__PC)
        Green1_backup.pcState = Green1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Green1_backup.usbState = Green1_CR1_REG;
            Green1_USB_POWER_REG |= Green1_USBIO_ENTER_SLEEP;
            Green1_CR1_REG &= Green1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Green1__SIO)
        Green1_backup.sioState = Green1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Green1_SIO_REG &= (uint32)(~Green1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Green1_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Green1_Sleep() for an example usage.
*******************************************************************************/
void Green1_Wakeup(void)
{
    #if defined(Green1__PC)
        Green1_PC = Green1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Green1_USB_POWER_REG &= Green1_USBIO_EXIT_SLEEP_PH1;
            Green1_CR1_REG = Green1_backup.usbState;
            Green1_USB_POWER_REG &= Green1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Green1__SIO)
        Green1_SIO_REG = Green1_backup.sioState;
    #endif
}


/* [] END OF FILE */
