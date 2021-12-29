#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, total=0, pos, temp, *v, *bt, *wt, *tat, *p;
	float avgwt = 0, avgtat = 0;
	printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));
    v = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
 	
    printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
	printf("p%d : , i+1);
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    printf("\n enter the arrival time for each process \n");
    for(i=0 ; i<n ; i++)
    {
	printf("p%d" : " , i+1);
	printf("the arrival time for p%d : ",i);
	scanf("%d" , &v[i]);
	p[i]=i+1;
     }

    for(i=0; i<n; i++)
    {
    	pos = i;
    	for(j=i+1; j<n; j++)
    	{
    		if(bt[j] < bt[pos])
    		{
    			pos = j;
    		}
    	}
    	temp = bt[i];
    	bt[i] = bt[pos];
    	bt[pos] = temp;

    	temp = p[i];
    	p[i] = p[pos];
    	p[pos] = temp;
    }

    wt[0] = 0;
    tat[0] = bt[0];
     avgwt += wt[0];
        avgtat += tat[0]; 
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];  
        tat[i] = wt[i] + bt[i];     
        
         avgwt += wt[i];
        avgtat += tat[i]; 
    }

    
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n PROCESS \t BURST TIME \t Arrival Time \t WAITING TIME \t TURNAROUND TIME \n");
    printf("-----------------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i], bt[i], v[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("-------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}
