#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#define data_size 100

struct tvshows{
	
	char name[40]; 
	char f_t_d[30];
	int  t_eps;
	char tel_days[10];
	char original_r_d[10]; 
	char cast[30];
	char producer[30];
	char writer[30];
	char production_com[30];
};

struct Awards{
	
		char title[30];
        int year;
        char for_the[30]; //for which TV show or movie,
        char category[30];
        int result;
};

struct movies{
	
    char name[30]; 
    char release_date[10];
    char cast[30];
    char producer[30];
    char writer[30];
    char soundtrack[30];
    char production_com[50];
    char budget[20];
    char box_coll[20];
    struct Awards A;
    
}movies;

struct Cast{
	
    char name[50]; 
    char shows[100];
    char movies[100];
    struct Awards A;
};

struct user{
   
    char id_num[20]; 
    int sub_plan;       
    char sub_details[10];  
    char reg_date[10];    
    struct sub_database{           
	 
        char date[10];
        int amount;
    }sub_db;
    struct preferences{       
    	
        char languages[10];
        char fav_genre[10];
    }pref;
    struct viewing_details{      
	
        char movies_watched[100];
        int total_view_time;
    }vd;
    
};

void intialize_shows(struct tvshows s[])
{
	int i;
	for(i=0;i<data_size;i++)
    {
       s[i].name[0] = '\0';
       s[i].f_t_d[0] = '\0';
       s[i].t_eps = 0;
       s[i].tel_days[0] = '\0';
       s[i].original_r_d[0] = '\0';
       s[i].cast[0] = '\0';
       s[i].producer[0] = '\0';
       s[i].writer[0] = '\0';
       s[i].production_com[0] = '\0';
    }
  
}

void intialise_movies(struct movies m[])
{
    int i=0;
    for(i=0;i<data_size;i++)
    {
        m[i].name[0] = '\0';
        m[i].release_date[0] = '\0';
        m[i].cast[0] = '\0';
        m[i].producer[0] = '\0';
        m[i].writer[0] = '\0';
        m[i].soundtrack[0] = '\0';
        m[i].production_com[0] = '\0';
        m[i].budget[0] = '\0';
        m[i].box_coll[0] = '\0';
        m[i].A.title[0] = '\0';
        m[i].A.year= 0;
        m[i].A.for_the[0] = '\0'; // for which TV show or Movie award is won
        m[i].A.category[0] = '\0';
        
    }
}

void intialise_cast(struct Cast c[])
{
   int i=0,SIZE;
   for(i=0;i<data_size;i++)
   {
    c[i].name[0] = '\0';
    c[i].shows[0] ='\0';
    c[i].movies[0] ='\0';
    c[i].A.title[0] = '\0';
    c[i].A.year = 0;
    c[i].A.for_the[0] = '\0';
    c[i].A.category[0] = '\0';
   }
}

void intialise_user(struct user u[])
{
	int i=0;
  	for(i=0;i<data_size;i++)
   	{
       u[i].id_num[0] = '\0';
       u[i].reg_date[0] = '\0';
       u[i].sub_details[0] = '\0';
       u[i].sub_plan = 0; //no of years
       u[i].sub_db.date[0] = '\0';
       u[i].sub_db.amount = 0;
       u[i].pref.languages[0] = '\0';
       u[i].pref.fav_genre[0] = '\0';
       u[i].vd.movies_watched[0] = '\0';
       u[i].vd.total_view_time = 0;
   	}
   
}

void intialize_Awards(struct Awards A[])
{
	int j;
	for (j=0;j<data_size;j++)
    {
        A[j].title[0]   ='\0'; 
        A[j].year    = 0; 
        A[j].for_the[0] ='\0'; 
        A[j].category[0] ='\0';
	    A[j].result = 0; 
 	}
}

