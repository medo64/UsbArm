#include "config.h"
#include "io.h"
#include "uart.h"


void main() {
    init();

    uart_init(9600);
    uart_writeByte('.');

    io_init();

    io_led_on(); wait_100ms(); io_led_off(); wait_100ms();
    io_led_on(); wait_100ms(); io_led_off(); wait_100ms();
    io_led_on(); wait_100ms(); io_led_off();


    bool stateLed = false;
    int16_t stateM1 = 0;
    int16_t stateM2 = 0;
    int16_t stateM3 = 0;
    int16_t stateM4 = 0;
    int16_t stateM5 = 0;

    while (true) {
        clearWatchdog();

        if (uart_canRead()) {
            uint8_t cmd = uart_readByte();
            switch (cmd) {
                case '1': if (stateM1 > 0) { stateM1 = 0; } else if (stateM1 > -30000) { stateM1 -= 100; } break;
                case '2': if (stateM1 < 0) { stateM1 = 0; } else if (stateM1 <  30000) { stateM1 += 100; } break;
                case '3': if (stateM2 > 0) { stateM2 = 0; } else if (stateM2 > -30000) { stateM2 -= 100; } break;
                case '4': if (stateM2 < 0) { stateM2 = 0; } else if (stateM2 <  30000) { stateM2 += 100; } break;
                case '5': if (stateM3 > 0) { stateM3 = 0; } else if (stateM3 > -30000) { stateM3 -= 100; } break;
                case '6': if (stateM3 < 0) { stateM3 = 0; } else if (stateM3 <  30000) { stateM3 += 100; } break;
                case '7': if (stateM4 > 0) { stateM4 = 0; } else if (stateM4 > -30000) { stateM4 -= 100; } break;
                case '8': if (stateM4 < 0) { stateM4 = 0; } else if (stateM4 <  30000) { stateM4 += 100; } break;
                case '9': if (stateM5 > 0) { stateM5 = 0; } else if (stateM5 > -30000) { stateM5 -= 100; } break;
                case '0': if (stateM5 < 0) { stateM5 = 0; } else if (stateM5 <  30000) { stateM5 += 100; } break;
                case ' ': stateLed = !stateLed; break;

                case 0x0A:
                case 0x0D:
                    uart_writeConstBytes("*** UsbArm ***\r\n");
                    uart_writeConstBytes("\r\n");
                    uart_writeConstBytes("GRIPPER   close 1 2 open\r\n");
                    uart_writeConstBytes("WRIST      down 3 4 up\r\n");
                    uart_writeConstBytes("ELBOW      down 5 6 up\r\n");
                    uart_writeConstBytes("BASE       down 7 8 up\r\n");
                    uart_writeConstBytes("BASE       left 9 0 right\r\n");
                    uart_writeConstBytes("\r\n");
                    break;

                //default: uart_writeByte(cmd); break;
            }
        }

        if (stateLed) { io_led_on(); } else { io_led_off(); }
        if (stateM1 < 0) { io_gripper_close();    } else if (stateM1 > 0) { io_gripper_open();      } else { io_gripper_off();     }
        if (stateM2 < 0) { io_wrist_down();       } else if (stateM2 > 0) { io_wrist_up();          } else { io_wrist_off();       }
        if (stateM3 < 0) { io_elbow_down();       } else if (stateM3 > 0) { io_elbow_up();          } else { io_elbow_off();       }
        if (stateM4 < 0) { io_base_move_down();   } else if (stateM4 > 0) { io_base_move_up();      } else { io_base_move_off();   }
        if (stateM5 < 0) { io_base_rotate_left(); } else if (stateM5 > 0) { io_base_rotate_right(); } else { io_base_rotate_off(); }

        if (stateM1 > 0) { stateM1--; } else if (stateM1 < 0) { stateM1++; }
        if (stateM2 > 0) { stateM2--; } else if (stateM2 < 0) { stateM2++; }
        if (stateM3 > 0) { stateM3--; } else if (stateM3 < 0) { stateM3++; }
        if (stateM4 > 0) { stateM4--; } else if (stateM4 < 0) { stateM4++; }
        if (stateM5 > 0) { stateM5--; } else if (stateM5 < 0) { stateM5++; }
    }
}
