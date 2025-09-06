/**
 * @file    nRF24L01.h
 * @brief   Biblioteca genérica em C para o transceptor nRF24L01.
 *
 * @author  Lucas T. Azeredo
 * @date    2025-09-05
 *
 * @license MIT
 *
 * @note    
 *          
 *          
 */

typedef enum {
	NRF24L01_OK = 0,
	NRF24L01_SPI_ERROR
}nrf24l01_result_t;

typedef struct {
	uint8_t rf_channel;   // Canal RF (0–125)

}nrf24l01_handle_t;

nrf24l01_result_t nrf24l01_init(nrf24l01_handle_t *handle);
nrf24l01_result_t nrf24l01_read_register(uint8_t reg, uint8_t *pData, uint8_t size);
nrf24l01_result_t nrf24l01_write_register(uint8_t reg, const uint8_t *pData, uint8_t size);
nrf24l01_result_t nrf24l01_set_rx_mode(nrf24l01_handle_t *handle);
nrf24l01_result_t nrf24l01_read_rx_buffer(nrf24l01_handle_t *handle, uint8_t *pData);
nrf24l01_result_t nrf24l01_tx_data(nrf24l01_handle_t *handle, const uint8_t *pData, uint8_t size);
