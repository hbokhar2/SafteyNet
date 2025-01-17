/*******************************************************************************
* File Name: Green2.h  
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

#if !defined(CY_PINS_Green2_ALIASES_H) /* Pins Green2_ALIASES_H */
#define CY_PINS_Green2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Green2_0			(Green2__0__PC)
#define Green2_0_PS		(Green2__0__PS)
#define Green2_0_PC		(Green2__0__PC)
#define Green2_0_DR		(Green2__0__DR)
#define Green2_0_SHIFT	(Green2__0__SHIFT)
#define Green2_0_INTR	((uint16)((uint16)0x0003u << (Green2__0__SHIFT*2u)))

#define Green2_INTR_ALL	 ((uint16)(Green2_0_INTR))


#endif /* End Pins Green2_ALIASES_H */


/* [] END OF FILE */
