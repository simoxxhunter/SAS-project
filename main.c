#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
	char status[20];
}task;
//---------------------------------------------------------------------------------
FILE *addedTasks;
FILE *editedTasks;
char name[20],role[20];
int taskNo = 0;

void addAtask(task tasks[]) {
    if (taskNo < 50) { 
	
        tasks[taskNo].taskNo = taskNo ;
    	
    	strcpy(tasks[taskNo].status, "uncomplet"); 
    	
        printf("Enter a title for the task number %d :\n",taskNo);
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
        	
		addedTasks = fopen("C:\\Users\\LENOVO\\Desktop\\tasks.txt", "a");
		fprintf(addedTasks, "Task number #: %d\n Title: %s\n Priority: %s\n Description: %s\n Due Date: %d/%d/%d\n Added by: %s | %s\n ",
			tasks[taskNo].taskNo,
            tasks[taskNo].title,
            tasks[taskNo].priority,
            tasks[taskNo].description,
            tasks[taskNo].dueDate.day,
            tasks[taskNo].dueDate.month,
            tasks[taskNo].dueDate.year,
            tasks[taskNo].status,
            name,role);
		fclose(addedTasks);	
        taskNo++;
        printf("Task added successfully!\n");
        //exit(0) ;
        
    } else {
        printf("Cannot add more tasks.\nTask limit reached, please delete the completed tasks. \n");
        exit(0) ;
    }
}
//-------------------------------------------------------------------------------------------------------------
void listallTasks(task tasks[]) {
    int i = 0;
    
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-8s | %-20s | %-10s | %-30s | %-10s | %-15s | %-15s | %-10s\n", "Task No", "Title", "Priority", "Description", "Due Date", "Status", "Name", "Role");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (taskNo != 0 && i <= taskNo - 1) {
        printf("| %-8d | %-20s | %-10s | %-30s | %-2d/%-2d/%-4d | %-15s | %-15s | %-10s \n",
               tasks[i].taskNo,
               tasks[i].title,
               tasks[i].priority,
               tasks[i].description,
               tasks[i].dueDate.day,
               tasks[i].dueDate.month,
               tasks[i].dueDate.year,
			   tasks[i].status,
			   name,role);
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
        i++;
    }
    if (i == 0) {
        printf("\nThere are no tasks to show. Add some!\n\n");
    }
}

