
#include <QTRSensors.h>
  QTRSensorsRC qtr((char[]){A0,A1,A2,A3,A4,A5,A6,A7},8);
int endPoint =0;
int count=0;
static int a[200]; 
int x=0;
int sensor[8]={0, 0, 0, 0, 0,0,0,0};
int strt,j=0,k=0,i,ir;
int LED = 11;
int flag=0;
void read_sensor_values();
void readData();

void HardRight(){
    analogWrite(4,255);
    analogWrite(5,0);
    analogWrite(6,255);//RIGHT
    analogWrite(7,0); 
    Serial.println("HR ");
   }
  void HardLeft(){
    analogWrite(4,0);
    analogWrite(5,255);
    analogWrite(6,0);//left
    analogWrite(7,255); 
    Serial.println("HL ");  
  }
  void Straight(){
    analogWrite(4,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(7,255);
    Serial.println(" | ");
}

void SoftLeft()
{
    analogWrite(4,150);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(7,200);
}

void SoftRight()
{
    analogWrite(4,200);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(7,150);
}
void speeds(int a, int b){
  analogWrite(9, a);
  analogWrite(10, b);
}
/*digitalWrite()*/

//algo
void func1(){
  for(i=0;i<200;i++)
  {
    if(a[i]==4)
    { //    L L B R L ->S
      if((a[i-2]==1)&&(a[i-1]==1)&&(a[i+1]==2)&&(a[i+2]==1))
      {   //printf(" llbrl found");
          a[i-2]=3;
         for(j=i+3;j<200;j++)
            a[j-4]=a[j];
        i-=2;   
      }
      //   L L B R L->S
      if((a[i-2]==1)&&(a[i-1]==2)&&(a[i+1]==1)&&(a[i+2]==1))
      {    //printf("lrbll found");
         x+=3;
         a[i-2]=3;
         for(j=i+3;j<200;j++)
            a[j-4]=a[j];
        i-=2;
      }
      //   L B L -> S
      if((a[i-1]==1)&&(a[i+1]==1))
      {      //printf("lbl found");
        a[i-1]=3;
        x+=2;
        for(j=i+2;j<200-x;j++)
            a[j-2]=a[j];
        i-=1;
      }  //  L B S->R
      if((a[i-1]==1)&&(a[i+1]==3))
      {     //printf("lbs found");
        a[i-1]=2;
        x+=2;
        for(j=i+2;j<200;j++)
            a[j-2]=a[j];
        i-=1;
      }
      //     S B L -> R
      if((a[i-1]==3)&&(a[i+1]==1))
      {    // printf("sbl found");
        a[i-1]=2;
        for(j=i+2;j<200;j++)
            a[j-2]=a[j];
        i--;
      }
      
    }
}
}


//finalrun
void led_blink()
{
  
   digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);                 // wait for a second
                      // wait for a second
}
void follow()
{
 if(flag=0){
   if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)&&(sensor[6]==0)&&(sensor[7]==0)&&(ir==0))
  {   digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,255);//RIGHT
    digitalWrite(7,0); 
    delay(5000);
      endPoint=1;
    }
  if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)&&(sensor[6]==1)&&(sensor[7]==1))
            HardLeft();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
   {         Straight();
            flag=0;
   }
  if((sensor[0]!=0)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
   {         Straight();
             flag=0;
   }
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=0))
   {         Straight();
              flag=0;
   }
    if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
   {         Straight();
              flag=0;
   }
   
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
   {         flag=1;
   }
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
    {        flag=1;
    }
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=0))
    {        flag=1;
    }
  if((sensor[0]!=0)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
   {         flag=1;
   }
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
   {         flag=1;
   }
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
   {         flag=1;
   }
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)&&(sensor[6]==0)&&(sensor[7]==0))
   {         flag=1;
   } 
 }

  else if(flag==1)
  {
    if(a[i]==1)  HardLeft();
    if(a[i]==2)  HardRight();
    if(a[i]==3)  Straight();
    if(a[i]==4)  HardLeft();
  }

}

