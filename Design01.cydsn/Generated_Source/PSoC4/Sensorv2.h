/*******************************************************************************
* File Name: Sensorv2.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Sensorv2_H) /* Pins Sensorv2_H */
#define CY_PINS_Sensorv2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Sensorv2_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Sensorv2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Sensorv2_Read(void);
void    Sensorv2_Write(uint8 value);
uint8   Sensorv2_ReadDataReg(void);
#if defined(Sensorv2__PC) || (CY_PSOC4_4200L) 
    void    Sensorv2_SetDriveMode(uint8 mode);
#endif
void    Sensorv2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sensorv2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Sensorv2_Sleep(void); 
void Sensorv2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Sensorv2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Sensorv2_DRIVE_MODE_BITS        (3)
    #define Sensorv2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Sensorv2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Sensorv2_SetDriveMode() function.
         *  @{
         */
        #define Sensorv2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Sensorv2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Sensorv2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Sensorv2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Sensorv2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Sensorv2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Sensorv2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Sensorv2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Sensorv2_MASK               Sensorv2__MASK
#define Sensorv2_SHIFT              Sensorv2__SHIFT
#define Sensorv2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sensorv2_SetInterruptMode() function.
     *  @{
     */
        #define Sensorv2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Sensorv2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Sensorv2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Sensorv2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Sensorv2__SIO)
    #define Sensorv2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Sensorv2__PC) && (CY_PSOC4_4200L)
    #define Sensorv2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Sensorv2_USBIO_DISABLE              ((uint32)(~Sensorv2_USBIO_ENABLE))
    #define Sensorv2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Sensorv2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Sensorv2_USBIO_ENTER_SLEEP          ((uint32)((1u << Sensorv2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Sensorv2_USBIO_SUSPEND_DEL_SHIFT)))
    #define Sensorv2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Sensorv2_USBIO_SUSPEND_SHIFT)))
    #define Sensorv2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Sensorv2_USBIO_SUSPEND_DEL_SHIFT)))
    #define Sensorv2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Sensorv2__PC)
    /* Port Configuration */
    #define Sensorv2_PC                 (* (reg32 *) Sensorv2__PC)
#endif
/* Pin State */
#define Sensorv2_PS                     (* (reg32 *) Sensorv2__PS)
/* Data Register */
#define Sensorv2_DR                     (* (reg32 *) Sensorv2__DR)
/* Input Buffer Disable Override */
#define Sensorv2_INP_DIS                (* (reg32 *) Sensorv2__PC2)

/* Interrupt configuration Registers */
#define Sensorv2_INTCFG                 (* (reg32 *) Sensorv2__INTCFG)
#define Sensorv2_INTSTAT                (* (reg32 *) Sensorv2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Sensorv2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Sensorv2__SIO)
    #define Sensorv2_SIO_REG            (* (reg32 *) Sensorv2__SIO)
#endif /* (Sensorv2__SIO_CFG) */

/* USBIO registers */
#if !defined(Sensorv2__PC) && (CY_PSOC4_4200L)
    #define Sensorv2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Sensorv2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Sensorv2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Sensorv2_DRIVE_MODE_SHIFT       (0x00u)
#define Sensorv2_DRIVE_MODE_MASK        (0x07u << Sensorv2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Sensorv2_H */


/* [] END OF FILE */
