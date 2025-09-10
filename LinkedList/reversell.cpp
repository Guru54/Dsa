#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(){
        next = nullptr;
    }
    Node(int x){
        data = x;
        next = nullptr;
    }
    Node(int x, Node* next){
        data = x;
        this->next = next;
    }
};
Node* convert(vector<int> &arr){
    if(arr.size()==0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        
        temp = temp->next;
        

    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<< " x "<<endl;
}
Node* reverse( Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next; 
    while(current){
        next = current->next;
        current->next = prev;
        
        prev =  current;
        current = next;

    }
    return prev;
}
Node* rreverse(Node* head){
    if(!head|| !head->next) return head;
    Node* newhead = rreverse(head->next);
    Node* temp = head->next;
    temp->next = head;
    head->next = nullptr;

   return newhead;
}

// detect a loop in a ll
bool detect(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            // To find the starting node of the loop:
            // slow = head;
            // while(slow != fast){
            //     slow = slow->next;
            //     fast = fast->next;
            // }
            // return slow; // This is the start of the loop

            return true;
        }
    }

    return false;
}

// palindrome linkedlist
bool isPalindrome(Node* head){
    if(!head || !head->next) return true;
    Node* slow = head; 
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;

    }
    Node* newhead = reverse(slow->next);
    Node* first = head;
    Node* second = newhead;
    while(second){
        if(first->data!=second->data) {
            slow->next = reverse(newhead);
        
            slow = head;
            return false;
        }
        first = first->next;
        second = second->next;


    }
    slow->next = reverse(newhead);
    return true;
}

// odd even linked list
Node* oddEvenList(Node* head){
    if(!head&&!head->next){
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* evenhead = head->next;
    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;

    }
    odd->next = evenhead;
    return head;
}


// delete the nth node from the end

//merge two sorted list
Node* meger(Node* head1, Node* head2){
    if(!head1 && !head2) return nullptr;
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(t1&&t2){
         if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
         }else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
         }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dummy->next;
} 



Node* findmiddle(Node * head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* merge2list(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(t1&&t2){
        if(t1->data<t2->data){
            temp->next = t1;
            t1 = t1->next;

        }else{
            temp->next =t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dummy->next;
}
Node* sortll(Node* head){
     if(!head || !head->next) return head;

     Node* middle = findmiddle(head);
     Node* left = head;
     Node* right = middle->next;
     middle->next = nullptr;

     left = sortll(left);
     right = sortll(right);
     return merge2list(left,right);
}



int main(){



    //       vector<int> arr = {1,2,3,4,5};
    //       vector<int> arr2 = {2,4,5,54};
    //       Node* head1 = convert(arr2);
    //       Node* head =   convert(arr);
    //       cout<< "the linked list is : "<< endl;
    //       print(head);
    //       print(head1);
    //     //   cout<<"after reversing the ll  is : "<<endl;
    //     //   head =   rreverse(head);
    //     // int a = isPalindrome(head);
    //     // if(a){
    //     //     cout<< " the list is palindrome";
    //     // }else{ 
    //     //     cout<<"the list is not palindrome";
    //     // }
    //     // cout<<endl;
    //     // cout<<" after odd even saperating "<<endl;
    //     // oddEvenList(head);
    //     // print(head);
        
    //     cout<<"after mergint linked list "<<endl;
    //   Node* head3 =  meger(head, head1);
    //   print(head3);
    
    //  vector<int> arr = {2,32,3,43,31,45,30,29,34};
    //  Node* head = convert(arr);
    //  print(head);
    //  cout<< "after sorting the ll  is : "<< endl;
    //  head =  sortll(head);
    //  print(head);

          
 return 0;
}