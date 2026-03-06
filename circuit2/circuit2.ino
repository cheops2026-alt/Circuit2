#include <LiquidCrystal_I2C.h>
#include <MQ135.h>
#include <DHT11.h>
#include <SoftwareSerial.h>


DHT11 dht11(2);


#define PIN_MQ135 A2
MQ135 mq135_sensor(PIN_MQ135);

// LCD 20x4 I2C
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Bluetooth
const int bluetoothRX = 10;
const int bluetoothTX = 11;
SoftwareSerial BTSerial(bluetoothRX, bluetoothTX);

// Variables
int temperature = 0;
int humidity = 0;
float correctedPPM = 0;
int NO2ppm = 0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}
void loop() {

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  correctedPPM = mq135_sensor.getCorrectedPPM(temperature, humidity);


  int analogVal = analogRead(PIN_MQ135);
  NO2ppm = map(analogVal, 0, 1023, 0, 100); 


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(humidity);
  lcd.print("%");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CO2:");
  lcd.print(correctedPPM);
  lcd.print(" PPM");

  lcd.setCursor(0, 1);
  lcd.print("NO2:");
  lcd.print(NO2ppm);
  lcd.print(" ppm");
  delay(500);



  BTSerial.print("Temp:");
  BTSerial.print(temperature);
  BTSerial.print(",Hum:");
  BTSerial.print(humidity);
  BTSerial.print(",CO2:");
  BTSerial.print(correctedPPM);
  BTSerial.print(",NO2:");
  BTSerial.println(NO2ppm);


  Serial.print("Temp:");
  Serial.print(temperature);
  Serial.print(" Hum:");
  Serial.print(humidity);
  Serial.print(" CO2:");
  Serial.print(correctedPPM);
  Serial.print(" NO2:");
  Serial.println(NO2ppm);

  delay(1000);  
}

