
#include <graphics.h>
#include <iostream.h>
#include  <fstream.h>
#include   <string.h>
#include   <stdlib.h>
#include    <ctype.h>
#include    <conio.h>
#include    <stdio.h>
#include      <dos.h>
char sysdat[15];
int button,x,y;
int long a;
char na[30],no[30];
union REGS in,out;



class bankcustomer
{
char name[30],fname[30],mname[30],city[30],district[30],state[30];
char varify[30],gender[30],nation[30],dob[15],actype[20],mob[20];
char ano[15],pin[15],sysdate[15];
long double amt;

public:
class transaction
{
long double m;
char d[15],n[12],t[15];
public:
void transact(long double,char*,char*);
void balance(char*,long double);
};




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		            FUNCTIONS TO GET DATA
//                                FROM USER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




		       void getamt(int,int,int,int,int);
		       void getacno();
		       void getactype(int,int,int,int,int);
		       void getalphabet(int,int,int,int,int);
		       void getdob(int,int,int,int);
		       void getgender(int,int,int,int,int);
		       void getno(int,int,int,int,int);




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		            FUNCTIONS TO CHECK ERROR
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




		       int checkalphabet(char*);
		       int checkdob(char*);
		       int finaldate(char*);
		       int checkgender(char*);
		       int checkno(char*,int p);
		       int checkamt(char[],int);




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		            FUNCTIONS TO HANDLE ERROR
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




		       void error(int,int,int,int,int);
		       void doberror(int,int);
		       void amterror(int,int,int,int,int);




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTIONS FOR FILE HANDLING
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




			void  showindividual();
			void depositwithdraw(int);
			void confirm();
			friend void getdeposit();
			void deposit_withdraw(char[],char[],int) ;
			void money_transfer();
			void transfer();
			void modify_account();
			void all(int,int);
			void balance_inq();
			void closeaccount();
};



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		     OTHER FUNCTIONS THAT PERFORM
//                          ESSENTIAL TASK
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



			char* date();
			void newaccountinterface(char[],int,int);
			void mainmenu();
			void addfile(bankcustomer c);
			void input();
			void title();
			void winborder();
			void buttun(int,int,int,int,char[],int,int);
			void help();
			void start();
			void deposit_withdraw(char[],char[],int);
			void individual();
			void all_account();
			void money_transfer();
			void welcome();





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                         FUNCTION TO INITIALISE MOUSE
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




int mouseinit()
{
in.x.ax=0;
int86(0x33,&in,&out);
return 0;
}



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO HIDE MOUSE POINTER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




