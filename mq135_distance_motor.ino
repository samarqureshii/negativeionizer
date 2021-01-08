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
pinMode(leftMotor_forward, OUTPUT);
pinMode(leftMotor_backward, OUTPUT);
pinMode(rightMotor_forward,OUTPUT);
pinMode(rightMotor_backward, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}

void loop() {
sensorValue = analogRead(0); // read analog input pin 0
Serial.print("AirQuality=");
Serial.print(sensorValue, DEC); // prints the value read
Serial.println(" PPM\t");


digitalWrite(trigPin, LOW);
delayMicroseconds(1000);
digitalWrite(trigPin, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;
Serial.print("\t\t\t\t\t\t\t\tDistance:");
Serial.println(distance);

}
