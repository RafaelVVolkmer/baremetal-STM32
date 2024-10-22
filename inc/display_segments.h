/* =============================================================================
 *  @ingroup    commun_includes
 *  @addtogroup commun_includes display_segments
 *
 *  @package    display_segments
 *  @brief      This module provides enumerations and mapping arrays for representing
 *              numeric, alphabetical, and hexadecimal values on 7-segment displays
 *              and character displays.
 *
 *  @details    This module defines several enumerations (`display_numbers_t`,
 *              `display_digits_t`, and `display_hex_t`) along with corresponding
 *              arrays that map these enums to their respective characters and
 *              binary codes. These mappings facilitate the display of numbers,
 *              letters, and hexadecimal values on various display types, ensuring
 *              consistent and efficient representation across different interfaces.
 *
 *              - **Character Mappings**: Arrays such as `display_number_char`,
 *                `display_digit_char`, and `display_hexadecimal_char` map enums to
 *                their respective ASCII characters for easy representation in
 *                character-based displays.
 *              
 *              - **Binary Code Mappings**: Arrays like `display_number`,
 *                `display_digit`, and `display_hexadecimal` map enums to specific
 *                binary codes used in 7-segment displays, where each bit corresponds
 *                to a particular segment of the display.
 *
 *              - **Attributes**: The arrays are defined with attributes
 *                `__attribute__((weak, used, aligned(4)))` to allow for flexibility
 *                in overriding, ensure they are retained during compilation, and
 *                optimize memory alignment for performance.
 *
 *  @file       display_segments.h
 * 
 *  @author     Rafael V. Volkmer (rafael.v.volkmer@gmail.com)
 *  @date       21/10/2024
 *
 * =============================================================================*/

#ifndef DISPLAY_SEGMENTS_H_
#define DISPLAY_SEGMENTS_H_

/*==========================================
 *             Private includes
 * ========================================== */

/* Dependencies of libc */
#include <stdint.h>

/*==========================================
 *             Private Defines
 * ========================================== */

/**
 * @def MAX_DISPLAY_NUM
 * @package    display_segments
 * @brief Maximum number of numerical display mappings.
 * 
 * @details This define specifies the total number of numerical display mappings available.
 */
#define MAX_DISPLAY_NUM             (uint8_t)(11U)

/**
 * @def MAX_DISPLAY_HEX
 * @package    display_segments
 * @brief Maximum number of hexadecimal display mappings.
 * 
 * @details This define specifies the total number of hexadecimal display mappings available.
 */
#define MAX_DISPLAY_HEX             (uint8_t)(17U)

/**
 * @def MAX_DISPLAY_DIG
 * @package    display_segments
 * @brief Maximum number of alphabetical display mappings.
 * 
 * @details This define specifies the total number of alphabetical display mappings available.
 */
#define MAX_DISPLAY_DIG             (uint8_t)(27U)


/*==========================================
 *             Private Macros
 * ========================================== */

/**
 * @def COMMUN_ANODE
 * @package    display_segments
 * @brief Converts a binary value for common anode displays.
 * 
 * @details This macro inverts the binary value to suit common anode display requirements.
 * 
 * @param binary_value The binary value to be converted.
 * 
 * @return The inverted binary value as an 8-bit unsigned integer.
 */
#define COMMUN_ANODE(binary_value)  (uint8_t)(!(binary_value))

/**
 * @def COMMUN_CATODE
 * @package    display_segments
 * @brief Converts a binary value for common cathode displays.
 * 
 * @details This macro passes the binary value through for common cathode display usage.
 * 
 * @param binary_value The binary value to be converted.
 * 
 * @return The original binary value as an 8-bit unsigned integer.
 */
#define COMMUN_CATODE(binary_value) (uint8_t)(binary_value)

/*==========================================
 *              Private Types
 * ========================================== */

