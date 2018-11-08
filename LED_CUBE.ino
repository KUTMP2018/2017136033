             *                                               #include <LedCube.h>                                                                              // 헤더 추가

#define SIZE 5                                                                                    // 큐브 사이즈
#define COLS (SIZE*SIZE)                                                                          // 가로 숫자

byte levelPins[SIZE] = {47,48,49,50,51};                                                          // 층 조절
byte colPins[COLS] = {46,41,36,31,26,45,40,35,30,25,44,39,12,29,24,43,38,33,28,23,42,37,32,27,22};// 각 층 led 조절

LedCube cube(SIZE, levelPins, colPins);              // Make instance of the imported library

void setup ()
{
  delay(10000);
}

void loop ()
{  
    //randomCube(310);               // 무작위 led 켜고 끄기
    Tornado();                     // led 하나씩 켜서 토네이도 만들기
    Levels();                      // led 하나씩 켜기
    crossing();                    // led 교차
    Segments();                    // led 열 또는 세그먼트 조작
    cube.randomColumn(25,20);      // 랜덤 열 선택
    heart(3);                      // 전부 켜졌다 꺼졋다
    SpeedUpFan(1);                 // 회전 
    Pyramid();                     // 피라미드
    WavesUpDown();                 // 위아래 이동 파동
    Waves(3);                      // 왼쪽에서 오른족 이동하는 파동
    CubeFlick(3);                  // 모든 led 깜박깜박
    GoNBack();                     // 왼쪽에서 오른쪽
    OneSpeedFan(3,5);              
    randomCube(20);
    ReversedFan(3,5);
    LightDrops(5,50);              // Display a rain drops
    Tornado();
    GoNBack();
    LightDrops(30,55);
    GoNBack();
}
void Levels()
{
//-------------------------------------------------------------- LEVELS FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs one by one moving from the first level to the last one then 
//turn off the whole CUBE and start lighting on the LEDs strating from the last level
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** We start by lighting ON the LEDs **********************
  for(int i=0;i<25;i++)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,HIGH); // "light" function is similar to "digitalWrite" API but it takes three arguments which are the level,the column and the state(HIGH or LOW)
      delay(8);
    }
  }
//***************** We turn OFF all the LEDs *******************************
  for(int i=0;i<25;i++)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,LOW);
    }
  }
