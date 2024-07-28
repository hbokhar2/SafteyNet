/*******************************************************************************
* File Name: Sensorv2.h  
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

#if !defined(CY_PINS_Sensorv2_ALIASES_H) /* Pins Sensorv2_ALIASES_H */
#define CY_PINS_Sensorv2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Sensorv2_0			(Sensorv2__0__PC)
#define Sensorv2_0_PS		(Sensorv2__0__PS)
#define Sensorv2_0_PC		(Sensorv2__0__PC)
#define Sensorv2_0_DR		(Sensorv2__0__DR)
#define Sensorv2_0_SHIFT	(Sensorv2__0__SHIFT)
#define Sensorv2_0_INTR	((uint16)((uint16)0x0003u << (Sensorv2__0__SHIFT*2u)))

#define Sensorv2_INTR_ALL	 ((uint16)(Sensorv2_0_INTR))


#endif /* End Pins Sensorv2_ALIASES_H */


/* [] END OF FILE */