/**
 *  @enum    displayNumber
 *  @typedef display_numbers_t
 *  @package    display_segments
 * 
 *  @brief   Enumeration for numeric display values.
 */
typedef enum __attribute__((aligned(1))) displayNumber
{
    DISPLAY_NUM_0       = (uint8_t)(0u),    /**< Display number 0 */
    DISPLAY_NUM_1       = (uint8_t)(1u),    /**< Display number 1 */
    DISPLAY_NUM_2       = (uint8_t)(2u),    /**< Display number 2 */
    DISPLAY_NUM_3       = (uint8_t)(3u),    /**< Display number 3 */
    DISPLAY_NUM_4       = (uint8_t)(4u),    /**< Display number 4 */
    DISPLAY_NUM_5       = (uint8_t)(5u),    /**< Display number 5 */
    DISPLAY_NUM_6       = (uint8_t)(6u),    /**< Display number 6 */
    DISPLAY_NUM_7       = (uint8_t)(7u),    /**< Display number 7 */
    DISPLAY_NUM_8       = (uint8_t)(8u),    /**< Display number 8 */
    DISPLAY_NUM_9       = (uint8_t)(9u),    /**< Display number 9 */
    DISPLAY_NUM_NULL    = (uint8_t)(10u)    /**< Null display number */
} display_numbers_t;

/**
 *  @enum    displayDigit
 *  @typedef display_digits_t
 *  @package    display_segments
 * 
 *  @brief   Enumeration for digit representations on display.
 */
typedef enum __attribute__((aligned(1))) displayDigit
{
    DISPLAY_DIG_A       = (uint8_t)(0u),    /**< Display digit A */
    DISPLAY_DIG_B       = (uint8_t)(1u),    /**< Display digit B */
    DISPLAY_DIG_C       = (uint8_t)(2u),    /**< Display digit C */
    DISPLAY_DIG_D       = (uint8_t)(3u),    /**< Display digit D */
    DISPLAY_DIG_E       = (uint8_t)(4u),    /**< Display digit E */
    DISPLAY_DIG_F       = (uint8_t)(5u),    /**< Display digit F */
    DISPLAY_DIG_G       = (uint8_t)(6u),    /**< Display digit G */
    DISPLAY_DIG_H       = (uint8_t)(7u),    /**< Display digit H */
    DISPLAY_DIG_I       = (uint8_t)(8u),    /**< Display digit I */
    DISPLAY_DIG_J       = (uint8_t)(9u),    /**< Display digit J */
    DISPLAY_DIG_K       = (uint8_t)(10u),   /**< Display digit K */
    DISPLAY_DIG_L       = (uint8_t)(11u),   /**< Display digit L */
    DISPLAY_DIG_M       = (uint8_t)(12u),   /**< Display digit M */
    DISPLAY_DIG_N       = (uint8_t)(13u),   /**< Display digit N */
    DISPLAY_DIG_O       = (uint8_t)(14u),   /**< Display digit O */
    DISPLAY_DIG_P       = (uint8_t)(15u),   /**< Display digit P */
    DISPLAY_DIG_Q       = (uint8_t)(16u),   /**< Display digit Q */
    DISPLAY_DIG_R       = (uint8_t)(17u),   /**< Display digit R */
    DISPLAY_DIG_S       = (uint8_t)(18u),   /**< Display digit S */
    DISPLAY_DIG_T       = (uint8_t)(19u),   /**< Display digit T */
    DISPLAY_DIG_U       = (uint8_t)(20u),   /**< Display digit U */
    DISPLAY_DIG_V       = (uint8_t)(21u),   /**< Display digit V */
    DISPLAY_DIG_W       = (uint8_t)(22u),   /**< Display digit W */
    DISPLAY_DIG_X       = (uint8_t)(23u),   /**< Display digit X */
    DISPLAY_DIG_Y       = (uint8_t)(24u),   /**< Display digit Y */
    DISPLAY_DIG_Z       = (uint8_t)(25u),   /**< Display digit Z */
    DISPLAY_DIG_NULL    = (uint8_t)(26u)    /**< Null display digit */
} display_digits_t;

