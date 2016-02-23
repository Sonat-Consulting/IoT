# Ethernet oppgave
En enkel måte å få en enhet på nett er å bruke kablet nett (Ethernet).

Til våre byggesett har vi kjøpt inn en modul som heter ENC28J60.
For å bruke denne trenger du et eget bibliotek kalt [EtherCard](https://github.com/jcw/ethercard).

For å gjøre tilgjengelig i Arduiono utviklingsmiljø laster du ned [biblioteket](https://github.com/jcw/ethercard/archive/master.zip)

* åpne Arduiono IDE
* gå til menyvalg __Skisse -> Administrer bibliotek -> Legg til ZIP bibliotek__ og finn frem ZIP filen du lastet ned 

## Tilkoblinger
![Ethernet kort](HR91105A.jpeg)

Du kobler til Ethernet kortet til Arduino kortet som følger:
* ENC SO -> digital pin 12
* ENC SI -> digital pin 11
* ENC SCK -> digital pin 13
* ENC CS -> digital pin 8
* ENC VCC -> 3V3 pin
* ENC GND -> Gnd pin