//***************** We turn ON again the LEDs *****************************
    for(int i=24;i>=0;i--)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,HIGH);
      delay(8);
    }
  }
}
//---------------------------------------------------------------- END OF LEVELS FUNCTION ----------------------------------------------------------
void Segments()
{
//-------------------------------------------------------------- SEGMENTS FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in lines or segments starting from the first and the last lines 
//then reverse the lighting trend
//The lines will be formed as sequence then transfered to the CUBE
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** We start by preparing the sequences **********************
  byte ccc [] = {0,20, 0,4, };
  byte d [] = {0,20, 1,20, 0,4, 1,4, };
  byte e [] = {0,20, 1,20, 2,20, 0,4, 1,4, 2,4, }; 
  byte f [] = {0,20, 1,20, 2,20, 3,20, 0,4, 1,4, 2,4, 3,4, }; 
  byte g [] = {0,20, 1,20, 2,20, 3,20, 4,20, 0,4, 1,4, 2,4, 3,4, 4,4, };
  byte h [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, };
  byte ii [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, };
  byte jj [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, };
  byte kk [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, };
  byte ll [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, };
  byte mm [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, };
  byte nn [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, };
  byte oo [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, };
  byte pp [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, };
  byte qq [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, };
  byte rr [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, };
  byte s [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, };
  byte t [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 2,23, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, 2,1, };
  byte u [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 2,23, 1,23, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, 2,1, 1,1, };
  byte v [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 2,23, 1,23, 0,23, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, 2,1, 1,1, 0,1, };
  byte w [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 2,23, 1,23, 0,23, 0,24, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, 2,1, 1,1, 0,1, 0,0, };
  byte x [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 2,23, 1,23, 0,23, 0,24, 1,24, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, 2,1, 1,1, 0,1, 0,0, 1,0, };
  byte y [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 2,23, 1,23, 0,23, 0,24, 1,24, 2,24, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, 2,1, 1,1, 0,1, 0,0, 1,0, 2,0, };
  byte z [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 2,23, 1,23, 0,23, 0,24, 1,24, 2,24, 3,24, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, 2,1, 1,1, 0,1, 0,0, 1,0, 2,0, 3,0, };
  byte aa [] = {0,20, 1,20, 2,20, 3,20, 4,20, 4,21, 3,21, 2,21, 1,21, 0,21, 0,22, 1,22, 2,22, 3,22, 4,22, 4,23, 3,23, 2,23, 1,23, 0,23, 0,24, 1,24, 2,24, 3,24, 4,24, 0,4, 1,4, 2,4, 3,4, 4,4, 4,3, 3,3, 2,3, 1,3, 0,3, 0,2, 1,2, 2,2, 3,2, 4,2, 4,1, 3,1, 2,1, 1,1, 0,1, 0,0, 1,0, 2,0, 3,0, 4,0, };

//****************** And now we transfer the sequenses to our CUBE **********************
  cube.lightSequence(ccc, sizeof(ccc), 3);//The lightSequence function allows us to transfer the sequences to our CUBE, this function takes three arguments which are the sequences of bytes, the size of the sequence and the delay between each byte to send
  cube.lightSequence(d, sizeof(d), 3);
  cube.lightSequence(e, sizeof(e), 3);
  cube.lightSequence(f, sizeof(f), 3);
  cube.lightSequence(g, sizeof(g), 3);
  cube.lightSequence(h, sizeof(h), 3);
  cube.lightSequence(ii, sizeof(ii), 3);
  cube.lightSequence(jj, sizeof(jj), 3);
  cube.lightSequence(kk, sizeof(kk), 3);
  cube.lightSequence(ll, sizeof(ll), 3);
  cube.lightSequence(mm, sizeof(mm), 3);
  cube.lightSequence(nn, sizeof(nn), 3);
  cube.lightSequence(oo, sizeof(oo), 3);
  cube.lightSequence(pp, sizeof(pp), 3);
  cube.lightSequence(qq, sizeof(qq), 3);
  cube.lightSequence(rr, sizeof(rr), 3);
  cube.lightSequence(s, sizeof(s), 3);
  cube.lightSequence(t, sizeof(t), 3);
  cube.lightSequence(u, sizeof(u), 3);
  cube.lightSequence(v, sizeof(v), 3);
  cube.lightSequence(w, sizeof(w), 3);
  cube.lightSequence(x, sizeof(x), 3);
  cube.lightSequence(y, sizeof(y), 3);
  cube.lightSequence(z, sizeof(z), 3);
  cube.lightSequence(aa, sizeof(aa), 3);
  cube.lightSequence(z, sizeof(z), 3);
  cube.lightSequence(y, sizeof(y), 3);
  cube.lightSequence(x, sizeof(x), 3);
  cube.lightSequence(w, sizeof(w), 3);
  cube.lightSequence(v, sizeof(v), 3);
  cube.lightSequence(u, sizeof(u), 3);
  cube.lightSequence(t, sizeof(t), 3);
  cube.lightSequence(s, sizeof(s), 3);
  cube.lightSequence(rr, sizeof(rr), 3);
  cube.lightSequence(qq, sizeof(qq), 3);
  cube.lightSequence(pp, sizeof(pp), 3);
  cube.lightSequence(oo, sizeof(oo), 3);
  cube.lightSequence(nn, sizeof(nn), 3);
  cube.lightSequence(mm, sizeof(mm), 3);
  cube.lightSequence(ll, sizeof(ll), 3);
  cube.lightSequence(kk, sizeof(kk), 3);
  cube.lightSequence(jj, sizeof(jj), 3);
  cube.lightSequence(ii, sizeof(ii), 3);
  cube.lightSequence(h, sizeof(h), 3);
  cube.lightSequence(g, sizeof(g), 3);
  cube.lightSequence(f, sizeof(f), 3);
  cube.lightSequence(e, sizeof(e), 3);
  cube.lightSequence(d, sizeof(d), 3);
  cube.lightSequence(ccc, sizeof(ccc), 3);
}
//---------------------------------------------------------------- END OF SEGMENTS FUNCTION ----------------------------------------------------------

void SpeedUpFan(int executeTimes)
{
//--------------------------------------------------------------SPEED UP FAN FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form of fan that speed up from each itiration 
//This function takes one argument which is the execution times to identify how many times you want to execute this function
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  byte aa2 [] = {0,10, 1,10, 2,10, 3,10, 4,10, 4,11, 3,11, 2,11, 1,11, 0,11, 0,12, 1,12, 2,12, 3,12, 4,12, 4,13, 3,13, 2,13, 1,13, 0,13, 0,14, 1,14, 2,14, 3,14, 4,14,};
  byte aa3 [] = {0,0, 1,0, 2,0, 3,0, 4,0, 4,6, 3,6, 2,6, 1,6, 0,6, 0,12, 1,12, 2,12, 3,12, 4,12, 4,18, 3,18, 2,18, 1,18, 0,18, 1,24, 2,24, 3,24, 4,24,};
  byte aa4 [] = {0,2, 1,2, 2,2, 3,2, 4,2, 4,7, 3,7, 2,7, 1,7, 0,7, 0,12, 1,12, 2,12, 3,12, 4,12, 4,17, 3,17, 2,17, 1,17, 0,17, 1,22, 2,22, 3,22, 4,22,};
  byte aa5 [] = {0,4, 1,4, 2,4, 3,4, 4,4, 4,8, 3,8, 2,8, 1,8, 0,8, 0,12, 1,12, 2,12, 3,12, 4,12, 4,16, 3,16, 2,16, 1,16, 0,16, 1,20, 2,20, 3,20, 4,20,};

//****************** And now we transfer the sequenses to our CUBE **********************
  int counter=0; //I used this counter to count how many times we already executed the function
  while ( counter<executeTimes)
  {
    int i=10;
    for(i=10;i>0;i--)
    {
      cube.lightSequence(aa2, sizeof(aa2), i);
      cube.lightSequence(aa3, sizeof(aa3), i);
      cube.lightSequence(aa4, sizeof(aa4), i);
      cube.lightSequence(aa5, sizeof(aa5), i);
      cube.lightSequence(aa2, sizeof(aa2), i);
      cube.lightSequence(aa3, sizeof(aa3), i);
      cube.lightSequence(aa4, sizeof(aa4), i);
      cube.lightSequence(aa5, sizeof(aa5), i);
    }
    counter+=1;
  }
}
//---------------------------------------------------------------- END OF SPEED UP FAN FUNCTION ----------------------------------------------------------

