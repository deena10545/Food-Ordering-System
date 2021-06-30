#include <stdio.h>
#include <stdlib.h>

struct User_details
{
    char name[100];
    char password[50];
    char email[100];
    char phone_no[10];
};
struct Hotels
{
    char hotel[100];
    char food_one[50];
    char food_two[50];
    char food_three[50];
    char temp_hotel[50];
    int price_one,price_two,price_three,add_count[50],add_price[50];
};
struct User_details s[100];
struct Hotels h[4];

int choice,i,a,b,j=0,count=0,n,total=0;
char temp_name[100],temp_pass[50],temp_confirmpass[50],temp_email[50],temp_mobile[10];
int caps=0,small=0,num=0,special_characters=0;
int p=0,z=0,rate=0,flag;
void login();
void signup();
void swiggy();
int account_check();
int validate();
void cart();
void allocate_hotels();
void search_by_hotel();
void search_by_food();
void hotel_details(int);
void food_order(int);
int food_choice,hotel_choice,confirm,food,hotel_id;

int main()
{
    while(1)
	{
		printf("\n--------------------------------------------------\n");
		printf("\n\t     WELCOME!!\n");
		printf("\n\tFOOD ORDERING SYSTEM\n");
		printf("\n1) LOGIN\n2) SIGNUP\n3) EXIT\nEnter Your Choice.......");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				login();
				break;
			}
			case 2:
			{
				signup();
				break;
			}
			case 3:
            {
                exit(1);
            }
			default:
			{
				printf("\nPlease enter the valid choice\n");
				break;
			}
		}
	}
}

int account_check()
{
    for(i=0;i<100;i++)
    {
        if(!strcmp(s[i].email,temp_email))
        {
            if(!strcmp(s[i].password,temp_pass))
            {
                printf("\nAccount already existed...Please login!!!\n");
                main();
            }
        }
    }
    if(i==100)
    {
       return 1;
    }
}

int validate()
{
    for(i=0;temp_name[i]!='\0';i++)
    {
        if(!((temp_name[i]>='a' && temp_name[i]<='z')|| (temp_name[i]>='A' && temp_name[i]<='Z')))
        {
            count=0;
            printf("\n\nInvalid Name....Please enter the valid name.....\n\n");
            main();
        }
        else
            count=1;
    }
    if(count==1)
    {
        caps=0;small=0;num=0;special_characters=0;
        for(i=0;temp_pass[i]!='\0';i++)
        {
            if(temp_pass[i]>='A' && temp_pass[i]<='Z')
                caps++;
            else if(temp_pass[i]>='a' && temp_pass[i]<='z')
                small++;
            else if(temp_pass[i]=='@' || temp_pass[i]=='#' || temp_pass[i]=='&' || temp_pass[i]=='*' || temp_pass[i]=='.')
                special_characters++;
            else if(temp_pass[i]>='0' && temp_pass[i]<='9')
                num++;
        }
        if(caps>=1 && small>=3 && special_characters>=1 && num>=3)
        {
            count=1;
        }
        else
        {
            count=0;
            printf("\n\nThe password you enter is weak...Please enter the strong password....\n\n");
            main();
        }
    }
    if(count==1)
    {
        for(i=0;temp_pass[i]!='\0';i++)
        {
            if(temp_pass[i]!=temp_confirmpass[i])
            {
                count=0;
                printf("\n Password did not match...Please try again!!");
                main();
                break;
            }
            else
                count=1;
        }
    }
    if(count==1)
    {
        int at=0,dot=0;
        small=0;num=0;
        for(i=0;temp_email[i]!='\0';i++)
        {
            if(temp_email[i]=='@')
                at++;
            else if(temp_email[i]=='.')
                dot++;
            else if(temp_email[i]>='a' && temp_email[i]<='z')
                small++;
            else if(temp_email[i]>='0' && temp_email[i]<='9')
                num++;
            else
            {
                printf("\nEnter valid mail address...\n");
                main();
                break;
            }
        }
        if(at==1 && dot==1 && small>=5)
            {
                count=1;
            }
        else
        {
            count=0;
            printf("\nPlease enter the valid mail address...\n");
            main();
        }
    }
    if(count==1)
    {
        num=0;
        for(i=0;temp_mobile[i]!='\0';i++)
        {
            if(temp_mobile[i]>='0' && temp_mobile[i]<='9')
                num++;
        }
        if(num==10 &&temp_mobile[0]!='0')
        {
            return 1;
        }
        else
        {
            printf("\nPlease enter the valid Mobile number...\n");
            main();
        }
    }
}

