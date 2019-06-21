#include "ir_control.h"

void init_start(void)
{
    uint8_t sendbuf[5];
    sendbuf[0]=0xAA;
    sendbuf[1]=0xAA;
    sendbuf[2]=0x08;
    sendbuf[3]=0x08;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}

void init_end(void)
{
    uint8_t sendbuf[5];
    sendbuf[0]=0xCC;
    sendbuf[1]=0xCC;
    sendbuf[2]=0x08;
    sendbuf[3]=0x08;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}

void set_ir_ID(uint16_t num)
{
    uint8_t sendbuf[5];
    sendbuf[0]=0x02;
    sendbuf[1]=num>>8;
    sendbuf[2]=num;
    sendbuf[3]=0x08;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}

void set_CMD_powerswitch(uint8_t cmd)
{
    uint8_t sendbuf[5];
    sendbuf[0]=0x04;
    if(cmd==1)
    {
        sendbuf[1]=0xff;
    }
    else
    {
        sendbuf[1]=0x00;
    }  
    sendbuf[2]=0x08;
    sendbuf[3]=0x08;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}

void set_CMD_mode(uint8_t cmd)
{
    switch(cmd)
    {
        case 2:
        cmd=0;
        break;
        case 9:
        cmd=1;
        break;
        case 10:
        cmd=4;
        break;
        case 11:
        cmd=3;
        break;
        case 13:
        cmd=2;
        break;
        default:break;
    }
    uint8_t sendbuf[5];
    sendbuf[0]=0x05;
    sendbuf[1]=cmd; 
    sendbuf[2]=0x08;
    sendbuf[3]=0x08;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}

void set_CMD_temperature(uint8_t cmd)
{
    uint8_t sendbuf[5];
    if(cmd<0x10)
    {
        cmd=0x10;
    }
    if(cmd>0x1f)
    {
        cmd=0x1f;
    }
    sendbuf[0]=0x06;
    sendbuf[1]=cmd; 
    sendbuf[2]=0x08;
    sendbuf[3]=0x08;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}

void set_CMD_windspeed(uint8_t cmd)
{
    uint8_t sendbuf[5];
    switch(cmd)
    {
        case 151:
        cmd=1;
        break;
        case 153:
        cmd=2;
        break;
        case 155:
        cmd=3;
        break;
        case 255:
        cmd=0;
        break;
        default:break;
    }
    sendbuf[0]=0x07;
    sendbuf[1]=cmd; 
    sendbuf[2]=0x08;
    sendbuf[3]=0x08;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}

void set_CMD_verticalswitch(uint8_t cmd)
{
    uint8_t sendbuf[5];
    sendbuf[0]=0x08;
    sendbuf[1]=cmd; 
    sendbuf[2]=0x08;
    sendbuf[3]=0x08;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}

void set_init_data(uint8_t mode,uint8_t wind,uint8_t temperature)
{
    uint8_t cmd;
    init_start();
    switch(mode)
    {
        case 2:
        cmd=0;
        break;
        case 9:
        cmd=1;
        break;
        case 10:
        cmd=4;
        break;
        case 11:
        cmd=3;
        break;
        case 13:
        cmd=2;
        break;
        default:cmd=0;break;
    }
    set_CMD_mode(cmd);
    if(temperature<0x10)
    {
        temperature=0x10;
    }
    if(temperature>0x1f)
    {
        temperature=0x1f;
    }
    set_CMD_temperature(temperature);
    switch(wind)
    {
        case 151:
        cmd=1;
        break;
        case 153:
        cmd=2;
        break;
        case 155:
        cmd=3;
        break;
        case 255:
        cmd=0;
        break;
        default:cmd=0;break;
    }
    set_CMD_windspeed(cmd);
    init_end();
}

void study_ir_CMD(uint8_t addr)
{
    uint8_t sendbuf[5];
    if(addr>0x3e)
    {
        addr=0x3e;
    }
    sendbuf[0]=0x88;
    sendbuf[1]=addr; 
    sendbuf[2]=0x00;
    sendbuf[3]=0x00;
    sendbuf[4]=sendbuf[0]^sendbuf[1]^sendbuf[2]^sendbuf[3];
    uart1_printf(sendbuf,5);
}