/**
 *  @enum    displayHexadecimal
 *  @typedef display_hex_t
 *  @package    display_segments
 * 
 *  @brief   Enumeration for hexadecimal display values.
 */
typedef enum __attribute__((aligned(1))) displayHexadecimal
{
    DISPLAY_HEX_0       = (uint8_t)(0u),    /**< Hexadecimal display 0 */
    DISPLAY_HEX_1       = (uint8_t)(1u),    /**< Hexadecimal display 1 */
    DISPLAY_HEX_2       = (uint8_t)(2u),    /**< Hexadecimal display 2 */
    DISPLAY_HEX_3       = (uint8_t)(3u),    /**< Hexadecimal display 3 */
    DISPLAY_HEX_4       = (uint8_t)(4u),    /**< Hexadecimal display 4 */
    DISPLAY_HEX_5       = (uint8_t)(5u),    /**< Hexadecimal display 5 */
    DISPLAY_HEX_6       = (uint8_t)(6u),    /**< Hexadecimal display 6 */
    DISPLAY_HEX_7       = (uint8_t)(7u),    /**< Hexadecimal display 7 */
    DISPLAY_HEX_8       = (uint8_t)(8u),    /**< Hexadecimal display 8 */
    DISPLAY_HEX_9       = (uint8_t)(9u),    /**< Hexadecimal display 9 */
    DISPLAY_HEX_A       = (uint8_t)(10u),   /**< Hexadecimal display A */
    DISPLAY_HEX_B       = (uint8_t)(11u),   /**< Hexadecimal display B */
    DISPLAY_HEX_C       = (uint8_t)(12u),   /**< Hexadecimal display C */
    DISPLAY_HEX_D       = (uint8_t)(13u),   /**< Hexadecimal display D */
    DISPLAY_HEX_E       = (uint8_t)(14u),   /**< Hexadecimal display E */
    DISPLAY_HEX_F       = (uint8_t)(15u),   /**< Hexadecimal display F */
    DISPLAY_HEX_NULL    = (uint8_t)(16u)    /**< Null hexadecimal display */
} display_hex_t;

/*==========================================
 *         Private Global Variables
 * ========================================== */

/**
 *  @var display_number_char
 *  @package    display_segments
 *
 *  @brief  Mapping of numbers to their corresponding characters.
 *
 *  @details
 *  This constant defines an array of characters that maps each value of the
 *  `display_numbers_t` enumeration to its corresponding character. Used for
 *  displaying numbers as characters.
 */
const char display_number_char[MAX_DISPLAY_NUM] __attribute__((weak, used, aligned(4))) =
{
    [DISPLAY_NUM_0]     = '0',    /**< Character for number 0 */
    [DISPLAY_NUM_1]     = '1',    /**< Character for number 1 */
    [DISPLAY_NUM_2]     = '2',    /**< Character for number 2 */
    [DISPLAY_NUM_3]     = '3',    /**< Character for number 3 */
    [DISPLAY_NUM_4]     = '4',    /**< Character for number 4 */
    [DISPLAY_NUM_5]     = '5',    /**< Character for number 5 */
    [DISPLAY_NUM_6]     = '6',    /**< Character for number 6 */
    [DISPLAY_NUM_7]     = '7',    /**< Character for number 7 */
    [DISPLAY_NUM_8]     = '8',    /**< Character for number 8 */
    [DISPLAY_NUM_9]     = '9',    /**< Character for number 9 */
    [DISPLAY_NUM_NULL]  = '\0'    /**< Null character */
};

