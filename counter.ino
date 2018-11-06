//  |7|6|9|10| 5|4|2|1
//  |A|B|F| G|dp|C|D|E
int numbers[] = {
  B11100111, 
  B01000100,
  B11010011,
  B11010110,
  B01110100,
  B10110110,
  B10110111,
  B11000100,
  B11110111,
  B11110110
};
int counter = 0;
boolean button_state = 0;
unsigned long last_press;



void setup() {
  for(int i = 2; i < 12; i++){
    if(i == 10) continue;
    pinMode(i, OUTPUT);
  }
  digitalWrite(11, HIGH);
}

void loop() {
  
  int num = numbers[counter];
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, num % 2);
    num = num >> 1;
  }
  boolean current_state = digitalRead(12);
  if ( current_state && !button_state && millis() - last_press > 50){
    button_state = 1;
    counter++;
    last_press = millis();
  }
  else if(!current_state && button_state) {
     button_state = 0;
  }
  if (counter > 9) counter = 0;
}
