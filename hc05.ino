/*
 <^/M! (FL)              \^> M2 (FR)
   ----------------
  |                            |
  |                            |
  |                            |
  |                            |
  |                            |
   ----------------
 <v\M3 (BL)             /v> M4 (BR)
 */
int m11 = 3; //FL
int m12 = 4;
int m21 = 5; //FR
int m22 = 6;
int m31 = 7; //BL
int m32 = 8;
int m41 = 9; //BR
int m42 = 10;
byte val;



void setup()
{
  Serial.begin(9600);//Change the baud rate value depending on the default baud rate of your bluetooth module
  pinMode(m11, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m31, OUTPUT);
  pinMode(m41, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(m32, OUTPUT);
  pinMode(m42, OUTPUT);
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  digitalWrite(m31, LOW);
  digitalWrite(m32, LOW);
  digitalWrite(m41, LOW);
  digitalWrite(m42, LOW);
}

void loop()
{
 int a=0;
 if(Serial.available())
  {
    val=Serial.read();
    Serial.println(int(val));

    if(int(val)==49)//Move front
    {
      Serial.println("FRONT");
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
      digitalWrite(m31, HIGH);
      digitalWrite(m32, LOW);
      digitalWrite(m41, HIGH);
      digitalWrite(m42, LOW);
    }
    
    if(int(val)==50)//Move back
    {
      Serial.println("BACK");  
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
      digitalWrite(m31, LOW);
      digitalWrite(m32, HIGH);
      digitalWrite(m41, LOW);
      digitalWrite(m42, HIGH);
    }
    
    if(int(val)==51)//left
    {
      Serial.println("LEFT");
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
      digitalWrite(m31, HIGH);
      digitalWrite(m32, LOW);
      digitalWrite(m41, LOW);
      digitalWrite(m42, HIGH);
    }
    
    if(int(val)==52)//right
    {
      Serial.println("RIGHT");
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
      digitalWrite(m31, LOW);
      digitalWrite(m32, HIGH);
      digitalWrite(m41, HIGH);
      digitalWrite(m42, LOW);
    }
    
    if(int(val)==53)//Stop
    {
      Serial.println("STOP");
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, LOW);
      digitalWrite(m31, LOW);
      digitalWrite(m32, LOW);
      digitalWrite(m41, LOW);
      digitalWrite(m42, LOW);
    }
    
    if(int(val)==55)//Extra button
    {
      //Enter your code for any extra commands
    }
    
    }
}
