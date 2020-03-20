#include <iostream>
template <class Data>
class List {
	private:
		struct _list {
			Data value;
			struct _list *next;
			struct _list *prev;
		};
		typedef struct _list Dlist;
		size_t _size;
		Dlist *_front;
		Dlist *_back;

		void reccopy(const Dlist *ptr) {
			if(ptr) { // if(ptr != nullptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
			}
		}
	public:
		List() {
			_size = 0;
			_front = nullptr;
			_back = nullptr;
		}

		List(const List &list) {
			_front=nullptr;
			_back=nullptr;
			_size=0;
			reccopy(list._front);
		}

		~List() {
			while(!empty()) {
				pop_front();
			}
		
		}

		List &operator=(const List &x){
			size = x.size;
			Dlist *temp;
			front = temp;
			for(temp=x.front; temp!=nullptr; temp=temp->next) {
				push_back(temp->value);
			}
			back = temp;
			return *this;
		}
		
		/*
		bool List::operator==(const List &x)
		{
			if(x.size == size && front == x.front && back == x.back)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		*/

		Data &front() const {
			return _front->value;
		}

		Data &back() const {
			return _back->value;
		}

		size_t size() const {
			return _size;
		}

		size_t length() const {
			return _size;
		}

		void push_front(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->prev = nullptr;

			if(_front==nullptr) {
				newNode->next=nullptr;
				_back=newNode;
			}
			else {
				newNode->next=_front;
				_front->prev = newNode;
			}

			_front=newNode;
			_size++;
		}

		void push_back(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->next=nullptr;

			if(_back!=nullptr) {
				_back->next=newNode;
				newNode->prev = _back;
			}

			if(_front==nullptr) {
				_front=newNode;
				newNode->prev = nullptr;
			}

			_back=newNode;
			_size+=1;
		}

		void pop_front() {
			Dlist *front_to_delete = _front;
			_front = _front->next;
			if(_front==nullptr) {
				_back = nullptr;
			}
			else {
				_front->prev = nullptr;
			}
			delete front_to_delete;
			_size -= 1;
		}
		//CONVERT THIS FUNCTION
		void pop_back() {
			Dlist *back_to_remove = _back;
			_back = _back->prev;
			if(_back==nullptr) {
				_front = nullptr;
			}
			else {
				_back->next = nullptr;
			}
			delete back_to_remove;
			_size-=1;
		}

		// leave this alone
		bool empty() const {
			return ((_front==nullptr) && (_back==nullptr));
		}

		//Modify this
		void print() {
			Dlist *temp;
			for(temp=_front; temp!=nullptr; temp=temp->next) {
				std::cout << temp->value << " ";
			}
			std::cout << std::endl;
		}
		void print_back() {
			Dlist *temp;
			for(temp=_back; temp!=nullptr; temp=temp->prev) {
				std::cout << temp->value << " ";
			}
			std::cout << std::endl;
		}
		template<typename V> friend bool operator==(const List<V> &a, const List<V> &b);
		template<typename V> friend bool operator!=(const List<V> &a, const List<V> &b);
};


template<typename V>
bool operator==(const List<V> &a, const List<V> &b){
			//TODO: why don't you try the auto keyword?
			for(auto tempa=a._front, tempb=b._front; 
					(tempa!=nullptr) || (tempb != nullptr); 
					tempa=tempa->next, tempb = tempb->next) {

				if(tempa->value != tempb->value){
					return false;
				}	
			}
			if(a.size() != b.size()){
				return false;
			}
			else{
				return true;
			}
		}
		template<typename V> bool operator!=(const List<V> &a, const List<V> &b){
			//TODO: why don't you try the auto keyword?
			for(auto tempa=a._front, tempb=b._front; tempa!=nullptr || tempb != nullptr; tempa=tempa->next, tempb = tempb->next) {
				if(tempa->value != tempb->value){
				return true;
				}	
			}
			if(a.size() != b.size()){
				return true;
			}
			else{
				return false;
			}
		}
