/*ir_control.h*/  
#ifndef _IR_CONTROL_H  
#define _IR_CONTROL_H  
  
#include <stdlib.h>  
#include <string.h>  
#include <stdint.h>

void set_ir_ID(uint16_t num);
void set_CMD_powerswitch(uint8_t cmd);
void set_CMD_mode(uint8_t cmd);
void set_CMD_temperature(uint8_t cmd);
void set_CMD_windspeed(uint8_t cmd);
void set_CMD_verticalswitch(uint8_t cmd);
void set_init_data(uint8_t mode,uint8_t wind,uint8_t temperature);
void study_ir_CMD(uint8_t addr);

#endif 