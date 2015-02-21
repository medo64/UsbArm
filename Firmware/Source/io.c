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
    LATB3 = 0; //IN1
    LATA4 = 0; //IN2
}

void io_gripper_close() {
    LATB3 = 1; //IN1
    LATA4 = 0; //IN2
}

void io_gripper_open() {
    LATB3 = 0; //IN1
    LATA4 = 1; //IN2
}


void io_wrist_off() {
    LATA2 = 0; //IN1
    LATA3 = 0; //IN2
}

void io_wrist_down() {
    LATA2 = 0; //IN1
    LATA3 = 1; //IN2
}

void io_wrist_up() {
    LATA2 = 1; //IN1
    LATA3 = 0; //IN2
}


void io_elbow_off() {
    LATB5 = 0; //IN1
    LATB4 = 0; //IN2
}

void io_elbow_down() {
    LATB5 = 0; //IN1
    LATB4 = 1; //IN2
}

void io_elbow_up() {
    LATB5 = 1; //IN1
    LATB4 = 0; //IN2
}


void io_base_move_off() {
    LATA1 = 0; //IN1
    LATA0 = 0; //IN2
}

void io_base_move_down() {
    LATA1 = 1; //IN1
    LATA0 = 0; //IN2
}

void io_base_move_up() {
    LATA1 = 0; //IN1
    LATA0 = 1; //IN2
}


void io_base_rotate_off() {
    LATA7 = 0; //IN1
    LATA6 = 0; //IN2
}

void io_base_rotate_left() {
    LATA7 = 1; //IN1
    LATA6 = 0; //IN2
}

void io_base_rotate_right() {
    LATA7 = 0; //IN1
    LATA6 = 1; //IN2
}
