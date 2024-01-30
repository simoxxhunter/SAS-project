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
void addAtask(task tasks[]) {
    if (taskNo < 50) {  
        tasks[taskNo].taskNo = taskNo ;
    
        printf("Enter the task title for the task number %d :\n",taskNo);
        scanf(" %[^\n]", tasks[taskNo].title);
			getchar(); 
        printf("Enter task priority: (Low/Meduim/High) \n");
        scanf(" %[^\n]", tasks[taskNo].priority);
			getchar();
        printf("Enter task description: \n");
        scanf(" %[^\n]", tasks[taskNo].description);
			getchar();
        printf("Enter due DAY (a number between 1-31):\n");
        scanf("%d", &tasks[taskNo].dueDate.day);

        printf("Enter due MONTH (a number between 1-12):\n");
        scanf("%d", &tasks[taskNo].dueDate.month);
        
        printf("Enter due YEAR:\n");
        scanf("%d", &tasks[taskNo].dueDate.year);
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
int i = 0;
void listallTasks(task tasks[]){
	
	while (taskNo != 0 && i <= taskNo - 1){
			printf("-------------------------------------------------\n");
			printf("\nTask number #%d:\n", tasks[i].taskNo);
       		printf("Title: %s\n", tasks[i].title);
        	printf("Priority: %s\n", tasks[i].priority);
        	printf("Description: %s\n", tasks[i].description);
        	printf("Due Date: %d/%d/%d\n", tasks[i].dueDate.day, tasks[i].dueDate.month, tasks[i].dueDate.year);
        	printf("-------------------------------------------------\n");
        	i++;
	}if (i == 0){
		printf("\nthere is no tasks to show, add some !\n\n");
	}
}
//-------------------------------------------------------------------------------------
int taskNotoedit = 0;
void editAtask(task tasks[]){
	
	printf("please enter the TaskNo that you want to edit :\n");
	scanf("%d",&taskNotoedit);
	
	if ( taskNo >= 0 && taskNotoedit < taskNo ){
		printf("you are currently editing task number : %d \n", taskNotoedit);
		
		printf("Enter the new title for the task number %d : \n",taskNo - 1);
        scanf(" %[^\n]", tasks[taskNotoedit].title);
			getchar();
        printf("Enter the new task priority value: (Low/Meduim/High) \n");
        scanf(" %[^\n]", tasks[taskNotoedit].priority);
			getchar();
        printf("Enter the new task description: \n");
        scanf(" %[^\n]", tasks[taskNotoedit].description);
			getchar();
        printf("Enter the new due DAY (a number between 1-31):\n");
        scanf("%d", &tasks[taskNotoedit].dueDate.day);

        printf("Enter the new due MONTH (a number between 1-12):\n");
        scanf("%d", &tasks[taskNotoedit].dueDate.month);
        
        printf("Enter the new due YEAR:\n");
        scanf("%d", &tasks[taskNotoedit].dueDate.year);
        //	getchar();
    
        printf("Task edited successfully !\n");
    	//exit(0) ;
		
		} else {
			printf("invalid task number ! please retry.");
		}
}
//-------------------------------------------------------------------------------------
int taskNoTOdelete = 0;

void deleteAtask(task tasks[]){
	printf("Please enter the task number that you want to delete:\n");
	scanf("%d",&taskNoTOdelete);
	
	while(taskNoTOdelete < taskNo - 1 && taskNo > 0){
		tasks[taskNoTOdelete] = tasks[taskNoTOdelete + 1];
		printf("Task number %d has been deleted successfully.\n", taskNoTOdelete);
		taskNoTOdelete++;
	}
	taskNo--;
	if (taskNo == 0){
		printf("\nthere is no tasks to delete !\n");
	}else if(taskNoTOdelete > taskNo){
		printf("invalid task number ! please enter a number below %d :\n",taskNo);
	}
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
     			addAtask(tasks);
 			} else if (choice == 2) {
        		editAtask(tasks);
  			} else if (choice == 3) {
        		deleteAtask(tasks);
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

