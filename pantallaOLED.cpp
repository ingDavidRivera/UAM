#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"

#define OLED_ADDR   0x3C
#define SDA_PIN     16
#define SCL_PIN     17

#define ADC_PIN     26

int main() {
    // Inicializar la librería de stdio
    stdio_init_all();

    // Inicializar la librería de I2C
    i2c_init(i2c0, 100 * 1000);

    // Configurar los pines SDA y SCL
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    // Inicializar la pantalla OLED
    ssd1306_init(i2c0, OLED_ADDR);

    // Limpiar la pantalla
    ssd1306_clear();

    // Mostrar un mensaje de bienvenida
    ssd1306_set_text_cursor(0, 0);
    ssd1306_puts("Bienvenido!");

    // Configurar el pin ADC
    adc_init();
    adc_gpio_init(ADC_PIN);
    adc_select_input(ADC_PIN);

    while (true) {
        // Leer el valor del potenciómetro
        uint16_t adc_value = adc_read();

        // Convertir el valor leído a un número de 0 a 100
        uint8_t percent_value = (adc_value * 100) / 65535;

        // Mostrar el valor en la pantalla OLED
        ssd1306_set_text_cursor(0, 2);
        ssd1306_printf("Valor: %d %%", percent_value);

        // Esperar 500ms antes de leer el valor del potenciómetro de nuevo
        sleep_ms(500);
    }
}
