#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <savor/spi.h>

int main(){
	char spi_count = 0;

	DDRC |= (1 << 5);

	SPI_MasterInit();

	while(1){
		SPI_Tranceive(spi_count);
		PORTC ^= (1 << 5);
		spi_count++;
		_delay_ms(1000);
	}
}
