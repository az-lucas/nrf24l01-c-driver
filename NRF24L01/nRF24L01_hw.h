/**
 * @file    nRF24L01.h
 * @brief   Biblioteca genérica em C para o transceptor nRF24L01.
 *
 * @author  Lucas T. Azeredo
 * @date    2025-09-06
 *
 * @license MIT
 *
 * @note    
 *          
 *          
 */
#include <stdint.h>

typedef enum {
	NRF24L01_SPI_OK = 0,
	NRF24L01_SPI_ERROR
}nrf24l01_hw_result_t;

void nrf24l01_delay(uint32_t ms);
void nrf24l01_ce_high(void); //CE -> Operating Mode,RX/TX
void nrf24l01_ce_low(void);
void nrf24l01_csn_high(void); //CSN -> SPI chip select
void nrf24l01_csn_low(void);
nrf24l01_hw_result_t nrf24l01_spi_init(void);
nrf24l01_hw_result_t nrf24l01_spi_transfer(const uint8_t *pTxData, uint8_t *pRxData, uint16_t size);

