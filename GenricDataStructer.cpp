#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and doubly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL <T>::SinglyLL()
{
  first = NULL;
  iCount= 0;
}

template <class T>
void SinglyLL<T>::Display()
{
  cout<<"Elements of singly Linear LinkedList are : "<<"\n";

  NodeS<T> * temp = first;

  for(int iCnt = 1;iCnt <= iCount; iCnt++)
  {
  cout<<"| "<<temp-> data << " | ->";
  temp = temp -> next;
  } 
  cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
    }

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
   NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        temp->next = newn;
    }
    iCount++;  
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++; 
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
   if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
      if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
  int iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCL <T>::SinglyCL()
{
  first = NULL;
  last = NULL;
  iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
 cout<<"Elements of singly Linear LinkedList are : "<<"\n";

  NodeS<T> * temp = first;

  for(int iCnt = 1;iCnt <= iCount; iCnt++)
  {
  cout<<"| "<<temp-> data << " | ->";
  temp = temp -> next;
  } 
  cout<<"NULL"<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
  NodeS<T> * newn = new NodeS<T>;
  newn -> data = no;
  newn -> next = NULL;

   if(first == NULL && last == NULL)
   {
  first = newn;
  last = newn;
   }
   else if(first == last)
   {
   first = newn;
   first -> next = last;
   }
   else
   {
   newn -> next = first;
   first = newn;
   }
   iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
  NodeS<T> * newn = new NodeS<T>;
  newn -> data = no;
  newn -> next = NULL;

   if(first == NULL && last == NULL)
   {
  first = newn;
  last = newn;
   }
   else if(first == last)
   {
   last = newn;
   first -> next = last;
   }
   else
   {
   last -> next = newn;
   last = newn;
   }
   iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
   int count = Count();

    if((iPos < 1) || (iPos > count+1))
    {
        cout<<"Invalid position\n data Not initiated \n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == count+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++; 
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
  if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last == NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
  if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete last;
        first = NULL;
        last == NULL;
    }
    else
    {
          NodeS<T> *temp = first;
                                                                     

        while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = last;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
   int icount = Count();

    if((iPos < 1) || (iPos > icount))
    {
        cout<<"Invalid position \n ";
        cout<< "\n data Not deleted\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == icount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int); 
};

template <class T>
DoublyLL <T>::DoublyLL()
{
  first = NULL;
  last = NULL;
  iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
   cout<<"Elements of singly Linear LinkedList are : "<<"\n";

  NodeD<T> * temp = first;

  for(int iCnt = 1;iCnt <= iCount; iCnt++)
  {
  cout<<"| "<<temp-> data << " | ->";
  temp = temp -> next;
  } 
  cout<<"NULL"<<"\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
   NodeD<T> * newn = new NodeD<T>;
    newn-> data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }

    
    iCount++;

}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
     NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = last -> next;
    }

   
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
  if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T>* temp = first;

        for(int icnt = 1; icnt < iPos -1; icnt++)
        {
            temp = temp->next;
        }

       NodeD<T> * newn = new  NodeD<T>;
       newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
   if(iCount == 0)         // LL is empty
    {
        return; 
    }
    else if(iCount == 1)        // LL contains one node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else        // LL contains more than one node
    {  
         NodeD<T> * temp = first;
        first = first->next;
        delete temp;      // delete first->prev;

        }

    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(iCount == 0)         // LL is empty
    {
        return; 
    }
    else if(iCount == 1)        // LL contains one node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else        // LL contains more than one node
    {
          NodeD<T> * temp = first;
         while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = last;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
  if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;

        for(int icnt = 1; icnt < iPos -1; icnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCL <T>::DoublyCL()
{
  first = NULL;
  last = NULL;
  iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
   cout<<"Elements of singly Linear LinkedList are : "<<"\n";

 NodeD<T> * temp = first;

  for(int iCnt = 1;iCnt <= iCount; iCnt++)
  {
  cout<<"| "<<temp-> data << " | ->";
  temp = temp -> next;
  } 
  cout<<"NULL"<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
 NodeD<T> * newn = new NodeD<T>;
    newn-> data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }

    last -> next = first;
    first -> prev = last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
     NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = last -> next;
    }

    last -> next = first;
    first -> prev = last;
    
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T>* temp = first;

        for(int icnt = 1; icnt < iPos -1; icnt++)
        {
            temp = temp->next;
        }

       NodeD<T> * newn = new  NodeD<T>;
       newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
   if(iCount == 0)         // LL is empty
    {
        return; 
    }
    else if(iCount == 1)        // LL contains one node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else        // LL contains more than one node
    {
        first = first->next;
        delete last->next;      // delete first->prev;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
   if(iCount == 0)         // LL is empty
    {
        return; 
    }
    else if(iCount == 1)        // LL contains one node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else        // LL contains more than one node
    {
        last = last -> prev;
        delete last->next;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
   if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;

        for(int icnt = 1; icnt < iPos -1; icnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}


/////////////////////////////////////////////////////////////////
//////////     Queue data structure 
/////////////////////////////////////////////////////////////////
template <class T>
class Queue
{
    public:
        struct NodeS<T> * first;
        int iCount;

    public:
        Queue();
        void Enqueue(T no);      // InsertLast
        int Dequeue();              // DleteFirst
        void Display();
        int Count();
};
template <class T>
Queue <T>:: Queue()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void Queue <T>::Enqueue(T no)        // InsertLast
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T>* temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
} 

template <class T>
int Queue<T>::Dequeue()        // Deletefirst
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = first -> data;
        delete first;
        first = NULL;
    }
    else
    {
        Value = first -> data;
        NodeS<T>* temp = first;
        first = first -> next;
        delete temp;
    }

    iCount--;

    return Value;
}              

template <class T>
void Queue <T>::Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }
    
    cout<<"Elements of Queue are : \n";

    NodeS<T>*temp = first;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////
/////   Stack Datab Structure
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
    private:
        struct NodeS<T> * first;
        int iCount;

    public:
        Stack();
        void Push(int no);      // InsertLast
        int Pop();              // DleteLast
        void Display();
        int Count();
};

template <class T>
Stack<T>:: Stack()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Push(int no)        // InsertLast
{
   NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;
    
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
       NodeS<T> * temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
} 

template <class T>
int Stack <T>::Pop()        // DeleteLast
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = first -> data;
        delete first;
        first = NULL;
    }
    else
    {
         NodeS<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;

    return Value;
}              

template <class T>
void Stack <T>::Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }
    
    cout<<"Elements of Queue are : \n";

    NodeS<T>*temp = first;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}
////////////////////////////////////////////////////////////////////////////////////////////
/////////   Buble sort 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        void BubbleSortEfficient();
        void InsertionSort();
};


/////
//    Dynamic memory allocations in Constructor 
////
template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

/////
//     memory  Deallocation in distructor 
////
template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

/////
//    accept array element
////
template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

/////
//    Display array element
////
template <class T>
void ArrayX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

/////
//    Funtion for bubble sorting
////
template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

/////
//    Funtion forInsrtion sorting 
////

template <class T>
void ArrayX <T>::InsertionSort()
{
    int i =0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL <int>obj1;
    SinglyCL <int>obj2;
    DoublyLL <int>obj3;
    DoublyCL <int>obj4;

    
   Queue <int>obj5;
   Stack <int>obj6;

    return 0;

}


