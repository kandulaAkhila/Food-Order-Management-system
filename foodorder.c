#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void returnfunc(void);

void mainmenu(void);

void administration(void);

void customer(void);

void addrecord(void);

void deleterecord(void);

void searchrecord(void);

void viewrecord(void);

void vegetarian(void);

void nonvegetarian(void);

void details(void);

void Password(void);
int getdata();
struct employee
{

	char name[30];
	int id;
	int dd; int mm; int yyyy;
	int YOJ;
	char place[20];
	float salary;
	char department[20];
	int quantity;
};
struct employee e;
FILE *fp,*ft,*dp,*dt;
int s;
char findrecord;
int again;
int quantity;
double total=0;
int t;
char password[20]="foodgood";

int main()
{
	mainmenu();
	return 0;
}

void mainmenu(void)
{
	system("cls");
	printf("\n\n");
	printf("          **************************************************************************\n");
	printf("          -----------------------WELCOME TO FOOD ORDER SYSTEM-----------------------\n");
	printf("          **************************************************************************\n\n\n");
	printf("          1. ADMINISTRATION SECTION--> \n\n          2. CUSTOMER SECTION--> \n\n          3. Exit--> \n\n\n             Enter Your Choice:");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		Password();
		administration();
	}
	else if(choice==2)
	{
		customer();
	}
	else if(choice==3)
	{
		system("cls");
		printf("\n\n\n");
		printf("***************-------------------THANK YOU------------------*****************\n");
		exit(0);
	}
}

void administration(void)
{
	system("cls");
	printf("\n\n");
	printf("-----------------------------WELCOME TO THE EMPLOYEE SECTION----------------------------\n\n");
	printf("          1. Add New Record-->\n\n          2. Search Record-->\n\n          3. Delete Record-->\n\n          4. View THe Records-->\n\n          5. View previous orders placed-->\n\n          6. Back To Main Menu-->\n\n             Enter Your Choice:");
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		addrecord();
	}
	else if(n==2)
	{
		searchrecord();
	}
	else if(n==3)
	{
		deleterecord();
	}
	else if(n==4)
	{
		viewrecord();
	}
		
	else if(n==5)
	{
		FILE *view;
		char viw;
		view = fopen("order.txt","rt");
		while((viw=fgetc(view))!=EOF)
		{
			printf("%c",viw);
		}
		fclose(view);
		mainmenu();
	}
	else if(n==6)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("Wrong Input !! PLease Re-enter The Correct Option");
		if(getch())
		administration();
	}
	
}

void addrecord(void)
{
	system("cls");
	fp=fopen("record1.txt","a");
	if(getdata()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&e,sizeof(e),1,fp);
		fclose(fp);
		printf("\n\n");
		printf("The Record Is Successfully Saved ! !\n\n");
		printf("Save any more?(y / n): ");
		if(getch()=='n')
	    	administration();
		else
	    	system("cls");
	    	addrecord();
	}	
}

