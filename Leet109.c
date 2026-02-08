/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #include <stdlib.h>
 #include <stdio.h>
 
   struct TreeNode* NewNode(int val) {
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

            node -> val = val;
            node -> left = NULL;
            node -> right = NULL;

            return node;
            
   }
   struct TreeNode* sortedListToBST(struct ListNode* head)
   {
        if (head == NULL)
        
            return NULL;
        
        if (head->next == NULL)
        
         return NewNode(head -> val);
        
        
            struct ListNode *pnt = NULL;
            struct ListNode *slow = head;
            struct ListNode *fast = head;

            while(fast != NULL && fast->next != NULL){
            pnt = slow;
           slow = slow->next;
           fast = fast->next->next;
            }
            pnt->next = NULL;

            struct TreeNode* Root = NewNode (slow -> val);
              Root ->left = sortedListToBST(head);
              Root -> right = sortedListToBST(slow -> next);
            return Root;

        }

    // pensar casos:
    // pensar como o ultimo leet de entrega o 143 -- percorrer a lista rapidamente e lentamente para achar o meio e o final
    // se tiver um nodo só?  retorna o unico valor que tem -- feito
    // se não tiver nada? retorna null -- feito
    // criar ponteiros para rapido e devagar, e um auxiliar (pnt ele corta a lista na metade) -- feito
    // percorer rapido e devagar -- feito
    // achar o mid --  feito (o lento vai achar o meio da lista encadeada e o pnt cortar a lista em duas)
    // o meio é a raiz
    // recursao para os lados direito e esquerdo da raiz -- feito
    // o lado esquerdo vou usar head;
    // o lado direito vou usar slow->next -- feito


