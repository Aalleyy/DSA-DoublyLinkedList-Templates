#ifndef DLIST_H
#define DLIST_H

// Node Structure
template <class T>

struct Node{
	public:
		T data;
		Node<T>* next;
		Node<T>* prev;
};
// Defining Node Pointer Type
//commented because using template
//typedef Node* Nodeptr;

// List Class Declaration
template <class T>
class DList
{
    public:
        // constructor
        DList();
        // destructor
        virtual ~DList();
        // copy constructor
        DList(const DList& other);

        // boolean function
        bool empty() const;
        // access head element
        T headElement() const;
        // access tail element
        T tailElement() const;
        // access element at specific index
        T getAt(int idx);
        // add to the head
        void addHead(T newdata);
        // delete the head
        void delHead();
        // add to the head
        void addTail(T newdata);
        // delete the head
        void delTail();
        // add to the head
        void addAt(int idx, T newdata);
        // delete the head
        void delAt(int idx);
        // Clear the list
        void Clear();

        // utility function to get length of list
        int length() const;
        // display the list
        void print() const;

    private:
        void createDummyHead();
        //Go to specific index and return poiter to node at that position
        Node<T>* goToIndex(int idx);
        //head pointer, pointing to dummy noce actually
        Node<T>* head;
};

#endif // DLIST_H
