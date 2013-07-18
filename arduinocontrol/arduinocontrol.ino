/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int moto1_1 = 2;
int moto1_2 = 3;
int moto2_1 = 4;
int moto2_2 = 5;
int moto1_en = 6;
int moto2_en = 9;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);  
  // initialize the digital pin as an output.
  pinMode(moto1_1, OUTPUT);     
  pinMode(moto1_2, OUTPUT);     
  pinMode(moto2_1, OUTPUT);     
  pinMode(moto2_2, OUTPUT);    
  pinMode(moto1_en, OUTPUT);     
  pinMode(moto2_en, OUTPUT);  
  establishContact();  // send a byte to establish contact until receiver responds 
}

// the loop routine runs over and over again forever:
void loop() {
   
   while (Serial.available() > 0) {
       // look for the next valid integer in the incoming serial stream:
      char cmd = Serial.read(); 
      // do it again:
      int param = Serial.parseInt(); 
     // look for the newline. That's the end of your  sentence:
      if (Serial.read() == '#') {
         
         param = param*255/10;

          if(cmd == 'F') {
            goFront(param);
          } 
          if(cmd == 'B') {
            goBack(param);
          }    
          if(cmd == 'L') {
            goLeft(param);
          }    
          if(cmd == 'R') {
            goRight(param);
          }
          if(cmd == 'S') {
            goStop();
          }
    
      }
      //echo rx values:
      Serial.print("-->");
      Serial.print(cmd);
      Serial.println(param,HEX);
      
   }
 
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("IC Welcome U!");   // send an initial string
    delay(300);
  }
}

//sp mean speed
void goFront(int sp){
  digitalWrite(moto1_1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(moto1_2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(moto2_1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(moto2_2, LOW);   // turn the LED on (HIGH is the voltage level)
  analogWrite(moto1_en, sp);   //
  analogWrite(moto2_en, sp);   //
}

void goBack(int sp){
  digitalWrite(moto1_1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(moto1_2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(moto2_1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(moto2_2, HIGH);    // turn the LED off by making the voltage LOW
  analogWrite(moto1_en, sp);   //
  analogWrite(moto2_en, sp);   //
}

void goLeft(int sp){
  digitalWrite(moto1_1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(moto1_2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(moto2_1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(moto2_2, LOW);   // turn the LED on (HIGH is the voltage level)
  analogWrite(moto1_en, sp);   //
  analogWrite(moto2_en, sp);   //
}

void goRight(int sp){
  digitalWrite(moto1_1, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(moto1_2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(moto2_1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(moto2_2, HIGH);   // turn the LED on (HIGH is the voltage level)
  analogWrite(moto1_en, sp);   //
  analogWrite(moto2_en, sp);   //
}

void goStop(){
  digitalWrite(moto1_1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(moto1_2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(moto2_1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(moto2_2, LOW);   // turn the LED on (HIGH is the voltage level)
}
