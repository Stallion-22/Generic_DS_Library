#include<iostream>
using namespace std;

template<class T>
struct node1
{
    T data;
    struct node1* next;
};

template<class T>
struct node2
{
    T data;
    struct node2* next;
    struct node2* prev;
};

template<class T>
class SinglyLL
{
    private:
        int Count;
        struct node1<T>* Head;

    public:
        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        
        void Display();
        int CountNode();

        void BubbleSort(char type);
        void SelectionSort(char type);
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}
template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node1<T>* newn = NULL;
    newn = new node1<T>();

    newn->data = no;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}
template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node1<T>* newn = NULL;

    newn = new node1<T>();

    newn->data = no;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else if(Count == 1)
    {
        Head->next = newn;
    }
    else
    {
        struct node1<T>* temp = Head;
        while( temp->next != NULL )
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}
template<class T>
void SinglyLL<T>::InsertAtPos(T no,int pos)
{
    if(( pos <= 0 ) || ( pos > Count+1 ))
    {
        cout<<"Invalid Insert Position"<<endl;
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {

        struct node1<T>* newn = NULL;
        newn = new node1<T>();

        newn->data = no;
        newn->next = NULL;

        struct node1<T>* temp = Head;

        for(int i=1 ; i<pos-1 ; i++ )
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        Count++;
    }
}
template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node1<T>* temp = Head->next;
        delete Head;
        Head = temp;
    }
    Count--;
}
template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node1<T>* temp = Head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count --;
}
template<class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    if(( pos <= 0 ) || ( pos > Count ))
    {
        cout<<"Invalid Delete Position"<<endl;
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node1<T>* temp1 = Head;
        struct node1<T>* temp2 = NULL;
        for(int i = 1 ; i<pos-1 ; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        Count--;
    }
}
template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements are: "<<endl;
    struct node1<T>* temp = Head;
    for(int i = 1; i<=Count ; i++ )
    {
        cout<<temp->data<<" "<<endl;
        temp = temp->next;
    }

}
template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyLL<T>::BubbleSort(char type)
{
    int i = 0; 
    struct node1<T>* j = NULL;
    bool swap = false;
    T temp = 0; 

    for( i=0 ; i<Count ; i++ )
    {
        for( j=Head , swap=false ; j->next!=NULL ; j=j->next )
        {
            if( type == 'I' || type == 'i' )
            {
                if( j->data > j->next->data )
                {
                    temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swap =true;
                }
            }
            else if( type == 'D' || type == 'd' )
            {
                if( j->data < j->next->data )
                {
                    temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swap =true;
                }
            }
        }
        if( !swap )
        {
            break;
        }
    }

}

template<class T>
void SinglyLL<T>::SelectionSort(char type)
{
    struct node1<T>* min_index = NULL ; 
    struct node1<T>* i = NULL ;
    struct node1<T>* j = NULL ;
    T temp = 0; 

    for( i = Head ; i->next !=NULL  ; i++ )
    {
        for( j=i->next , min_index = i ; j!=NULL ; j++ )
        {
            if( type == 'I' || type == 'i' )
            {
                if(min_index->data > j->data)
                {
                    min_index = j;
                }
            }
            if( type == 'D' || type == 'd' )
            {
                if(min_index->data < j->data)
                {
                    min_index = j;
                }
            }
        }
        if( i != min_index )
        {
            temp = i->data;
            i->data = min_index->data;
            min_index->data = temp;
        }
    }
}

template<class T>
class DoublyLL
{
    private:
        int Count;
        struct node2<T>* Head;
        struct node2<T>*Tail;

    public:
        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int CountNode();

