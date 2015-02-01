#include "io.h"


void io_init() {
    io_led_off();
    io_gripper_off();
    io_wrist_off();
    io_elbow_off();
    io_base_move_off();
    io_base_rotate_off();

    ANSELA &= 0b00100000;
    ANSELB &= 0b11000110;
    TRISA  &= 0b00100000; //A7 A6    A4 A3 A2 A1 A0
    TRISB  &= 0b11000110; //      B5 B4 B3       B0

    //fixup for RB5
    SS1SEL = 1;
    TXCKSEL = 0;
    CCP1M0 = 0;
    CCP1M1 = 0;
    CCP1M2 = 0;
    CCP1M3 = 0;
}



void io_gripper_off() {
    LATA0 = 0; //IN1
    LATA1 = 0; //IN2
}

void io_gripper_close() {
    LATA0 = 1; //IN1
    LATA1 = 0; //IN2
}

void io_gripper_open() {
    LATA0 = 0; //IN1
    LATA1 = 1; //IN2
}

void io_gripper_toggle() {
    LATA0 = !LATA0; //IN1
    LATA1 = !LATA1; //IN2
}


void io_wrist_off() {
    LATA6 = 0; //IN1
    LATA7 = 0; //IN2
}

void io_wrist_down() {
    LATA6 = 0; //IN1
    LATA7 = 1; //IN2
}

void io_wrist_up() {
    LATA6 = 1; //IN1
    LATA7 = 0; //IN2
}

void io_wrist_toggle() {
    LATA6 = !LATA6; //IN1
    LATA7 = !LATA7; //IN2
}


void io_elbow_off() {
    LATA2 = 0; //IN1
    LATB4 = 0; //IN2
}

void io_elbow_down() {
    LATA2 = 0; //IN1
    LATB4 = 1; //IN2
}

void io_elbow_up() {
    LATA2 = 1; //IN1
    LATB4 = 0; //IN2
}

void io_elbow_toggle() {
    LATA2 = !LATA2; //IN1
    LATB4 = !LATB4; //IN2
}


void io_base_move_off() {
    LATA3 = 0; //IN1
    LATB5 = 0; //IN2
}

void io_base_move_down() {
    LATA3 = 0; //IN1
    LATB5 = 1; //IN2
}

void io_base_move_up() {
    LATA3 = 1; //IN1
    LATB5 = 0; //IN2
}

void io_base_move_toggle() {
    LATA3 = !LATA3; //IN1
    LATB5 = !LATB5; //IN2
}


void io_base_rotate_off() {
    LATA4 = 0; //IN1
    LATB3 = 0; //IN2
}

void io_base_rotate_left() {
    LATA4 = 1; //IN1
    LATB3 = 0; //IN2
}

void io_base_rotate_right() {
    LATA4 = 0; //IN1
    LATB3 = 1; //IN2
}

void io_base_rotate_toggle() {
    LATA4 = !LATA4; //IN1
    LATB3 = !LATB3; //IN2
}