//-------------------------------------------------------------------------------------
int taskNotoedit = 0;
void editAtask(task tasks[]){
	int infotoedit = 0;
	
/*	printf("would you like to edit just the Status or the task info ?\n");
	printf("1.to edit task's status.\n2.to edit task's info.\n");
	scanf("%d",&infotoedit);
	getchar();*/
	
	printf("please enter the TaskNo that you want to edit :\n");
	scanf("%d",&taskNotoedit);
	getchar();
	
/*	if(infotoedit == 1){
		printf("please enter the new status for task number %d: \n",taskNotoedit);
		scanf(" %[^\n]", tasks[taskNotoedit].status);
		getchar();
	//	return 0;
	}else if(infotoedit == 2)
	{*/
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
    	editedTasks = fopen("C:\\Users\\LENOVO\\Desktop\\editedTasks.txt", "a");
		fprintf(editedTasks, "Task number #: %d\n Title: %s\n Priority: %s\n Description: %s\n Due Date: %d/%d/%d\n Last Edited by: %s | %s ",
			tasks[taskNotoedit].taskNo,
            tasks[taskNotoedit].title,
            tasks[taskNotoedit].priority,
            tasks[taskNotoedit].description,
            tasks[taskNotoedit].dueDate.day,
            tasks[taskNotoedit].dueDate.month,
            tasks[taskNotoedit].dueDate.year,
            name,role);
		fclose(editedTasks);
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
void filterbypriority(task tasks[]){
	char priorityTOsearchfor[10];
	
	if(taskNo != 0){
		int i=0;
		printf("Please enter the priority you want to filter by: \n");
		scanf("%s",priorityTOsearchfor);
		
		if(strcmp(priorityTOsearchfor, "Low") == 0 || strcmp(priorityTOsearchfor, "Meduim") == 0 ||strcmp(priorityTOsearchfor,"High" ) == 0){
			while(strcmp(tasks[i].priority, priorityTOsearchfor) == 0){
				
			printf("\nTask number #%d:\n", tasks[i].taskNo);
       		printf("Title: %s\n", tasks[i].title);
        	printf("Priority: %s\n", tasks[i].priority);
        	printf("Description: %s\n", tasks[i].description);
        	printf("Due Date: %d/%d/%d\n", tasks[i].dueDate.day, tasks[i].dueDate.month, tasks[i].dueDate.year);
        	printf("-------------------------------------------------\n");
        	i++;
			}		
		}
		printf("no tasks are found with that priority !\n");
		printf("pelase enter a valid priority value, Low/Meduim/High\n");
		
	}else{
		printf("no tasks to search in\n");
		}
}
//-------------------------------------------------------------------------------------
void ascendingorder(task tasks[]){
	int i,j;
	
	while(i < taskNo){
		j = i;
		while(j < taskNo){
			if ((tasks[i].dueDate.year > tasks[j].dueDate.year) ||
   		 		((tasks[i].dueDate.year == tasks[j].dueDate.year) &&
    			((tasks[i].dueDate.month > tasks[j].dueDate.month) ||
    			((tasks[i].dueDate.month == tasks[j].dueDate.month) &&
    			(tasks[i].dueDate.day > tasks[j].dueDate.day))))){
        		task tmp;
                tmp = tasks[i];
                tasks[i] = tasks [j];
                tasks[j] = tmp;
            }
            j++;
		}
		i++;
	}
	listallTasks(tasks);
}
//-------------------------------------------------------------------------------------
void descendingorder(task tasks[]){
	int i,j;
	
	while(i < taskNo){
		j = i;
		while(j < taskNo){
			if ((tasks[i].dueDate.year < tasks[j].dueDate.year) ||
   		 		((tasks[i].dueDate.year == tasks[j].dueDate.year) &&
    			((tasks[i].dueDate.month < tasks[j].dueDate.month) ||
    			((tasks[i].dueDate.month == tasks[j].dueDate.month) &&
    			(tasks[i].dueDate.day < tasks[j].dueDate.day))))){
        		task tmp;
                tmp = tasks[i];
                tasks[i] = tasks [j];
                tasks[j] = tmp;
            }
            j++;
		}
		i++;
	}
	listallTasks(tasks);
}
//-------------------------------------------------------------------------------------
void taskstatus(task tasks[]){

	if ( taskNo >= 0 && taskNotoedit < taskNo ){
		
	printf("please enter the TaskNo that you want to edit its status:\n");
	scanf("%d",&taskNotoedit);
	getchar();
	
		printf("please enter the new status for task number %d: \n",taskNotoedit);
		scanf(" %[^\n]", tasks[taskNotoedit].status);
		
	}listallTasks(tasks);
}
//-------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {
	
	int choice;
	//char name[20],role[20];
	task tasks[50];
	
		printf("welcome to the task management software.\n\n");
		printf("Please enter your full name:\n");
		scanf("%[^\n]",name);
		getchar();
		printf("Please enter your role:\n");
		scanf("%[^\n]",role);
		getchar();
		printf("Good Morning %s !\n",name);
		printf("press enter to continue:\n");
		getchar();
	do{
		printf("type a number according to your choice:\n");
		
		printf("1. add a task. \n");
		printf("2. edit a task. \n");
		printf("3. delete a task. \n");
		printf("4. filter the tasks. \n");
		printf("5. list all the tasks. \n");
		printf("6. sort the tasks by date. \n");
		printf("7. edit a task's status'. \n");
		printf("0. exit and close the software. \n");
		scanf("%d",&choice);
		getchar();
			if (choice == 1) {
				printf("\n== Adding a task ==\n");
     			addAtask(tasks);
 			} else if (choice == 2) {
 				printf("\n== Editing a task ==\n");
        		editAtask(tasks);
  			} else if (choice == 3) {
  				 printf("\n== Deleting a task ==\n");
        		deleteAtask(tasks);
  			} else if (choice == 4) {
  				printf("\n== Filtering tasks by priority ==\n");
        		filterbypriority(tasks);
  			} else if (choice == 5) {
  				printf("\n== Listing all tasks ==\n");
  		    	listallTasks(tasks);
 			} else if (choice == 6) {
 				 printf("\n== Sorting tasks by date ==\n");
 				int sortchoice;
					printf("in what date order would you like to sort the tasks ? \n");
					printf("1. ascending. \n");
					printf("2. descending. \n");
	
					scanf("%d",&sortchoice);
					if(sortchoice == 1) {
						 printf("Sorting in ascending order...\n");
						ascendingorder(tasks);
					}else if(sortchoice == 2) {
						printf("Sorting in descending order...\n");
						descendingorder(tasks);
					}else{
						printf("the only valid option is either 1 or 2.\n");
						}
   			} else if (choice == 7){
   				printf("\n== Editing a task Status ==\n");
        		taskstatus(tasks);
			} else if (choice == 0) {
    		 	printf("Exiting the program.\n");
    		 	printf("Press enter to close.\n");
    		}else{
      	 		printf("Invalid choice, Please type a number from the list above.\n");
    					}
	}	while (choice != 0);
	return 0;
} 

