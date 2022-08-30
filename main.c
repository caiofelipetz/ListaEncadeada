// Caio Felipe Trindade Zehnder
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random_number;
int n = 200000;
int r = 1000000;

struct Node
{
    int data;
    struct Node* next;
};

static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);    
    *head_ref = new_node;
}
void printList(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    

void print_Middle(struct Node *head){
  
    struct Node *first_ptr = head;
    struct Node *second_ptr = head;
  
    if (head!=NULL)
    {
        //Para cada 2 passos do ponteiro2 , o ponteiro 1 da um passo,logo quando P2 chega
        //no fim da lista, P1 vai estar no meio
        while (second_ptr != NULL && second_ptr->next != NULL)
        {
            if (second_ptr->next->next == NULL){
              second_ptr = second_ptr->next->next;
            }
            else{
              second_ptr = second_ptr->next->next;
              first_ptr = first_ptr->next;
          }
        }
        printf("O elemento do meio da lista: %d\n", first_ptr->data);
    }
}
void deleteLinked(struct Node *head)
{
  struct Node *temp = head;

  temp=head;
  head= head->next;
  free(temp);
}    

int main() {
  struct Node* head = NULL;
  clock_t tic = clock();
  srand(time(NULL));                
    
  for (int i = 0; i < n; ++i) {     
        
        random_number = rand() % r + 1;
        push(&head, random_number);

    }
  
  clock_t toc = clock();
  printf("Tempo de geracao da lista:   %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC); 
  
  printf("Given linked list\n");
  //printList(head);
  clock_t tic2 = clock();
  reverse(&head);
  clock_t toc2 = clock();
  printf("Tempo de inversao da lista:   %f seconds\n", (double)(toc2 - tic2) / CLOCKS_PER_SEC); 
  printf("\nLista invertida: \n");
  //printList(head);  
  clock_t tic3 = clock();
  print_Middle(head);
  clock_t toc3 = clock();
  printf("Tempo de achar o valor do meio da lista:   %f seconds\n", (double)(toc3 - tic3) / CLOCKS_PER_SEC); 
  clock_t tic4 = clock();
  deleteLinked(head);
  clock_t toc4 = clock();
  printf("Tempo de apagar a lista:   %f seconds\n", (double)(toc4 - tic4) / CLOCKS_PER_SEC); 
  printf("Empty list \n");
  //printList(head);
}
