#include <iostream>

using namespace std;

struct  node{
	int payload;
	node * next;
	node(int payload)
	{
		this->payload = payload;
	};
};

class josephus_circle{
	node* tail;
	node* eliminate_ptr;
public:
	josephus_circle();
	void add(int value);
	void eliminate(int step);
	void output();
};
josephus_circle::josephus_circle()
{
	tail = NULL;
}

void josephus_circle::add(int value)
{
	if(tail == NULL){
		tail = new node(value);
		tail->next = tail;
	}else{
		node* new_node = new node(value);
		new_node->next = tail->next;
		tail->next = new_node;
		tail = new_node;
	}
}
void josephus_circle::eliminate(int step)
{
	node* p = tail;
	while(p != NULL && p->next != p){
		for(int i=0; i<step-1;i++){
			p=p->next;
		}
		node* eliminate_node=p->next;
		p->next = p->next->next;
		if(eliminate_node == tail)
			tail = p;
		cout<<"deleting:"<<eliminate_node->payload<<endl;
		delete eliminate_node;
		output();
	}
}
void josephus_circle::output()
{
	node* iterator = tail;
	while(iterator!=NULL){
		iterator = iterator->next;
		cout<<iterator->payload<<"\t\t";
		if(iterator == tail)
			break;
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	/* code */
	josephus_circle circle;
	for(int i=0;i<8;i++){
		circle.add(i);
	}
	circle.output();
	circle.eliminate(3);

	return 0;
}

