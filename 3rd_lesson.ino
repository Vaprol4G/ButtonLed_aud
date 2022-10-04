#define btn_pin 3
#define check_time 100
#define led_pin 11
#define sensor_pin A0


long timer = 0;
int counter = 0;
int prev = 0;
bool on_off = false;

void setup()
{
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = !digitalRead(btn_pin);
  
  if (value != prev)
  {
    timer = millis();
  }
  prev = value;
  
  if (value && millis() - timer > check_time)
  {
    
    Serial.println("Button pressed !");
    timer = millis();
    on_off = !on_off;
    delay(200);
    
  }
  if (on_off)
  {
    digitalWrite(led_pin, HIGH);
    
  }else
  {
    digitalWrite(led_pin, LOW);
  }
}