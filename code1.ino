// Constants
const int coinpin = 2;
const int ledpin = 13;

// Variables
volatile int pulse = 0;

boolean bInserted = false;

// Setup
void setup() {
 
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(coinpin), coinInterrupt, RISING);
  pinMode(ledpin, OUTPUT);
 
}

// Main loop
void loop() {
 
 
  if( bInserted  ){ // for show LED ON when Inserted
     bInserted = false;
     digitalWrite(ledpin, HIGH);    
     delay(1000);
  }else{
   
  // Turn off LED
  digitalWrite(ledpin, LOW);
  } 
}

// Interrupt
void coinInterrupt(){
 
  // Each time a pulse is sent from the coin acceptor,
  // interrupt main loop to add 1  and flip on the LED
  pulse++ ;
  bInserted = true;

 // digitalWrite(ledpin, HIGH);
 // Serial.println( pulse );
   
}
