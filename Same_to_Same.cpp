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
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void insert_at_tail_2(Node* &head2, Node* &tail2, int val2)
{
    Node *newnode = new Node(val2);
    if (head2 == NULL)
    {
        head2 = newnode;
        tail2 = newnode;
        return;
    }
    tail2->next = newnode;
    tail2 = newnode;
}

//  

void print_linked_list(Node *head, Node* head2)
{
    Node *temp = head;
    Node* temp2 = head2;

    int flag = 1;

    while(temp != NULL && temp2 != NULL)
    {
        if(temp->val != temp2->val)
        {
            flag = 0;
            break;
        }

        temp = temp->next;
        temp2 = temp2->next;
    }
    if(flag == 1)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    int count = 0;
    while(cin >> val)
    {
        if(val == -1)
        {
            break;
        }
        count++;
        insert_at_tail(head, tail, val);
    }

    Node* head2 = NULL;
    Node* tail2 = NULL;

    int val2;
    int count2 = 0;
    while(cin >> val2)
    {
        if(val2 == -1)
        {
            break;
        }
        count2++;
        insert_at_tail(head2, tail2, val2);
    }

    if(count == count2)
    {
        print_linked_list(head, head2);
    }
    else{
        cout << "NO" << endl;
    }
    

    return 0;
}