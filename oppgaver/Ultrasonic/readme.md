Oppgave: å få en buzzer til å pipe og lys til å lyse, med volum og lysstyrke styrt av en ultralydsensor

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
	- Enheter som skal ha variabel strømstyrke, må kobles til digtal output merket PWM
	- Langt bein betyr pluss
	- Bruk de langsgående + og - feltene på breadboardet
	- Den ultrasoniske sensoren har fire pins, Volt, trigger, echo og jord
	- Husk at LED-ene ikke bør ha mer enn 18mA strøm gjennom seg!
	
- Kode:
	- Pins som skal gi analog output, trenger ikke å konfigureres i setup()
	- Sensoren initialiseres slik: Ultrasonic ultrasonic(pin, pin)
	- For å lese av sensoren: ultrasonic.Ranging(CM)
	- Forsøk dere frem for å finne fornuftige verdier for lyd- og lysstyrke
	- Skriv sensorverdien til skjerm for lettere debugging
	
- For de avanserte:
	- Seriekoble LED-ene, koble på flere
	- Parallellkoble resistors for å få sterkere (men ikke for sterkt!) lys i LED-ene
	- Lag en robot