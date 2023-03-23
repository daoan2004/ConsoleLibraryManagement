#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "User.h"
#include "Book.h"
#include "showMenu.h"

char S_userName[256], S_password[256];
int S_level = -1;
void menuLogin();
void menuStart();
void menuMain();

void menuShowInfor()
{
	int num;
	system("cls");
	showMenuInfor();
	printf("Do you want to back?(1/0)(Yes/No): ");
	scanf("%d",&num);
	if(num==1) menuStart();
	else exit(0);
}

void menuRenewalBook()
{
	char enterId[256];
	system("cls");
	showIntro(S_level,S_userName);
	showListBookBorrow();showBorrowBook(S_userName);
	printf("Enter id of book you want to renewal: ");
	scanf("%s",&enterId);
	renewalBook(enterId,S_userName);
} 

void meneReturnBook()
{
	char enterId[256];
	system("cls");
	showIntro(S_level,S_userName);
	showListBookBorrow();
	showBorrowBook(S_userName);
	printf("Enter id of book you want to return: ");
	scanf("%s",&enterId);
	returnBook(enterId,S_userName);
}

void menuBorrowBook()
{

	char enterId[256];
	int num;
	
	system("cls");
	showIntro(S_level,S_userName);
	showListBook();
	showBook(S_level);
	
	start:
	printf("\nDo you want to search 1/0(Yes/No): ");
	scanf("%d",&num);
	if(num==0){
		printf("\nEnter your id of book you want borrow: ");
		scanf("%s",&enterId);
		if(borrowBook(enterId, S_userName)==1)
		{
				goto start;
		}
		menuMain();
	}
	else if(num==1)
	{
		searchBook(S_userName,S_level);
	}
	
} 
 
void menuBookManagement()
{
	start:
	system("cls");
	showIntro(S_level,S_userName);
	showBookManagement();
	
	int choiceId = 0;
	scanf("%d", &choiceId);
	switch(choiceId)
	{
		case 1:	
			if(addBook()==0)
			goto start;		
			break;
		case 2:
			if(editBook()==0)
			goto start;				
			break;
		case 3:
			if(removeBook()==0)
			goto start;				
			break;
			exit(0);
		case 4:	
			exit(0);		
			break;
		default:
			exit(0);
	}
}

void menuUserManagement()
{
	start:
	system("cls");
	showIntro(S_level,S_userName);
	showUserManagement();
	
	int choiceId = 0;
	scanf("%d", &choiceId);
	switch(choiceId)
	{
		case 1:	
			if(addUser()==0)
			goto start;		
			break;
		case 2:
			if(editUser()==0)
			goto start;				
			break;
		case 3:
			if(removeUser()==0)
			goto start;				
			break;
			exit(0);
		case 4:	
			exit(0);		
			break;
		default:
			exit(0);
	}
}

void menuMain()
{
	system("cls");
	showIntro(S_level,S_userName);	
	if(checkOverDate(S_userName)==0)
	{	
		showMain(S_level);
		int choiceId = 0;
		scanf("%d", &choiceId);
		switch(choiceId)
		{
			case 0:	
				S_level=-1;
				menuStart();		
				break;
			case 1:
				exit(0);
				break;
			case 2:
				menuBorrowBook();
				break;
			case 3:	
				meneReturnBook();	
				break;
			case 4:
				menuRenewalBook();
				break;
			case 5:
				if(S_level == 0||S_level == 2)
				{
					menuBookManagement();
				}
				else 
				{
					exit(0);
				}
				break;
			case 6:
				if(S_level == 0||S_level == 1)
				{
					menuUserManagement();
				}
				else 
				{
					exit(0);
				}			
				break;
			default:
				exit(0);		
		}
	}	
	else 
	{
		showCheckOverDate();
		int choiceId2 = 0;
		scanf("%d", &choiceId2);
		switch(choiceId2)
		{
			case 1:
				meneReturnBook();	
				break;
			case 2:
				exit(0);
				break;
			default:
				exit(0);		
		}
	}
	
	
}

void menuLogin()
{
	system("cls");
	showIntro(-1,"");
		
	printf("Please enter your username: ");
	scanf("%s", &S_userName);
	char *password=inputPassword("Please enter your password: ", 0);
	strcpy(S_password,password);
	
	S_level = checkUser(S_userName,S_password);
		if(S_level == -1)
	{
		printf("\nYour username or password is incorrect. Do you want to enter again 1/0(Yes/No): ");
		int check;
		scanf("%d",&check);
		if(check == 1) 
			menuLogin();
		else 
			menuStart();		
	}
	else
	{
		menuMain();
	}
	free(password);
	
}

void menuStart()
{
	system("cls");
	showIntro(-1,"");
	showStart();
	
	int choiceId = 0;
	scanf("%d", &choiceId);
	switch(choiceId)
	{
		case 1:
			menuLogin();
			break;
		case 2:
			menuShowInfor();
			break;
		case 3:
			exit(0);
		default:
			exit(0);		
	}	
}

int main() 	
{	
	menuStart();
	return 0;
}
