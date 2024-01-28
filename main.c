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
//---------------------------------------------------------------------------------
int taskNo = 0;
void addtask(task tasks[]) {
	
    if (taskNo < 50) {  
        tasks[taskNo].taskNo = taskNo + 1;

        printf("Enter the task title: \n");
        scanf(" %[^\n]s", tasks[taskNo].title);
			getchar();
        printf("Enter task priority: (Low/Meduim/High) \n");
        scanf(" %[^\n]s", tasks[taskNo].priority);
			getchar();
        printf("Enter task description: \n");
        scanf(" %[^\n]s", tasks[taskNo].description);
			getchar();
        printf("Enter due date (day month year) in 01/01/0000 format: \n");
        scanf("%d %d %d", &tasks[taskNo].dueDate.day, &tasks[taskNo].dueDate.month, &tasks[taskNo].dueDate.year);
        getchar();
        taskNo++;
        printf("Task added successfully!\n");
        //exit(0) ;
    } else {
        printf("Cannot add more tasks.\nTask limit reached, please delete the completed tasks. \n");
        exit(0) ;
    }
}
//-------------------------------------------------------------------------------------------------------------
void listallTasks(task tasks[]){
	int i = 0;
	while (taskNo != 0 && i < taskNo ){
		printf("Task number #%d:\n", tasks[i].taskNo);
        printf("Title: %s\n", tasks[i].title);
        printf("Priority: %s\n", tasks[i].priority);
        printf("Description: %s\n", tasks[i].description);
        printf("Due Date: %02d/%02d/%04d\n", tasks[i].dueDate.day, tasks[i].dueDate.month, tasks[i].dueDate.year);
        i++;
	}  
		printf("\nthere is no tasks to show, add some !\n\n");
}
//-------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	
	int choice;
	task tasks[50];
	
		printf("welcome to the task management software.\n\n");
	
	do{
		printf("type a number according to your choice:\n");
		
		printf("1. add a task. \n");
		printf("2. edit a task. \n");
		printf("3. delete a task. \n");
		printf("4. filter the tasks. \n");
		printf("5. list all the tasks. \n");
		printf("6. sort the tasks by date. \n");
		printf("0. exit and close the software. \n");
		scanf("%d",&choice);
		getchar();
			if (choice == 1) {
				
     			addtask(tasks);
 			} else if (choice == 2) {
        
  			} else if (choice == 3) {
        
  			} else if (choice == 4) {
        
  			} else if (choice == 5) {
  				
  		    	listallTasks(tasks);
 			} else if (choice == 6) {
 				
   		 	} else if (choice == 0) {
        		printf("Exiting the program.\n");
    		} else {
       	 		printf("Invalid choice, Please type a number from the list above.\n");
    		}
		}	while (choice != 0);
	
return 0;
} 

