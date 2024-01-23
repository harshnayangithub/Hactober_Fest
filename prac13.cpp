/*
deques are frequently used in computer programming, and a typical example is the creation of a job deque by an operating system. 
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job deque. Write functions to add job and delete job from deque.
*/

#include <iostream>
#define MAX 10
using namespace std;
struct deque
{       int data[MAX];
	int front,rear;
};
class deque
{    struct deque q;
   public:
      deque(){q.front=q.rear=-1;}
      int isempty();
      int isfull();
      void endeque(int);
      int deldeque();
      void display();
};
int deque::isempty()
{
	return(q.front==q.rear)?1:0;
}
int deque::isfull()
{    return(q.rear==MAX-1)?1:0;}
void deque::endeque(int x)
{q.data[++q.rear]=x;}
int deque::deldeque()
{return q.data[++q.front];}
void deque::display()
{   int i;
    cout<<"\n";
    for(i=q.front+1;i<=q.rear;i++)
	     cout<<q.data[i]<<" ";
}
int main()
{      deque obj;
	int ch,x;
	do{    cout<<"\n 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
	       cin>>ch;
	switch(ch)
	{  case 1: if (!obj.isfull())
		   {   cout<<"\n Enter data : \n";
			cin>>x;
			obj.endeque(x);
			cout<<endl;
		   }
	          else
		      cout<< "deque is overflow!!!\n\n";
	           break;
	   case 2: if(!obj.isempty())
			    cout<<"\n Deleted Element = "<<obj.deldeque()<<endl;
		    else
			{   cout<<"\n deque is underflow!!!\n\n";  }
		    cout<<"\nRemaining Jobs : \n";
		    obj.display();
	           break;
	  case 3: if (!obj.isempty())
	        {  cout<<"\n deque contains : \n";
		       obj.display();
	        }
	        else
		         cout<<"\n deque is empty!!!\n\n";
	       break;
	  case 4: cout<<"\n Exiting Program.....";
        }
      }while(ch!=4);
return 0;
}