void signup()
{
    printf("\n--------SIGNUP--------\n\n");
    printf("Enter your Name(ONLY ALPHABETS):\t");
    scanf("%s",temp_name);
    printf("Enter a strong password:\t");
    scanf("%s",temp_pass);
    printf("Confirm your password:\t");
    scanf("%s",temp_confirmpass);
    printf("Enter your Email Address:\t");
    scanf("%s",temp_email);
    printf("Enter your Mobile number:\t");
    scanf("%s",temp_mobile);
    a=account_check();
    b=validate();
    if(a==1 && b==1)
    {
        strcpy(s[j].name,temp_name);
        strcpy(s[j].password,temp_pass);
        strcpy(s[j].email,temp_email);
        strcpy(s[j].phone_no,temp_mobile);
        j++;
        printf("\nSign up successfully....Please login...\n");
    }
}

void login()
{
   printf("\n-------LOGIN-------\n\n");
    printf("Enter the E-mail:\t");
    scanf("%s",temp_email);
    printf("Enter the password:\t");
    scanf("%s",temp_pass);
        for(i=0;i<j;i++)
        {
            if(!strcmp(s[i].email,temp_email))
            {
                if(!strcmp(s[i].password,temp_pass))
                   {
                       printf("\n\n\tLogin successful...\n\n");
                       swiggy();
                       break;
                   }
                   else
                   {
                       printf("\nInvalid password...Please Enter the correct password!!\n");
                       main();
                       break;
                   }
			}
		}
        printf("\n\nAccount does not exist! Please signup...\n\n");
        main();
}

