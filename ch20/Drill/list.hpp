#include "list.h" 

template<typename T,typename A> list<T,A>::list(): size(0),alloc(NodeAllocator()){
  Node* newNode = createNode(T{});
  tail = head = newNode; 
}
template<typename T,typename A> list<T,A>::list(int num,T value):size(0),alloc(NodeAllocator()){
  Node* newNode = createNode(value);
  tail = head = newNode;
  for(int i=1;i<num;++i){
    push_back(value);
  }
}
template<typename T,typename A> list<T,A>::list(std::initializer_list<T> lst): size(0),alloc(NodeAllocator()){
  Node* newNode = createNode(T{});
  tail = head = newNode;
  for(auto p =lst.begin();p!=lst.end();++p){
    push_back(*p);
  }
}
template<typename T,typename A> list<T,A>::list(const list& src):size(0),alloc(NodeAllocator()){
  Node* newNode = createNode(T{});
  tail = head = newNode;
  /*We need to define const_iterator in order get an iterator to a const list*/
  for(auto p =src.begin();p!=src.end();++p){
    push_back(*p);
  }
}
template<typename T,typename A> list<T,A>& list<T,A>::operator =(const list& src){
  if(&src==this)
    return *this;
  Node* newNode = createNode(T{});
  tail = head = newNode;
  for(auto p =src.begin();p!=src.end();++p){
    push_back(*p);
  }
}
/*The increment and dicrement of the iterator 
  is implemented in the cyclic form */
