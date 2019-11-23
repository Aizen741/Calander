#include<stdio.h>
#include<stdlib.h>



char *months[]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"}; //aaray pointer of months
int monthday[]={31,28,31,30,31,30,31,31,30,31,30,31}; //days in the every month


void red()
{
	printf("\033[1;31m");
}

void black()
{
	printf("\033[0m");
}

int start_day(int year)
{
	int day;
	day=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;   //calculate the 1st day of year
	return day;
}

int input_year(void)
{
	int year;

	printf("please enter a year= ");
	scanf("%d",&year);
	return year;
}

int leap_year(int year)
{
	
	if((year%4==0 && year%100!=0)|| year%400==0) //checking the year is leap year or not
	{
		monthday[2]=29; //leap year then fab days are 29.
		return year;
	}
}

void cal(int year, int start_day)
{
	int month,weekday,day,daysinmonth;
	for(month=1;month<=12;month++)
	{
		daysinmonth=monthday[month];
		printf("\n\n");
		black();
		printf("*****************%s*****************\n",months[month]);
		red();
		printf("  sun");   //printing sunday in red
		black();
	 	printf("  mon  tue  wed  thu  fri  sat\n"); //print monday to saturday


		for(weekday=0;weekday<start_day;weekday++)   //for next month starting day 
			printf("     ");
			for(day=1;day<=daysinmonth;day++)   //print the dates in a month
			{
				red();
				if(weekday==0)
				{
					printf("%5d",day);
				}
				else
				{
					black();
					printf("%5d",day);
				}
				if(++weekday>6)  //it will take date after sat to sun 
                		{
					printf("\n");
					weekday=0;
					
						
				}
				start_day=weekday;
			}
	}
}

int month1(int year,int mond,int start_day)
{
	int month,weekday,day,daysinmonth;
	for(month=1;month<=12;month++)
	{
	if(month==mond)
	{
	daysinmonth=monthday[month];
	printf("*****************%s*****************\n",months[month]);
	red();
        printf("  sun");   //printing sunday in red
        black();
        printf("  mon  tue  wed  thu  fri  sat\n"); //print monday to saturday


// So O added "<=" here and "Weekday = 1 " and added "monthday [month -1]

	for(weekday=1 ;weekday <= start_day; weekday++)   //for next month starting day 
		printf("     ");
		for(day=1;day<=monthday[month-1] ;day++)   //print the dates in a month
		{
			red();
			if(weekday==0)
			{
				printf("%5d",day);
			}
			else
			{
				black();
				printf("%5d",day);
			}

			if(++weekday>6)  //it will take date after sat to sun 
                	{
				printf("\n");
				weekday=0;
			}
			start_day=weekday;
		}
	}

	}
}

int main()
{
	
	int year,daycode;
	int ch,month,choice,day;

	do
	{
		printf("1.Calander of particular year\n");
		printf("2.Calander of particular month\n");
		printf("3.EXIT \n");

		printf("\n\nEnter the option: ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
			
				year=input_year();
				daycode=start_day(year);
				leap_year(year);
				cal(year,daycode);
				printf("\n \n");
				break;
			case 2:
				printf("enter the month and year:  ");
				scanf("%d",&month);
				scanf("%d",&year);
				daycode = start_day(year);
				leap_year(year);
     				month1(year,month,daycode);
				printf("\n\n");
				break;
			default:
				printf("Enter the valid option\n");
}
				
}while(ch<3);

return 0;
}

