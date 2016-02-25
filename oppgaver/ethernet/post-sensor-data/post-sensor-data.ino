#include <enc28j60.h>
#include <EtherCard.h>
#include <net.h>

// 1: bytt ut MAC adressen slik at alle får unik adresse
byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
byte Ethernet::buffer[700];

boolean initiateDhcp(byte *mac) {
  if (ether.begin(sizeof Ethernet::buffer, mac) == 0) {
    return false;
  }
  return ether.dhcpSetup();
}

void setup() {
  // 2: initialiser DHCP
  // 3: initialiser sensor

}

void loop() {
  // 4: les av sensor
  // 5: post sensordata til server http://192.168.2.21/gruppe/sensor/
  

}
