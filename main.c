#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct {
	int day;
	int month;
	int year;
	
}date;
typedef struct {
	int	 taskNo;
	char title[25];
	char priority[10];
	char description[250];
	date dueDate;
	
}task;
	
int numTasks = 1;
void addtask(task tasks[]) {
	
    if (numTasks < 1) {  
        tasks[numTasks].taskNo = numTasks + 1;

        printf("Enter the task title: \n");
        scanf("%s", tasks[numTasks].title);

        printf("Enter task priority: (Low/Meduim/High) \n ");
        scanf("%s", tasks[numTasks].priority);

        printf("Enter task description: \n");
        scanf("%s", tasks[numTasks].description);

        printf("Enter due date (day month year) in 01/01/0000 format: \n");
        scanf("%d %d %d", &tasks[numTasks].dueDate.day, &tasks[numTasks].dueDate.month, &tasks[numTasks].dueDate.year);
        numTasks++;

        printf("Task added successfully!\n");
        exit(0) ;
    } else {
        printf("Cannot add more tasks.\nTask limit reached, please delete the completed tasks. \n");
        exit(0) ;
    }
}




int main(int argc, char *argv[]) {
	
	int choice;
	task tasks[50];
	
	printf("welcome to the task management software \n");
	printf("type a number according to your choice: \n \n");
	
	printf("1. add a task. \n");
	printf("2. edit a task. \n");
	printf("3. delete a task. \n");
	printf("2. filter the tasks. \n");
	printf("4. list all the tasks. \n");
	printf("5. sort the tasks by date. \n");
	printf("0. exit and close the software. \n");
	scanf("%d",&choice);
	do{
		if(choice == 1){
			addtask(tasks);
		}
	}
	while (choice != 0);
	
	return 0;
}

