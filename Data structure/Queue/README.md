# 5. 큐

## 5.1 큐 추상 데이터 타입

- 큐 : 먼저 들어온 데이터가 먼저 나가는 자료구조이다.

  - **FIFO(First In First Out)** : 선입선출로 큐의 중요한 특징이다.

    ex) 매표소에서 표를 사기 위해 줄을 서는 것, 가장 먼저 온 사람이 가장 먼저 표를 산다.

  - 큐는 뒤에서 새로운 데이터가 추가되고 앞에서 데이터가 하나씩 삭제되는 구조를 가지고 있다.

  - 스택과의 다른 점은 삽입과 삭제가 다른 쪽에서 일어난다는 것이다.

  ![자료구조 큐에 대한 이미지 검색결과](https://img1.daumcdn.net/thumb/R720x0.q80/?scode=mtistory2&fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F9929C0495C932BB1153D55)

  - 다음 그림과 같이 삽입이 일어나느 곳을 **후단(Rear)**이라고 하고 삭제가 일어나는 곳을 **전단(Front)**이라고 한다.

- 큐 추상 데이터 타입

  ```
  추상 자료형 Queue
  create()		::= 큐를 생성한다.
  init(q)			::= 큐를 초기화 한다. 
  is_empty(q)		::= 큐가 비어 있는지를 검사한다.
  is_full(q)		::= 큐가 가득 찼는가를 검사한다.
  enqueue(q, e)	::= 큐의 뒤에 요소를 추가한다.
  dequeue(q)		::=	큐의 앞에 있는 요소를 반환한 다음 삭제 한다.
  peek(q)			::= 큐에서 삭제하지 않고 앞에 있는 요소를 반환한다.
  ```

  - 추상 자료형 큐의 연산들은 추상 자료형 스택과 아주 유사하다.
  - is_empty()와 is_full() 연산들은 스택과 마찬가지로 비어있거나 가득 차 있으면 TRUE를 반환하고, 그렇지 않으면 FALSE를 반환한다.
  - 가장 중요한 삽입과 삭제 연산은 enqueue와 dequeue이다.
  - enqueue 연산은 큐에 연산을 추가하는 연산으로서 큐의 맨뒤에 새로운 요소를 추가한다.
  - dequeue 연산은 큐의 맨 앞에 있는 요소를 꺼내서 외부로 반환한다.
  - 스택에서는 삽입, 삭제와 관련하여 변수 1개만 존재하는 데 비해 큐에서는 두 개의 변수가 사용된다.
    - 삽입과 관련된 변수를 rear라고 한다.
    - 삭제와 관련된 변수를 front라고 한다.



## 5.2 배열로 구현한 큐

### 5.2-1 선형 큐(Linear Queue)

- 큐도 스택과 마찬가지로 구현하는 방법이 여러가지이나 가장 간단한 방법은 1차원 배열을 쓰는 방법이다.

  ![자료구조 선형큐에 대한 이미지 검색결과](http://www.tipssoft.com/data/cheditor4/1408/c9df1e0cbf27c9ac473a9a49bcafb16b_7rdg23Pw5ZQODRpVTbbiq.png)

  - 삽입 삭제를 위한 front와 rear를 만든다.

  ```c
  typedef struct{
      int queue[MAX_QUEUE_SIZE];
      int front, rear;
  }QueueType;
  ```

  - front와 rear의 초깃값은 -1이다. front는 첫번째 요소의 하나 앞을 가리키고 rear는 마지막 요소를 가리킨다.
    - 데이터가 증가하게 되면 rear가 하나 증가하고 그 위치에 데이터가 저장된다.
    - 삭제할 때는 front가 하나 증가하고 그 위치에 있던 데이터를 삭제한다.
    - 위와 같은 큐를 **선형 큐(linear queue)**라고 한다.
  - front와 rear의 값이 계속 증가만 하기 때문에 <span style="color:red">언젠가는 배열의 끝에 도달하게 되고 배열의 앞부분이 비어 있더라도 사용하지 못한다는</span> 점이다.



### 5.2-2 원형 큐(Circular Queue)

- 선형 큐의 문제는 배열을 선형으로 생각하지 말고 원형으로 생각하면 쉽게 해결할 수 있다.

  - 즉 front와 rear의 값이 MAX_QUEUE_SIZE-1에 도달하면 다음에 증가되는 값은 0이 되도록 하는 것이다. 배열이 원형으로 처음과 끝이 연결되어 있다고 생각하는 것이다. 이것을 **원형 큐(circular queue)**라고 한다.

  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSrDOOgLT0-TvIkAflLcSbZh_ddx33nzt0oG2gNj0zYB6vGuPP3fQ&amp;s" alt="자료구조 원형큐에 대한 이미지 검색결과" style="zoom:200%;" />

  - 원형 큐에서는 front와 rear의 개념이 약간 변경된다.
    - 초기값은 -1이 아닌 0이다.
    - front와 rear가 값이 같으면 원형 큐가 비어 있음을 나타낸다.
    - 원형 큐에서는 하나의 자리는 항상 비워둔다. 왜냐하면 포화 상태와 공백 상태를 구별하기 위해서이다.
    - front = rear이면 공백 상태가 되고 만약 front가 rear보다 하나 앞에 있으면 포화 상태가 된다.

  ![자료구조 원형큐 에러상태에 대한 이미지 검색결과](https://img1.daumcdn.net/thumb/R720x0.q80/?scode=mtistory2&fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F24454C3B537BFDF720A292)

  - 원형 큐의 구현에 있어서 중요한 것은 front와 rear를 원형으로 회전시켜야 한다는 것이다.

    - 이는 나머지 연산자를 이용하여 쉽게 구현할 수 있다.
    - **enqueue연산**

    ```c
    void enqueue(QueueType *q, element e){
        if(is_full(q)){
            fprintf(stderr, "큐 포화 에러\n");
            exit(1);
        }
        q->queue[++(q->rear)%MAX_QUEUE_SIZE] = e;
    }
    ```

    - **dequeue연산**

    ```c
    element dequeue(QueueType *q){
        if(is_empty(q)){
            fprintf(stderr, "큐 공백 에러\n");
            exit(1);
        }
        return q->queue[++(q->front)%MAX_QUEUE_SIZE];
    }
    ```



## 5.3 연결 리스트로 구현한 큐

- 스택을 연결 리스트를 이용하여 만들 수 있는 것처럼 큐도 연결 리스트를 이용하여 만들 수 있다.

  ![img](https://t1.daumcdn.net/cfile/tistory/991DD4455BBE19E218)

  - 연결 리스트로 만들어진 큐를 **연결된 큐(linked queue)**라고 한다.
  - 연결 리스트로 만들어진 큐는 크기가 제한되지 않는다.
  - 반면  배열로 구현한 큐에 비하여 코드가 약간 더 복잡해지고, 링크 필드 때문에 메모리 공간을 더 많이 사용한다.

  ```c
  typedef struct QueueNode{
      element data;
      struct QueueNode *link;
  }QueueNode;
  
  typedef struct{
      QueueNode *front, *rear;
  }QueueType;
  ```

  - 기본적인 구조는 단순 연결 리스트에다가 2개의 포인터를 추가한 것과 같다.
  - 큐의 요소들은 구조체로 정의되며 이 구조체는 데이터를 저장하는 data 필드와 다음 노드를 가리키기 위한 link 필드로 이루어져 있다.
  - front 포인터는 삭제와 관련되며 rear 포인터는 삽입과 관련된다.
  - front는 연결 리스트의 맨 앞에 있는 요소를 가리키며, rear 포인터는 맨 뒤에 있는 요소를 가리킨다.

  ```c
  void init_queue(QueueType *q){
      q->rear = q->front = NULL;
  }
  ```

  - 큐에 요소가 없는 경우에는 rear와 front는 NULL 값이 된다.

  - **enqueue연산**

  ```c
  void enqueue(QueueType *q, element e){
      QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
      if(temp == NULL){
          fprintf(stderr, "메모리 할당 에러\n");
          exit(1);
      }
      else{
          temp->data = e;
          temp->link = NULL;
          if(is_empty(q)){
              q->rear = temp;
              q->front = temp;
          }
          else{
              q->rear->link = temp;
              q->rear = temp;
          }
      }
  }
  ```

  - 삽입 연산은 먼저 동적 메모리 할당을 통하여 새로운 노드를 생성한 다음, 데이터를 저장하고 연결 리스트의 끝에 새로운 노드를 추가하면 된다.
    - 큐가 공백 상태이면(즉 front와 rear가 모두 NULL이면) front와 rear 모두 새로운 노드를 가리키도록 해야 한다.
    - 공백 상태가 아닌 기존의 노드가 있는 경우라면 rear가 가리키고 있는 노드의 링크 필드가 새로운 노드를 가리키게 하고, 다음에 rear가 이 새로운 노드를 가리키도록 변경하면 된다.
  - **dequeue연산**

  ```c
  element dequeue(QueueType *q){
      QueueNode *temp = q->front;
      element = item;
      if(is_empty(q)){
          fprintf(stderr, "큐 공백 에러\n");
          exit(1);
      }
      else{
          item = temp->data;
          q->front = temp->link;
          if(q->front == NULL)
              q->rear = NULL;
          free(temp);
          return item;
      }
  }
  ```

  - 삭제 연산은 연결 리스트의 처음에서 노드를 꺼내오면 된다.
    - 삭제 연산은 먼저 큐가 공백 상태인가를 검사하여야 한다.
    - 공백 상태가 아니라면 front가 가리키는 노드를 temp가 가리키도록 하고 front는 front의 링크 값으로 설정한다.
    - front는 이전에 가리키는 노드의 다음 노드를 가리키게 될 것이다.
    - temp가 가리키는 노드로부터 데이터를 꺼내오고 동적 메모리 해제를 통하여 이 노드를 삭제하면 된다.

  

## 5.4 덱

- **덱(deque)** : **double-ended queue**의 줄임말로서 큐의 전단(front)과 후단(rear)에서 모두 삽입과 삭제가 가능한 큐를 의미한다.

  ![자료구조 덱에 대한 이미지 검색결과](https://t1.daumcdn.net/cfile/tistory/2432283D5671366307)

  - 덱은 스택과 큐의 연산들을 모두 가지고 있다.
    - add_front와 delete_front 연산은 스택의 push와 pop 연산과 같다.
    - add_rear와 delete_front 연산은 큐의 enqueue와 dequeue 연산과 같다.
    - 추가로 덱은 get_front, get_rear, delete_rear를 가지고 있다.

### 덱 추상 데이터 타입

```
create				::= 덱을 생성한다.
init(dq)			::= 덱을 초기화한다.
is_empty(dq)		::= 덱이 공백 상태인지를 검사한다.
is_full(dq)			::= 덱이 포화 상태인지를 검사한다.
add_front(dq, e)	::= 덱의 앞에 요소를 추가한다.
add_rear(dq, e)		::= 덱의 뒤에 요소를 추가한다.
delete_front(dq)	::= 덱의 앞에 있는 요소를 반환한 다음 삭제한다.
delete_rear(dq)		::= 덱의 뒤에 있는 요소를 반환한 다음 삭제한다.
get_front(dq)		::= 덱의 앞에서 삭제하지 않고 앞에 있는 요소를 반환한다.
get_rear(dq)		::= 덱의 뒤에서 삭제하지 않고 뒤에 있는 요소를 반환한다.
```



### 덱의 구현

- 덱은 보통 이중 연결 리스트로 구현된다.

  - 전단과 후단에서 모두 삽입, 삭제가 가능해야하기 때문에 양쪽으로 링크를 가지고 있어야 편리하기 때문이다.

  ```c
  typedef struct DlistNode{
      element data;
      struct DlistNode *rlink;
      struct DlistNode *llink;
  }DlistNode;
  typedef struct DequeType{
      DlistNode *head, *tail;
  }DequeType;
  ```

  - 첫 번째 노드와 마지막 노드를 가리키는 포인터를 동시에 가지고 있어야 한다.
    - 덱과 관련된 변수는 첫 번쨰 노드를 가리키는 변수인 head와 마지막 노드를 가리키는 tail이 된다.
  - **삽입연산**

  ```c
  void add_rear(DequeType *dq, element e){
      DlistNode *new_node = create_node(dq->tail, e, NULL);
      if(is_empty(dq))
          dq->head = new_node;
      else
          dq->tail->rlink = new_node;
      dq->tail = new_node;
  }
  
  void add_front(DequeType *dq, element e){
      DlistNode *new_node = create_node(NULL, e, dq->head);
      if(is_empty(dq))
          dq->tail = new_node;
      else
          dq->head->llink = new_node;
      dq->head = new_node;
  }
  ```

  - **삭제연산**

  ```c
  element delete_rear(DequeType *dq){
      element item;
      DlistNode *removed_node;
      if(is_empty(dq)){
          fprintf(stderr, "덱 공백 에러\n");
          exit(1);
      }
      else{
          removed_node = dq->tail;
          item = removed_node->data;
          dq->tail = removed_node->llink;
          if(dq->tail == NULL)
              dq->head = NULL;
          else
              dq->tail->rlink = NULL;
      }
      return item;
  }
  
  element delete_front(DequeType *dq){
      element item;
      DlistNode *removed_node;
      if(is_empty(dq)){
          fprintf(stderr, "덱 공백 에러\n");
          exit(1);
      }
      else{
          removed_node = dq->head;
          item = removed_node->data;
          dq->head = removed_node->rlink;
          if(dq->head == NULL)
              dq->tail = NULL;
          else
              dq->head->llink = NULL;
      }
      return item;
  }
  ```

  