void hidemouseptr()
{
in.x.ax=2;
int86(0x33,&in,&out);
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO SHOW MOUSE POINTER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




void showptr()
{
in.x.ax=1;
int86(0x33,&in,&out);
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		      FUNCTION TO RESTRICT MOUSE POINTER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




void ristrictmouseptr()
{
in.x.ax=7;
in.x.cx=4;
in.x.dx=getmaxx()-10;
int86(0x33,&in,&out);
in.x.ax=8;
in.x.cx=2;
in.x.dx=getmaxy()-18;
int86(0x33,&in,&out);
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO GET MOUSE POSITION
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




void getmousepos(int*button,int*x,int*y)
{
in.x.ax=3;
int86(0x33,&in,&in);
*button=in.x.bx;
*x=in.x.cx;
*y=in.x.dx;
}








//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                          FUNCTIONS FOR INTERFACE
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		      FUNCTION FOR CREATING A BUTTON
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





	      void buttun(int x1,int y1,int x2,int y2,char arr[],int c1,int c2)
	      {
	      setcolor(c1);
	      line(x1,y1,x2,y2);
	      line(x1,y1,x1,y1+20);
	      setcolor(c2);
	      line(x1,y1+20,x2,y2+20);
	      line(x2,y2+20,x2,y1);
	      line(x1,y1+21,x2+1,y2+21);
	      line(x2+1,y2+21,x2+1,y2);
	      settextstyle(0,0,0);
	      outtextxy(x1+10,y1+8,arr);
	      setcolor(8);
	      }




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO CREATE WINDOW BORDER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





		void winborder(int color)
		{
		setcolor(color);
		rectangle(1,1,638,478);
		rectangle(2,2,637,477);
		char *d=date();
		setcolor(9);
		outtextxy(530,45,d);
		setcolor(color);
		outtextxy(490,45,"DATE:");
		setcolor(8);
		}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO CREATE TITLE BAR
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void title(int text,int back)
{
 setfillstyle(1,back);
 bar(3,3,636,26);
 setcolor(9);
 setfillstyle(1,9);
 circle(20,14,10);
 floodfill(20,14,9);
 setcolor(back);
 setfillstyle(1,back);
 circle(20,14,3);
 floodfill(20,14,back);
 bar(19,17,21,24);
 setcolor(text);
 outtextxy(40,10,"STATE BANK OF INDIA");
 setcolor(9);
 rectangle(3,26,636,27);
 }




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		         FUNCTION TO CREATE INTERFACE
//                            FOR OPENING ACCOUNT
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





			 void newaccountinterface(char arr[],int text,int border)
			 {
			 cleardevice();
			 title(15,4);
			 setfillstyle(1,7);
			 bar(3,28,getmaxx(),getmaxy());
			 winborder(border);
			 settextstyle(8,0,1);
			 setcolor(border);
			 rectangle(3,26,636,27);
			 outtextxy(100,35,arr);
			 settextstyle(0,0,0);
			 rectangle(3,70,636,71);
			 setcolor(text);
			 outtextxy(50,100,"NAME             :");
			 outtextxy(50,125,"FATHER NAME      :");
			 outtextxy(50,150,"MOTHER NAME      :");
			 outtextxy(50,175,"DATE OF BIRTH    :");
			 outtextxy(50,200,"GENDER           :");
			 outtextxy(50,225,"CITY             :");
			 outtextxy(50,250,"DISTRICT         :");
			 outtextxy(50,275,"STATE            :");
			 outtextxy(50,300,"PIN CODE         :");
			 outtextxy(50,325,"PHONE NUMBER     :");
			 outtextxy(50,350,"NATIONALITY      :");
			 outtextxy(50,375,"ACCOUNT TYPE     :");
			 outtextxy(50,400,"VERIFYER         :");
			 rectangle(200,95,410,115);
			 rectangle(200,120,410,140);
			 rectangle(200,145,410,165);
			 rectangle(200,170,410,190);
			 rectangle(200,195,410,215);
			 rectangle(200,220,410,240);
			 rectangle(200,245,410,265);
			 rectangle(200,270,410,290);
			 rectangle(200,295,410,315);
			 rectangle(200,320,410,340);
			 rectangle(200,345,410,365);
			 rectangle(200,370,410,390);
			 rectangle(200,395,410,415);
			 buttun(450,435,500,435,"EXIT",border,text);
			 buttun(510,435,560,435,"BACK",border,text);
			 buttun(570,435,620,435,"NEXT",border,text);
			 setcolor(text);
			 }





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//				 HELP MENU
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



	void help()
	{
	cleardevice();
	setbkcolor(8);
	settextstyle(1,0,1);
	setcolor(8);
	setfillstyle(9,5);
	bar(2,10,637,30);
	outtextxy(255,9,"INSTRUCTIONS");
	setcolor(2);
	settextstyle(1,0,1);
	outtextxy(30,50,"Welcome to you in SBI. It manages accounts activity as daily");
	outtextxy(30,65,"routine of banking system, by providing a set of options...");
	settextstyle(2,0,6);
	setcolor(13);
	outtextxy(15,105,"1. The Ist option is OPEN A/C, through which a person can open");
	outtextxy(40,120,"a new account in SBI by inserting some informations & initial");
	outtextxy(40,135,"balance. The initial amount not less than 1000.");
	outtextxy(15,155,"2. To perform deposite operation, DEPOSITE option is to be used.");
	outtextxy(15,180,"3. To perform withdraw operation, we select WITHDRAW option.");
	outtextxy(15,205,"4. To check balance or transacton the option BALANCE INQ is to");
	outtextxy(40,220,"be selected");
	outtextxy(15,240,"5. To know the details about bank customer, CUST INFO button");
	outtextxy(40,255,"is pressed.");
	outtextxy(15,275,"6. The ALL ACCOUNT option provides a you to display total no of");
	outtextxy(40,290,"account along with their name, a/c number, a/c type, ");
	outtextxy(40,305,"date of creation & available balance.");
	outtextxy(15,325,"7. To modify a record of bank customer, SBI provides an editing");
	outtextxy(40,340,"facility, which  enables after pressing MODIFY ACC option");
	outtextxy(15,360,"8. SBI provides feature of transfering money from one account");
	outtextxy(40,375,"to other account, which enables after selecting MONEY TRANS.");
	outtextxy(15,395,"9. For closing account we select CLOSE A/C option.");
	buttun(500,435,550,435,"EXIT",2,7);
	buttun(560,435,610,435,"NEXT",2,7);
	showptr();
	while(1)
	{
	getmousepos(&button,&x,&y);
	if(x>500&&y>435&&x<550&&y<455&&(button&1)==1)
	 {
	  buttun(500,435,550,435,"EXIT",7,2);
	  delay(50);
	  buttun(500,435,550,435,"EXIT",2,7);
	  exit(0);
	 }
	 else if(x>560&&y>435&&x<610&&y<455&&(button&1)==1)
	       {
	       hidemouseptr();
	       buttun(560,435,610,435,"NEXT",7,2);
	       delay(50);
	       buttun(560,435,610,435,"NEXT",2,7);
	       mainmenu();
		}
	}
	}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                         FUNCTION FOR WELCOME SCREEN
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




							      //  FIRST SCREEN
void welcome(){
     setfillstyle(1,15);
     bar(3,3,636,getmaxy());
     setbkcolor(15);
     setcolor(1);
     for(int y=50;y<60;y++)
     {
       moveto(25,y);
       lineto(620,y);
     }
     for(int r=52;r<60;r++)
       arc(65,110,240,90,r);
     for(y=150;y<162;y++)
     {
       moveto(35,y);
       lineto(115,y+80);
     }
     for(y=140;y<150;y++)
     {
       moveto(107,y);
       lineto(135,y);
     }
     for(r=50;r>42;r--)
       arc(185,150,70,290,r);
     for(int x=185;x<193;x++)
     {
       moveto(x+15,50);lineto(x+15,240);
       moveto(x+38,50);lineto(x+38,240);
       moveto(x+160,50);lineto(x+160,240);
       moveto(x+265,50);lineto(x+265,240);
       moveto(x+340,50);lineto(x+340,240);
       moveto(x+400,50);lineto(x+400,240);}
       for(x=292;x<300;x++)
       {
	 moveto(x,50);
	 lineto(x,240);
       }
       for(r=41;r<50;r++)
	 arc(292,190,120,270,r);
       for(r=41;r<50;r++)
	 arc(420,150,40,190,r);
       for(x=370;x<379;x++)
       {
	 moveto(x,150);lineto(x+10,241);}
       for(y=150;y<159;y++)
       {
	 moveto(480,y);
	 lineto(590,y);
       }
       for(x=476;x<484;x++)
       {
	 moveto(x,150);
	 lineto(x+49,241);
       }
       for(x=585;x<593;x++)
       {
	 moveto(x,244);
	 lineto(x+10,250);
       }
       for(r=200;r<205;r++)
	 arc(102,650,70,120,r);
       for(r=100;r<105;r++)
	 arc(-10,370,300,360,r);
       for(r=1;r<10;r++)
	 circle(85,368,r);
       for(r=1;r<10;r++)
	 circle(170,467,r);
       for(r=200;r<205;r++)
	 arc(539,650,60,110,r);
       for(r=1;r<10;r++)
	 circle(473,467,r);
       for(r=100;r<105;r++)
	 arc(649,370,180,237,r);
       for(r=1;r<10;r++)
	 circle(555,368,r);
	 setcolor(4);
	 rectangle(1,1,639,478);
	 rectangle(2,2,638,477);
	 rectangle(3,3,637,476);
	 int t1=2,t2=4,i;
	 setbkcolor(8);

	 while(!kbhit())
	 {
	   for(x=20;x<639;x=x+20)
	   {
	     for(int r=1;r<10;r++)
	     {
	       setcolor(t1);
	       circle(x,3,r);
	       circle(x,473,r);
	       circle(5,x,r);
	       circle(635,x,r);
	     }
	     i=t1;t1=t2;t2=i;
	    }
	    delay(100);
	  }
	 // buttun(500,420,550,420,"NEXT",7,8);
	 /*    showptr();
	  while(1)
	  {
	 getmousepos(&button,&x,&y);
	 if(x>500&&y>420&&x<550&&y<440&&(button&1)==1)
	 {
	   hidemouseptr();
	   buttun(500,420,550,420,"NEXT",8,7);
	   delay(50);
	   buttun(500,420,550,420,"NEXT",7,8);
	   start();
	 }
	}*/
       }






//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//				 MAIN MENU
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




	void mainmenu()
	{
	int x,y,button;
	cleardevice();
	title(15,7);
	setfillstyle(1,15);
	bar(3,28,getmaxx(),getmaxy());
	winborder(9);
	setcolor(9);

	//      SBI LOGO

	ellipse(getmaxx()/2,getmaxy()/2,0,360,195,195);
	setfillstyle(1,9);
	floodfill(getmaxx()/2,getmaxy()/2,9);
	setcolor(15);
	ellipse(getmaxx()/2,getmaxy()/2,0,360,30,30);
	setfillstyle(1,15);
	floodfill(getmaxx()/2,getmaxy()/2,15);
	bar(314,220,324,434);
	setfillstyle(1,15);
	floodfill(315,220,15);

	//     CREATING MENU

	buttun(265,70,368,70,  " OPEN A/C ",7,8);
	buttun(265,110,368,110,"  DEPOSIT  ",7,8);
	buttun(265,150,368,150," WITHDRAW ",7,8);
	buttun(265,190,368,190,"BALANCE INQ",7,8);
	buttun(265,230,368,230,"CUST INFO",7,8);
	buttun(265,270,368,270,"ALL ACCOUNT",7,8);
	buttun(265,310,368,310,"MODIFY  ACC",7,8);
	buttun(265,350,368,350,"MONEY TRANS",7,8);
	buttun(265,390,368,390," CLOSE A/C ",7,8);
	setfillstyle(1,9);
	bar(575,415,625,435);
	bar(575,445,625,465);
	buttun(575,415,625,415,"HELP",8,15);
	buttun(575,445,625,445,"EXIT",8,15);
	showptr();
	sleep(1);
	while(1)
	{
	int button,x,y;
	showptr();
	getmousepos(&button,&x,&y);
	if(x>265&&y>70&&x<368&&y<90&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,70,368,70," OPEN A/C ",8,7);
	delay(50);
	buttun(265,70,368,70," OPEN A/C ",7,8);
	flushall();
	input();
	break;
	}
	else if(x>265&&y>110&&x<368&&y<130&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,110,368,110,"  DEPOSIT  ",8,7);
	delay(50);
	buttun(265,110,368,110,"  DEPOSIT  ",7,8);
	deposit_withdraw("DEPOSIT","DEPOSIT AMOUNT   :",1);
	break;
	}
	else if(x>265&&y>150&&x<368&&y<170&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,150,368,150," WITHDRAW ",8,7);
	delay(50);
	buttun(265,150,368,150," WITHDRAW ",7,8);
	deposit_withdraw("WITHDRAW","WITDRAW AMOUNT   :",2);
	break;
	}
	else if(x>265&&y>190&&x<368&&y<210&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,190,368,190,"BALANCE INQ",8,7);
	delay(50);
	buttun(265,190,368,190,"BALANCE INQ",7,8);
	bankcustomer b;
	b.balance_inq();
	break;
	}
	else if(x>265&&y>230&&x<368&&y<250&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,230,368,230,"CUST INFO",8,7);
	delay(50);
	buttun(265,230,368,230,"CUST INFO",7,8);
	individual();
	break;
	}
	else if(x>265&&y>270&&x<368&&y<290&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,270,368,270,"ALL ACCOUNT",8,7);
	delay(50);
	buttun(265,270,368,270,"ALL ACCOUNT",7,8);
	all_account();
	break;
	}
	else if(x>265&&y>310&&x<368&&y<330&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,310,368,310,"MODIFY  ACC",8,7);
	delay(50);
	buttun(265,310,368,310,"MODIFY  ACC",7,8);
	bankcustomer v;
	v.modify_account();
	break;
	}
	else if(x>265&&y>350&&x<368&&y<370&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,350,368,350,"MONEY TRANS",8,7);
	delay(50);
	buttun(265,350,368,350,"MONEY TRANS",7,8);
	money_transfer();

	}
	else if(x>265&&y>390&&x<368&&y<410&&(button&1)==1)
	{
	hidemouseptr();
	buttun(265,390,368,390," CLOSE A/C ",8,7);
	delay(50);
	buttun(265,390,368,390," CLOSE A/C ",7,8);
	bankcustomer b;
	b.closeaccount();
	break;
	}
	else if(x>575&&y>445&&x<625&&y<465&&(button&1)==1)
	{
	hidemouseptr();
	buttun(575,445,625,445,"EXIT",15,8);
	delay(50);
	buttun(575,445,625,445,"EXIT",8,15);
	exit(0);
	}
	else if(x>575&&y>415&&x<625&&y<435&&(button&1)==1)
	{
	hidemouseptr();
	buttun(575,415,625,415,"HELP",15,8);
	delay(50);
	buttun(575,415,625,415,"HELP",8,15);
	help();
	}
	}}



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                              STARTING SBI
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



				void start()
				{
				int i,j;
				setbkcolor(16);
				setcolor(15);
				setfillstyle(1,15);
				bar(0,0,getmaxx(),getmaxy());
				winborder(9);
				showptr();
			      //sbi logo
			      //setbkcolor(3);
				setcolor(9);
				ellipse(100,150,0,360,90,90);
				setfillstyle(1,9);
				floodfill(100,150,9);
				setcolor(15);
				ellipse(100,150,0,360,19,19);
				setfillstyle(1,15);
				floodfill(100,150,15);
				setcolor(15);
				bar(98,155,102,240);
				setfillstyle(1,15);
				floodfill(100,150,15);
				setcolor(8);
				settextstyle(1,0,5);
				outtextxy(200,100,"State Bank of India");
				line(190,150,610,150);
				line(190,151,610,151);
				line(190,152,610,152);
				settextstyle(1,0,3);
				outtextxy(220,155,"THE BANKER TO EVERY INDIAN");
				// process bar
				buttun(450,420,500,420,"NEXT",7,8);
				setcolor(9);
				rectangle(80,350,560,370);//jj=10;
				for(i=81;i<560;i++)
				{
				rectangle(81,351,i,369);
				delay(10);
				if(i==300)
				{
				delay(15);
				//j=5;
				}}
				while(1)
				{
				getmousepos(&button,&x,&y);
				if(x>450&&y>420&&x<500&&y<440&&(button&1)==1)
				{
				buttun(450,420,500,420,"NEXT",8,7);
				delay(50);
				buttun(450,420,500,420,"NEXT",7,8);
				hidemouseptr();
				help();
				}
				}
				}







//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                     FUNCTIONS WORKING ON DATAS
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!






//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		      FUNCTION TO GET DATA FROM CUSTOMER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void input()
{
 bankcustomer c;
 newaccountinterface("OPEN NEW ACCOUNT",8,15);
 c.getalphabet(205,102,1,8,7);
 c.getalphabet(205,127,2,8,7);
 c.getalphabet(205,152,3,8,7);
 c.getdob(205,177,8,7);
 c.getgender(205,202,5,8,7);
 c.getalphabet(205,227,6,8,7);
 c.getalphabet(205,252,7,8,7);
 c.getalphabet(205,277,8,8,7);
 c.getno(205,302,9,8,7);
 c.getno(205,327,10,8,7);
 c.getalphabet(205,352,11,8,7);
 c.getactype(205,377,12,8,7);
 c.getalphabet(205,402,13,8,7);
 c.getacno();
 int button,x,y;
 showptr();
 while(1)
 {
 getmousepos(&button,&x,&y);
 if(x>450&&y>435&&x<500&&y<455&&(button&1)==1)
 {
 buttun(450,435,500,435,"EXIT",15,8);
 delay(50);
 buttun(450,435,500,435,"EXIT",8,15);
 exit(0);
 }
 else if(x>510&&y>435&&x<560&&y<455&&(button&1)==1)
 {
 hidemouseptr();
 buttun(510,435,560,435,"BACK",15,8);
 delay(50);
 buttun(510,435,560,435,"BACK",8,15);
 mainmenu();
 break;
 }
 else if(x>570&&y>435&&x<620&&y<455&&(button&1)==1)
 {
 hidemouseptr();
 buttun(570,435,620,435,"NEXT",15,8);
 delay(50);
 buttun(570,435,620,435,"NEXT",8,15);
 c.confirm();
 break;
 }}
 }






