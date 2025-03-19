int sensor=8;
int buzzer=4;
int SENSORTHRESHOLD = 200;
int detectionState;
//int BUZZER = 4;
int GAS_SENSOR = A1;
//int SENSORTHRESHOLD = 200;
void setup() {
  // put your setup code here, to run once:
 pinMode(buzzer,OUTPUT);
  pinMode(sensor,INPUT);// setting eyeblink pin as INPUT
  Serial.begin(9600); 
   Serial.begin(9600);
pinMode(BUZZER, OUTPUT);
pinMode(GAS_SENSOR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
detectionState = digitalRead(sensor); // saving the eye blink state to detection variable

    if (detectionState == HIGH) // check the detection variable is HIGH
    {
        Serial.println("Eye is closed"); // if true, print the following message on serial monitor
        if(sensor > SENSORTHRESHOLD){
       tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(500);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(500);        // ...for 1sec
    }
   Serial.println(sensor);
         
    }

    else {

        Serial.println("Eye is open"); // if false, print the following message on serial monitor

    }

    delay(50); // providing a delay of 50ms between each loop
    int SENSOR = analogRead(GAS_SENSOR);
  
  if(SENSOR-50 > SENSORTHRESHOLD){
tone(BUZZER, 1000); // Send 1KHz sound signal...
  delay(500);        // ...for 1 sec
  noTone(BUZZER);     // Stop sound...
  delay(500);        // ...for 1sec
    }
   Serial.println(SENSOR-50);
}