int trig = 2; 
int echo = 3; 
float pre_distance = 0; 

float get_distance()
{
  digitalWrite(trig, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trig, LOW);  

  unsigned long duration = pulseIn(echo, HIGH);  
  float distance = duration / 29.0 / 2.0;  

  return distance; 
}

void setup()
{
  Serial.begin(9600); 

  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT); 
  
  pre_distance = get_distance(); 
}

void loop() 
{
  float now_distance;
  float filtered_distance;
  
  for(int i=0;i<10;i++)
  {
    now_distance = get_distance(); 
    filtered_distance = (now_distance * 0.3) + (pre_distance * 0.7);
    pre_distance = filtered_distance;
  }
  
  Serial.println(filtered_distance);

} 
