#include "mbed.h"
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

DigitalOut trigS(p25);
DigitalIn EchoR(p8);
DigitalOut trigR(p24);
Timer t;

void LEDOutput(){
        //This is for the output on the mbed board
        led4 = 0;
        led1 = 1;
        wait(1);
        led2 = 1;
        wait(1);
        led3 = 1;
        wait(1);
        led1 = 0;        
        led2 = 0;        
        led3 = 0;
        wait(0.5);
        led1 = 1;        
        led2 = 1;        
        led3 = 1;
        wait(0.5);
        led1 = 0;        
        led2 = 0;        
        led3 = 0;
    }

int main() {
    while(1) {
        
        trigS = 1;
        double distance;

        if(EchoR){
            t.start();
            
            wait(3);
        }   
        else{
            t.stop();
            printf("Error\n");
        }
        
        distance = t.read() * 0.034;
        printf("Distance is: %f\r\n", t.read(),distance);
        wait(1);
    }
}
