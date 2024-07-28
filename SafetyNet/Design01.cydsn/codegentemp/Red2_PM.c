/*******************************************************************************
* File Name: Red2.c  
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
#include "Red2.h"

static Red2_BACKUP_STRUCT  Red2_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Red2_Sleep
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
*  \snippet Red2_SUT.c usage_Red2_Sleep_Wakeup
*******************************************************************************/
void Red2_Sleep(void)
{
    #if defined(Red2__PC)
        Red2_backup.pcState = Red2_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Red2_backup.usbState = Red2_CR1_REG;
            Red2_USB_POWER_REG |= Red2_USBIO_ENTER_SLEEP;
            Red2_CR1_REG &= Red2_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Red2__SIO)
        Red2_backup.sioState = Red2_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Red2_SIO_REG &= (uint32)(~Red2_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Red2_Wakeup
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
*  Refer to Red2_Sleep() for an example usage.
*******************************************************************************/
void Red2_Wakeup(void)
{
    #if defined(Red2__PC)
        Red2_PC = Red2_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Red2_USB_POWER_REG &= Red2_USBIO_EXIT_SLEEP_PH1;
            Red2_CR1_REG = Red2_backup.usbState;
            Red2_USB_POWER_REG &= Red2_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Red2__SIO)
        Red2_SIO_REG = Red2_backup.sioState;
    #endif
}


/* [] END OF FILE */
