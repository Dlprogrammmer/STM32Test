#ifndef _SERIAL_H
#define _SERIAL_H
void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array,uint16_t Length);
#endif