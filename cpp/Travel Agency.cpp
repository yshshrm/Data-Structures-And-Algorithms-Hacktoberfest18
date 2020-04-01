/*****************************/
/*   PROJECT TRAVEL AGENCY   */
/*****************************/

/*************************/
/* INCLUDED HEADER FILES */
/*************************/
#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
/*******************************************************************/
//	   THIS CLASS CONTAIN ALL THE FUNCTION RELATED TO TICKET
//	   LIKE RESERVATION, DELETION, ETC.
/*******************************************************************/
class TRAVEL
{
public :
void INFORMATION(void) ;
void RESERVATION(void) ;
int  RESERVED(int,int,int,int,int) ;
int  AVAIL(int,int,int,int) ;
void DELETION(void) ;
void LIST_OF_PASS(void) ;
void PASS_INFO(void) ;
void MAINMENU(void)  ;
private :
int  busno, seatno ;
char name[26], sex ;
int  age, fair ;
int  dd, mm, yy ;
} ;


char *place[3]={"Jaipur","Nainital","Chandigarh"} ;
int price[3]={220,220,210} ;



/***************************************************/
/* THIS FUNCTION DISPLAY THE PASSENGER INFORMATION */
/***************************************************/



void TRAVEL :: PASS_INFO(void)
{
clrscr() ;
int bno=0, found=0, sno, d, m, y ;
cout <<"\n Bus 1 : Delhi to Jaipur.      <Fare Rs.220>" ;
cout <<"\n Bus 2 : Delhi to Nainital.    <Fare Rs.220>" ;
cout <<"\n Bus 3 : Delhi to Chandigarh.  <Fare Rs.210>" ;
do
{
cout <<"\n\n Enter the bus no. (1/2/3) " ;
cin >>bno ;
} while (bno < 1 || bno > 3) ;
cout <<"\n\nEnter the Date of the reserved ticket (dd mm yyyy) : " ;
cin >>d >>m >>y ;
cout <<"\nEnter the Seat no. : " ;
cin >>sno ;
if (sno > 60 || sno < 1 || !RESERVED(bno,d,m,y,sno))
{
cout <<"\n\n\n Sorry!\7 Seat not reserved" ;
getch() ;
return ;
}
fstream file ;
file.open("BUS.DAT", ios::in) ;
while (file.read((char *) this, sizeof(TRAVEL)))
{
if ((dd == d && mm == m && yy == y) && bno == busno && sno == seatno)
{
found = 1 ;
clrscr() ;
gotoxy(5,5) ;
cout<<"****************************************" ;
gotoxy(28,7) ;
cout <<"K. D. TRAVEL AGENCY" ;
gotoxy(10,9) ;
cout <<"BUS NO. " <<bno <<"\t\t\t\tDate : " <<d <<"/" <<m <<"/" <<y ;
gotoxy(10,10) ;
cout <<"Seat no. : " <<sno ;
gotoxy(35,12) ;
cout <<"From : Delhi" <<"\tTo : " <<place[bno-1] ;
gotoxy(10,15) ;
cout <<"Passenger name : " <<name ;
gotoxy(10,16) ;
cout <<"Passenger age : " <<age <<"\t\tSex : " <<sex ;
gotoxy(10,18) ;
cout <<"Total Fair : " <<price[bno-1] ;
gotoxy(5,20) ;


cout<<"****************************************" ;
gotoxy(1,25) ;
cout <<"Press any key to continue..." ;
getch() ;
break ;
}
}
file.close() ;
if (!found)
{
cout <<"\n\n\7 Passenger record not found" ;
getch() ;
}
}


