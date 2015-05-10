//const unsigned int pwmTime[4][2] = {{2000,3000},{3000,4000},{4000,5000},{5000,6000}};
const unsigned int pwmTime[4][2] = {{1,1},{1,1},{1,1},{1,1}};


byte i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9,1);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Serial.println(i);
  digitalWrite(7,(i & B00000001));
  digitalWrite(8,((i & B00000010)>>1));
  digitalWrite(9, 0); //ON
  delay(pwmTime[i][0]);
  digitalWrite(9, 1); //OFF
  delay(pwmTime[i][1]);
  if (++i == 4) i = 0;
}