        void BubbleSort(char type);
        void SelectionSort(char type);
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node2<T>* newn = NULL;
    newn = new node2<T>();

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Count == 0)
    {
        Tail = newn;
        newn->next = NULL;
    }
    else
    {
        newn->next = Head;
    }
    Head = newn;
    newn->prev = NULL;
    Count++;
}
template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node2<T>* newn = NULL;

    newn = new node2<T>();

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Count == 0)
    {
        Head = newn;
        newn->prev = NULL;
    }
    else if(Count == 1)
    {
        Head->next = newn;
        newn->prev = Head;
    }
    else
    {
        struct node2<T>* temp = Head;
        while( temp->next != NULL )
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    Tail = newn;
    newn->next = NULL;
    Count++;
}
template<class T>
void DoublyLL<T>::InsertAtPos(T no,int pos)
{
    if(( pos <= 0 ) || ( pos > Count+1 ))
    {
        cout<<"Invalid Insert Position"<<endl;
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node2<T>* newn = NULL;
        newn = new node2<T>();

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct node2<T>* temp = Head;

        for(int i=1 ; i<pos-1 ; i++ )
        {
            temp = temp->next;
        }
        temp->next->prev = newn;
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;

        Count++;

    }
}
template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
        Head->prev = NULL;
    }
    Count--;
}
template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node2<T>* temp = Head;
        temp = Tail->prev;
        delete Tail;
        Tail = temp;
    }
    Count --;
}
template<class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    if(( pos <= 0 ) || ( pos > Count ))
    {
        cout<<"Invalid Delete Position"<<endl;
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node2<T>* temp1 = Head;
        for(int i = 1 ; i<pos-1 ; i++)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
        delete temp1->next->prev;
        temp1->next->prev = temp1;
        Count--;
    }
}
template<class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements are: "<<endl;
    struct node2<T>* temp = Head;
    for(int i = 1; i<=Count ; i++ )
    {
        cout<<temp->data<<" "<<endl;
        temp = temp->next;
    }
}
template<class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}
template<class T>
void DoublyLL<T>::BubbleSort(char type)
{
    int i = 0; 
    struct node2<T>* j = NULL;
    bool swap = false;
    T temp = 0; 

    for( i=0 ; i<Count ; i++ )
    {
        for( j=Head , swap=false ; j->next!=NULL ; j=j->next )
        {
            if( type == 'I' || type == 'i' )
            {
                if( j->data > j->next->data )
                {
                    temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swap =true;
                }
            }
            else if( type == 'D' || type == 'd' )
            {
                if( j->data < j->next->data )
                {
                    temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swap =true;
                }
            }
        }
        if( !swap )
        {
            break;
        }
    }

}
template<class T>
void DoublyLL<T>::SelectionSort(char type)
{
    struct node2<T>* min_index = NULL ; 
    struct node2<T>* i = NULL ;
    struct node2<T>* j = NULL ;
    T temp = 0; 

    for( i = Head ; i->next !=NULL  ; i++ )
    {
        for( j=i->next , min_index = i ; j!=NULL ; j++ )
        {
            if( type == 'I' || type == 'i' )
            {
                if(min_index->data > j->data)
                {
                    min_index = j;
                }
            }
            if( type == 'D' || type == 'd' )
            {
                if(min_index->data < j->data)
                {
                    min_index = j;
                }
            }
        }
        if( i != min_index )
        {
            temp = i->data;
            i->data = min_index->data;
            min_index->data = temp;
        }
    }
}

template<class T>
class SinglyCL
{
    private:
        int Count;
        struct node1<T>* Head;
        struct node1<T>* Tail;

    public:

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int CountNode();

        void BubbleSort(char type);
        void SelectionSort(char type);
};

