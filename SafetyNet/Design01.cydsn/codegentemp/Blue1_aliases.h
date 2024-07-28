/*******************************************************************************
* File Name: Blue1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Blue1_ALIASES_H) /* Pins Blue1_ALIASES_H */
#define CY_PINS_Blue1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Blue1_0			(Blue1__0__PC)
#define Blue1_0_PS		(Blue1__0__PS)
#define Blue1_0_PC		(Blue1__0__PC)
#define Blue1_0_DR		(Blue1__0__DR)
#define Blue1_0_SHIFT	(Blue1__0__SHIFT)
#define Blue1_0_INTR	((uint16)((uint16)0x0003u << (Blue1__0__SHIFT*2u)))

#define Blue1_INTR_ALL	 ((uint16)(Blue1_0_INTR))


#endif /* End Pins Blue1_ALIASES_H */


/* [] END OF FILE */