void OneSpeedFan(int speedFan, int executionTimes)
{
//--------------------------------------------------------------SPEED UP FAN FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form of fan that spin in one speed
//This function takes two arguments which are the execution times to identify how many times you want to execute this function and the speed fan to indicate the spining speed
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  byte aa2 [] = {0,10, 1,10, 2,10, 3,10, 4,10, 4,11, 3,11, 2,11, 1,11, 0,11, 0,12, 1,12, 2,12, 3,12, 4,12, 4,13, 3,13, 2,13, 1,13, 0,13, 0,14, 1,14, 2,14, 3,14, 4,14,};
  byte aa3 [] = {0,0, 1,0, 2,0, 3,0, 4,0, 4,6, 3,6, 2,6, 1,6, 0,6, 0,12, 1,12, 2,12, 3,12, 4,12, 4,18, 3,18, 2,18, 1,18, 0,18, 1,24, 2,24, 3,24, 4,24,};
  byte aa4 [] = {0,2, 1,2, 2,2, 3,2, 4,2, 4,7, 3,7, 2,7, 1,7, 0,7, 0,12, 1,12, 2,12, 3,12, 4,12, 4,17, 3,17, 2,17, 1,17, 0,17, 1,22, 2,22, 3,22, 4,22,};
  byte aa5 [] = {0,4, 1,4, 2,4, 3,4, 4,4, 4,8, 3,8, 2,8, 1,8, 0,8, 0,12, 1,12, 2,12, 3,12, 4,12, 4,16, 3,16, 2,16, 1,16, 0,16, 1,20, 2,20, 3,20, 4,20,};
  int counter=0;
  while(counter<executionTimes)
  {
     cube.lightSequence(aa2, sizeof(aa2), speedFan);
     cube.lightSequence(aa3, sizeof(aa3), speedFan);
     cube.lightSequence(aa4, sizeof(aa4), speedFan);
     cube.lightSequence(aa5, sizeof(aa5), speedFan);
     cube.lightSequence(aa2, sizeof(aa2), speedFan);
     cube.lightSequence(aa3, sizeof(aa3), speedFan);
     cube.lightSequence(aa4, sizeof(aa4), speedFan);
     cube.lightSequence(aa5, sizeof(aa5), speedFan);
     counter+=1;
  }
}
//---------------------------------------------------------------- END OF ONE SPEED FAN FUNCTION ----------------------------------------------------------

void ReversedFan(int speedFan, int executionTimes)
{
//--------------------------------------------------------------REVERSED FAN FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form of fan that spin in one speed
//This function takes two arguments which are the execution times to identify how many times you want to execute this function and the speed fan to indicate the spining speed
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  byte aa2 [] = {0,10, 1,10, 2,10, 3,10, 4,10, 4,11, 3,11, 2,11, 1,11, 0,11, 0,12, 1,12, 2,12, 3,12, 4,12, 4,13, 3,13, 2,13, 1,13, 0,13, 0,14, 1,14, 2,14, 3,14, 4,14,};
  byte aa3 [] = {0,0, 1,0, 2,0, 3,0, 4,0, 4,6, 3,6, 2,6, 1,6, 0,6, 0,12, 1,12, 2,12, 3,12, 4,12, 4,18, 3,18, 2,18, 1,18, 0,18, 1,24, 2,24, 3,24, 4,24,};
  byte aa4 [] = {0,2, 1,2, 2,2, 3,2, 4,2, 4,7, 3,7, 2,7, 1,7, 0,7, 0,12, 1,12, 2,12, 3,12, 4,12, 4,17, 3,17, 2,17, 1,17, 0,17, 1,22, 2,22, 3,22, 4,22,};
  byte aa5 [] = {0,4, 1,4, 2,4, 3,4, 4,4, 4,8, 3,8, 2,8, 1,8, 0,8, 0,12, 1,12, 2,12, 3,12, 4,12, 4,16, 3,16, 2,16, 1,16, 0,16, 1,20, 2,20, 3,20, 4,20,};
  int counter=0;
  while(counter<executionTimes)
  {
      cube.lightSequence(aa5, sizeof(aa5), speedFan);
     cube.lightSequence(aa4, sizeof(aa4), speedFan);
     cube.lightSequence(aa3, sizeof(aa3), speedFan);
     cube.lightSequence(aa2, sizeof(aa2), speedFan);
     cube.lightSequence(aa5, sizeof(aa5), speedFan);
     cube.lightSequence(aa4, sizeof(aa4), speedFan);
     cube.lightSequence(aa3, sizeof(aa3), speedFan);
     cube.lightSequence(aa2, sizeof(aa2), speedFan);
     counter+=1;
  }
}
//---------------------------------------------------------------- END OF REVERSED FAN FUNCTION ----------------------------------------------------------

