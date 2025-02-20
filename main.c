#include <reg51.h>
#include <stdio.h>

sbit C1 = P3^0;
sbit C2 = P3^1;
sbit C3 = P3^2;
sbit R1 = P3^3;
sbit R2 = P3^4;
sbit R3 = P3^5;
sbit R4 = P3^6;

sbit motor_pin_1=P3^7;
sbit motor_pin_2=P2^7;



unsigned char numbers[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

void delay(unsigned int t) {
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 1275; j++);
}

unsigned char search() {
    R1 = 0; R2 = R3 = R4 = 1; 
    if (C1 == 0) return '1';
    if (C2 == 0) return '2';
    if (C3 == 0) return '3';
    R2 = 0; R1 = R3 = R4 = 1; 
    if (C1 == 0) return '4';
    if (C2 == 0) return '5';
    if (C3 == 0) return '6';
    R3 = 0; R1 = R2 = R4 = 1; 
    if (C1 == 0) return '7';
    if (C2 == 0) return '8';
    if (C3 == 0) return '9';
    R4 = 0; R1 = R2 = R3 = 1; 
    if (C1 == 0) return '*';
    if (C2 == 0) return '0';
    if (C3 == 0) return '#';
    return 0; // No key pressed
}

void main() {
    unsigned char num;
     
    
    while (1) {
      R1 = R2 = R3 = R4 = 1; 
      P2 = 0x00;
      P1=0x00;
      motor_pin_1=motor_pin_2=1;

        num = search();
        if (num != 0) { 
            switch (num) {
                case '0': P2 = numbers[0];P1=(0x00);motor_pin_1=0;motor_pin_2=1; break;
                case '1': P2 = numbers[1];P1=(0x01);motor_pin_2=1 ;motor_pin_1=0;break;
                case '2': P2 = numbers[2];P1=(0x02); break;
                case '3': P2 = numbers[3];P1=(0x04); break;
                case '4': P2 = numbers[4];P1=(0x08); break;
                case '5': P2 = numbers[5];P1=(0x10); break;
                case '6': P2 = numbers[6];P1=(0x20); break;
                case '7': P2 = numbers[7];P1=(0x40); break;
                case '8': P2 = numbers[8];P1=(0x80); break;
                case '9': P2 = numbers[9];P1=(0x01); break;
            }
            delay(20); 
        }
    }
}
	
