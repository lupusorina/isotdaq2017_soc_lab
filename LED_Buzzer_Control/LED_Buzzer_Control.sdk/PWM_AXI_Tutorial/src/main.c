#include "xparameters.h"
#include "xil_io.h"
#include "stdlib.h"
#include "itoa_fcn.h"

#define MY_PWM_MEMORY_MAP 0x43C00000 //This value is found in the Address editor tab in Vivado (next to Diagram tab)
#define MY_PWM_MEMORY_MAP_OFFSET 4
#define FREQUENCY_FPGA 50000000 // 50 MHz

void print_memory_mapped_registers();

// Generate a random number between 1 and 3 (1 - red; 2 - green;  3 - blue)
// Every time the red color is showed, activate the buzzer for 1 seconds
int main(){
    int red_pwm = 0;
    int blue_pwm = 0;
    int green_pwm = 0;

    int led_duty_cycle_max = 50000;
    int rand_choose_color;
    int i;

    while(1){


    	rand_choose_color = (rand() % 3) + 1;
    	print("Generated random color: ");
    	switch (rand_choose_color){
    			case 1:
    				red_pwm = 0;
    				blue_pwm = led_duty_cycle_max;
       				green_pwm = led_duty_cycle_max;
       				print("RED");
       				print("\n");
       			break;

    			case 2:
    				red_pwm = led_duty_cycle_max;
    				blue_pwm = 0;
    				green_pwm = led_duty_cycle_max;
    				print("BLUE");
    				print("\n");
    			break;

    			case 3:
    				red_pwm = led_duty_cycle_max;
    				blue_pwm = led_duty_cycle_max;
    				green_pwm = 0;
    				print("GREEN");
    				print("\n");
    			default:
    				red_pwm = led_duty_cycle_max;
    				blue_pwm = led_duty_cycle_max;
    				green_pwm = 0;
    	}


        Xil_Out32(MY_PWM_MEMORY_MAP, red_pwm);
        Xil_Out32((MY_PWM_MEMORY_MAP + MY_PWM_MEMORY_MAP_OFFSET), blue_pwm);
        Xil_Out32((MY_PWM_MEMORY_MAP + 2 * MY_PWM_MEMORY_MAP_OFFSET), green_pwm);


        print_memory_mapped_registers();

        // wait 3 seconds
        for(i=0;i < 3 * FREQUENCY_FPGA; i++){
        	print("");
        }



    }
}

void print_memory_mapped_registers(){
	int register_red_pwm;
	int register_green_pwm;
	int register_blue_pwm;
	char buffer_red[10];
    char buffer_blue[10];
    char buffer_green[10];

	register_red_pwm = Xil_In32(MY_PWM_MEMORY_MAP);
	register_green_pwm = Xil_In32(MY_PWM_MEMORY_MAP);
	register_blue_pwm = Xil_In32(MY_PWM_MEMORY_MAP);

	itoa_fcn(register_red_pwm, buffer_red);
	itoa_fcn(register_green_pwm, buffer_green);
	itoa_fcn(register_blue_pwm, buffer_blue);

	print("(REG READ at address 0x43C00000): Duty Cycle for RED: = ");
	print(buffer_red);
	print("\n");
	print("(REG READ at address 0x43C00004): Duty Cycle for GREEN: = ");
	print(buffer_green);
	print("\n");
	print("(REG READ at address 0x43C00008): Duty Cycle for BLUE: = ");
	print(buffer_blue);
	print("\n");
	print("---------------------------------------------------------");

}
