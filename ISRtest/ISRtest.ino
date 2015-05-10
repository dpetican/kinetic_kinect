void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);     // Pin 13 is output to which an LED is connected
  digitalWrite(13, LOW);   // Make pin 13 low, switch LED off
  pinMode(2, INPUT);	   // Pin 2 is input to which a switch is connected = INT0
  pinMode(3, INPUT);	   // Pin 3 is input to which a switch is connected = INT1
  attachInterrupt(0, blink1, FALLING);
  attachInterrupt(1, blink2, FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void blink1(){              // Interrupt service routine
  digitalWrite(13, HIGH);
  Serial.println("ISR0");
}

void blink2(){              // Interrupt service routine
  digitalWrite(13, LOW);
  Serial.println("ISR1");
}