//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                    FUNCTION TO PROVIDE A/C NO TO USER
//                        & DEPOSITE INITIAL AMOUNT
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





	  void bankcustomer::confirm()
	  {
	int flag=0;
	cleardevice();
	title(15,4);
	setfillstyle(1,7);
	bar(3,28,getmaxx(),getmaxy());
	winborder(15);
	setcolor(15);
	rectangle(3,26,636,27);
	setcolor(8);
	outtextxy(100,95,"BRANCH        :");
	outtextxy(300,95,"RAJGIR");
	outtextxy(100,115,"ACCOUNT NO    :");
	setcolor(15);
	outtextxy(300,115,ano);
	setcolor(8);
	outtextxy(100,135,"I.F.S.E. NO   :");
	outtextxy(300,135,"IFSENO1234");
	outtextxy(100,155,"CUST NAME     :");
	outtextxy(300,155,name);
	outtextxy(100,185,"AMOUNT        :");
	rectangle(300,177,500,197);
	buttun(415,435,480,435,"SUBMIT",4,8);
	buttun(490,435,550,435,"CLOSE",4,8);
	getamt(310,184,1,8,7);
	showptr();
	while(1)
	{
	int button,x,y;
	getmousepos(&button,&x,&y);
	if(flag==0)
	{
	if(x>415&&y>435&&x<480&&y<455&&(button&1)==1)
	{hidemouseptr();
	buttun(415,435,480,435,"SUBMIT",8,4);
	delay(50);
	buttun(415,435,480,435,"SUBMIT",4,8);
	showptr();
	addfile(*this);
	setcolor(RED);
	settextstyle(9,0,1);
	outtextxy(80,300,"ACCOUNT SUCCESSFULLY CREATED");
	setcolor(GREEN);sleep(1);
	outtextxy(80,300,"ACCOUNT SUCCESSFULLY CREATED");
	setcolor(8);
	settextstyle(0,0,0);
	flag=1;
	}
	}
	else if(x>500&&y>435&&x<550&&y<455&&(button&1)==1)
	{hidemouseptr();
	buttun(500,435,550,435,"CLOSE",8,4);
	delay(50);
	buttun(500,435,550,435,"CLOSE",4,8);
	mainmenu();
	}
	}
	}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO STORE RECORD IN FILE
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void addfile(bankcustomer c)
{
fstream fs;
fs.open("cust1.dat",ios::app|ios::binary);
fs.write((char*)&c,sizeof(c));
fs.close();
}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                    FUNCTION TO STORE DATA FOR TRANSACTION
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!






			void bankcustomer::transaction::transact(long double m,char *t,char *n)
			{
			fstream T;
			T.open("transaction.dat",ios::app|ios::binary);
			transaction tr;
			tr.m=m;
			strcpy(tr.t,t);
			strcpy(tr.d,sysdat);
			strcpy(tr.n,n);
			T.write((char*)&tr,sizeof(tr));
			T.close();
			}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       CREATING INTERFACE & READING DATA
//                         FOR DEPOSIT AND WITHDRAW
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!






		     void deposit_withdraw(char arr[],char arr1[],int i)
			 {
			 int x,y,button;
			 cleardevice();
			 if(i==1)
			 {
			 title(8,15);
			 setfillstyle(1,2);
			 bar(3,28,getmaxx(),getmaxy());
			 winborder(8);
			 }
			 if(i==2)
			 {
			 title(8,15);
			 setfillstyle(1,5);
			 bar(3,28,getmaxx(),getmaxy());
			 winborder(8);
			 }
			 setcolor(8);
			 rectangle(3,26,636,27);
			 setcolor(15);
			 settextstyle(9,0,1);
			 buttun(400,435,450,435,"BACK",7,15);
			buttun(460,435,525,435,"SUBMIT",7,15);
			buttun(535,435,585,435,"EXIT",7,15);
			  settextstyle(9,0,1);
			 outtextxy(110,60,arr);
			 settextstyle(0,0,0);
			 setcolor(8);
			 rectangle(3,105,636,106);
			 setcolor(15);
			 outtextxy(50,150,"ACCOUNT NUMBER   :");
			 outtextxy(50,175,"CUSTOMOR NAME    :");
			 outtextxy(50,200,arr1);
			 rectangle(200,145,390,165);
			 rectangle(200,170,390,190);
			 rectangle(200,195,390,215);
			 if(i==1)
			 {
			 bankcustomer c;
			c.getno(210,152,15,15,2);
			c.getalphabet(210,177,1,15,2);
			c.getamt(210,202,3,15,2);
			 c.depositwithdraw(i);
			 mainmenu();
			 }
			 if(i==2)
			 {
			 bankcustomer c;
			 c.getno(210,152,15,15,5);
			c.getalphabet(210,177,1,15,5);
			c.getamt(210,202,3,15,5);
			 c.depositwithdraw(i);
			 mainmenu();
			 }
			}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                       CODING FOR DEPOSIT & WITHDRAW
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





			void bankcustomer::depositwithdraw(int i)
			{
			int flag=0,y=0;
			long double bal;
			bankcustomer c;
			bankcustomer c1;
			bankcustomer c2;
			buttun(400,435,450,435,"BACK",7,15);
			buttun(460,435,525,435,"SUBMIT",7,15);
			buttun(535,435,585,435,"EXIT",7,15);
			showptr();
			if(i==1||i==2)
			{
			down:
			 while(1)
			{
			getmousepos(&button,&x,&y);
			if(x>400&&y>435&&x<450&&y<455&&(button&1)==1)
			{hidemouseptr();
			buttun(400,435,450,435,"BACK",15,7);
			delay(50);
			buttun(400,435,450,435,"BACK",7,15);
			mainmenu();
			}
			else if(x>535&&y>435&&x<585&&y<455&&(button&1)==1)
			{
			buttun(535,435,585,435,"EXIT",15,7);
			delay(50);
			buttun(535,435,585,435,"EXIT",7,15);
			exit(0);
			}
			else if(x>460&&y>435&&x<525&&y<455&&(button&1)==1)
			{
			hidemouseptr();
			buttun(460,435,525,435,"SUBMIT",15,7);
			delay(50);
			buttun(460,435,525,435,"SUBMIT",7,15);
			showptr();
			if(flag==0)
			{
			flag=1;
			fstream f;
			f.open("cust1.dat",ios::in|ios::binary);
			if(!f)
			{
			 setcolor(15);
			 outtextxy(300,320,"ACCOUNT NOT FOUND");
			 setcolor(RED);sleep(1);
			 outtextxy(300,320,"ACCOUNT NOT FOUND");
			 setcolor(15);
			 flag=1;
			 goto down;
			}
			f.seekg(0,ios::beg);
			while(f.read((char*)&c1,sizeof(c1)))
			{

			if(strcmp(ano,c1.ano)==0&&strcmpi(name,c1.name)==0)
			{
			c2=c1;
			bal=c2.amt;
			if(i==1)
			{
			c2.amt=c2.amt+amt;
			bal=c2.amt;
			}
			else if(i==2&&c1.amt>=amt)
			{
			c2.amt=c2.amt-amt;
			bal=c2.amt;
			}
			else if(i==2&&c1.amt<amt)
			{
			setcolor(15);
			outtextxy(300,320,"YOU HAVE INSUFICIENT BALANCE");
			setcolor(RED);sleep(1);
			outtextxy(300,320,"YOU HAVE INSUFICIENT BALANCE");
			setcolor(15);
			goto down;
			}
			y=1;
			goto r;
			}
			}
			f.close();
			if(y!=1)
			{
			 setcolor(15);
			 outtextxy(300,320,"ACCOUNT NOT FOUND");
			 setcolor(RED);sleep(1);
			 outtextxy(300,320,"ACCOUNT NOT FOUND");
			 setcolor(15);
			 goto down;
			 }
			 r:
			 if(i==2)
			 {
			 transaction t;
			 t.transact(amt,"WITHDRAW",ano);
			 }
			 if(i==1)
			 {
			  transaction t;
			  t.transact(amt,"DEPOSITE",ano);
			 }
			f.close();
			 fstream fs;
			 fstream temp;
			 fs.open("cust1.dat",ios::in|ios::binary);
			 temp.open("temp.dat",ios::app|ios::binary);
			 fs.seekg(0,ios::beg);
			 temp.seekg(0,ios::beg);
			 while(fs.read((char*)&c,sizeof(c)))
			 {

			 if(!(strcmpi(c.name,name)==0&&strcmp(c.ano,ano)==0))
			 temp.write((char*)&c,sizeof(c));
			 }
			 temp.write((char*)&c2,sizeof(c2));
			 fs.close();
			 temp.close();
			 remove("cust1.dat");
			 rename("temp.dat","cust1.dat");
			 setcolor(RED);
			outtextxy(50,360,"AVAILABLE BALANCE :");
			outtextxy(300,320,"TRANSACTION SUCCESSFULL");
			char ba[20];
			itoa(bal,ba,10);
			outtextxy(210,360,ba);
			setcolor(15);
			sleep(1);
			outtextxy(300,320,"TRANSACTION SUCCESSFULL");
			setcolor(15);
			goto down;
			}
			}
			}
		       }
			}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                    CREATING INTERFACE & GETING DATA TO KNOW
