
	LIST      p=16F84            ; Définition de processeur
	#include <p16F84.inc>        ; Définitions de variables

	__CONFIG   _CP_ON & _WDT_OFF & _PWRTE_ON & _HS_OSC


org 0x0005

BSF status,rp0
bsf trisa,0
bcf trisb,0

BCF status,rp0
bcf portb,0

test BTFSS porta,0
     goto OFF
     goto ON

ON bsf portb,0
   goto test

OFF bcf portb,0
   goto test

END

