#include <enc28j60.h>
#include <EtherCard.h>
#include <net.h>

byte mymac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };
byte Ethernet::buffer[700];
boolean hasPrinted = false;

void setup() {
  Serial.begin(9600);
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
    Serial.println( "Failed to access Ethernet controller");
  if (!ether.dhcpSetup())
  {
    Serial.println("Could not obtain lease");
  }

}

void loop() {
  if (! hasPrinted) {
    ether.printIp("My IP: ", ether.myip);
    ether.printIp("GW IP: ", ether.gwip);
    ether.printIp("DNS IP: ", ether.dnsip);
    hasPrinted = true;
  }
}
