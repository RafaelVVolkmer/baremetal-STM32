#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SUCCESS 0u

typedef enum gpioPorts
{
    GPIO_A      = 0u,
    GPIO_B      = 1u,
    GPIO_C      = 2u,
    GPIO_D      = 3u,
    MAX_PORTS   = 4u
} ports_t;

typedef enum gpioFuncs
{
    GPIO_OUT    = 0u,
    GPIO_IN     = 1u,
    GPIO_ALT    = 2u,
    MAX_FUNC    = 3u
} funcs_t;

typedef enum gpioCmd
{
    GPIO_OFF    = 0u,
    GPIO_ON     = 1u
} cmd_t;

typedef struct 
{
    size_t num_of_pins;
    int ***pins;
} pins_t;

static pins_t *PINS_createInstance (size_t num_of_pins);
static int PINS_destroyInstance(pins_t *instance) ;

int main() 
{
    pins_t *my_pins = NULL;
    int destroy_ret = 0u;
    
    my_pins = PINS_createInstance(6);
    
    if (my_pins != NULL) 
    {
        my_pins->pins[GPIO_A][0][GPIO_OUT] = GPIO_ON;
        my_pins->pins[GPIO_B][2][GPIO_ALT] = GPIO_ON;
        my_pins->pins[GPIO_C][5][GPIO_IN]  = GPIO_ON;
        
        do
        {
            destroy_ret = PINS_destroyInstance(my_pins);
        } while (destroy_ret != SUCCESS);
            
    } 

    return 0;
}

static pins_t *PINS_createInstance (size_t num_of_pins)
 {
    pins_t *pins_matrix = NULL;
    
    size_t pin  = 0u;
    size_t func = 0u;
    
    pins_matrix = (pins_t*)malloc(sizeof(pins_t));
    if (pins_matrix == NULL)
    {
        goto function_output;
    }
    
    pins_matrix->num_of_pins = num_of_pins;
    
    pins_matrix->pins = (int***)malloc(MAX_PORTS * sizeof(int**));
    if (pins_matrix->pins == NULL)
    {
        free(pins_matrix);
        pins_matrix = NULL;
        
        goto function_output;
    }

    for (pin = 0u; pin < MAX_PORTS; pin++) 
    {
        pins_matrix->pins[pin] = (int**)malloc(pins_matrix->num_of_pins * sizeof(int*));
        if (pins_matrix->pins[pin] == NULL) 
        {
            PINS_destroyInstance(pins_matrix);
            pins_matrix = NULL;
            
            goto function_output;
        }

        for (func = 0; func < pins_matrix->num_of_pins; func++) 
        {
            pins_matrix->pins[pin][func] = (int*)malloc(MAX_FUNC * sizeof(int));
            if (pins_matrix->pins[pin][func] == NULL) 
            {
                PINS_destroyInstance(pins_matrix);
                pins_matrix = NULL;
                
                goto function_output; 
            }
        }
    }

function_output:
    return pins_matrix;
}


static int PINS_destroyInstance(pins_t *instance) 
{
    int ret = SUCCESS;
    
    if (instance == NULL) 
    {
        ret = -EINVAL;
        goto function_output;
    }

    if (instance->pins != NULL) 
    {
        for (size_t port = 0; port < MAX_PORTS; port++) 
        {
            if (instance->pins[port] != NULL) 
            {
                for (size_t pin = 0; pin < instance->num_of_pins; pin++) 
                {
                    if (instance->pins[port][pin] != NULL) 
                    {
                        free(instance->pins[port][pin]);
                        instance->pins[port][pin] = NULL;
                    }
                }
                
                free(instance->pins[port]);
                instance->pins[port] = NULL;
            }
        }
        
        free(instance->pins);
        instance->pins = NULL;
    }

    free(instance);
    instance = NULL;
    
function_output:
    return SUCCESS;
}