//                       BALANCE & TRANSACTION INFORMATION
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





	      void bankcustomer::balance_inq()
	      {
	       int flag=0,fo=0;
	       cleardevice();
	       title(15,2);
	       setfillstyle(1,7);
	       bar(3,28,getmaxx(),getmaxy());
	       winborder(9);
	       settextstyle(9,0,2);
		outtextxy(150,40,"ACCOUNT STATUS");
		setcolor(9);
		rectangle(3,100,636,101);
		setcolor(8);
		settextstyle(0,0,0);
		outtextxy(50,150,"ACCOUNT NUMBER   :");
		outtextxy(50,175,"CUSTOMOR NAME    :");
		rectangle(200,145,390,165);
		rectangle(200,170,390,190);
		buttun(400,435,450,435,"BACK",4,8);
		buttun(460,435,525,435,"SUBMIT",4,8);
		buttun(535,435,585,435,"EXIT",4,8);
		bankcustomer c;
		c.getno(210,152,15,8,7);
		c.getalphabet(210,177,1,8,7);
		down:
		showptr();
		 while(1)
			{
			getmousepos(&button,&x,&y);
			if(x>400&&y>435&&x<450&&y<455&&(button&1)==1)
			{hidemouseptr();
			buttun(400,435,450,435,"BACK",8,4);
			delay(50);
			buttun(400,435,450,435,"BACK",4,8);
			mainmenu();
			}
			else if(x>535&&y>435&&x<585&&y<455&&(button&1)==1)
			{
			buttun(535,435,585,435,"EXIT",8,4);
			delay(50);
			buttun(535,435,585,435,"EXIT",4,8);
			exit(0);
			}
			else if(x>460&&y>435&&x<525&&y<455&&(button&1)==1)
			{
			hidemouseptr();
			buttun(460,435,525,435,"SUBMIT",8,4);
			delay(50);
			buttun(460,435,525,435,"SUBMIT",4,8);
			showptr();
			if(flag==0)
			 {
			  bankcustomer b;
			  fstream f;
			  f.open("cust1.dat",ios::in|ios::binary);
			  if(!f)
			{
			 n:
			 setcolor(GREEN);
			 outtextxy(400,420,"ACCOUNT NOT AVAILABLE");
			 setcolor(RED);sleep(1);
			 outtextxy(400,420,"ACCOUNT NOT AVAILABLE");
			 setcolor(8);
			 flag=1;
			 goto down;
			}
			 f.seekg(0,ios::beg);
			  while(f.read((char*)&b,sizeof(b)))
			  {
			  if(strcmp(b.ano,c.ano)==0&&strcmpi(b.name,c.name)==0)
			  {
			  fo=1;
			  hidemouseptr();
			  transaction t;
			  t.balance(c.ano,b.amt);
			  }
			  }
			  if(fo==0)
			  goto n;
			 }
			 }
			 }
			}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			      CODING TO KNOW BALANCE
