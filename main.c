#include <REGX51.H>

#define MYDATA P0

sbit rs = P3^2;
sbit rw = P3^3;
sbit en = P3^4;

sbit A1 = P1^0;
sbit A2 = P1^1;
sbit A3 = P1^2;

sfr datas = 0xA0; // Mapping data lines to Port 2

void lcdinit(void);
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void delay(unsigned int);
void init_uart(void);
void txs(unsigned char);

// LCD Initialization
void lcdinit(void) {
    lcdcmd(0x38);  // 2 lines, 5x7 matrix
    lcdcmd(0x0C);  // Display ON, Cursor OFF
    lcdcmd(0x06);  // Auto Increment cursor
    lcdcmd(0x01);  // Clear display
    lcdcmd(0x80);  // Cursor to first line
}

// Send command to LCD
void lcdcmd(unsigned char lcmd) {
    datas = lcmd;
    rs = 0;
    rw = 0;
    en = 1;
    delay(100);
    en = 0;
}

// Send data to LCD
void lcddata(unsigned char ldat) {
    datas = ldat;
    rs = 1;
    rw = 0;
    en = 1;
    delay(100);
    en = 0;
}

// Basic delay function
void delay(unsigned int del) {
    while(del--);
}

// UART Initialization (9600 baud for 11.0592 MHz clock)
void init_uart(void) {
    SCON = 0x50;  // Mode 1, 8-bit UART, REN enabled
    TMOD = 0x20;  // Timer1 in Mode 2 (auto-reload)
    TH1 = 0xFD;   // Baud rate 9600 for 11.0592 MHz
    TR1 = 1;      // Start Timer1
}

// UART Transmit Function
void txs(unsigned char value) {
    SBUF = value;
    while(TI == 0);
    TI = 0;
}

// Main program
void main() {
    unsigned char receivedChar;

    init_uart();
    lcdinit();

    P3_7 = 0; // Optional pins, purpose unknown
    P3_6 = 0;

    while(1) {
        A1 = 0; // Example GPIO control
        A2 = 1;

        while(RI == 0); // Wait for serial input
        receivedChar = SBUF; // Read received character
        RI = 0; // Clear receive interrupt flag

        lcdcmd(0x01); // Clear LCD
        lcdcmd(0x80); // Cursor to start
        lcddata(receivedChar); // Display character

        txs(receivedChar); // Echo back the character
    }
}
