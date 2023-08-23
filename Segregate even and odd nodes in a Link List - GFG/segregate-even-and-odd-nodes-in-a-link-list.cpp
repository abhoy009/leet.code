//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    Node* divide(int N, Node *head) {
        if (!head || !head->next)
            return head; // Nothing to segregate if the list is empty or has only one node

        Node *evenHead = nullptr, *evenTail = nullptr;
        Node *oddHead = nullptr, *oddTail = nullptr;

        Node *current = head;
        while (current) {
            if (current->data % 2 == 0) {
                if (!evenHead) {
                    evenHead = evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = current;
                }
            } else {
                if (!oddHead) {
                    oddHead = oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = current;
                }
            }
            current = current->next;
        }

        if (evenHead) {
            evenTail->next = oddHead; // Connect the even list to the odd list
            if (oddTail) {
                oddTail->next = nullptr; // Terminate the odd list
            }
            return evenHead; // Return the head of the modified even-odd segregated list
        } else {
            return oddHead; // If no even nodes, return the head of the odd list
        }
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends