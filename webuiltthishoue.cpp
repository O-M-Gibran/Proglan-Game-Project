#include<graphics.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<winuser.h>
#include <cstdlib>
using namespace std;
int delayBullet=0,testcuk=0;
class Bullet{
public:
    int xp,yp,cekBullet,warna;
    Bullet(){
        xp=0;
        yp=0;
        cekBullet=0;
        warna=rand()%10;
    }
    int updateBullet(int x,int y){
        if((xp==0)&&(yp==0)&&(cekBullet==1)){
            xp=x;
            yp=y;
        }
        if(xp>getmaxx()){
            xp=0;
            yp=0;
            cekBullet=0;
        }
        if(cekBullet==1){
            xp=xp+5;
            //setcolor(warna);
            circle(30+xp,yp,10);
        }
        return 0;
    }
    int controlBullet(int x,int y){
        if(delayBullet==0){
            if (GetAsyncKeyState(VK_RIGHT)| GetAsyncKeyState(VK_LEFT)){
                cekBullet=1;
                if(xp==0&&yp==0){
                    delayBullet=10;
                   // printf("number %d \n",testcuk);
                }
            }
        }
        updateBullet(x,y);
        return 0;
    }
};
class Player{
public:
    int x;
    int moveX;
    float moveY,y;
    int jumpState,walkState,attackState,dodgeState,dir,counter;
    int delaysprite,delayattack;
    Player(){
        x=0;
        y=0;
        moveX=0;moveY=0;
        jumpState=0;walkState=0;dir=1;attackState=0;
        counter=0;
        delaysprite=0;delayattack=0;
    }
    void playerControl(){
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            attackState=1;
            moveX=0;
            walkState=0;
        }
       else if(GetAsyncKeyState(68)){
            x=x+4;
            moveX=10;
            walkState=1;
            dir=1;
            //printf("%d ",x);
        }
        else if (GetAsyncKeyState(65)){
            x =x-4;
            moveX=-10;
            walkState=2;
            dir=0;
            //printf("%d ",x);
        }
        else{
            moveX=0;
            walkState=0;
        }
        if(x>10000){
            moveX=0;
            x=10000;
        }
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            attackState=1;
        }
        else{
            attackState=0;
        }
        if(jumpState==0){
            /*if (kbhit()){
                char ch = getch();
                if(ch==32){
                   moveY =10;jumpState=1;
                }
            }*/
            if (GetAsyncKeyState(VK_SPACE)&&attackState==0){moveY =10;jumpState=1;}
        }
        else if(jumpState==1){
            moveY=moveY-0.15;
            y=y-moveY;
           // printf("%d ",y);
            if(y>0){
                printf("jumpstate");
                jumpState=0;
                moveY=0;
                y=0;
            }
        }
        if(attackState==1&&dir==1){
            if(delayattack>80|delayattack==0){ readimagefile("attack right/attack_00.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>75){readimagefile("attack right/attack_01.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>70){ readimagefile("attack right/attack_02.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=5;}
            else if(delayattack>65){readimagefile("attack right/attack_03.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>60){ readimagefile("attack right/attack_04.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>55){readimagefile("attack right/attack_05.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=5;}
            else if(delayattack>50){ readimagefile("attack right/attack_06.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>45){readimagefile("attack right/attack_07.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>40){ readimagefile("attack right/attack_08.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=20;}
            else if(delayattack>35){ readimagefile("attack right/attack_09.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>30){readimagefile("attack right/attack_10.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>25){ readimagefile("attack right/attack_11.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=10;}
            else if(delayattack>20){readimagefile("attack right/attack_12.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>15){readimagefile("attack right/attack_13.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>10){readimagefile("attack right/attack_14.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=10;}
            else if(delayattack>5){readimagefile("attack right/attack_15.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>0){readimagefile("attack right/attack_16.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
        }
        if(attackState==1&&dir==0){
            if(delayattack>80|delayattack==0){ readimagefile("attack left/attackl_00.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>75){readimagefile("attack left/attackl_01.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>70){ readimagefile("attack left/attackl_02.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=-5;}
            else if(delayattack>65){readimagefile("attack left/attackl_03.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>60){ readimagefile("attack left/attackl_04.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>55){readimagefile("attack left/attackl_05.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=-5;}
            else if(delayattack>50){ readimagefile("attack left/attackl_06.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>45){readimagefile("attack left/attackl_07.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>40){ readimagefile("attack left/attackl_08.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=-20;}
            else if(delayattack>35){ readimagefile("attack left/attackl_09.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>30){readimagefile("attack left/attackl_10.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>25){ readimagefile("attack left/attackl_11.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=-10;}
            else if(delayattack>20){readimagefile("attack left/attackl_12.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>15){readimagefile("attack left/attackl_13.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>10){readimagefile("attack left/attackl_14.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
                moveX=-10;}
            else if(delayattack>5){readimagefile("attack left/attackl_15.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
            else if(delayattack>0){readimagefile("attack left/attackl_16.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);}
        }
        else if(jumpState==1){
            readimagefile("brother walk gif/spritewalkright_01.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
        }
        else if(walkState==1){
            if(delaysprite>45|delaysprite==0){
                readimagefile("brother walk gif/spritewalkright_01.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>40){
                readimagefile("brother walk gif/spritewalkright_02.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>35){
                readimagefile("brother walk gif/spritewalkright_03.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>30){
                readimagefile("brother walk gif/spritewalkright_04.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>25){
                readimagefile("brother walk gif/spritewalkright_05.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>20){
                readimagefile("brother walk gif/spritewalkright_06.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>15){
                readimagefile("brother walk gif/spritewalkright_07.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>10){
                readimagefile("brother walk gif/spritewalkright_08.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>5){
                readimagefile("brother walk gif/spritewalkright_09.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>0){
                readimagefile("brother walk gif/spritewalkright_10.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
        }
        /*else if(delaySprite/4<13){
            readimagefile("brother walk gif/1.gif",50,50,500,500);
            playerSprite1();
        }*/
        else if(walkState==2){
            if(delaysprite>45|delaysprite==0){
                readimagefile("brother walk gif/spritewalkleft_01.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>40){
                readimagefile("brother walk gif/spritewalkleft_02.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>35){
                readimagefile("brother walk gif/spritewalkleft_03.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>30){
                readimagefile("brother walk gif/spritewalkleft_04.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>25){
                readimagefile("brother walk gif/spritewalkleft_05.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>20){
                readimagefile("brother walk gif/spritewalkleft_06.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>15){
                readimagefile("brother walk gif/spritewalkleft_07.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>10){
                readimagefile("brother walk gif/spritewalkleft_08.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>5){
                readimagefile("brother walk gif/spritewalkleft_09.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
            else if(delaysprite>0){
                readimagefile("brother walk gif/spritewalkleft_10.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            }
        }

        if(walkState==0|delaysprite<=0){
                delaysprite=50;
        }
        if(attackState==1){
                delaysprite--;
        }
        else if(walkState==1){
            delaysprite--;
        }
        else if(walkState==2){
            delaysprite--;
        }
        if(attackState==0|delayattack<=0){
                delayattack=85;
        }
        else if(attackState==1){
                delayattack--;
        }
        if((dir==1&&walkState==0)&&attackState==0) {
            readimagefile("brother walk gif/1.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            playerSprite1();
        }
        else if((dir==0&&walkState==0)&&attackState==0) {
            readimagefile("brother walk gif/spritewalkleft_00.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
            playerSprite1();
        }

    }
    void playerSprite1(){
        circle(getmaxx()/2,(getmaxy()*5/10+50),30);
    }
    void playerSprite2(){
        readimagefile("brother walk gif/1.gif",getmaxx()/2-200,300,getmaxx()/2+200,732);
    }
    int playerX(){
        return moveX;
    }
    int posisiX(){
        return x;
    }
    float playerY(){
        return moveY;
    }
};
class World{
public :
    int xw,yw,yw2,x1;
    World(int x){
        xw=100+x;
        x1=0;
        yw=(getmaxy()*5/10+100);
        yw2=(getmaxy()*5/10+100);
    }
    int buildWorld(int x,float y,int barisy){
            xw=xw-x;
           // x1=x1-x;
            yw=yw+y;
            yw2=yw2+y;
            if(xw>getmaxx()){
                xw=0;
            }
            else if(xw<0){
                xw=getmaxx();
            }
            if(yw<(getmaxy()*5/10+100)){
                yw=(getmaxy()*5/10+100);
                yw2=(getmaxy()*5/10+100);
            }
            line(0,yw+barisy,getmaxx(),yw+barisy);
            line(xw,yw2+0,xw,yw2+50);xw=xw-95;
            line(xw,yw2+50,xw,yw2+100);xw=xw+95;
            line(xw,yw2+100,xw,yw2+150);xw=xw-95;
            line(xw,yw2+150,xw,yw2+200);xw=xw+95;
            line(xw,yw2+200,xw,yw2+250);xw=xw-95;
            line(xw,yw2+250,xw,yw2+300);xw=xw+95;
            line(xw,yw2+300,xw,yw2+350);xw=xw-95;
            line(xw,yw2+400,xw,yw2+450);xw=xw+95;
           // circle(x1,300,300);
            //circle(x1-100,250,10);
            //circle(x1+100,250,10);
            return 0;
    }
};
class Enemy{
public:
    int xEnemy, yEnemy;
    Enemy(){
        xEnemy=0;
        yEnemy=0;
    }
    movement(int xc,int moveX){
        xEnemy=xEnemy-moveX;
        if(xEnemy<xc){
            xEnemy=xEnemy+5;
        }
        else if(xEnemy>xc){
            xEnemy=xEnemy-5;;
        }
        else{
            xEnemy=xEnemy+0;
        }
        circle(1000+xEnemy,100,10);
    }
};
int main()
{
    int page = 0,delaySprite=100;
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    printf("%d\n",screenWidth);
    printf("%d\n",screenHeight);
    Player p1;Enemy melee;
    Bullet bullet[50];
    initwindow(screenWidth,screenHeight);
    World* map1=(World*)malloc(sizeof(World) * 10);
    int barisx=0;
    int barisy;
        for(int i = 0; i<10; i++){
            map1[i]=World(barisx);
            barisx=barisx+190;
           // printf("%d",p1.playerX());
        }
    barisx=0;
    while(1)
    {
        barisy=0;
        setbkcolor(4);
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        //readimagefile("brother walk gif/3.gif",50,50,500,500);
        p1.playerControl();
        melee.movement(p1.posisiX(),p1.playerX());
        for(int i = 0; i<10; i++){
            map1[i].buildWorld(p1.playerX(),p1.playerY(),barisy);
            barisx=barisx+190;
            barisy=barisy+50;
        }
       /* for(int i=0; i<50; i++){
            bullet[i].controlBullet(getmaxx()/2,500);
           // testcuk=i;
        }
            if(delayBullet!=0){
            delayBullet=delayBullet-1;
        }*/
        //printf("%d ",delayBullet);
        if (kbhit())
        {
            char ch = getch();
            if(ch==27){
                break;;
            }
        }
        page=1-page;
    }
    closegraph();
    return 0;
}
