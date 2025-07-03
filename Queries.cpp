#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;


class Node
{   
    public:
        long long int val;
        Node* next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }

};

void insert_at_tail(Node* &head, Node* &tail, long long int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void insert_at_head(Node* &head, Node* &tail, long long int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

int print_linked_list(Node* head)
{
    Node* temp = head;
    int count = -1;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        count ++;
        temp = temp->next;
    }
    cout << endl;
    return count;
}

void delete_at_head(Node* &head)
{
    Node* deletenode = head;
    head = head->next;
    delete deletenode;
}

void delete_at_tail(Node* &head, Node* &tail, int size)
{
    Node* temp = head;
    for(int i = 0; i < size-1; i++)
    {
        temp = temp->next;
    }
    Node* deletenode = temp->next;
    temp->next = temp->next->next;
    delete deletenode;
    tail = temp;
}

void delete_at_any(Node* &head, int size, int v)
{
    // cout << "Size" << size << endl;
    Node* temp = head;
    for(int i = 0; i < v-1; i++)
    {
        temp = temp->next;
    }
    Node* deletenode = temp->next;
    temp->next = temp->next->next;
    delete deletenode;
}

int main()
{

    int query;
    cin >> query;
    
    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < query; i++)
    {
        int x, v;
        cin >> x >> v;

        int size;

        if(x == 0)
        {
            //Insert at head;
            insert_at_head(head, tail, v);
            size = print_linked_list(head);
        }
        else if(x == 1)
        {
            //Insert at tail
            insert_at_tail(head, tail, v);
            size = print_linked_list(head);
        }
        else if(x == 2)
        {
            if(v > size)
            {
                size = print_linked_list(head);
            }
            else if(v == 0)
            {
                //Delete at head
                // size--;
                delete_at_head(head);
                size = print_linked_list(head);
            }
            else if(v == size)
            {
                //Delete at tail;
                delete_at_tail(head, tail, size);
                size = print_linked_list(head);
            }
            else
            {
                //Delete at any;
                delete_at_any(head, size, v);
                size = print_linked_list(head);
            }
        }
        // cout << "Size" << size << endl;

    }



    return 0;
}