#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING 1
#define NUMBERS 0

typedef struct Worker 
{
	unsigned int id;
	char* name;
	double sal;
	union WorkeDate
	{
		char Ldate[6];
		unsigned int Ndate;
	}WorkeDate;
}worker;

typedef struct WorkerList
{
	worker* data;
	struct WorkerList* next;
} WorkerList;

void printList(WorkerList* head);//print all woorkers

worker* CreateWorker();// create new worker

void printWorker(worker* head, int typeD);//print specific worker

WorkerList* addWorker(WorkerList* head, worker* w);// add new worker to the list 

int index(WorkerList* head, long unsigned id)// find the place the worker in th list

WorkerList* deleteWorstWorker(WorkerList* head);// delte all workers

void update_worker(WorkerList* head, float percent);// Raised in salary

WorkerList* reverse(WorkerList* head);// change the list the worst worker is the head

void freeWorkers(WorkerList* head);// free the memory 

void main() {
	worker* printW;
	int id = 0;
	worker* ptr;
	float perecent = 0;
	WorkerList* head = NULL;

	int checkTheNum = -1;

	while (checkTheNum != 0) {

		printf("press 1 to creat new worker: \n");

		/*printf("press 2 to add worker to the list: \n");*/

		printf("press 3 to delete the last worker: \n");

		printf("press 4 to update the salary of all the workers: \n");

		printf("press 5 to revers the list\n");

		printf("press 6 to delet all the list \n");

		printf("press 7 to print the emploo: \n");

		printf("press 8 to print the emploo place in the salary table: \n");

		printf("press 0 to return to the main: \n");

		printf("\nyou chosen num is: ");
		scanf("%d", &checkTheNum);

		switch (checkTheNum)
		{
		case(1):
			ptr = CreateWorker();
			head = addWorker(head, ptr);
			break;
		case(3):
			head = deleteWorstWorker(head);
			break;
		case(4):
			printf("enter perecent: ");
			scanf("%f", &perecent);
			update_worker(head, perecent);
			printf("you update the emlpp salary!");
			break;
		case(5):
			head = reverse(head);
			break;
		case(6):
			head = deleteWorstWorker(head);
			break;
		case(7):

			printW = head->data;
			printWorker(printW, 0);
			break;
		case(8):
			printf("enter emploo id: \n");
			scanf("%d", &id);
			int retPlace = index(head, id);
			printf("the place is: %d\n", retPlace);
			break;
		}
	}


}



worker* CreateWorker() {
	worker* ptr = (worker*)calloc(5, sizeof(worker));
	int dataType = 0;
	char tepname[100];
	if (!ptr) {
		printf("allocation faild");
		exit(-1);
	}

	printf("enter emploo id: ");
	scanf("%d", &ptr->id);

	printf("\nenter emploo name: ");
	scanf("%s", &tepname);

	int len = strlen(tepname);
	ptr->name = (char*)malloc(len * sizeof(char*));
	strcpy(ptr->name, tepname);

	printf("\nenter salary: ");
	scanf("%lf", &ptr->sal);

	printf("\nchose type of data to enter: 1 -string ,0-number: ");
	scanf("%d", &dataType);

	switch (dataType) {
	case(STRING): {
		printf("\nenter string data: ");
		scanf("%s", &ptr->WorkeDate.Ldate);
		break;
	}
	case(NUMBERS): {
		printf("\n enter data num: ");
		scanf("%d", &ptr->WorkeDate.Ndate);
		break;
	}
	default:
		printf("illegel choise");
		break;
	}
	return ptr;
}

void printWorker(worker* head, int typeD) {

	printf("emplo id is:%d\n", head->id);

	printf("emplo name is: %s\n", head->name);

	printf("emplo salary is: %g\n", head->sal);

	switch (typeD) {
	case(STRING):
		printf("emplo work date is: %s\n", head->WorkeDate.Ldate);
		break;

	case(NUMBERS):
		printf("emplo work data is: %d\n", head->WorkeDate.Ndate);
		break;
	}

}

WorkerList* addWorker(WorkerList* head, worker* w) {

	WorkerList* newworker = (WorkerList*)calloc(1, sizeof(WorkerList));
	if (newworker==NULL)
	{
		printf("alocation is faild");
		return NULL;
	}
	newworker->data = w;
	if (head == NULL) {
		head=newworker;
		return head;
	}
	if (head->data->sal<newworker->data->sal)
	{
		newworker->next = head;
		return newworker;
	}
	WorkerList* ptr = head->next;
	WorkerList* prev = head;
		while ((ptr && ptr->data->sal > newworker->data->sal))
	{
		
			ptr = ptr->next;
			prev = prev->next;
			
	}
		prev->next = newworker;
		newworker->next = ptr;
		return head;
	

}

int index(WorkerList* head, long unsigned id) {
	int counter = 1;
	WorkerList* temp = head;
	while (temp != NULL) {
		if (temp->data->id == id) {
			return counter;
		}
		counter++;
		temp = temp->next;
	}
	return -1;
}

WorkerList* deleteWorstWorker(WorkerList* head) {
	WorkerList* ptr = head;

	if (head->next == NULL) 
	{
		free(head);
		head = NULL;
		return head;
	}
	else
		if (head == NULL) 
		{
			return head;
		}
		else
		{
			while (ptr != NULL)
			{
				if (ptr->next->next == NULL)
				{
					free(ptr->next->next);
					ptr->next = NULL;
				}
			}
		} 
	return head;
}

void update_worker(WorkerList* head, float percent) 
{
	WorkerList* temp = (WorkerList*)malloc(sizeof(WorkerList));
	temp->data = head->data;
	if (temp == NULL) 
	{
		printf("you dont have any emplo");
		return temp;
	}
	while (temp != NULL) 
	{
		temp->data->sal += (temp->data->sal) * (percent / 100);
		if (head->next == NULL) 
		{
			break;
		}
		else
		{
			temp = temp->next;
		}

	}

}

WorkerList* reverse(WorkerList* head) {
	WorkerList* temp = head;
	WorkerList* prev = NULL;
	WorkerList* next = NULL;

	while (temp != NULL) 
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}

	return prev;

}

void freeWorkers(WorkerList* head) 
{
	WorkerList* temp = head;
	while (temp != NULL) 
	{
		free(temp->data);
		temp = temp->next;
	}
}

void printList(WorkerList* head) 
{
	WorkerList* temp = head;

	while (temp)
	{
		printWorker(temp->data, 0);
		temp = temp->next;
	}
}