template<typename T,typename A> class list<T,A>::iterator{
private:
  Node* nodePtr;
   /*By adding a member list* to the class iterator 
     we allow it to have access to the private member of the list class*/
  const list* listPtr;
  friend class list;
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T*;
  using reference = T&;
  iterator(Node* newNodePtr = nullptr,const list* parent = nullptr) : nodePtr(newNodePtr),listPtr(parent) {}
  T& operator*() const { return nodePtr->val; }
  T& operator*() { return nodePtr->val; }
  iterator& operator++() {
    if(nodePtr->next==nullptr)
      nodePtr = listPtr->head;
    else
      nodePtr = nodePtr->next;
    return *this;
  }
  iterator& operator+(int step) {
    for(int i=0;i<step;++i){
      if(nodePtr->next==nullptr){
	nodePtr = listPtr->head;	
      }else
	nodePtr = nodePtr->next;
    }
    return *this;
  }
  iterator operator++(int) {
    iterator temp = *this;
    if(nodePtr->next==nullptr)
      nodePtr = listPtr->head;
    else
      nodePtr = nodePtr->next;
    return temp;
  }
  iterator& operator--() {
    if(nodePtr->prev==nullptr)
      nodePtr = listPtr->tail;
    else
      nodePtr = nodePtr->prev;
    return *this;
  }
  iterator& operator-(int step) {
    for(int i=0;i<step;++i)
      if(nodePtr->prev==nullptr)
	nodePtr = listPtr->tail;
      else
	nodePtr = nodePtr->prev;
    return *this;
  }
  iterator operator--(int) {
    iterator temp = *this;
    if(nodePtr->prev==nullptr)
      nodePtr = listPtr->tail;
    else
      nodePtr = nodePtr->prev;
    return temp;
  }
  bool operator==(const iterator& other) const { return nodePtr == other.nodePtr; }
  bool operator!=(const iterator& other) const { return nodePtr != other.nodePtr; }
};
/*The const_iterator is needed to implement the copy constructor with const qulifier*/
template<typename T,typename A> class list<T,A>::const_iterator{
private:
  const Node* nodePtr;
   /*By adding a member list* to the class iterator 
     we allow it to have access to the private member of the list class*/
  const list* listPtr;
  friend class list;
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using const_pointer = T*;
  using const_reference = T&;
  const_iterator(const Node* newNodePtr = nullptr,const list* parent = nullptr) : nodePtr(newNodePtr),listPtr(parent) {}
  const T& operator*() const { return nodePtr->val; }
  const_iterator& operator++() {
    if(nodePtr->next==nullptr)
      nodePtr = listPtr->head;
    else
      nodePtr = nodePtr->next;
    return *this;
  }
  const_iterator& operator+(int step) {
    for(int i=0;i<step;++i){
      if(nodePtr->next==nullptr){
	nodePtr = listPtr->head;	
      }else
	nodePtr = nodePtr->next;
    }
    return *this;
  }
  const_iterator operator++(int) {
    const_iterator temp = *this;
    if(nodePtr->next==nullptr)
      nodePtr = listPtr->head;
    else
      nodePtr = nodePtr->next;
    return temp;
  }
  const_iterator& operator--() {
    if(nodePtr->prev==nullptr)
      nodePtr = listPtr->tail;
    else
      nodePtr = nodePtr->prev;
    return *this;
  }
  const_iterator& operator-(int step) {
    for(int i=0;i<step;++i)
      if(nodePtr->prev==nullptr)
	nodePtr = listPtr->tail;
      else
	nodePtr = nodePtr->prev;
    return *this;
  }
  const_iterator operator--(int) {
    const_iterator temp = *this;
    if(nodePtr->prev==nullptr)
      nodePtr = listPtr->tail;
    else
      nodePtr = nodePtr->prev;
    return temp;
  }
  bool operator==(const const_iterator& other) const { return nodePtr == other.nodePtr; }
  bool operator!=(const const_iterator& other) const { return nodePtr != other.nodePtr; }
};
/*Insert v after p*/
template<typename T,typename A> typename list<T,A>::iterator list<T,A>::insert(iterator p,const T& value){
  bool flag{false};
  for(iterator iter = this->begin();iter!=this->end(),flag==false;++iter){
    if(p==iter){
      Node* newNode = createNode(value);
      if (head==tail){
	head = newNode;
	head->next = tail;
	tail->prev = head;
      }else {
	newNode->prev = p.nodePtr;
	newNode->next = p.nodePtr->next;
	p.nodePtr->next->prev = newNode;
	p.nodePtr->next = newNode; 
      }
      flag=true;
    }
  }
  ++size;
  return (p+1);
}
template<typename T,typename A> typename list<T,A>::iterator list<T,A>::erase(iterator p){
  if(head!=tail && p!=nullptr){
    bool flag{false};
    size_t count{0};
    for(iterator iter = this->begin();iter!=this->end(),flag==false;++iter){
      if(p==iter){
	p.nodePtr->prev->next = p.nodePtr->next;
	p.nodePtr->next->prev = p.nodePtr->prev;
	flag=true;
      }
      ++count;
    }
    destroyNode(p.nodePtr);
    return (this->begin()+count-1);
  }
  return p;
}
/*Add a new node at the end of the list */                                                                             
template<typename T,typename A> void list<T,A>::push_back(const T& value) {
  Node* newNode = createNode(value);
  if (head==tail){
    head = newNode;
    head->next = tail;
    tail->prev = head;
  }else {
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    newNode->next = tail;
    tail->prev = newNode;
  }
  ++size;
}
/*Add a new node at the beginning of the list*/
template<typename T,typename A> void list<T,A>::push_front(const T& value) {
  Node* newNode = createNode(value);
  if (head==tail) {
    head = newNode;
    head->next = tail;
    tail->prev = head;
  } else {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
  }
  ++size;
}
template<typename T,typename A> void list<T,A>::pop_front(){
  Node* temp{nullptr};
  if(head!=tail){
    temp = head;
    head = head->next;
    head->prev = nullptr; 
    destroyNode(temp);
    --size;
  }
}
template<typename T,typename A> void list<T,A>::pop_back(){
  Node* temp{nullptr};
  if(head!=tail){
    temp = tail->prev;
    tail->prev = temp->prev;
    temp->prev->next = tail;
    destroyNode(temp);
    --size;
  }
}

/*Clear the list*/                                                                                                         
template<typename T,typename A> void list<T,A>::clear() {
  Node* current = head;
  while (current != nullptr) {
    Node* nextNode = current->next;
    destroyNode(current);
    current = nextNode;
  }
  head = tail = nullptr;
  size = 0;
}
template<typename T,typename A> void list<T,A>::display() const {
  Node* current = head;
  while (current != tail) {
    std::cout << current->val << " <-> ";
    current = current->next;
  }
  std::cout << "end()" << std::endl;
}
template<typename T,typename A> list<T,A>::~list() {
  clear();
}
