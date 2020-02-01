# 7. 연결 리스트 2

## 7.1 원형 연결 리스트

### 원형 연결 리스트의 소개

- **원형 연결 리스트** : 마지막 노드가 첫 번째 노드를 가리키는 리스트이다.

  - 마지막 노드의 링크 필드가 NULL이 아니라 첫 번째 노드 주소가 되는 리스트이다.
  - **장점**
    - 원형 연결 리스트에서는 하나의 노드에서 다른 모든 노드로의 접근이 가능하다.
      - 하나의 노드에서 링크를 계속 따라 가면 결국 모든 노드를 지나 자기 자신으로 되돌아 올 수 있는 것이다.
      - 노드의 삽입과 삭제가 단순 연결 리스트보다는 용이해 진다는 것이다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/circular_linked_list.PNG">

  - 특히 유용한 경우는 리스트의 끝에 노드를 삽입하는 연산이 단순 연결 리스트보다 효율적일 수 있다는 것이다.
    - 단순 연결 리스트에서 리스트의 끝에 노드를 추가하려면 첫 번째 노드에서부터 링크를 따라서 노드의 개수만큼 진행하여 마지막 노드까지 가야한다.
    - 원형 연결 리스트에서 헤드 포인터가 마지막 노드를 가리키도록 구성한다면 상수 시간안에 리스트의 처음과 끝에 노드를 삽입할 수 있다.
    - 변현된 원형 연결 리스트에서 마지막 노드는 헤드 포인터인 head가 가리키고 있고, 첫 번째 노드는 head->link가 가리키고 있으므로, 리스트의 마지막에 노드를 삽입하거나 삭제하기 위하여 리스트의 맨 끝까지 힘들게 가지 않아도 된다.



### 원형 연결 리스트 정의

- 원형 연결 리스트도 원칙적으로 헤드 포인터만 있으면 된다.

  ```c
  ListNode *head;
  ```



### 원형 리스트의 처음에 삽입

- 새로운 노드의 링크인 node->link가 첫 번째 노드를 가리키게 하고 다음에 마지막 노드의 링크가 node를 가리키게 하면 된다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/insert_first().PNG">

  ```C
  ListNode* insert_first(ListNode *head, element data)
  {
      ListNode *node = (ListNode *)malloc(sizeof(ListNode));
      node->data = data;
      if(head == NULL){
  		head = node;
          node->link = head;
      }
      else{
          node->link = head->link;
          head->link = node;
      }
      return head;
  }
  ```



### 원형 리스트의 끝에 삽입

- 원형 연결 리스트는 원형으로 연결되어 있으므로 처음과 끝이 어딘지 불분명하다.

  - head의 위치만 새로운 노드로 바꾸어주면 새로운 노드가 마지막 노드가 된다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/insert_last().PNG">

  ```c
  ListNode* insert_last(ListNode *head, element data)
  {
      ListNode *node = (ListNode *)malloc(sizeof(ListNode));
      node->data = data;
      if(head == NUUL){
          head = node;
          node->link = head;
      }
      else{
          node->link = head->link;
          head->link = node;
          head = node;
      }
      return head;        
  }
  ```



## 7.2 원형 연결 리스트는 어디에 사용될까?

- 컴퓨터에서 여러 응용 프로그램을 하나의 CPU를 이용하여 실행할 때에 필요하다.

  - 현재 실행중인 모든 응용 프로그램은 원형 연결 리스트에 보관되며 운영 체제는 원형 연결 리스트에 있는 프로그램의 실행을 위해 고정된 시간 슬롯을 제공한다.
  - 운영 체제는 모든 응용 프로그램이 완료될 때가지 원형 연결 리스트를 계속 순회한다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/CPU.PNG">

- 멀티 플레이어 게임

  - 모든 플레이어는 원형 연결 리스트에 저장되며 한 플레이어의 기회가 끝나면 포인터를 앞으로 움직여서 다음 플레이어의 순서가 된다.

- 원형 연결 리스트는 원형 큐를 만드는데도 사용할 수 있다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/circular_queue.PNG">

### 멀티 플레이어 게임

## 7.3 이중 연결 리스트

- 단일 연결 리스트에서 임의의 노드의 후속 노드를 찾기는 쉽지만, 선행 노드를 찾으려면 구조상 아주 어렵다.

- 원형 연결 리스트라고 하더라도 거의 전체 노드를 거쳐서 돌아 와야 한다.

- 따라서 응용 프로그램에서 특정 노드에서 양방향으로 자유롭게 움직일 필요가 있다면 단순 연결 리스트 구조는 부적합하다.

- 이중 연결 리스트는 이러한 문제점을 해결하기 위하여 만들어진 자료구조이다.

