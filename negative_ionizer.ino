int led1 = 1; //green
int led2 = 2; //yellow
int led3 = 3; //red

int inPin = 2;
int trigPin = 5;
int echoPin = 6;
int leftMotor_forward = 9;
int leftMotor_backward = 10;
int rightMotor_forward = 11;
int rightMotor_backward = 12;
long duration;
int distance, sensorValue;


void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
lcd.begin(16, 2);



pinMode(leftMotor_forward, OUTPUT);
pinMode(leftMotor_backward, OUTPUT);
pinMode(rightMotor_forward,OUTPUT);
pinMode(rightMotor_backward, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);

}

void forward(int duration){

digitalWrite(leftMotor_forward, HIGH);

digitalWrite(leftMotor_backward, LOW);

digitalWrite(rightMotor_forward, HIGH);

digitalWrite(rightMotor_backward,LOW);

delay(duration);

}

void backward(int duration){

digitalWrite(leftMotor_forward, LOW);

digitalWrite(leftMotor_backward, HIGH);

digitalWrite(rightMotor_forward, LOW);

digitalWrite(rightMotor_backward, HIGH);

delay(duration);

}



void Stop (int duration){

digitalWrite(leftMotor_forward,LOW);

digitalWrite(leftMotor_backward,LOW);

digitalWrite(rightMotor_forward, LOW);

digitalWrite(rightMotor_backward, LOW);

delay(duration);

}



void pivotLeft(int pivotDuration){

digitalWrite(leftMotor_forward,LOW);

digitalWrite(leftMotor_backward,HIGH);

digitalWrite(rightMotor_forward, HIGH);

digitalWrite(rightMotor_backward, LOW);

delay(pivotDuration);

}



void pivotRight(int pivotDuration){

digitalWrite(leftMotor_forward,HIGH);

digitalWrite(leftMotor_backward,LOW);

digitalWrite(rightMotor_forward, LOW);

digitalWrite(rightMotor_backward, HIGH);

delay(pivotDuration);

}



void loop() {

sensorValue = analogRead(0); // read analog input pin 0

Serial.print("AirQuality=");

Serial.print(sensorValue, DEC); // prints the value read

Serial.println(" PPM");

lcd.setCursor(0,0);

lcd.print("ArQ=");

lcd.print(sensorValue,DEC);

lcd.print(" PPM");

lcd.println(" ");

lcd.print(" ");

delay(100);



digitalWrite(trigPin, LOW);

delayMicroseconds(1000);

digitalWrite(trigPin, HIGH);

delayMicroseconds(1000);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = duration*0.034/2;

Serial.print("Distance:");

Serial.println(distance);



backward(1000);



while(sensorValue<=300){

backward(100000);

digitalWrite(led1, HIGH);

digitalWrite(led2, LOW);

digitalWrite(led2, LOW);

if (distance<10){

forward(2000);

pivotRight(1400);

}

}



while (sensorValue>300 && sensorValue<400) {

backward(100000);

digitalWrite(led1, LOW);

digitalWrite(led2, HIGH);

digitalWrite(led3, LOW);

if (distance<10){

forward(2000);

pivotRight(1400);

}

}



while (sensorValue>=400) {

backward(100000);

digitalWrite(led1, LOW);

digitalWrite(led2, LOW);

digitalWrite(led3, HIGH);

if (distance<10){

forward(2000);

pivotRight(1400);

}

}

}
