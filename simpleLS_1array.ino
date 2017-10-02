#define MAX_SPEED 255
#define AVG_SPEED 120
#define MIN_SPEED 0

int AB_PWM = 2;
int BC_PWM = 3;
int CD_PWM = 4;
int DA_PWM = 5;

int AB_DIR = 22;
int BC_DIR = 23;
int CD_DIR = 24;
int DA_DIR = 25;

int ir0 = 0;
int ir1 = 0;
int ir2 = 0;
int ir3 = 0;
int ir4 = 0;
int ir5 = 0;
int ir6 = 0;
int ir7 = 0;

void setup() {
  
  pinMode(AB_DIR, OUTPUT);
  pinMode(BC_DIR, OUTPUT);
  pinMode(CD_DIR, OUTPUT);
  pinMode(DA_DIR, OUTPUT);

  pinMode(AB_PWM, OUTPUT);
  pinMode(BC_PWM, OUTPUT);
  pinMode(CD_PWM, OUTPUT);
  pinMode(DA_PWM, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  ReadValues();
  
 //assuming the ir values to be high on white and low on red/green since the array is currently unavailable 
 
 if(ir0 == LOW &&  ir1 == LOW && ir2 == LOW &&  ir3 == HIGH && ir4 == HIGH &&  ir5 == LOW && ir6 == LOW &&  ir7 == LOW )
  {
  //move forward
  FORWARD(MAX_SPEED);
  }
 
  else if(ir0 == LOW &&  ir1 == LOW &&  ir3 == HIGH && ir4 == HIGH &&  ir5 == HIGH && ir6 == HIGH &&  ir7 == HIGH )
  {
  //ir2 - don't care
  //A right turn occured
  RIGHT(MAX_SPEED);
  //now next ir array comes into effect
  }
  
  else if(ir0 == HIGH &&  ir1 == HIGH && ir2 == HIGH &&  ir3 == HIGH && ir4 == HIGH && ir6 == LOW &&  ir7 == LOW )
  {
  //ir5 - don't care
  //a left turn occured
  LEFT(MAX_SPEED);
  //now next ir array comes into effect
  }
  
  else if(ir0 == LOW &&  ir1 == LOW && ir2 == LOW &&  ir3 == HIGH && ir4 == HIGH &&  ir5 == HIGH &&  ir7 == LOW )
  {
  //ir6 - don't care
  //shift right
  while(!(ir0 == LOW &&  ir1 == LOW && ir2 == LOW &&  ir3 == HIGH && ir4 == HIGH &&  ir5 == LOW && ir6 == LOW &&  ir7 == LOW ))
  {
  FORWARD_RIGHT();
  ReadValues();
  }
  }
 
 else if(ir0 == LOW && ir2 == HIGH &&  ir3 == HIGH && ir4 == HIGH &&  ir5 == LOW && ir6 == LOW &&  ir7 == LOW )
  {
  //ir1 - don't care
  //shift left
  while(!(ir0 == LOW &&  ir1 == LOW && ir2 == LOW &&  ir3 == HIGH && ir4 == HIGH &&  ir5 == LOW && ir6 == LOW &&  ir7 == LOW ))
  {
  FORWARD_LEFT();
  ReadValues();
  }
  }
 
  }

  void ReadValues() 
  {
  ir0 = analogRead(A0);
  ir1 = analogRead(A1);
  ir2 = analogRead(A2);
  ir3 = analogRead(A3);
  ir4 = analogRead(A4);
  ir5 = analogRead(A5);
  ir6 = analogRead(A6);
  ir7 = analogRead(A7);
  }

  void FORWARD(int SPEED) 
  {
  analogWrite(AB_PWM, SPEED);
  analogWrite(BC_PWM, SPEED);
  analogWrite(CD_PWM, SPEED);
  analogWrite(DA_PWM, SPEED);
  //make sure high results in forward rotation of every wheel
  analogWrite(AB_DIR, HIGH);
  analogWrite(BC_DIR, HIGH);
  analogWrite(CD_DIR, HIGH);
  analogWrite(DA_DIR, HIGH);
  }
  
  void BACKWARD(int SPEED) 
  {
  analogWrite(AB_PWM, SPEED);
  analogWrite(BC_PWM, SPEED);
  analogWrite(CD_PWM, SPEED);
  analogWrite(DA_PWM, SPEED);
  //make sure low results in backward rotation of every wheel
  analogWrite(AB_DIR, LOW);
  analogWrite(BC_DIR, LOW);
  analogWrite(CD_DIR, LOW);
  analogWrite(DA_DIR, LOW);
  }
  
  void LEFT(int SPEED) 
  {
  analogWrite(AB_PWM, SPEED);
  analogWrite(BC_PWM, SPEED);
  analogWrite(CD_PWM, SPEED);
  analogWrite(DA_PWM, SPEED);

  analogWrite(AB_DIR, LOW);
  analogWrite(BC_DIR, HIGH);
  analogWrite(CD_DIR, LOW);
  analogWrite(DA_DIR, HIGH);
  }
  
  void RIGHT(int SPEED) 
  {
  analogWrite(AB_PWM, SPEED);
  analogWrite(BC_PWM, SPEED);
  analogWrite(CD_PWM, SPEED);
  analogWrite(DA_PWM, SPEED);
  
  analogWrite(AB_DIR, HIGH);
  analogWrite(BC_DIR, LOW);
  analogWrite(CD_DIR, HIGH);
  analogWrite(DA_DIR, LOW);
  }

  void FORWARD_RIGHT() 
  {
  analogWrite(AB_PWM, MAX_SPEED);
  analogWrite(BC_PWM, AVG_SPEED);
  analogWrite(CD_PWM, AVG_SPEED);
  analogWrite(DA_PWM, MAX_SPEED);
  //make sure high results in forward rotation of every wheel
  analogWrite(AB_DIR, HIGH);
  analogWrite(BC_DIR, HIGH);
  analogWrite(CD_DIR, HIGH);
  analogWrite(DA_DIR, HIGH);
  }

  void FORWARD_LEFT() 
  {
  analogWrite(AB_PWM, AVG_SPEED);
  analogWrite(BC_PWM, MAX_SPEED);
  analogWrite(CD_PWM, MAX_SPEED);
  analogWrite(DA_PWM, AVG_SPEED);
  //make sure high results in forward rotation of every wheel
  analogWrite(AB_DIR, HIGH);
  analogWrite(BC_DIR, HIGH);
  analogWrite(CD_DIR, HIGH);
  analogWrite(DA_DIR, HIGH);
  }
