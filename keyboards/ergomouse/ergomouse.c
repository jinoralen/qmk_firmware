#include "ergomouse.h"

#include "pointing_device.h"

#include "analog.h"
#include "drivers/sensors/analog_joystick.h"

void pointing_device_init_kb(void){
    analog_joystick_init();  
}

static bool isEnabled = false;

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    report_analog_joystick_t data = analog_joystick_read();

    if(data.button) {
        isEnabled = !isEnabled;
    }

    // mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, data.button, POINTING_DEVICE_BUTTON1);

    if(isEnabled) {
        mouse_report.x = data.x;
        mouse_report.y = data.y;
    }

    return mouse_report;
}