#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap
{
public:
	const static int FRONT_LEFT_MOTOR_PORT = 0;
	const static int FRONT_RIGHT_MOTOR_PORT = 1;
	const static int REAR_LEFT_MOTOR_PORT = 2;
	const static int REAR_RIGHT_MOTOR_PORT = 3;
	const static int32_t FRONT_LEFT_MOTOR_ENCODER_PORT_A = 3;
	const static int32_t FRONT_LEFT_MOTOR_ENCODER_PORT_B = 4;
	const static int32_t REAR_LEFT_MOTOR_ENCODER_PORT_A = 5;
	const static int32_t REAR_LEFT_MOTOR_ENCODER_PORT_B = 6;
	const static int32_t FRONT_RIGHT_MOTOR_ENCODER_PORT_A = 7;
	const static int32_t FRONT_RIGHT_MOTOR_ENCODER_PORT_B = 8;
	const static int32_t REAR_RIGHT_MOTOR_ENCODER_PORT_A = 9;
	const static int32_t REAR_RIGHT_MOTOR_ENCODER_PORT_B = 10;
	const static int PADDLE_MOTOR_PORT = 4;
	const static u_int32_t PADDLE_CHANNEL_A = 1;
	const static u_int32_t PADDLE_CHANNEL_B = 2;
};

#endif