void Tornado()
{
//--------------------------------------------------------------TORNADO FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form of a tornado
//This function takes no arguments
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  int n=0;
  int c=0;
  int m=0;
  int i=5;
  for(i=5;i>0;i--)
  {
    while (c<4)
    {
       byte cadre [] = {n,m, n,m, n,m, n,m, n,m,};
       cube.lightSequence(cadre, sizeof(cadre), i);
       m+=1;
        c+=1;
     }
   c=0;
   while (c<4)
    {
      byte cadre [] = {n,m, n,m, n,m, n,m, n,m,};
      cube.lightSequence(cadre, sizeof(cadre), i);
      m+=5;
      c+=1;
    }
  c=0;
    while (c<4)
    {
      byte cadre [] = {n,m, n,m, n,m, n,m, n,m,};
      cube.lightSequence(cadre, sizeof(cadre), i);
      m-=1;
      c+=1;
    }
  c=0;
    while (c<4)
    {
      byte cadre [] = {n,m, n,m, n,m, n,m, n,m,};
      cube.lightSequence(cadre, sizeof(cadre), i);
      m-=5;
      c+=1;
    }
  n+=1;
  m=0;
  c=0;
  }
}
//---------------------------------------------------------------- END OF TORNADO FUNCTION ----------------------------------------------------------

void Pyramid()
{
//-------------------------------------------------------------- Pyramid FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form of a Pyramid
//This function takes no arguments
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  byte cube1 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 0,5, 0,6, 0,7, 0,8, 0,9, 0,10, 0,11, 0,12, 0,13, 0,14, 0,15, 0,16, 0,17, 0,18, 0,19, 0,20, 0,21, 0,22, 0,23, 0,24, 1,0, 1,1, 1,2, 1,3, 1,4, 1,5, 1,6, 1,7, 1,8, 1,9, 1,10, 1,11, 1,12, 1,13, 1,14, 1,15, 1,16, 1,17, 1,18, 1,19, 1,20, 1,21, 1,22, 1,23, 1,24, 2,0, 2,1, 2,2, 2,3, 2,4, 2,5, 2,6, 2,7, 2,8, 2,9, 2,10, 2,11, 2,12, 2,13, 2,14, 2,15, 2,16, 2,17, 2,18, 2,19, 2,20, 2,21, 2,22, 2,23, 2,24, 3,0, 3,1, 3,2, 3,3, 3,4, 3,5, 3,6, 3,7, 3,8, 3,9, 3,10, 3,11, 3,12, 3,13, 3,14, 3,15, 3,16, 3,17, 3,18, 3,19, 3,20, 3,21, 3,22, 3,23, 3,24, 4,0, 4,1, 4,2, 4,3, 4,4, 4,5, 4,6, 4,7, 4,8, 4,9, 4,10, 4,11, 4,12, 4,13, 4,14, 4,15, 4,16, 4,17, 4,18, 4,19, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte cube2 [] = {0,9, 0,13, 0,14, 0,17, 0,18, 0,19, 0,21, 0,22, 0,23, 0,24, 1,0, 1,1, 1,2, 1,3, 1,5, 1,6, 1,7, 1,9, 1,10, 1,11, 1,13, 1,14, 1,15, 1,17, 1,18, 1,19, 1,21, 1,22, 1,23, 1,24, 2,0, 2,1, 2,2, 2,3, 2,5, 2,6, 2,7, 2,9, 2,10, 2,11, 2,13, 2,14, 2,15, 2,17, 2,18, 2,19, 2,21, 2,22, 2,23, 2,24, 3,0, 3,1, 3,2, 3,3, 3,5, 3,6, 3,7, 3,9, 3,10, 3,11, 3,13, 3,14, 3,15, 3,17, 3,18, 3,19, 3,21, 3,22, 3,23, 3,24, 4,0, 4,1, 4,2, 4,3, 4,5, 4,6, 4,7, 4,10, 4,11, 4,15, };
  byte cube3 [] = {0,14, 0,18, 0,19, 0,23, 0,24, 1,14, 1,18, 1,19, 1,21, 1,23, 1,24, 2,0, 2,1, 2,2, 2,5, 2,6, 2,10, 2,14, 2,18, 2,19, 2,21, 2,22, 2,23, 2,24, 3,0, 3,1, 3,2, 3,5, 3,6, 3,10, 3,15, 4,0, 4,1, 4,2, 4,3, 4,5, 4,6, 4,7, 4,10, 4,11, 4,15, };
  byte cube4 [] = {0,19, 0,23, 0,24, 1,19, 1,23, 1,24, 3,0, 3,1, 3,5, 4,0, 4,1, 4,5, };
  byte cube5 [] = {0,24, 4,0, };
  cube.lightSequence(cube1, sizeof(cube1), 3);
  cube.lightSequence(cube2, sizeof(cube2), 8);
  cube.lightSequence(cube3, sizeof(cube3), 8);
  cube.lightSequence(cube4, sizeof(cube4), 8);
  cube.lightSequence(cube5, sizeof(cube5), 8);
}
//---------------------------------------------------------------- END OF Pyramid FUNCTION ----------------------------------------------------------

