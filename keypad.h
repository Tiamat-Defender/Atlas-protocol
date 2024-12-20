#include "pico/stdlib.h"

#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3

#define COLUMN1 4
#define COLUMN2 5
#define COLUMN3 6
#define COLUMN4 6

char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void Keypad_init()
{
    gpio_init(ROW1);
    gpio_init(ROW2);
    gpio_init(ROW3);
    gpio_init(ROW4);

    gpio_init(COLUMN1);
    gpio_init(COLUMN2);
    gpio_init(COLUMN3);
    gpio_init(COLUMN4);
    gpio_init(COLUMN4);

    gpio_set_dir(ROW1, GPIO_OUT);
    gpio_set_dir(ROW2, GPIO_OUT);
    gpio_set_dir(ROW3, GPIO_OUT);
    gpio_set_dir(ROW4, GPIO_OUT);
    
    gpio_set_dir(COLUMN1, GPIO_IN);
    gpio_set_dir(COLUMN2, GPIO_IN);
    gpio_set_dir(COLUMN3, GPIO_IN);
    gpio_set_dir(COLUMN4, GPIO_IN);

}

void Scan_Input()
{
    //check row1
    gpio_put(ROW1, 1);

    if (gpio_get(COLUMN1))
    {

    }else if (gpio_get(COLUMN2))
    {

    }else if (gpio_get(COLUMN3))
    {

    }else if (gpio_get(COLUMN4))
    {

    }
    gpio_put(ROW1, 0);

    //check row 2
    gpio_put(ROW2, 1);

    if (gpio_get(COLUMN1))
    {

    }else if (gpio_get(COLUMN2))
    {

    }else if (gpio_get(COLUMN3))
    {

    }else if (gpio_get(COLUMN4))
    {
        
    }
    gpio_put(ROW2, 0);

    //check row 3
    gpio_put(ROW3, 1);

    if (gpio_get(COLUMN1))
    {

    }else if (gpio_get(COLUMN2))
    {

    }else if (gpio_get(COLUMN3))
    {

    }else if (gpio_get(COLUMN4))
    {
        
    }
    gpio_put(ROW3, 0);

    //check row 4
    gpio_put(ROW4, 1);

    if (gpio_get(COLUMN1))
    {

    }else if (gpio_get(COLUMN2))
    {

    }else if (gpio_get(COLUMN3))
    {

    }else if (gpio_get(COLUMN4))
    {
        
    }
    gpio_put(ROW4, 0);  


}