#include <bits/stdc++.h>
using namespace std;

#define SIZE 100000

template <class T>
class Stack
{
public:
    Stack();

    void push(T k);

    T pop();

    T topElement();

    int size();

    bool isFull();

    bool isEmpty();

private:
    int top;
    T st[SIZE];
};

template <class T>
Stack<T>::Stack() { top = -1; }

template <class T>
void Stack<T>::push(T k)
{

    if (isFull())
    {
        cout << "Stack is full\n";
    }
    top = top + 1;

    st[top] = k;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

template <class T>
bool Stack<T>::isFull()
{
    if (top == (SIZE - 1))
        return 1;
    else
        return 0;
}

template <class T>
T Stack<T>::pop()
{
    T popped_element = st[top];
    top--;
    return popped_element;
}

template <class T>
T Stack<T>::topElement()
{
    T top_element = st[top];
    return top_element;
}

template <class T>
int Stack<T>::size()
{
    return top + 1;
}

void print(int arr[], int n, Stack<int> st)
{
    if (st.size() == n)
    {
        while (!st.isEmpty())
        {
            cout << st.pop() << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        st.push(arr[i]);
        print(arr, n, st);
        st.pop();
    }
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Stack<int> st;
    print(arr, n, st);
}