int movedx()
{   int local=1;
   digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
     digitalWrite(6,LOW);//left
    digitalWrite(7,HIGH);
    delay(500);
  sensor[1] = analogRead(A1);
  sensor[2] = analogRead(A2);
  sensor[3] = analogRead(A3);
  sensor[4] = analogRead(A4);
  sensor[5] = analogRead(A5);
  sensor[6] = analogRead(A6);
  sensor[7] = analogRead(A7);
  for(i=0;i<8;i++)
  {
    if(sensor[i]<500)  sensor[i]=0;
    if(sensor[i]>800)  sensor[i]=1;
  }
     if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)&&(sensor[6]==1)&&(sensor[7]==1))
           local=0;
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);//left
    digitalWrite(7,LOW);
    delay(500);
   return local;
}
void unode()
{
  a[k++]=1;
  HardLeft();
  delay(800);
}
void lnode()
{ 
  a[k++]=1;
   HardLeft();
  delay(800);

}
void rnode()
{
 strt = 0;//movedx();
   if(strt==0)
   { a[k++]=2;
     HardRight();
       delay(800);
   }
  if(strt==1)
  {  a[k++]=3;
   Straight();
     delay(800);
 
  } 
   
}
void forward()
{
  a[k++]=3;
  Straight();
}
void lrnode()
{
 //strt = movedx();
 a[k++]=1;
  HardLeft();
    delay(800);

}
void readData(){
  sensor[0]=analogRead(A0);
  sensor[1]=analogRead(A1);
  sensor[2]=analogRead(A2);
  sensor[3]=analogRead(A3);
  sensor[4]=analogRead(A4);
  sensor[5]=analogRead(A5);
  sensor[6]=analogRead(A6);
  sensor[7]=analogRead(A7);
  ir=digitalRead(3);
 for(i=0;i<8;i++)
  {
    if(sensor[i]<600)  sensor[i]=0;
    if(sensor[i]>800)  sensor[i]=1;
  }

Serial.print(sensor[0]);
Serial.print(sensor[1]);
Serial.print(sensor[2]);
Serial.print(sensor[3]);
 
Serial.print(sensor[4]);
Serial.print(sensor[5]);
Serial.print(sensor[6]);
Serial.println(sensor[7]);
}
void read_sensor_values()
{
  readData();
  //UTURN
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)&&(sensor[6]==0)&&(sensor[7]==0)&&(ir==0))
  { count==1;
     func1();
      digitalWrite(4,LOW);
   digitalWrite(5,LOW);
      digitalWrite(6,LOW);//left
    digitalWrite(7,LOW);
     delay(6000);
    }
  if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)&&(sensor[6]==1)&&(sensor[7]==1))
            unode();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
            forward();
  if((sensor[0]!=0)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
            forward();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=0))
            forward();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
            lnode();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
            lnode();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=0))
            lnode();
  if((sensor[0]!=0)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            rnode();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            rnode();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            rnode();
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)&&(sensor[6]==0)&&(sensor[7]==0))
            lrnode(); 
       
}


void setup() {
 pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A7,INPUT);

  
  for(i=0;i<250;i++)
  {
    qtr.calibrate();
    delay(5);
    
 }
  // put your setup code here, to run once:
pinMode(9,OUTPUT); //PWM Pin 1
 pinMode(10,OUTPUT); //PWM Pin 2
 pinMode(4,OUTPUT); //Left Motor Pin 1
 pinMode(5,OUTPUT); //Left Motor Pin 2
 pinMode(6,OUTPUT); //Right Motor Pin 1
 pinMode(7,OUTPUT);  //Right Motor Pin 2
 pinMode(3,OUTPUT);   //LED BLink
   pinMode(LED, OUTPUT);

 Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
if(count==0)
{
    read_sensor_values();
    
}
else
{readData();
 i=0;
  follow();

  if(endPoint==1)
   led_blink();
 }
}

/* 
 * if(s[0]==0 && 8times &irsensor==1)
 *  endPoint =1;
 *  stop();
 */

//code for dry run that will change the value of endPoint to 1 when it reach at end