int Add_TVshow(struct tvshows s[], char name[],char cast[], char production_com[], int size)
{
    int i=0,found=0,location=0,halt=0;
   
    while(i<data_size&&!halt)
    {
        if(strcmp(s[i].name,name)>=0)
        {
            location=i;
            halt=1;
        }
        i++;
    }
    for(i=size-1;i>=location;i--)
    {
        s[i+1]=s[i];
    }
    i=location;
    strcpy(s[i].name,name);
    strcpy(s[i].cast,cast);
    return location;
}

void add_show_cast(struct Cast c[],char name[],char cast_name[],int size)
{
    int i=0,halt=0,location=0;
    while(i<data_size&&!halt)
    {
        if(strcmp(c[i].name,cast_name)>0||strcmp(c[i].name,"\0")==0)
        {
            location=i;
            halt=1;
        }
        i++;
    }
    for(i=size-1;i>=location;i--)
    {
        c[i+1]=c[i];
    }
    i=location;
    strcpy(c[i].name,name);
    strcpy(c[i].shows,name);
}


void add_user(struct user u[],char id_num[],int sub_plan,char languages[],char fav_genre[],int size)
{
    int i=0,found =0,location=0,halt=0;
    struct user tmp;
    while(i<data_size&&!halt)
    {
        if(strcmp(u[i].id_num,id_num)>0||strcmp(u[i].id_num,"\0")==0)
        {
            location=i;
            halt=1;
        }
        i++;
    }
    for(i=size-1;i>=location;i--)
    {
        u[i+1]=u[i];
    }
    i=location;
    strcpy(u[i].id_num, id_num);
    u[i].sub_plan=sub_plan;
    strcpy(u[i].pref.languages,languages);
    strcpy(u[i].pref.fav_genre,fav_genre);
    i=0;
    while(i<data_size&&!halt)
    {
        if(strcmp(u[i].pref.languages,u[location].pref.languages)==0)
        {
            int a;
            printf("%s",u[i].pref.fav_genre);
            printf("if u want to pick the genre enter 1 else enter 0\n");
            scanf("%d",&a);
            if(a==1)
            {
                strcpy(u[location].pref.fav_genre,u[i].pref.fav_genre);
            }
        }
        else
        {
            printf("Not Matched \n");
        }
    }
}

void Add_Movie(struct movies m[], char name[],char cast[],char production_com[],char title[],int year,int result,int size)
{
    int i=0,found =0,location=0,halt=0;
    
    while(i<data_size&&!halt)
    {
        if(strcmp(m[i].name,name)>=0)
        {
            location=i;
            halt=1;
        }
        i++;
    }
    for(i=size-1;i>=location;i--)
    {
        m[i+1]=m[i];
    }
    i=location;
    strcpy(m[i].name,name);
    strcpy(m[i].cast,cast);
    strcpy(m[i].A.title,title);
    m[i].A.year=year;
}
void update_cast(struct tvshows s[],struct Cast c[],int location,int size)
{
    int i=0,j=0,location1=0,halt=0;
    int found=0;
    while(i<data_size&&!found)
    {
        if(strcmp(c[i].name,s[location].cast)==0)
        {
            found=1;
            location1=i;
        }
        i+=1;
    }
    if(found==1)
    {
        strcpy(c[location1].shows,s[location].cast);
    }
    else
    {
        add_show_cast(c,s[location].name,s[location].cast,size);
    }
        
}



int add_cast(struct Cast c[],char name[],char movies[],char shows[],char title[] ,int year,int size )
{
    int i=0,found =0,location=0,halt=0;
    struct Cast tmp;
    while(i<data_size&&!halt)
    {
        if(strcmp(c[i].name,name)>0||strcmp(c[i].name,"\0")==0)
        {
            location=i;
            halt=1;
        }
        i++;
    }
    for(i=size-1;i>=location;i--)
    {
        c[i+1]=c[i];
    }
    i=location;
    strcpy(c[i].name,name);
    strcpy(c[i].movies,movies);
    strcpy(c[i].A.title,title);
    c[i].A.year=year;
    return location;
}
int validate(struct movies m[],struct Cast c[],int location)
{
    int i=0,found=0,status,location1=0;
    while(i<data_size&&!found)
    {
        if(strcmp(m[i].name,c[location].movies)==0)
        {
            found=1;
            location=i;
        }
        i++;
    }
    if(found==1&&m[location1].A.year==c[location].A.year&&strcmp(m[location].A.title,c[location].A.title)==0)
    {
        status=1;
    }
    else
    {
        status=0;
    }
    return status;
}

