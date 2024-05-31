#include<graphics.h>
#include<windows.h>
#include <unistd.h>
#include<winuser.h>
#include <math.h>
#include<iostream>
#include<time.h>
using namespace std;
class System{
public:
    int enemyM;
    int enemyR;
    int health;
    int score;
    int delaytransition;
    int mouseX;
    int mouseY;
    System(){
        delaytransition=5;
    }
    void menu(){
      /*  while(delaytransition>0){
            settextstyle(2,0,8);
            settextjustify(1,1);
            outtextxy(getmaxx()/2,getmaxy()/2, "WARNING, THIS GAME CAN ONLY BE PLAYED ON RESOLUTION OF 1536 x 864");
            sleep(1);
            delaytransition--;
        }*/
        MENU:
        cleardevice();
        readimagefile("environment/menu.gif",0,0,getmaxx(),getmaxy());
        settextjustify(1,1);
        settextstyle(2,0,10);
        outtextxy(getmaxx()/2,getmaxy()/8,"Phantom Of Memories");
        outtextxy(getmaxx()/2,getmaxy()/8+50,"The Twins");
        settextstyle(2,0,8);
        outtextxy((getmaxx()*7/8)+75,getmaxy()*5/8+25,"Play");
       //  rectangle(getmaxx()*7/8,getmaxy()*5/8,getmaxx()-30,getmaxy()*5/8+30);
        outtextxy((getmaxx()*7/8)+75,getmaxy()*5/8+75,"Tutorial");
       // rectangle(getmaxx()*7/8,getmaxy()*5/8+50,getmaxx()-30,getmaxy()*5/8+80);
        while(1){
            mouseX=mousex();
            mouseY=mousey();
                if (ismouseclick(WM_LBUTTONDOWN)){
                    clearmouseclick(WM_LBUTTONDOWN);
                    if(mouseX>getmaxx()*7/8&&mouseX<getmaxx()-30&&mouseY>getmaxy()*5/8&&mouseY<getmaxy()*5/8+30){
                        cleardevice();
                        break;
                    }
                    else if(mouseX>getmaxx()*7/8&&mouseX<getmaxx()-30&&mouseY>getmaxy()*5/8+50&&mouseY<getmaxy()*5/8+80){
                            cleardevice();
                            readimagefile("environment/insanity.gif",0,0,getmaxx(),getmaxy());
                            outtextxy((getmaxx()*7/8)+75,getmaxy()*5/8+75,"Next");
                            while(1){
                                mouseX=mousex();
                                mouseY=mousey();
                                if (ismouseclick(WM_LBUTTONDOWN)){
                                    clearmouseclick(WM_LBUTTONDOWN);
                                    if(mouseX>getmaxx()*7/8&&mouseX<getmaxx()-30&&mouseY>getmaxy()*5/8+50&&mouseY<getmaxy()*5/8+80){
                                        break;
                                    }
                                }
                            }
                            cleardevice();
                            readimagefile("environment/insanity 2.gif",0,0,getmaxx(),getmaxy());
                            outtextxy((getmaxx()*7/8)+75,getmaxy()*5/8+75,"Next");
                            while(1){
                                mouseX=mousex();
                                mouseY=mousey();
                                if (ismouseclick(WM_LBUTTONDOWN)){
                                    clearmouseclick(WM_LBUTTONDOWN);
                                    if(mouseX>getmaxx()*7/8&&mouseX<getmaxx()-30&&mouseY>getmaxy()*5/8+50&&mouseY<getmaxy()*5/8+80){
                                        break;
                                    }
                                }
                            }
                            goto MENU;
                    }
                }
        }
    }
    void loading(){
        while(delaytransition>0){
            settextstyle(2,0,8);
            settextjustify(1,1);
            outtextxy(getmaxx()/2,getmaxy()/2, "WARNING, THIS GAME CAN ONLY BE PLAYED ON RESOLUTION OF 1536 x 864");
            sleep(1);
            delaytransition--;
        }
    }
    void death(){
        int page=0;
        PlaySound(TEXT("soundtrack/Wish.wav"),NULL,SND_ASYNC | SND_LOOP);
        int deathm;
        deathm=rand()%3;
        while(1){
            setactivepage(page);
            setvisualpage(1-page);
            page=1-page;
            setbkcolor(BLACK);
            cleardevice();
            settextstyle(2,0,8);
            settextjustify(1,1);
            outtextxy(getmaxx()/2,getmaxy()/2, "The Comfort Of Death Has Come");
            if(deathm==0){
                outtextxy(getmaxx()/2,getmaxy()/2+50, "Certain enemies has a change to be immune to stagger, don't wildly swing !");
            }
            else if(deathm==1){
                outtextxy(getmaxx()/2,getmaxy()/2+50, "Abilities will always stagger and you are immune to damage during casting!");
            }
            else if(deathm==2){
                outtextxy(getmaxx()/2,getmaxy()/2+50, "dodge has short cooldown, might not be a good idea to spam it");
            }
            outtextxy(getmaxx()/2,getmaxy()/2+200, "Press ESC to end");
             if (kbhit())
                {
                    char ch = getch();
                    if(ch==27){
                        break;
                    }
                }
        }
    }
    void ending(){
        PlaySound(TEXT("soundtrack/Wish.wav"),NULL,SND_ASYNC | SND_LOOP);
        int page=0;
        while(1){
            setactivepage(page);
            setvisualpage(1-page);
            page=1-page;
            setbkcolor(BLACK);
            cleardevice();
            settextstyle(2,0,8);
            settextjustify(1,1);
            outtextxy(getmaxx()/2,getmaxy()/2, "The Twins have escaped the world that was their birthplace, although they are unaware of each other");
            outtextxy(getmaxx()/2,getmaxy()/2+25, "for light and shadow can't exist at the same place, they will always be together ");
            outtextxy(getmaxx()/2,getmaxy()/2+200, "Press ESC to end");
             if (kbhit())
                {
                    char ch = getch();
                    if(ch==27){
                        break;
                    }
                }
        }
    }
};
class Player{
public:
    int x;
    int moveX;
    float moveY,y,staticmoveY;
    int jumpState,walkState,attackState,dodgeState,dir,counter,jumpState2;
    int delaysprite,delayattack,delaydodge,iframe;
    int hit,kena,health,regen;
    int ability1,ability2,delay1,delay2,ability,satu,dua;
    void *walkr[11];void *walkl[11];
    void *attackr[17];void *attackl[17];
    void *mwalkr[11];void *mwalkl[11];
    void *mattackr[17];void *mattackl[17];
    void *dodger[6];void *dodgel[6];
    void *mdodger[6];void *mdodgel[6];
    void *rsister[9];void *lsister[9];
    void *mrsister[9];void *mlsister[9];
    void *ult[16];void *mult[16];
    void *logo[10];void *logom[10];
    int area;
    char darah[10];
    Player(){
        x=0;
        y=0;
        hit=0;kena=0;health=10;regen=0;
        moveX=0;moveY=0;
        jumpState=0;walkState=0;dir=1;attackState=0;jumpState2=0;
        counter=0;dodgeState=0;
        delaysprite=32;delayattack=0;delaydodge=0;iframe=0;
        ability1=0;ability2=0;delay1=0;delay2=0;ability=0;satu=1;dua=1;
    }
    void initializelogo(){
        int i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("skill/layer_0.gif",-15,getmaxy()-275,700,getmaxy()+100);
        area = imagesize(-15,getmaxy()-275,700,getmaxy()+100);
        logom[i] = malloc(area);
        getimage(-15,getmaxy()-275,700,getmaxy()+100,logom[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("skill/layer_0.gif",-15,getmaxy()-275,700,getmaxy()+100);
        area = imagesize(-15,getmaxy()-275,700,getmaxy()+100);
        logo[i] = malloc(area);
        getimage(-15,getmaxy()-275,700,getmaxy()+100,logo[i]);
        i++;//1
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("skill/logo_7.gif",-15,getmaxy()-165,145,getmaxy()-15);
        area = imagesize(-15,getmaxy()-165,145,getmaxy()-15);
        logom[i] = malloc(area);
        getimage(-15,getmaxy()-165,145,getmaxy()-15,logom[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("skill/logo_6.gif",-15,getmaxy()-165,145,getmaxy()-15);
        area = imagesize(-15,getmaxy()-165,145,getmaxy()-15);
        logo[i] = malloc(area);
        getimage(-15,getmaxy()-165,145,getmaxy()-15,logo[i]);
        i++;//2
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("skill/logo_5.gif",100,getmaxy()-165,250,getmaxy()-15);
        area = imagesize(100,getmaxy()-165,250,getmaxy()-15);
        logom[i] = malloc(area);
        getimage(100,getmaxy()-165,250,getmaxy()-15,logom[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("skill/logo_3.gif",100,getmaxy()-165,250,getmaxy()-15);
        area = imagesize(100,getmaxy()-165,250,getmaxy()-15);
        logo[i] = malloc(area);
        getimage(100,getmaxy()-165,250,getmaxy()-15,logo[i]);
        i++;//3
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("skill/logo_2.gif",205,getmaxy()-165,355,getmaxy()-15);
        area = imagesize(205,getmaxy()-165,355,getmaxy()-15);
        logom[i] = malloc(area);
        getimage(205,getmaxy()-165,355,getmaxy()-15,logom[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("skill/logo_0.gif",205,getmaxy()-165,355,getmaxy()-15);
        area = imagesize(205,getmaxy()-165,355,getmaxy()-15);
        logo[i] = malloc(area);
        getimage(205,getmaxy()-165,355,getmaxy()-15,logo[i]);
        i++;//4
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("skill/logo_4.gif",100,getmaxy()-165,250,getmaxy()-15);
        area = imagesize(100,getmaxy()-165,250,getmaxy()-15);
        logo[i] = malloc(area);
        getimage(100,getmaxy()-165,250,getmaxy()-15,logo[i]);
        i++;//5
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("skill/logo_1.gif",205,getmaxy()-165,355,getmaxy()-15);
        area = imagesize(205,getmaxy()-165,355,getmaxy()-15);
        logo[i] = malloc(area);
        getimage(205,getmaxy()-165,355,getmaxy()-15,logo[i]);
     /*   readimagefile("skill/layer_0.gif",-15,getmaxy()-275,700,getmaxy()+100);
        readimagefile("skill/logo_6.gif",-15,getmaxy()-165,145,getmaxy()-15);
        readimagefile("skill/logo_3.gif",100,getmaxy()-165,250,getmaxy()-15);
        readimagefile("skill/logo_0.gif",205,getmaxy()-165,355,getmaxy()-15);
        settextjustify(0,0);
        settextstyle(2,0,8);
        sprintf(str,"%d",health);
        outtextxy(15,getmaxy()-155,"Changes: 1");*/
    }
    void printlogo(){
        putimage(-15,getmaxy()-275,logom[0],3);
        putimage(-15,getmaxy()-275,logo[0],1);
        setcolor(RED);
        rectangle(10,getmaxy()-175,240,getmaxy()-150);

        rectangle(10,getmaxy()-175,24*health,getmaxy()-150);
        setfillstyle(SOLID_FILL,RED);
        floodfill(11,getmaxy()-174,RED);
        setcolor(WHITE);
        putimage(-15,getmaxy()-165,logom[1],3);
        putimage(-15,getmaxy()-165,logo[1],1);
        if(satu==1){
            putimage(100,getmaxy()-165,logom[2],3);
            if(delay1!=0){
                putimage(100,getmaxy()-165,logo[4],1);
            }
            else{
                putimage(100,getmaxy()-165,logo[2],1);
            }
        }
        if(dua==1){
            putimage(205,getmaxy()-165,logom[3],3);
            if(delay2!=0){
                putimage(205,getmaxy()-165,logo[5],1);
            }
            else{
                putimage(205,getmaxy()-165,logo[3],1);
            }
        }
     //   settextjustify(0,0);
      //  settextstyle(2,0,8);
       // sprintf(darah,"%d",health);
       // outtextxy(15,getmaxy()-155,"Changes: ");
        //outtextxy(138,getmaxy()-155,darah);
    }
    void initializeskill(){
        int i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("longing/mask longing_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//1
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("longing/mask longing_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//2
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("longing/mask longing_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//3
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("longing/mask longing_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//4
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("longing/mask longing_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//5
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("longing/mask longing_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//6
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//7
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//8
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//9
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//10
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//11
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("longing/longing_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        ult[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,ult[i]);
        i++;//12
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("cons/mask long_0.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        mult[i] = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("cons/long_0.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        ult[i] = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),ult[i]);
        i++;//13
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("cons/mask long_1.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        mult[i] = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("cons/long_1.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        ult[i] = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),ult[i]);
        i++;//14
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("cons/mask long_2.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        mult[i] = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("cons/long_2.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        ult[i] = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),ult[i]);
        i++;//15
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("cons/mask long_3.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        mult[i] = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),mult[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("cons/long_3.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        ult[i] = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),ult[i]);
        i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_0.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_0.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_0.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_0.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);
        i++;//1
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);
        i++;//2
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_2.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_2.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_2.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_2.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);
        i++;//3
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_3.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_3.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_3.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_3.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);
        i++;//4
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_4.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_4.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_4.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_4.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);
        i++;//5
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_5.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_5.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_5.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_5.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);
        i++;//6
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_6.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_6.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_6.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_6.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);
        i++;//7
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_7.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_7.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_7.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_7.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);
        i++;//8
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister right/masking s attackr_8.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mrsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mrsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister right/s attackr_8.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        rsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,rsister[i] );
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("mask sister left/masking s attackl_8.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mlsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mlsister[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("sister left/s attackl_8.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        lsister[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,lsister[i]);

    }
    void initializePlayerdodge(){
        int i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodger/masking dodger_0.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodger[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodger/dodger_0.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodger[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodger/masking dodger_1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodger[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodger/dodger_1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodger[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodger/masking dodger_2.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodger[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodger/dodger_2.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodger[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodger/masking dodger_3.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodger[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodger/dodger_3.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodger[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodger/masking dodger_4.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodger[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodger/dodger_4.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodger[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodger/masking dodger_5.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodger[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodger/dodger_5.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodger[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodger[i]);
        i=0;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodgel/masking dodgel_0.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodgel[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodgel/dodgel_0.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodgel[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodgel/masking dodgel_1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodgel[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodgel/dodgel_1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodgel[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodgel/masking dodgel_2.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodgel[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodgel/dodgel_2.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodgel[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodgel/masking dodgel_3.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodgel[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodgel/dodgel_3.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodgel[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodgel/masking dodgel_4.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodgel[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodgel/dodgel_4.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodgel[i]);
        i++;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking dodgel/masking dodgel_5.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mdodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mdodgel[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("dodgel/dodgel_5.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        dodgel[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,dodgel[i]);
    }
    void initializePlayerwalk(){
        int i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//1
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//2
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//3
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//4
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//5
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//6
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//7
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//8
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//9
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//10
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkr_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkright_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkr[i]);
        i++;//11
        i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//1
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//2
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//3
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//4
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//5
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//6
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//7
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//8
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//9
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//10
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking walk gif/maskingwalkl_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mwalkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mwalkl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("brother walk gif/spritewalkleft_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        walkl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,walkl[i]);
        i++;//11
    }
    void initializePlayerattack(){
        int i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//1
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//2
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//3
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//4
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//5
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//6
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//7
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//8
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//9
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//10
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//11
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//12
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//13
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//14
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//15
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_15.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_15.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i++;//16
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack right/maskingattackr_16.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack right/attack_16.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackr[i]);
        i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//1
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//2
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//3
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//4
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//5
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//6
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//7
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//8
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//9
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//10
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//11
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//12
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//13
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//14
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//15
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_15.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_15.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
        i++;//16
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("masking attack left/maskingattackl_16.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        mattackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,mattackl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("attack left/attackl_16.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        attackl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,attackl[i]);
    }
    void playerHurt(int delayStage){
        if(kena!=0&&iframe==0&&dodgeState==0){
            iframe=10;
            walkState=0;
            attackState=0;
            if(kena==1){
                moveX=30;
                health--;
            }
            else if(kena==2){
                moveX=-30;
                health--;
            }
            //cout<<health<<" ";
        }
        else if (GetKeyState(VK_SHIFT)<0&&delaydodge==0&&ability==0){
                iframe=20;
                walkState=0;
                attackState=0;
                delaydodge=50;
                dodgeState=1;
            if(dir==1){
                moveX=40;
            }
            else if(dir==0){
                moveX=-40;
            }
        }
    }
    void playerControl(int coll,int delayStage){
        hit=0;
        hit=ability;
        if(iframe!=0&&ability==0){
            if(dodgeState==1&&ability==0){
                if(moveX>0){
                    if(iframe>17){
                        putimage(getmaxx()/2-200,310,mdodger[0],3);
                        putimage(getmaxx()/2-200,310,dodger[0],1);
                    }
                    else if(iframe>14){
                        putimage(getmaxx()/2-200,310,mdodger[1],3);
                        putimage(getmaxx()/2-200,310,dodger[1],1);
                    }
                    else if(iframe>11){
                        putimage(getmaxx()/2-200,310,mdodger[2],3);
                        putimage(getmaxx()/2-200,310,dodger[2],1);
                    }
                    else if(iframe>8){
                        putimage(getmaxx()/2-200,310,mdodger[3],3);
                        putimage(getmaxx()/2-200,310,dodger[3],1);
                    }
                    else if(iframe>4){
                        putimage(getmaxx()/2-200,310,mdodger[4],3);
                        putimage(getmaxx()/2-200,310,dodger[4],1);
                    }
                    else if(iframe>0){
                        putimage(getmaxx()/2-200,310,mdodger[5],3);
                        putimage(getmaxx()/2-200,310,dodger[5],1);
                    }
                }
                else{
                    if(iframe>17){
                        putimage(getmaxx()/2-200,310,mdodgel[0],3);
                        putimage(getmaxx()/2-200,310,dodgel[0],1);
                    }
                    else if(iframe>14){
                        putimage(getmaxx()/2-200,310,mdodgel[1],3);
                        putimage(getmaxx()/2-200,310,dodgel[1],1);
                    }
                    else if(iframe>11){
                        putimage(getmaxx()/2-200,310,mdodgel[2],3);
                        putimage(getmaxx()/2-200,310,dodgel[2],1);
                    }
                    else if(iframe>8){
                        putimage(getmaxx()/2-200,310,mdodgel[3],3);
                        putimage(getmaxx()/2-200,310,dodgel[3],1);
                    }
                    else if(iframe>4){
                        putimage(getmaxx()/2-200,310,mdodgel[4],3);
                        putimage(getmaxx()/2-200,310,dodgel[4],1);
                    }
                    else if(iframe>0){
                        putimage(getmaxx()/2-200,310,mdodgel[5],3);
                        putimage(getmaxx()/2-200,310,dodgel[5],1);
                    }
                }
            }
            else if(moveX<0&&iframe>2){
                putimage(getmaxx()/2-200,310,mattackr[0],3);
                putimage(getmaxx()/2-200,310,attackr[0],1);
            }
            else if(iframe>2){
                putimage(getmaxx()/2-200,310,mattackl[0],3);
                putimage(getmaxx()/2-200,310,attackl[0],1);
            }
            iframe--;
            if(iframe==0){
                if(dodgeState==1){
                    delaydodge=50;
                    dodgeState=0;
                }
                moveX=0;
                kena=0;
            }
        }
        if(delaydodge!=0){
            delaydodge--;
        }
        if(iframe==0){
            if (GetAsyncKeyState(VK_LBUTTON))
            {
                attackState=1;
                if(jumpState==1&&counter==4){
                    attackState=0;
                }
                else{
                    moveX=0;
                    walkState=0;
                }
            }
            else if(GetAsyncKeyState(68)&&attackState==0){
                moveX=10;
                walkState=1;
                counter=0;
                //attackState=0;
                dir=1;
            //    printf("%d ",x);
            }
            else if (GetAsyncKeyState(65)&&attackState==0){
                moveX=-10;
                walkState=2;
                counter=0;
                //attackState=0;
                dir=0;
              //  printf("%d ",x);
            }
            else{
                moveX=0;
                walkState=0;
                //attackState=0;
            }
        }
        /*if(x>5000){
            moveX=0;
            x=1000;
        }
        else if(x<-5000){
            moveX=0;
            x=-1000;
        }*/
        if(jumpState==0&&attackState==0){
            /*if (kbhit()){
                char ch = getch();
                if(ch==32){
                   moveY =14;jumpState=1;
                }
            }*/
            if (GetKeyState(VK_SPACE)<0&&delayStage==0){moveY =25;jumpState=1;}
        }
        /*else if(jumpState2==0&&attackState==0&&y<-70){
            if (GetKeyState(VK_SPACE)0){moveY =14;jumpState2=1;}
        }*/
        else if(jumpState==1){
            moveY=moveY-1;
            staticmoveY=moveY;
            if(attackState==1|ability1==1){
                moveY=0;
            }
            else{
                moveY=staticmoveY;
            }
            y=y-moveY;
            if(coll!=0){
                jumpState=0;
                jumpState2=0;
                moveY=0;
                y=0;
            }
        }
        if(walkState==0&&dir==1){
            if(counter==0&&attackState==1){
                counter=1;
            }
            else if(attackState==0){
                if(jumpState!=1){
                    counter=0;
                }
            }
            if(counter!=0&&dodgeState==0){
                if(jumpState==1&&counter==4){
                    //cout<<"so what now ?";
                }
                else if(counter==1){
                    if(delayattack>125|delayattack==0){// readimagefile("attack right/attack_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[0],3);
                        putimage(getmaxx()/2-200,310,attackr[0],1);
                    }
                    else if(delayattack>118){//readimagefile("attack right/attack_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[1],3);
                        putimage(getmaxx()/2-200,310,attackr[1],1);
                    }
                    else if(delayattack>111){ //readimagefile("attack right/attack_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        moveX=5;hit=1;
                        putimage(getmaxx()/2-200,310,mattackr[2],3);
                        putimage(getmaxx()/2-200,310,attackr[2],1);
                         /*   line(getmaxx()/2+215,getmaxy()/2-50,getmaxx()/2+165,getmaxy()/2+200);
                            line(getmaxx()/2+165,getmaxy()/2+200,getmaxx()/2+25,getmaxy()/2+200);
                            line(getmaxx()/2+25,getmaxy()/2+200,getmaxx()/2+25,getmaxy()/2);
                            line(getmaxx()/2+25,getmaxy()/2,getmaxx()/2+215,getmaxy()/2-50);*/
                        if(delayattack==112){
                            counter=2;
                            attackState=0;}
                    }
                }
                else if(counter==2){
                    if(delayattack>101){//readimagefile("attack right/attack_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[3],3);
                        putimage(getmaxx()/2-200,310,attackr[3],1);
                    }
                    else if(delayattack>94){ //readimagefile("attack right/attack_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[4],3);
                        putimage(getmaxx()/2-200,310,attackr[4],1);
                    }
                    else if(delayattack>87){//readimagefile("attack right/attack_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        moveX=7;hit=1;
                        putimage(getmaxx()/2-200,310,mattackr[5],3);
                        putimage(getmaxx()/2-200,310,attackr[5],1);
                        if(delayattack==88){
                            counter=3;
                            attackState=0;}
                    }
                }
                else if(counter==3){
                    if(delayattack>77){ //readimagefile("attack right/attack_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[6],3);
                        putimage(getmaxx()/2-200,310,attackr[6],1);
                    }
                    else if(delayattack>70){//readimagefile("attack right/attack_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[7],3);
                        putimage(getmaxx()/2-200,310,attackr[7],1);
                    }
                    else if(delayattack>63){ //readimagefile("attack right/attack_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        moveX=30;hit=1;
                        putimage(getmaxx()/2-200,310,mattackr[8],3);
                        putimage(getmaxx()/2-200,310,attackr[8],1);
                        if(delayattack==64){
                            counter=4;
                            attackState=0;}
                    }
                }
                else if(counter==4){
                    if(delayattack>53){ //readimagefile("attack right/attack_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[9],3);
                        putimage(getmaxx()/2-200,310,attackr[9],1);
                    }
                    else if(delayattack>45){//readimagefile("attack right/attack_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[10],3);
                        putimage(getmaxx()/2-200,310,attackr[10],1);
                    }
                    else if(delayattack>38){ //readimagefile("attack right/attack_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[11],3);
                        putimage(getmaxx()/2-200,310,attackr[11],1);
                        moveX=20;hit=1;
                        if(delayattack==39){
                            counter=5;
                            attackState=0;}
                    }
                }
                else if(counter==5){
                    if(delayattack>28){//readimagefile("attack right/attack_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[12],3);
                        putimage(getmaxx()/2-200,310,attackr[12],1);
                    }
                    else if(delayattack>21){//readimagefile("attack right/attack_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[13],3);
                        putimage(getmaxx()/2-200,310,attackr[13],1);
                    }
                    else if(delayattack>14){//readimagefile("attack right/attack_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        moveX=20;hit=1;
                        putimage(getmaxx()/2-200,310,mattackr[14],3);
                        putimage(getmaxx()/2-200,310,attackr[14],1);}
                    else if(delayattack>7){//readimagefile("attack right/attack_15.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[15],3);
                        putimage(getmaxx()/2-200,310,attackr[15],1);
                    }
                    else if(delayattack>0){//readimagefile("attack right/attack_16.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackr[16],3);
                        putimage(getmaxx()/2-200,310,attackr[16],1);
                        if(delayattack==1){
                            counter=1;
                            attackState=0;}
                    }
                }
            }
        }
        else if(walkState==0&&dir==0){
            if(counter==0&&attackState==1){
                counter=1;
            }
            else if(attackState==0){
                if(jumpState!=1){
                    counter=0;
                }
            }
            if(counter!=0&&dodgeState==0){
                if(jumpState==1&&counter==4){
                    //cout<<"so what now ?";
                }
                else if(counter==1){
                    if(delayattack>125|delayattack==0){ //readimagefile("attack left/attackl_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[0],3);
                        putimage(getmaxx()/2-200,310,attackl[0],1);
                    }
                    else if(delayattack>118){//readimagefile("attack left/attackl_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[1],3);
                        putimage(getmaxx()/2-200,310,attackl[1],1);
                    }
                    else if(delayattack>111){ //readimagefile("attack left/attackl_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[2],3);
                        putimage(getmaxx()/2-200,310,attackl[2],1);
                        moveX=-5;hit=1;
                   /*     line(getmaxx()/2-215,getmaxy()/2-50,getmaxx()/2-165,getmaxy()/2+200);
                        line(getmaxx()/2-165,getmaxy()/2+200,getmaxx()/2-25,getmaxy()/2+200);
                        line(getmaxx()/2-25,getmaxy()/2+200,getmaxx()/2-25,getmaxy()/2);
                        line(getmaxx()/2-25,getmaxy()/2,getmaxx()/2-215,getmaxy()/2-50);*/
                        if(delayattack==112){
                            counter=2;
                            attackState=0;}
                    }
                }
                else if(counter==2){
                    if(delayattack>101){//readimagefile("attack left/attackl_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[3],3);
                        putimage(getmaxx()/2-200,310,attackl[3],1);
                    }
                    else if(delayattack>94){ //readimagefile("attack left/attackl_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[4],3);
                        putimage(getmaxx()/2-200,310,attackl[4],1);
                    }
                    else if(delayattack>87){//readimagefile("attack left/attackl_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[5],3);
                        putimage(getmaxx()/2-200,310,attackl[5],1);
                        moveX=-7;hit=1;
                        if(delayattack==88){
                            counter=3;
                            attackState=0;}
                    }
                }
                else if(counter==3){
                    if(delayattack>77){ //readimagefile("attack left/attackl_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[6],3);
                        putimage(getmaxx()/2-200,310,attackl[6],1);
                    }
                    else if(delayattack>70){//readimagefile("attack left/attackl_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[7],3);
                        putimage(getmaxx()/2-200,310,attackl[7],1);
                    }
                    else if(delayattack>63){ //readimagefile("attack left/attackl_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[8],3);
                        putimage(getmaxx()/2-200,310,attackl[8],1);
                        moveX=-30;hit=1;
                        if(delayattack==64){
                            counter=4;
                            attackState=0;}
                    }
                }
                else if(counter==4){
                    if(delayattack>53){ //readimagefile("attack left/attackl_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[9],3);
                        putimage(getmaxx()/2-200,310,attackl[9],1);
                    }
                    else if(delayattack>45){readimagefile("attack left/attackl_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[10],3);
                        putimage(getmaxx()/2-200,310,attackl[10],1);
                    }
                    else if(delayattack>38){ readimagefile("attack left/attackl_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[11],3);
                        putimage(getmaxx()/2-200,310,attackl[11],1);
                        moveX=-20;hit=1;
                        if(delayattack==39){
                            counter=5;
                            attackState=0;}
                    }
                }
                else if(counter==5){
                    if(delayattack>28){//readimagefile("attack left/attackl_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[12],3);
                        putimage(getmaxx()/2-200,310,attackl[12],1);
                    }
                    else if(delayattack>21){//readimagefile("attack left/attackl_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[13],3);
                        putimage(getmaxx()/2-200,310,attackl[13],1);
                    }
                    else if(delayattack>14){readimagefile("attack left/attackl_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[14],3);
                        putimage(getmaxx()/2-200,310,attackl[14],1);
                        moveX=-20;hit=1;}
                    else if(delayattack>7){//readimagefile("attack left/attackl_15.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[15],3);
                        putimage(getmaxx()/2-200,310,attackl[15],1);
                    }
                    else if(delayattack>0){readimagefile("attack left/attackl_16.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                        putimage(getmaxx()/2-200,310,mattackl[16],3);
                        putimage(getmaxx()/2-200,310,attackl[16],1);
                        if(delayattack==1){
                            counter=1;
                            attackState=0;}
                    }
                }
            }
        }
        if(jumpState==1&&dir==1&&(counter==0|counter==4)&&iframe==0){
           // readimagefile("brother walk gif/spritewalkright_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
            putimage(getmaxx()/2-200,310,mwalkr[1],3);
            putimage(getmaxx()/2-200,310,walkr[1],1);
        }
        else if(jumpState==1&&dir==0&&(counter==0|counter==4)&&iframe==0){
            //readimagefile("brother walk gif/spritewalkleft_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
            putimage(getmaxx()/2-200,310,mwalkl[1],3);
            putimage(getmaxx()/2-200,310,walkl[1],1);
        }
        else if(walkState==1){
            if(delaysprite>45|delaysprite==0){
               // readimagefile("brother walk gif/spritewalkright_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[1],3);
                putimage(getmaxx()/2-200,310,walkr[1],1);
            }
            else if(delaysprite>40){
                //readimagefile("brother walk gif/spritewalkright_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[2],3);
                putimage(getmaxx()/2-200,310,walkr[2],1);
            }
            else if(delaysprite>35){
                //readimagefile("brother walk gif/spritewalkright_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[3],3);
                putimage(getmaxx()/2-200,310,walkr[3],1);
            }
            else if(delaysprite>30){
               // readimagefile("brother walk gif/spritewalkright_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
               putimage(getmaxx()/2-200,310,mwalkr[4],3);
                putimage(getmaxx()/2-200,310,walkr[4],1);
            }
            else if(delaysprite>25){
                //readimagefile("brother walk gif/spritewalkright_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[5],3);
                putimage(getmaxx()/2-200,310,walkr[5],1);
            }
            else if(delaysprite>20){
                //readimagefile("brother walk gif/spritewalkright_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[6],3);
                putimage(getmaxx()/2-200,310,walkr[6],1);
            }
            else if(delaysprite>15){
                //readimagefile("brother walk gif/spritewalkright_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[7],3);
                putimage(getmaxx()/2-200,310,walkr[7],1);
            }
            else if(delaysprite>10){
                //readimagefile("brother walk gif/spritewalkright_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[8],3);
                putimage(getmaxx()/2-200,310,walkr[8],1);
            }
            else if(delaysprite>5){
                //readimagefile("brother walk gif/spritewalkright_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[9],3);
                putimage(getmaxx()/2-200,310,walkr[9],1);
            }
            else if(delaysprite>0){
                //readimagefile("brother walk gif/spritewalkright_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkr[10],3);
                putimage(getmaxx()/2-200,310,walkr[10],1);
            }
        }
        else if(walkState==2){
            if(delaysprite>45|delaysprite==0){
                //readimagefile("brother walk gif/spritewalkleft_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[1],3);
                putimage(getmaxx()/2-200,310,walkl[1],1);
            }
            else if(delaysprite>40){
               // readimagefile("brother walk gif/spritewalkleft_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[2],3);
                putimage(getmaxx()/2-200,310,walkl[2],1);
            }
            else if(delaysprite>35){
                //readimagefile("brother walk gif/spritewalkleft_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[3],3);
                putimage(getmaxx()/2-200,310,walkl[3],1);
            }
            else if(delaysprite>30){
                //readimagefile("brother walk gif/spritewalkleft_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[4],3);
                putimage(getmaxx()/2-200,310,walkl[4],1);
            }
            else if(delaysprite>25){
                //readimagefile("brother walk gif/spritewalkleft_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[5],3);
                putimage(getmaxx()/2-200,310,walkl[5],1);
            }
            else if(delaysprite>20){
                //readimagefile("brother walk gif/spritewalkleft_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[6],3);
                putimage(getmaxx()/2-200,310,walkl[6],1);
            }
            else if(delaysprite>15){
                //readimagefile("brother walk gif/spritewalkleft_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[7],3);
                putimage(getmaxx()/2-200,310,walkl[7],1);
            }
            else if(delaysprite>10){
                //readimagefile("brother walk gif/spritewalkleft_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[8],3);
                putimage(getmaxx()/2-200,310,walkl[8],1);
            }
            else if(delaysprite>5){
                //readimagefile("brother walk gif/spritewal7//kleft_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[9],3);
                putimage(getmaxx()/2-200,310,walkl[9],1);
            }
            else if(delaysprite>0){
                //readimagefile("brother walk gif/spritewalkleft_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
                putimage(getmaxx()/2-200,310,mwalkl[10],3);
                putimage(getmaxx()/2-200,310,walkl[10],1);
            }
        }
        if(walkState==0|delaysprite==0){
            //delaysprite--;
            delaysprite=50;
        }
        else if(walkState==1){
            delaysprite--;
        }
        else if(walkState==2){
            delaysprite--;
        }
        if(counter==0|delayattack==0){
                delayattack=134;
        }
        else{
                delayattack--;
        }
        if((dir==1&&walkState==0)&&counter==0&&jumpState==0&&iframe==0) {
            //readimagefile("brother walk gif/1.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
            putimage(getmaxx()/2-200,310,mwalkr[0],3);
            putimage(getmaxx()/2-200,310,walkr[0],1);

        }
        else if((dir==0&&walkState==0)&&counter==0&&jumpState==0&&iframe==0) {
            //readimagefile("brother walk gif/spritewalkleft_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
            putimage(getmaxx()/2-200,310,mwalkl[0],3);
            putimage(getmaxx()/2-200,310,walkl[0],1);
        }
      /*  line(getmaxx()/2-25,getmaxy()/2,getmaxx()/2+25,getmaxy()/2);
        line(getmaxx()/2+25,getmaxy()/2,getmaxx()/2+25,getmaxy()/2+200);
        line(getmaxx()/2+25,getmaxy()/2+200,getmaxx()/2-25,getmaxy()/2+200);
        line(getmaxx()/2-25,getmaxy()/2+200,getmaxx()/2-25,getmaxy()/2);*/
    }
    void playerAbilities(){
        if(regen>=10){
            if(health<10){
                health++;
            }
            regen=0;
        }
        if (GetKeyState(69)<0&&ability1==0&&ability==0&&delay1==0&&satu==1){
            iframe=30;
            walkState=0;
            attackState=0;
            dodgeState=1;
            ability1=1;
            hit=2;
            ability=2;
            if(dir==1){
                moveX=40;
            }
            else if(dir==0){
                moveX=-40;
            }
        }
        else if(GetKeyState(81)<0&&ability2==0&&ability==0&&delay2==0&&dua==1){
            iframe=1000;
            walkState=0;
            attackState=0;
            dodgeState=1;
            ability2=1;
            ability=4;
        }
        if(iframe!=0&&ability2==1){
            iframe--;
            moveX=0;
            if(iframe<601){
                ability=3;
                if(iframe>590){
                    putimage(getmaxx()/2-200,310,mult[1],3);
                    putimage(getmaxx()/2-200,310,ult[7],1);
                }
                else if(iframe>580){
                    putimage(getmaxx()/2-200,310,mult[2],3);
                    putimage(getmaxx()/2-200,310,ult[8],1);
                    putimage(0,0,mult[15],3);
                    putimage(0,0,ult[15],1);
                }
                else if(iframe>570){
                    putimage(getmaxx()/2-200,310,mult[3],3);
                    putimage(getmaxx()/2-200,310,ult[9],1);
                    putimage(0,0,mult[14],3);
                    putimage(0,0,ult[14],1);
                }
                else if(iframe>560){
                    putimage(getmaxx()/2-200,310,mult[4],3);
                    putimage(getmaxx()/2-200,310,ult[10],1);
                    putimage(0,0,mult[13],3);
                    putimage(0,0,ult[13],1);
                }
                else{
                    putimage(getmaxx()/2-200,310,mult[5],3);
                    putimage(getmaxx()/2-200,310,ult[11],1);
                    putimage(0,0,mult[12],3);
                    putimage(0,0,ult[12],1);
                }
            }
            else{
                if(iframe>975){
                    putimage(getmaxx()/2-200,310,mult[0],3);
                    putimage(getmaxx()/2-200,310,ult[0],1);
                }
                else if(iframe>950){
                    putimage(getmaxx()/2-200,310,mult[0],3);
                    putimage(getmaxx()/2-200,310,ult[1],1);
                }
                else if(iframe>925){
                    putimage(getmaxx()/2-200,310,mult[0],3);
                    putimage(getmaxx()/2-200,310,ult[2],1);
                }
                else if(iframe>900){
                    putimage(getmaxx()/2-200,310,mult[0],3);
                    putimage(getmaxx()/2-200,310,ult[3],1);
                }
                else if(iframe>875){
                    putimage(getmaxx()/2-200,310,mult[0],3);
                    putimage(getmaxx()/2-200,310,ult[4],1);
                }
                else if(iframe>850){
                    putimage(getmaxx()/2-200,310,mult[0],3);
                    putimage(getmaxx()/2-200,310,ult[5],1);
                }
                else if(iframe>600){
                    putimage(getmaxx()/2-200,310,mult[0],3);
                    putimage(getmaxx()/2-200,310,ult[6],1);
                }
            }
        }
        else if(iframe!=0&&ability1==1){
            if(dodgeState==1){
                if(moveX>0){
                    if(iframe>26){
                        putimage(getmaxx()/2-200,310,mrsister[0],3);
                        putimage(getmaxx()/2-200,310,rsister[0],1);
                    }
                    else if(iframe>23){
                        putimage(getmaxx()/2-200,310,mrsister[1],3);
                        putimage(getmaxx()/2-200,310,rsister[1],1);
                    }
                    else if(iframe>19){
                        putimage(getmaxx()/2-200,310,mrsister[2],3);
                        putimage(getmaxx()/2-200,310,rsister[2],1);
                    }
                    else if(iframe>16){
                        putimage(getmaxx()/2-200,310,mrsister[3],3);
                        putimage(getmaxx()/2-200,310,rsister[3],1);
                    }
                    else if(iframe>12){
                        putimage(getmaxx()/2-200,310,mrsister[4],3);
                        putimage(getmaxx()/2-200,310,rsister[4],1);
                    }
                    else if(iframe>9){
                        putimage(getmaxx()/2-200,310,mrsister[5],3);
                        putimage(getmaxx()/2-200,310,rsister[5],1);
                    }
                    else if(iframe>6){
                        putimage(getmaxx()/2-200,310,mrsister[6],3);
                        putimage(getmaxx()/2-200,310,rsister[6],1);
                    }
                    else if(iframe>3){
                        putimage(getmaxx()/2-200,310,mrsister[7],3);
                        putimage(getmaxx()/2-200,310,rsister[7],1);
                    }
                    else if(iframe>0){
                        putimage(getmaxx()/2-200,310,mrsister[8],3);
                        putimage(getmaxx()/2-200,310,rsister[8],1);
                    }
                }
                else{
                    if(iframe>26){
                        putimage(getmaxx()/2-200,310,mlsister[0],3);
                        putimage(getmaxx()/2-200,310,lsister[0],1);
                    }
                    else if(iframe>23){
                        putimage(getmaxx()/2-200,310,mlsister[1],3);
                        putimage(getmaxx()/2-200,310,lsister[1],1);
                    }
                    else if(iframe>19){
                        putimage(getmaxx()/2-200,310,mlsister[2],3);
                        putimage(getmaxx()/2-200,310,lsister[2],1);
                    }
                    else if(iframe>16){
                        putimage(getmaxx()/2-200,310,mlsister[3],3);
                        putimage(getmaxx()/2-200,310,lsister[3],1);
                    }
                    else if(iframe>12){
                        putimage(getmaxx()/2-200,310,mlsister[4],3);
                        putimage(getmaxx()/2-200,310,lsister[4],1);
                    }
                    else if(iframe>9){
                        putimage(getmaxx()/2-200,310,mlsister[5],3);
                        putimage(getmaxx()/2-200,310,lsister[5],1);
                    }
                    else if(iframe>6){
                        putimage(getmaxx()/2-200,310,mlsister[6],3);
                        putimage(getmaxx()/2-200,310,lsister[6],1);
                    }
                    else if(iframe>3){
                        putimage(getmaxx()/2-200,310,mlsister[7],3);
                        putimage(getmaxx()/2-200,310,lsister[7],1);
                    }
                    else if(iframe>0){
                        putimage(getmaxx()/2-200,310,mlsister[8],3);
                        putimage(getmaxx()/2-200,310,lsister[8],1);
                    }
                }
            }
            iframe--;
        }
        else if(ability1==1&&iframe==0){
            ability1=0;
            ability=0;
            hit=0;
            delay1=200;
            dodgeState=0;
//            cout<<"plis laaaah";
        }
        else if(ability2==1&&iframe==0){
            ability2=0;
            ability=0;
            delay2=2000;
            dodgeState=0;
//            cout<<"worked";
        }
        if(delay1!=0){
            delay1--;
            //else{moveX=0;}
        }
        if(delay2!=0){
            delay2--;
            //else{moveX=0;}
        }
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
class Enemy{
    public:
        int random;
        int xe,xef,dir,s,speed;
        float ye;
        int delayAttack,delayWalk,attackState,meleeSequence,meleeCooldown,shoot,cek,kena,iframe;
        float bagi;
        float dx,dy;
        float vx,vy;
        float xp,yp,xp1,yp1;
        float cos,sin;
        int xw,yw;
        int xc,yc1,yc2,yc3;
        int rangedhp,meleehp,death,initialize;
        void *enemyr[15];void *menemyr[15];
        void *enemyl[15];void *menemyl[15];
        int area;
        int delaydeath;

    Enemy(){
        xe=0;xef=0;speed=rand()%4;
        dir=0;
        ye=(getmaxy()*5/10+50);
        delayAttack=40;delayWalk=12;
        attackState=0;
        meleeSequence=12;meleeCooldown=0;
        s=25;
        xp=0;yp=0;
        vx=0;vy=0;
        dx=0;dy=0;
        bagi=0;
        shoot=0;
        cek=1;iframe=0;kena=0;
        rangedhp=0;
        meleehp=0;death=0;initialize=1;
        kena=0;
        delaydeath=0;
    }
    void initializeRanged(){
        int i=10;
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_10.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//11
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_11.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//12
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_12.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//13
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_13.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//14
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_14.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
    }
    void initializeMelee(){
        int i=0;//0
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_00.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//1
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_01.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//2
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_02.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//3
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_03.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//4
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_04.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//5
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_05.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//6
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_06.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//7
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_07.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//8
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_08.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
        i++;//9
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyr_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyr[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyr_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyr[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyr[i]);
        setbkcolor(WHITE);
        cleardevice();
        readimagefile("adversary/menemyl_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        menemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,menemyl[i]);
        setbkcolor(BLACK);
        cleardevice();
        readimagefile("adversary/enemyl_09.gif",getmaxx()/2-200,310,getmaxx()/2+200,720);
        area = imagesize(getmaxx()/2-200,310,getmaxx()/2+200,720);
        enemyl[i] = malloc(area);
        getimage(getmaxx()/2-200,310,getmaxx()/2+200,720,enemyl[i]);
    }
    int movementM(int posisiX,int moveX, float moveY,int coll,int moblimit){
        ye=ye+moveY+coll;
        if(meleehp!=0){
            initialize=0;
            death=0;
            delaydeath=30;
        if(iframe==0&&kena!=0){
            random==0;
            meleehp--;
            if(kena==3|kena==4){
                iframe=30;
                if(kena==3){
                    xef=-7-speed;
                }
                else if(kena==4){
                    xef=7+speed;
                }
            }
            else{
                random=rand()%3;
//                cout<<random<<" ";
                if(random==0){
                    iframe=30;
//                    cout<<"hit        ";
                    if(kena==1){
                        xef=-7-speed;
                    }
                    else if(kena==2){
                        xef=7+speed;
                    }
                }
                else if(random==1){
                    iframe=30;
//                    cout<<"hit        ";
                    if(kena==1){
                        xef=30+speed;
                    }
                    else if(kena==2){
                        xef=-30-speed;
                    }
                }
                else{
                    iframe=30;
                    if(kena==1){
                        xef=-7-speed;
                    }
                    else if(kena==2){
                        xef=7+speed;
                    }
                }
            }

            }
        if(iframe !=0){
            iframe--;
                xe=xe+xef;
        }
        xe=xe-moveX;
        if(iframe!=0&&random!=2){
            //Melee();
            if(dir==1){
                putimage(xe-200,ye-175,menemyr[0],3);
                putimage(xe-200,ye-175,enemyr[0],1);
            }
            else{
               putimage(xe-200,ye-175,menemyl[0],3);
                putimage(xe-200,ye-175,enemyl[0],1);
            }
        }
        else if(attackState!=1){
            if(delayWalk>8){
                //MeleeWalk();
            if(dir==1){
                putimage(xe-200,ye-175,menemyr[4],3);
                putimage(xe-200,ye-175,enemyr[4],1);
            }
            else{
               putimage(xe-200,ye-175,menemyl[4],3);
                putimage(xe-200,ye-175,enemyl[4],1);
            }
            }
            else if(delayWalk>4){
                //MeleeWalk2();
            if(dir==1){
                putimage(xe-200,ye-175,menemyr[5],3);
                putimage(xe-200,ye-175,enemyr[5],1);
            }
            else{
               putimage(xe-200,ye-175,menemyl[5],3);
                putimage(xe-200,ye-175,enemyl[5],1);
            }
            }
            else{
                //MeleeWalk3();
            if(dir==1){
                putimage(xe-200,ye-175,menemyr[6],3);
                putimage(xe-200,ye-175,enemyr[6],1);
            }
            else{
               putimage(xe-200,ye-175,menemyl[6],3);
                putimage(xe-200,ye-175,enemyl[6],1);
            }
            }
        }
       attackMelee();
        if(xe>getmaxx()/2&&iframe==0){
            if(attackState==0){
                xe=xe-7-speed;
                dir=-1;
            }
        }
        else if(xe<getmaxx()/2&&iframe==0){
            if(attackState==0){
                xe=xe+7+speed;
                dir=1;
            }
        }
        setcolor(WHITE);
       /* //hb musuh
        line(xe-25,ye-50,xe-25,ye+100);
        line(xe-25,ye-50,xe+25,ye-50);
        line(xe-25,ye+100,xe+25,ye+100);
        line(xe+25,ye-50,xe+25,ye+100);

        line(xe,ye-50,xe,ye+100);
        //attack
        line(xe+275,ye+10,xe+275,ye+20);
        line(xe-275,ye+10,xe-275,ye+20);*/

        xc=xe;
        yc1=ye-50;
        yc2=ye+50;
        yc3=ye+100;
        if(delayWalk<=0){delayWalk=12;}
        else{delayWalk--;}
        }
        else if(meleehp==0&&delaydeath!=0){
            attackState=0;
             xe=xe-moveX;
            if(delaydeath>20){
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[7],3);
                    putimage(xe-200,ye-175,enemyr[7],1);
                }
                else{
                   putimage(xe-200,ye-175,menemyl[7],3);
                    putimage(xe-200,ye-175,enemyl[7],1);
                }
            }
            else if(delaydeath>10){
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[8],3);
                    putimage(xe-200,ye-175,enemyr[8],1);
                }
                else{
                   putimage(xe-200,ye-175,menemyl[8],3);
                    putimage(xe-200,ye-175,enemyl[8],1);
                }
            }
            else if(delaydeath>0){
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[9],3);
                    putimage(xe-200,ye-175,enemyr[9],1);
                }
                else{
                   putimage(xe-200,ye-175,menemyl[9],3);
                    putimage(xe-200,ye-175,enemyl[9],1);
                }
            }
            delaydeath--;
        }
        else{
            random=rand()%2;
            speed=rand()%4;
            xef=0;
            if(initialize==1){
                initialize=0;
                attackState=0;
//                cout<<death;
            }
            else if(moblimit==0&&initialize==2){
                initialize=0;
            }
            else if(moblimit==1&&initialize==2){death=0;}
            else{death=1;}
            if(moblimit==0){
                meleehp=5;
                attackState=0;
            }
            else{initialize=2;}
            if(random==1){
                xe=getmaxx()+200;
            }
            else{
                xe=-200;
            }
        }
    }
    int movementR(int posisiX,int moveX, float moveY,int coll,int moblimit){
        ye=ye+moveY+coll;
        if(rangedhp!=0){
            initialize=0;
            death=0;
            delaydeath=30;
            if(cek==1){ye=(getmaxy()*5/10-250);cek=0;}
            if(iframe==0&&kena!=0){
                iframe=30;
                rangedhp--;
//                cout<<"hit        ";
                if(kena==1|kena==2){
                    random=rand()%2;
                    if(random==0){
                        xef=-30-speed;
                    }
                    else if(random==1){
                        xef=30+speed;
                    }
                }
            }
            else if(iframe !=0){
                iframe--;
                xe=xe+xef;
            }
            xe=xe-moveX;
            if(attackState!=1){
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[10],3);
                    putimage(xe-200,ye-175,enemyr[10],1);
                }
                else{
                   putimage(xe-200,ye-175,menemyl[10],3);
                    putimage(xe-200,ye-175,enemyl[10],1);
                }
            }
            attackRanged(moveX,moveY);
            if(xe>getmaxx()/2){
                if(attackState==0){
                    xe=xe-7-speed;
                }
                dir=-1;
            }
            else if(xe<getmaxx()/2){
                if(attackState==0){
                    xe=xe+7+speed;
                }
                dir=1;
            }
            setcolor(WHITE);
          /*  line(xe-25,ye-50,xe-25,ye+100);
            line(xe-25,ye-50,xe+25,ye-50);
            line(xe-25,ye+100,xe+25,ye+100);
            line(xe+25,ye-50,xe+25,ye+100);

            line(xe,ye-50,xe,ye+100);*/
            xc=xe;
            yc1=ye-50;
            yc2=ye+50;
            yc3=ye+100;
        }
        else if(rangedhp==0&&delaydeath!=0){
             xe=xe-moveX;
            if(delaydeath>20){
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[12],3);
                    putimage(xe-200,ye-175,enemyr[12],1);
                }
                else{
                   putimage(xe-200,ye-175,menemyl[12],3);
                    putimage(xe-200,ye-175,enemyl[12],1);
                }
            }
            else if(delaydeath>10){
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[13],3);
                    putimage(xe-200,ye-175,enemyr[13],1);
                }
                else{
                   putimage(xe-200,ye-175,menemyl[13],3);
                    putimage(xe-200,ye-175,enemyl[13],1);
                }
            }
            else if(delaydeath>0){
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[14],3);
                    putimage(xe-200,ye-175,enemyr[14],1);
                }
                else{
                   putimage(xe-200,ye-175,menemyl[14],3);
                    putimage(xe-200,ye-175,enemyl[14],1);
                }
            }
            delaydeath--;
        }
        else{
            random=rand()%2;
            xef=0;
            if(initialize==1){
                initialize=0;
//                cout<<death;
            }
            else if(moblimit==0&&initialize==2){
                initialize=0;
            }
            else if(moblimit==1&&initialize==2){death=0;}
            else{death=1;}
            if(moblimit==0){
                rangedhp=3;
                attackState=1;
            }
            else{initialize=2;}
            speed=rand()%4;
            if(random==1){
                xe=getmaxx()+200;
            }
            else{
                xe=-200;
            }
        }
        return 0;
    }
    int attackMelee(){
        if(iframe!=0&&random!=2){attackState=0;delayAttack=40;}
        else if(xe>getmaxx()/2-200&&xe<getmaxx()/2+200){
            attackState=1;
        }
        if(attackState==1){
            if(delayAttack==0){
                if(meleeSequence!=0){
                //MeleeAttack2();
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[2],3);
                    putimage(xe-200,ye-175,enemyr[2],1);
                }
                else{
                    putimage(xe-200,ye-175,menemyl[2],3);
                    putimage(xe-200,ye-175,enemyl[2],1);
                }
                    if(dir==1){
                        xe=xe+40;
                    }
                    else if(dir==-1){
                        xe=xe-40;
                    }
                    xw=xe+dir*100;
                    yw=ye+20;
                    meleeSequence--;
                }
                else{
                    meleeCooldown=20;
                    delayAttack=60-5*speed;
                    meleeSequence=12;
                }
            }
            else if(meleeCooldown!=0){
                xw=0;
                yw=0;
                //MeleeAttack2();
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[3],3);
                    putimage(xe-200,ye-175,enemyr[3],1);
                }
                else{
                    putimage(xe-200,ye-175,menemyl[3],3);
                    putimage(xe-200,ye-175,enemyl[3],1);
                }
                meleeCooldown--;
                if(meleeCooldown<=0){
                    attackState=0;
                    //cout<<"test";
                }
            }
            else{
                xw=0;
                yw=0;
                delayAttack--;
               // MeleeAttack();
                if(dir==1){
                    putimage(xe-200,ye-175,menemyr[1],3);
                    putimage(xe-200,ye-175,enemyr[1],1);
                }
                else{
                    putimage(xe-200,ye-175,menemyl[1],3);
                    putimage(xe-200,ye-175,enemyl[1],1);
                }
            }
        }
        return 0;
    }
    int attackRanged(int moveX, float moveY){
        if(xe>getmaxx()/2-500-75*speed&&xe<getmaxx()/2+500+75*speed&&kena==0){
                    attackState=1;
        }
        if(attackState==1){
            if(dir==1){
                putimage(xe-200,ye-175,menemyr[11],3);
                putimage(xe-200,ye-175,enemyr[11],1);
            }
            else{
               putimage(xe-200,ye-175,menemyl[11],3);
                putimage(xe-200,ye-175,enemyl[11],1);
            }
            if(delayAttack==0){
                if(shoot==0){
                    xp=xe;
                    yp=ye;
                    vx=getmaxx()/2-xe;
                    vy=(getmaxy()*5/10+50)-ye;
                    bagi=sqrt(vx*vx+vy*vy);
                    cos=vy/bagi;
                    sin=vx/bagi;
                    dx=10*sin;
                    dy=10*cos;
                    shoot=1;
                }
                delayAttack=40;
                attackState=0;
            }
            else{
                delayAttack--;
            }
        }
        xp=xp-moveX;
        yp=yp+moveY;
        xp=xp+dx;
        xp1=xp1+dx;
        yp=yp+dy;
        yp1=yp1+dy;
        if(xp!=0&&yp!=0){
            circle(xp,yp,30);
        }
        if(xp1>2000|yp1>2000|xp1<-2000|yp1<-2000){
            shoot=0;xp1=0;yp1=0;dx=0;dy=0;xp=-100;yp=-100;
        }
        if(xe>getmaxx()/2-500&&xe<getmaxx()/2+500){
                    attackState=1;
        }
        return 0;
    }
};
class World{
public :
    int xw1,xw2,xw3;
    float yw;
    int coll,repY;
    int area;
    void *bg;
    void *g1;
    void *g2;

    World(){
        xw1=0;xw2=getmaxx()/2;xw3=getmaxx();
        yw=(getmaxy()*5/10+200);
        coll=1;
    }
    int initializeWorld(){
        readimagefile("environment/Brick.gif",0,getmaxy()*5/10+200,getmaxx()/2,getmaxy()+150);
        readimagefile("environment/Brick.gif",getmaxx()/2,getmaxy()*5/10+200,getmaxx(),getmaxy()+150);
        area=imagesize(0,getmaxy()*5/10+200,getmaxx()/2,getmaxy()+150);
        g1=malloc(area);
        getimage(0,getmaxy()*5/10+200,getmaxx()/2,getmaxy()+150,g1);
        area=imagesize(getmaxx()/2,getmaxy()*5/10+200,getmaxx(),getmaxy()+150);
        g2=malloc(area);
        getimage(getmaxx()/2,getmaxy()*5/10+200,getmaxx(),getmaxy()+150,g2);
        cleardevice();
        readimagefile("environment/beginning.gif",0,-200,getmaxx(),getmaxy());
        area=imagesize(0,-200,getmaxx(),getmaxy());
        bg=malloc(area);
        getimage(0,-200,getmaxx(),getmaxy(),bg);
        cleardevice();
    }
    void buildWorld(int x,float y){
        xw1=xw1-x;
        xw2=xw2-x;
        xw3=xw3-x;
        yw=yw+y;
        if(xw1<-getmaxx()/2){
            xw1=xw1+getmaxx()*3/2;
        }
        else if(xw1>getmaxx()){
            xw1=xw1-getmaxx()*3/2;
        }
        if(xw2<-getmaxx()/2){
            xw2=xw2+getmaxx()*3/2;
        }
        else if(xw2>getmaxx()){
            xw2=xw2-getmaxx()*3/2;
        }
        if(xw3<-getmaxx()/2){
            xw3=xw3+getmaxx()*3/2;
        }
        else if(xw3>getmaxx()){
            xw3=xw3-getmaxx()*3/2;
        }
        if(yw<(getmaxy()*5/10+200)){
            coll=(getmaxy()*5/10+200)-yw;
            yw=yw+coll;
        }
        else{
            coll=0;
        }
        putimage(0,-200,bg,COPY_PUT);
        putimage(xw1,yw,g1,COPY_PUT);
        putimage(xw2,yw,g2,COPY_PUT);
        putimage(xw3,yw,g2,COPY_PUT);
        //circle(x1+100,250,10);
    }
    int worldColl(){
        return coll;
    }
};
class Hitbox{
public:
    int xp1,xp2;
    int yp1,yp2;
    int xpa1,xpa2,xpa3;
    int ypa1,ypa2;
    int xe1,ye1,xe2,ye2;
    int xea,yea;
    int hp,he;
    Hitbox(){
        xp1=getmaxx()/2-25;yp1=getmaxy()/2;
        xp2=getmaxx()/2+25;yp2=getmaxy()/2+200;
        ypa1=getmaxy()/2-50;
        ypa2=getmaxy()/2+200;
        hp=0;he=0;


    }
    void attack(int hit,int dir,int xc,int yc1,int yc2,int yc3){
      if(hit==1|hit==2){
            if(dir==0){
                xpa1=getmaxx()/2-215;
                xpa2=getmaxx()/2-165;
                xpa3=getmaxx()/2-25;
                if((xpa1<xc|xpa2<xc)&&(xpa3>xc)&&(yc1>ypa1|yc2>ypa1|yc3>ypa1)&&(yc1<ypa2|yc2<ypa2|yc3<ypa2)){
                    //cout<<"yessir";
                    he=1;
                    if(hit==2){
                        he=3;
                    }
                }
            }
            else if(dir==1){
                xpa1=getmaxx()/2+215;
                xpa2=getmaxx()/2+165;
                xpa3=getmaxx()/2+25;
                if((xpa1>xc|xpa2>xc)&&(xpa3<xc)&&(yc1>ypa1|yc2>ypa1|yc3>ypa1)&&(yc1<ypa2|yc2<ypa2|yc3<ypa2)){
                   // cout<<"yessir";
                    he=2;
                    if(hit==2){
                        he=4;
                    }
                }
            }
        }
        else if(hit==3){
            if(getmaxx()>xc&&0<xc&&(yc1>0|yc2>0|yc3>0)&&(yc1<getmaxy()|yc2<getmaxy()|yc3<getmaxy())){
                he=5;
//                cout<<" yesssssssss";
            }
        }
        else{he=0;}
    }
    void hit(int xw,int yw,int dir){
        xea=xw;
        yea=yw;
        if((xea<xp2&&xea>xp1)&&(yea>yp1&&yea<yp2)){
            if(dir==-1){hp=2;/*cout<<"right"*/;}
            else if(dir==1){hp=1;/*cout<<"left"*/;}
        }
        else{hp=0;}
    }
};
int main()
{
    int page = 0,delayStage=0,stage=2,substage=0;
    int limit=0,moblimitm=0,moblimitr=0;
    srand(time(0));
    initwindow(1536,864);
    System game;
    Hitbox global;
    Player p1;
    Enemy melee[7];
    Enemy ranged[7];
   // Bullet bullet[50];
    World map1;
    game.loading();
    PlaySound(TEXT("soundtrack/Wish.wav"),NULL,SND_ASYNC | SND_LOOP);
    game.menu();
    PlaySound(NULL, NULL, 0);
    setactivepage(1);
    p1.initializePlayerdodge();
    p1.initializePlayerattack();
    map1.initializeWorld();
    p1.initializePlayerwalk();
    p1.initializeskill();
    p1.initializelogo();
    for(int i=0;i<7;i++){
        melee[i].initializeMelee();
        ranged[i].initializeRanged();
    }
    setactivepage(0);

    //stage 2-1
    limit=2;
    game.enemyM=3;
    game.enemyR=0;
    PlaySound(TEXT("soundtrack/Battle escalate 1.wav"),NULL,SND_ASYNC | SND_LOOP);
    delay(100);
    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        setbkcolor(8);
        cleardevice();
        map1.buildWorld(p1.playerX(),p1.playerY());
        p1.playerControl(map1.worldColl(),delayStage);
        p1.playerAbilities();
        for(int i =0;i<limit;i++){
                if(game.enemyM<=limit){
                    moblimitm=1;
                }
                if(game.enemyR<=limit){
                    moblimitr=1;
                }
                if(melee[i].kena!=0&&melee[i].iframe==0){
                    p1.regen++;
                    //cout<<" strike "<<p1.regen<<" ";
                }
                melee[i].movementM(p1.posisiX(),p1.playerX(),p1.playerY(),map1.coll,moblimitm);
                global.attack(p1.hit,p1.dir,melee[i].xc,melee[i].yc1,melee[i].yc2,melee[i].yc3);
                melee[i].kena=global.he;
                global.he=0;
                global.hit(melee[i].xw,melee[i].yw,melee[i].dir);
                p1.kena=global.hp;
                p1.playerHurt(delayStage);

                if(ranged[i].kena!=0&&ranged[i].iframe==0){
                    p1.regen++;
                    //cout<<" strike "<<p1.regen<<" ";
                }
                ranged[i].movementR(p1.posisiX(),p1.playerX(),p1.playerY(),map1.coll,moblimitr);
                global.attack(p1.hit,p1.dir,ranged[i].xc,ranged[i].yc1,ranged[i].yc2,ranged[i].yc3);
                ranged[i].kena=global.he;
                global.he=0;
                global.hit(ranged[i].xp,ranged[i].yp,ranged[i].dir);
                p1.kena=global.hp;
                p1.playerHurt(delayStage);
            if(game.enemyM!=0){
                game.enemyM=game.enemyM-melee[i].death;
                //cout<<"m "<<game.enemyM<<" ";
            }
            if(game.enemyR!=0){
                game.enemyR=game.enemyR-ranged[i].death;
               // cout<<"r "<<game.enemyR<<" ";
            }
        }
        if(delayStage!=0){
            delayStage--;
            p1.kena=0;
            outtextxy(getmaxx()/2,200,"STAGE CLEAR");
            if(delayStage==1){
                if(stage==1){
                    PlaySound(NULL, NULL, 0);
                    PlaySound(TEXT("soundtrack/Battle escalate 2.wav"),NULL,SND_ASYNC | SND_LOOP);
                }
                else if(stage==2){
                    PlaySound(NULL, NULL, 0);
                    PlaySound(TEXT("soundtrack/Battle escalate 3.wav"),NULL,SND_ASYNC | SND_LOOP);
                }
            }
        }
        else if((game.enemyM<=0&&game.enemyR<=0&&delayStage==0&&p1.jumpState==0)){
                substage++;
            if(stage==0){
                if(substage==1){
                    game.enemyM=5;
                    game.enemyR=0;
                    moblimitr=0;moblimitm=0;
                    limit=3;
                }
                else if(substage==2){
                    game.enemyM=6;
                    game.enemyR=0;
                    moblimitr=0;moblimitm=0;
                    limit=4;
                }
                else if(substage==3){
                    delayStage=300;
                    p1.satu=1;
                }
            }
            else if(stage==1){
                if(substage==1){
                    game.enemyM=3;
                    game.enemyR=3;
                    moblimitr=0;moblimitm=0;
                    limit=2;
                }
                else if(substage==2){
                    game.enemyM=6;
                    game.enemyR=6;
                    moblimitr=0;moblimitm=0;
                    limit=2;
                }
                else if(substage==3){
                    delayStage=300;
                    p1.dua=1;
                }
            }
            else if(stage==2){
                if(substage==1){
                    game.enemyM=6;
                    game.enemyR=6;
                    moblimitr=0;moblimitm=0;
                    limit=3;
                }
                else if(substage==2){
                    game.enemyM=20;
                    game.enemyR=20;
                    moblimitr=0;moblimitm=0;
                    limit=4;
                }
                else if(substage==3){
                    delayStage=300;
                }
            }
            else if(stage==3){
                break;
            }
            if(substage==3){
                stage++;
                substage=0;
            }
        }
        else if(p1.health<=0){
            cout<<"lose";
            break;
        }
        else if (kbhit())
        {
            char ch = getch();
            if(ch==27){
                break;
            }
        }
        page=1-page;
        p1.printlogo();
    }
    if(p1.health<=0){
        game.death();
    }
    else{
        game.ending();
    }
    closegraph();
    return 0;
}
