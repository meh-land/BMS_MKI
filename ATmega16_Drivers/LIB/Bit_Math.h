#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(X, POS) ((X) |= (0x01 << (POS)))
#define CLR_BIT(X, POS) ( (X) &= ~(0x01 << (POS)) )
#define TOG_BIT(X, POS) ( (X) ^= (0x01 << POS) )
#define GET_BIT(X, POS) ( ((X) >> (POS)) & 0x01 )

#define SET_PORT(Y) ( (Y) = 0xFF )
#define CLR_PORT(Y) ( (Y) = 0x00 )
#define TOG_PORT(Y) ( (Y) ^= 0xFF )

#define SET_PORT_TO_VAL(Y, VAL) ( (Y) = (VAL) )


#endif /* BIT_MATH_H_ */
