#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
struct person
{
int id;
int burst;
int arr;
int pri,wait,turn,ctime;
};

void getData(struct person p[20],int n)
{
	int i;
    for (i = 0; i < n; i++)
    {
        printf("\nGive data for Person\n");
        printf("\nPerson id : ");
        scanf("%d",&p[i].id);
        printf("\nGive Burst time in minuts :");
        scanf("%d",&p[i].burst);
    }
	p[i].wait = 0;
	p[i].turn = 0; 
}

void displayData(struct person p[20],int n)
{
	int i;
	int avgWait = 0;
	int avgTurn = 0;
    for (i = 0; i < n; i++)
    {
        printf("\n Data for Person of %d\n",(i+1));
        printf("Person id : %d\n",p[i].id);
        printf("Burst time in minuts : %d\n",p[i].burst);
        printf("Waiting time : %d\n",p[i].wait);
        printf("Turnaround time : %d\n",p[i].turn);
    }
    for (i = 0; i < n; i++)
    {
    	avgWait += p[i].wait;
    	avgTurn += p[i].turn;
	}
	printf("Avg Waiting time : %d\n",(avgWait/n));
    printf("Avg Turnaround time : %d\n",(avgTurn/n));
}

void sortData(struct person p[20],int n)
{
	int i,j;
	struct person temp;
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(p[j].burst<p[j+1].burst)
			{
				temp = p[j];
				p[j]=p[j+1];
				p[j+1] = temp;
			}
			else if (p[j].burst=p[j+1].burst)
			{
				if(p[j].id<p[j+1].id)
				{
					temp = p[j];
					p[j]=p[j+1];
					p[j+1] = temp;
				}
			}
		}
	}
}

void cal(struct person p[20],int n)
{
	int time = 0;
	int i;
	for(i = 0;i<n;i++)
	{
		p[i].wait = time;
		p[i].turn = time+p[i].burst ;
		time += p[i].burst;
	}
	
}


void main ()
{
	int n,i;
	struct person p[20];
	printf("Enter no. of person: ");
	scanf("%d",&n);
	getData(p,n);
	sortData(p,n);
	cal(p,n);
	displayData(p,n);
}
