



void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  analogWriteResolution(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(A0,0);
  digitalWrite(A0,1);
}