void swiggy()
{
    printf("\t Welcome %s!!!\n",s[i].name);
    printf("\nHere, We provide two ways of search for Food Order\n\n 1) Search_by_hotel\n 2) Search_by_food\n 3) View_Cart\n 4) Exit\n");
    printf("\n\nPlease Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
        {
            case 1:
                {
                    search_by_hotel();
                    break;
                }
            case 2:
                {
                    search_by_food();
                    break;
                }
            case 3:
                {
                    cart();
                    break;
                }
            case 4:
                {
                    exit(1);
                }
            default:
                {
                    printf("Enter the valid choice....");
                    break;
                }
        }
}
void search_by_hotel()
{
    allocate_hotels();
    printf("Choose the hotels\n\n 1)%s\n 2)%s\n 3)%s\n 4)%s\n 5)%s\n 6)Go_Back\n 7)Exit\n",h[1].hotel,h[2].hotel,h[3].hotel,h[4].hotel,h[5].hotel);
    scanf("%d",&hotel_choice);
    if(hotel_choice>7)
    {
        printf("\nPlease Enter the valid choice..\n");
        search_by_hotel();
    }
    else if(hotel_choice==6)
        swiggy();
    else if(hotel_choice==7)
        exit(1);
    else
        hotel_details(hotel_choice);
}

void search_by_food()
{
    allocate_hotels();
    while(1)
    {
        printf("\n\nPlease choose the food\n\n1) %s-%d\n2) %s-%d\n3) %s-%d\n4) %s-%d\n5) %s-%d\n6) %s-%d\n7) %s-%d\n8) %s-%d\n9) %s-%d\n10) %s-%d\n11) %s-%d\n12) %s-%d\n13) %s-%d\n14) %s-%d\n15) %s-%d\n16) Go-Back\n17) Exit",h[1].food_one,h[1].price_one,h[1].food_two,h[1].price_two,h[1].food_three,h[1].price_three,h[2].food_one,h[2].price_one,h[2].food_two,h[2].price_two,h[2].food_three,h[2].price_three,h[3].food_one,h[3].price_one,h[3].food_two,h[3].price_two,h[3].food_three,h[3].price_three,h[4].food_one,h[4].price_one,h[4].food_two,h[4].price_two,h[4].food_three,h[4].price_three,h[5].food_one,h[5].price_one,h[5].food_two,h[5].price_two,h[5].food_three,h[5].price_three);
        printf("\nPlease Enter Your Choice\t");
        scanf("%d",&food);
        if(food>16)
            {
                printf("Please Enter the valid choice\n\n");
                search_by_food();
            }
            else if(food==16)
                swiggy();
            else if(food==17)
                exit(1);
            else
                food_order(food);
    }
}

void food_order(int food)
{
    if(food>=1 && food<=3)
		hotel_id=1;
	else if(food>=4 && food<=6)
		hotel_id=2;
	else if(food>=7 && food<=9)
		hotel_id=3;
    else if(food>=10 && food<=12)
        hotel_id=4;
    else
        hotel_id=5;
    flag=1;
    if((food%3)==1)
	{
		printf("\nPlease Enter the Count of %s\t",h[hotel_id].food_one);
		scanf("%d",&n);
		rate=(n*h[hotel_id].price_one);
		total=total+rate;
        for(i=0;i<p;i++)
            {
                if(!strcmp(h[i].temp_hotel,h[hotel_id].food_one))
                {
                    h[i].add_price[i]+=rate;
                    h[i].add_count[i]+=n;
                    flag=0;
                }
            }
            if(flag==1)
            {
                strcpy(h[p].temp_hotel,h[hotel_id].food_one);
                h[p].add_count[z]=n;
                h[p].add_price[z]=rate;
                p++;
                z++;
            }
	}
	else if((food%3)==2)
	{
		printf("\nPlease Enter the Count of %s\t",h[hotel_id].food_two);
		scanf("%d",&n);
		rate=(n*h[hotel_id].price_two);
		total=total+rate;
        for(i=0;i<p;i++)
            {
                if(!strcmp(h[i].temp_hotel,h[hotel_id].food_two))
                {
                    h[i].add_price[i]+=rate;
                    h[i].add_count[i]+=n;
                    flag=0;
                }
            }
            if(flag==1)
            {
                strcpy(h[p].temp_hotel,h[hotel_id].food_two);
                h[p].add_count[z]=n;
                h[p].add_price[z]=rate;
                p++;
                z++;
            }
	}
	else if((food%3)==0)
	{
		printf("\nPlease Enter the Count of %s\t",h[hotel_id].food_three);
		scanf("%d",&n);
		rate=(n*h[hotel_id].price_three);
		total=total+rate;
        for(i=0;i<p;i++)
            {
                if(!strcmp(h[i].temp_hotel,h[hotel_id].food_three))
                {
                    h[i].add_price[i]+=rate;
                    h[i].add_count[i]+=n;
                    flag=0;
                }
            }
            if(flag==1)
            {
                strcpy(h[p].temp_hotel,h[hotel_id].food_three);
                h[p].add_count[z]=n;
                h[p].add_price[z]=rate;
                p++;
                z++;
            }
	}
}

void hotel_details(int hotel_choice)
{
    while(1)
    {
         flag=1;
        printf("\n\nList of foods available in %s\n\n1) %s\tRs: %d\n2) %s\tRs: %d\n3) %s\tRs: %d\n4) Exit\n\nPlease Enter Your Choice\t",h[hotel_choice].hotel,h[hotel_choice].food_one,h[hotel_choice].price_one,h[hotel_choice].food_two,h[hotel_choice].price_two,h[hotel_choice].food_three,h[hotel_choice].price_three);
			scanf("%d",&food_choice);
			if(food_choice==1)
			{
				printf("\nPlease Enter the Count of %s\t",h[hotel_choice].food_one);
				scanf("%d",&n);
				rate=(n*h[hotel_choice].price_one);
				total=total+rate;
				for(i=0;i<p;i++)
                {
                    if(!strcmp(h[i].temp_hotel,h[hotel_choice].food_one))
                    {
                        h[i].add_price[i]+=rate;
                        h[i].add_count[i]+=n;
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    strcpy(h[p].temp_hotel,h[hotel_choice].food_one);
                    h[p].add_count[z]=n;
                    h[p].add_price[z]=rate;
                    p++;
                    z++;
                }
			}
			else if(food_choice==2)
			{
				printf("\nPlease Enter the Count of %s\t",h[hotel_choice].food_two);
				scanf("%d",&n);
                rate=(n*h[hotel_choice].price_two);
				total=total+rate;
                for(i=0;i<p;i++)
                {
                    if(!strcmp(h[i].temp_hotel,h[hotel_choice].food_two))
                    {
                        h[i].add_price[i]+=rate;
                        h[i].add_count[i]+=n;
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    strcpy(h[p].temp_hotel,h[hotel_choice].food_two);
                    h[p].add_count[z]=n;
                    h[p].add_price[z]=rate;
                    p++;
                    z++;
                }
			}
			else if(food_choice==3)
            {
                printf("\nPlease Enter the count of %s\t",h[hotel_choice].food_three);
                scanf("%d",&n);
                rate=(n*h[hotel_choice].price_three);
                total=total+rate;
                for(i=0;i<p;i++)
                {
                    if(!strcmp(h[i].temp_hotel,h[hotel_choice].food_three))
                    {
                        h[i].add_price[i]+=rate;
                        h[i].add_count[i]+=n;
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    strcpy(h[p].temp_hotel,h[hotel_choice].food_three);
                    h[p].add_count[z]=n;
                    h[p].add_price[z]=rate;
                    p++;
                    z++;
                }
            }
            else if(food_choice==4)
            {
                search_by_hotel();
            }
            else
            {
                printf("\nPlease Enter the valid choice...\n");
                hotel_details(hotel_choice);
            }
    }
}

void cart()
{
    if(total==0)
    {
        printf("\nYou didn't order anything....Please order the food\n");
        swiggy();
    }
    printf("\n\n\n\n--------------Cart----------------\n\n");
    for(i=0;i<p;i++)
    {
            printf("%s-%d                Rs.%d\n",h[i].temp_hotel,h[i].add_count[i],h[i].add_price[i]);
    }
	printf("\nYour Total Order Amount is %d\n",total);
	printf("\nDo you want to add more items in the cart(y=1/n=0): ");
	scanf("%d",&choice);
	if(choice==1)
    {
        swiggy();
    }
	printf("\n\nDo You wish to order (y=1/n=0): ");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("\n\nThank You for your order!! Your Food is on the way. Welcome again!!\n\n");
		exit(1);
	}
	else if(choice==0)
	{
		printf("\nDo You want to exit -1 or Go back -0: ");
		scanf("%d",&confirm);
		if(confirm==1)
		{
			printf("\n\nOops! Your order is cancelled!! Exiting..Thank You :) visit again !\n");
			exit(1);
		}
		else
		{
		    printf("\nDo you want to delete the cart(y=1/n=0):");
		    scanf("%d",&choice);
		    if(choice==1)
            {
                p=0;
                z=0;
                total=0;
            }
			printf("\n\nThank You :)\n\n");
			swiggy();
		}
	}
	else
	{
		printf("\n\nPlease Enter the correct choice\n\n");
		cart();
	}
}

void allocate_hotels()
{
    strcpy(h[1].hotel,"Saravana_bhavan");
    strcpy(h[1].food_one,"Meals");
    strcpy(h[1].food_two,"Plain_roast");
    strcpy(h[1].food_three,"Egg_chapathi");
    h[1].price_one=150;
    h[1].price_two=50;
    h[1].price_three=40;
    strcpy(h[2].hotel,"Barbeque_nation");
    strcpy(h[2].food_one,"Chicken_briyani");
    strcpy(h[2].food_two,"Chicken_Shawarma");
    strcpy(h[2].food_three,"Grill_chicken");
    h[2].price_one=200;
    h[2].price_two=250;
    h[2].price_three=300;
    strcpy(h[3].hotel,"KR_bhavan");
    strcpy(h[3].food_one,"Dosa");
    strcpy(h[3].food_two,"Chapathi");
    strcpy(h[3].food_three,"Mutton_briyani");
    h[3].price_one=15;
    h[3].price_two=20;
    h[3].price_three=150;
    strcpy(h[4].hotel,"Hotel_bharathi");
    strcpy(h[4].food_one,"Mutton_Chukka");
    strcpy(h[4].food_two,"Parotta");
    strcpy(h[4].food_three,"chocolate_icecream");
    h[4].price_one=100;
    h[4].price_two=15;
    h[4].price_three=50;
    strcpy(h[5].hotel,"11<->11_bakes");
    strcpy(h[5].food_one,"Pizza");
    strcpy(h[5].food_two,"Burger");
    strcpy(h[5].food_three,"Sandwich");
    h[5].price_one=120;
    h[5].price_two=70;
    h[5].price_three=70;
}

