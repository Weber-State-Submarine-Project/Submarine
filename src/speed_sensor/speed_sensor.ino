// Timer
unsigned long mytime;
unsigned long lasttime;
unsigned long diff;

int val;
int oldval;

float speed;

// the setup() method runs once, when the sketch starts

void setup() {

Serial.begin(9600);
  
  // initialize the digital pin as an output.
  pinMode(10, INPUT);

  lasttime = 0;
}

// the loop() methor runs over and over again,
// as long as the board has power


void loop() {

  // Read the speedometer
  // The speedometer signal oscillates between 0 and 1023 (when at 5v)
  // The speedometer signal oscillates between 0 and 659 (when at 3.3v)
  // So the signal is either 0 or a positive number.
  // Want to detect then the signal falls to zero or rises from zero
  // The speed of the oscillation is the rotation of the wheel
  
  val = analogRead(0);
  //Serial.println(val);
  
  // The paddle wheel has turned. 
  if ((val <= 2 && oldval>2) || (oldval <= 2 && val>2)) {
    // Find change in milliseconds since last
    mytime = millis();
    diff = mytime - lasttime;
    lasttime = mytime;

    // The wheel has moved 2 cm between the change 0 and 1.
    // Numbers are approximate
    // Diameter of wheel = 2 * 3.142 * 0.02 (2.pi.r)
    // 12.5cm / 6 paddles = 2 cm per paddle
    
    //Serial.print(diff);
    //Serial.print("ms,\t");

    speed = (float)20/diff;
    Serial.println(speed);
    //Serial.println("m/s");
  } 

  // Update the oldval
  oldval = val;
  
}