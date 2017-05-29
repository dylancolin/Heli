#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
int rx1=200,ry1=100,rx2=230,ry2=115,stop=0,bx1=0,by1=0,by2=0,by3=0,by6=0,i=0;
int bx2=0,bx3=0,bx4=0,bx5=0,bx6=0,i,j=0,n,f,x,l=0,b1=0,b2=0,by4=0,by5=0,b=0;
//int nrx1,nrx2,nry1,nry2;
char input; double score=0;
void translate(int); void translate3(int);
void translate1(int); void translate4(int);
void translate2(int); void translate5(int);
void blade(int,int);
void rotate();
void main()
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
//setbkcolor(LIGHTGRAY);
while(stop==0)
{
 cleardevice();
     if(kbhit()!=0){input = getch();}
  if(input=='w'){ry1=ry1-8; ry2=ry2-8; input='0';}
  else if(input=='s'){ry1=ry1+3; ry2=ry2+3; input='0';}
  else if(input=='a'){rx1=rx1-6; rx2=rx2-6; input='0';}
  else if(input=='d'){rx1=rx1+6; rx2=rx2+6; input='0';}
  else{ ry1=ry1+1; ry2=ry2+1;}
  line(10,60,490,60); line(10,60,10,440);
  line(10,440,490,440); line(490,60,490,440);
  if(rx2>490){rx2=490; rx1=460;}
  if(rx1<10){rx1=10; rx2=40;}
  if(ry1<60){ry1=60; ry2=75; printf("Game Over!\n score : %lf",score); b=1;}
  if(ry2>440){ry2=440; ry1=425; printf("Game Over!\n score : %lf",score); b=1;}
  rectangle(rx1,ry1,rx2,ry2);
  floodfill(rx1+1,ry1+1,WHITE);
  blade(rx1+(rx2-rx1)/2,ry1);

 if(j%150==0){
 n=rand()%3;
 if(n==0){l=1;}
 else if(n==2){ b1=1;}
 else{ b2=1;}
 }
 j++;
 if(l==1){
  if(bx1==0){ bx1=470; by1=190; translate(bx1); l=0;}
  else if(bx4==0){ bx4=500; by4=210; translate3(bx4); l=0;}
 }
 if(b1==1){
   if(bx2==0){ bx2=470; by2=200;translate1(bx2); b1=0;}
  else if(bx5==0){ bx5=500; by5=150; translate4(bx5); b1=0;}
 }
 if(b2==1){
     if(bx3==0){ bx3=470; by3=200;translate2(bx3); b2=0;}
  else if(bx6==0){ bx6=500; by6=150;translate5(bx6); b2=0;}
 }
  delay(10);
 if(bx1>0){ bx1=bx1-1; translate(bx1);}else{ by1=0;}
 if(bx2>0){ bx2=bx2-1; translate1(bx2);}else{ by2=0;}
 if(bx4>0){ bx4=bx4-1; translate3(bx4);}else{ by4=0;}
 if(bx5>0){ bx5=bx5-1; translate4(bx5);}else{ by5=0;}
 if(bx3>0){ bx3=bx3-1; translate2(bx3);}else{ by3=0;}
 if(bx6>0){ bx6=bx6-1; translate5(bx6);}else{ by6=0;}
  delay(10);
   if(bx1>rx1 && bx1<rx2){
     if((ry1<by1) || (ry2<by1) || (ry1>500-by1-40) || (ry2>500-by1-40)){stop=1;
     printf("Game Over!\n score : %lf\n",score);b=1;}
   }
   else if(bx4>rx1 && bx4<rx2){
    if((ry1<by4) || (ry2<by4) || (ry1>500-by4-40) || (ry2>500-by4-40)){stop=1;
     printf("Game Over!\n score : %lf",score);b=1;}
   }
   else if(bx2>rx1 && bx2<rx2){
     if((ry1>by2 && ry1<by2+230) || (ry2>by2 && ry2<by2+230)){stop=1;
     printf("Game Over!\n score : %lf",score);b=1;}
   }
   else if(bx5>rx1 && bx5<rx2){
    if((ry1>by5 && ry1<by5+230) || (ry2>by5 && ry2<by5+230)){stop=1;
     printf("Game Over!\n score : %lf",score);b=1;}
   }
   else if(bx3>rx1 && bx3<rx2){
     if((ry1>by3 && ry1<by3+100) || (ry2>by3 && ry2<by3+100) || (ry1>by3+180 && ry1<by3+240) || (ry2>by3+180 && ry2<by3+240)){stop=1;
     printf("Game Over!\n score : %lf",score);b=1;}
   }
   else if(bx6>rx1 && bx6<rx2){
    if((ry1>by6 && ry1<by6+100) || (ry2>by6 && ry2<by6+100) || (ry1>by6+180 && ry1<by6+240) || (ry2>by6+180 && ry2<by6+240)){stop=1;
     printf("Game Over!\n score : %lf",score);b=1;}
   }
  if(b==1){ //nrx1=rx1; nrx2=rx2; nry1=ry1; nry2=ry2;
     //while(1){rotate(); delay(10);}
     break;}
}
getch();
}
void translate(int i)
{
   line(i,0,i,by1);
   line(i,500,i,500-by1-40);
   if(i>=450){by1=by1-1;}else if(i>=400){by1=by1+1;}else if(i>=300){
   by1=by1-1;}else if(i>=200){by1=by1+1;}else if(i>=100){by1=by1-1;}
   else{by1=by1+1;}
   score=score+0.001;
}
void translate1(int i)
{
line(i,by2,i,by2+230);
   if(i>=450){by2=by2-1;}else if(i>=400){by2=by2+1;}else if(i>=300){
   by2=by2-1;}else if(i>=200){by2=by2+1;}else if(i>=100){by2=by2-1;}
   else{by2=by2+1;}
   score=score+0.001;
}
void translate2(int i)
{
line(i,by3,i,by3+100);
line(i,by3+180,i,by3+240);
   if(i>=450){by3=by3-1;}else if(i>=400){by3=by3+1;}else if(i>=300){
   by3=by3-1;}else if(i>=200){by3=by3+1;}else if(i>=100){by3=by3-1;}
   else{by3=by3+1;}
   score=score+0.001;
}
void translate3(int i)
{
   line(i,0,i,by4);
   line(i,500,i,500-by4-40);
   if(i>=450){by4=by4-1;}else if(i>=400){by4=by4+1;}else if(i>=300){
   by4=by4-1;}else if(i>=200){by4=by4+1;}else if(i>=100){by4=by4-1;}
   else{by4=by4+1;}
   score=score+0.001;
}
void translate4(int i)
{
line(i,by5,i,by5+230);
   if(i>=450){by5=by5-1;}else if(i>=400){by5=by5+1;}else if(i>=300){
   by5=by5-1;}else if(i>=200){by5=by5+1;}else if(i>=100){by5=by5-1;}
   else{by5=by5+1;}
   score=score+0.001;
}
void translate5(int i)
{
line(i,by6,i,by6+100);
line(i,by6+180,i,by6+240);
   if(i>=450){by6=by6-1;}else if(i>=400){by6=by6+1;}else if(i>=300){
   by6=by6-1;}else if(i>=200){by6=by6+1;}else if(i>=100){by6=by6-1;}
   else{by6=by6+1;}
   score=score+0.001;
}
void blade(int a,int b)
{
 setcolor(BLUE);
 if(j%4==0){
 line(a,b,a,b-8);
 sector(a,b-8,270,360,13,3); sector(a-25,b+7,270,360,5,4);}
 else if(j%3==0){
 line(a,b,a,b-8);
 sector(a,b-8,180,270,13,3); sector(a-25,b+7,180,270,5,4);}
 else if(j%2==0){
 line(a,b,a,b-8);
 sector(a,b-8,90,180,13,3); sector(a-25,b+7,90,180,5,4);}
 else{
 line(a,b,a,b-8);
 sector(a,b-8,0,90,13,3); sector(a-25,b+7,0,90,5,4);}
 line(a-15,b+7,a-25,b+7);
 //setcolor(DARKGRAY); fillellipse(a-30,b+7,3,3);
 setcolor(WHITE); fillellipse(a+15,b+7,7,7);
}
/*void rotate()
{
 int ro=30,t;
 t=3.14*ro/180;
 nrx1=abs(nrx1*cos(t)-nry1*sin(t));
 nry1=abs(nrx1*sin(t)+nry1*cos(t));
 nrx2=abs(nrx2*cos(t)-nry2*sin(t));
 nry2=abs(nrx2*sin(t)+nry2*cos(t));
 rectangle(nrx1,nry1,nrx2,nry2);
 floodfill(nrx1+1,nry1+1,WHITE);
 blade(nrx1+(nrx2-nrx1)/2,nry1);
}*/
