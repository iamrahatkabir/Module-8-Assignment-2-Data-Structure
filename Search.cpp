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
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, long long int val)
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

void print_linked_list(Node *head, int x)
{
    Node *temp = head;

    int count = -1;

    int flag = 0;
    while (temp != NULL)
    {
        // cout << temp->val << " ";
        count++;

        if(temp->val == x)
        {
            flag = 1;
            break;
        }

        temp = temp->next;
    }
    if(flag == 1)
    {
        cout << count;
    }
    else{
        cout << -1;
    }
    cout << endl;

}

int main()
{
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        Node *head = NULL;
        Node *tail = NULL;

        long long int val;
        while (cin >> val)
        {
            if (val == -1)
            {
                break;
            }
            insert_at_tail(head, tail, val);
        }

        long long int x; cin >> x;

        print_linked_list(head, x);
    }

    return 0;
}