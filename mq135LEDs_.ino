int led1 = 1; //red
int led2 = 2; //yellow
int led3 = 3; //green
int sensorValue;


void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600);

}


void loop() {
sensorValue = analogRead(0); // read analog input pin 0, which is mq135
Serial.print("Air Quality: ");
Serial.println(sensorValue, DEC); // prints the value read as a decimal number
delay(100);

  if(sensorValue>=600){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  sensorValue = analogRead(0);
}

if(sensorValue<600){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  sensorValue = analogRead(0);
}
 
 



}
