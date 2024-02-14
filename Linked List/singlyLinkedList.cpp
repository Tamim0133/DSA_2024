/*
01 : Insert at head
02 : Insert at tail
03 : Insert at position
04 : Insert after a value

05. Search First index of a value
06. Search All Indices of a value
07. Get Value at an Index

08> Delete At Head
09> Delete At Tail
10> Delete At Position
11> Printing
12> Print Reverse Order
13>  Get sz

14 : Bubble Sort on Linked List
15 : Delete all Zeros
16 : Get Odd Index Sum

17>  LL has Duplicate Values ?
18>  Is LL Circular
19>  Detect Loop
20>  Detect Loop (floyd Version)
21>  Remove Loop

*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }

    // destructor
    // ~Node()
    // {
    //     int value = this->data;
    //     // memory free
    //     if (this->next != NULL)
    //     {
    //         delete next;
    //         this->next = NULL;
    //     }
    //     cout << " memory is free for node with data " << value << endl;
    // }
    // ~Node()
    // {
    //     int value = this->data;

    //     // delete this;

    //     cout << " memory is free for node with data " << value << endl;
    // }
};

class ll
{
public:
    Node *head;
    Node *tail;
    int sz;

    // constructor
    ll()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    /*---------------------------------------
                01: Insert At Head
    ---------------------------------------*/
    void insertAtHead(int d)
    {

        // new node create
        Node *a = new Node(d);
        if (head == NULL)
        {
            head = a;
            tail = a;
        }
        else
        {
            a->next = head;
            head = a;
        }

        sz++;
    }

    /*---------------------------------------
                   02: Insert At Tail
    ---------------------------------------*/
    void insertAtTail(int d)
    {
        // new node create
        Node *a = new Node(d);
        if (tail)
        {
            tail->next = a;
            tail = a;
        }
        else
        {
            head = a;
            tail = a;
        }

        sz++;
    }

    /*---------------------------------------
                03: Insert At Position
    ---------------------------------------*/
    // "1" based position
    void insertAtPosition(int position, int d)
    {
        if (position <= 0 || position > sz + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        // insert at Start
        if (position == 1)
        {
            insertAtHead(d);
            return;
        }

        Node *temp = head;
        int cnt = 1;

        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }

        // inserting at Last Position
        if (temp->next == NULL)
        {
            insertAtTail(d);
            return;
        }

        // creating a node for d
        Node *nodeToInsert = new Node(d);

        nodeToInsert->next = temp->next;

        temp->next = nodeToInsert;

        sz++;
    }

    /*------------------------------------------------------------
                    04 : Insert after a value
   ---------------------------------------------------------------*/
    void InsertAfterValue(int value, int data)
    {

        Node *a = head;

        while (a != NULL)
        {
            if (a->data == value)
            {
                break;
            }
            a = a->next;
        }

        sz++;

        if (a == NULL)
            cout << value << " Does not exists ! " << endl;

        Node *newnode = new Node(data);
        newnode->next = a->next;
        a->next = newnode;
    }

    /*------------------------------------------------------------
                05. Search First Index of a value
   ---------------------------------------------------------------*/
    int firstOccurrence(int value)
    {
        Node *a = head;
        int index = 0;

        while (a != NULL)
        {
            if (a->data == value)
                return index;
            a = a->next;
            index++;
        }

        return -1;
    }
    /*------------------------------------------------------------
                06. Search All Indices of a value
   ---------------------------------------------------------------*/
    void allOccurrences(int value)
    {
        Node *a = head;
        int index = 0;

        while (a != NULL)
        {
            if (a->data == value)
            {
                cout << value << " Found at index : " << index << endl;
            }

            a = a->next;
            index++;
        }
    }

    /*------------------------------------------------------------
                07. Get Value at an Index
   ---------------------------------------------------------------*/
    int getValueAtIndex(int index)
    {
        Node *a = head;
        int i = 0;

        if (index >= size())
        {
            return -1;
        }

        while (a != NULL)
        {
            if (i == index)
            {
                return a->data;
            }
            a = a->next;
            i++;
        }

        return -1;
    }

    /*--------------------------------------
               08> Delete At Head
    -----------------------------------------*/
    int deleteAtHead()
    {
        if (head == NULL)
            return -1;

        if (head == tail)
        {
            int x = head->data;

            head = NULL;
            tail = NULL;

            return x;
        }
        else
        {
            int x = head->data;
            head = head->next;
            return x;
        }
    }
    /*---------------------------------
               09> Delete At Tail
    ----------------------------------*/
    int deleteAtTail()
    {
        if (head == NULL)
            return -1;

        if (head == tail)
        {
            int x = tail->data;

            head = NULL;
            tail = NULL;

            return x;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }

            int x = tail->data;

            tail = temp;

            temp = tail->next;
            delete temp;

            tail->next = NULL;

            return x;
        }
    }

    /*--------------------------------------
            10> Delete At Position
    -----------------------------------------*/
    // Xoss Ekkhan Code
    //---------------------------
    void deleteNode(int position)
    {

        // deleting first or start node
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            // memory free start Node
            temp->next = NULL;
            delete temp;
        }
        else
        {
            // deleting any middle node or last node
            Node *curr = head;
            Node *prev = NULL;

            int cnt = 1;
            while (cnt < position)
            {
                prev = curr;
                curr = curr->next;
                cnt++;
            }

            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
    /*---------------------------------------
           11> Printing
 ---------------------------------------*/
    void print()
    {
        Node *p = head;
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        cout << endl;
    }
    /*------------------------------------------------------------
           12> Print Reverse Order
  ---------------------------------------------------------------*/
    void printReverse2(Node *a)
    {
        if (a == NULL)
            return;

        printReverse2(a->next);
        cout << a->data << " ";
    }

    void printReverse()
    {
        printReverse2(head);
        cout << endl;
    }

    /*---------------------------------------
              13>  Get sz
    ---------------------------------------*/
    int size()
    {
        return sz;
    }

    /*------------------------------------------------------------
           14 > Bubble Sort on Linked List
  ---------------------------------------------------------------*/
    void BubbleSort()
    {

        for (Node *i = head; i != NULL; i = i->next)
        {
            for (Node *j = i->next; j != NULL; j = j->next)
            {
                if (i->data > j->data)
                    swap(i->data, j->data);
            }
        }
    }

    /*------------------------------------------------------------
                15 : Delete all Zeros
   ---------------------------------------------------------------*/
    void deleteAllZeros()
    {
        // Handle the case where the list is empty
        if (head == nullptr)
        {
            return;
        }

        // Traverse the linked list
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            // Check if the current node has a zero value
            if (current->data == 0)
            {
                // If it does, remove the node
                if (prev == nullptr)
                {
                    // If it's the head, update the head
                    // cout << "At heda" << endl;
                    head = current->next;
                }
                else
                {
                    // Otherwise, update the previous node's next pointer
                    prev->next = current->next;
                }

                // Delete the current node
                // cout << "Deleting current node" << endl;
                delete current;

                // Move to the next node
                current = (prev == nullptr) ? head : prev->next;
                // cout << current->data << endl;
            }
            else
            {
                // If the current node doesn't have a zero value, move to the next node
                prev = current;
                current = current->next;
            }
        }
    }

    /*------------------------------------------------------------
                16 : Get Odd Index Sum
   ---------------------------------------------------------------*/
    int getOddIndexSum()
    {
        Node *a = head;
        int i = 0, sum = 0;
        while (a != NULL)
        {
            if (i % 2 == 1)
            {
                sum += a->data;
            }
            a = a->next;
            i++;
        }
        return sum;
    }

    /*------------------------------------------------------------
            17 : LL has Duplicate Values ?
   ---------------------------------------------------------------*/
    bool hasDuplicate()
    {
        Node *a = head;
        map<int, int> m;
        while (a != NULL) // Time Complexity of Nlogn
        {
            m[a->data]++;
            a = a->next;
        }

        for (auto i : m)
        {
            if (i.second > 1)
                return true;
        }
        return false;
    }
    /*----------------------------------------------------------------
                       18> Is LL Circular
    ------------------------------------------------------------------*/
    bool isCircularList()
    {
        // empty list
        if (head == NULL)
        {
            return true;
        }

        Node *temp = head->next;
        while (temp != NULL && temp != head)
        {
            temp = temp->next;
        }

        if (temp == head)
        {
            return true;
        }

        return false;
    }
    /*----------------------------------------------------
                  19>  Detect Loop
    ----------------------------------------------------*/
    bool detectLoop()
    {

        if (head == NULL)
            return false;

        map<Node *, bool> visited;

        Node *temp = head;

        while (temp != NULL)
        {

            // cycle is present
            if (visited[temp] == true)
            {
                cout << "Present on element " << temp->data << endl;
                return true;
            }

            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
    /*----------------------------------------------------
                  20>  Detect Loop (floyd Version)
    ----------------------------------------------------*/
    Node *floydDetectLoop()
    {

        if (head == NULL)
            return NULL;

        Node *slow = head;
        Node *fast = head;

        while (slow != NULL && fast != NULL)
        {

            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }

            slow = slow->next;

            if (slow == fast)
            {
                cout << "present at " << slow->data << endl;
                return slow;
            }
        }

        return NULL;
    }
    /* -----------------------------------------------
               21> Remove Loop
    -------------------------------------------------*/
    Node *getStartingNode(Node *head)
    {

        if (head == NULL)
            return NULL;

        Node *intersection = floydDetectLoop();
        Node *slow = head;

        while (slow != intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }

        return slow;
    }

    void removeLoop(Node *head)
    {

        if (head == NULL)
            return;

        Node *startOfLoop = getStartingNode(head);
        Node *temp = startOfLoop;

        while (temp->next != startOfLoop)
        {
            temp = temp->next;
        }

        temp->next = NULL;
    }
};

int main()
{
    ll l;
    l.insertAtHead(1);
    l.insertAtHead(2);
    l.insertAtHead(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtHead(6);
    l.insertAtPosition(1, 0);
    l.insertAtPosition(8, 0);

    // l.allOccurrences(101);
    // cout << l.firstOccurrence(101) << endl;

    l.print();
    // l.printReverse();
    // cout << l.size() << endl;

    // cout << l.getValueAtIndex(7) << endl;

    l.deleteAllZeros();
    l.print();
    return 0;
}