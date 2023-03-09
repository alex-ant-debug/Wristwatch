#ifndef SRC_WIDGETS_CONSTANTS_H_
#define SRC_WIDGETS_CONSTANTS_H_

#include <stdbool.h>

#define PI 	3.14159265
#define xC	120
#define yC	120

typedef struct encoderData_t
{
	bool isEnter;
	uint8_t encoderPosition;
}encoderData_t;

#endif /* SRC_WIDGETS_CONSTANTS_H_ */