//                          AND TRANSACTION INFORMATION
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





	       void bankcustomer::transaction::balance(char *no,long double bal)
	       {
	       int not=0;
	       cleardevice();
	       title(8,15);
	       setfillstyle(1,7);
	       winborder(9);
		settextstyle(9,0,2);
		outtextxy(150,35,"ACCOUNT STATUS");
		setcolor(9);
		rectangle(3,100,636,130);
		setcolor(8);
		settextstyle(0,0,0);
		setcolor(GREEN);
		outtextxy(50,110,"A/C NO :");
		outtextxy(140,110,no);
		char balance[15];
		itoa(bal,balance,10);
		outtextxy(300,110,"AVAILABLE BALANCE :");
		outtextxy(470,110,balance);
		setcolor(8);
		buttun(535,435,585,435,"EXIT",15,7);
		buttun(480,435,530,435,"BACK",15,7);
		setcolor(15);
	       outtextxy(80,150,"TRANSACTION");
	       line(80,160,169,160);
	       outtextxy(280,150,"AMOUNT");
	       line(279,160,327,160);
	       outtextxy(480,150,"DATE");
	       line(479,160,511,160);
	       int y=170;
	       transaction tr,tn;
	       fstream f;
	       f.open("transaction.dat",ios::in|ios::binary);
	       if(!f)
	       {
	       setcolor(GREEN);
	       settextstyle(9,0,1);
	       outtextxy(80,200,"NO ANY TRANSACTION DONE YET");
	       sleep(1);setcolor(RED);
	       outtextxy(80,200,"NO ANY TRANSACTION DONE YET");
	       setcolor(8);
	       settextstyle(0,0,0);
	       goto down;
	       }
	       f.seekg(0,ios::beg);
	       while(f.read((char*)&tr,sizeof(tr)))
	       {
	       if(strcmp(tr.n,no)==0)
	       {
		not=1;
		outtextxy(80,y,tr.t);
		char money[15];
		itoa(tr.m,money,10);
		outtextxy(280,y,money);
		outtextxy(480,y,tr.d);
		y=y+15;
	       }
	       }
	       if(not==0)
	       {
	       setcolor(GREEN);
	       settextstyle(9,0,1);
	       outtextxy(80,200,"NO ANY TRANSACTION DONE YET");
	       sleep(1);setcolor(RED);
	       outtextxy(80,200,"NO ANY TRANSACTION DONE YET");
	       setcolor(8);
	       settextstyle(0,0,0);
	       }
	       down:
	       showptr();
		 while(1)
			{
			getmousepos(&button,&x,&y);
			if(x>480&&y>435&&x<530&&y<455&&(button&1)==1)
			{hidemouseptr();
			buttun(480,435,530,435,"BACK",7,15);
			delay(50);
			buttun(480,435,530,435,"BACK",15,7);
			mainmenu();
			}
			else if(x>535&&y>435&&x<585&&y<455&&(button&1)==1)
			{
			hidemouseptr();
			buttun(535,435,585,435,"EXIT",7,15);
			delay(50);
			buttun(535,435,585,435,"EXIT",15,7);
			exit(0);
		     }	}

	     }


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                    INTERFACE & READING DATA
//                      FOR CUSTOMER DETAILS
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void individual()
{
 cleardevice();
 title(15,7);
 setfillstyle(1,8);
 bar(3,28,getmaxx(),getmaxy());
 winborder(15);
 setcolor(15);
 rectangle(3,26,636,27);
 settextstyle(9,0,1);
 setcolor(15);
 outtextxy(110,60,"DETAILS OF BANK CUSTOMER");
 settextstyle(0,0,0);
 setcolor(7);
 outtextxy(50,150,"ACCOUNT NUMBER   :");
 outtextxy(50,175,"CUSTOMOR NAME    :");
 rectangle(200,145,390,165);
 rectangle(200,170,390,190);
 buttun(500,435,550,435,"BACK",2,7);
 buttun(560,435,620,435,"SUBMIT",2,7);
 bankcustomer b;
 setcolor(7);
 b.getno(210,152,15,7,8);
 b.getalphabet(210,177,1,7,8);
 showptr();
 while(1)
 {
 getmousepos(&button,&x,&y);
 if(x>500&&y>435&&x<550&&y<455&&(button&1)==1)
  {
   hidemouseptr();
   buttun(500,435,550,435,"BACK",7,2);
   delay(50);
   buttun(500,435,550,435,"BACK",2,7);
   mainmenu();
  }
 else if(x>560&&y>435&&x<620&&y<455&&(button&1)==1)
 {
  hidemouseptr();
  buttun(560,435,620,435,"SUBMIT",7,2);
  delay(50);
  buttun(560,435,620,435,"SUBMIT",2,7);
  b.showindividual();
 }
}
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			 CODING TO GET CUSTOMER DETAILS
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




void bankcustomer::showindividual()
{
int flag=0;
bankcustomer c;
fstream fs;
fs.open("cust1.dat",ios::in|ios::binary);
fs.seekg(0,ios::beg);
while(!fs.eof())
{
fs.read((char*)&c,sizeof(c));
if(strcmp(ano,c.ano)==0&&strcmpi(name,c.name)==0)
{
flag=1;
newaccountinterface("DETAILS OF BANK CUSTOMER",15,4);
setfillstyle(1,7);
bar(570,435,622,457);
bar(450,435,502,457);
bar(510,435,562,457);
settextstyle(0,0,0);
outtextxy(205,105,c.name);
outtextxy(205,127,c.fname);
outtextxy(205,152,c.mname);
outtextxy(205,177,c.dob);
outtextxy(205,202,c.gender);
outtextxy(205,227,c.city);
outtextxy(205,252,c.district);
outtextxy(205,277,c.state);
outtextxy(205,302,c.pin);
outtextxy(205,327,c.mob);
outtextxy(205,352,c.nation);
outtextxy(205,377,c.actype);
outtextxy(205,402,c.varify);
break;
}
}
fs.close();
buttun(500,435,550,435,"BACK",4,15);
buttun(560,435,610,435,"EXIT",4,15);
if(flag==0)
{
setfillstyle(1,8);
bar(500,435,552,457);
bar(560,435,612,457);
buttun(500,435,550,435,"BACK",2,7);
buttun(560,435,620,435,"SUBMIT",2,7);
setcolor(RED);
settextstyle(9,0,1);
outtextxy(250,250,"ACCOUNT NOT FOUND");
settextstyle(0,0,0);
sleep(1);
setfillstyle(1,8);
bar(500,435,552,457);
bar(560,435,622,457);
buttun(500,435,550,435,"BACK",4,15);
buttun(560,435,610,435,"EXIT",4,15);
goto down;
}
down:
showptr();
while(1)
{
getmousepos(&button,&x,&y);
if(x>500&&y>435&&x<550&&y<455&&(button&1)==1)
 {
  hidemouseptr();
  buttun(500,435,550,435,"BACK",15,4);
  delay(50);
  buttun(500,435,550,435,"BACK",4,15);
   mainmenu();
  }
  else if(x>560&&y>435&&x<610&&y<455&&(button&1)==1)
 {
   hidemouseptr();
   buttun(560,435,610,435,"EXIT",15,4);
   delay(50);
   buttun(560,435,610,435,"EXIT",4,15);
   exit(0);
   }
   }
}



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                       INTERFACE OF TOTAL RECORD
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





			void all_account()
			{
			int x1,y1,prevx,prevy;
			cleardevice();
			title(15,4);
			setfillstyle(1,8);
			bar(0,28,getmaxx(),getmaxy());
			winborder(15);
			setcolor(7);
			rectangle(3,26,636,27);
			rectangle(3,60,636,61);
			setfillstyle(1,7);
			bar(3,70,636,93);
			rectangle(3,70,636,93);
			bar(3,430,636,440);
			rectangle(3,430,636,431);
			rectangle(3,440,636,441);
			setcolor(15);
			outtextxy(20,80,"NAME");
			outtextxy(160,80,"ACCOUNT NO");
			outtextxy(300,80,"A/C TYPE");
			outtextxy(400,80,"CREATED ON");
			outtextxy(510,80,"BALANCE");
			setcolor(15);
			buttun(500,445,560,445,"CLOSE",4,7);
			buttun(570,445,620,445,"NEXT",4,7);
			bankcustomer b;
			b.all(20,110);
			}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                      CODING OF DISPLAYING ALL RECORD
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





			void bankcustomer::all(int x,int y)
			{
			int n=0;
			fstream fs;
			fs.open("cust1.dat",ios::in|ios::binary);
			if(!fs)
			{
			 setcolor(GREEN);
			 settextstyle(9,0,1);
			 outtextxy(80,250,"ACCOUNT NOT FOUND");
			 sleep(1);setcolor(RED);
			 outtextxy(80,250,"ACCOUNT NOT FOUND");
			 setcolor(8);
			 settextstyle(0,0,0);
			 goto down;
			}
			fs.seekg(0,ios::beg);
			f:
			setcolor(7);
			while( fs.read((char*) this,sizeof(bankcustomer)))
			{
			outtextxy(20,y,name);
			outtextxy(160,y,ano);
			outtextxy(300,y,actype);
			outtextxy(400,y,sysdate);
			char am[20];
			itoa(amt,am,10);
			outtextxy(510,y,am);
			y=y+20;
			n++;
			if(n>=15)
			break;
			}
			down:
			 while(1)
			  { showptr();
			     getmousepos(&button,&x,&y);
			 if(x>500&&y>445&&x<560&&y<465&&(button&1)==1)
			     {   hidemouseptr();
				 buttun(500,445,560,445,"CLOSE",7,4);
				 delay(50);
				 buttun(500,445,560,445,"CLOSE",4,7);
				 mainmenu();
				 break;
			     }
			     else if(x>570&&y>445&&x<620&&y<465&&(button&1)==1)
			     {
			     hidemouseptr();
			     buttun(570,445,620,445,"NEXT",7,4);
			     delay(50);
			     buttun(570,445,620,445,"NEXT",4,7);
			     setfillstyle(1,8);
			     bar(3,94,636,429);
			     delay(100);
			     n=0;y=110;
			     x=20;
			     goto f;
			     }
			    }
			   fs.close();
			  }





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			  FUNCTION TO MODIFY RECORD
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




			 void bankcustomer::modify_account()
			 {
			 int gh=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0;
			 cleardevice();
			 title(8,15);
			 setfillstyle(1,7);
			 bar(3,28,getmaxx(),getmaxy());
			 winborder(8);
			 setcolor(8);
			 rectangle(3,26,636,27);
			 settextstyle(9,0,1);
			 setcolor(15);
			 outtextxy(110,60,"MODIFY ACCOUNT");
			 settextstyle(0,0,0);
			 outtextxy(50,150,"ACCOUNT NUMBER   :");
			 outtextxy(50,175,"CUSTOMOR NAME    :");
			 rectangle(200,145,390,165);
			 rectangle(200,170,390,190);
			 bankcustomer get;
			 bankcustomer c1;
			 bankcustomer c2;
			 bankcustomer c3;
			 y:
			 setcolor(15);
			get.getno(210,152,15,15,7);
			get.getalphabet(210,177,1,15,7);
			fstream fs;
			fs.open("cust1.dat",ios::in|ios::binary);
			if(!fs)
			{
			y1:
			setcolor(RED);
			outtextxy(200,350,"ACCOUNT NOT AVAILABLE");
			sleep(2);
			setfillstyle(1,7);
			bar(200,350,450,360);
			bar(210,152,380,162);
			bar(210,177,380,187);
			setcolor(15);
			goto y;
			}
			fs.seekg(0,ios::beg);
			while(fs.read((char*)&c1,sizeof(c1)))
			{
			if(strcmp(get.ano,c1.ano)==0&&strcmpi(get.name,c1.name)==0)
			{   gh=1;
			    newaccountinterface("MODIFY ACCOUNT",8,15);
			    outtextxy(250,80,"click in the box to modify");
			    setfillstyle(1,7);
			    bar(570,435,630,455);
			    buttun(570,435,630,435,"SUBMIT",15,8);
			    outtextxy(205,105,c1.name);
			    outtextxy(205,127,c1.fname);
			    outtextxy(205,152,c1.mname);
			    outtextxy(205,177,c1.dob);
			    outtextxy(205,202,c1.gender);
			    outtextxy(205,227,c1.city);
			    outtextxy(205,252,c1.district);
			    outtextxy(205,277,c1.state);
			    outtextxy(205,302,c1.pin);
			    outtextxy(205,327,c1.mob);
			    outtextxy(205,352,c1.nation);
			    outtextxy(205,377,c1.actype);
			    outtextxy(205,402,c1.varify);
			    break;
			  }
			 }
			     fs.close();
			     if(gh==0)
			     goto y1;
			     while(1)
			     {
			     showptr();
			     getmousepos(&button,&x,&y);
			     if(x>200&&y>95&&x<410&&y<115&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,102,408,112);
			     setcolor(8);
			     hidemouseptr();
			     c2.getalphabet(208,102,1,8,7);
			     showptr();
			     a=1;
			     }
			     else if(x>200&&y>120&&x<410&&y<140&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,127,408,137);
			     setcolor(8);
			     hidemouseptr();
			     c2.getalphabet(208,127,2,8,7);
			     showptr();
			     b=1;
			     }
			     else if(x>200&&y>145&&x<410&&y<165&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,152,408,162);
			     setcolor(8);
			     hidemouseptr();
			     c2.getalphabet(208,152,3,8,7);
			     showptr();
			     c=1;
			     }
			     else if(x>200&&y>170&&x<410&&y<190&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,177,408,187);
			     setcolor(8);
			     hidemouseptr();
			     c2.getdob(206,177,8,7);
			     showptr();
			     d=1;
			     }
			     else if(x>200&&y>195&&x<410&&y<215&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,202,408,212);
			     setcolor(8);
			     hidemouseptr();
			     c2.getgender(206,202,5,8,7);
			     showptr();
			     e=1;
			     }
			     else if(x>200&&y>220&&x<410&&y<240&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,227,408,237);
			     setcolor(8);
			     hidemouseptr();
			     c2.getalphabet(206,227,6,8,7);
			     showptr();
			     f=1;
			     }
			     else if(x>200&&y>245&&x<410&&y<265&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,252,408,262);
			     setcolor(8);
			     hidemouseptr();
			     c2.getalphabet(206,252,7,8,7);
			     showptr();
			     g=1;
			     }
			     else if(x>200&&y>270&&x<410&&y<290&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,277,408,287);
			     setcolor(8);
			     hidemouseptr();
			     c2.getalphabet(206,277,8,8,7);
			     showptr();
			     h=1;
			     }
			     else if(x>200&&y>295&&x<410&&y<315&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,302,408,312);
			     setcolor(8);
			     hidemouseptr();
			     c2.getno(206,302,9,8,7);
			     showptr();
			     i=1;
			     }
			     else if(x>200&&y>320&&x<410&&y<340&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,327,408,337);
			     setcolor(8);
			     hidemouseptr();
			     c2.getno(206,327,10,8,7);
			     showptr();
			     j=1;
			     }
			     else if(x>200&&y>345&&x<410&&y<365&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,352,408,362);
			     setcolor(8);
			     hidemouseptr();
			     c2.getalphabet(206,352,11,8,7);
			     showptr();
			     k=1;
			     }
			     else if(x>200&&y>370&&x<410&&y<390&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,377,408,387);
			     setcolor(8);
			     hidemouseptr();
			     c2.getactype(206,352,12,8,7);
			     showptr();
			     l=1;
			     }
			     else if(x>200&&y>395&&x<410&&y<415&&(button&1)==1)
			     {
			     setfillstyle(1,7);
			     bar(205,402,408,412);
			     setcolor(8);
			     hidemouseptr();
			     c2.getalphabet(206,402,13,8,7);
			     showptr();
			     m=1;
			     }
			     else if(x>450&&y>435&&x<500&&y<455&&(button&1)==1)
			     {
			     buttun(450,435,500,435,"EXIT",8,15);
			     delay(50);
			     buttun(450,435,500,435,"EXIT",15,8);
			     exit(0);
			     }
			     else if(x>510&&y>435&&x<560&&y<455&&(button&1)==1)
			     {
				 hidemouseptr();
				 buttun(510,435,560,435,"BACK",8,15);
				 delay(50);
				 buttun(510,435,560,435,"BACK",15,8);
				 hidemouseptr();
				 mainmenu();
				 break;
			     }
			     else if(x>570&&y>435&&x<630&&y<455&&(button&1)==1)
			     {
			     buttun(570,435,630,435,"SUBMIT",8,15);
			     delay(50);
			     buttun(570,435,630,435,"SUBMIT",15,8);
			     if(a==1)
			     strcpy(c3.name,c2.name);
			     else
			     strcpy(c3.name,c1.name);
			     if(b==1)
			     strcpy(c3.fname,c2.fname);
			     else
			     strcpy(c3.fname,c1.fname);
			     if(c==1)
			     strcpy(c3.mname,c2.mname);
			     else
			     strcpy(c3.mname,c1.mname);
			     if(d==1)
			     strcpy(c3.dob,c2.dob);
			     else
			     strcpy(c3.dob,c1.dob);
			     if(e==1)
			     strcpy(c3.gender,c2.gender);
			     else
			     strcpy(c3.gender,c1.gender);
			     if(f==1)
			     strcpy(c3.city,c2.city);
			     else
			     strcpy(c3.city,c1.city);
			     if(g==1)
			     strcpy(c3.district,c2.district);
			     else
			     strcpy(c3.district,c1.district);
			     if(h==1)
			     strcpy(c3.state,c2.state);
			     else
			     strcpy(c3.state,c1.state);
			     if(i==1)
			     strcpy(c3.pin,c2.pin);
			     else
			     strcpy(c3.pin,c1.pin);
			     if(j==1)
			     strcpy(c3.mob,c2.mob);
			     else
			     strcpy(c3.mob,c1.mob);
			     if(k==1)
			     strcpy(c3.nation,c2.nation);
			     else
			     strcpy(c3.nation,c1.nation);
			     if(l==1)
			     strcpy(c3.actype,c2.actype);
			     else
			     strcpy(c3.actype,c1.actype);
			     if(m==1)
			     strcpy(c3.varify,c2.varify);
			     else
			     strcpy(c3.varify,c1.varify);
			     c3.amt=c1.amt;
			     strcpy(c3.ano,c1.ano);
			     strcpy(c3.sysdate,c1.sysdate);
			     bankcustomer data;
			     fstream fs1;
			     fs1.open("temp.dat",ios::app|ios::binary);
			     fs1.seekg(0,ios::beg);
			     fs.open("cust1.dat",ios::in|ios::binary);
			     fs.seekg(0,ios::beg);
			     while(fs.read((char*)&data,sizeof(data)))
			     {

			     if(!(strcmpi(get.name,data.name)==0&&strcmp(get.ano,data.ano)==0))
			     fs1.write((char*)&data,sizeof(data));
			     }
			    fs1.write((char*)&c3,sizeof(c3));
			    fs.close();
			    fs1.close();
			    remove("cust1.dat");
			    rename("temp.dat","cust1.dat");
			    setcolor(RED);
			    outtextxy(400,420,"SUCCESSFULLY MODIFIED");
			    setcolor(GREEN);sleep(1);
			    outtextxy(400,420,"SUCCESSFULLY MODIFIED");
			    }
			    }
			  }





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			  INTERFACE & DATA READING
//                         TASK FOR MONEY TRANSFER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




