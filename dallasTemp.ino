//Memasukkan library
#include <OneWire.h> 
#include <LiquidCrystal.h>
#include <DallasTemperature.h>

LiquidCrystal lcd(12,11,10,9,8,7);

#define BUS 2                   // Data wire is plugged into pin 2 on the Arduino
OneWire oneWire(BUS);           // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature s1(&oneWire); // Pass our oneWire reference to Dallas Temperature.

void setup(void){
  Serial.begin(9600);           //Begin serial communication
  lcd.begin(16, 2);
  s1.begin();                   //start sensor
}
void loop(void){ 
  s1.requestTemperatures();           // Send the command to get temperatures
  float T1 = s1.getTempCByIndex(0);   // T1 yang dibaca arduino
  float T2 = s1.getTempCByIndex(1);   // T2 yang dibaca arduino

  T1 = (T1*0.9857) + 0.6016;
  T2 = (T2*1.0331) - 0.9269;

  //Menampilkan ke LCD

  lcd.setCursor(0,0); lcd.print("T1:");
  lcd.setCursor(4,0); lcd.print(T1); lcd.print("   ");
  lcd.setCursor(10,0); lcd.print((char)223);
  lcd.setCursor(11,0); lcd.print("C");
  
  lcd.setCursor(0,1); lcd.print("T2:");
  lcd.setCursor(4,1); lcd.print(T2); lcd.print("   ");
  lcd.setCursor(10,1); lcd.print((char)223);
  lcd.setCursor(11,1); lcd.print("C");
  
  delay(100); //Update value every 1 sec.
}
