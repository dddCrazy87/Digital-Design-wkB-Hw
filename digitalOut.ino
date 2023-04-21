void setup() {               
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, 1);
  pinMode(13, INPUT_PULLUP);
  Serial.begin(9600);
}

byte segs[10][7] = { { 0,0,0,0,0,0,1 },
                     { 1,0,0,1,1,1,1 },
                     { 0,0,1,0,0,1,0 },
                     { 0,0,0,0,1,1,0 },
                     { 1,0,0,1,1,0,0 },
                     { 0,1,0,0,1,0,0 },
                     { 0,1,0,0,0,0,0 },
                     { 0,0,0,1,1,1,1 },
                     { 0,0,0,0,0,0,0 },
                     { 0,0,0,1,1,0,0 }
};

void show(byte n) {
  
  for (byte seg = 0, pin = 2; seg < 7; seg++, pin++) {
    digitalWrite(pin, segs[n][seg]);
  }
}

byte cnt = 0, nowState = 0;

void loop() {

  
  byte preState = nowState;
  nowState = digitalRead(13);

  if(preState == nowState) return;
  
  if(nowState == 0){
     cnt ++;
     if(cnt > 9) cnt = 0;
     show(cnt);
     Serial.println(cnt);
  }
}
