#include<iostream>
using namespace std;

class node
{

int data;
node  *next;
node *h1=NULL,*h2=NULL;
public:

void insert(int n1,int n2)
{
   for(int i=1;i<=50;i++)	
   {
   	node *curr=new node();
   	curr->data=i*n1;
   	curr->next=NULL;
   	if(h1==NULL)
   	  h1=curr;
   	else
   	{
   		node *t1=h1;
   		while(t1->next!=NULL)
   		  t1=t1->next;
   		t1->next=curr;
	   }
   }
   for(int i=1;i<=50;i++)	
   {
   	node *curr=new node();
   	curr->data=i*n2;
   	curr->next=NULL;
   	if(h2==NULL)
   	  h2=curr;
   	else
   	{
   		node *t2=h2;
   		while(t2->next!=NULL)
   		  t2=t2->next;
   		t2->next=curr;
	   }
   }
}
void display()
{
	node *t1=h1;
   	while(t1->next!=NULL)
   	{
   		cout<<t1->data<<"->";
	    t1=t1->next;
    }
    cout<<"\n";
    node *t2=h2;
    while(t2->next!=NULL)
   	{
   		cout<<t2->data<<"->";
	    t2=t2->next;
    }
}
void findLCM()
{
	node *t1=h1;
	while(t1->next!=NULL)
	{
	   node *t2=h2;
	   while (t2->next!=NULL)	
	   {
	   	  if(t1->data==t2->data)
	   	  {
	   	  	cout<<"\n LCM is"<<t1->data;
	   	  	return;
		  }
		  else
		    t2=t2->next;
		    
	  }
	  t1=t1->next;
	}
	
}
};
int main()
{
	node obj;
	int n1,n2;
	cin>>n1>>n2;
	obj.insert(n1,n2);
	obj.display();
	obj.findLCM();
	
}