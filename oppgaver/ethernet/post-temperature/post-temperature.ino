#include <enc28j60.h>
#include <EtherCard.h>
#include <net.h>
#include <Wire.h>
#include <DHT11.h>

// 1: bytt ut MAC adressen slik at alle får unik adresse
byte mymac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };
byte Ethernet::buffer[700];
const char website[] PROGMEM = "192.168.1.134";
const char dbName[] PROGMEM = "metric";
int port = 8083;
String groupName = "gruppe1";
Stash stash;

dht11 DHT11;

#define DHT11PIN 2

boolean initiateDhcp(byte *mac) {
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) {
    return false;
  }
  return ether.dhcpSetup();
}

void setup() {
  Serial.begin(9600);
  // 2: initialiser DHCP
  initiateDhcp(mymac);
  ether.printIp("My IP: ", ether.myip);
  // 3: initialiser sensor

}

void loop() {
  // 4: les av sensor
  int chk = DHT11.read(DHT11PIN);
  // 5: post sensordata til server
  switch (chk)
  {
    case DHTLIB_OK:
      postResults();
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    default:
      Serial.println("Unknown error");
      break;
  }

  delay(2000);
}

boolean postResults() {
  float humidity = (float)DHT11.humidity;
  float temperature = (float) DHT11.temperature;
  Serial.print("temperature");
  Serial.println(temperature);

  Serial.println("Prepare POST");
  byte sd = stash.create();
  stash.print("temperature,group=");
  stash.print(groupName);
  stash.print(" ");
  stash.println(temperature);

  stash.print("humidity,group=");
  stash.print(groupName);
  stash.print(" ");
  stash.println(humidity);
  stash.save();
  int stash_size = stash.size();

  Stash::prepare(PSTR("POST http://$F:$D/write?db=$F HTTP/1.0" "\r\n"
    "Host: $F" "\r\n"
    "Content-Length: $D" "\r\n"
    "\r\n"
    "$H"),
  website, port, dbName, website, stash_size, sd);
  stash.println("Sending POST");
  ether.tcpSend();  

}





