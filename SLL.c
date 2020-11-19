#include<stdio.h>
#include<stdlib.h>

void Insert();
int Delete();
void Display();

struct Linked_list
{
	int data;
	struct Linked_list *address;
};

struct Linked_list *head=NULL;
struct Linked_list *new_node;
struct Linked_list *previous;
struct Linked_list *temp=NULL;
struct Linked_list *del=NULL;
struct Linked_list *Search(int );


struct Linked_list *getNode()
{ 
   new_node=(struct Linked_list*)malloc(sizeof(struct Linked_list));
  if(!new_node)
  {
    return NULL;
  }
  else
   return new_node;
  }

void main()
{
	printf("\n\t\t -------Oerations on Singly Linked List----------");
	int n;
while(1)
{
printf("\n\nAvailable Operations:");
printf("\n1. Input\t\t2.Delete\t\t3.Display\t\t4.Exit");
printf("\nEnter your Choice:");
scanf("%d",&n);
switch(n)
		{
			case 1: Insert();
					break;
			case 2: Delete( );
					break;
		    case 3: Display();
					break;
			case 4: printf("successfully Exited!!!");
					exit(0);
			default: printf("Enter valid input !!\n");
		}

	
}


}


int  length=0;

void Insert()
{
	int info, position,i=0;

	
	printf("Enter the postion:");
	scanf("%d",&position);
	
	if(position>length+1)
	{
		printf("Invalid Position");
		
	}
else
{
	

printf("Enter the value to be inserted:");
	scanf("%d",&info);


 if(position==1)
{
	if(head==NULL)
{
	new_node=getNode();
	new_node->data=info;
	new_node->address=NULL;
	head=new_node;
    length++;
}

else
{
	new_node=getNode();
	new_node->data=info;
	new_node->address=head;
	head=new_node;
}
}
else
{

	new_node=getNode();
	previous=head;
     i = 1;
        while(i<=position - 2)
        {
            previous=previous->address;
            i++;
        }
        
        new_node->data=info;
        new_node->address=previous->address;
        previous->address=new_node;
        length++;
}
printf("Element inserted successfully !!!");
}
}

struct Linked_list *Search(int element)
{
	temp=head;
	while(temp!=NULL && temp->data!=element)
	{
		temp=temp->address;
	}
return temp;
}

int Delete()
{
	
	if(head==NULL)
	{
		printf("Empty Linked List");
	}
	else
	{
		int value;
		printf("\nEnter the element to be deleted:");
		scanf("%d",&value); 
  		del=Search(value);
 		if(del==NULL)
		{
			printf("The Element is not found "); 	
 		}
		else{
			if(head->data==value)
			{
				temp = head;
				head=head->address;
				free(temp);
			}
			else{
				temp=head, previous=NULL;
				while(temp->data != value && temp!=NULL)
				{
					previous=temp;
					temp = temp->address;
				}
				previous->address=temp->address;
				free(temp);
			}
		printf("Element is Deleted!!!");
		printf("\n");
		Display();
		}
	}
} 


void Display()
{

    if(head==NULL)
    {
        printf("\nEmpty Linked List");
    }
    else
    {
    	printf("The Linked List:\t");
      temp = head;
      while(temp != NULL)
      {
	 printf("%d\t",temp->data);
	 temp = temp -> address;
      }
      
   }

}