void money_transfer()
{
cleardevice();
title(15,7);
setfillstyle(1,6);
bar(3,28,getmaxx(),getmaxy());
winborder(15);
settextstyle(9,0,1);
setcolor(7);
outtextxy(180,30,"MONEY TRANSER");
rectangle(3,80,6,81);
settextstyle(1,0,2);
rectangle(3,80,676,81);
rectangle(35,260,400,261);
rectangle(35,110,400,111);
setcolor(8);
outtextxy(100,85,"FROM");
outtextxy(100,235,"TO");
settextstyle(0,0,0);
setcolor(15);
rectangle(3,26,636,27);
outtextxy(50,136,"ACCOUNT NUMBER:");
outtextxy(50,176,"CUSTOMER NAME :");
outtextxy(50,216,"AMOUNT        :");
rectangle(200,130,390,150);
rectangle(200,170,390,190);
rectangle(200,210,390,230);
rectangle(200,280,390,300);
rectangle(200,320,390,340);
outtextxy(50,286,"ACCOUNT NUMBER:");
outtextxy(50,326,"CUSTOMER NAME :");
bankcustomer bv;
bv.transfer();
mainmenu();
}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			   CODING OF MONEY TRANSFER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





			void bankcustomer::transfer()
			{
			int flag=0;
			long double bal;
			buttun(400,435,450,435,"BACK",7,15);
			buttun(460,435,525,435,"SUBMIT",7,15);
			buttun(535,435,585,435,"EXIT",7,15);
			bankcustomer c;
			bankcustomer c1;
			bankcustomer c2;
			bankcustomer b1;
			bankcustomer b;
			bankcustomer b2;
			setcolor(15);
			c.getno(210,138,15,15,6);
			c.getalphabet(210,178,1,15,6);
			c.getamt(210,218,3,15,6);
			b.getno(210,288,15,15,6);
			b.getalphabet(210,328,1,15,6);
			showptr();
			down:
			 while(1)
			{
			getmousepos(&button,&x,&y);
			if(x>400&&y>435&&x<450&&y<455&&(button&1)==1)
			{hidemouseptr();
			buttun(400,435,450,435,"BACK",15,7);
			delay(50);
			buttun(400,435,450,435,"BACK",7,15);
			return;
			}
			else if(x>535&&y>435&&x<585&&y<455&&(button&1)==1)
			{
			buttun(535,435,585,435,"EXIT",15,7);
			delay(50);
			buttun(535,435,585,435,"EXIT",7,15);
			exit(0);
			}
			else if(x>460&&y>435&&x<525&&y<455&&(button&1)==1)
			{
			hidemouseptr();
			buttun(460,435,525,435,"SUBMIT",15,7);
			delay(50);
			buttun(460,435,525,435,"SUBMIT",7,15);
			showptr();
			if(flag==0)
			{
			flag=1;
			fstream f;
			f.open("cust1.dat",ios::in|ios::binary);
			if(!f)
			{
			 setcolor(GREEN);
			 outtextxy(400,420,"ACCOUNT NOT FOUND");
			 setcolor(RED);sleep(1);
			 outtextxy(400,420,"ACCOUNT NOT FOUND");
			 setcolor(8);
			 flag=1;
			 goto down;
			}
			f.seekg(0,ios::beg);
			while(f.read((char*)&c1,sizeof(c1)))
			{
			if(strcmp(c.ano,c1.ano)==0&&strcmpi(c.name,c1.name)==0)
			{
			c2=c1;
			bal=c2.amt;
			if(c2.amt>=c.amt)
			{
			c2.amt=c2.amt-c.amt;
			bal=c2.amt;
			goto r;
			}
			else
			{
			setcolor(GREEN);
			outtextxy(400,420,"YOU HAVE INSUFICIENT BALANCE");
			setcolor(RED);sleep(1);
			outtextxy(400,420,"YOU HAVE INSUFICIENT BALANCE");
			goto down;
			}
			}
			}
			setcolor(GREEN);
			 outtextxy(400,420,"ACCOUNT NOT FOUND");
			 setcolor(RED);sleep(1);
			 outtextxy(400,420,"ACCOUNT NOT FOUND");
			 setcolor(15);
			 flag=1;
			 goto down;

			 r:
			f.close();
			fstream f1;
			f1.open("cust1.dat",ios::in|ios::binary);
			if(!f1)
			{
			setcolor(GREEN);
			 outtextxy(400,420,"ACCOUNT NOT FOUND");
			 setcolor(RED);sleep(1);
			 outtextxy(400,420,"ACCOUNT NOT FOUND");
			 setcolor(15);
			 flag=1;
			 goto down;
			}
			transaction t;
			t.transact(c.amt,"M_TRANSFER",c.ano);
			f1.seekg(0,ios::beg);
			while(f1.read((char*)&b1,sizeof(b1)))
			{
			if(strcmp(b.ano,b1.ano)==0&&strcmpi(b.name,b1.name)==0)
			{
			b2=b1;
			b2.amt=b2.amt+c.amt;
			transaction t1;
			t1.transact(c.amt,"M_CREDIT",b.ano);
			goto r1;
			}
			}
			setcolor(GREEN);
			 outtextxy(400,420,"ACCOUNT NOT FOUND");
			 setcolor(RED);sleep(1);
			 outtextxy(400,420,"ACCOUNT NOT FOUND");
			 setcolor(15);
			 flag=1;
			 goto down;

			r1:
			f1.close();
			 fstream fs;
			 fstream temp;
			 fs.open("cust1.dat",ios::in|ios::binary);
			 temp.open("temp.dat",ios::app|ios::binary);
			 fs.seekg(0,ios::beg);
			 temp.seekg(0,ios::beg);
			 while(fs.read((char*)&c1,sizeof(c1)))
			 {
			 if(!(strcmpi(c1.name,c.name)==0&&strcmp(c1.ano,c.ano)==0))
			 temp.write((char*)&c1,sizeof(c1));
			 }
			 temp.write((char*)&c2,sizeof(c2));
			 fs.close();
			 temp.close();
			 remove("cust1.dat");
			 rename("temp.dat","cust1.dat");
			 fs.open("cust1.dat",ios::in|ios::binary);
			 temp.open("temp.dat",ios::app|ios::binary);
			 fs.seekg(0,ios::beg);
			 temp.seekg(0,ios::beg);
			 while(fs.read((char*)&b1,sizeof(b1)))
			 {
			 if(!(strcmpi(b1.name,b.name)==0&&strcmp(b1.ano,b.ano)==0))
			 temp.write((char*)&b1,sizeof(b1));
			 }
			 temp.write((char*)&b2,sizeof(b2));
			 fs.close();
			 temp.close();
			 remove("cust1.dat");
			 rename("temp.dat","cust1.dat");
			 setcolor(RED);
			 outtextxy(400,420,"TRANSACTION SUCCESSFULL");
			outtextxy(50,400,"AVAILABLE BALANCE :");
			char ba[20];
			itoa(bal,ba,10);
			outtextxy(210,400,ba);
			sleep(1);setcolor(GREEN);
			outtextxy(400,420,"TRANSACTION SUCCESSFULL");
			setcolor(15);
			goto down;
			 }
			}
			}
			}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			 FUNCTION TO CLOSE ACCOUNT
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




