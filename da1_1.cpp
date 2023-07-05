// Consider a singly linked list with 13 nodes. All the nodes store the value ‘0’ initially. In the first 
// iteration, all the nodes which are multiples of one, are incremented by one. In the second iteration, those 
// nodes which are multiples of two, are incremented by one. Likewise, in the third iteration, those nodes which 
// are multiples of three, are incremented by one. Write a program to print the list elements after performing 
// ‘n’  such iterations.

#include<iostream>
using namespace std;

class node
{
	int data;
	node *next;

	public:
	
    	node *start=NULL;

		void createlist()
		{
			int n=13;
			for(int i=0;i<n;i++)
			{	
				node *curr= new node();
				curr->data=0;
				curr->next=NULL;

				if(start==NULL)
				    start=curr;
				else
				{
					node *temp=start;
					while (temp->next!=NULL)
					    temp=temp->next;
					temp->next=curr;
			    }
			    
		    }
		}

		void update(int n)
		{
			for(int i=1;i<=n;i++)
			{
				node *temp=start;
				int count=1;
			
				while(temp!=NULL)
				{
					if(count%i==0)
					  temp->data=temp->data+1;
					temp=temp->next;
					count++;
					
				}
			}
			
		}

		void display()
		{
		 node *temp=start;   
		 while(temp!=NULL)
		 {
		   cout<<temp->data<<" -> ";
		   temp=temp->next;
        }
        }
		
	};

	int main()
	{
		node obj;
		int n;
		obj.createlist();
	    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
		cout<<"Enter the number of iterations to be performed : ";
		cin>>n;
		obj.update(n);
	    for(int i=1; i<14; i++)
		{
		   cout<<i<<" -> ";
        }
        cout<<endl;
        cout<<"Updated linked list : "<<endl;
        obj.display();
	}