void WavesUpDown()
{
//-------------------------------------------------------------- WAVES UP DOWN FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form of a waves moving up and down
//This function takes no arguments
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  byte bb [] = {0,0, 0,1, 0,2, 0,3, 0,4, 0,5, 0,6, 0,7, 0,8, 0,9, 0,10, 0,11, 0,12, 0,13, 0,14, 0,15, 0,16, 0,17, 0,18, 0,19, 0,20, 0,21, 0,22, 0,23, 0,24, };
  byte bb1 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 0,5, 1,6, 1,7, 1,8, 0,9, 0,10, 1,11, 1,12, 1,13, 0,14, 0,15, 1,16, 1,17, 1,18, 0,19, 0,20, 0,21, 0,22, 0,23, 0,24, };
  byte bb2 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 0,5, 1,6, 1,7, 1,8, 0,9, 0,10, 1,11, 2,12, 1,13, 0,14, 0,15, 1,16, 1,17, 1,18, 0,19, 0,20, 0,21, 0,22, 0,23, 0,24, };
  byte bb3 [] = {1,0, 1,1, 1,2, 1,3, 1,4, 1,5, 2,6, 2,7, 2,8, 1,9, 1,10, 2,11, 2,12, 2,13, 1,14, 1,15, 2,16, 2,17, 2,18, 1,19, 1,20, 1,21, 1,22, 1,23, 1,24, };
  byte bb4 [] = {2,0, 2,1, 2,2, 2,3, 2,4, 2,5, 2,6, 2,7, 2,8, 2,9, 2,10, 2,11, 2,12, 2,13, 2,14, 2,15, 2,16, 2,17, 2,18, 2,19, 2,20, 2,21, 2,22, 2,23, 2,24, };
  byte bb5 [] = {3,0, 3,1, 3,2, 3,3, 3,4, 3,5, 2,6, 2,7, 2,8, 3,9, 3,10, 2,11, 2,12, 2,13, 3,14, 3,15, 2,16, 2,17, 2,18, 3,19, 3,20, 3,21, 3,22, 3,23, 3,24, };
  byte bb6 [] = {4,0, 4,1, 4,2, 4,3, 4,4, 4,5, 3,6, 3,7, 3,8, 4,9, 4,10, 3,11, 2,12, 3,13, 4,14, 4,15, 3,16, 3,17, 3,18, 4,19, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte bb7 [] = {4,0, 4,1, 4,2, 4,3, 4,4, 4,5, 3,6, 3,7, 3,8, 4,9, 4,10, 3,11, 3,12, 3,13, 4,14, 4,15, 3,16, 3,17, 3,18, 4,19, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte bb8 [] = {4,0, 4,1, 4,2, 4,3, 4,4, 4,5, 4,6, 4,7, 4,8, 4,9, 4,10, 4,11, 4,12, 4,13, 4,14, 4,15, 4,16, 4,17, 4,18, 4,19, 4,20, 4,21, 4,22, 4,23, 4,24, };
  
  cube.lightSequence(bb, sizeof(bb), 2);
  cube.lightSequence(bb1, sizeof(bb1), 2);
  cube.lightSequence(bb2, sizeof(bb2), 2);
  cube.lightSequence(bb3, sizeof(bb3), 2);
  cube.lightSequence(bb4, sizeof(bb4), 2);
  cube.lightSequence(bb5, sizeof(bb5), 2);
  cube.lightSequence(bb6, sizeof(bb6), 2);
  cube.lightSequence(bb7, sizeof(bb7), 2);
  cube.lightSequence(bb8, sizeof(bb8), 2);
  cube.lightSequence(bb8, sizeof(bb8), 2);
  cube.lightSequence(bb7, sizeof(bb7), 2);
  cube.lightSequence(bb6, sizeof(bb6), 2);
  cube.lightSequence(bb5, sizeof(bb5), 2);
  cube.lightSequence(bb4, sizeof(bb4), 2);
  cube.lightSequence(bb3, sizeof(bb3), 2);
  cube.lightSequence(bb2, sizeof(bb2), 2);
  cube.lightSequence(bb1, sizeof(bb1), 2);
  cube.lightSequence(bb, sizeof(bb), 2);
}
//---------------------------------------------------------------- END OF WAVES UP DOWN FUNCTION ----------------------------------------------------------

void LightDrops(int speedDrop,int times)
{
//-------------------------------------------------------------- LIGHT DROPS FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form rain drops
//This function takes two arguments which are the speed of drops and the execution itirations
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  for(int i=0;i<times;i++)
  {
    cube.lightDrop(random(25),speedDrop);
  }
}
//---------------------------------------------------------------- END OF LIGHT DROPS FUNCTION ----------------------------------------------------------

void LightPeremeters(int speedLights,int times)
{
//-------------------------------------------------------------- LIGHT PEREMETERS FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form rain drops
//This function takes no arguments
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  for(int i=0;i<times;i++)
  {
    for(int j=0;i<times;i++)
    {
      cube.lightPerimeter(i,1,speedLights);
    }
  }
}
//---------------------------------------------------------------- END OF LIGHT PEREMETERS FUNCTION ----------------------------------------------------------

void Waves(int times)
{
//-------------------------------------------------------------- WAVES FUNCTION ------------------------------------------------------------------
//This function allows you to light on the LEDs in a form of waves moving from left to right
//This function takes one argument which is the number of itirations
//-------------------------------------------------------------------------------------------------------------------------------------------------
//****************** As usual starting with the sequences to make **********************
  byte wave [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,0, 1,1, 1,2, 1,3, 1,4, 2,0, 2,1, 2,2, 2,3, 2,4, 3,0, 3,1, 3,2, 3,3, 3,4, 4,0, 4,1, 4,2, 4,3, 4,4, };
  byte wave1 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,0, 1,1, 1,2, 1,3, 1,4, 2,0, 2,1, 2,2, 2,3, 2,4, 3,0, 3,1, 3,2, 3,3, 3,4, 4,5, 4,6, 4,7, 4,8, 4,9, };
  byte wave2 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,0, 1,1, 1,2, 1,3, 1,4, 2,0, 2,1, 2,2, 2,3, 2,4, 3,5, 3,6, 3,7, 3,8, 3,9, 4,10, 4,11, 4,12, 4,13, 4,14, };
  byte wave3 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,0, 1,1, 1,2, 1,3, 1,4, 2,5, 2,6, 2,7, 2,8, 2,9, 3,10, 3,11, 3,12, 3,13, 3,14, 4,15, 4,16, 4,17, 4,18, 4,19, };
  byte wave4 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 1,5, 1,6, 1,7, 1,8, 1,9, 2,10, 2,11, 2,12, 2,13, 2,14, 3,15, 3,16, 3,17, 3,18, 3,19, 4,20, 4,21, 4,22, 4,23, 4,24, };  
  byte wave5 [] = {0,5, 0,6, 0,7, 0,8, 0,9, 1,10, 1,11, 1,12, 1,13, 1,14, 2,15, 2,16, 2,17, 2,18, 2,19, 3,20, 3,21, 3,22, 3,23, 3,24, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave6 [] = {0,10, 0,11, 0,12, 0,13, 0,14, 1,15, 1,16, 1,17, 1,18, 1,19, 2,20, 2,21, 2,22, 2,23, 2,24, 3,20, 3,21, 3,22, 3,23, 3,24, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave7 [] = {0,15, 0,16, 0,17, 0,18, 0,19, 1,20, 1,21, 1,22, 1,23, 1,24, 2,20, 2,21, 2,22, 2,23, 2,24, 3,20, 3,21, 3,22, 3,23, 3,24, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave8 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,20, 1,21, 1,22, 1,23, 1,24, 2,20, 2,21, 2,22, 2,23, 2,24, 3,20, 3,21, 3,22, 3,23, 3,24, 4,20, 4,21, 4,22, 4,23, 4,24, };
  byte wave9 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,20, 1,21, 1,22, 1,23, 1,24, 2,20, 2,21, 2,22, 2,23, 2,24, 3,20, 3,21, 3,22, 3,23, 3,24, 4,15, 4,16, 4,17, 4,18, 4,19, };
  byte wave10 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,20, 1,21, 1,22, 1,23, 1,24, 2,20, 2,21, 2,22, 2,23, 2,24, 3,15, 3,16, 3,17, 3,18, 3,19, 4,10, 4,11, 4,12, 4,13, 4,14, };
  byte wave11 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,20, 1,21, 1,22, 1,23, 1,24, 2,15, 2,16, 2,17, 2,18, 2,19, 3,10, 3,11, 3,12, 3,13, 3,14, 4,5, 4,6, 4,7, 4,8, 4,9, }; 
  byte wave12 [] = {0,20, 0,21, 0,22, 0,23, 0,24, 1,15, 1,16, 1,17, 1,18, 1,19, 2,10, 2,11, 2,12, 2,13, 2,14, 3,5, 3,6, 3,7, 3,8, 3,9, 4,0, 4,1, 4,2, 4,3, 4,4, }; 
  byte wave13 [] = {0,15, 0,16, 0,17, 0,18, 0,19, 1,10, 1,11, 1,12, 1,13, 1,14, 2,5, 2,6, 2,7, 2,8, 2,9, 3,0, 3,1, 3,2, 3,3, 3,4, 4,0, 4,1, 4,2, 4,3, 4,4, }; 
  byte wave14 [] = {0,10, 0,11, 0,12, 0,13, 0,14, 1,5, 1,6, 1,7, 1,8, 1,9, 2,0, 2,1, 2,2, 2,3, 2,4, 3,0, 3,1, 3,2, 3,3, 3,4, 4,0, 4,1, 4,2, 4,3, 4,4, }; 
  byte wave15 [] = {0,5, 0,6, 0,7, 0,8, 0,9, 1,0, 1,1, 1,2, 1,3, 1,4, 2,0, 2,1, 2,2, 2,3, 2,4, 3,0, 3,1, 3,2, 3,3, 3,4, 4,0, 4,1, 4,2, 4,3, 4,4, }; 
  
  for(int i=0;i<times;i++)
  {
   cube.lightSequence(wave, sizeof(wave), 3); 
   cube.lightSequence(wave1, sizeof(wave1), 3);
   cube.lightSequence(wave2, sizeof(wave2), 3);
   cube.lightSequence(wave3, sizeof(wave3), 3);
   cube.lightSequence(wave4, sizeof(wave4), 3);
   cube.lightSequence(wave5, sizeof(wave5), 3);
   cube.lightSequence(wave6, sizeof(wave6), 3);
   cube.lightSequence(wave7, sizeof(wave7), 3);
   cube.lightSequence(wave8, sizeof(wave8), 3);
   cube.lightSequence(wave9, sizeof(wave9), 3);
   cube.lightSequence(wave10, sizeof(wave10), 3);
   cube.lightSequence(wave11, sizeof(wave11), 3);
   cube.lightSequence(wave12, sizeof(wave12), 3);
   cube.lightSequence(wave13, sizeof(wave13), 3);
   cube.lightSequence(wave14, sizeof(wave14), 3);
   cube.lightSequence(wave15, sizeof(wave15), 3);
  }
}
//---------------------------------------------------------------- END OF WAVES FUNCTION ----------------------------------------------------------

