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

void print_linked_list(Node* head)
{
    Node* temp = head;

    int min = INT_MAX;
    int max = INT_MIN;

    while(temp != NULL)
    {
        if(temp->val < min)
        {
            min = temp->val;
        }
        if(temp->val > max)
        {
            max = temp->val;
        }
        temp = temp->next;
    }

    cout << max-min << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    long long int val;
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
    
    print_linked_list(head);

    return 0;
}