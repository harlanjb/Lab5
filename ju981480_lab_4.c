#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
  int length=0;
  while(head!=NULL){
  length++;
  head=head->next;
  }
return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
  int l = length(head); 
 char* string=malloc(sizeof(char)* (l+1)); 
  for(int i=0; i<l; i++){
   string[i] = head->letter;
   head = head->next;
 }
  string[l]='\0';
  return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
  node * newNode=malloc(sizeof(node));
  newNode->letter = c;
  newNode->next = NULL;
  if (!*pHead)
  {
    *pHead=newNode;
    return;
  }
  node * cur=*pHead;
  while (cur->next)
    {
    cur=cur->next;
    }
    cur->next=newNode;
  }

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {
  node* cur = *pHead;
  node* temp;

  while (cur != NULL) {
    temp = cur->next;
    free(cur);
    cur = temp;
  }
  *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}