- 이중 연결 리스트는 하나의 노드가 선행 노드와 후속 노드에 대한 두 개의 링크를 가지는 리스트이다.

  - 링크가 양방향이므로 양방향으로 검색이 가능해진다.
  - 단점으로는 공간을 많이 차지하고 코드가 복잡해진다는 것이다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/doubly_linked_list.PNG">

- 실제 응용에서는 이중 연결 리스트와 원형 연결 리스트를 혼합한 형태가 많이 사용된다.

  - 헤드 노드(head node)라는 특별한 노드를 추가하는 경우가 많다.
  - 헤드 포인터와는 구별해야 한다.
    - 헤드 포인터는 리스트의 첫 번째 노드를 가리키는 포인터이고, 헤드 노드는 데이터를 가지고 있지 않는 특별한 노드를 추가하는 것이다.
  - 헤드 노드가 존재하게 되면 삽입, 삭제 알고리즘이 간편해진다.

  - 헤드 노드의 데이터 필드는 아무런 정보도 담고 있지 않다. 다만 삽입과 삭제 알고리즘을 간편하게 하기 위하여 존재한다.

- 이중 연결 리스트에서의 노드는 3개의 왼쪽 링크 필드, 데이터 필드, 오른쪽 링크 필드로 이루어져 있다.

  -  링크 필드는 포인터로 이루어진다.
  -  노드의 왼쪽 링크 필드 llink는 선행 노드를, 오른쪽 링크 필드 rlink는 후속 노드를 가리킨다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/node.PNG">

  ```c
  typedef int element;
  typedef struct _DListNode{
      element data;
      struct _DListNode *rlink;
      struct _DListNode *llink;
  }DListNode;
  ```

- 이중 연결 리스트에서 임의의 노드를 가리키는 포인터를 p라 하면, 다음의 관계가 성립한다.

  ```c
  p = p->llink->rlink = p->rlink->llink
  ```

  - 즉 앞뒤로 똑같이 이동할 수 있음을 나타낸다.
    - 이러한 관계는 공백 리스트에도 성립한다. 

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/head_node.PNG">

  ```C
  void init(DListNode *phead)
  {
      phead->rlink = phead;
      phead->llink = phead;
  }
  ```



### 삽입 연산

- 순서에 따른 링크 필드의 값을 바꿔야 한다.

  - 새로 만들어진 노드의 링크를 먼저 바꾸는 데, 이는 새로 만들어진 노드의 링크는 아무런 정보도 가지고 있지 않기 때문에 변경하여도 안전하기 때문이다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/dinsert().PNG">

  ```c
  void dinsert(DListNode *before, element data)
  {
      DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
      newnode->data = data;
      newnode->llink = before;
      newnode->rlink = before->rlink;
      before->rlink->llink = newnode;
      before->rlink = newnode;
  }
  ```



### 삭제 연산

- 삭제 연산은 헤드 노드가 아니라면 선행 노드의 rlink는 삭제 노드의 rlink를 가리키고, 삭제 노드의 후속 노드의 llink가 선행 노드를 가리키면 된다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/ddelete().PNG">

  ```c
  void ddelete(DListNode *head, DListNode removed)
  {
      if(removed == head)
          return ;
      removed->llink->rlink = removed->rlink;
      removed->rlink->llink = removed->llink;
      free(removed);
  }
  ```



## 7.4 연결 리스트로 구현한 스택

- 스택은 연결 리스트를 이용해서도 구현될 수 있다.

  - 이러한 스택을 **연결된 스택(linked stack)**이라고 한다.
  - 외부에서 보기에는 배열을 이용한 것이나 연결 리스트를 이용한 것이나 전혀 차이가 없지만 달라지는 것은 스택의 내부구현이다.
    - 즉 제공되는 외부 인터페이스는 완전히 동일하다.

  - 연결 리스트로 구현한 스택은 크기가 제한되지 않는다.
    - 동적 메모리 할당만 할 수만 있으면 스택에 새로운 요소를 삽입할 수 있다.
  - 연결 리스트를 이용한 스택은 동적 메모리 할당이나 해제를 해야 하므로 삽입이나 삭제 시간은 좀 더 걸린다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/linked_stack.PNG">

  - 노드의 구조는 저장할 데이터 필드와 다음 노드를 가리키는 포인터인 링크 필드로 구성된다.
  - 스택에서 상단에 있는 요소를 가리키는 top은 더 이상 정수가 아니고 노드를 가리키는 포인터로 선언된다.
  - 연결된 스택에 관련된 데이터는  top 포인터 뿐이지만 일관성을 위하여 LinkedStackType이라는 구조체 타입으로 정의한다.
    - 모든 함수들은 이 구조체의 포인터를 매개 변수로 받아서 사용한다.

  ```c
  typedef int element;
  typedef struct _StackNode{
      element data;
      struct _StackNode *link;
  }StackNode;
  
  typedef struct{
      StackNode *top;
  }LinkedStackType;
  ```

  

