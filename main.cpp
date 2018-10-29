//
// Created by Master64k on 30/10/2017.
//

#include <iostream>

using namespace std;

typedef struct _Data
{
    int i = 0;
    struct _Data* next = nullptr;
}Data, *pData;


class LinkedList
{
    pData Last;
    pData Item;
    int iCount;

public:

    LinkedList()
    {
        this->Item = new Data;
        this->Item->next = nullptr;
        iCount = 0;
        Last = nullptr;

    }

    pData add()
    {
        if(this->iCount == 0)
        {
            this->iCount++;
            this->Last = this->Item;
            return Item;
        }
        else
        {

            Last->next = new Data;
            Last = Last->next;
            this->iCount++;
            return Last;
        }
    }

    int Size()
    {
        return this->iCount;
    }

    pData operator[](const int i)
    {
        if(i < 0 || i > this->iCount)
        {
            return nullptr;
        }
        else
        {
            if(i == 0)
                return Item;
            else
            {
                pData tmp = this->Item->next;
                for(int a = 1;tmp->next not_eq nullptr;a++)
                {
                    if(a == i)
                        return tmp;
                    else
                    {
                        if( tmp->next not_eq nullptr)
                            tmp = tmp->next;

                        continue;
                    }
                }
                return tmp;
            }
        }
    }
    ~LinkedList()
    {
        if(!Item->next)
            return;

        pData tmp = Item;
        cout << "\n\n-----------Destructor-------------\n\n";
        while(tmp->next != nullptr)
        {
            pData foo = tmp;
            tmp = tmp->next;
            cout << "DBG -- deleting entry with number " << foo->i << endl;
            delete foo;
        }
        cout << "DBG -- deleting entry with number " << tmp->i << endl;
        delete tmp;
    }

    pData Insert(const int index)
    {
        // parameter checking
        if(index < 0 || index > this->iCount)
            return nullptr;

        pData prev, nxt, nw;

        if(index == 0) {
            nw = new Data;

            nw->next = this->Item;

            this->Item = nw;

            this->iCount++;

            return nw;

        }

        prev = this->operator[](index -1);
        nxt = prev->next;

        nw = new Data;

        prev->next = nw;

        nw->next = nxt;

        this->iCount++;
        return nw;

    }
};

void print(LinkedList* l)
{
    cout << "items list: " << endl;
    for(int a = 0; a < l->Size();a++)
    {
        pData pf = l->operator[](a);
        if(pf)
        {
            cout << pf->i << endl;
        }
        else cout << "DBG -- error at index: " << a << endl << endl;
    }

    cout << endl;
}

int main()
{
    LinkedList l;

    for(int a = 1;a <= 5;a++)
    {

        pData pf = l.add();

        pf->i = a;
    }

    print(&l);

    pData pf = l.Insert(1);
    pf->i = 2;

    cout << "inserting value 2 at index 1" << endl;

    pf = l.Insert(3);
    pf->i = 4;

    cout << "inserting value 4 at index 3" << endl;

    pf = l.Insert(5);
    pf->i = 6;

    cout << "inserting value 6 at index 5" << endl;

    pf = l.Insert(7);
    pf->i = 8;

    cout << "inserting value 8 at index 7" << endl;

    print(&l);
}
