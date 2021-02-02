#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

int sec = 0; //D
int min = 0; //B
int hor = 12; //A
int pressed_min = 0;
int R_sikkerhet_min = 0;
int P_sikkerhet_min = 0;
int pressed_hor = 0;
int R_sikkerhet_hor = 0;
int P_sikkerhet_hor = 0;
void sett();
char* en[10] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001};
char* ti[10] = {0b00010000, 0b00010001, 0b00010010, 0b00010011, 0b00010100, 0b00010101, 0b00010110, 0b00010111, 0b00011000, 0b00011001};
char* tyve[10] = {0b00100000, 0b00100001, 0b00100010, 0b00100011, 0b00100100, 0b00100101, 0b00100110, 0b00100111, 0b00101000, 0b00101001};
char* tretti[10] = {0b00110000, 0b00110001, 0b00110010, 0b00110011, 0b00110100, 0b00110101, 0b00110110, 0b00110111, 0b00111000, 0b00111001};
char* forti[10] = {0b01000000, 0b01000001, 0b01000010, 0b01000011, 0b01000100, 0b01000101, 0b01000110, 0b01000111, 0b01001000, 0b01001001};
char* femti[10] = {0b01010000, 0b01010001, 0b01010010, 0b01010011, 0b01010100, 0b01010101, 0b01010110, 0b01010111, 0b01011000, 0b01011001};
size_t lengde = 10;

int main(void)
{
 sei();							//aktiverer kommando for global interrupt

 DDRA = 0xff;
 DDRB = 0xff;
 DDRC = 0x00; //// input til knappene og resten output til diodene
 PORTC = 0xff;
 DDRD = 0xff;

 TCCR1B |= 1<<CS12| 1<<WGM12;	//prescaler pa 256
 TIMSK |= 1<<OCIE1A;
 OCR1A = 3905;

 while(1) {
   sjekkKnappMin();
   sjekkKnappHor();
 };
}

ISR(TIMER1_COMPA_vect)
{
 settTid();
 sjekkTid();
}

void settTid() {
 //PORTA = arr[sec];
 //PORTB = arr[min];
 //PORTD = arr[hor];

 //sjekke sekunder
 if(sec < 10) {
   PORTA = en[sec];
 }
 else if(sec < 20) {
   PORTA = ti[sec-10];
 }
 else if(sec < 30) {
   PORTA = tyve[sec-20];
 }
 else if(sec < 40) {
   PORTA = tretti[sec-30];
 }
 else if(sec < 50) {
   PORTA = forti[sec-40];
 }
 else {
   PORTA = femti[sec-50];
 }

 //sjekke minutter
 if(min < 10) {
   PORTB = en[min];
 }
 else if(min < 20) {
   PORTB = ti[min-10];
 }
 else if(min < 30) {
   PORTB = tyve[min-20];
 }
 else if(min < 40) {
   PORTB = tretti[min-30];
 }
 else if(min < 50) {
   PORTB = forti[min-40];
 }
 else {
   PORTB = femti[min-50];
 }

 //sjekke timer
 if(hor < 10) {
   PORTD = en[hor];
 }
 else if(hor < 20) {
   PORTD = ti[hor-10];
 }
 else {
   PORTD = tyve[hor-20];
 }
}

void sjekkTid() {
 if (sec >= 59)		//denne var bare > men da rekker sekunder a bli 60 (?)
 {
   min++;		//sec=0 var forst i orginal kode
   sec = 0;
 }
 else {
   sec++;
 }
 if (min > 59) {
   hor++;
   min = 0;
 }
 if (hor > 23) {
   hor = 0;
 }
}

void sjekkKnappMin() {
 //minKnapp
 if ((bit_is_clear(PINC,0))) {
   P_sikkerhet_min++;
   if (P_sikkerhet_min > 800) {
     if (pressed_min == 0) {
       PORTB = 0b01111111;
       pressed_min = 1;
       min++;
     }
     P_sikkerhet_min = 0;
   }
 }
 else {
   R_sikkerhet_min++;
   if(R_sikkerhet_min > 800) {
     pressed_min = 0;
     R_sikkerhet_min = 0;
   }
 }
}

void sjekkKnappHor() {
 //horKnapp
 if ((bit_is_clear(PINC,1))) {
   P_sikkerhet_hor++;
   if (P_sikkerhet_hor > 800) {
     if (pressed_hor == 0) {
       PORTD = 0b00111111;
       pressed_hor = 1;
       hor++;
     }
     P_sikkerhet_hor = 0;
   }
 }
 else {
   R_sikkerhet_hor++;
   if(R_sikkerhet_hor > 800) {
     pressed_hor = 0;
     R_sikkerhet_hor = 0;
   }
 }
}
