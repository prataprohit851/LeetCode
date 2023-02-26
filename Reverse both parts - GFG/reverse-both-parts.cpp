//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution{
    private:
        Node* rev(Node* head, Node* &h2){
            if(head->next==NULL){
                h2=head;
                return head;
            }
            
            rev(head->next, h2)->next=head;
            return head;
        }
    public:
        Node *reverse(Node *head, int k){
            Node* temp=head;
            Node* h1=NULL;
            while(k!=1){
                temp=temp->next;
                k--;
            }
            h1=temp;
            
            Node* h2=NULL;
            
            rev(head, h2)->next=NULL;
            
            temp=h1;
            
            while(temp->next!=h1){
                if(temp->next==NULL){
                    temp->next=h2;
                }
                temp=temp->next;
            }
            temp->next=NULL;
            return h1;
        }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends