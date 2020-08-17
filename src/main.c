#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <savor/spi.h>
#include <savor/serial.h>

int main(){
	char spi_count = 0;

	DDRC |= (1 << 5);

    uint16_t ubrr = serial_ubrr(F_CPU, 38400);

	SPI_MasterInit();
    serial_init(ubrr);

	while(1){
		SPI_Tranceive(spi_count);
        printf("Ubrr: %d, Count: %d\n", ubrr, spi_count);
		spi_count++;
		_delay_ms(1000);
	}
}
