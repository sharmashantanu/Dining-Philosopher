#include <iostream>
#include<graphics.h>
#define n 6

using namespace std;

int count = 0,i;

class stick
{
    public:
    int used;
}chop[n];

class philospher
{
    public:
    int left;
    int right;
}P[n];

void func(int name)
{
    if(P[name].left==-1 && P[name].right==-1)
        cout<<"Philosopher "<<name+1<<" completed his Lunch\n";

    else if(P[name].left==1 && P[name].right==1)
    {
        cout<<"Philosopher "<<name+1<<" completed his Lunch\n";
        P[name].left = P[name].right = -1;
        int fork = name-1;
        if(fork== -1)
            fork=(n-1);
        chop[name].used = chop[fork].used = 0;
        cout<<"Philosopher "<<name+1<<" released chopstick "<<name+1<<" and chopstick "<<fork+1<<"\n";
        count++;
    }
    else if(P[name].left==1 && P[name].right==0)
    {
        if(name==(n-1))
        {
            if(chop[name].used==0)
            {
                chop[name].used = P[name].right = 1;
                cout<<"Chopstick "<<name+1<<" taken by philosopher "<<name+1<<"\n";
            }
            else
            {
                cout<<"Philosopher "<<name+1<<" is waiting for chopstick "<<name+1<<"\n";
            }
        }
        else
        {
            int vr = name;
            name-=1;
            if(name== -1)
                name=(n-1);
            if(chop[name].used == 0)
            {
                chop[name].used = P[vr].right = 1;
                cout<<"Chopstick "<<name+1<<" taken by Philosopher "<<vr+1<<"\n";
            }
            else
            {
                cout<<"Philosopher "<<vr+1<<" is waiting for Chopstick "<<name+1<<"\n";
            }
        }
    }
    else if(P[name].left==0)
    {
        if(name==(n-1))
        {
            if(chop[name-1].used==0)
            {
                chop[name-1].used = P[name].left = 1;
                cout<<"Chopstick "<<name<<" taken by philosopher "<<name+1<<"\n";
            }
            else
            {
                cout<<"Philosopher "<<name+1<<" is waiting for chopstick "<<name<<"\n";
            }
        }
        else
        {
            if(chop[name].used == 0)
            {
                chop[name].used = P[name].left = 1;
                cout<<"Chopstick "<<name+1<<" taken by Philosopher "<<name+1<<"\n";
            }
            else
            {
                cout<<"Philosopher "<<name+1<<" is waiting for Chopstick "<<name+1<<"\n";
            }
        }
    }
}


int main()
{
    int gd=DETECT,gm,num,j,k;
    initwindow(800,700);

    // GUI

    setfillstyle(XHATCH_FILL,BLUE);
    floodfill(550,400,WHITE);
    circle(400,350,200);
        circle(400,225,35);
        circle(400,475,35);
        circle(275,350,35);
        circle(525,350,35);
        line(435,305,505,235);
        line(365,305,295,235);
        line(365,395,295,465);
        line(435,395,505,465);
        rectangle(380,80,420,120);
        outtextxy(393,93,"P1");
        setfillstyle(SLASH_FILL,RED);
        floodfill(390,90,WHITE);
        rectangle(380,580,420,620);
        outtextxy(393,593,"P3");
        setfillstyle(SLASH_FILL,RED);
        floodfill(390,590,WHITE);
        rectangle(130,330,170,370);
        outtextxy(143,343,"P2");
        setfillstyle(SLASH_FILL,RED);
        floodfill(140,340,WHITE);
        rectangle(630,330,670,370);
        outtextxy(643,343,"P4");
        setfillstyle(SLASH_FILL,RED);
        floodfill(640,340,WHITE);

    // CODE

    cout<<"Enter the number of Philosophers : ";
    cin>>num;

    for(j=0;j<num;j++)
        chop[j].used=P[j].left=P[j].right=0;

    while(count<num)
    {
        for(j=0;j<num;j++)
            func(j);
        cout<<"\n Number of Philosophers who completed their Lunch : "<<count<<"\n\n";
        if(count==1)
        {
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(410,230,WHITE);
        }
        if(count==2)
        {
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(280,360,WHITE);
        }
        if(count==3)
        {
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            floodfill(410,480,WHITE);
        }
        if(count==4)
        {
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(530,360,WHITE);
        }
        delay(2000);
    }


    getch();
    closegraph();
    return 0;
}

