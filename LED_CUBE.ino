#include <LedCube.h>                                                                              // 헤더 추가
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
    heart(3);                      // 전부 켜졌다 꺼졋다
    WavesUpDown();                 // 위아래 이동 파동
    CubeFlick(3);                  // 모든 led 깜박깜박
    GoNBack();                     // 왼쪽에서 오른쪽              
    randomCube(20);
    LightDrops(5,50);              // 떨어지기
    Tornado();
    GoNBack();
    LightDrops(30,55);
    GoNBack();
}
void Levels()
{
//-------------------------------------------------------------- LEVELS FUNCTION ------------------------------------------------------------------
//****************** led 켜기**********************
  for(int i=0;i<25;i++)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,HIGH); // "light" function is similar to "digitalWrite" API but it takes three arguments which are the level,the column and the state(HIGH or LOW)
      delay(8);
    }
  }
//***************** led 끄기 *******************************
  for(int i=0;i<25;i++)
  {
    for(int j=0;j<5;j++)
    {
      cube.light(j,i,LOW);
    }
  }
//***************** led 다시 켜기 *****************************
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
void Tornado()
{
//--------------------------------------------------------------TORNADO FUNCTION ------------------------------------------------------------------
//****************** 순서 만들기 *********************
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
void WavesUpDown()
{
//-------------------------------------------------------------- WAVES UP DOWN FUNCTION ------------------------------------------------------------------
//****************** 순서 만들기 **********************
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
  cube.lightSequence(bb, sizeof(bb1), 2);
  cube.lightSequence(bb, sizeof(bb2), 2);
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
//****************** 순서만들기 **********************
  for(int i=0;i<times;i++)
  {
    cube.lightDrop(random(25),speedDrop);
  }
}
//---------------------------------------------------------------- END OF LIGHT DROPS FUNCTION ---------------------------------------------------------
void CubeFlick(int times)
{
//-------------------------------------------------------------- CUBE FLICK FUNCTION ------------------------------------------------------------------

//****************** 순서만들기 **********************
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

//****************** 순서만들기 **********************
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
int forc=0;

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