void TRAVEL :: LIST_OF_PASS(void)
{
clrscr() ;
int bno=0, found=0, row=8 ;
char ch ;
cout <<"\n Bus 1 : Delhi to Jaipur.      <Fare Rs.220>" ;
cout <<"\n Bus 2 : Delhi to Nainital.    <Fare Rs.480>" ;
cout <<"\n Bus 3 : Delhi to Chandigarh.  <Fare Rs.210>" ;
do
{
cout <<"\n\n Enter the bus no. (1/2/3) " ;
cin >>bno ;
} while (bno < 1 || bno > 3) ;
do
{
cout <<"\n\n Do you want date wise report (y/n) " ;
cin >>ch ;
} while (toupper(ch) != 'N' && toupper(ch) != 'Y') ;
int d=0, m=0, y=0 ;
if (toupper(ch) == 'Y')
{
cout <<"\n\n Enter the Date for the report (dd mm yyyy) : " ;
cin >>d >>m >>y ;
}
clrscr() ;
gotoxy(25,1) ;
cout <<"LIST OF THE PASSENGERS" ;
gotoxy(24,2) ;
cout <<"************************" ;
cout <<"\nBus no.: " <<bno <<"\t\t\t\tFrom: Delhi     To: " <<place[bno-1] ;
gotoxy(2,5) ;
cout <<" SEAT NO.   PASSENGER NAME              SEX     AGE        DATE" ;
gotoxy(1,6) ;


cout<<"***************************************" ;
fstream file ;
file.open("BUS.DAT", ios::in) ;
while (file.read((char *) this, sizeof(TRAVEL)))
{
if (busno == bno)
{
if ((toupper(ch) == 'N') || ((toupper(ch) == 'Y') && (dd == d && mm == m && yy == y)))
{
found = 1 ;
gotoxy(5,row) ;
cout <<seatno ;
gotoxy(14,row) ;
cout <<name ;
gotoxy(43,row) ;
cout <<sex ;
gotoxy(50,row) ;
cout <<age ;
gotoxy(61,row) ;
cout <<dd<<"/"<<mm<<"/"<<yy ;
row++ ;
if (row == 25)
{
getch() ;
for (int i=8; i<=24; i++)
{
gotoxy(1,i) ;
clreol() ;
}
row = 8 ;
}
}
}
}
file.close() ;
if (!found)
{
cout <<"\n\n\n\n\n\7 No Reservation for the bus no. "<<bno ;
getch() ;
return ;
}
cout <<"\n\nPress any key to continue..." ;
getch() ;
}


int TRAVEL :: AVAIL(int bno, int d, int m, int y)
{
fstream file ;
file.open("BUS.DAT", ios::in) ;
int avail=0, count=0 ;
while (file.read((char *) this, sizeof(TRAVEL)))
{
if (bno == busno && dd == d && mm == m && yy == y)
count++ ;
}
file.close() ;
if (count < 60)
avail = 1 ;
return avail ;
}


int TRAVEL :: RESERVED(int bno, int d, int m, int y, int sno)
{
fstream file ;
file.open("BUS.DAT", ios::in) ;
int reserved=0 ;
while (file.read((char *) this, sizeof(TRAVEL)))
{
if (bno == busno && dd == d && mm == m && yy == y && sno)
{
reserved = 1 ;
break ;
}
}
file.close() ;
return reserved ;
}



/************************************************/
/* FUNCTION TO RESERVE TICKET FOR THE PASSENGER */
/************************************************/



