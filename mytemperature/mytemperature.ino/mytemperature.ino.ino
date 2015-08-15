int mysenser = A0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(mysenser, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int res = analogRead(mysenser);
  Serial.println(res);
  delay(1000);
}
