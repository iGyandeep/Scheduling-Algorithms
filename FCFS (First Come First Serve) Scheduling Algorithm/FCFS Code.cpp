#include<stdio.h>
#include<stdlib.h>
//print function
void print(int p[][6], int n) {
	int i, j;
	printf("Process Id\tArrival Time\tCPU Brust\tI/O Brust\tTurnAround Time\t\tWaiting Time\n");
	for (i=0; i<n; i++) {
		for (int j=0; j<6; j++) {
			printf("\t%d\t",p[i][j]);
		}
		printf("\n");
	}
};
//sort function: on all the data on the basis of Arival Time
void sort(int p[][6], int n) {
	int temp[4], i, j, k;
	for (j=1; j<2; j++) {
		for (i=1; i<n; i++) {
			for (k=0; k<n-i; k++) {
				if (p[k][j] > p[k+1][j]) {
//					Sort Arrival Time
					temp[1] = p[k][j];
					p[k][j] = p[k+1][j];
					p[k+1][j] = temp[1];
					
//					Sort P_id
					temp[0] = p[k][0];
					p[k][0] = p[k+1][0];
					p[k+1][0] = temp[0];
					
//					Sort CPU Brust
					temp[2] = p[k][2];
					p[k][2] = p[k+1][2];
					p[k+1][2] = temp[2];
					
//					Sort I/O Brust
					temp[3] = p[k][3];
					p[k][3] = p[k+1][3];
					p[k+1][3] = temp[3];
				}
			}
			
		}
	}
};
//Turnaround Function
void turnAroundTime(int p[][6], int n) {
	int temp = 0, i;
	for (i=0; i<n; i++) {
		p[i][4] = (p[i][2] + p[i][3] + temp) - p[i][1];
		temp = p[i][4] + p[i][1];
	}
};
//Waiting Time Function
void waitingTime(int p[][6], int n) {
	int i;
	for (i=0; i<n; i++) {
		p[i][5] = p[i][4] - p[i][2];
	}
};
//CPU Utilization Function
float CPU_Util(int p[][6], int n) {
	int cpuUses = 0, i;
	for (i=0; i<n; i++) {
		cpuUses += p[i][2];
	}
	return float((cpuUses) * 100)/(p[n-1][4] + p[n-1][1]);
}
//Average Turnaround Time Function
float avgTAT(int p[][6], int n) {
	int total_TAT = 0, i;
	for (i=0; i<n; i++) {
		total_TAT += p[i][4];
	}
	return float(total_TAT)/n;
}
//Average Waiting Time Function
float avgWT(int p[][6], int n) {
	int total_WT = 0, i;
	for (i=0; i<n; i++) {
		total_WT += p[i][5];
	}
	return float(total_WT)/n;
}
//Main Function
int main()
{
	int p[10][6] = {0}, n, i, j;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	
//	Input the Process id, Arrival time, CPU Burst and I/O Brust of a process
	printf("Enter process id no., Arrival Time, CPU Burst and I/O Burst: \n");
	for (i=0; i<n; i++) {
		for (j=0; j<4; j++) {
			scanf("%d",&p[i][j]);
		}
	}
//	Clear the Screen for clean result
	system("cls");
	
//	Print the inputed data
	printf("Inputed Data Before Calculation:- \n");
	print(p,n);
	
//	Sort the data by using sort() function:
	sort(p,n);
	
//	Calculate and Store Turnaroud Time
	turnAroundTime(p,n);
	
//	Calculate and Store Waiting Time
	waitingTime(p,n);
	
	printf("====================================================================================================================\n");
	
//	Print the resut after processing
	printf("Inputed Data After Calculation:- \n");
	print(p,n);
	printf("\n\n");
	
	printf("CPU Utilization = %.2f %%",CPU_Util(p, n));
	printf("\n");
	
	printf("Throughput = %d/%d",n,p[n-1][4]+p[n-1][1]);
	printf("\n");
	
	printf("Average Turnaround Time = %.2f",avgTAT(p,n));
	printf("\n");
	
	printf("Average Waiting Time = %.2f", avgWT(p,n));
}
