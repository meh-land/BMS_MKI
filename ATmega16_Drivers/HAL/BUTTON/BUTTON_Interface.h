#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

void BTN_voidButtonInit(u8 copy_u8PortName, u8 copy_u8PinNum);
u8 BTN_u8IsButtonPressed(u8 copy_u8PortName, u8 copy_u8PinNum);

#endif