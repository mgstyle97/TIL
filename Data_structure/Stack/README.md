# 4. 스택

## 1. 스택이란?

- 스택 : 영어 사전에서 '(건초 밀집 따위를 쌓아놓은)더미 낟가리'를 의미한다고 되어 있다.

  - **LIFO(Last In First Out)** : 후입선출의 의미로 가장 나중에 들어온 것이 가장 먼저 나간다.

    ex) A, B, C, D 순서로 입력했다가 하나를 지우게 되면 D가 지워진다.

  - 스택에서의 입출력은 맨 위에서만 일어나고 스택의 중간에서는 데이터를 삭제할 수 없다.
  - 스택에서 입출력이 이루어지는 부분을 **스택 상단**이라 하고, 반대쪽인 바닥 부분을 **스택 하단**이라 한다.
  - 스택에 저장되는 것을 **요소**라 부르고, 스택에 요소가 하나도 없을 때 스택을 **공백 스택**이라 한다.
  - 스택을 구현하는 방법에는 배열과 연결 리스트가 있다.
    - 배열로 구현한 방법은 간단한 반면에 스택의 크기가 고정되는 약점이 있다.
    - 연결리스트로 구현하는 방법은 약간 복잡한 반면, 스택의 크기를 필요에 따라 가변적으로 변경할 수 있다.

## 2. 스택의 추상자료형(ADT)

```
추상자료형 Stack
create()	::= 스택을 생성한다.
is_empty(s)	::= 스택이 비어 있는지를 검사한다.
is_full(s)	::= 스택이 가득 찼는가를 검사한다.
push(s, e)	::= 스택의 맨 위에 요소 e를 추가한다.
pop(s)		::=	스택의 맨 위에 있는 요소를 삭제한다.
peek(s)		::= 스택의 맨 위에 있는 요소를 삭제하지 않고 반환한다.
```

- push 연산 : 삽입 연산이다.

![img](https://t1.daumcdn.net/cfile/tistory/231BC645595CFF401B)

- pop 연산 : 요소를 스택에서 완전히 삭제하면서 가져온다.

![img](https://t1.daumcdn.net/cfile/tistory/2423F445595CFF4122)

- is_empty와 is_full 연산 : 스택이 공백 상태에 있는지와 포화 상태에 있는지를 검사하는 함수이다.

- create 연산 : 스택을 생성한다.

- peek 연산 : 요소를 스택에서 삭제하지 않고 보기만 하는 연산이다.

  

## 3.1 배열로 구현한 스택

- 배열

  > - 스택 : stack[MAX_STACK_SIZE]
  >
  > - 가장 최근에 입력되 자료를 가리키는 변수 : top
  >
  >   ex) 가장 먼저 들어온 요소는 stack[0], 가장 최근에 들어온 요소는 stack[top]이다.
  >
  >   - top 변수는 스택에 아무런 데이터가 없으면 -1값을 갖는다. 대부분의 언어에서 첫 번째 요소의 인덱스가 0이기 때문이다.

- is_empty 연산

  ```c
  is_empty(S)			// S는 스택
  {
  	if top == -1	// 스택이 비어 있는지를 검사하기 위해 top을 -1과 비교한다.
  		return TRUE
      else
      	return FALSE
  }
  ```



- is_full 연산

  ```c
  is_full(S)			// S는 스택
  {
  	if top == (MAX_STACK_SIZE-1)	// 스택이 가득 차 있는지를 검사하기 위해
          return TRUE;				// MAX_STACK_SIZE-1과 top을 비교한다.
      else							// MAX_STACK_SIZE-1과 비교하는 이유는 배열의
      	return FALSE;				// 인덱스가 0부터 시작하기 때문이다.
  }
  ```

  

- push 연산

  ```c
  push(S, x)			// S는 스택, x는 들어갈 요소
  {
  	if(is_full(S)){					// 스택이 가득 차 있는지를 검사한다.
  		fprintf(stderr, "oveflow");	// 스택이 가득 차 있으면 에러 메시지를 출력한다.
      	return;
      }
      else{
          stack[++top] = x;			// 가득 차 있지 않으면 top을 하나 늘리고
      	return;						// 배열에 top 인덱스에 요소를 삽입안다.
      }
  }
  ```



- pop 연산

  ```c
  pop(S)				// S는 스택
  {
      if(is_empty(S)){
          fprintf(stderr, "underflow");
          return;
      }
      else
          return stack[top--];
  }
  ```



## 3.2 동적 배열로 구현한 스택

- malloc으로 동적 할당을 해주며 기존의 크기보다 더 요소가 추가될 경우 realloc으로 크기를 재지정해 준다.

  ```c
  typedef struct {
      int *data;			// 배열의 역할을 할 포인터 변수
      int capacity;		// 현재 배열의 크기를 나타내주는 변수
      int top;			// 가장 최근의 들어온 변수의 인덱스
  }StackType;
  ```

  - 구조체를 통하여 스택을 구현한다.

  ```c
  void init_stack(StackType *s){				// 스택을 초기화 한다.
      s->top = -1;							
      s->capacity = 1;
      s->data = (int *)malloc(sizeof(int));	
    //s->data = (int *)malloc(s->capacity*sizeof(int))와 같다.
  }
  ```

  - 스택을 초기화 해주는 함수이다.

  ```c
  int is_full(StackType *s){
      return (s->top == s->capacity-1);		// 현재 용량과 최근의 들어온 요소의
  }											// 인덱스가 같으면 가득 차있는 상태이다.
  ```

  - 기존의 배열에서 MAX_STACK_SIZE가 아닌 현재 용량과 비교하여 가득 차 있는지를 확인한다.

  ```c
  void push(StackType *s, int data){
      if(is_full(s)){
          s->capacity *= 2;
          s->data = (int *)realloc(s->data, s->capacity* sizeof(int));
      }	// is_full 연산을 사용하여 상태를 확인하고 true이면 크기를 2배로 늘린다.
      
      s->data[++(s->top)] = data;
  }
  ```

  - 배열처럼 크기가 정해진 것이 아닌 realloc을 통해 크기를 재지정 함으로써 배열의 단점인 크기가 제한된 것을 없앨 수 있다.
  - 나머지 연산들은 기존의 연산과 동일하다.

## 4. 연결리스트로 구현한 스택

- linked stack : 연결리스트로 구현한 스택이다.

  - 외부에서 보기에는 배열로 구현한 스택과 인터페이스가 동일하다.
  - 배열로 구현한 것과 달리 크기가 제한되지 않는다.
  - 동적 메모리 할당만 할 수만 있으면 스택에 새로운 요소를 삽입할 수 있다.
  - 동적 메모리 할당을 해제를 해야 하므로 삽입이나 삭제 시간은 좀 더 걸린다.
  - top은 노드를 가리키는 포인터로 선언된다.

  ```c
  typedef struct StackNode{	// 노드
      int item;
      struct StackNode *link;
  }StackNode;
  
  typedef struct{				// top
      StackNode *top;
  }LinkedStackType;
  ```

  