template<class T>
SinglyCL<T>::SinglyCL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
template<class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct node1<T>* newn = NULL;
    newn = new node1<T>();

    newn->data = no;
    newn->next = NULL;

    if(Count == 0)    //LL is Empty
    {
        Head = newn;
        Tail = newn;
    }
    else             // Atleast 1 element
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
    Count++;
}
template<class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node1<T>* newn = NULL;

    newn = new node1<T>();

    newn->data = no;
    newn->next = NULL;

    if(Count == 0)     // LL is Empty
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
    Count++;
}
template<class T>
void SinglyCL<T>::InsertAtPos(T no,int pos)
{
    if(( pos <= 0 ) || ( pos > Count+1 ))
    {
        cout<<"Invalid Insert Position"<<endl;
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node1<T>* newn = NULL;
        newn = new node1<T>();

        newn->data = no;
        newn->next = NULL;

        struct node1<T>* temp = Head;

        for(int i=1 ; i<pos-1 ; i++ )
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        Count++;
    }
}
template<class T>
void SinglyCL<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
        Tail->next = Head; 
    }
    Count--;
}
template<class T>
void SinglyCL<T>::DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct node1<T>* temp = Head;
        while(temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        temp->next = Head;
        Tail = temp;
    }
    Count --;
}
template<class T>
void SinglyCL<T>::DeleteAtPos(int pos)
{
    if(( pos <= 0 ) || ( pos > Count ))
    {
        cout<<"Invalid Delete Position"<<endl;
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node1<T>* temp1 = Head;
        struct node1<T>* temp2 = NULL;
        for(int i = 1 ; i<pos-1 ; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        Count--;
    }
}
template<class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements are: "<<endl;
    struct node1<T>* temp = Head;
    for(int i = 1; i<=Count ; i++ )
    {
        cout<<temp->data<<" "<<endl;
        temp = temp->next;
    }
}
template<class T>
int SinglyCL<T>::CountNode()
{
    return Count;
}
template<class T>
void SinglyCL<T>::BubbleSort(char type)
{
    int i = 0; 
    struct node1<T>* j = NULL;
    bool swap = false;
    T temp = 0; 

    for( i=0 ; i<Count ; i++ )
    {
        for( j=Head , swap=false ; j->next!=Head ; j=j->next )
        {
            if( type == 'I' || type == 'i' )
            {
                if( j->data > j->next->data )
                {
                    temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swap =true;
                }
            }
            else if( type == 'D' || type == 'd' )
            {
                if( j->data < j->next->data )
                {
                    temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swap =true;
                }
            }
        }
        if( !swap )
        {
            break;
        }
    }

}
template<class T>
void SinglyCL<T>::SelectionSort(char type)
{
    struct node1<T>* min_index = NULL ; 
    struct node1<T>* i = NULL ;
    struct node1<T>* j = NULL ;
    T temp = 0;

    for( i = Head ; i->next !=Head  ; i++ )
    {
        for( j=i->next , min_index = i ; j!=Head ; j++ )
        {
            if( type == 'I' || type == 'i' )
            {
                if(min_index->data > j->data)
                {
                    min_index = j;
                }
            }
            if( type == 'D' || type == 'd' )
            {
                if(min_index->data < j->data)
                {
                    min_index = j;
                }
            }
        }
        if( i != min_index )
        {
            temp = i->data;
            i->data = min_index->data;
            min_index->data = temp;
        }
    }
}

template<class T>
class DoublyCL
{
    private:
        int Count;
        struct node2<T>* Head;
        struct node2<T>* Tail;

    public:
        
        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int CountNode();

        void BubbleSort(char type);
        void SelectionSort(char type);
};

template<class T>
DoublyCL<T>::DoublyCL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
template<class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct node2<T>* newn = NULL;
    newn = new node2<T>();

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Head->prev = newn;
        newn->next = Head;
        Head = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count++;
}
template<class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct node2<T>* newn = NULL;

    newn = new node2<T>();

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head; 
    Count++;
}
template<class T>
void DoublyCL<T>::InsertAtPos(T no,int pos)
{
    if(( pos <= 0 ) || ( pos > Count+1 ))
    {
        cout<<"Invalid Insert Position"<<endl;
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node2<T>* newn = NULL;
        newn = new node2<T>();

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct node2<T>* temp = Head;

        for(int i=1 ; i<pos-1 ; i++ )
        {
            temp = temp->next;
        }
        temp->next->prev = newn;
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp; 

        Count++;

    }
}
template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
    }

    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}
