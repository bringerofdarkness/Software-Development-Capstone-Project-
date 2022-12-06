/* Hello! I am Md Shahrul Zakaria, a student Department of Software Engineering at Daffodil International University.
This is my final project!
“Boarding allocation System” 

//ID:221-35-1033
*/

 

#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> //for windows related functions 
#include <string.h>  

COORD coord = {0,0}; 


void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
 
  /** structure that represent a student */
 typedef struct hostel{
 	int rno;
 	char name[30];              //name of student
 	char location[30];          //name of location
 	char gender[6];            //  gender name
 	int roomno;                 //  room no
 		
 }hostel;

int lower=1, upper=5;
void create () {
 
  
  hostel h;
  FILE * fp = fopen ("hostel.txt","a+");
  
  printf("Enter Roll no : ");
  scanf("%d",&h.rno);
  printf("Enter Name : ");
  scanf("%s",h.name);
  printf("Enter Location : ");
  scanf("%s",h.location);
  printf("Enter Gender : ");
  scanf("%s",h.gender);
    h.roomno= getRoomNo(((rand()%(upper-lower+1))+lower));
    if(h.roomno!=0)
    
  fwrite(&h,sizeof(hostel),1,fp);
 
  
  
  fclose (fp);
  
  
}

    int getRoomNo(int roomno ){
    	int allocated= 0;
	FILE * fp = fopen("hostel.txt","r"); 
	hostel h1;
	while(fread(&h1, sizeof(hostel),1,fp))
	{
	
	     if(h1.roomno == roomno){
	     	allocated = 1;
		 }
	}
	if(allocated == 0)
	    return roomno;
	    else
	        return getRoomNo(((rand()%(upper-lower+1))+lower));
	fclose (fp);
}
void display () {
	hostel h1;
    FILE * fp =fopen("hostel.txt","r");
    printf("\n-----------------------------------------------------------------------\n");
    printf("%-10s%-20s%-15s%-10s%-5s\n","RollNo","Name","Location","Gender","RoomNo");
    printf("\n-----------------------------------------------------------------------\n");

    while (fread(&h1,sizeof(hostel),1,fp))
    printf("%-10d%-20s%-15s%-10s%-5d\n",h1.rno,h1.name,h1.location,h1.gender,h1.roomno);
}


int main(){
		int i;
	char admin_user[20],admin_password[20];
	for(i=1;i<=1;i++)
	{
		system("cls");
		gotoxy(30,6);printf("--------------------------------------------------");
		gotoxy(34,10);printf("WECLOME TO Dhaka Boarding");
		gotoxy(30,14);printf("-------------------------------------------------");
		fflush(stdin);
		gotoxy(30,18);printf("Enter User Name:");
		gets(admin_user);
		gotoxy(30,20);printf("Enter Password: ");
		gets(admin_password);
		system("cls");
	
		if(strcmp(admin_user,"zk666")!=0 || strcmp(admin_password,"666")!=0){
			gotoxy(30,24);printf("Wrong User Name or Password\n");
			getch();
			i--;
		}
	}

	
	int ch;
	do{
		
		printf("\n1. Allocate new room");
		printf("\n2. Display");
		printf("\n3. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: 
			    create ();
			    break;
			case 2: 
			    display ();
			    break;
			case 0: printf("\nThanks...\n");
		}
		
		
	}while(ch!=0);
	
	
}