### 연결된 스택의 삽입 연산

- 연결된 스택은 개념적으로 단순 연결 리스트에서 맨 앞에 데이터를 삽입하는 것과 동일하다.

  - 연결된 스택에서는 헤드 포인터가 top이라는 이름으로 불리는 것 이외에는 별 차이점이 없다.

- 삽입 연산에서는 먼저 동적 메모리 할당으로 노드를 만들고 이 노드를 첫 번째 노드로 삽입한다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/linked_stack_push().PNG">

  ```C
  void push(LinkedStackType *s, element item)
  {
      StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
      temp->data = item;
      temp->link = s->top;
      s->top = temp;
  }
  ```

  

### 연결된 스택의 삭제 연산

- top 포인터의 값을 top 포인터가 가리키는 노드로 변경한 다음 top이 원래 가리키고 있던 노드를 동적 메모리 해제를 하면된다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/linked_stack_pop().PNG">

  ```c
  element pop(LinkedStackType *s)
  {
      if(is_empty(s)){
          fprintf(stderr, "스택이 비어있음\n");
          exit(1);
      }
      else{
          StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
          element item;
          temp = s->top;
          item = temp->data;
          s->top = s->top->link;
          free(temp);
          return item;
  	}
  }
  ```



## 7.5 연결 리스트로 구현한 큐

- 큐도 연결 리스트를 이용하여 구현할 수 있다.

- 연결리스트로 만들어진 큐를 **연결된 큐(linked queue)**라고 한다.

  - 연결 리스트로 구현된 큐는 배열로 구현된 큐에 비하여 크기가 제한되지 않는다는 장점을 지니고 있다.
  - 반면 배열로 구현된 큐에 비하여 코드가 약간 더 복잡해지고, 링크 필드 때문에 메모리 공간을 더 많이 사용한다.
  - 기본적인 구조는 단순 연결 리스트에다가 2개의 포인터를 추가한 것과 같다.
    - front 포인터는 삭제와 관련되며, rear 포인터는 삽입과 관련된다.
    - front 포인터는 맨 앞에 있는 요소를 가리키며, rear 포인터는 맨 뒤에 있는 요소를 가리킨다.
    - 큐에 요소가 없는 경우에는 front와 rear는 NULL 값이 된다.
  - 큐의 요소들은 구조체로 정의되며 이 구조체는 데이터를 저장하는 data 필드와 다음 노드를 가리키기 위한 포인터가 들어 있는 link 필드로 이루어져 있다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/linked_queue.PNG">

  - 연결된 스택과 마찬가지로 연관된 데이터는 front와 rear이지만 일관성을 위해 LinkedQueueType이라는 구조체 타입으로 새로 정의한다.

  ```c
  typedef int element;
  typedef struct _QueueNode{
      element data;
      struct _QueueNode *link;
  }QueueNode;
  
  typedef struct{
      QueueNode *front, *rear;
  }LinkedQueueType;
  ```



### 연결된 큐의 삽입 연산

- 새로운 동적 메모리 할당을 통하여 새로운 노드를 생성한 다음, 데이터를 저장하고 연결 리스트의 끝에 새로운 노드를 추가하면 된다.

  - 큐가 공백상태일 때 새로운 데이터가 삽입이 된다면 front와 rear 모두 새로운 노드를 가리키도록 하면 된다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/linked_queue_insert_null.PNG">

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/linked_queue_enqueue().PNG">

  ```C
  void enqueue(LinkedQueueType *q, element item)
  {
      QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
      temp->data = item;
      temp->link = NULL;
      if(is_empty(q)){
          q->front = temp;
          q->rear = temp;
      }
      else{
          q->rear->link = temp;
          q->rear = temp;
      }
  }
  ```



### 연결된 큐의 삭제 연산

- 삭제 연산은 연결 리스트의 첫 번째 노드를 꺼내오면 된다.

  - front가 가리키는 노드를 삭제할 노드 포인터 변수가 가리키고 front는 front가 가리키던 노드가 가리키는 노드를 가리킨 후 삭제할 노드를 동적 메모리 해제를 하면된다.

  <img src="C:/Users/mgsty/OneDrive/Desktop/김민기/Data structure/7. 연결 리스트 2/linked_queue_dequeue().PNG">

  ```c
  element dequeue(LinkedQueueType *q)
  {
      QueueNode *temp = q->front;
      element data;
      if(is_empty(q)){
          fprintf(stderr, "스택이 비어있음\n");
          exit(1);
      }
      else{
          data = temp->data;
          q->front = temp->link;
          if(q->front == NULL)
              q->rear = NULL;
          free(temp);
          return data;
      }
      
  }
  ```