void TRAVEL :: RESERVATION(void)
{
clrscr() ;
int bno=0, sno=0, pfair=0, page=0 ;
char pname[26], psex, ch ;
cout <<"\n Bus 1 : Delhi to Jaipur.      <Fare Rs.220>" ;
cout <<"\n Bus 2 : Delhi to Nainital.    <Fare Rs.220>" ;
cout <<"\n Bus 3 : Delhi to Chandigarh.  <Fare Rs.210>" ;
do
{
cout <<"\n\n Enter the bus no. (1/2/3) " ;
cin >>bno ;
} while (bno < 1 || bno > 3) ;
int d,m,y ;
cout <<"\n\nEnter the Date for the reservation (dd mm yyyy) : " ;
cin >>d >>m >>y ;
if (!AVAIL(bno,d,m,y))
{
cout <<"\n\n\n Sorry!\7 Seats not available." ;
getch() ;
return ;
}
cout <<"\nEnter the Seat no. : " ;
cin >>sno ;
if (sno > 60 || sno < 1 || RESERVED(bno,d,m,y,sno))
{
cout <<"\n\n\n Sorry!\7 Seat already reserved" ;
getch() ;
return ;
}
cout <<"\n Enter Name of passenger : " ;
gets(pname) ;
do
{
cout <<" Enter Sex of passenger (M/F) : " ;
cin >>psex ;
} while (toupper(psex) != 'M' && toupper(psex) != 'F') ;
cout <<" Enter age : " ;
cin >>page ;
if (page <= 5)
{
cout <<"\7\nNo ticket is required upto age of 5" ;
getch() ;
return ;
}

clrscr() ;
gotoxy(5,5) ;
cout<<"*********************************" ;
gotoxy(28,7) ;
cout <<"K. D. TRAVEL AGENCY" ;
gotoxy(10,9) ;
cout <<"BUS NO. " <<bno <<"\t\t\t\tDate : " <<d <<"/" <<m <<"/" <<y ;
gotoxy(10,10) ;
cout <<"Seat no. : " <<sno ;
gotoxy(35,12) ;
cout <<"From : Delhi" <<"\tTo : " <<place[bno-1] ;
gotoxy(10,15) ;
cout <<"Passenger name : " <<pname ;
gotoxy(10,16) ;
cout <<"Passenger age : " <<page <<"\t\tSex : " <<psex ;
gotoxy(10,18) ;
cout <<"Total Fair : " <<price[bno-1] ;
gotoxy(5,20) ;

cout<<"**************************************" ;
cout <<"\n\n\n" ;
do
{
cout <<"Do you want to save ticket (y/n) " ;
cin >>ch ;
} while (toupper(ch) != 'Y' && toupper(ch) != 'N') ;
if (toupper(ch) == 'N')
return ;
fstream file ;
file.open("BUS.DAT", ios::app) ;
busno = bno ;
seatno = sno ;
strcpy(name,pname) ;
sex = psex ;
age = page ;
fair = pfair ;
dd = d ;
mm = m ;
yy = y ;
file.write((char *) this, sizeof(TRAVEL)) ;
file.close() ;
}



/**********************************************/
/* FUNCTION TO DELETE RECORD OF THE PASSENGER */
/**********************************************/



