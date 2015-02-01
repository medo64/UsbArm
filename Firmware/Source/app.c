#include "config.h"
#include "io.h"
#include "uart.h"


void main() {
    init();

    uart_init(9600);
    uart_writeByte('.');

    io_init();

    bool stateLed = false;
    int8_t stateM1 = 0;
    int8_t stateM2 = 0;
    int8_t stateM3 = 0;
    int8_t stateM4 = 0;
    int8_t stateM5 = 0;

    while (true) {
        clearWatchdog();

        if (uart_canRead()) {
            uint8_t cmd = uart_readByte();
            switch (cmd) {
                case 'a': if (stateM1 > 0) { stateM1 = 0; } else if (stateM1 > -100) { stateM1--; } break;
                case 'd': if (stateM1 < 0) { stateM1 = 0; } else if (stateM1 <  100) { stateM1++; } break;
                case 'w': if (stateM2 > 0) { stateM2 = 0; } else if (stateM2 > -100) { stateM2--; } break;
                case 's': if (stateM2 < 0) { stateM2 = 0; } else if (stateM2 <  100) { stateM2++; } break;
                case 'j': if (stateM3 > 0) { stateM3 = 0; } else if (stateM3 > -100) { stateM3--; } break;
                case 'l': if (stateM3 < 0) { stateM3 = 0; } else if (stateM3 <  100) { stateM3++; } break;
                case 'i': if (stateM4 > 0) { stateM4 = 0; } else if (stateM4 > -100) { stateM4--; } break;
                case 'k': if (stateM4 < 0) { stateM4 = 0; } else if (stateM4 <  100) { stateM4++; } break;
                case 'v': if (stateM5 > 0) { stateM5 = 0; } else if (stateM5 > -100) { stateM5--; } break;
                case 'b': if (stateM5 < 0) { stateM5 = 0; } else if (stateM5 <  100) { stateM5++; } break;
                case 'g': stateLed = !stateLed; break;
            }
            uart_writeByte(cmd);
        }

        if (stateLed) { io_led_on(); } else { io_led_off(); }
        if (stateM1 < 0) { io_gripper_close();    } else if (stateM1 > 0) { io_gripper_open();      } else { io_gripper_toggle();     }
        if (stateM2 < 0) { io_wrist_down();       } else if (stateM2 > 0) { io_wrist_up();          } else { io_wrist_toggle();       }
        if (stateM3 < 0) { io_elbow_down();       } else if (stateM3 > 0) { io_elbow_up();          } else { io_elbow_toggle();       }
        if (stateM4 < 0) { io_base_move_down();   } else if (stateM4 > 0) { io_base_move_up();      } else { io_base_move_toggle();   }
        if (stateM5 < 0) { io_base_rotate_left(); } else if (stateM5 > 0) { io_base_rotate_right(); } else { io_base_rotate_toggle(); }
    }
}