void CubeFlick(int times)
{
//-------------------------------------------------------------- CUBE FLICK FUNCTION ------------------------------------------------------------------
//This function allows you to flick the whole CUBE
//This function takes one argument which is the number of itirations
//-------------------------------------------------------------------------------------------------------------------------------------------------

//****************** As usual starting with the sequences to make **********************
  byte cube1 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 0,5, 0,6, 0,7, 0,8, 0,9, 0,10, 0,11, 0,12, 0,13, 0,14, 0,15, 0,16, 0,17, 0,18, 0,19, 0,20, 0,21, 0,22, 0,23, 0,24, 1,0, 1,1, 1,2, 1,3, 1,4, 1,5, 1,6, 1,7, 1,8, 1,9, 1,10, 1,11, 1,12, 1,13, 1,14, 1,15, 1,16, 1,17, 1,18, 1,19, 1,20, 1,21, 1,22, 1,23, 1,24, 2,0, 2,1, 2,2, 2,3, 2,4, 2,5, 2,6, 2,7, 2,8, 2,9, 2,10, 2,11, 2,12, 2,13, 2,14, 2,15, 2,16, 2,17, 2,18, 2,19, 2,20, 2,21, 2,22, 2,23, 2,24, 3,0, 3,1, 3,2, 3,3, 3,4, 3,5, 3,6, 3,7, 3,8, 3,9, 3,10, 3,11, 3,12, 3,13, 3,14, 3,15, 3,16, 3,17, 3,18, 3,19, 3,20, 3,21, 3,22, 3,23, 3,24, 4,0, 4,1, 4,2, 4,3, 4,4, 4,5, 4,6, 4,7, 4,8, 4,9, 4,10, 4,11, 4,12, 4,13, 4,14, 4,15, 4,16, 4,17, 4,18, 4,19, 4,20, 4,21, 4,22, 4,23, 4,24, };

  for(int i=0;i<times;i++)
  {
    cube.lightSequence(cube1, sizeof(cube1), 3);
  }
}
//---------------------------------------------------------------- END OF WAVES FUNCTION ----------------------------------------------------------

