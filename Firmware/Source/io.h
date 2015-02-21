#ifndef IO_H
#define IO_H

#include <xc.h>


void io_init();


#define io_led_on()  { LATB0 = 0; }
#define io_led_off()  { LATB0 = 1; }

void io_gripper_off();
void io_gripper_close();
void io_gripper_open();

void io_wrist_off();
void io_wrist_down();
void io_wrist_up();

void io_elbow_off();
void io_elbow_down();
void io_elbow_up();

void io_base_move_off();
void io_base_move_down();
void io_base_move_up();

void io_base_rotate_off();
void io_base_rotate_left();
void io_base_rotate_right();


#endif