void bankcustomer::closeaccount()
{
 int flag=0,fl=0;
 cleardevice();
 title(8,15);
 setfillstyle(1,8);
 bar(3,28,getmaxx(),getmaxy());
 setcolor(7);
 rectangle(3,26,636,27);
 winborder(7);
 setcolor(GREEN);
 settextstyle(9,0,1);
 outtextxy(110,60,"CLOSING OF ACCOUNT");
 setcolor(7);
 settextstyle(0,0,0);
 outtextxy(50,150,"ACCOUNT NUMBER   :");
 outtextxy(50,175,"CUSTOMOR NAME    :");
 rectangle(200,145,390,165);
 rectangle(200,170,390,190);
 buttun(400,435,450,435,"BACK",2,7);
 buttun(460,435,525,435,"SUBMIT",2,7);
 buttun(535,435,585,435,"EXIT",2,7);
 setcolor(7);
 bankcustomer b,b1;
 b.getno(210,152,15,7,8);
 b.getalphabet(210,177,1,7,8);
 showptr();
 down:
 while(1)
 {
 getmousepos(&button,&x,&y);
 if(x>400&&y>435&&x<450&&y<455&&(button&1)==1)
 {hidemouseptr();
 buttun(400,435,450,435,"BACK",7,2);
 delay(50);
 buttun(400,435,450,435,"BACK",2,7);
 mainmenu();
 }
 else if(x>535&&y>435&&x<585&&y<455&&(button&1)==1)
 {
 buttun(535,435,585,435,"EXIT",7,2);
 delay(50);
 buttun(535,435,585,435,"EXIT",2,7);
 exit(0);
 }
 else if(x>460&&y>435&&x<525&&y<455&&(button&1)==1)
 {
 hidemouseptr();
 buttun(460,435,525,435,"SUBMIT",7,2);
 delay(50);
 buttun(460,435,525,435,"SUBMIT",2,7);
 showptr();
 if(flag==0)
 {
 flag=1;
 fstream f,temp;
 f.open("cust1.dat",ios::in|ios::binary);
 if(!f)
 {
  n:
  setcolor(GREEN);
  settextstyle(9,0,1);
  outtextxy(80,220,"ACCOUNT NOT FOUND");
  setcolor(RED);sleep(1);
  outtextxy(80,220,"ACCOUNT NOT FOUND");
  setcolor(8);
  settextstyle(0,0,0);
  flag=1;
  goto down;
 }
 temp.open("temp.dat",ios::app|ios::binary);
 f.seekg(0,ios::beg);
 temp.seekg(0,ios::beg);
 while(f.read((char*)&b1,sizeof(b1)))
 {
 if(!(strcmp(b1.ano,b.ano)==0&&strcmpi(b1.name,b.name)==0))
  temp.write((char*)&b1,sizeof(b1));
 else
 fl=1;
 }
 f.close();
 temp.close();
 remove("cust1.dat");
 rename("temp.dat","cust1.dat");
 if(fl==0)
 goto n;
 else
 {
  setcolor(RED);
  settextstyle(9,0,1);
  outtextxy(80,220,"ACCOUNT SUCCESSFUL DELETED");
  setcolor(GREEN);sleep(1);
  outtextxy(80,220,"ACCOUNT SUCCESSFUL DELETED");
  setcolor(8);
  settextstyle(0,0,0);
 }
 }
 }
 }
 }






//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                      FUNCTIONS DEFINITION OF CLASS
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO CHECK ERROR RELATED TO
//                            ALPHABET TYPE VALUE
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





int bankcustomer::checkalphabet(char *ch)
 {
 int l,i,a=0;
 l=strlen(ch);
 for(i=0;i<l;i++)
 {
 if(isalpha(ch[i])||ch[i]==32)
 a=1;
 else
 {
 a=0;
 break;
 }
 }
 return a;
 }




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		          FUNCTION TO HANDLE ERROR
//                      BASED ON UNIVERSAL TYPE DATA
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void bankcustomer::error(int x,int y,int p,int text,int back)
 {
    setcolor(4);
    if(p==1||p==2||p==3||p==13)
    outtextxy(x+250,y,"Invalid Name");
    else if(p==5)
    outtextxy(x+250,y,"Invalid Gender");
    else if(p==6)
    outtextxy(x+250,y,"Not A City Name");
    else if(p==7)
    outtextxy(x+250,y,"Only Alphabet Valid");
    else if(p==8)
    outtextxy(x+250,y,"State Not Found");
    else if(p==9)
    outtextxy(x+250,y,"Invalid Pin Code");
    else if(p==10)
    outtextxy(x+250,y,"Invalid mob No");
    else if(p==11)
    outtextxy(x+250,y,"Invalid Nationality");
    else if(p==12)
    outtextxy(x+250,y,"Saving/Current");
    else if(p==15)
    outtextxy(x+250,y,"A/C No Not Valid");
    delay(1000);
    setfillstyle(1,back);
    bar(x,y,x+170,y+10);
    bar(x+250,y,x+400,y+10);
    setcolor(text);
 }





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO GET ALPHABET TYPE DATA
//                                FROM USER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





 void bankcustomer::getalphabet(int x,int y,int p,int text,int back)
 {
  int i=x,j=y,pos=0;
  char ch[2],c[100];
   while(1)
  {
  ch[0]=getch();
  ch[1]='\0';
  if(ch[0]==13)
  {
  c[pos]='\0';
  if(checkalphabet(c)==1)
   {
     if(p==1)
     strcpy(name,c);
     else if(p==2)
     strcpy(fname,c);
     else if(p==3)
     strcpy(mname,c);
     else if(p==6)
     strcpy(city,c);
     else if(p==7)
     strcpy(district,c);
     else if(p==8)
     strcpy(state,c);
     else if(p==11)
     strcpy(nation,c);
     else if(p==13)
     strcpy(varify,c);
     return;
   }
  else
  error(x,y,p,text,back);
  pos=0;c[pos]='\0';
  i=x;j=y;
  }
  else if(ch[0]==27)
  {
  c[pos]='\0';
  mainmenu();
  }
  else if(ch[0]==9)
  {
     c[pos]='\0';
     if(checkalphabet(c)==1)
     {
     if(p==1)
     strcpy(name,c);
     else if(p==2)
     strcpy(fname,c);
     else if(p==3)
     strcpy(mname,c);
     else if(p==6)
     strcpy(city,c);
     else if(p==7)
     strcpy(district,c);
     else if(p==8)
     strcpy(state,c);
     else if(p==11)
     strcpy(nation,c);
     else if(p==13)
     strcpy(varify,c);
     return;
     }
    else
    {
    error(x,y,p,text,back);
    pos=0;c[pos]='\0';
    i=x;j=y;
    }
  }
  else if(ch[0]==8)
  {
  if(i>x)
  {
  i=i-8;
  c[--pos]='\0';
  setfillstyle(1,back);
  bar(i,j,i+8,j+10);
  }
  }
  else
  {
  if(i<x+200)
  {
  outtextxy(i,j,ch);
  c[pos]=ch[0];
  pos++;i=i+8;
  }
  }
  }
 }




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO HANDLE ERROR BASED ON
//                               DATE OF BIRTH
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





 void bankcustomer::doberror(int text,int back)
 {
 setfillstyle(1,back);
 bar(450,177,630,187);
 setcolor(4);
 outtextxy(450,177,"Invalid Date Formate");
 delay(1000);
 setfillstyle(1,back);
 bar(450,177,638,187);
 bar(205,177,400,187);
 setcolor(text);
 outtextxy(450,177,"DD-MM-YYYY");
 }




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO CHECK DATE TYPE VALUE
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





