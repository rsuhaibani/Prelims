#include<iostream>
using namespace std;

template <typename T>
class node {
					public:
						node<T> *next;
						T data;
						node() 
						{next=nullptr;}
						node( T d, node<T> *n)
						{next=nullptr;
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
		front=nullptr;
		back=nullptr;
		//Remember you need to point to the front of the Queue so you can copy each node one by one

		node<T> *ptr = orignal.front;


		while(ptr!=nullptr)
		{
			enqueue(ptr->data);
			ptr=ptr->next; // to run one all the queue
		}

	};
	~Queue() //destructor
	{
	 while (front!=nullptr)
		 dequeue();
	 
	}

	Queue & operator=(const Queue &rhs) // assignment operator DO NOT FORGET the const HERE!!!

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
	node<T> *n = new node<T>(item,nullptr); // Do not forget the astrisk
	front=n;
	back=n;
	}
	  else 
		addToBack(item);
	}
	T dequeue()
	{ 	node<T>  *temp = front->next;
		T val = front->data;

		if (front==nullptr)
			cout<<"nothing to remove!"<<endl;
		else				
		delete front;
		front=temp;
		return val;

	

	}
	void addToBack(T item)
	{
	node<T> *n = new node<T>(item,nullptr);
		back->next=n;
		back=n;
		
	}

	



};

int main() {

	Queue<int> ReemQueue;

	for(int i=0;i<=3;i++)
		{ReemQueue.enqueue(i);}


	std::cerr << "ReemQueue: ";
	node<int> *tmp = ReemQueue.front;
	while (tmp !=  nullptr) {
		std::cerr << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cerr << std::endl;



}
