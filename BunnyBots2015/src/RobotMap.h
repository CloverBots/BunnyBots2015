#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

struct RobotMap
{
	const static u_int32_t
		FRONT_LEFT_MOTOR_PORT = 4,
		FRONT_RIGHT_MOTOR_PORT = 5,
		REAR_LEFT_MOTOR_PORT = 6,
		REAR_RIGHT_MOTOR_PORT = 7,
		FRONT_LEFT_ENCODER_PORT_A = -1, // Define if implemented.
		FRONT_LEFT_ENCODER_PORT_B = -1, // Define if implemented.
		REAR_LEFT_ENCODER_PORT_A = -1, // Define if implemented.
		REAR_LEFT_ENCODER_PORT_B = -1, // Define if implemented.
		FRONT_RIGHT_ENCODER_PORT_A = -1, // Define if implemented.
		FRONT_RIGHT_ENCODER_PORT_B = -1, // Define if implemented.
		REAR_RIGHT_ENCODER_PORT_A = -1, // Define if implemented.
		REAR_RIGHT_ENCODER_PORT_B = -1, // Define if implemented.
		PADDLE_LEFT_MOTOR_PORT = 1,
		PADDLE_RIGHT_MOTOR_PORT = 0,
		PADDLE_ENCODER_CHANNEL_A = 1,
		PADDLE_ENCODER_CHANNEL_B = 2,
		CLAW_LIFTER_PORT = 2,
		CLAW_GRABBER_PORT = 3;
};

#endif
