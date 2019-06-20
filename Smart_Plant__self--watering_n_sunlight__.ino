//Motors
#define motorR1 10  // Assigning Right motor pin1 to digitalpin 10 of arduino
#define motorR2 11  // Assigning Right motor pin2 to digitalpin 11 of arduino
#define motorL1 12  // Assigning Left motor pin1 to digitalpin 12 of arduino
#define motorL2 13  // Assigning Left motor pin2 to digitalpin 13 of arduino
#define waterpump 8  // Assigning water pumping motor to digitalpin 8 of arduino

// Sensors
#define SensorLDR1 7  // Assigning LDR sensor1 to digitalpin7 of arduino
#define SensorLDR2 6  // Assigning LDR sensor2 to digitalpin6 of arduino
#define SensorMOISTURE 5 // Assigning Humidity sensor to digitalpin5 of arduino

void setup() {

   //SerialInit
      Serial.begin(9600);
  
  // OutPut Pins
  pinMode(motorR1 , OUTPUT);
  pinMode(motorR2, OUTPUT); 
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);

  pinMode(waterpump, OUTPUT);
   

  //InputPins
  pinMode(SensorLDR1 , INPUT_PULLUP);
  pinMode(SensorLDR2 , INPUT_PULLUP);
  pinMode(SensorMOISTURE, INPUT_PULLUP);
  

}

void loop() {
   Serial.print("Robot is not moving...\r\n"); 
   digitalWrite(motorR1, LOW); digitalWrite(motorR2, LOW);
   digitalWrite(motorL1, LOW); digitalWrite(motorL2, LOW);
   
   digitalWrite(waterpump, LOW); // Water pump is in OFF state
   
if(digitalRead(SensorLDR1) ==  HIGH && digitalRead(SensorLDR2) ==  LOW )
{
    Serial.print("Sun light is Detected by LDR1...Robot is moving towards LDR1\r\n");
   digitalWrite(motorR1, HIGH); digitalWrite(motorR2, LOW);
   digitalWrite(motorL1, HIGH); digitalWrite(motorL2, LOW);
    while(digitalRead(SensorLDR2) ==  HIGH);

    Serial.print("Sun light is Detected by both sensors.. Robot stops moving\r\n");
}

if(digitalRead(SensorLDR1) ==  LOW && digitalRead(SensorLDR2) ==  HIGH )
{
    Serial.print("Sun light is Detected by LDR2.. Robot is moving towards LDR2 \r\n");
   digitalWrite(motorR1, LOW); digitalWrite(motorR2, HIGH);
   digitalWrite(motorL1, LOW); digitalWrite(motorL2, HIGH);
    while(digitalRead(SensorLDR1) ==  HIGH);

    Serial.print("Sun light is Detected by both sensors.. Robot stops moving\r\n");
}

if(digitalRead(SensorMOISTURE) ==  LOW) 
{
    Serial.print("LOW Moisture content in Soil \r\n");
    digitalWrite(waterpump, HIGH); 
    Serial.print("Water Pump is serving the water \r\n");
    delay(2000);
    digitalWrite(waterpump, LOW);
    Serial.print("Water Pump is is in OFF state \r\n");
   
}


}
