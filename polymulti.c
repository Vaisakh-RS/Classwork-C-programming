#include<stdio.h>
#include<stdlib.h>

void Insert();
void Display();
void Mulitplication();


struct Poly
{
    int coeff;
    int exp;
    struct Poly *next;
};


struct Poly *temp=NULL;
struct Poly *Previous=NULL;
struct Poly *new_node;

struct Poly *P_Header=NULL;
struct Poly *P_Ptr=NULL;

struct Poly *Q_Header=NULL;
struct Poly *Q_Ptr=NULL;

struct Poly *R_Header=NULL;
struct Poly *R_Ptr=NULL;
struct Poly *R_Ptr1=NULL;



struct Poly *getNode()
{ 
	new_node=(struct Poly*)malloc(sizeof(struct Poly));
  	new_node->next = NULL;
    return new_node;
}


void Insert(struct Poly *Ptr, struct Poly *Header )
{
   int value,degree,op;
   do{
       struct Poly* new_node=getNode();
       printf("\nEnter The Coefficent: ");
       scanf("%d",&value);
       new_node->coeff=value;
       
       printf("Enter The Degree: ");
       scanf("%d",&degree);
       new_node->exp=degree; 
       
       if (Header->next == NULL) 
	   {
         Header->next = new_node;
       }

       else 
	   {
          Ptr = Header->next;
          Previous = Header;

          while (Ptr != NULL && Ptr->exp > new_node->exp)
		   {
              Previous = Ptr;
              Ptr = Ptr->next;
           }

          if (Ptr != NULL && Ptr->exp == new_node->exp) 
              Ptr->coeff += new_node->coeff;

         //else
		   {
            new_node->next = Previous->next;
            Previous->next = new_node;
           }
       }
    
       printf("Do you want to continue?(1/2)");
       scanf("%d",&op);

   }
   while(op==1);
}
   
 
   
void Multiplication()
{
	int coef, expo;
	R_Header = getNode();
	R_Header->next=NULL;
	R_Ptr=R_Header->next;
	if(P_Header->next==NULL || Q_Header==NULL)  //1
	{
	  printf("Multiplication is not Possible");	
	  return;
	}  
	P_Ptr=P_Header->next;
	while(P_Ptr!=NULL)
	{
		Q_Ptr=Q_Header;
		while(Q_Ptr!=NULL)
		{
			coef=P_Ptr->coeff * Q_Ptr->coeff;
			expo= P_Ptr->exp + Q_Ptr->exp; 
			R_Ptr=R_Header->next;
			R_Ptr1=R_Header;
			while(R_Ptr!=NULL && R_Ptr->exp>expo)  //
			{
				R_Ptr1=R_Ptr;
				R_Ptr=R_Ptr->next;
			}
			if(R_Ptr!=NULL && R_Ptr->exp==expo)
			{
				R_Ptr->coeff = R_Ptr->coeff+coef;
			}
		    else
		    {
		    	new_node=getNode();
		    	new_node->exp=expo;
		    	new_node->coeff=coef;
		    	R_Ptr1->next=new_node;
		    	new_node->next=R_Ptr;
			}
			Q_Ptr=Q_Ptr->next;
		}
		P_Ptr=P_Ptr->next;	
	}
}

void Display(struct Poly *Head)
{
    if(Head == NULL)
    {
        printf("No Polynomial found");
    }
    else
    {
        struct Poly *temp = Head;
        while(temp!=NULL)
        {
            printf("%d",temp->coeff);
            if(temp->exp!=0)
            {
                printf("x^");
                printf("%d",temp->exp);
            }
            if(temp->next!=NULL)
            {
                printf(" + ");
            }
             temp=temp->next; 
            
        }
            printf("\n\n");
        
    }
}
  
  
int main()
{
    P_Header = getNode();
	Q_Header = getNode();
	
    printf("Enter the 1st polynomial:\n");
    Insert(P_Ptr,P_Header);
    
    printf("\nThe first polynomial you entered is:");
    Display(P_Header->next);
	
	printf("\nEnter the 2nd polynomial\n");
    Insert(Q_Ptr,Q_Header);
    
    printf("\nThe second polynomial you entered is");
    Display(Q_Header->next);
    
    Multiplication();
    printf("The Product of the 2 Ploynomials:\t");
    Display(R_Header->next);
    
   
}
