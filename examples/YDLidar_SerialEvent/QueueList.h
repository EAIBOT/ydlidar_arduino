// header defining the interface of the source.
#ifndef _QUEUELIST_H
#define _QUEUELIST_H

// the definition of the queue class.
template<typename T>
class QueueList {
  public:
    // init the queue (constructor).
    QueueList ();

    // clear the queue (destructor).
    ~QueueList ();

    // push an item to the queue.
    void push (const T i);

    // pop an item from the queue.
    T pop ();

    // get an item from the queue.
    T peek () const;

    // check if the queue is empty.
    bool isEmpty () const;

    // get the number of items in the queue.
    int count () const;

  private:
    // the structure of each node in the list.
    typedef struct node {
      T item;      // the item in the node.
      node * next; // the next node in the list.
    } node;

    typedef node * link; // synonym for pointer to a node.

    int size;        // the size of the queue.
    link head;       // the head of the list.
    link tail;       // the tail of the list.
};

// init the queue (constructor).
template<typename T>
QueueList<T>::QueueList () {
  size = 0;       // set the size of queue to zero.
  head = NULL;    // set the head of the list to point nowhere.
  tail = NULL;    // set the tail of the list to point nowhere.
}

// clear the queue (destructor).
template<typename T>
QueueList<T>::~QueueList () {
  // deallocate memory space of each node in the list.
  for (link t = head; t != NULL; head = t) {
    t = head->next; delete head;
  }

  size = 0;       // set the size of queue to zero.
  tail = NULL;    // set the tail of the list to point nowhere.
}

// push an item to the queue.
template<typename T>
void QueueList<T>::push (const T i) {
  // create a temporary pointer to tail.
  link t = tail;

  // create a new node for the tail.
  tail = (link) new node;


  // set the next of the new node.
  tail->next = NULL;

  // store the item to the new node.
  tail->item = i;

  // check if the queue is empty.
  if (isEmpty ())
    // make the new node the head of the list.
    head = tail;
  else
    // make the new node the tail of the list.
    t->next = tail;
  
  // increase the items.
  size++;
}

// pop an item from the queue.
template<typename T>
T QueueList<T>::pop () {

  // get the item of the head node.
  T item = head->item;

  // remove only the head node.
  link t = head->next; delete head; head = t;

  // decrease the items.
  size--;

  // return the item.
  return item;
}

// get an item from the queue.
template<typename T>
T QueueList<T>::peek () const {

  // return the item of the head node.
  return head->item;
}

// check if the queue is empty.
template<typename T>
bool QueueList<T>::isEmpty () const {
  return head == NULL;
}

// get the number of items in the queue.
template<typename T>
int QueueList<T>::count () const {
  return size;
}



#endif // _QUEUELIST_H
