#define trigf 4
#define echof 5
#define trigr 6
#define echor 7
#define trigl 3
#define echol 2

#define rmotor1 8
#define rmotor2 9

#define lmotor1 10
#define lmotor2 11
#define pwmr 12
#define pwml 13

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, INPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT_PULLUP);



  Serial.begin(9600);


}
void loop() {
 

  int re = digitalRead(A0);


  if (re == 1) {
    manual();

  }

  if (re == 0) {
    autom();
  }

}


void manual() {
  if (Serial.available()) {
    char m = Serial.read();

    if (m == 'U') {
      forward(pwmr);
      delay(100);
      botastp(pwmr);

    }
    if (m == 'D') {
      back(0);
      delay(100);
      botastp(pwmr);

    }

    if (m == 'R') {
      right(pwmr);
      delay(30);
      botastp(pwmr);

    }

    if (m == 'L') {
      left(pwmr);
      delay(30);
      botastp(pwmr);

    }

    if (m == 'S') {
      botastp(pwmr);

    }

  }


}



void autom() {
  int f = distance(trigf, echof);
  int r = distance(trigr, echor);
  int l = distance(trigl, echol);


  int d = minDistance(f, r, l);
 Serial.println( d );

  if (d<70){

    if(d==f){
      if (d>0 && d<20){
        back(d);
      }
      if(d>=21 && d<=29){
        stp();
      }
  
      if (d>30 && d<70){
        forward(d*4);
      }
  
     
    }
  
    else if(d==r){
        if (d>0 && d<17){
        left(d);
      }
      if(d>=18 && d<=29){
        stp();
      }
  
      if (d>30 && d<70){
        right(d);
      }
      
    }
  
    else if(d==l){
        if (d>0 && d<17){
        right(d);
      }
      if(d>=18 && d<=29){
        stp();
      }
  
      if (d>30 && d<70){
        left(d);
      }
      
     
    }

  }

  else{
    stp();
}
}

int distance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long dura = pulseIn(echo, HIGH);

  long duration= dura/29;
  int dis = 0.340 * duration / 2;
 return dis;

}
int minDistance(int a, int b, int c) {
  if (a < b && a < c) {
    return a;
  }

  if (b < a && b < c) {
    return b;
  }

  else {
    return c;
  }
}
void back(int j) {
  digitalWrite(rmotor1, HIGH);
  digitalWrite(rmotor2, LOW);
  digitalWrite(lmotor1, HIGH);
  digitalWrite(lmotor2, LOW);
  for (j = j; j <= 255; j++) {
    analogWrite(pwmr, j);
    analogWrite(pwml, j);
  }
}

void forward(int j) {

  digitalWrite(rmotor1, LOW);
  digitalWrite(rmotor2, HIGH);
  digitalWrite(lmotor1, LOW);
  digitalWrite(lmotor2, HIGH);
  for (j = j; j <= 255; j++) {
    analogWrite(pwmr, j);
    analogWrite(pwml, j);
  }
}

void left(int j) {
  digitalWrite(rmotor1, HIGH);
  digitalWrite(rmotor2, LOW);
  digitalWrite(lmotor1, LOW);
  digitalWrite(lmotor2, HIGH);
  for (j = j; j <= 255; j++) {
    analogWrite(pwmr, j);
    analogWrite(pwml, j);

  }
}
void right(int j) {
  digitalWrite(rmotor1, LOW);
  digitalWrite(rmotor2, HIGH);
  digitalWrite(lmotor1, HIGH);
  digitalWrite(lmotor2, LOW);
  for (j = j; j <= 255; j++) {
    analogWrite(pwmr, j);
    analogWrite(pwml, j);

  }
}




void botastp(int i) {
  digitalWrite(rmotor1, LOW);
  digitalWrite(rmotor2, LOW);
  digitalWrite(lmotor1, LOW);
  digitalWrite(lmotor2, LOW);

  for (int i = i; i >= 0; --i)
  {
    analogWrite(pwmr, i);
    analogWrite(pwml, i);
  }
  loop();
}
void stp() {
  analogWrite(pwmr, 0);
  digitalWrite(rmotor1, LOW);
  digitalWrite(rmotor2, LOW);
  analogWrite(pwml, 0);
  digitalWrite(lmotor1, LOW);
  digitalWrite(lmotor2, LOW);


}