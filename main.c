#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>


void lab6();
void lab9();
int lab10();
int lab11();


int i,j,ec,fg,ec2;
char fn[20],e,c;

FILE *fp1,*fp2,*fp;

void Create();
void Append();
void Delete();
void Display();
void display();
void getdata();
void waitTime();
void turnAroundTime();


int n,a[100],b[100];


int main()
 {
     int a;
     printf("\t\tOS PROJECT\n\n\n");
xxx:
    printf("LABS:\n\t1.LAB6\n\t2.LAB9\n\t3.LAB10\n\t4.LAB11\nEnter Number[1:4]: ");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        lab6();
        break;
    case 2:
        lab9();
        break;
    case 3:
        lab10();
        break;
    case 4:
        lab11();
        break;
    default:
        printf("\nPlease Choose from 1 to 4 ONLY!\n");
    goto xxx;

    }
}


//LAB6
void lab6()
{
    do
    {
        printf("\n\t\t***TEXT EDITOR***");
        printf("\n\n\tMENU:\n\t-----\n ");
        printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.DELETE\n\t5.EXIT\n");
        printf("\n\tEnter your choice: ");
        scanf("%d",&ec);
        switch(ec)
        {
        case 1:
            Create();
            break;
        case 2:
            Display();
            break;
        case 3:
            Append();
            break;
        case 4:
            Delete();
            break;
        case 5:
            exit(0);
        }
    }
    while(1);
}
void Create()
{
    fp1=fopen("temp.text","w");
    printf("\n\tEnter the text and press '.' to save\n\n\t");
    while(1)
    {
        c=getchar();
        fputc(c,fp1);
        if(c=='.')
        {
            fclose(fp1);
            printf("\n\tEnter then new filename: ");
            scanf("%s",fn);
            fp1=fopen("temp.txt","r");
            fp2=fopen(fn,"w");
            while(!feof(fp1))
            {
                c=getc(fp1);
                putc(c,fp2);
            }
            fclose(fp2);
            break;
        }
    }

}
void Display()
{
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1==NULL)
    {
        printf("\n\tFile not found!");
        goto end1;
    }
    while(!feof(fp1))
    {
        c=getc(fp1);
        printf("%c",c);
    }
    end1:
    fclose(fp1);
    printf("\n\n\tPress any key to continue...");
    getch();
}
void Delete()
{
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1==NULL)
    {
        printf("\n\tFile not found!");
        goto end2;
    }
   fclose(fp1);
   if(remove(fn)==0)
   {
       printf("\n\n\tFile has been deleted successfully!");
       goto end2;
   }
   else
    printf("\n\tError!\n");
   end2: printf("\n\n\tPress any key to continue...");
   getch();
 }
 void Append()
 {
     printf("\n\tEnter the file name: ");
     scanf("%s",fn);
     fp1=fopen(fn,"r");
     if(fp1==NULL)
     {
         printf("\n\tFile not found!");
         goto end3;
     }
     while(!feof(fp1))
     {
         c=getc(fp1);
         printf("%c",c);
     }
     fclose(fp1);
     printf("\n\tType the text and press 'Ctrl+S' to append.\n");
     fp1=fopen(fn,"a");
     while(1)
     {
         c=getch();
         if(c==19)
         goto end3;
         if(c==13)
         {
             c='\n';
             printf("\n\t");
             fputc(c,fp1);
         }
         else {
            printf("%c",c);
            fputc(c,fp1);
         }
     }
     end3: fclose(fp1);
     getch();
 }
//___________________________________

//LAB9


void lab9()
{
    int a[20],b[20],d,n,i,j,temp,s,k=0,x=0,t=0;
       printf("|||| Shortest Seek Time First, Disk Scheduling Alogrithm ||||\n\n\n");
    printf("Enter head pointer position:");
    scanf("%d",&a[0]);
    printf("\nEnter number of process:");
    scanf("%d",&n);
    printf("\nEnter processes in request order\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[k++]=a[0];
    for(i=0;i<n;i++)
    {
        s=1000;
        for(j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
            d=a[i]-a[j];
            else
                d=a[j]-a[i];
            if(d<s)
            {
                s=d;
                x=j;
            }
        }
        t+=s;
        temp=a[i+1];
        a[i+1]=a[x];
        a[x]=temp;
        b[k++]=a[i+1];
    }
    printf("\nProcessing order:");
    for(i=0;i<=n;i++)
        printf("\t%d",b[i]);
        printf("\nTotal Head Movement:%d",t);
        getch();
}

//___________________________________



//LAB10
int lab10()
{
    printf("|||| First Come First Serviced, CPU Scheduling Alogrithm ||||\n\n\n");
    getdata();
    display();
    waitTime();
    turnAroundTime();
    getch();
}
void getdata()
{
    char c;
    int i;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("\nDo you need to enter the arrival time of process [y/n] or [Y/N] ?\n");
    scanf("%s",&c);
    for(i=0;i<n;i++)
    {
        printf("Enter the %d process burst time: ",i+1);
        scanf("%d",&b[i]);
        if(c=='y' || c=='Y')
        {
            printf("Enter the %d process arrival time: ",i+1);
            scanf("%d",&a[i]);
        }
        else
        {
            a[i]=0;
        }
    }
}
void display()
{
    int i;
    printf("\nPROCESS\t\tBURST TIME\tARRIVAL TIME\n");
    for(i=0;i<n;i++)
    {
        printf("  %d\t\t    %d\t\t    %d\n",i+1,b[i],a[i]);
    }
}
void waitTime()
{
    int w[100];
    int i;
    float totalWait=0;
    w[0]=0;
    for(i=1;i<n;i++)
    {
        w[i]=b[i-1]-a[i]+w[i-1];
        totalWait=w[i]+totalWait;
    }
    printf("\nTotal Waiting time = %f",totalWait);
    printf("\nAverage Waiting time = %f",totalWait*1.0/n);
}
void turnAroundTime()
{
    int tat[100];
    int i;
    float totalTat=0;
    tat[-1]=0;
    for(i=0;i<n;i++)
    {
        tat[i]=b[i]-a[i]+tat[i-1];
        totalTat=totalTat+tat[i];
    }
    printf("\n\nTotal Turn Around Time(TAT)= %f",totalTat);
    printf("\nAverage Turn Around Time Avg.(TAT)= %f",totalTat*1.0/n);
}
//___________________________________



//LAB11
int lab11()
{
    int time,bt[10],at[10],sum_bt=0,smallest,n,i;
    int sum_turnaround=0,sum_wait=0;
    printf("|||| Shortest Job First, CPU Scheduling Alogrithm ||||\n\n\n");
    printf("Enter no of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for process P%d : ",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for process P%d : ",i+1);
        scanf("%d",&bt[i]);
        sum_bt+=bt[i];
    }
    bt[9]=9999;
    printf("\n\nProcess\tTurnaround Time\t Waiting Time\n\n");
    for (time=0;time<sum_bt;)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time&&bt[i]>0&&bt[i]<bt[smallest])
                smallest=i;
        }
        if(smallest==9)
        {
            time++;
            continue;
        }
        printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+bt[smallest]-at[smallest],time-at[smallest]);
        sum_turnaround+=time+bt[smallest]-at[smallest];
        sum_wait+= time-at[smallest];
        time+=bt[smallest];
        bt[smallest]=0;
    }
    printf("\n\nAverage waiting time = %f",sum_wait*1.0/n);
    printf("\n\nAverage turnaround time = %f",sum_turnaround*1.0/n);
    return 0;
}

//___________________________________
