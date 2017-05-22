#include <OneWire.h>
#include <DallasTemperature.h>

// Data wires are plugged into pin 2 and 3 on the Arduino
#define ONE_WIRE_BUS 2
#define ONE_WIRE_BUS_B 3
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
OneWire oneWireb(ONE_WIRE_BUS_B);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensora(&oneWire);
DallasTemperature sensorb(&oneWireb);

void setup(void)
{
  Serial.begin(9600); //Begin serial communication
  Serial.println("Started"); 
  sensora.begin();
  sensorb.begin();
}

void loop(void)
{ 
  // Send the command to get temperatures
  sensora.requestTemperatures();
  sensorb.requestTemperatures();  
  Serial.print("Air Temperature: ");
  Serial.println(sensora.getTempCByIndex(0)); 
  //Update value every 1 sec.
  Serial.print("Liquid's Temperature: ");
  Serial.println(sensorb.getTempCByIndex(0)); 
  delay(1000);
}
