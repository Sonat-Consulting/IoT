Oppgave: � f� en buzzer til � pipe og lys til � lyse, med volum og lysstyrke styrt av en ultralydsensor

Deler:
- Arduino Uno
- Breadboard
- Red LED
- Green LED
- Buzzer
- Ultrasonic sensor
- Ev. resistors
- kabler

Tips og triks:
- Kobling
	- Enheter som skal ha variabel str�mstyrke, m� kobles til digtal output merket PWM
	- Langt bein betyr pluss
	- Bruk de langsg�ende + og - feltene p� breadboardet
	- Den ultrasoniske sensoren har fire pins, Volt, trigger, echo og jord
	- Husk at LED-ene ikke b�r ha mer enn 18mA str�m gjennom seg!
	
- Kode:
	- Pins som skal gi analog output, trenger ikke � konfigureres i setup()
	- Sensoren initialiseres slik: Ultrasonic ultrasonic(pin, pin)
	- For � lese av sensoren: ultrasonic.Ranging(CM)
	- Fors�k dere frem for � finne fornuftige verdier for lyd- og lysstyrke
	- Skriv sensorverdien til skjerm for lettere debugging
	
- For de avanserte:
	- Seriekoble LED-ene, koble p� flere
	- Parallellkoble resistors for � f� sterkere (men ikke for sterkt!) lys i LED-ene
	- Lag en robot