int bankcustomer::finaldate(char *dob)
{
  char ch1[10],ch2[10],ch3[10];
 ch1[0]=dob[0];ch1[1]=dob[1];ch1[2]='\0';
 ch2[0]=dob[3];ch2[1]=dob[4];ch2[2]='\0';
 ch3[0]=dob[6];ch3[1]=dob[7];ch3[2]=dob[8];ch3[3]=dob[9];ch3[4]='\0';
 int d,m,y;
 d=atoi(ch1); m=atoi(ch2);y=atoi(ch3);
 if(d>0&&d<32&&m>0&&m<13&&y>1900)
 return 1;
 else
 return 0;
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO CHECK ERROR IN
//                          IN DATE TYPE DATA
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




int bankcustomer::checkdob(char *date)
 {
 int l,flag=0;
 l=strlen(date);
 if(l==10||l==9||l==8)
 {
 for(int i=0;i<=l-1;i++)
 {
 char c=date[i];
 if(c>=48&&c<=57||c==45||c==47)
 flag=1;
 else
 return 0;
 }
 if(flag==1)
 {
 if(l==8)
 {
 if(date[1]==45||date[1]==47&&date[3]==45||date[3]==47)
  {
  dob[0]=48;
  dob[1]=date[0];
  dob[2]=45;
  dob[3]=48;
  dob[4]=date[2];
  dob[5]=45;
  dob[6]=date[4];
  dob[7]=date[5];
  dob[8]=date[6];
  dob[9]=date[7];
  dob[10]='\0';
 int b=finaldate(dob);
 if(b==1)
  return 1;
  else
  return 0; // b;
  }
  else
  return 0;
  }
  else if(l==9)
  {
  if(date[1]==45||date[1]==47&&date[4]==45||date[4]==47)
  {
  dob[0]=48;
  dob[1]=date[0];
  dob[2]=45;
  dob[3]=date[2];
  dob[4]=date[3];
  dob[5]=45;
  dob[6]=date[5];
  dob[7]=date[6];
  dob[8]=date[7];
  dob[9]=date[8];
  dob[10]='\0';
  int b=finaldate(dob);
  if(b==1)
  return 1;//b;
  else
  return 0;
  }
  else if(date[2]==45||date[2]==47&&date[4]==45||date[4]==47)
  {
  dob[0]=date[0];
  dob[1]=date[1];
  dob[2]=45;
  dob[3]=48;
  dob[4]=date[3];
  dob[5]=45;
  dob[6]=date[5];
  dob[7]=date[6];
  dob[8]=date[7];
  dob[9]=date[8];
  dob[10]='\0';
  int b=finaldate(dob);
  if(b==1)
  return 1;//b;
  else
  return 0;
  }
  else
  return 0;
  }
  else if(l==10)
  {
  if(date[2]==45||date[2]==47&&date[5]==45||date[5]==47)
  {
  strcpy(dob,date);
  int b=finaldate(dob);
  if(b==1)
  return 1;//b;
  else
  return 0;
  }
  else
  return 0;
  }
 else
 return 0;
 }
}
return 0;
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO GET DATE OF BIRTH
//                                FROM USER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void bankcustomer::getdob(int x,int y,int text,int back)
{
 strcpy(sysdate,sysdat);
 outtextxy(450,177,"DD-MM-YYYY");
 int i,j,pos=0;
 char date[30],ch[2];
 i=x,j=y;
 while(1)
 {
  ch[0]=getch();
  ch[1]='\0';
  if(ch[0]==13)
  {
  date[pos]='\0';
   if(checkdob(date)==1)
  {
  setfillstyle(1,back);
  bar(450,177,600,187);
  return;
  }
  else
  doberror(text,back);
  pos=0;date[pos]='\0';
  i=x;
  }
  else if(ch[0]==27)
  {
  date[pos]='\0';
  mainmenu();
  }
  else if(ch[0]==9)
  {
     date[pos]='\0';
     if(checkdob(date)==1)
     {
      setfillstyle(1,back);
      bar(450,177,600,187);
     return ;
     }
    else
    {
    doberror(text,back);
    pos=0;date[pos]='\0';
    i=x;
    }
  }
  else if(ch[0]==8)
  {
  if(i>x)
  {
  i=i-8;
  date[--pos]='\0';
  setfillstyle(1,back);
  bar(i,j,i+8,j+10);
  }
  }
  else
  {
  if(i<x+200)
  {
  outtextxy(i,j,ch);
  date[pos]=ch[0];
  pos++;i=i+8;
  }
  }
  }
 }


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO CHECK ERROR IN
//                          GENDER TYPE DATA
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





int bankcustomer::checkgender(char *g)
{
if(strcmpi(g,"male")==0||strcmpi(g,"female")==0||strcmpi(g,"other")==0)
return 1;
else
return 0;
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		    FUNCTION TO READ INFORMATION
//                     FROM USER ABOUT GENDER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void bankcustomer::getgender(int x,int y,int p,int text,int back)
{
  int i=x,j=y,pos=0;
  char ch[2],c[30];
   while(1)
  {
  ch[0]=getch();
  ch[1]='\0';
  if(ch[0]==13)
  {
  c[pos]='\0';
  if(checkgender(c)==1)
  {
  strcpy(gender,c);
  return;
  }
  else
  error(x,y,p,text,back);
  pos=0;c[pos]='\0';
  i=x;j=y;
  }
  else if(ch[0]==27)
  {
  c[pos]='\0';
  mainmenu();
  }
  else if(ch[0]==9)
  {
     c[pos]='\0';
     if(checkgender(c)==1)
     {
     strcpy(gender,c);
     return ;
     }
    else
    {
    error(x,y,p,text,back);
    pos=0;c[pos]='\0';
    i=x;j=y;
    }
  }
  else if(ch[0]==8)
  {
  if(i>x)
  {
  i=i-8;
  c[--pos]='\0';
  setfillstyle(1,back);
  bar(i,j,i+8,j+10);
  }
  }
  else
  {
  if(i<x+200)
  {
  outtextxy(i,j,ch);
  c[pos]=ch[0];
  pos++;i=i+8;
  }
  }
 }
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO CHECK ERROR IN
//                           NUMBER TYPE DATA
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





int bankcustomer::checkno(char *c,int p)
{
int l,i;
l=strlen(c);
for(i=0;i<l;i++)
{
if(c[i]>=48&&c[i]<=57)
continue;
else
return 0;
}
if(p==9&&l==6||p==10&&l==10||p==15&&l==11)
return 1;
else
return 0;
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO READ NUMBER TYPE
//                            DATA FROM USER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




void bankcustomer::getno(int x,int y,int p,int text,int back)
{
  int i=x,j=y,pos=0;
  char ch[2],c[30];
   while(1)
  {
  ch[0]=getch();
  ch[1]='\0';
  if(ch[0]==13)
  {
  c[pos]='\0';
  if(checkno(c,p)==1)
  {
  if(p==9)
  strcpy(pin,c);
  else if(p==10)
  strcpy(mob,c);
  else if(p==15)
  strcpy(ano,c);
  return;
  }
  else
  error(x,y,p,text,back);
  pos=0;c[pos]='\0';
  i=x;j=y;
  }
  else if(ch[0]==27)
  {
  c[pos]='\0';
  mainmenu();
  }
  else if(ch[0]==9)
  {
     c[pos]='\0';
     if(checkno(c,p)==1)
     {
     if(p==9)
     strcpy(pin,c);
     else if(p==10)
     strcpy(mob,c);
     else if(p==15)
     strcpy(ano,c);
     return;
     }
    else
    {
    error(x,y,p,text,back);
    pos=0;c[pos]='\0';
    i=x;j=y;
    }
  }
  else if(ch[0]==8)
  {
  if(i>x)
  {
  i=i-8;
  c[--pos]='\0';
  setfillstyle(1,back);
  bar(i,j,i+8,j+10);
  }
  }
  else
  {
  if(i<x+200)
  {
  outtextxy(i,j,ch);
  c[pos]=ch[0];
  pos++;i=i+8;
  }
  }
 }
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		     FUNCTION TO CHECK A/C TYPE INFORMATION
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




int checkactype(char *c)
{
if(strcmpi(c,"saving")==0||strcmpi(c,"current")==0)
return 1;
else
return 0;
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	        FUNCTION TO GET A/C TYPE INFORMATION FROM USER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void bankcustomer::getactype(int x,int y,int p,int text,int back)
{
  int i=x,j=y,pos=0;
  char ch[2],c[30];
   while(1)
  {
  ch[0]=getch();
  ch[1]='\0';
  if(ch[0]==13)
  {
  c[pos]='\0';
  if(checkactype(c)==1)
  {
  strcpy(actype,c);
  return;
  }
  else
  error(x,y,p,text,back);
  pos=0;c[pos]='\0';
  i=x;j=y;
  }
  else if(ch[0]==27)
  {
  c[pos]='\0';
  mainmenu();
  }
  else if(ch[0]==9)
  {
     c[pos]='\0';
     if(checkactype(c)==1)
     {
     strcpy(actype,c);
     return ;
     }
    else
    {
    error(x,y,p,text,back);
    pos=0;c[pos]='\0';
    i=x;j=y;
    }
  }
  else if(ch[0]==8)
  {
  if(i>x)
  {
  i=i-8;
  c[--pos]='\0';
  setfillstyle(1,back);
  bar(i,j,i+8,j+10);
  }
  }
  else
  {
  if(i<x+200)
  {
  outtextxy(i,j,ch);
  c[pos]=ch[0];
  pos++;i=i+8;
  }
  }
 }
}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO GENERATE UNIQUE A/C NO
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void bankcustomer::getacno()
{
int a,b,c,d,e,f,g;
char a1[5],b1[5],c1[5],d1[5],e1[5],f1[5],g1[5];
randomize();
a=rand();
b=rand();
c=rand();
d=rand();
e=rand();
f=rand();
g=rand();
itoa(a,a1,10);itoa(b,b1,10);itoa(c,c1,10);itoa(d,d1,10);itoa(e,e1,10);
itoa(f,f1,10);itoa(g,g1,10);
char acno[13]={'3','0','9','7',a1[0],b1[0],c1[0],d1[0],e1[0],f1[0],g1[0]};
strcpy(ano,acno);
}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO CHECK AMOUNT
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





int bankcustomer::checkamt(char c[],int p)
{
int l,i;
l=strlen(c);
for(i=0;i<l;i++)
{
if(!(c[i]>=48&&c[i]<=57||c[i]=='.'))
return 0;
}
long double n=atof(c);
if(n>=1000&&p==1)
return 1;
else if(p==3)
return 3;
else
return 2;
}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		   FUNCTION TO HANDLE ERROR RELATED TO AMOUNT
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





void bankcustomer::amterror(int x,int y,int p,int text,int back)
{
 setcolor(4);
 if(p==0)
 outtextxy(x-200,y+150,"Invalid Amount");
 else if(p==2)
 {
 setcolor(RED);
 outtextxy(x-200,y+150,"Initial Amount Must Be Atleast 1000");
 setcolor(GREEN);
 sleep(1);
 outtextxy(x-200,y+150,"Initial Amount Must Be Atleast 1000");
 setcolor(text);
 }
 else if(p==3)
 {
 outtextxy(x+200,y,"Invalid Amount");
 sleep(1);
 setfillstyle(1,back);
 bar(x,y-2,x+165,y+8);
 bar(x+200,y,x+350,y+10);
 setcolor(text);
 return;
 }
 sleep(1);
 setfillstyle(1,back);
 bar(x-200,y+150,x+90,y+160);
 bar(x,y-2,x+160,y+8);
 setcolor(text);
}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		       FUNCTION TO GET AMOUNT FOR
//                        DEPOSITE OR WITHDRAW
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!






void bankcustomer::getamt(int x,int y,int p,int text,int back)
{
 int i=x,j=y,pos=0,ck;
  char ch[2],c[30];
   while(1)
  {
  ch[0]=getch();
  ch[1]='\0';
  if(ch[0]==13)
  {
  c[pos]='\0';
  ck=checkamt(c,p);
  if(ck==1||ck==3)
  {
  amt=atof(c);
  return;
  }
  else
  amterror(x,y,ck,text,back);
  pos=0;c[pos]='\0';
  i=x;j=y;
  }
  else if(ch[0]==27)
  {
  c[pos]='\0';
  if(p==1)
  hidemouseptr();
  mainmenu();
  }
  else if(ch[0]==9)
  {
     c[pos]='\0';
     ck=checkamt(c,p);
     if(ck==1||ck==3)
     {
     amt=atof(c);
     return ;
     }
    else
    {
    amterror(x,y,ck,text,back);
    pos=0;c[pos]='\0';
    i=x;j=y;
    }
  }
  else if(ch[0]==8)
  {
  if(i>x)
  {
  i=i-8;
  c[--pos]='\0';
  setfillstyle(1,back);
  bar(i,j,i+8,j+10);
  }
  }
  else
  {
  if(i<x+200)
  {
  setcolor(text);
  outtextxy(i,j,ch);
  c[pos]=ch[0];
  pos++;i=i+8;
  }
  }
 }

}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		        FUNCTION TO GET SYSTEM DATE
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





 char* date()
 {
 int d1,m1,y1;
 char c1[5],c2[5],c3[5];
 struct date d;
	getdate(&d);
	d1 =d.da_day ;itoa(d1,c1,10);
	m1 =d.da_mon ;itoa(m1,c2,10);
	y1 =d.da_year ; itoa(y1,c3,10);
	if(d1<10)
	{
	sysdat[0]='0';
	sysdat[1]=c1[0];
	}
	else
	{
	sysdat[0]=c1[0];
	sysdat[1]=c1[1];
	}
	sysdat[2]='/';
	if(m1<10)
	{
	sysdat[3]='0';
	sysdat[4]=c2[0];
	}
	else
	{
	sysdat[3]=c2[0];
	sysdat[4]=c2[1];
	}
	sysdat[5]='/';
	sysdat[6]=c3[0];
	sysdat[7]=c3[1];
	sysdat[8]=c3[2];
	sysdat[9]=c3[3];
	sysdat[10]='\0';
	return sysdat;
	}





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//				 MAIN FUNCTION
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


		void main(void)
		{
		int gdriver = DETECT, gmode, errorcode;
		initgraph(&gdriver, &gmode, "..//bgi");
		setbkcolor(16);
		setfillstyle(1,15);
		bar(0,0,getmaxx(),getmaxy());
		setcolor(15);
		int x,y,button;
		mouseinit();
		ristrictmouseptr();
		welcome();
		start();
		}
