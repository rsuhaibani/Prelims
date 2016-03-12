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

	Queue<T> & operator=(const Queue<T> srhs) // assignment operator DO NOT FORGET the const HERE!!!

	{
		//works fine
		node<T> *ptr = rhs.front;


		while(ptr!=nullptr)
		{
			enqueue(ptr->data);
			ptr=ptr->next; // to run one all the queue
		}

		return *this;

		//Works fine
		/*node<T> * tmp = rhs.front;
		rhs.front = front;
		front = tmp;

		return *this;*/
	}

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
		{ReemQueue.enqueue(i);} // working

	ReemQueue.dequeue();		// working



	std::cerr << "ReemQueue: ";
	node<int> *tmp = ReemQueue.front;
	while (tmp !=  nullptr) {
		std::cerr << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cerr << std::endl;


	Queue<int> ReemQueue2=ReemQueue;


	std::cerr << "ReemQueue2: ";
	node<int> *tmp2 = ReemQueue2.front;
	while (tmp2 !=  nullptr) {
		std::cerr << tmp2->data << " ";
		tmp2 = tmp2->next;
	}
	std::cerr << std::endl;



}
