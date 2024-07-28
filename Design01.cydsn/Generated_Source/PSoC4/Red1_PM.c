/*******************************************************************************
* File Name: Red1.c  
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
#include "Red1.h"

static Red1_BACKUP_STRUCT  Red1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Red1_Sleep
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
*  \snippet Red1_SUT.c usage_Red1_Sleep_Wakeup
*******************************************************************************/
void Red1_Sleep(void)
{
    #if defined(Red1__PC)
        Red1_backup.pcState = Red1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Red1_backup.usbState = Red1_CR1_REG;
            Red1_USB_POWER_REG |= Red1_USBIO_ENTER_SLEEP;
            Red1_CR1_REG &= Red1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Red1__SIO)
        Red1_backup.sioState = Red1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Red1_SIO_REG &= (uint32)(~Red1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Red1_Wakeup
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
*  Refer to Red1_Sleep() for an example usage.
*******************************************************************************/
void Red1_Wakeup(void)
{
    #if defined(Red1__PC)
        Red1_PC = Red1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Red1_USB_POWER_REG &= Red1_USBIO_EXIT_SLEEP_PH1;
            Red1_CR1_REG = Red1_backup.usbState;
            Red1_USB_POWER_REG &= Red1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Red1__SIO)
        Red1_SIO_REG = Red1_backup.sioState;
    #endif
}


/* [] END OF FILE */