/**
 *  @var display_number
 *  @package    display_segments
 *
 *  @brief  Mapping of numbers to 7-segment display binary codes.
 *
 *  @details
 *  This constant defines an array of `uint8_t` that maps each value of the
 *  `display_numbers_t` enumeration to its corresponding binary code used in
 *  7-segment displays. Each bit represents a specific segment of the display.
 */
const uint8_t display_number[MAX_DISPLAY_NUM] __attribute__((weak, used, aligned(4))) =
{
    [DISPLAY_NUM_0]     = 0b00111111, /**< Binary code for number 0 */
    [DISPLAY_NUM_1]     = 0b00000110, /**< Binary code for number 1 */
    [DISPLAY_NUM_2]     = 0b01011011, /**< Binary code for number 2 */
    [DISPLAY_NUM_3]     = 0b01001111, /**< Binary code for number 3 */
    [DISPLAY_NUM_4]     = 0b01100110, /**< Binary code for number 4 */
    [DISPLAY_NUM_5]     = 0b01101101, /**< Binary code for number 5 */
    [DISPLAY_NUM_6]     = 0b01111101, /**< Binary code for number 6 */
    [DISPLAY_NUM_7]     = 0b00000111, /**< Binary code for number 7 */
    [DISPLAY_NUM_8]     = 0b01111111, /**< Binary code for number 8 */
    [DISPLAY_NUM_9]     = 0b01101111, /**< Binary code for number 9 */
    [DISPLAY_NUM_NULL]  = 0b00000000  /**< Null binary code */
};

/**
 *  @var display_digit_char
 *  @package    display_segments
 *
 *  @brief  Mapping of alphabetical digits to their corresponding characters.
 *
 *  @details
 *  This constant defines an array of characters that maps each value of the
 *  `display_digits_t` enumeration to its corresponding alphabetical character.
 *  Used for displaying letters as characters.
 */
const char display_digit_char[MAX_DISPLAY_DIG] __attribute__((weak, used, aligned(4))) =
{
    [DISPLAY_DIG_A]     = 'A',    /**< Character for digit A */
    [DISPLAY_DIG_B]     = 'B',    /**< Character for digit B */
    [DISPLAY_DIG_C]     = 'C',    /**< Character for digit C */
    [DISPLAY_DIG_D]     = 'D',    /**< Character for digit D */
    [DISPLAY_DIG_E]     = 'E',    /**< Character for digit E */
    [DISPLAY_DIG_F]     = 'F',    /**< Character for digit F */
    [DISPLAY_DIG_G]     = 'G',    /**< Character for digit G */
    [DISPLAY_DIG_H]     = 'H',    /**< Character for digit H */
    [DISPLAY_DIG_I]     = 'I',    /**< Character for digit I */
    [DISPLAY_DIG_J]     = 'J',    /**< Character for digit J */
    [DISPLAY_DIG_K]     = 'K',    /**< Character for digit K */
    [DISPLAY_DIG_L]     = 'L',    /**< Character for digit L */
    [DISPLAY_DIG_M]     = 'M',    /**< Character for digit M */
    [DISPLAY_DIG_N]     = 'N',    /**< Character for digit N */
    [DISPLAY_DIG_O]     = 'O',    /**< Character for digit O */
    [DISPLAY_DIG_P]     = 'P',    /**< Character for digit P */
    [DISPLAY_DIG_Q]     = 'Q',    /**< Character for digit Q */
    [DISPLAY_DIG_R]     = 'R',    /**< Character for digit R */
    [DISPLAY_DIG_S]     = 'S',    /**< Character for digit S */
    [DISPLAY_DIG_T]     = 'T',    /**< Character for digit T */
    [DISPLAY_DIG_U]     = 'U',    /**< Character for digit U */
    [DISPLAY_DIG_V]     = 'V',    /**< Character for digit V */
    [DISPLAY_DIG_W]     = 'W',    /**< Character for digit W */
    [DISPLAY_DIG_X]     = 'X',    /**< Character for digit X */
    [DISPLAY_DIG_Y]     = 'Y',    /**< Character for digit Y */
    [DISPLAY_DIG_Z]     = 'Z',    /**< Character for digit Z */
    [DISPLAY_DIG_NULL]  = '\0'    /**< Null character */
};

