#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/**
	unsigned integers
*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long int u64;

/**
	signed integers
*/
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long int s64;

/**
	floats
*/
typedef float f32;
typedef double f64;
typedef long double f128;

typedef enum bool 
{
	true  = 1,
	false = 0
} bool;

/* typedef enum errors
{
	
} errors; */

#define NULL ((void *)0)

typedef void (*ptrFunc)(void);

/*
	MCU Frequency (in MHz)
*/
#ifndef F_CPU

	#define F_CPU		8000000UL
	
#endif


/*
	CPU Periodic Time (in us)
*/

#define CLK_CPU		12.5			// 1/F_CPU

#endif