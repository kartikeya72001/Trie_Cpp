#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

class node{
public:
    node* left=NULL;//0
    node* right=NULL;//1
};
void insert(int n, node* head)
{
    node* cur = head;
    for(int i=31;i>=0;i--)
    {
        int bit = (n>>i)&1;
        if(bit == 0)
        {
            if(cur->left == NULL)
            {
                cur->left = new node;
            }
            cur = cur->left;
        }
        else
        {
            if(cur->right == NULL)
            {
                cur->right = new node;
            }
            cur = cur->right;
        }
    }
    return;
}

int MaxXorPair(node* head, int *arr, int n, int e)
{
    int max = INT_MIN;
    node *curr = head;
    int value = e;
    int currxor = 0;
    for(int i=31;i>=0;i--)
    {
        int b = (value>>i)&1;
        if(b==0)
        {
            if(curr->right != NULL)
            {
                curr = curr->right;
                currxor += int(pow(2,i));
            }
            else{
                curr = curr->left;
            }
        }
        else
        {
            if(curr->left != NULL)
            {
                curr = curr->left;
                currxor += int(pow(2,i));
            }
            else{
                curr = curr->right;
            }
        }
    }
    if(currxor>max)
        max = currxor;
    return max;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        int a = 0;
        if(i>0)
        {
            cin>>a;
            arr[i] = arr[i-1]^a;
        }
        else
            cin>>arr[i];
    }
    node *head = new node();
    int result = INT_MIN;
    for(int i=0;i<n;i++)
    {
        insert(arr[i],head);
        int x = MaxXorPair(head,arr,n,arr[i]);
        result = (result<x)?x:result;
    }
    cout<<result<<endl;
    return 0;
}
