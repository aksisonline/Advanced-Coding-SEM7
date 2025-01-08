#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Creating Nodes
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Function to merge k sorted linked lists
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];
    
    int mid = listsSize / 2;
    struct ListNode* left = mergeKLists(lists, mid);
    struct ListNode* right = mergeKLists(lists + mid, listsSize - mid);
    
    return mergeTwoLists(left, right);
}

// Printing Function
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory of the linked list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int arr[][3] = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6, 0} // Add a zero to fill the last element
    };
    int sizes[] = {3, 3, 2}; // Specify the sizes of each array
    int k = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* lists[k];

    for (int i = 0; i < k; i++) {
        struct ListNode* head = NULL;
        struct ListNode* tail = NULL;
        for (int j = 0; j < sizes[i]; j++) {
            struct ListNode* newNode = createNode(arr[i][j]);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        lists[i] = head;
    }

    struct ListNode* result = mergeKLists(lists, k);

    printList(result);

    freeList(result);

    return 0;
}