int no_of_rec_incast_db(struct Cast c[])
{
    int size=1,i=0;
    while(i<data_size&&strcmp(c[i].name,"\0")!=0)
    {
        i++;
        size++;
    }
    return size;
}

void list_Q2a(struct Cast c[],char cast[])
{
    int i=0,found=0,location=0;
    while(i<data_size&&!found)
    {
        if(strcmp(c[i].name,cast)==0)
        {
            found=1;
            location=i;
        }
        i++;
    }
    if(found==1)
    {
        printf("%s %s \n",c[location].shows,c[location].movies);
    }
    else
    {
        printf(" cast is not found in data \n");
    }

}

void list_Q2c(struct tvshows s[],struct movies m[],char cast[])
{
    int i=0,found=0,location1=0,location2=0;
    while(i<data_size&&!found)
    {
        if(strcmp(s[i].cast,cast)==0)
        {
            found=1;
            location1=i;
        }
        i++;
    }
    i=0;
    int found1=0;
    while(i<data_size&&!found)
    {
        if(strcmp(m[i].cast,cast)==0)
        {
            found1=1;
            location2=i;
        }
        i++;
    }
    if(strcmp(s[location1].production_com,m[location2].production_com)==0)
    {
        printf("%s %s \n",s[location1].name,m[location2].name);
    }
    else
    {
        printf(" any producer didN't produce a both Tv_show and Movie with the given cast\n");
    }


}

void award_won(struct Cast c[])
{
    int i=0,j=0,max,location=0;
    struct Cast temp;
    max=c[0].A.year;
    while(i<data_size&&strcmp(c[i].name,"\0")!=0)
    {
       location=i;
       j=i+1;
       while(j<data_size&&strcmp(c[j].name,"\0")!=0)
       {
            if(c[j].A.year>max)
            {
                location=j;
                max=c[j].A.year;
            }
            j++;
        }

         temp=c[i];
         c[i]=c[location];
         c[location]=temp;
         i++;
    }
    i=0;
    while(i<data_size && strcmp(c[i].name,"\0")!=0)
    {
        printf("%s%s%s%d\n",c[i].shows,c[i].movies,c[i].A.title,c[i].A.year);
        i++;
    }
}

void movie_awd(struct movies m[],char movies[])
{
    int i,found=0,location=0;
    while(i<data_size&&!found)
    {
        if(strcmp(m[i].name,movies)==0)
        {
            found=1;
            location=i;
        }
    }
    if(found==1&&m[location].A.result==1)
    {
        printf("%s \n",m[location].A.title);
    }
    else
    {
        printf("Null award won\n");
    }
}


void category_division(struct user u[])
{
    int i=0,j=0,max,location=0;
    struct user temp;

    while(i<data_size&&u[i].id_num!=0)
    {
       location=i;
       j=i+1;
       while(j<data_size&&u[i].id_num!=0!=0)
       {
            if(u[j].sub_plan>max)
            {
                location=j;
                max=u[j].sub_plan;
            }
            j++;
        }

         temp=u[i];
         u[i]=u[location];
         u[location]=temp;
         i++;
    }
    i=0;
    while(i<data_size&&strcmp(u[i].id_num,"\0")!=0)
    {
        if(u[i].sub_plan>3)
        {
            printf("%d PLATINUM subscriber \n",u[i].sub_plan);
        }
        else if(u[i].sub_plan<=3 && u[i].sub_plan>=1.5)
        {
            printf("%d GOLD subscriber \n",u[i].sub_plan);
        }
        else if(u[i].sub_plan<1.5)
        {
            printf("%d SILVER subscriber \n",u[i].sub_plan);
        }

        i++;
    }
}

