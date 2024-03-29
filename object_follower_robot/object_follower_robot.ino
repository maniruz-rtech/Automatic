instructions

1. user name :pi
2. Pass : mektek123
.
1. If Camera light off
-> sudo service motion restart

2. sever failed
-> node-red(continue)

3. parts list
1. raspberry pi 3
2. arduino uno
3. camera
4. sonar sensor
5. li-po battery (1800 mah)
6. motor driver(L298)
7. Buck- Boots converter
8. Geared Motor (12V, 300 rpm)

Start :-
server ip:1880/ui
camer ip:8081


Server json :-
[{"id":"1c7a595f.72c017","type":"ui_template","z":"635dff9e.45137","group":"cc7995d8.b64e78","name":"template","order":1,"width":"6","height":"11","format":"\n    <p>streaming</p>\n    <iframe src=\"http://192.168.0.101:8081/\" height = \"480\" width = \"640\"></iframe>\n","storeOutMessages":true,"fwdInMessages":true,"templateScope":"local","x":860,"y":200,"wires":[[]]},{"id":"cc7995d8.b64e78","type":"ui_group","z":"","name":"Up-Down","tab":"c6d0c4d2.e8d208","order":2,"disp":true,"width":"6"},{"id":"c6d0c4d2.e8d208","type":"ui_tab","z":"","name":"key","icon":"dashboard"}]
                                                            e(trigr,echor);
  int l = distance(trigl,echol);


  int d = minDistance(f,r,l);

    Serial.println(d);

  if (d<70){

    if(d==f){
      if (d<20){
        back(d);
      }
  
      else if (d>23){
        forward(d*4);
      }
  
      else{
        stp();
      }
    }
  
    else if(d==r){
      right();
    }
  
    else if(d==l){
      left();
    }

  }

  else{
    stp();
  }

}





int distance(int trig, int echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo,HIGH);



  int dis = .0340*duration/2;
  return dis;
  
}

int minDistance(int a, int b, int c){
  if (a<b && a<c){
    return a;
  }

  if (b<a && b<c){
    return b;
  }

  else{
    return c;
  }
}

void back(int spd){
    spd = 20-spd;
  spd *= 10;
  if (spd < 66){ spd = 66;}
  analogWrite(rmotor, spd);
  digitalWrite(rmotor1, HIGH);
  digitalWrite(rmotor2, LOW);
  analogWrite(lmotor, spd);
  digitalWrite(lmotor1, HIGH);
  digitalWrite(lmotor2, LOW);
  
}

void forward(int spd){

  analogWrite(rmotor, spd);
  digitalWrite(rmotor1, LOW);
  digitalWrite(rmotor2, HIGH);
  analogWrite(lmotor, spd);
  digitalWrite(lmotor1, LOW);
  digitalWrite(lmotor2, HIGH);
  
  
}

void left(){
  analogWrite(rmotor, 120);
  digitalWrite(rmotor1, HIGH);
  digitalWrite(rmotor2, LOW);
  analogWrite(lmotor, 120);
  digitalWrite(lmotor1, LOW);
  digitalWrite(lmotor2, HIGH);
  
}

void right(){
  analogWrite(rmotor, 120);
  digitalWrite(rmotor1, LOW);
  digitalWrite(rmotor2, HIGH);
  analogWrite(lmotor, 120);
  digitalWrite(lmotor1, HIGH);
  digitalWrite(lmotor2, LOW);
  
}

void stp(){
  analogWrite(rmotor, 0);
  digitalWrite(rmotor1, LOW);
  digitalWrite(rmotor2, LOW);
  analogWrite(lmotor, 0);
  digitalWrite(lmotor1, LOW);
  digitalWrite(lmotor2, LOW);
  
  
}


