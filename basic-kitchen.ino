///////////////////////////////
// Make A Kitchen Do A Thing //
//        Test Sketch        //
//                           //
// This should just turn on  //
// outputs to match inputs.  //
// Totally untested.         //
///////////////////////////////

const int dIns[] = {12,13,14,15};
const int aIns[] = {A2,A3,A4,A5};
const int dOuts[] = {8,7,9,6};
const int aOuts[] = {10,5,11,3};
const int inputDebounce = 50;

int dInStat[] = {HIGH,HIGH,HIGH,HIGH};
unsigned long dInTimer[] = {0,0,0,0};
int aInStat[] = {0,0,0,0};
unsigned long aInTimer[] = {0,0,0,0};

void setup(){
  analogReference(EXTERNAL);
  unsigned long now = millis();
  for (int i=0; i<4; i++){
    pinMode(dIns[i], INPUT);
    pinMode(aIns[i], INPUT);
    pinMode(dOuts[i], OUTPUT);
    pinMode(aOuts[i], OUTPUT);
    aInTimer[i] = now;
    dInTimer[i] = now;
  }
}

void checkInputs(){
  for (int i=0; i<4; i++){
    if (millis() > dInTimer[i] + inputDebounce ){
      dInStat[i] = digitalRead(dIns[i]);
    }
    if (millis() > aInTimer[i] + inputDebounce ){
      aInStat[i] = analogRead(aIns[i]);
    }
  }
}

void setOutputs(){
  for (int i=0; i<4; i++){
    digitalWrite(dOuts[i], !dInStat[i]);
    analogWrite(aOuts[i], aInStat[i]);
  }
}

void loop(){
  checkInputs();
  setOutputs();
}