void TRAVEL :: DELETION(void)
{
clrscr() ;
int bno=0, found=0, sno, d, m, y ;
char ch ;
cout <<"\n Bus 1 : Delhi to Jaipur.      <Fare Rs.220>" ;
cout <<"\n Bus 2 : Delhi to Nainital.    <Fare Rs.480>" ;
cout <<"\n Bus 3 : Delhi to Chandigarh.  <Fare Rs.210>" ;
do
{
cout <<"\n\n Enter the bus no. (1/2/3) " ;
cin >>bno ;
} while (bno < 1 || bno > 3) ;
cout <<"\n\nEnter the Date of the reserved ticket (dd mm yyyy) : " ;
cin >>d >>m >>y ;
cout <<"\nEnter the Seat no. : " ;
cin >>sno ;
if (sno > 60 || sno < 1 || !RESERVED(bno,d,m,y,sno))
{
cout <<"\n\n\n Sorry!\7 Seat not reserved" ;
getch() ;
return ;
}
fstream file, temp ;
file.open("BUS.DAT", ios::in) ;
temp.open("TEMP.DAT", ios::out) ;
while (file.read((char *) this, sizeof(TRAVEL)))
{
if ((dd == d && mm == m && yy == y) && bno == busno && sno == seatno)
{
found = 1 ;
clrscr() ;
gotoxy(5,5) ;

cout<<"***************************************" ;
gotoxy(28,7) ;
cout <<"K. D. TRAVEL AGENCY" ;
gotoxy(10,9) ;
cout <<"BUS NO. " <<bno <<"\t\t\t\tDate : " <<d <<"/" <<m <<"/" <<y ;
gotoxy(10,10) ;
cout <<"Seat no. : " <<sno ;
gotoxy(35,12) ;
cout <<"From : Delhi" <<"\tTo : " <<place[bno-1] ;
gotoxy(10,15) ;
cout <<"Passenger name : " <<name ;
gotoxy(10,16) ;
cout <<"Passenger age : " <<age <<"\t\tSex : " <<sex ;
gotoxy(10,18) ;
cout <<"Total Fair : " <<price[bno-1] ;
gotoxy(5,20) ;
cout<<"****************************************" ;
do
{
gotoxy(1,25) ; clreol() ;
cout <<"Do you want to Delete (y/n) " ;
cin >>ch ;
} while (toupper(ch) != 'Y' && toupper(ch) != 'N') ;
if (toupper(ch) == 'N')
temp.write((char *) this, sizeof(TRAVEL)) ;
}
else
temp.write((char *) this, sizeof(TRAVEL)) ;
}
file.close() ;
temp.close() ;
if (!found)
{
cout <<"\n\n\7 Passenger record not found" ;
getch() ;
return ;
}
if (toupper(ch) == 'N')
return ;
file.open("BUS.DAT", ios::out) ;
temp.open("TEMP.DAT", ios::in) ;
while (temp.read((char *) this, sizeof(TRAVEL)))
file.write((char *) this, sizeof(TRAVEL)) ;
file.close() ;
temp.close() ;
}


void	TRAVEL :: INFORMATION(void)
{
clrscr();
gotoxy(20,8);
cout<<"INTRODUCTION OF K. D. TRAVEL AGENCY";
gotoxy(4,10);
cout<<"In this agency there is totally three buses whose routes and fair are:" ;
gotoxy(15,12);
cout <<" Bus 1 : Delhi to Jaipur.      <Fare Rs.220>" ;
gotoxy(15,13);
cout <<" Bus 2 : Delhi to Nainital.    <Fare Rs.220>" ;
gotoxy(15,14);
cout <<" Bus 3 : Delhi to Chandigarh.  <Fare Rs.210>" ;
gotoxy(4,16);
cout<<"You can reserve a ticket of any date and later on cancel the same also. ";
gotoxy(28,23);
cout<<"Press a Key to continue...." ;
getche();
}



/*********************************************************************/
/* MAIN FUNCTION WHICH DISPLAY MAIN MENU & CALLS ALL OTHER FUNCTIONS */
/*********************************************************************/



void MAINMENU(void)
{
TRAVEL travel ;
char ch ;
while (1)
{
clrscr() ;
gotoxy(26,5) ;
cout <<"***************************" ;
gotoxy(26,6) ;
cout <<"* K. D. TRAVEL AGENCY *" ;
gotoxy(26,7) ;
cout <<"***************************" ;
gotoxy(29,10) ;
cout <<"1 :: INTRODUCTION" ;
gotoxy(29,11) ;
cout <<"2 :: RESERVATION" ;
gotoxy(29,12) ;
cout <<"3 :: DELETE RECORD" ;
gotoxy(29,13) ;
cout <<"4 :: PASSENGER LIST" ;
gotoxy(29,14) ;
cout <<"5 :: PASSENGER INFO." ;
gotoxy(29,15) ;
cout <<"6 :: QUIT" ;
gotoxy(29,18) ;
cout <<"Enter your choice :: " ;
ch = getche() ;
if (ch == 27 || ch == '6')
break ;
else
if (ch == '1')
travel.INFORMATION();
else
if (ch == '2')
travel.RESERVATION() ;
else
if (ch == '3')
travel.DELETION() ;
else
if (ch == '4')
travel.LIST_OF_PASS() ;
else
if (ch == '5')
travel.PASS_INFO() ;
}
}


void main(void)
{
    MAINMENU();
}
