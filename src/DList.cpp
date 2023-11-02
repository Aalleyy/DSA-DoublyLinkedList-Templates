#include "DList.h"
#include <iostream>

using namespace std;
template <class T>
DList<T>::DList()
{
    createDummyHead();
}
template <class T>
DList<T>::~DList()
{
    //Clear The list
    Clear();
    //Delete Dummy Node
    //Write your code between these lines only
    //---------------------------
    delete head;
    //---------------------------
}

// copy constructor
template <class T>
DList<T>::DList(const DList& other)
{
    //Initialize current list
    createDummyHead();
    //Check if other list is empty (if empty do nothing)
    if(other.empty())
        return;
    //Iterate through all the nodes of other list
    //and add all data elements to current list
    Node<T>* other_curr = other.head->next;
    Node<T>* other_head = other.head;

    //Write your code between these lines only
    //---------------------------
    while(other_curr != other_head)
    {
        addTail(other_curr->data);
        other_curr = other_curr->next;
    }
    //---------------------------
}

// boolean function
template <class T>
bool DList<T>::empty() const
{
    //Write your code between these lines only
    //---------------------------
    if(head->next == head && head->prev == head)
        return 1;
    else
        return 0;
    //---------------------------
}

// access head element
template <class T>
T DList<T>::headElement() const
{
    if(!empty())
        return head->next->data;
    cerr<<"List is Empty";
}

// access tail element
template <class T>
T DList<T>::tailElement() const
{
    if(!empty())
        return head->prev->data;
    cerr<<"List is Empty";
}

// access element at specific index
template <class T>
T DList<T>::getAt(int idx)
{
    Node<T>* pos = goToIndex(idx);
    if(pos != NULL)
    {
    //Write your code between these lines only
    //---------------------------
    return pos->data;
    //---------------------------
    }
}

// add to the head
template <class T>
void DList<T>::addHead(T newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual First Node
    Node<T>* curr = head->next;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Node<T>* p = new Node<T>;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    p->data = newdata;
    p->next = curr;
    p->prev = head;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    curr->prev = p;
    head->next = p;
    //---------------------------
}

// delete the head
template <class T>
void DList<T>::delHead()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Head Node,
    //Just after DummyHead
    Node<T>* curr = head->next;
    //Update references
    //Write your code between these lines only
    //---------------------------
    head->next = curr->next;
    curr->next->prev = head;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------

}

// add to the tail
template <class T>
void DList<T>::addTail(T newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual Last Node
    //Nodeptr curr = head; (commented as it has nouse in the code)
    //Create New Node
    Node<T>* newnode = new Node<T>;
    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    newnode->data = newdata;
    newnode->next = head;
    newnode->prev = head->prev;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    head->prev->next = newnode;
    head->prev = newnode;
    //---------------------------

}

// delete the tail
template <class T>
void DList<T>::delTail()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Tail Node,
    //Just Before DummyHead
    Node<T>* curr = head->prev;
    //Update references
    //Write your code between these lines only
    //---------------------------
    head->prev = curr->prev;
    curr->prev->next = head;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------

}

// add to the specific index
template <class T>
void DList<T>::addAt(int idx, T newdata)
{
    //Get node at current position
    Node<T>* curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Node<T>* p = new Node<T>;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    p->data = newdata;
    p->next = curr;
    p->prev = curr->prev;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    p->prev->next = p;
    curr->prev = p;
    //---------------------------

}

// delete the specific index
template <class T>
void DList<T>::delAt(int idx)
{
    //Get node at current position
    Node<T>* curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Update references
    //Write your code between these lines only
    //---------------------------
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------
}

// utility function to get length of list
template <class T>
int DList<T>::length() const
{
    //Write your code between these lines only
    //---------------------------
    if(empty())
    {
        return 0;
    }
    else
    {
        Node<T>* ptr = head->next;
        int x = 0;
        while(ptr!=head)
        {
            x++;
            ptr = ptr->next;
        }
        return x;
    }
    //---------------------------

}

// display the list
template <class T>
void DList<T>::print() const
{
    //Set the starting point of list
    Node<T>* curr = head->next;
    cout << "[";
    //Iterate and display list.
    //Make sure to handle comma ',' seperation is correct
    if(!empty()){
        cout << curr->data;
        curr = curr->next;
    }
    while(curr != head){
        cout << ", " << curr->data;
        curr = curr -> next;
    }
    cout << "]" << endl;
}

// Add dummy Head and populate
template <class T>
void DList<T>::createDummyHead()
{
    head = new Node<T>;
    head->next = head;
    head->prev = head;
}

// Clear The List
template <class T>
void DList<T>::Clear()
{
    while(!empty())
        delHead();
}

//Go to specific index and return poiter to node at that position
//Indexing is zero based
template <class T>
Node<T>* DList<T>::goToIndex(int idx)
{
    if(idx > length())
    {
        cerr<<"Error! Given index exceed the size of list ";
        return NULL;
    }

    //Iterate uptill given index
    Node<T>* curr = head->next;
    //Write your code between these lines only
    //---------------------------
    for(int i=0;i<idx;i++)
    {
        curr = curr->next;
    }
    //---------------------------
    return curr;
}

