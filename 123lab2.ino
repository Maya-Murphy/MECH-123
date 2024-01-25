 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0, INPUT); 
pinMode(2, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
attachInterrupt(digitalPinToInterrupt(2), measure, FALLING); 
}

void measure(){
  volatile float IRRead = analogRead(A0);
  IRRead = IRRead *((float)5/(float)1024);
  float distance = 0; 
  if(IRRead < 2.560 && IRRead >= 2.390){
    //pwl model 1 distance = (upperbound - input)/slope
    distance = (IRRead-(float)2.560)/((float)-0.034); 
    Serial.print(distance); 
    Serial.println(" cm");
  }
  else if(IRRead < 2.390 && IRRead >= 1.610){
    //pwl model 2
    distance = (IRRead-(float)2.390)/((float)-0.156);
    Serial.print(distance);
    Serial.println(" cm");
    
  }
  else if(IRRead < 1.610 && IRRead >= 1.290){
    //pwl model 3
    distance = (IRRead-(float)1.610)/((float)-0.064);
    Serial.print(distance); 
    Serial.println(" cm");
  }
  else if(IRRead < 1.290 && IRRead >= 1.046){
    //pwl model 4
    distance = (IRRead-(float)1.290)/((float)-0.0488);
    Serial.print(distance); 
    Serial.println(" cm");
  }
  else if(IRRead < 1.046 && IRRead >= .910){
    //pwl model 5
    distance = (IRRead-(float)1.046)/((float)-0.0272);
    Serial.print(distance); 
    Serial.println(" cm");
  }
  else if(IRRead < .910 && IRRead >= .750){
    //pwl model 6
    distance = (IRRead-(float).910)/((float)-0.032);
    Serial.print(distance); 
    Serial.println(" cm");
  }
  else if(IRRead < .750 && IRRead >= .690){
    //pwl model 7
    distance = (IRRead-(float).750)/((float)-0.012);
    Serial.print(distance); 
    Serial.println(" cm");
  }

}