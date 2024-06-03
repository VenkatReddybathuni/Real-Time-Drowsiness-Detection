#include <Wire.h>
const int MPU1 = 0x68; // I2C address of the first MPU-6050
const int MPU2 = 0x69; // I2C address of the second MPU-6050
int16_t AcX2, AcY2, AcZ2, Gyrox, Gyroy, Gyroz; // definition of variables
int c;
float outputx,outputy,outputz,out1,out2,out3;
int execute=0;
int arr1[10]={2,2,2,2,2,2,2,2,2,2};
int arr2[10]={2,2,2,2,2,2,2,2,2,2};
int arr3[10]={2,2,2,2,2,2,2,2,2,2};
int outs[8]={0,0,0,0,0,0,0,0};
int final=0;
int i=0;
int k=0;
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU1);
  Wire.write(0x6B);
  Wire.write(0b00000000);
  Wire.endTransmission();  
  Wire.beginTransmission(MPU1);
  Wire.write(0x1B);
  Wire.write(0x00000000);
  Wire.endTransmission(); 
  Wire.beginTransmission(MPU1);
  Wire.write(0x1C);
  Wire.write(0b00000000);
  Wire.endTransmission(); 
  
  Wire.begin();
  Wire.beginTransmission(MPU2);
  Wire.write(0x6B);
  Wire.write(0b00000000); 
  Wire.endTransmission();  
  Wire.beginTransmission(MPU2); 
  Wire.write(0x1B);
  Wire.write(0x00000000);
  Wire.endTransmission(); 
  Wire.beginTransmission(MPU2);
  Wire.write(0x1C);
  Wire.write(0b00000000);
  Wire.endTransmission(); 
  Serial.begin(38400);
  
}


void loop() {
  if (final==1){
    final=0;
  }
  int output=0;
  if (execute!=1){function();}
  Wire.beginTransmission(MPU1);
  Wire.write(0x43);  
  Wire.endTransmission();
  Wire.requestFrom(MPU1, 6, true);
  while(Wire.available() < 6);
  float Gyrox = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  float Gyroy = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  float Gyroz = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Wire.beginTransmission(MPU2);
  Wire.write(0x43);  
  Wire.endTransmission();
  Wire.requestFrom(MPU2, 6, true); 
  while(Wire.available() < 6);
  float Gyrox1 = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  float Gyroy1= Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  float Gyroz1 = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  float Rotx = (Gyrox / 131); 
  float Roty = (Gyroy / 131);
  float Rotz = (Gyroz / 131);
  float Rotx1 = (Gyrox1 / 131); 
  float Roty1 = (Gyroy1 / 131);
  float Rotz1 = (Gyroz1 / 131);
  out1=(Rotx-Rotx1)*0.5-outputx;
  out2=(Roty-Roty1)*0.5-outputy;
  out3=(Rotz-Rotz1)*0.5-outputz;
  if (i>9)
  {
    i=0;
  }
  arr1[i]=out1;
  arr2[i]=out2;
  arr3[i]=out3; 
  i++;
  int j=0;
  int count=0;
  while (j<10)
  {
    if (arr1[j]>1 || arr2[j]>1 || arr3[j]>1)
    {
      count++;
    }
    j++;
  }
  if(count<6){
    output=1;
  }
 
  if (k>7){
    k=0;
  }
  outs[k]=output;
  k++;
  j=0;
  count=0;
  while (j<8)
  {
    if (outs[j]==1)
    {
      count++;
    }
    j++;
  }
  if (count==8){
    final=1;
  }
  delay(500);
  Serial.println(final);

  
}
void function(){
  int c=0;
  while (c<200){
  Wire.beginTransmission(MPU1);
  Wire.write(0x43);  
  Wire.endTransmission();
  Wire.requestFrom(MPU1, 6, true);
  while(Wire.available() < 6);
  float Gyrox = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  float Gyroy = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  float Gyroz = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  Wire.beginTransmission(MPU2);
  Wire.write(0x43);  
  Wire.endTransmission();
  Wire.requestFrom(MPU2, 6, true); 
  while(Wire.available() < 6);
  float Gyrox1 = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  float Gyroy1= Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  float Gyroz1 = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  float Rotx = (Gyrox / 131); 
  float Roty = (Gyroy / 131);
  float Rotz = (Gyroz / 131);
  float Rotx1 = (Gyrox1 / 131); 
  float Roty1 = (Gyroy1 / 131);
  float Rotz1 = (Gyroz1 / 131);
  outputx=outputx+(Rotx-Rotx1)*0.5;
  outputy=outputy+(Roty-Roty1)*0.5;
  outputz=outputz+(Rotz-Rotz1)*0.5;
  delay(500);
  c++;}
  outputx=outputx/200;
  outputy=outputy/200;
  outputz=outputz/200;
  execute=1;
}