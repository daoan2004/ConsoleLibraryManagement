#include<string.h>
#include<stdlib.h>

int checkUser(char *userName, char *password)
{
   FILE *fp;
   fp = fopen("User.DBF", "r");  
   	char _userName[256],_password[256];
	int level; 
  	while (fscanf(fp, "%s %s %d", &_userName, &_password, &level) != EOF) 
   	{
   		if(strcmp(_userName,userName)==0)
   		{
   			if(strcmp(_password,password)==0)
		    {
				fclose(fp);	
		    	return level;
			}
			else 
			{
				fclose(fp);	
				return -1;
			}	
		}
	}	
    
   fclose(fp);	
   return -1;
}	
int addUser()
{
	char userName[256], password[256];
	int level;
	char userName1[256], password1[256];
	int level1;
	int duplicate=0;
	
	printf("\nEnter your username: ");
	scanf("%s",&userName);
	printf("\nEnter your password: ");
	scanf("%s",&password);
	printf("\nSet permission for the account 0(Admin), 1(Teacher), 2(Library Manager), 3(Student): ");
	scanf("%d",&level);
	
	FILE *fp;
	FILE *fp2;
    fp = fopen("User_temp.DBF", "w");
	fp2 = fopen("User.DBF", "r");
	
	while (fscanf(fp2, "%s %s %d", &userName1, &password1, &level1) != EOF) 
   	{
   		if(strcmp(userName,userName1)==0) duplicate=1;
		fprintf(fp,"%s %s %d\n", userName1, password1, level1);
	}
	if(duplicate==1)
	{
		printf("Cannot add because account exist");
	}
	else 
	{	
	fprintf(fp,"%s %s %d\n", userName, password, level);
	}	
    fclose(fp);
    fclose(fp2);
	    
    remove("User.DBF");
	rename("User_temp.DBF","User.DBF");
	return 0;
}
int editUser()
{
	char userName[256], password[256];
	int level;
	char userName1[256], password1[256];
	int level1;
	char content[256];
	int n; 
	int num;
	printf("\nEnter the username: ");
	scanf("%s",&userName);
	printf("What field to edit 0(username), 1(password), 2(level): ");
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
    fp = fopen("User_temp.DBF", "w");
	fp2 = fopen("User.DBF", "r");	
	while (fscanf(fp2, "%s %s %d", &userName1, &password1, &level1) != EOF) 
   	{
   		if(strcmp(userName,userName1)==0)
   		{
   			if(n==0)
	   		{
	   			fprintf(fp,"%s %s %d\n", content, password1, level1);
			}
			else if(n==1)
	   		{
	   			fprintf(fp,"%s %s %d\n", userName, content, level);
			}
			else if(n==2)
	   		{
	   			printf("%d",num);
	   			fprintf(fp,"%s %s %d\n", userName1, password1, num);
			}	
		}   
		else fprintf(fp,"%s %s %d\n", userName1, password1, level1);				
	}
	
	fclose(fp);
    fclose(fp2);
	    
    remove("User.DBF");
	rename("User_temp.DBF","User.DBF");
	return 0;
}

int removeUser()
{
	char userName[256], password[256];
	int level;
	char userName1[256], password1[256];
	int level1;
	char content[256];
	int n; 
	int num;
	printf("\nEnter the username of account you want to remove : ");
	scanf("%s",&userName);
	FILE *fp;
	FILE *fp2;
    fp = fopen("User_temp.DBF", "w");
	fp2 = fopen("User.DBF", "r");	
	while (fscanf(fp2, "%s %s %d", &userName1, &password1, &level1) != EOF) 
   	{
   		if(strcmp(userName,userName1)==0)
   		{
   			
		}   
		else fprintf(fp,"%s %s %d\n", userName1, password1, level1);				
	}
	
	fclose(fp);
    fclose(fp2);
	    
    remove("User.DBF");
	rename("User_temp.DBF","User.DBF");
	return 0;
}

char* inputPassword(char msg[], int visible){
	char* str=(char*)malloc(100*sizeof(char));
	if(str==NULL){
		printf("Error:Unable to allocate memory");
		exit(1);
	}
	printf("%s",msg);
	char c;
	int i=0;
	if (visible==1){
		while((c=getche())!='\r'){
			str[i]=c;
			i++;
		}
	}
	else if (visible==0){
		while((c=getch())!='\r'){	
			printf("*");		
			str[i]=c;
			i++;
		}
	}
	str[i]='\0';
	printf("\n");
	return str;
}

   
