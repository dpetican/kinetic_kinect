#define a0  13  //white
#define a1  12  //yellow
#define a2  11  //black
#define a3  10  //green
#define led17  9   //yellow
#define led18  8   //yellow
#define led19  7   //yellow
#define led20  6   //yellow
const int extraLeds[4] = {9, 8, 7, 6};

#define en0  A0   //red E1
#define blank A3  //blue E2

#define extint 2

const unsigned int pwmTime[20][2] =
{ {3500, 3500}, {3500, 3500}, {3500, 3500}, {3500, 3500},
  {3500, 3500}, {3500, 3500}, {3500, 3500}, {3500, 3500},
  {3500, 3500}, {3500, 3500}, {3500, 3500}, {3500, 3500},
  {3500, 3500}, {3500, 3500}, {3500, 3500}, {3500, 3500},
  {3500, 3500}, {3500, 3500}, {3500, 3500}, {3500, 3500}
};

byte i = 0, j;

void setup() {
  // put your setup code here, to run once:
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(led17, OUTPUT);
  pinMode(led18, OUTPUT);
  pinMode(led19, OUTPUT);
  pinMode(led20, OUTPUT);
  pinMode(blank, OUTPUT);
  pinMode(en0, OUTPUT);
  digitalWrite(blank, 1); //OFF
  digitalWrite(en0, 0);// always enable for now
  digitalWrite(led17, 1);//OFF
  digitalWrite(led18, 1);//OFF
  digitalWrite(led19, 1);//OFF
  digitalWrite(led20, 1);//OFF

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
  if (i < 16) {
    digitalWrite(a0, (i & B00000001));
    digitalWrite(a1, ((i & B00000010) >> 1));
    digitalWrite(a2, ((i & B00000100) >> 2));
    digitalWrite(a3, ((i & B00001000) >> 3));
    digitalWrite(blank, 0); //ON
    delay(pwmTime[i][0]);
    digitalWrite(blank, 1); //OFF
    delay(pwmTime[i][1]);
  }
  else { // i is between 16 and 20
    j = i - 16;
    digitalWrite(extraLeds[j], 0); //ON
    delay(pwmTime[i][0]);
    digitalWrite(extraLeds[j], 1); //OFF
    delay(pwmTime[i][1]);
  }
  
  if (++i == 20) i = 0; // increment i and check for rollover
}

