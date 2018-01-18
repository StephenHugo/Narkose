#include <Wire.h>
int Device_Address = 0x78; // Device address in which is also included the 8th bit for selecting the mode, read in this case.
#define Device_ID_Register 0x00 // Hexadecima address for the Device ID internal register.
#define Power_Mode_Register 0x01 // Hexadecima address for the Power Mode internal register.
#define Frequency_Register 0x02 // Hexadecima address for the Output Frequency internal register.
#define Slope_Shape_Register 0x03 // Hexadecima address for the Signal Shape internal register.
#define Boost_Converter_Register 0x04 // Hexadecima address for the Boost Converter internal register.
#define Audio_Register 0x05 // Hexadecima address for the Audio Effects internal register.
#define Ramp_Time_CH_1_Register 0x06 // Hexadecima address for the Peak output voltage ramping time CH 1 internal register.
#define Ramp_Time_CH_2_Register 0x07 // Hexadecima address for the Peak output voltage ramping time CH 2 internal register.
#define Ramp_Time_CH_3_Register 0x08 // Hexadecima address for the Peak output voltage ramping time CH 3 internal register.
#define Ramp_Time_CH_4_Register 0x09 // Hexadecima address for the Peak output voltage ramping time CH 4 internal register.
//#define Power_Register 0x2D // Power Control Register
int X0,X1,X2,X3,X4,X5,X6,X7,X8,X9;
void setup() {
  Wire.begin(); // Initiate the Wire library
  Serial.begin(9600);
  delay(100);
  // Enable measurement
  Wire.beginTransmission(Device_Address);
  Wire.write(Power_Mode_Register);
  // Bit D3 High for measuring enable (0000 1000)
  Wire.write(1);  // not sure here
  Wire.endTransmission();
}
void loop() {
  Wire.beginTransmission(Device_Address); // Begin transmission to the Sensor
  //Ask the particular registers for data
  Wire.write(Device_ID_Register);
  Wire.write(Frequency_Register);
  Wire.write(Slope_Shape_Register);
  Wire.write(Boost_Converter_Register);
  Wire.write(Audio_Register);
  Wire.write(Ramp_Time_CH_1_Register);
  Wire.write(Ramp_Time_CH_2_Register);
  Wire.write(Ramp_Time_CH_3_Register);
  Wire.write(Ramp_Time_CH_4_Register);
 
  Wire.endTransmission(); // Ends the transmission and transmits the data from the ten registers
 
  Wire.requestFrom(Device_Address,10); // Request the transmitted two bytes from the ten registers
 
  if(Wire.available()<=10) {  //
  X0 = Wire.read(); // Reads the data from the register
  X1 = Wire.read();  
  X2 = Wire.read();
  X3 = Wire.read();
  X4 = Wire.read();
  X6 = Wire.read();
  X7 = Wire.read();
  X8 = Wire.read();
  X9 = Wire.read();
  }
 
  Serial.print("X0= ");
  Serial.println(X0, BIN);
  Serial.print("   X1= ");
  Serial.println(X1, BIN);
  Serial.print("   X2= ");
  Serial.println(X2, BIN);
  Serial.print("   X3= ");
  Serial.println(X3, BIN);
  Serial.print("   X4= ");
  Serial.println(X4, BIN);
  Serial.print("   X5= ");
  Serial.println(X5, BIN);
  Serial.print("   X6= ");
  Serial.println(X6, BIN);
  Serial.print("   X7= ");
  Serial.println(X7, BIN);
  Serial.print("   X8= ");
  Serial.println(X8, BIN);
  Serial.print("   X9= ");
  Serial.println(X9, BIN);
  delay(50000);
}