void deleterecord(void)
{
	system("cls");
    	int d;
    	char another='y';
    	while(another=='y')  //infinite loop
    	{
		system("cls");
		printf("\n\n                Enter The Employee ID To Delete :");
		scanf(" %d",&d);
		fp=fopen("record1.txt","r+");
	  	rewind(fp);
		while(fread(&e,sizeof(e),1,fp)==1)
		{
	    		if(e.id==d)
	    		{
				printf("\n\n");
				printf("                               .....................The Employee Record Is Available....................\n\n");
				printf("               Employee Name Is %s\n\n",e.name);
				printf("               Employee's Date  OF Birth Is %d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
				findrecord='t';
	    		}
		}
		if(findrecord!='t')
		{
	    		printf("                                    .........................No record is found modify the search..........................\n\n");
	    		if(getch())
	    		administration();
		}
		if(findrecord=='t' )
		{
	    		printf("Do You Want To Delete THe Record ? (y / n) ");
	    		if(getch()=='y')
	    		{
				ft=fopen("test1.txt","w");  //temporary file for delete
				rewind(fp);
				while(fread(&e,sizeof(e),1,fp)==1)
				{
		    			if(e.id!=d)
		    			{
						fseek(ft,0,SEEK_CUR);
						fwrite(&e,sizeof(e),1,ft); //write all in tempory file except that
		    			}                              //we want to delete
				}	
				fclose(ft);
				fclose(fp);
				remove("record1.txt");
				rename("test1.txt","record1.txt"); //copy all item from temporary file to fp except that
				fp=fopen("record1.txt","r");    //we want to delete
				if(findrecord=='t')
				{
		    			printf("        THE RECORD IS SUCCESSFULLY DELETED.\n\n");
		    			printf("        Delete Another Record ? (Y/N) : ");
				}
	    		}
			else
			administration();
			fflush(stdin);
			another=getch();
		}
	}
	administration();
}

void searchrecord(void)
{
	system("cls");
    	int d;
    	printf("\n\n                                     -------------------------Search Employees Record-------------------------\n\n");
    	printf("                  1. Search By ID\n");
    	printf("                  2. Search By Name\n\n");
    	printf("                  Enter Your Choice---> ");
    	fp=fopen("record1.txt","r"); //open file for reading propose
    	rewind(fp);   //move pointer at the begining of file
    	switch(getch())
    	{
	  case '1':
		{
	    	system("cls");
	    	printf("                       ******************************Search Record By Id*******************************\n\n");
	    	printf("                Enter The Employee ID : ");
	    	scanf(" %d",&d);
	    	printf("\n\n");
		printf("Searching........");
	    	while(fread(&e,sizeof(e),1,fp)==1)
	    	{
				if(e.id==d)
				{
		    			printf("\n\n");
					printf("...........................The Record is available............................\n\n");
				    	printf("       ID : %d\n\n",e.id);
				    	printf("       Name : %s\n\n",e.name);
				    	printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
				    	printf("       Year Of Joining :%d\n\n",e.YOJ);
				    	printf("       Department :%s\n\n",e.department);
				    	printf("       Place :%s\n\n",e.place);
				    	findrecord='t';
				}

	    	}
	    	if(findrecord!='t')  //checks whether condition enters inside loop or not
	    	{
	    		printf("\aNo Record Found\a");
	    	}
	    	printf("Try Another Search ? (y/n)");
	    	if(getch()=='y')
	    	searchrecord();
	    	else
	    	administration();
	    	break;
	}
	case '2':
	{
	    char s[15];
	    system("cls");
	    printf("                                      *************************Search Employees By Name***************************\n\n");
	    printf("               Enter Employee Name : ");
	    scanf(" %s",s);
	    int d=0;
	    while(fread(&e,sizeof(e),1,fp)==1)
	    {
		if(strcmp(e.name,(s))==0) //checks whether a.name is equal to s or not
		{
		    printf("                               .........................The Record is available...........................\n\n\n");
			printf("       ID : %d\n\n",e.id);
			printf("       Name : %s\n\n",e.name);
			printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
			printf("       Year Of Joining :%d\n\n",e.YOJ);
			printf("       Department :%s\n\n",e.department);
			printf("       Place :%s\n\n",e.place);
		    d++;
		}

	    }
	    if(d==0)
	    {
	    	printf("\aNo Record Found\a");
	    }
	    printf("Try Another Search ? (Y/N)");
	    if(getch()=='y')
	    searchrecord();
	    else
	    administration();
	    break;
	}
	default :
	getch();
	searchrecord();
    }
    fclose(fp);
}

void viewrecord(void) 
{
    	system("cls");
    	printf("                              ********************** Employee Details**********************\n\n");
    	printf("                 DEPARTMENT        ID        EMPLOYEE NAME        D.O.B        Y.O.J        PLACE\n\n");
    
    	fp=fopen("record1.txt","r");
    	while(fread(&e,sizeof(e),1,fp)==1)
    	{
		printf("                 %s\t",e.department);
		printf("%d\t",e.id);
		printf("%s\t",e.name);
		printf("%d/%d/%d\t",e.dd,e.mm,e.yyyy);
		printf("%d\t",e.YOJ);
		printf("%s\t",e.place);
		printf("\n\n");
	}
      
      	fclose(fp);
      	returnfunc();
}

void returnfunc(void)
{
    {
		printf(" Press ENTER to return to main menu");
    }
    e:
    if(getch()==13) //allow only use of enter
    administration();
    else
    goto e;
}

int checkid(int c)  //check whether the record is exist in list or not
{
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	if(e.id==c)
	
	return 0;  //returns 0 if employee exits
    
	return 1; //return 1 if it not
}
int getdata()
{
	//*int t;
	printf("\n\n        Employee ID :\t");
	scanf("%d",&t);
	if(checkid(t)==0)
	{
		printf("\n\n");
		printf("\a                        The Employee Record Already Exists !!!\a");
		getch();
		mainmenu();
		return 0;
	}
	e.id=t;
	printf("        Employee Name : ");
	scanf("%s",e.name);
	printf("        Date Of Birth (dd/mm/yyyy) :");
	scanf("%d/%d/%d",&e.dd,&e.mm,&e.yyyy);
	printf("        Year OF Joining :");
	scanf("%d",&e.YOJ);
	printf("        Place :");
	scanf("%s",e.place);
	printf("        Department :");
	scanf("%s",e.department);
	return 1;
}
void customer(void)
{

	system("cls");
	printf("\n\n");
	printf("                    ************************************************\n                    ---------------------WELCOME--------------------\n                    ************************************************\n\n");
	printf("               YOU ARE--->\n\n               1. Vegetarian-->\n\n               2. Non Vegetarian-->\n\n                      OR\n\n               3. Back To Main Menu-->\n\n   Enter Your Choice:");
	int k;
	scanf("%d",&k);
	if(k==1)
	{
		system("cls");
		vegetarian();
	}
	else if(k==2)
	{
		system("cls");
		nonvegetarian();
	}
	else if(k==3)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("Wrong Input !Please Re-enter The Correct Option......\n\n");
		customer();
	}
}
void vegetarian(void)
{
	int choice;
	int again;
	int quantity;
	double price=0;
	//printf("\n\n");
	printf("                    ****************************************\n             ---------------------VEGETARIAN MENU------------------\n                    ****************************************\n\n");
	printf("      1. Burger               40/-\n\n      2. Noodles              60/-\n\n      3. Manchuria            45/-\n\n      4. Beverages            35/-\n\n      5. Veg. Thaali          150/-\n\n      6. Sandwich             50/-\n\n      7. Veg lollipop         70/-\n\n      8. Back To Main Menu\n\n Enter Your Choice-->  ");
	char v;
	FILE *vmenu;
	vmenu=fopen("vegmenu.txt","rt");
	while((v=getc(vmenu))!=EOF)
        {
        	printf("%c",v);
	}
        fclose(vmenu);
   	printf("\n\nEnter What You Want:");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 40*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 60*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 45*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 35*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 150*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
		
			details();
		}
			
	}
	else if(choice==6)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 50*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==7)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 70*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==8)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		if(getch())
		vegetarian();
	}
}
void nonvegetarian(void)
{
	int choice;
	int again;
	int quantity;
	double price=0;
	printf("                    **********************************************\n");
	printf("              ----------------------Non-Vegetarian Menu-----------------\n");
	printf("                    **********************************************\n\n");
     	printf("1. Chilli chicken         100/-\n\n	2. Chicken 65             120/-\n\n	3. Chicken Biryani        85/-\n\n	4. Beverages              35/-\n\n	5. Mutton kurma           175/-\n\n	6. fish fry               200/-\n\n	7. Back To Main Menu\n\n\nEnter Your Choice");
	char n;
	FILE *nmenu;
	nmenu = fopen("nonveg.txt","rt");
	while((n=getc(nmenu))!=EOF)
	{
		printf("%c",n);
	}
	printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity : ");
		scanf(" %d",&quantity);
		total=total + 100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 120*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 85*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==4)
	{
		printf("Enter Quantity :");
		scanf(" %d",&quantity);
		total=total + 35*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==5)
	{
		printf("Enter Quantity :");
		scanf(" %d",&quantity);
		total=total + 170*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==6)
	{
		printf("Enter Quantity :");
		scanf(" %d",&quantity);
		total=total + 200*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==7)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		nonvegetarian();
	}
}
void details(void)
{
	char name1[20];
	char name2[20];
	long long int phone;
	char address[40];
	char landmark[30];
	printf("Please Give Your Contact Details \n");
	printf(" First Name : ");
	scanf("%s",name1);
	printf("Last Name : ");
	scanf("%s",name2);
	printf("Phone : ");
	scanf("%lld",&phone);
	printf("Address : ");
	scanf("%s",address);
	printf("Landmark : ");
	scanf("%s",landmark);
	printf("\n\n");
	printf("Your Entered Details Are --->\n");
	FILE *cust;
	cust = fopen("order.txt","a");
	fprintf(cust,"Order Placed By : %s %s\nPhone number : %lld\n",name1,name2,phone);
	fclose(cust);
	printf("    -->First Name :  %s\n    -->Last Name   :  %s\n    -->Phone     :%lld \n    -->Address  :%s \n    -->Landmark  :%s \n",name1,name2,phone,address,landmark);
	printf("\n\n\n");
	printf("                       *********************************************************************************************\n");
	printf("                       ------------------------Your Order Will Be At Your Door In 30 minutes-------------------------\n");
	printf("                                                       .....HAPPY ORDERING.....\n");
	printf("                       *********************************************************************************************\n");
	
	printf("Press Any  key To The MainMenu.");
	if(getch())
	customer();
}
void Password(void)
{
	system("cls");
	char d[30]="PASSWORD PROTECTED";
	char ch,pass[10];
	int i=0,j;
	for(j=0;j<20;j++)
	{
		printf("*");
	}
	for(j=0;j<20;j++)
	{
		printf("%c",d[j]);
	}
	for(j=0;j<20;j++)
	{
		printf("*");
	}
	printf("\nEnter Password : ");
	while(ch!=13)
	{
		ch=getch();
		if(ch!=13 && ch!=8)
		{
			putch('*');
			pass[i]=ch;
			i++;
		}
	}
	pass[i]='\0';
	if(strcmp(pass,password)==0)
	{
		printf("PASSWORD MATCHED !!!\n\n");
		printf("Press Any Key To Continue......\n\n");
		getch();
	}
	else
	{
		printf("\nWARNING ! INCORRECT PASSWORD....");
		printf("\nClick ENTER to enter the password again:");
		getch();
		Password();
	}
}