/**
 *  @var display_digit
 *  @package    display_segments
 *
 *  @brief  Mapping of alphabetical digits to 7-segment display binary codes.
 *
 *  @details
 *  This constant defines an array of `uint8_t` that maps each value of the
 *  `display_digits_t` enumeration to its corresponding binary code used in
 *  7-segment displays. Each bit represents a specific segment of the display.
 */
const uint8_t display_digit[MAX_DISPLAY_DIG] __attribute__((weak, used, aligned(4))) =
{
    [DISPLAY_DIG_A]     = 0b01110111, /**< Binary code for digit A */
    [DISPLAY_DIG_B]     = 0b01111100, /**< Binary code for digit B */
    [DISPLAY_DIG_C]     = 0b00111001, /**< Binary code for digit C */
    [DISPLAY_DIG_D]     = 0b01011110, /**< Binary code for digit D */
    [DISPLAY_DIG_E]     = 0b01111001, /**< Binary code for digit E */
    [DISPLAY_DIG_F]     = 0b01110001, /**< Binary code for digit F */
    [DISPLAY_DIG_G]     = 0b00111101, /**< Binary code for digit G */
    [DISPLAY_DIG_H]     = 0b01110100, /**< Binary code for digit H */
    [DISPLAY_DIG_I]     = 0b00110000, /**< Binary code for digit I */
    [DISPLAY_DIG_J]     = 0b00011110, /**< Binary code for digit J */
    [DISPLAY_DIG_K]     = 0b01110101, /**< Binary code for digit K */
    [DISPLAY_DIG_L]     = 0b00111000, /**< Binary code for digit L */
    [DISPLAY_DIG_M]     = 0b00010101, /**< Binary code for digit M */
    [DISPLAY_DIG_N]     = 0b00110111, /**< Binary code for digit N */
    [DISPLAY_DIG_O]     = 0b00111111, /**< Binary code for digit O */
    [DISPLAY_DIG_P]     = 0b01110011, /**< Binary code for digit P */
    [DISPLAY_DIG_Q]     = 0b01100111, /**< Binary code for digit Q */
    [DISPLAY_DIG_R]     = 0b00110011, /**< Binary code for digit R */
    [DISPLAY_DIG_S]     = 0b01101101, /**< Binary code for digit S */
    [DISPLAY_DIG_T]     = 0b01111000, /**< Binary code for digit T */
    [DISPLAY_DIG_U]     = 0b00111110, /**< Binary code for digit U */
    [DISPLAY_DIG_V]     = 0b00011100, /**< Binary code for digit V */
    [DISPLAY_DIG_W]     = 0b00101010, /**< Binary code for digit W */
    [DISPLAY_DIG_X]     = 0b00110110, /**< Binary code for digit X */
    [DISPLAY_DIG_Y]     = 0b01101110, /**< Binary code for digit Y */
    [DISPLAY_DIG_Z]     = 0b01011011, /**< Binary code for digit Z */
    [DISPLAY_DIG_NULL]  = 0b00000000  /**< Null binary code */
};

/**
 *  @var display_hexadecimal_char
 *  @package    display_segments
 *
 *  @brief  Mapping of hexadecimal values to their corresponding characters.
 *
 *  @details
 *  This constant defines an array of characters that maps each value of the
 *  `display_hex_t` enumeration to its corresponding hexadecimal character. Used
 *  for displaying hexadecimal values as characters.
 */
