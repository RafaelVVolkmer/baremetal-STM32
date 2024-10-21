/* =============================================================================
 *  @ingroup    STM32_baremetal_examples
 *  @addtogroup STM32_baremetal_examples Baremetal
 *
 *  @package    STM32_baremetal
 *  @brief      This module provides a set of exercises for practicing register 
 *              manipulation in baremetal programming on 32-bit ARM Cortex-M4 
 *              microcontrollers from STMicroelectronics.
 *
 *  @details    This code checks the input from 3 user keys and, depending on the 
 *              condition, displays the following output on LEDs:
 *                  - If the input is even, the first LED is turned on.
 *                  - If the input is odd, the second LED is turned on.
 * 
 *  @file       oddOrEvenOnLed.c
 * 
 *  @author     Rafael V. Volkmer       (rafael.v.volkmer@gmail.com.br)
 *  @date       21/10/2024
 *
 * ===========================================================================*/

/*==========================================
 *             Private includes
 * ========================================== */

/* Dependencies of libc */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implementeds */
#include "stm32f4xx.h"

/*==========================================
 *             Private Defines
 * ========================================== */

#define KEYS_MASK           (uint8_t)(0b111)
#define LEDS_MASK           (uint8_t)(0b11)

#define MAX_KEY_CONDITIONS  (uint8_t)(2u)

/*==========================================
 *              Private Types
 * ========================================== */

typedef enum keyConditions
{
    EVEN_KEY_PRESSED =      (uint8_t)(0u),
    ODD_KEY_PRESSED  =      (uint8_t)(1u)
}key_conditions_t;

/*==========================================
 *         Private Global Variables
 * ========================================== */

static const uint8_t user_output[MAX_KEY_CONDITIONS]
{
    [EVEN_KEY_PRESSED]  = 0b01;
    [ODD_KEY_PRESSED]   = 0b10;
}

/*==========================================
 *        Private Function Prototypes
 * ========================================== */

static key_conditions_t checkKeyConditions(uint8_t binary_number);

/*==========================================
 *              Main Function
 * ========================================== */

int main (void)
{
    /* private variable declaration ------------------------------------------*/
    uint8_t break_condition = 0u;

    uint8_t user_input      = 0u;

    uint8_t condition_check = 0u;

    /* Enable Clock for each GPIO --------------------------------------------*/
    RCC->AHB1ENR |= 
    (
        RCC_AHB1ENR_GPIOBEN |    /* GPIOB clock enabled */
        RCC_AHB1ENR_GPIOCEN      /* GPIOC clock enabled */
    );

    /* Set the user keys inputs ----------------------------------------------*/
    GPIOB->MODER |= 
    (
        (0b00 << 4u) |          /* Mux PB2 for digital input */ 
        (0b00 << 2u) |          /* Mux PB1 for digital input */
        (0b00 << 0u)            /* Mux PB0 for digital input */
    );

    /* Set key inputs for pull-down internal resistor ------------------------*/
    GPIOC->PUPDR |= 
    (
        (0b00 << 4u) |          /* Clean pull resistor register at PB2 position */
        (0b00 << 2u) |          /* Clean pull resistor register at PB1 position */
        (0b00 << 0u)            /* Clean pull resistor register at PB0 position  */
    );

    GPIOC->PUPDR |= 
    (
        (0b01 << 4u) |          /* Set PB2 input for pull-down */
        (0b01 << 2u) |          /* Set PB1 input for pull-down */
        (0b01 << 0u)            /* Set PB0 finput or pull-down */
    );
    
    /* Set the user leds outputs ---------------------------------------------*/
    GPIOC->MODER |= 
    ( 
        (0b00 << 4u) |          /* Clean mux register at PC2 position */
        (0b00 << 2u) |          /* Clean mux register at PC1 position */
        (0b00 << 0u)            /* Clean mux register at PC0 position */
    );

    GPIOC->MODER |= 
    ( 
        (0b01 << 4u) |          /* Mux PC2 for digital output */
        (0b01 << 2u) |          /* Mux PC1 for digital output */
        (0b01 << 0u)            /* Mux PC0 for digital output */
    );

    /* Main Loop -------------------------------------------------------------*/
    while( !(break_condition) )
    {
        user_input      = (GPIOB->IDR & KEYS_MASK);         

        condition_check = checkKeyConditions(user_input);

        GPIOC->ODR      = (user_output[condition_check] & LEDS_MASK);
    }

    /* Main return ------------------------------------------------------------*/
    return 0;
}

/*==========================================
 *      Private Function Declaration
 * ========================================== */

/**
 *  @fn         checkKeyConditions
 *  @package    STM32_baremetal
 * 
 *  @brief      Determines if the number of '1' bits in a binary number is even or odd.
 *
 *  @details    This function evaluates the binary representation of a given number 
 *              to ascertain whether the count of '1' bits is even or odd. 
 *              It performs the following actions:
 * 
 *                  - Initializes a counter to track the number of '1' bits.
 *                  - Iterates through each bit of the binary number.
 *                  - Increments the counter for every '1' bit encountered.
 *                  - Determines if the total count of '1' bits is even or odd.
 *                  - Returns the corresponding key condition based on the parity 
 *                    of the count.
 *
 *  @param      binary_number [in] : The 8-bit binary number to be evaluated.
 *
 *  @return     EVEN_KEY_PRESSED: if the count of '1' bits is even or zero.
 *              ODD_KEY_PRESSED : if the count of '1' bits is odd.
 */
static key_conditions_t checkKeyConditions(uint8_t binary_number) 
{
    key_conditions_t ret;
    
    uint8_t counter = 0u;
    
    while(binary_number) 
    {
        counter += number & 1u;
        binary_number >>= 1u;
    }
    
    ret = ((counter % 2u) == 0u || counter == 0u) ? ODD_BINARY : EVEN_BINARY;
    
end_of_function:
    return ret;
}

/* end of file */
