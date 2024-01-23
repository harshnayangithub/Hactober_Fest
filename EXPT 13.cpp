#include<iostream>
#include<stdlib.h>
#define size 5
using namespace std;
class Ddeque {
    private:
    int que[size] ;
    public:
    int front,rear;
    Ddeque();
    int Qfull();
    int Qempty();
    int insert_rear(int item);
    int delete_front();
    int insert_front(int item);
    int delete_rear();
    void display();
};
Ddeque::Ddeque() {
    front=-1;
    rear= -1;
    for(int i=0;i <size;i++) {
        que[i]=-1;
    }
}
int Ddeque::Qfull() {
    if(rear==size-1)
        return 1;
    return 0;
}
int Ddeque::Qempty()
{
    if((front>rear) || (front==-1&&rear==-1))
        return 1;
    return 0;
}
int Ddeque::insert_rear(int item)
{
    if(front == -1 && rear==-1)
        front++;
    que[++rear] = item;
    return rear;
}
int Ddeque::delete_front()
{
    int item;
    if(front== -1)
        front++ ;
    item=que[front];
    que[front]= -1;
    front++ ;
    return item;
}
int Ddeque::insert_front(int item)
{
    int i,j;
    if(front==-1)
        front++;
    i=front-1;
    while(i >= 0) {
        que[i+1] =que[i];
        i--;
    }
    j=rear;
    while(j >= front) {
        que[j+1]=que[j];
        j--;
    }
    rear++ ;
    que[front] =item;
    return front;
}
int Ddeque::delete_rear()
{
    int item;
    item=que[rear];
    que [rear] = -1 ;/*logical deletion*/
    rear--;
    return item;
}
void Ddeque::display()
{
    int i;
    cout<<"\nStraight deque is:";
    for(i=front;i <= rear; i ++) {
        cout<<" "<<que[i];
    }
}
int main() {
    int choice,item;
    char ans;
    ans='y';
    Ddeque obj;
    cout<<"\n\t\t Program For doubly ended deque using arrays";
    do
    {
        cout<<"\n1.insert by rear\n2.delete by front\n3.insert by front\n4.delete by rear";
        cout<<"\n5.display\n6.exit";
        cout<<"\n Enter Your choice ";
        cin>>choice;
        switch(choice) {
            case 1:
                if(obj.Qfull())
                    cout<<"\n Doubly ended deque is full";
                else
                {
                    cout<<"\n Enter The item to be inserted: ";
                    cin>>item;
                    obj.rear=obj.insert_rear(item);
                }
                break;
            case 2:
                if(obj.Qempty())
                    cout<<"\n Doubly ended deque is Empty";
                else
                {
                    item= obj.delete_front();
                    cout<<"\n The item deleted from deque is "<<item;
                }
                break;
            case 3:
                if(obj.Qfull())
                    cout<<"\n Doubly ended deque is full";
                else
                {
                    cout<<"\n Enter The item to be inserted: ";
                    cin>>item;
                    obj.front= obj.insert_front(item);
                }
                break;
            case 4:
                if(obj.Qempty())
                    cout<<"\n Doubly ended deque is Empty";
                else {
                    item= obj.delete_rear();
                    cout<<"\n The item deleted from deque is "<< item;
                }
                break;
            case 5:
                obj.display();
                break;
            case 6:
                exit(0);
        }
    }  
    while(true);
    return 0;
}