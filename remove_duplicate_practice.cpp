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
#include <limits>
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
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newcode = new Node(val);

    if (head == NULL)
    {
        head = newcode;
        tail = newcode;
        return;
    }
    tail->next = newcode;
    tail = newcode;
}

void remove_duplicate(Node* &head)
{
    Node* temp = head;
    
    while(temp != NULL)
    {
        Node* temp2 = temp;
        while(temp2->next != NULL)
        {
            if(temp->val == temp2->next->val)
            {
                // cout << temp->val << " ";
                Node* deletenode = temp2->next;
                temp2->next = temp2->next->next;
    
                delete deletenode;
            }
            else
            {
                temp2 = temp2->next;
            }

        }
        // cout << endl;

        temp = temp->next;
    }

}

void print_linked_list(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (cin >> val)
    {
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    remove_duplicate(head);
    print_linked_list(head);

    return 0;
}