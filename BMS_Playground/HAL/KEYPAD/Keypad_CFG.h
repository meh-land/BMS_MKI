#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define KPD_NO_OF_ROWS 4
#define KPD_NO_OF_COLS 4

#define KPD_PORT DIO_PORTC

#define KPD_ROW_PIN1 DIO_PIN0
#define KPD_ROW_PIN2 DIO_PIN1
#define KPD_ROW_PIN3 DIO_PIN2
#define KPD_ROW_PIN4 DIO_PIN3

#define KPD_COL_PIN1 DIO_PIN4
#define KPD_COL_PIN2 DIO_PIN5
#define KPD_COL_PIN3 DIO_PIN6
#define KPD_COL_PIN4 DIO_PIN7

#define KPD_BUTTON_PRESSED 0
#define KPD_BUTTON_RELEASED 1


/** NOTE THAT this button configuration is according to 
	Proteus's 4x4 keypad button configuration
 */

#define KPD_BUTTON_CFG 	{ 							\
							{'7', '8', '9', '/'},   \
							{'4', '5', '6', '*'},   \
							{'1', '2', '3', '-'},   \
							{'C', '0', '=', '+'}    \
						}                       	\

#endif