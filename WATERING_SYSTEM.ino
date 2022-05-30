int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int wilting_point ;  //minimum water moisture content required for the plants to survive .if the moisture content is than this point then water wont be useful for the plants. 
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
     Serial.begin(9600); //the rate at which tthe data is transfered  to aurdino
   Serial.println("Reading From the Sensor ..."); //prints the function 
   delay(2000);  //2000 ms delay in printing the value
}


  // put your main code here, to run repeatedly:

  void loop() {
   wilting_point= analogRead(sensor_pin); //reads the moisture value from the pin ao
   wilting_point = map(wilting_point,550,10,0,100);  //map the value of sensor from one range to another and gives moisture value
   Serial.print("Mositure : "); //prints 
   Serial.print(wilting_point); //prints value of the moisture
   Serial.println("%");
   if(wilting_point<8){   //from PROCTOR CURVE  the wilting point is determiined as 8%
      digitalWrite(9,HIGH);
     }
     else{
            digitalWrite(9,LOW);
     }
   delay(1000);
}
