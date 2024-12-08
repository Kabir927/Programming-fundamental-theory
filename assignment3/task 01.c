#include<stdio.h>

struct date{
	int day;
	int month;
	int year;
};
struct employee{
	int employee_code;
	char employee_name[30];
	struct date dateOfJoining;
};

void assigndate(struct employee *employees){
	printf("enter the code of employee: ");
	scanf("%d",&employees->employee_code);
	getchar();
	printf("enter the name of employee: ");
	fgets(employees->employee_name,30,stdin);
	printf("enter the joining day of employee: ");
	scanf("%d",&employees->dateOfJoining.day);
	printf("enter the joining month of employee: ");
	scanf("%d",&employees->dateOfJoining.month);
	printf("enter the joining year of employee: ");
	scanf("%d",&employees->dateOfJoining.year);	
}
int calculate_tenure(struct date doj,struct date current_date){
	int years=current_date.year-doj.year;
	int months=current_date.month-doj.month;
	int days=current_date.day-doj.day;
	if(days<0){
		months--;
	}
	if(months<0){
		years--;
	}
	return years;
}
void check_tenure(struct employee employees[],int n){
	struct date current_date;
	int count=0;
	
	printf("enter the current date(dd mm yyyy)\n");
	scanf("%d%d%d",&current_date.day,&current_date.month,&current_date.year);
	printf("employees tenure with more than 3 years\n");
	for(int i=0;i<n;i++){
		int tenure=calculate_tenure(employees[i].dateOfJoining,current_date);
		if(tenure>3){
			printf("code:%d\nname:%s\ndate of joining:%d %d %d of employee %d\n",
	employees[i].employee_code,employees[i].employee_name,employees[i].dateOfJoining.day,employees[i].dateOfJoining.month,employees[i].dateOfJoining.year,i+1);
			printf("tenure %d years\n",tenure);
			count++;
		}
	}
	printf("\n");
	printf("total employees with tenure of more than 3 year:%d\n",count);	
}
int main(){
	int n=4;
	struct employee employees[n];
	for(int i=0;i<n;i++){
		printf("enter details for employee %d:\n",i+1);
		assigndate(&employees[i]);
		printf("\n");
	}
	check_tenure(employees,n);
}
