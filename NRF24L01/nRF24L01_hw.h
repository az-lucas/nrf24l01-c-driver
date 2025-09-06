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

#include "nRF24L01.h"


void nrf24l01_ce_high(void);
void nrf24l01_ce_low(void);
void nrf24l01_csn_high(void);
void nrf24l01_csn_low(void);
nrf24l01_result_t nrf24l01_spi_transfer(const uint8_t *pTxData, uint8_t *pRxData, uint16_t Size);

