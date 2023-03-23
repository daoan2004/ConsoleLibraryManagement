#include<stdio.h>
#include <time.h>
typedef struct {
    char id[256];
    char name[256];
	int status;
    char userBorrow[256];
    char returnDate[256] ;   
}Book;

int addBook()
{
	
	Book newBook;
	int duplicate=0;
	printf("\nEnter id of book: ");
	scanf("%s",&newBook.id);
	printf("\nEnter name of book: ");
	scanf("%s",&newBook.name);
	printf("\nEnter status of book: ");
	scanf("%d",&newBook.status);
	strcpy(newBook.userBorrow,"none");
	strcpy(newBook.returnDate,"none");
	FILE *fp;
	FILE *fp2;
    fp = fopen("Book_temp.DBF", "w");
	fp2 = fopen("Book.DBF", "r");
	Book currentBook;
	while (fscanf(fp2, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.returnDate, &currentBook.userBorrow) != EOF) 
   	{
   		if(strcmp(newBook.id,currentBook.id)==0) duplicate=1;
		fprintf(fp,"%s %s %d %s %s\n", currentBook.id, currentBook.name, currentBook.status, currentBook.returnDate, currentBook.userBorrow);
	}
	if(duplicate==1)
	{
		printf("Cannot add because book exist");
	}
	else 
	{	
	fprintf(fp,"%s %s %d %s %s\n", newBook.id, newBook.name, newBook.status, newBook.returnDate, newBook.userBorrow);
	}	
    fclose(fp);
    fclose(fp2);
	    
    remove("Book.DBF");
	rename("Book_temp.DBF","Book.DBF");
	return 0;
}
int editBook()
{
	Book currentBook;
	Book newBook;
	int n; 
	int num;
	int duplicate=0;
	char content[256];
	strcpy(currentBook.userBorrow,"none");
	strcpy(currentBook.returnDate,"none");
	
	printf("\nEnter id of book: ");
	scanf("%s",&newBook.id);
	printf("What field to edit 0(id), 1(name), 2(status): ");
   	scanf("%d",&n);   	
	printf("Enter your data you want to edit: ");	
	if(n==0||n==1)
	{
		scanf("%s",&content);
	}
	else if(n==2)
	{
		scanf("%d",&num);
	}
	
	FILE *fp;
	FILE *fp2;
    fp = fopen("Book_temp.DBF", "w");
	fp2 = fopen("Book.DBF", "r");
	
	while (fscanf(fp2, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate) != EOF) 
   	{
   		if(strcmp(newBook.id,currentBook.id)==0) 
   		{
   			if(n==0)
	   		{
	   			fprintf(fp,"%s %s %d %s %s\n", content, currentBook.name, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
			}
			else if(n==1)
	   		{
	   			fprintf(fp,"%s %s %d %s %s\n", currentBook.id, content, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
			}
			else if(n==2)
	   		{
	   			printf("%d",num);
	   			fprintf(fp,"%s %s %d %s %s\n", currentBook.id, currentBook.name, num, currentBook.userBorrow, currentBook.returnDate);
			}
		}
		else fprintf(fp,"%s %s %d %s %s\n", currentBook.id, currentBook.name, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
	}		
    fclose(fp);
    fclose(fp2);
	    
    remove("Book.DBF");
	rename("Book_temp.DBF","Book.DBF");
	return 0;
}
int removeBook()
{
	Book newBook;
	int n; 
	int num;
	int duplicate=0;
	char content[256];
	printf("\nEnter id of book you want to remove: ");
	scanf("%s",&newBook.id);
	FILE *fp;
	FILE *fp2;
    fp = fopen("Book_temp.DBF", "w");
	fp2 = fopen("Book.DBF", "r");
	Book currentBook;
	while (fscanf(fp2, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate) != EOF) 
   	{
   		if(strcmp(newBook.id,currentBook.id)==0) 
   		{
   			
		}
		else fscanf(fp2, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate);
	}		
    fclose(fp);
    fclose(fp2);
	    
    remove("Book.DBF");
	rename("Book_temp.DBF","Book.DBF");
	return 0;
}

int searchBook(char *S_userName,int level)
{
	Book currentBook;
	char name[256];
	int num;
	int numMore;
	char enterId[256];
	int choMuon=0;
	
	start:
	printf("\nEnter the keyword: ");
	scanf("%s", name);	
	FILE *fp;
	fp = fopen("Book.DBF","r");
	while (fscanf(fp, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate) != EOF) 
	{
		if(strstr(currentBook.name, name) != NULL)
		{	
			if(level==0 )
			{
				printf("%s %s %d %s %s\n", currentBook.id, currentBook.name, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
			}
			else
			{
				printf("%s %s %d\n", currentBook.id, currentBook.name, currentBook.status);
			}			    	
		}
	}
	fclose(fp);

	printf("\nDo you want to search more?(1/0)(Yes/No): ");
		scanf("%d",&numMore);
		if(numMore==1){
			goto start;
		}
		else if(numMore==0)
		{
			printf("\nEnter your id of book you want borrow: ");
			scanf("%s",&enterId);
			if(borrowBook(enterId, S_userName)==1)
			{

				goto start;
			}
			else 
			{
				return 0;
			}
			
		}
	
	
}

int borrowBook(char *id, char *S_userName)
{
	Book currentBook;
	int choMuon=0;
	int num;
	int flag=0;
	
	FILE *fp;
	FILE *fp2;
    fp = fopen("Book_temp.DBF", "w");
	fp2 = fopen("Book.DBF", "r");	
	while (fscanf(fp2, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate) != EOF) 
   	{		
		if(strcmp(currentBook.id, id) == 0)
   		{
   			flag=1;
   						
			struct tm *t;
			time_t returnTime = (time_t) strtol(currentBook.returnDate, NULL, 10);
			t = localtime(&returnTime);
			char str_time[20];
			time_t current_time = time(NULL);
			current_time += 14 * 24 * 60 * 60;
			t = localtime(&current_time);
			strftime(str_time, sizeof(str_time), "%d-%m-%Y", t);
			if(currentBook.status==1)
			{
				fprintf(fp,"%s %s %d %s %s\n",currentBook.id, currentBook.name, choMuon, S_userName, str_time);
				printf("\nBorrow success!!!");
			}
			else if(currentBook.status==0)
			{
				fprintf(fp,"%s %s %d %s %s\n",currentBook.id, currentBook.name, choMuon, currentBook.userBorrow, currentBook.returnDate);
				printf("\nYou cannot borrow book!!!");
			}
		
		
		}
		else fprintf(fp,"%s %s %d %s %s\n", currentBook.id, currentBook.name, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
		
	}
	
		
    fclose(fp);
    fclose(fp2);
	    
    remove("Book.DBF");
	rename("Book_temp.DBF","Book.DBF");	
	printf("\nDo you want to borrow more?(1/0)(Yes/No): ");
	scanf("%d",&num);
	if(flag=0) 
	{
		printf("Book dosen't exist!!");
	}
	
	return num;
}

int showBorrowBook(char *userName)
{
	Book currentBook;
	FILE *fp;
	FILE *fp2;
    fp = fopen("Book_temp.DBF", "w");
	fp2 = fopen("Book.DBF", "r");	
	while (fscanf(fp2, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate) != EOF) 
	{
		if(strcmp(currentBook.userBorrow, userName) == 0)
		{
			printf("%s %s %s\n", currentBook.id, currentBook.name, currentBook.returnDate);
		}
		
	} 
	
	fclose(fp);
    fclose(fp2);
}
	 

int returnBook(char *returnBook, char *userName)
{
	int choTra=1;
	
	Book currentBook;
	FILE *fp;
	FILE *fp2;
    fp = fopen("Book_temp.DBF", "w");
	fp2 = fopen("Book.DBF", "r");	
	while (fscanf(fp2, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate) != EOF) 
	{
		if(strcmp(currentBook.id,returnBook)==0)
		{
			if(strcmp(currentBook.userBorrow, userName)==0)
			{
				strcpy(currentBook.userBorrow,"none");
				strcpy(currentBook.returnDate,"none");
				fprintf(fp,"%s %s %d %s %s\n",currentBook.id, currentBook.name, choTra, currentBook.userBorrow, currentBook.returnDate);
				printf("\nReturn success!!!");
			}
			else 
			{
				fprintf(fp,"%s %s %d %s %s\n",currentBook.id, currentBook.name, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
				printf("\nYou can't return this book'!!!");
			}
		}
		else 
		{
			fprintf(fp,"%s %s %d %s %s\n",currentBook.id, currentBook.name, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
		
		}
	}
	
	fclose(fp);
    fclose(fp2);
    
    remove("Book.DBF");
	rename("Book_temp.DBF","Book.DBF");	
}

int renewalBook(char *returnBook, char *userName)
{
	Book currentBook;
	FILE *fp;
	FILE *fp2;
    fp = fopen("Book_temp.DBF", "w");
	fp2 = fopen("Book.DBF", "r");	
	time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    char str_time[20];
    strftime(str_time, sizeof(str_time), "%d-%m-%Y", local);
    char *token;
	int day1, month1, year1, day2, month2, year2;
	token = strtok(str_time, "-");
	day1 = atoi(token);
	token = strtok(NULL, "-");
	month1 = atoi(token);			
	token = strtok(NULL, "-");
	year1 = atoi(token);
	if(month1 == 2)
	{
		if( year1 % 4 == 0 && year1 % 100 == 0)
		{
			if(day1 >= 0 && day1 < 16 )
			{
				day2 = day1 + 14;
				month2 = month1;
				year2 = year1;
			}
			else if(day1 >= 16 && day1 <= 29 )
			{
				day2 = day1 + 14 - 29;
				month2 = month1 + 1;
				year2 = year1;
			}
		}	
	}
	else if(month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10)
	{
		if(day1 >= 0 && day1 < 17 )
		{
			day2 = day1 + 14;
			month2 = month1;
			year2 = year1;
		}
		else if(day1 >= 17 && day1 <= 31 )
		{
			day2 = day1 + 14 - 31;
			month2 = month1 + 1;
			year2 = year1;
		}	
	}
	else if(month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11)
	{
		if(day1 >= 0 && day1 < 16 )
		{
			day2 = day1 + 14;
			month2 = month1;
			year2 = year1;
		}
		else if(day1 >= 16 && day1 <= 30 )
		{
			day2 = day1 + 14 - 30;
			month2 = month1 + 1;
			year2 = year1;
		}	
	}	
	else if(month1 == 12)
	{
		if(day1 >= 0 && day1 < 16 )
		{
			day2 = day1 + 14;
			month2 = month1;
			year2 = year1;
		}
		else if(day1 >= 16 && day1 <= 31 )
		{
			day2 = day1 + 14 - 31;
			month2 = month1 + 1;
			year2 = year1 + 1;
		}
	}
	char s[11];
    sprintf(s, "%.2d-%.2d-%.4d", day2, month2, year2);
	
	
	while (fscanf(fp2, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate) != EOF) 
	{
		if(strcmp(currentBook.id,returnBook)==0)
		{
					
			if(strcmp(currentBook.userBorrow, userName)==0)
			{                           			
                fprintf(fp,"%s %s %d %s %s\n",currentBook.id, currentBook.name, currentBook.status, currentBook.userBorrow, s);
                printf("\nRenewal success!!!");
            }
			else 
			{
				fprintf(fp,"%s %s %d %s %s\n",currentBook.id, currentBook.name, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
				printf("\nYou can't renewal this book'!!!");
			}
		}
		else 
		{
			fprintf(fp,"%s %s %d %s %s\n",currentBook.id, currentBook.name, currentBook.status, currentBook.userBorrow, currentBook.returnDate);
		
		}
	}
	
	fclose(fp);
    fclose(fp2);
    
    remove("Book.DBF");
	rename("Book_temp.DBF","Book.DBF");	
}

int checkOverDate(char *userName)
{
	Book overDate;
	
    FILE *fp;
	fp= fopen("BOOK.DBF", "r");
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    char str_time[20];
    strftime(str_time, sizeof(str_time), "%d-%m-%Y", local);
    char *token;
	int day1, month1, year1;
	token = strtok(str_time, "-");
	day1 = atoi(token);
	token = strtok(NULL, "-");
	month1 = atoi(token);			
	token = strtok(NULL, "-");
	year1 = atoi(token);	
    while (fscanf(fp, "%s %s %d %s %s", overDate.id, overDate.name, &overDate.status, overDate.userBorrow, overDate.returnDate) != EOF)
	{
        if(strcmp(overDate.userBorrow, userName)==0)
        {			
			char *token1;
			int day2, month2, year2;
			token1 = strtok(overDate.returnDate, "-");
			day2 = atoi(token1);
			token1 = strtok(NULL, "-");
			month2 = atoi(token1);			
			token1 = strtok(NULL, "-");
			year2 = atoi(token1);			
	        if(year1 > year2 || (year1 == year2 && (month1 > month2 || (month1 == month2 && day1 > day2)))) 
			{
	            printf("You must return book!!!!\n");
	            fclose(fp);
	            return 1;
	        }        	
		}
    }

    fclose(fp);
    return 0;
}

