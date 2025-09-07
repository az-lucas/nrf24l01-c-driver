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
#include "nRF24L01_hw.h"


typedef enum {
	NRF24L01_OK = 0,
	NRF24L01_ERROR_SPI,
	NRF24L01_ERROR_SIZE
}nrf24l01_result_t;

typedef enum {
	NRF24L01_REG_CONFIG    		= 0x00,
	NRF24L01_REG_EN_AA     		= 0x01,
	NRF24L01_REG_EN_RXADDR 		= 0x02,
	NRF24L01_REG_SETUP_AW  		= 0x03,
	NRF24L01_REG_SETUP_RETR		= 0x04,
	NRF24L01_REG_RF_CH 			= 0x05,
	NRF24L01_REG_RF_SETUP 		= 0x06,
	NRF24L01_REG_STATUS 		= 0x07,
	NRF24L01_REG_OBSERVE_TX 	= 0x08,
	NRF24L01_REG_CD 			= 0x09,
	NRF24L01_REG_RX_ADDR_P0 	= 0x0A,
	NRF24L01_REG_RX_ADDR_P1 	= 0x0B,
	NRF24L01_REG_RX_ADDR_P2 	= 0x0C,
	NRF24L01_REG_RX_ADDR_P3 	= 0x0D,
	NRF24L01_REG_RX_ADDR_P4 	= 0x0E,
	NRF24L01_REG_RX_ADDR_P5 	= 0x0F,
	NRF24L01_REG_TX_ADDR		= 0x10,
	NRF24L01_REG_RX_PW_P0 		= 0x11,
	NRF24L01_REG_RX_PW_P1 		= 0x12,
	NRF24L01_REG_RX_PW_P2 		= 0x13,
	NRF24L01_REG_RX_PW_P3 		= 0x14,
	NRF24L01_REG_RX_PW_P4 		= 0x15,
	NRF24L01_REG_RX_PW_P5 		= 0x16,
	NRF24L01_REG_FIFO_STATUS	= 0x17,
	NRF24L01_REG_DYNPD 			= 0x1C,
	NRF24L01_REG_FEATURE 		= 0x1D,
	NRF24L01_CMD_R_RX_PL_WID	= 0x60,
	NRF24L01_CMD_R_RX_PAYLOAD	= 0x61,


}nrf24l01_reg_cmd_t;


typedef struct {
	uint8_t config;
	uint8_t en_aa;
	uint8_t en_rxaddr;
	uint8_t setup_aw;
	uint8_t setup_retr;
	uint8_t rf_ch;   // Canal RF (0–125)
	uint8_t rf_setup;
	uint8_t status;
	uint8_t observe_tx;
	uint8_t cd;
	uint8_t rx_addr_p0[5];
	uint8_t rx_addr_p1[5];
	uint8_t rx_addr_p2;
	uint8_t rx_addr_p3;
	uint8_t rx_addr_p4;
	uint8_t rx_addr_p5;
	uint8_t tx_addr[5];
	uint8_t rx_pw_p0;
	uint8_t rx_pw_p1;
	uint8_t rx_pw_p2;
	uint8_t rx_pw_p3;
	uint8_t rx_pw_p4;
	uint8_t rx_pw_p5;
	uint8_t fifo_status;
	uint8_t dynpd;
	uint8_t feature;
	uint8_t r_rx_pl_wid;
	uint8_t r_rx_payload[32];

}nrf24l01_handle_t;

nrf24l01_result_t nrf24l01_init				(nrf24l01_handle_t *handle);
nrf24l01_result_t nrf24l01_read_reg_cmd		(nrf24l01_handle_t *handle, nrf24l01_reg_cmd_t reg, uint8_t *pData, uint8_t size);
nrf24l01_result_t nrf24l01_write_register	(nrf24l01_handle_t *handle, nrf24l01_reg_cmd_t reg, const uint8_t *pData, uint8_t size);
nrf24l01_result_t nrf24l01_set_rx_mode		(nrf24l01_handle_t *handle);
nrf24l01_result_t nrf24l01_read_rx_buffer	(nrf24l01_handle_t *handle, uint8_t *pData);
nrf24l01_result_t nrf24l01_tx_data			(nrf24l01_handle_t *handle, const uint8_t *pData, uint8_t size);