void heart(int times)
{
//-------------------------------------------------------------- HEART  FUNCTION ------------------------------------------------------------------
//This function allows you to flick the whole CUBE like a heart tiks
//This function takes one argument which is the number of itirations
//-------------------------------------------------------------------------------------------------------------------------------------------------

//****************** As usual starting with the sequences to make **********************
  byte heart [] = {2,36};
  byte heart1 [] = {1,6, 1,7, 1,8, 1,11, 1,12, 1,13, 1,16, 1,17, 1,18, 2,6, 2,7, 2,8, 2,11, 2,13, 2,16, 2,17, 2,18, 3,6, 3,7, 3,8, 3,11, 3,12, 3,13, 3,16, 3,17, 3,18, };
  byte heart2 [] = {0,0, 0,1, 0,2, 0,3, 0,4, 0,5, 0,6, 0,7, 0,8, 0,9, 0,10, 0,11, 0,12, 0,13, 0,14, 0,15, 0,16, 0,17, 0,18, 0,19, 0,20, 0,21, 0,22, 0,23, 0,24, 1,0, 1,1, 1,2, 1,3, 1,4, 1,5, 1,9, 1,10, 1,14, 1,15, 1,19, 1,20, 1,21, 1,22, 1,23, 1,24, 2,0, 2,1, 2,2, 2,3, 2,4, 2,5, 2,9, 2,10, 2,12, 2,14, 2,15, 2,19, 2,20, 2,21, 2,22, 2,23, 2,24, 3,0, 3,1, 3,2, 3,3, 3,4, 3,5, 3,9, 3,10, 3,14, 3,15, 3,19, 3,20, 3,21, 3,22, 3,23, 3,24, 4,0, 4,1, 4,2, 4,3, 4,4, 4,5, 4,6, 4,7, 4,8, 4,9, 4,10, 4,11, 4,12, 4,13, 4,14, 4,15, 4,16, 4,17, 4,18, 4,19, 4,20, 4,21, 4,22, 4,23, 4,24, };

  for(int i=0;i<times;i++)
  {
    cube.lightSequence(heart, sizeof(heart), 500);
    delay(50);
    cube.lightSequence(heart, sizeof(heart), 1);
    cube.lightSequence(heart1, sizeof(heart1), 1);
    cube.lightSequence(heart, sizeof(heart), 1);
    cube.lightSequence(heart1, sizeof(heart1), 1);
    cube.lightSequence(heart2, sizeof(heart2), 1);
  }
}

//---------------------------------------------------------------- END OF HEART FUNCTION ----------------------------------------------------------

