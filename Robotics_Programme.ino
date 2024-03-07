


#include <Servo.h>



Servo myservo;
Servo myservo2;
Servo myservo3;

int potpin = A0;
int val;

int potpin2 = A1;
int val2;

int potpin3 = A2;
int val3;

int button_input = 6;
int EM_output = 7;
int state = 0;
bool EM_POWER = false;




void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  myservo2.attach(4);
  myservo3.attach(3);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(button_input, INPUT);
  pinMode(EM_output, OUTPUT);
}

void loop() {

  if (digitalRead(button_input) == HIGH) {
    EM_POWER = !EM_POWER;
    digitalWrite(EM_output, EM_POWER);
    Serial.print("The button state is:");
Serial.println(EM_POWER);
  }










  delay(15);  // waits for the servo to get there


  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);

  val2 = analogRead(potpin2);
  val2 = map(val2, 0, 1023, 0, 180);
  myservo2.write(val2);

  val3 = analogRead(potpin3);
  val3 = map(val3, 0, 1023, 0, 180);
  myservo3.write(val3);

  
}
