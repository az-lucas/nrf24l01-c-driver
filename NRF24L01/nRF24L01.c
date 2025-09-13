/**
 * @file    nRF24L01.c
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

#include "nRF24L01.h"

nrf24l01_handle_t nrf24;



nrf24l01_result_t nrf24l01_init(nrf24l01_handle_t *handle){
	nrf24l01_csn_high();
	nrf24l01_ce_low();
	if(nrf24l01_spi_init() != NRF24L01_SPI_OK) return NRF24L01_ERROR_SPI;
	nrf24l01_delay(15);

	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_CONFIG,		&handle->config,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_EN_AA, 		&handle->en_aa,			1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_EN_RXADDR, 	&handle->en_rxaddr,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_SETUP_AW, 	&handle->setup_aw,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_SETUP_RETR, 	&handle->setup_retr,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RF_CH, 		&handle->rf_ch,			1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RF_SETUP, 	&handle->rf_setup,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_STATUS, 		&handle->status,		0) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_OBSERVE_TX, 	&handle->observe_tx,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_CD, 			&handle->cd,			1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_ADDR_P0, 	&handle->rx_addr_p0[0],	5) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_ADDR_P1, 	&handle->rx_addr_p1[0],	5) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_ADDR_P2, 	&handle->rx_addr_p2,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_ADDR_P3, 	&handle->rx_addr_p3,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_ADDR_P4, 	&handle->rx_addr_p4,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_ADDR_P5, 	&handle->rx_addr_p5,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_TX_ADDR, 		&handle->tx_addr[0],	5) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_PW_P0, 	&handle->rx_pw_p0,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_PW_P1, 	&handle->rx_pw_p1,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_PW_P2, 	&handle->rx_pw_p2,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_PW_P3, 	&handle->rx_pw_p3,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_PW_P4, 	&handle->rx_pw_p4,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RX_PW_P5, 	&handle->rx_pw_p5,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_FIFO_STATUS, 	&handle->fifo_status,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_DYNPD, 		&handle->dynpd,			1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_FEATURE, 		&handle->feature,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_CMD_R_RX_PL_WID, 	&handle->r_rx_pl_wid,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	if(handle->status & NRF24L01_RX_DR){
		if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_CMD_FLUSH_RX, 	&handle->status , 	0) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
		handle->status |= NRF24L01_RX_DR;
		if(nrf24l01_write_register(handle, 	NRF24L01_REG_STATUS, 	&handle->status, 	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
		if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_STATUS, 	&handle->status,	0) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	}

	if(handle->status & NRF24L01_TX_DS){
		if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_CMD_FLUSH_TX, 	&handle->status , 	0) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
		handle->status |= NRF24L01_TX_DS;
		if(nrf24l01_write_register(handle, 	NRF24L01_REG_STATUS, 	&handle->status, 	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
		if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_STATUS, 	&handle->status,	0) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	}

	return NRF24L01_OK;
}

nrf24l01_result_t nrf24l01_read_reg_cmd(nrf24l01_handle_t *handle, nrf24l01_reg_cmd_t reg, uint8_t *pData, uint8_t size){
	nrf24l01_hw_result_t _result;
	uint8_t _tx[35];
	uint8_t _rx[35];
	uint8_t _cont;

	if(size > 34)return NRF24L01_ERROR_SIZE;

	_tx[0] = reg;
	nrf24l01_csn_low();
	_result = nrf24l01_spi_transfer(_tx, _rx, size);
	nrf24l01_csn_high();

	if(_result != NRF24L01_SPI_OK) return NRF24L01_ERROR_SPI;

	for(_cont = 1; _cont<size+1;_cont++){
		*pData++ = _rx[_cont];
	}

	handle->status = _rx[0];

	return NRF24L01_OK;
}

nrf24l01_result_t nrf24l01_write_register(nrf24l01_handle_t *handle, nrf24l01_reg_cmd_t reg, const uint8_t *pData, uint8_t size){
	nrf24l01_hw_result_t _result;
	uint8_t _tx[35];
	uint8_t _rx[35];
	uint8_t _cont;

	if(size > 34)return NRF24L01_ERROR_SIZE;

	_tx[0] = reg | NRF24L01_CMD_W_REGISTER;

	for(_cont = 1; _cont<size+1;_cont++){
		_tx[_cont] = *pData++;
	}

	nrf24l01_csn_low();
	_result = nrf24l01_spi_transfer(_tx, _rx, size);
	nrf24l01_csn_high();

	if(_result != NRF24L01_SPI_OK) return NRF24L01_ERROR_SPI;

	handle->status = _rx[0];

	return NRF24L01_OK;
}

nrf24l01_result_t nrf24l01_set_rx_mode(nrf24l01_handle_t *handle){
	if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_CONFIG, &handle->config, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	handle->config |= NRF24L01_PRIM_RX;
	handle->config |= NRF24L01_PWR_UP;
	if(nrf24l01_write_register(handle, 	NRF24L01_REG_CONFIG, &handle->config, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	nrf24l01_ce_high();
	return NRF24L01_OK;
}

nrf24l01_result_t nrf24l01_read_rx(nrf24l01_handle_t *handle){


	if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_CMD_NOP,	&handle->status,	0) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	if(handle->status & NRF24L01_RX_DR){

		if(handle->r_rx_payload.length >= sizeof(handle->r_rx_payload.buffer)/33-1)return NRF24L01_ERROR_BUFFER_RX_FULL;

		if(nrf24l01_read_reg_cmd(handle, NRF24L01_CMD_R_RX_PL_WID, 	&handle->r_rx_pl_wid,	1) 						!= NRF24L01_OK) return NRF24L01_ERROR_SPI;
		handle->r_rx_payload.buffer[handle->r_rx_payload.in_index].size = handle->r_rx_pl_wid;
		if(nrf24l01_read_reg_cmd(handle, NRF24L01_CMD_R_RX_PAYLOAD, handle->r_rx_payload.buffer[handle->r_rx_payload.in_index++].payload,	handle->r_rx_pl_wid)!= NRF24L01_OK) return NRF24L01_ERROR_SPI;
		if(handle->r_rx_payload.in_index > sizeof(handle->r_rx_payload.buffer)/33-1)handle->r_rx_payload.in_index = 0;
		handle->r_rx_payload.length++;
		handle->status |= NRF24L01_RX_DR;
		if(nrf24l01_write_register(handle, 	NRF24L01_REG_STATUS, 	&handle->status, 	1) 							!= NRF24L01_OK) return NRF24L01_ERROR_SPI;
		if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_STATUS, 	&handle->status,					0) 			!= NRF24L01_OK) return NRF24L01_ERROR_SPI;
	}


	return NRF24L01_OK;
}

nrf24l01_buffer_t nrf24l01_read_buffer(nrf24l01_handle_t *handle){
	nrf24l01_buffer_t rx;
	rx.size = 0;
	if(handle->r_rx_payload.length > 0){
		rx = handle->r_rx_payload.buffer[handle->r_rx_payload.out_index++];
		if(handle->r_rx_payload.out_index > sizeof(handle->r_rx_payload.buffer)/33-1)handle->r_rx_payload.out_index = 0;
		handle->r_rx_payload.length--;
		return rx;
	}else{
		return rx;
	}

}

nrf24l01_result_t nrf24l01_tx_data(nrf24l01_handle_t *handle, const uint8_t *pData, uint8_t size){
	nrf24l01_hw_result_t _result;
	uint8_t _tx[35];
	uint8_t _rx[35];
	uint8_t _cont;

	if(size > 34)return NRF24L01_ERROR_SIZE;

	if(nrf24l01_read_reg_cmd(handle, NRF24L01_CMD_FLUSH_TX, &handle->status , 0) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	if(handle->status & NRF24L01_MAX_RT){
		handle->status |= NRF24L01_MAX_RT;
		if(nrf24l01_write_register(handle, 	NRF24L01_REG_STATUS, 	&handle->status, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
		if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_STATUS, 	&handle->status, 0) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	}

	_tx[0] = NRF24L01_CMD_W_TX_PAYLOAD;

	for(_cont = 1; _cont<size+1;_cont++){
		_tx[_cont] = *pData++;
	}

	nrf24l01_csn_low();
	_result = nrf24l01_spi_transfer(_tx, _rx, size);
	nrf24l01_csn_high();
	if(_result != NRF24L01_SPI_OK) return NRF24L01_ERROR_SPI;

	if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_CONFIG,	&handle->config,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	handle->config &= ~NRF24L01_PRIM_RX;
	handle->config |= NRF24L01_PWR_UP;


	nrf24l01_ce_high();
	nrf24l01_delay(1);
	nrf24l01_ce_low();

	if(nrf24l01_write_register(handle, 	NRF24L01_REG_CONFIG,	&handle->config,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_CONFIG,	&handle->config,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;



	return NRF24L01_OK;
}

nrf24l01_result_t nrf24l01_set_rf_power(nrf24l01_handle_t *handle, nrf24l01_rf_power_t pwr){

	if(pwr>NRF24L01_HIGH) return NRF24L01_ERROR_INVALID_ARG;

	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RF_SETUP, 	&handle->rf_setup,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	handle->rf_setup &= 0xF9;
	handle->rf_setup |= (pwr<<1);

	if(nrf24l01_write_register(handle, 	NRF24L01_REG_RF_SETUP, 	&handle->rf_setup, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_RF_SETUP, 	&handle->rf_setup, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	return NRF24L01_OK;
}

nrf24l01_result_t nrf24l01_set_rf_dr(nrf24l01_handle_t *handle, nrf24l01_rf_dr_t dr){

	if(dr>NRF24L01_250kbps) return NRF24L01_ERROR_INVALID_ARG;

	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_RF_SETUP, 	&handle->rf_setup,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	handle->rf_setup &= 0xD7;
	if(dr == NRF24L01_250kbps){
		handle->rf_setup |= (1<<5);
	}else if(dr == NRF24L01_2Mbps){
		handle->rf_setup |= (1<<3);
	}


	if(nrf24l01_write_register(handle, 	NRF24L01_REG_RF_SETUP, 	&handle->rf_setup, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_RF_SETUP, 	&handle->rf_setup, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	return NRF24L01_OK;
}

nrf24l01_result_t nrf24l01_set_retx_delay	(nrf24l01_handle_t *handle, nrf24l01_retransmit_delay rd){
	if(rd > NRF24L01_4000uS) return NRF24L01_ERROR_INVALID_ARG;

	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_SETUP_RETR, 	&handle->setup_retr,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	handle->setup_retr &= 0x0F;
	handle->setup_retr |= (rd<<4);

	if(nrf24l01_write_register(handle, 	NRF24L01_REG_SETUP_RETR, 	&handle->setup_retr, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_SETUP_RETR, 	&handle->setup_retr,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	return NRF24L01_OK;
}

nrf24l01_result_t nrf24l01_set_retx_cout(nrf24l01_handle_t *handle, nrf24l01_retransmit_delay arc){
	if(arc > 15) return NRF24L01_ERROR_INVALID_ARG;

	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_SETUP_RETR, 	&handle->setup_retr,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	handle->setup_retr &= 0xF0;
	handle->setup_retr |= arc;

	if(nrf24l01_write_register(handle, 	NRF24L01_REG_SETUP_RETR, 	&handle->setup_retr, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_SETUP_RETR, 	&handle->setup_retr,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	return NRF24L01_OK;

}

nrf24l01_result_t nrf24l01_enable_dynamic_payload(nrf24l01_handle_t *handle, uint8_t pipe){

	if(pipe > 63)return NRF24L01_ERROR_INVALID_ARG;

	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_DYNPD, 		&handle->dynpd,			1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle, NRF24L01_REG_FEATURE, 		&handle->feature,		1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	handle->dynpd = pipe;

	if(nrf24l01_write_register(handle, 	NRF24L01_REG_DYNPD, &handle->dynpd, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	if(nrf24l01_read_reg_cmd(handle,	NRF24L01_REG_DYNPD, &handle->dynpd,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;

	if(pipe > 0){
		handle->feature |= 1<<2;

		if(nrf24l01_write_register(handle, 	NRF24L01_REG_FEATURE, &handle->feature, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
		if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_FEATURE, &handle->feature,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	}else{// disable all dynamic payload
		handle->feature &= 0xFB;

		if(nrf24l01_write_register(handle, 	NRF24L01_REG_FEATURE, &handle->feature, 1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
		if(nrf24l01_read_reg_cmd(handle, 	NRF24L01_REG_FEATURE, &handle->feature,	1) != NRF24L01_OK) return NRF24L01_ERROR_SPI;
	}


	return NRF24L01_OK;
}