void crossing()
{
//-------------------------------------------------------------- HEART  FUNCTION ------------------------------------------------------------------
//This function allows you to light on a crossing levels
//This function takes no argument
//-------------------------------------------------------------------------------------------------------------------------------------------------
int j=4;
int i=9;
int k=14;
int l=19;
int m=24;
int n=0;
int o=1;
int p=2;
int q=3;
int r=4;
  int forc=0;
  int c=0;
while (c<3)
{

    for(forc=0;forc<5;forc++)
    {
byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

         cube.lightSequence(a, sizeof(a), 3);
         j-=1;
         i-=1;
         k-=1;
         l-=1;
         m-=1;
         }
         for(forc=0;forc<5;forc++)
         {
           byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

                cube.lightSequence(b, sizeof(b), 3);
n+=5;
o+=5;
p+=5;
q+=5;
r+=5;
}
c+=1;
n=0;
 o=1;
 p=2;
 q=3;
 r=4;
 forc=0;  
 j=4;
 i=9;
 k=14;
 l=19;
 m=24;
}
for(forc=0;forc<5;forc++)
    {
      byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

          cube.lightSequence(a, sizeof(a), 2);
         
       cube.lightSequence(b, sizeof(b), 2);
n+=5;
o+=5;
p+=5;
q+=5;
r+=5;
j-=1;
         i-=1;
         k-=1;
         l-=1;
         m-=1;
}

   c=0;
   n+=5;
 j=0;
 i=5;
 k=10;
 l=15;
 m=20;
 n=20;
 o=21;
 p=22;
 q=23;
 r=24;
   while(c<3)
{

    for(forc=0;forc<5;forc++)
    {
byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

         cube.lightSequence(a, sizeof(a), 3);
         j+=1;
         i+=1;
         k+=1;
         l+=1;
         m+=1;
         }
         for(forc=0;forc<5;forc++)
         {
           byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

                cube.lightSequence(b, sizeof(b), 3);
n-=5;
o-=5;
p-=5;
q-=5;
r-=5;
}
c+=1;
 j=0;
 i=5;
 k=10;
 l=15;
 m=20;
 n=20;
 o=21;
 p=22;
 q=23;
 r=24;
 forc=0;  
 
}
c=0;
for(forc=0;forc<5;forc++)
    {
      byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

          cube.lightSequence(a, sizeof(a), 2);
         
       cube.lightSequence(b, sizeof(b), 2);
j+=1;
         i+=1;
         k+=1;
         l+=1;
         m+=1;
         n-=5;
o-=5;
p-=5;
q-=5;
r-=5;
}
}

void FastMove(int times)
{
  
  int m=24;
  int n=4;
  int i=0;
for(int i=0;i<times;i++)
{  
  for(i=0;i<4;i++)
  {
    byte fast [] = {0,m, 1,n, 2,m, 3,n, 4,m, };
    cube.lightSequence(fast, sizeof(fast), 13);
    m-=5;
    n+=5;
    }
    m=4;
    n=24;
    for(i=0;i<4;i++)
  {
    byte fast [] = {0,m, 1,n, 2,m, 3,n, 4,m, };
    cube.lightSequence(fast, sizeof(fast), 13);
    m-=1;
    n-=1;
    }
    m=0;
    n=20;
    for(i=0;i<4;i++)
  {
    byte fast [] = {0,m, 1,n, 2,m, 3,n, 4,m, };
    cube.lightSequence(fast, sizeof(fast), 13);
    m+=5;
    n-=5;
    }
    m=20;
    n=0;
    for(i=0;i<4;i++)
  {
    byte fast [] = {0,m, 1,n, 2,m, 3,n, 4,m, };
    cube.lightSequence(fast, sizeof(fast), 13);
    m+=1;
    n+=1;
    }
}
}

void GoNBack()
{
int j=4;
int  i=9;
int k=14;
int l=19;
int m=24;
int n=0;
int o=1;
int p=2;
int q=3;
int r=4;
int   forc=0;

    for(forc=0;forc<5;forc++)
    {
byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

         cube.lightSequence(a, sizeof(a), 2);
         j-=1;
         i-=1;
         k-=1;
         l-=1;
         m-=1;
         }
          j=0;
 i=5;
 k=10;
 l=15;
 m=20;
  for(forc=0;forc<5;forc++)
    {
byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

         cube.lightSequence(a, sizeof(a), 2);
         j+=1;
         i+=1;
         k+=1;
         l+=1;
         m+=1;
         }
         for(forc=0;forc<5;forc++)
         {
           byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

                cube.lightSequence(b, sizeof(b), 2);
n+=5;
o+=5;
p+=5;
q+=5;
r+=5;
}
n=20;
 o=21;
 p=22;
 q=23;
 r=24;
 for(forc=0;forc<5;forc++)
         {
           byte a [] = {0,j, 0,i, 0,k, 0,l, 0,m, 1,j, 1,i, 1,k, 1,l, 1,m, 2,j, 2,i, 2,k, 2,l, 2,m, 3,j, 3,i, 3,k, 3,l, 3,m, 4,j, 4,i, 4,k, 4,l, 4,m, };
byte b [] = {0,n, 1,n, 2,n, 3,n, 4,n, 0,o, 1,o, 2,o, 3,o, 4,o, 0,p, 1,p, 2,p, 3,p, 4,p, 0,q, 1,q, 2,q, 3,q, 4,q, 0,r, 1,r, 2,r, 3,r, 4,r, };

                cube.lightSequence(b, sizeof(b), 2);
n-=5;
o-=5;
p-=5;
q-=5;
r-=5;
}
}
void randomCube(int times)
{
  for(int i=0;i<times;i++)
  {
    cube.light(random(5),random(25),HIGH);
    cube.light(random(5),random(25),LOW);
    delay(100);
  }
  for(int i=0;i<25;i++)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,LOW);
    }
  }
}