void list_4b(struct tvshows s[],struct movies m[])
{
    int i=0,j=0,exist=0;
    while(i<data_size&&strcmp(s[i].name,"\0")==0)
    {
       int found=0;
       while(j<data_size&&strcmp(m[j].name,"\0")==0&&!found)
       {
           if(strcmp(s[i].cast,m[j].cast)==0)
           {
                printf("%s %s %s \n",s[i].name,m[j].name,s[i].cast);
                found=1;
                exist=1;
           }
           j++;
       }
       i++;
    }
    if(exist==0)
    {
        printf("Null match found\n");
    }
}
int main()
{
    printf("\n========WELCOME TO NETFLIX=========\n");
		
	struct tvshows s[data_size];
    struct movies m[data_size];
    struct Cast c[data_size];
    struct user u[data_size];
    int a,b,i,n;
    char name[40], cast[30], title[50], movies[50], movie[50], production_com[30],fav_genre[10],shows[100],languages[10],identity_num[30];
    int result,sub_plan,year,valid;
        
                   	
	printf("\nHow many Tvshow records do you want to add :-");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		
		printf("enter the tv show data \n");
		printf("\nEnter the name of Tv_Show :");
		scanf("%s",name);
		printf("\nEnter the cast :");
		scanf("%s",cast);
		printf("\nEnter the production_company :");
		scanf("%s",production_com);
		a=Add_TVshow(s,name,cast,production_com,i+1);
		update_cast(s,c,a,i+1);
    }
       					     
	    printf("No of  Movie records  to be  added :- \n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			
			printf("\nENTER THE DATA FOR MOVIE : \n");
			printf("\nEnter name of the Movie\n");
			scanf("%s",name);
			printf("\nEnter the Cast :");
			scanf("%s",cast);
			printf("\nEnter the Title to the  Award :");
			scanf("%s",title);
			printf("\nYear in which award is won :");
			scanf("%d",&year);
			printf("\nName of production_company :");
       		scanf("%s",production_com);
       		printf("Enter the result:\n");
       		scanf("%d",&result);
			Add_Movie(m,name,cast,production_com,title,year,result,i+1);
		}
	
		
		for(i=0;i<n;i++)
		{
		
			printf("Enter the cast details :\n");
			printf("\nEnter the cast :");
			scanf("%s",name);
			printf("\nEnter the movies :");
			scanf("%s",movies);
			printf("\nEnter the Tv_Show");
       		scanf("%s",shows);
			printf("\nEnter the title of award :");
			scanf("%s",title);
			printf("\nEnter the year in which award is won :");
			scanf("%d",&year);
			b=add_cast(c,name,movies,shows,title,year,no_of_rec_incast_db(c));
			valid=validate(m,c,b);
			printf("%d",valid);
		}
						
			
		for(i=0;i<n;i++)
     	{
        
         	printf("\nUser data to store :");
        	printf("\nEnter the user id_number :");
         	scanf("%s",identity_num);
        	printf("\nEnter the subscription_plan :");
         	scanf("%d",&sub_plan);
         	printf("\nEnter the language preferred  :");
         	scanf("%s",languages);
         	printf("\nEnter your favorite genres :");
         	scanf("%s",fav_genre);
         	add_user(u,identity_num,sub_plan,languages,fav_genre,i+1);
         	
         
     	}
		
		
	
		printf("Cast to list Tv_show and Movie in descendingorder years:\n");
		scanf("%s",cast);
		list_Q2a(c,cast);
	
		
		printf("Movie name want to list award won:\n");
		scanf("%s",cast);
		list_Q2c(s,m,cast);
    
	   
		printf("Cast name for which u want to list Tv_show and movies by common producer:\n");
		scanf("%s",cast);
		movie_awd(m,movies);
				    
				
	return 0;	
}
						
					
     	
    
 	


