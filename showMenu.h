#include<stdio.h>

void showIntro(int level,char *userName)
{
		printf("                                     ********************************************\n");
	    printf("                                     *           Library Manager Software       *\n");
	    printf("                                     *           Version     :     1.0.0        *\n");
	    printf("                                     *                                          *\n");
	    printf("                                     ********************************************\n \n");
	    if(level == 0)
	    {
	    	printf("                                     You are logged in as %s (Role: admin)  \n", userName); 
		}
		if(level == 1)
	    {
	    	printf("                                     You are logged in as %s (Role: Teacher)  \n", userName); 
		} 
		if(level == 2)
	    {
	    	printf("                                     You are logged in as %s (Role: Library Manager)  \n", userName); 
		}
		if(level == 3)
	    {
	    	printf("                                     You are logged in as %s (Role: Student)  \n", userName); 
		} 
		
    	printf("\n \n \n \n");

}
void showStart()
{
	printf("Start Menu\n");
	printf("1) Login\n");
	printf("2) Information\n");
	printf("3) Exit\n");
	printf("Enter your choice: ");
}
void showMain(int level)
{
	printf("Main Menu\n");
	printf("0) Logout\n");
	printf("1) Exit\n");
	printf("2) Borrow book\n");
	printf("3) Return book\n");
	printf("4) Book renewal\n");
	if(level == 2 || level == 0)
	{
		printf("5) Book Managenment\n");
	}
	if(level == 1 || level == 0) 
	{
		printf("6) User Managenment\n");
	}
	printf("Enter your choice: ");
}
void showUserManagement()
{
	printf("User Management Menu\n");
	printf("1) Add account\n");
	printf("2) Edit account\n");
	printf("3) Remove account\n");	
	printf("4) Exit\n");
	printf("Enter your choice: ");
}
void showBookManagement()
{
	printf("Book Managenment Menu\n");
	printf("1) Add book\n");
	printf("2) Edit book\n");
	printf("3) Remove book\n");
	printf("4) Exit\n");
	printf("Enter your choice: ");
}
void showBook(int level)
{
	
	Book currentBook;
	FILE *fp;
	fp = fopen("Book.DBF","r");
	while (fscanf(fp, "%s %s %d %s %s", &currentBook.id, &currentBook.name, &currentBook.status, &currentBook.userBorrow, &currentBook.returnDate) != EOF) 
	{
		printf("%s %s %d ", currentBook.id, currentBook.name, currentBook.status);
		if (level==0)
		{
			printf("%s %s", currentBook.userBorrow,currentBook.returnDate);
		}
		printf("\n");
	}
	fclose(fp);
	
}
void showListBook()
{
	printf("List book in library: \n\n\n");
}
void showListBookBorrow()
{
	printf("List book you had borrowed:  \n\n\n");
}
void showCheckOverDate()
{
	printf("\nOverDate Menu\n");

	printf("1) Return book\n");
	printf("2) Exit\n");
	
	printf("Enter your choice: ");
}
void showMenuInfor()
{
		printf("                                     ********************************************\n");
		printf("                                     *           LIBRARY MANAGER PROGRAM        *\n");
	    printf("                                     *           Version        :  1.0.0        *\n");
	    printf("                                     *           Edited by      :  Team 5       *\n");
	    printf("                                     *           Dao Binh An    -  HE186803     *\n");
	    printf("                                     *           Le The My      -  HS173043     *\n");
	    printf("                                     *           Do Duy Nghia   -  HE180687     *\n");
	    printf("                                     *           Cao Trang      -  HE186963     *\n");
	    printf("                                     *                                          *\n");
	    printf("                                     ********************************************\n \n");
		printf("                                                          _oo0oo_					\n");              
		printf("                                                         o8888888o				\n");
		printf("                                                         88\" . \"88				\n");
		printf("                                                         (| -_- |)				\n");
		printf("                                                         0\\  =  /0				\n");
		printf("                                                       ___/`---'\\___				\n");
		printf("                                                     .' \\\\|     |// '.			\n");			
		printf("                                                     / \\|||  :  |||/ \\			\n");
		printf("                                                   / _||||| -:- |||||-\\			\n");
		printf("                                                  |   | \\\\\\  -  /// |  |			\n");
		printf("                                                  | \\_|  ''\\\---/''  |_/ |			\n");
		printf("                                                  \\  .-\\__  '-'  ___/-. /			\n");
		printf("                                                ___'. .'  /--.--\\  `. .'___		\n");	
		printf("                                               ."" '<  `.___\\_<|>_/___.' >' "".		\n");	
		printf("                                            | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |	\n");		
		printf("                                             \\ \ \ `_.   \\_ __\\ /__ _/   .-` /  /	\n");		
		printf("                                        =====`-.____`.___ \\_____/___.-`___.-'=====\n");		
		printf("                                                          `=---='					\n");			
		printf("                                   												\n");			
		printf("                                        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");			
		printf("                                               Phat phu ho, khong bao gio BUG		\n");			
		printf("                                        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");			
}
