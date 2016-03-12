#include<iostream>
using namespace std;

template <typename T>
class node {
					public:
						node<T> *next;
						T data;
						node( T d, node <T> *n)
						{next=n;
						data=d;}
			};

template <typename T>
class Queue {
public:
	node<T> *front; 
	node<T> *back;
	Queue()
	{front=nullptr;
	back=nullptr;} //constructor
	Queue(const Queue<T> & orignal) // copy constructor  
	{
		front= nullptr;
		back=nullptr;
		// node<T> new node<T> newCopy; BIG MISTAKE
		//Remember you need to point to the front of the Queue so you can copy each node one by one

		Node<T> *ptr = orignal.front;


		while(ptr!=nullptr)
		{
			addToBack(data->next); // BIG MISTAKE! how do you enter the addtoback fun without going the enqueue!!!
			enqueue(ptr->data);
			ptr=ptr->next; // to run one all the queue
		}

	};
	~Queue() //destructor
	{
	 while (front!=nullptr)
		 dequeue();
	 
	}

	Queue<T>& operator=(const Queue<T> &rhs) // assignment operator DO NOT FORGET the const HERE!!!

	{
	
		node<T> *ptr = rhs.front;


		while(ptr!=nullptr)
		{
			enqueue(ptr->data);
			ptr=ptr->next; // to run one all the queue
		}

		return *this;
	}
	/*
	Queue& operator=(Queue<T> &obj) // assignment operator 
	{	swap(obj);
		return *this;
	}   
	void swap(Queue<T> rhs) //See here the value is a copy of the prev assignment operator function
	{ node<T> *tmpF=front->next.rhs;
				front->next.rhs=front;
				front=tmpF;

	node<T> *tmpB=back->next.rhs;
			back->next.rhs=back;
			back=tmpB;
	
	}
	*/
	void enqueue(T item) //???
	{ if(front==nullptr)
	{
	//Node<T> *n = new Node<T>(item); // Do not forget the astrisk
	//front=n;
	//back=n;
	}
	  else 
		addToBack(item);
	}
	Queue<T> dequeue()
	{ 
		if (front=nullptr)
			cout<<"nothing to remove!"<<endl;
		else
		removeFromFront();
	}
	T addToBack(T item)
	{
	node<T> *n = new node<T>(item);
		back->next=n;
		back=n;
	}
	T removeFromFront()
	{
	node<T>  *tmp=front;
	front = front->next;
	T val = tmp->data;
	delete tmp;
	return val;

	}



};

int main() {

	Queue<int> ReemQueue;

	ReemQueue.enqueue(1);
	ReemQueue.enqueue(2);
	ReemQueue.enqueue(3);


	ReemQueue.dequeue();
	ReemQueue.dequeue();



}
