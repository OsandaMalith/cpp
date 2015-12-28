#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * CC-BY : Osanda Malith Jayathissa (@OsandaMalith)
 * Website: http://osandamalith.wordpress.com/
 */

struct node {
	int  id;
	char name[100];
	char addr[200];
	int  age;
	char sex;
	int  nic;
	struct node *next;
};

struct node *list = NULL;
struct node *makenode(int,char *,char *,int,char,int);
int add(struct node **,int, char *,char *,int,char,int) ;
struct node* find(struct node* ,int );
struct node* display(struct node* list);
struct node* previous(struct node* , struct node*);
int removenode(struct node** , int );
void Insert();
void Search();
void Remove();

int
main () {
	int input;
	puts(
		"[~] Peoples Bank Customer Loan Service System\n"
		"[+] Coded by : Osanda Malith Jayathissa\n"
	);
	for(;;) {
	printf(
	"\n\n"
	"1. Register a Customer\n"
	"2. Search a Customer\n"
	"3. Unregister a Customer\n"
	"4. Update a Customer\n"
	"5. Display\n"
	"6. Exit\n"
	">> "
	);
	scanf("%i", &input);
	switch(input) {
		case 1:Insert();break;
		case 2:Search();break;
		case 3:Remove();break;
		case 4:update(); break;
		case 5:display(list);break;
		case 6:return 0;
		default:puts("[!] Input a valid choice");
		} 
	}
}

struct node *makenode(
	int   id,
	char *name, 
	char *addr, 
	int   age, 
	char  sex, 
	int   nic
) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	if(temp) {
		temp->id = id;
		strcpy(temp->name,name);
		strcpy(temp->addr, addr);
		temp->age = age;
		temp->sex = sex;
		temp->nic = nic;
	}
	return temp;
}

int add(
	struct node **list, 
	int   id,
	char *name, 
	char *addr, 
	int   age, 
	char  sex, 
	int   nic
) {
	struct node *temp = makenode(id,name,addr,age,sex,nic);
	if(!temp) return 0;
	temp->next = *list;
	*list = temp;
	return 1;
}

struct node* find(struct node* list,int id){
	if(!list) return 0;
	if(list->id == id) return list;
	return find(list->next, id);
}

struct node* display(struct node* list) {
	if(!list) return 0;
	printf("\n1. ID:      %i", list->id);
	printf("\n2. Name:    %s", list->name);
	printf("\n3. Address: %s", list->addr);
	printf("\n4. Age:     %i", list->age);
	printf("\n5. Sex:     %c", list->sex);
	printf("\n6. NIC:     %i", list->nic);
	puts("");
	return display(list->next);
}

struct node* previous(struct node* list, struct node* ptr) {
    if(!list) return 0;
    if(list->next == ptr) return list;
    return previous(list->next, ptr);
}

int removenode(struct node** list, int id) {
	struct node *temp = find(*list, id);
	if(!temp) return 0;
	struct node *ptr = previous(*list, id);
	ptr ? ptr->next=(temp->next) : (*list=temp->next);
	free(temp);
	return 1;
}

void Insert() {
	int i, n, id;
	char name[100];
	char addr[200];
	int  age;
	char sex;
	int  nic;

	fflush(stdin);
	printf("\nEnter ID: "); 
	scanf("%i",&id);
	fflush(stdin);
	printf("\nEnter your Name: "); 
	scanf("%[^\n]",&name);
	fflush(stdin);
	printf("\nEnter your Adress: "); 
	scanf("%[^\n]",&addr);
	fflush(stdin);
	printf("\nEnter your age: "); 
	scanf("%i",&age);
	fflush(stdin);
	printf("\nChoose your sex: 1.Male\n\t\t 2.Female: "); 
	scanf("%c",&sex);
	sex = (sex == '1') ? 'M' : 'F';
	fflush(stdin);
	printf("\nEnter your nic: "); 
	scanf("%i",&nic);
	fflush(stdin);
	
	add(&list, id,name,addr,age,sex,nic); 
	display(list); 
}

void Search() {
	int n;
	struct node *p;
	printf("Enter ID: "); 
	scanf("%i", &n);
    (p = find(list, n)) ? display(p) : puts("\n[!] Value not Found");
}

void Remove() {
	int n; 
	printf("Enter ID: "); 
	scanf("%i", &n);
	printf(removenode(&list, n) ? "\n[+] Entry Cleared\n" : "\n[-] Entry not found\n");
	display(list);
}

void update() {
	int n, in, id;
	char name[100];
	char addr[200];
	int  age;
	char sex;
	int  nic;
	struct node *p;
	
	printf("Enter ID: "); 
	scanf("%i", &n);
    if(p = find(list, n)) display(p); 
	else {
		puts("\n[!] Value not Found");
		return;
	} 
    fflush(stdin);
    for(;;) {
    printf("[?] What do you want to update?\n[*] 0 - Exit\n>> ");
    scanf("%i", &in);
    if(!in) break;
	fflush(stdin);
    
    switch(in) {
    	case 1:
    		fflush(stdin);
			printf("\nEnter ID: "); 
			scanf("%i",&id);
			p->id = id;
			break;
		
		case 2:
			fflush(stdin);
			printf("\nEnter your Name: "); 
			scanf("%[^\n]",&name);
			strcpy(p->name, name);
			break;
			
		case 3:
			fflush(stdin);
			printf("\nEnter your Adress: "); 
			scanf("%[^\n]",&addr);
			strcpy(p->addr, addr);
			break;	
				
		case 4:
			fflush(stdin);
			printf("\nEnter your age: "); 
			scanf("%i",&age);
			p->age = age;
			break;	
					
		case 5:
			fflush(stdin);
			printf("\nChoose your sex: 1.Male\n\t\t 2.Female: "); 
			scanf("%c",&sex);
			sex = (sex == '1') ? 'M' : 'F';
			p->sex = sex;
			break;
						
		case 6:
			fflush(stdin);
			printf("\nEnter your nic: "); 
			scanf("%i",&nic);
			fflush(stdin);
			p->nic = nic;
			break;
		
		default:
			puts("[!] Enter a valid Number");
    }
	puts("[+] Entry Updated Successfully\n");
	display(p);
	}
}
