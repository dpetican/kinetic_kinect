#define a0  13  //white
#define a1  12  //yellow
#define a2  11  //black
#define a3  10  //green
#define a4  9   //white
#define a5  8   //yellow
#define a6  7   //black
#define a7  6   //green
#define a8  5   //white
#define a9  4   //yellow
#define a10  a4  //black
#define a11  a5  //green

#define en0  A0   //red E1
#define en1  A1   //red E1
#define en2  A2   //red E1
#define blank A3  //blue E2

#define extint 2

//const unsigned int pwmTime[4][2] = {{2000,3000},{3000,4000},{4000,5000},{5000,6000}};
const unsigned int pwmTime[48][2] =
{{3000,2000},{3000,2000},{3000,2000},{3000,2000},
 {3000,2000},{3000,2000},{3000,2000},{3000,2000},
 {3000,2000},{3000,2000},{3000,2000},{3000,2000},
 {3000,2000},{3000,2000},{3000,2000},{3000,2000},
 {1,1},{1,1},{1,1},{1,1},
 {1,1},{1,1},{1,1},{1,1},
 {1,1},{1,1},{1,1},{1,1},
 {1,1},{1,1},{1,1},{1,1},
 {1,1},{1,1},{1,1},{1,1},
 {1,1},{1,1},{1,1},{1,1},
 {1,1},{1,1},{1,1},{1,1},
 {1,1},{1,1},{1,1},{1,1}};
  
byte i = 0, j;

void setup() {
  // put your setup code here, to run once:
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  pinMode(a5, OUTPUT);
  pinMode(a6, OUTPUT);
  pinMode(a7, OUTPUT);
  pinMode(a8, OUTPUT);
  pinMode(a9, OUTPUT);
  pinMode(a10, OUTPUT);
  pinMode(a11, OUTPUT);
  pinMode(en0, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(blank, OUTPUT);
  digitalWrite(blank,1);//OFF

  //pinMode(extint, INPUT);
  //attachInterrupt(0, pulseIR, FALLING);
  Serial.begin(9600);
}

void loop(){
  // put your main code here, to run repeatedly:
  Serial.println(i);
  if (i < 16) {
    j = i;
    digitalWrite(en0, 0);
    digitalWrite(en1, 1);
    digitalWrite(en2, 1);
    digitalWrite(a0,(j & B00000001));
    digitalWrite(a1,((j & B00000010)>>1));
    digitalWrite(a2,((j & B00000100)>>2));
    digitalWrite(a3,((j & B00001000)>>3));
  }
  else if (i < 32) {
    j = i - 16;
    digitalWrite(en0, 1);
    digitalWrite(en1, 0);
    digitalWrite(en2, 1);
    digitalWrite(a4,(j & B00000001));
    digitalWrite(a5,((j & B00000010)>>1));
    digitalWrite(a6,((j & B00000100)>>2));
    digitalWrite(a7,((j & B00001000)>>3));
  }
  else {// j < 48
    j = i - 32;
    digitalWrite(en0, 1);
    digitalWrite(en1, 1);
    digitalWrite(en2, 0);
    digitalWrite(a8,(j & B00000001));
    digitalWrite(a9,((j & B00000010)>>1));
    digitalWrite(a10,((j & B00000100)>>2));
    digitalWrite(a11,((j & B00001000)>>3));
  }

  digitalWrite(blank, 0); //ON
  delay(pwmTime[i][0]);
  digitalWrite(blank, 1); //OFF
  delay(pwmTime[i][1]);
  
  if (++i == 16) i = 0;
}

//void pulseIR() {}