template<class T>
void DoublyCL<T>::DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Tail->next;
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count --;
}
template<class T>
void DoublyCL<T>::DeleteAtPos(int pos)
{
    if(( pos <= 0 ) || ( pos > Count ))
    {
        cout<<"Invalid Delete Position"<<endl;
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node2<T>* temp1 = Head;
        for(int i = 1 ; i<pos-1 ; i++)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
        delete temp1->next->prev;
        temp1->next->prev = temp1;
        Count--;
    }
}
template<class T>
void DoublyCL<T>::Display()
{
    cout<<"Elements are: "<<endl;
    struct node2<T>* temp = Head;
    for(int i = 1; i<=Count ; i++ )
    {
        cout<<temp->data<<" "<<endl;
        temp = temp->next;
    }
}
template<class T>
int DoublyCL<T>::CountNode()
{
    return Count;
}
template<class T>
void DoublyCL<T>::BubbleSort(char type)
{
    int i = 0; 
    struct node2<T>* j = NULL;
    bool swap = false;
    T temp = 0; 

    for( i=0 ; i<Count ; i++ )
    {
        for( j=Head , swap=false ; j->next!=Head ; j=j->next )
        {
            if( type == 'I' || type == 'i' )
            {
                if( j->data > j->next->data )
                {
                    temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swap =true;
                }
            }
            else if( type == 'D' || type == 'd' )
            {
                if( j->data < j->next->data )
                {
                    temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swap =true;
                }
            }
        }
        if( !swap )
        {
            break;
        }
    }

}
template<class T>
void DoublyCL<T>::SelectionSort(char type)
{
    struct node2<T>* min_index = NULL ; 
    struct node2<T>* i = NULL ;
    struct node2<T>* j = NULL ;
    T temp = 0; 

    for( i = Head ; i->next !=Head  ; i++ )
    {
        for( j=i->next , min_index = i ; j!=Head ; j++ )
        {
            if( type == 'I' || type == 'i' )
            {
                if(min_index->data > j->data)
                {
                    min_index = j;
                }
            }
            if( type == 'D' || type == 'd' )
            {
                if(min_index->data < j->data)
                {
                    min_index = j;
                }
            }
        }
        if( i != min_index )
        {
            temp = i->data;
            i->data = min_index->data;
            min_index->data = temp;
        }
    }
}

template<class T>
class Stack
{
    private:
        int Count;
        struct node1<T>* Head;

    public:
        Stack();

        void Push(T no);
        void Pop();
        
        void Display();
        int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)          //InsertFirst(int no)
{
    struct node1<T>* newn = NULL;
    newn = new node1<T>();

    newn->data = no;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void Stack<T>::Pop()                //DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node1<T>* temp = Head->next;
        delete Head;
        Head = temp;
    }
    Count--;
}

template<class T>
void Stack<T>::Display()
{
    cout<<"Elements are: "<<endl;
    struct node1<T>* temp = Head;
    for(int i = 1; i<=Count ; i++ )
    {
        cout<<temp->data<<" "<<endl;
        temp = temp->next;
    }
}

template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

template<class T>
class Queue
{
    private:
        int Count;
        struct node1<T>* Head;

    public:
        Queue();

        void Enqueue(T no);           //InsertFirst()
        void Dequeue();                 //DeleteLast()
        
        void Display();
        int CountNode();
};

template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Queue<T>::Enqueue(T no)          //InsertFirst(int no)
{
    struct node1<T>* newn = NULL;
    newn = new node1<T>();

    newn->data = no;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void Queue<T>::Dequeue()                //DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node1<T>* temp = Head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count --;
}

template<class T>
void Queue<T>::Display()
{
    cout<<"Elements are: "<<endl;
    struct node1<T>* temp = Head;
    for(int i = 1; i<=Count ; i++ )
    {
        cout<<temp->data<<" "<<endl;
        temp = temp->next;
    }
}

template<class T>
int Queue<T>::CountNode()
{
    return Count;
}

int main()
{
    SinglyCL<char> obj1;

    /*obj1.InsertFirst(40);
    obj1.InsertFirst(20);
    obj1.InsertFirst(60);
    obj1.InsertFirst(30);
    obj1.InsertFirst(10);*/

    
    obj1.InsertFirst('A');
    obj1.InsertFirst('D');
    obj1.InsertFirst('I');
    obj1.InsertFirst('B');
    obj1.InsertFirst('C');

    cout<<"Before sort ";
    obj1.Display();

    obj1.BubbleSort('D');

    cout<<"After sort ";
    obj1.Display();
    
    return 0;
}