const char display_hexadecimal_char[MAX_DISPLAY_HEX] __attribute__((weak, used, aligned(4))) =
{
    [DISPLAY_HEX_0]     = '0',    /**< Character for hexadecimal 0 */
    [DISPLAY_HEX_1]     = '1',    /**< Character for hexadecimal 1 */
    [DISPLAY_HEX_2]     = '2',    /**< Character for hexadecimal 2 */
    [DISPLAY_HEX_3]     = '3',    /**< Character for hexadecimal 3 */
    [DISPLAY_HEX_4]     = '4',    /**< Character for hexadecimal 4 */
    [DISPLAY_HEX_5]     = '5',    /**< Character for hexadecimal 5 */
    [DISPLAY_HEX_6]     = '6',    /**< Character for hexadecimal 6 */
    [DISPLAY_HEX_7]     = '7',    /**< Character for hexadecimal 7 */
    [DISPLAY_HEX_8]     = '8',    /**< Character for hexadecimal 8 */
    [DISPLAY_HEX_9]     = '9',    /**< Character for hexadecimal 9 */
    [DISPLAY_HEX_A]     = 'A',    /**< Character for hexadecimal A */
    [DISPLAY_HEX_B]     = 'B',    /**< Character for hexadecimal B */
    [DISPLAY_HEX_C]     = 'C',    /**< Character for hexadecimal C */
    [DISPLAY_HEX_D]     = 'D',    /**< Character for hexadecimal D */
    [DISPLAY_HEX_E]     = 'E',    /**< Character for hexadecimal E */
    [DISPLAY_HEX_F]     = 'F',    /**< Character for hexadecimal F */
    [DISPLAY_HEX_NULL]  = '\0'    /**< Null character */
};

/**
 *  @var display_hexadecimal
 *  @package    display_segments
 *
 *  @brief  Mapping of hexadecimal values to 7-segment display binary codes.
 *
 *  @details
 *  This constant defines an array of `uint8_t` that maps each value of the
 *  `display_hex_t` enumeration to its corresponding binary code used in
 *  7-segment displays. Each bit represents a specific segment of the display.
 */
const uint8_t display_hexadecimal[MAX_DISPLAY_HEX] __attribute__((weak, used, aligned(4))) =
{
    [DISPLAY_HEX_0]     = 0b00111111, /**< Binary code for hexadecimal 0 */
    [DISPLAY_HEX_1]     = 0b00000110, /**< Binary code for hexadecimal 1 */
    [DISPLAY_HEX_2]     = 0b01011011, /**< Binary code for hexadecimal 2 */
    [DISPLAY_HEX_3]     = 0b01001111, /**< Binary code for hexadecimal 3 */
    [DISPLAY_HEX_4]     = 0b01100110, /**< Binary code for hexadecimal 4 */
    [DISPLAY_HEX_5]     = 0b01101101, /**< Binary code for hexadecimal 5 */
    [DISPLAY_HEX_6]     = 0b01111101, /**< Binary code for hexadecimal 6 */
    [DISPLAY_HEX_7]     = 0b00000111, /**< Binary code for hexadecimal 7 */
    [DISPLAY_HEX_8]     = 0b01111111, /**< Binary code for hexadecimal 8 */
    [DISPLAY_HEX_9]     = 0b01101111, /**< Binary code for hexadecimal 9 */
    [DISPLAY_HEX_A]     = 0b01110111, /**< Binary code for hexadecimal A */
    [DISPLAY_HEX_B]     = 0b01111100, /**< Binary code for hexadecimal B */
    [DISPLAY_HEX_C]     = 0b00111001, /**< Binary code for hexadecimal C */
    [DISPLAY_HEX_D]     = 0b01011110, /**< Binary code for hexadecimal D */
    [DISPLAY_HEX_E]     = 0b01111001, /**< Binary code for hexadecimal E */
    [DISPLAY_HEX_F]     = 0b01110001, /**< Binary code for hexadecimal F */
    [DISPLAY_HEX_NULL]  = 0b00000000  /**< Null binary code */
};

#endif /* DISPLAY_SEGMENTS_H_ */
/* end of file */
