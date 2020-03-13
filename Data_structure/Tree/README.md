# 8. 트리

## 8.1 트리의 개념

- **선형 자료 구조(linear data structure)** : 자료들이 선형으로 나열되어 있는 구조를 의미한다.

  <img src="./8. 트리/linear data structure.PNG">

- **트리(tree)** : 계층적인 자료를 표현하는데 적합한 자료구조이다.
  
  <img src="./8. 트리/example.PNG">
  
  - 이러한 구조를 트리라고 부르는 이유는 마치 실제 트리를 거꾸로 엎어놓은 것 같은 모양을 하고 있기 때문이다.
  - 또한 인공 지능 문제에서도 트리가 사용된다.
    - 대표적인 것이 **결정 트리(decision tree)**이다.
    - 결정 트리는 인간의 의사 결정 구조를 표현하는 한 가지 방법이다.
  
  <img src="./8. 트리/decision tree.PNG">

### 트리의 용어들

<img src="./8. 트리/structure of tree.PNG">

- 트리의 구성 요소에 해당하는 A, B, C, D, E, F, G, H, I, J를 노드(node)라 한다.

- 트리는 한 개 이상의 노드로 이루어진 유한 집합이다.

  - 이들 중 하나의 노드는 루트(root) 노드라 불리고 나머지 노드들은 서브 트리(subtree)라고 불린다.
    - 계층적인 구조에서 가장 높은 곳에 있는 노드가 루트가 된다.
    - 전체 노드 집합 {A, B, C, D, E, F, G, H, I, J} 중에서 루트 노드는 A이고 나머지 노드들은 {B, E, F, G}, {C, H}, {D, I, J}로 3개의 집합으로 나누어 지는데 이들을 A의 서브 트리라고 한다.
    - 다시 서브 트리인 {B, E, F, G}의 루트는 B가 되고 나머지 노드들은 다시 3개의 서브 트리, 즉 {E}, {F}, {G}로 나누어진다.
  - 트리에서 루트와 서브 트리는 선으로 연결된다. 이 연결선을 간선(edge)라고 한다.

- 노드들 간에는 부모 관계, 형제 관계, 조상과 자손 관계가 존재한다. 이들은 모두 인간의 관계와 동일하다.

  <img src="./8. 트리/relation of node.PNG">

  - A는 B의 **부모 노드(parent node)**가 된다.
  - 반대로 B는 A의 **자식 노드(children node)**가 된다.
  - B와 C와 D는 **형제 관계(sibling)**이다.
  - **조상 노드(ancestor node)**란 루트 노드에서 임의의 노드까지의 경로를 이루고 있는 노드들을 말한다.
  - **후손 노드(descendent node)**는 임의의 노드 하위에 연결된 모든 노드들을 의미한다. 즉 어떤 노드의 서브 트리에 속하는 모든 노드들은 후속 노드이다.
  - 자식 노드가 없는 노드를 **단말 노드(terminal node, 또는 leaf node)**라고 한다. 그 반대는 **비단말 노드(nonterminal node)**이다.

  <img src="./8. 트리/degree of node.PNG">

  - **노드의 차수(degree)**는 어떤 노드가 가지고 있는 자식 노드의 개수를 의미한다.
    - 루트 노드 A의 경우 자식 노드가 3개이기 때문에 차수도 3이 된다.
    - 단말 노드는 차수가 0인 노드이다.
  - 트리의 차수는 트리가 가지고 있는 노드의 차수 중에서 가장 큰 값이다.

  <img src="./8. 트리/level of tree.PNG">

  - 트리에서의 **레벨(level)**은 트리의 각 층에 번호를 매기는 것으로서 정의에 의하여 루트의 레벨은 1이 되고 한 층씩 내려갈수록 1씩 증가한다.
  - 트리의 **높이(height)**는 트리가 가지고 있는 최대 레벨을 말한다.
  - 트리들의 집합을 **포리스트(forest)**라고 한다.



### 트리의 종류

- 트리를 컴퓨터 메모리상에서 표현하는 방법은 여러가지가 있을 수 있다.

  - 트리를 프로그램 안에서 표현하는 가장 일반적인 방법은 각 노드가 데이터를 저장하는 데이터 필드와 자식 노드를 가리키는 링크 필드를 가지게 하는 것이다.
  - 일반적인 트리에서 각 노드들은 서로 다른 개수의 자식 노드를 가지므로 노드에 따라서 링크 필드의 개수가 달라진다.
  - 이 방법의 문제점은 <span style="color:red">노드의 크기가 고정되지 않는다는 것이다.</span> 즉 노드에 붙어 있는 자식노드의 개수에 따라서 노드의 크기가 커지기도 하고 작아지기도 한다,
  - 노드의 크기가 일정하지 않으면 프로그램이 복잡하게 된다.

  <img src="./8. 트리/normal tree.PNG">

  - **이진 트리** : 자식 노드의 개수가 2개인 트리

  <img src="./8. 트리/binary tree.PNG">

## 8.2 이진 트리 소개

### 이진 트리의 정의

- 트리 중에 가장 많이 쓰이는 트리가 이진트리이다.

- **이진 트리(binary tree)** : 모든 노드가 2개의 서브 트리를 가지고 있는 트리

  - 서브 트리는 공집합일 수 있다.
  - 이진 트리의 노드에는  최대 2개까지의 자식 노드가 존재할 수 있고 모든 노드의 차수가 2 이하가 된다.
  - 공집합도 이진 트리라는 점을 주의해야 한다.
  - 이진 트리에는 서브 트리간의 순서가 존재한다. 따라서 왼쪽 서브 트리와 오른쪽 서브 트리는 서로 구별된다.

  <img src="./8. 트리/difinition of binary tree.PNG">

- **이진 트리의 정의**

  > - 공집합
  > - 루트와 왼쪽 서브 트리, 오른쪽 서브 트리로 구성된 노드들의 유한 집합으로 정의된다. 
  > - 이진 트리의 서브 트리들은 모두 이진 트리여야 한다.

<img src="./8. 트리/subtree.PNG">

```
- SUB3은 하나의 노드 D로만 이루어져 있지만 서브 트리가 공집합이기 때문에 이진 트리이다.
- SUB2는 SUB3과 마찬가지로 서브 트리가 공집합이기 때문에 이진 트리이다.
- SUB1은 SUB3와 공집합으로 서브 트리가 이루어져 있기 때문에 이진 트리이다.
```

- 이진 트리의 모든 노드는 차수가 2 이하이다. 즉 자식 노드의 개수가 2 이하이다. 반면 일반 트리는 자식 노드의 개수에 제한이 없다.

- 일반 트리와는 달리 이진 트리는 노드를 하나도 갖지 않을 수도 있다.

- 서브 트리간에 순서가 존재한다는 점도 다른 점이다. 따라서 왼쪽 서브 트리와 오른쪽 서브 트리를 구별한다.

  <img src="./8. 트리/example of binary.PNG">

  - 이진 트리의 예로서 수식에서 각 연산자들은 하나 또는 2개의 피연산자를 가지고 있다.
    - 왼쪽 피연산자는 왼쪽 서브 트리가 되고 오른족 피연산자는 오른쪽 서브 트리로 표현된다.



### 이진트리의 성질

- n개의 노드를 가진 이진 트리는 정확하게 n-1의 간선을 가진다.

  - 이진 트리에서의 노드는 루트를 제외하면 정확하게 하나의 부모 노드를 가진다. 부모와 자식 간에는 정확하게 하나의 간선만이 존재한다.

  <img src="./8. 트리/number of edge.PNG">

  - 높이가 h인 이진 트리의 경우, 최소 h개의 노드를 가지며 최대 2<sup>h</sup>-1 개의 노드를 가진다.

    - 적어도 하나의 노드는 존재해야 하므로 높이가 h인 이진 트리는 적어도 h개의 노드를 가진다.

    - 하나의 노드는 최대 2개의 자식을 가질 수 있으므로 레벨 i에서의 노드의 최대 개수는 2<sup>i-1</sup>이 된다. 따라서 전체 노드 개수는 아래와 같은 수식이 된다.
      
      <img src="https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D1%7D%5Eh%202%5E%7Bi-1%7D%20%3D%202%5Eh-1">
  
<img src="./8. 트리/max_min_node.PNG">
  
- n개의 노드를 가지는 이진 트리의 높이는 최대 n이거나 최소 log<sub>2</sub>(n+1)이 된다.
    - 한 레벨 당 최소한 하나의 노드는 있어야 하므로 높이가 n을 넘을 수는 없다.
    - 높이 h의 이진 트리가 가질 수 있는 노드의 최대값은 2<sup>h</sup>-1이다. 따라서 n은 2<sup>h</sup>-1보다 작거나 같은 부등식이 성립하고 양변에 log를 취하여 정리하면 h는 log<sub>2</sub>(n+1)보다 크거나 같은 부등식이 된다.
    - h는 정수이어야 하므로 최소값은 log<sub>2</sub>(n+1)의 절댓값이 된다. 2.4는 올립 연산으로 3이 된다.
  
<img src="./8. 트리/max_min_height.PNG">



### 이진 트리의 분류

- 이진 트리는 다음과 같이 형태에 따라 분류할 수 있다.

  - **포화 이진 트리(full binary tree)** : 용어 그대로 트리의 각 레벨에 노드가 꽉 차있는 이진 트리를 의미한다.

    - 높이 k인 포화 이진 트리는 정확하게 2<sup>k</sup>-1개의 노드를 가진다.

    <img src="./8. 트리/full_number.PNG">

    - 포화 이진 트리에는 각 노드에 번호를 붙일 수 있다.
      - 노드에 번호를 부여하는 방법은 레벨 단위로 왼쪽에서 오른족으로 번호를 붙이면 된다.

    <img src="./8. 트리/full_tag.PNG">

  - **완전 이진 트리(complete binary tree)** : 높이가 k일 때 레벨 1부터 k-1까지는 노드가 모두 채워져 있고 마지막 레벨 k에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진 트리이다.

    - 마지막 레벨에서는 노드가 꽉차있지 않아도 되지만 중간에 빈곳이 있어서는 안된다.
    - 포화 이진 트리는 항상 완전 이진 트리이지만 그 역은 매번 성립하지는 않는다.
    - 포화 이진 트리의 노드 번호와 완전 이진 트리의 노드 번호는 1대 1로 대응한다.

    <img src="./8. 트리/example_complete.PNG">




## 8.3 이진 트리의 표현

- 이진 트리를 컴퓨터 프로그램 안에서 표현할 수 있는 방법
  - 배열을 이용하는 방법
  - 포인터를 이용하는 방법



### 배열 표현법

- **배열 표현법** : 주로 포화 이진 트리나 완전 이진 트리의 경우 많이 쓰이는 방법이다.

  - 이진 트리의 깊이가 k이면, 최대 2<sup>k</sup>-1개의 공간을 할당한 다음, 완전 이진 트리의 번호대로 노드들을 저장한다.
    - 여기서 인덱스 0은 사용되지 않는다.
    - 완전 이진 트리가 아닌 일반적인 이진 트리인 경우 배열 표현법을 사용하면 저장할 수는 있지만 기억공간의 낭비가 심해진다.

  <img src="./8. 트리/array representation.PNG">

  - 부모 노드와 자식 노드 간의 인덱스 관계

  ```
  - 노드 i의 부모 노드 인덱스 = i/2
  - 노드 i의 왼쪽 자식 인덱스 = 2i
  - 노드 i의 오른쪽 자식 인덱스 = 2i + 1
  ```



### 링크 표현법

- **링크 표현법** : 트리에서의 노드가 구조체로 표현되고, 각 노드가 포인터를 가지고 있어서 포인터를 이용하여 노드와 노드를 연결하는 방법이다.

  - 이진 트리를 링크 표현법으로 표현하면 하나의 노드가 3개의 필드를 가지는데, 데이터를 저장하는 필드, 왼쪽 자식 노드와 오른쪽 자식 노드를 가리키는 2개의 표인터 필드를 가진다.
  - 2개의 포인터를 이용하여 부모 노드와 자식 노드를 연결한다.

  <img src="./8. 트리/link node structure.PNG">

  <img src="./8. 트리/link representation.PNG">

  - 이진 트리를 링크 표현에 의해 나타내기 위해서는 구초제와 포인터 개념을 이용하여야 한다.
    - 구조체를 이용하여 노드의 구조를 정의하고 링크는 포인터의 개념을 이용하여 정의하면 된다.

  ```c
  typedef struct _TreeNode{
      int data;
      struct _TreeNode *left, *right;
  }TreeNode;
  ```

  -  링크법으로 표현된 트리는 루트 노드를 가리키는 포인터만 있으면 트리안의 모든 노드들에 접근할 수 있다.
    - 이것은 연결 리스트와 아주 유사하다. 연결 리스트 또한 포인터에 의해 연결된 구조이기 때문이다.
    - 연결 리스트는 1차원적인 연결된 구조라면 링크법으로 표현된 이진 트리는 2차원적으로 연결된 구조라 할 수 있다.



## 8.4 이진 트리의 순회

- 기본적으로  이진 트리도 데이터를 저장하기 위한 자료구조이다.

  - 데이터는 노드의 데이터 필드를 이용하여 저장된다.

- **이진 트리의 순회(traversal)** : 이진 트리에 속하는 모든 노드를 한 번씩 방문하여 노드가 가지고 있는 데이터를 목적에 맞게 처리하는 것을 의미한다.

  - 트리를 사용하는 목적은 트리의 노드에 자료를 저장하고 필요에 따라서 이 자료를 처리하기 위함이다.
  - 따라서 트리가 가지고 있는 자료를 순차적으로 순회하는 것은 이진 트리에서 중요한 연산이다.

  <img src="./8. 트리/traversal.PNG">

### 이진 트리 순회방법

- 이진 트리를 순회하는 표준적인 방법에는 전위, 중위, 후위의 3가지 방법이 있다.

  - 이는 루트와 왼쪽 서브 트리, 오른쪽 서브 트리 중에서 루트를 언제 방문하느냐에 따라 구분된다.
  - 루트를 서브 트리에 앞서서 먼저 방문하면 전위순회, 루트를 왼쪽 서브 트리와 오른쪽 서브 트리 중간에 방문하면 중위순회, 루트를 서브 트리 방문 후에 방문하면 후위순회가 된다.

  ```
  - 전위순회(preorder traversal)	: VLR
  - 중위순회(inorder traversal)	: LVR
  - 후위순회(postorder traversal)	: LRV
  ```

  - 이진 트리에서 각각의 서브 트리도 이진 트리이다.
    - 서브 트리에게도 전체 이진 트리와 똑같은 방법을 적용할 수 있다.
    - 즉 전위 순회라면 서브 트리에 들어 있는 노드들도 VLR의 순서대로 순회된다.
  - 트리 순회 알고리즘은 순환 기법을 사용한다.
    - 이진 트리에서 전체 트리나 서브 트리나 그 구조는 완전히 동일하다.
    - 따라서 전체 트리 순회에 사용된 알고리즘은 똑같이 서브 트리에 적용할 수 있을 것이다.



### 전위 순회

- **전위 순회** : 루트를 먼저 방문하고 그 다음에 왼쪽 서브 트리를 방문하고 오른쪽 서브 트리를 방문하는 순회 방법이다.

  <img src="./8. 트리/structure pre.PNG">

  ```
  1. 루트 노드를 방문한다.
  2. 왼쪽 서브 트리를 방문한다.
  3. 오른쪽 서브 트리를 방문한다.
  ```

  - **전위 순회 알고리즘 유사 코드**

  ```
  preorder(x):
  
  1.	if x!=NULL						// 노드 x가 NULL이면 더 이상 순환 호출을 하지 않는다.
  2.		then	print DATA(x);		// x의 데이터를 출력한다.	
  3.				preorder(LEFT(x));	// x의 왼쪽 서브 트리를 순환 호출하여 방문한다.
  4.				preorder(RIGHT(x));	// x의 오른쪽 서브 트리를 순환 호출하여 방문한다.
  ```

  > 전위 순회에서 루트 노드의 방문을 마친 후
  >
  > 왼쪽 서브 트리를 방문한다. 그리고 왼쪽 서브 트리 또한 하나의 이진 트리이다. 그렇기 때문에 왼쪽 서브 트리의 루트 노드를 방문한다.
  >
  > 따라서 전체 트리와 똑같은 방식으로 서브 트리를 방문하면 된다.

  <img src="./8. 트리/pre subtree.PNG">

  <img src="./8. 트리/preorder.PNG">



### 중위 순회

- **중위 순회** : 먼저 왼쪽 서브 트리를 방문하고, 루트, 오른쪽 서브 트리를 방문하는 순회 방법이다.

  <img src="./8. 트리/structure in.PNG">

  ```
  1. 왼쪽 서브 트리를 방문한다.
  2. 루트 노드를 방문한다.
  3. 오른쪽 서브 트리를 방문한다.
  ```

  - **중위 순회 알고리즘 유사코드**

  ```
  inorder(x):
  
  1.	if x!=NULL						// 노드 x가 NULL이면 더 이상 순환 호출을 하지 않는다.
  2.		then	inorder(LEFT(x));	// x의 왼쪽 서브 트리를 순환 호출하여 방문한다.
  3.				print DATA(x);		// x의 데이터를 출력한다.
  4.				inorder(RIGHT(x));	// x의 오른쪽 서브 트리를 순환 호출하여 방문한다.
  ```

  <img src="./8. 트리/inorder.PNG">



### 후위 순회

- **후위 순회** : 왼쪽 서브 트리를 먼저 방문한 후 오른쪽 서브 트리, 루트 순으로 방문하는 순회 방법이다.

  <img src="./8. 트리/structure post.PNG">

  ```
  1. 왼쪽 서브 트리의 모든 노드를 방문한다.
  2. 오른쪽 서브 트리의 모든 노드를 방문한다.
  3. 루트 노드를 방문한다.
  ```

  - **후위 순회 알고리즘 유사코드**

  ```
  postorder(x):
  
  1.	if x!=NULL						// 노드 x가 NULL이면 더 이상 순환 호출을 하지 않는다.
  2.		then	postorder(LEFT(x));	// x의 왼쪽 서브 트리를 순환 호출하여 방문한다.
  3.				postorder(RIGHT(x));// x의 오른쪽 서브 트리를 순환 호출하여 방문한다.	
  4.				print DATA(x);		// x의 데이터를 출력한다.
  ```

  <img src="./8. 트리/postorder.PNG">

### 전위, 중위, 후위 순회 구현

- 함수의 매개변수는 루트를 가리키는 포인터가 된다.

- 표준적인 순회방법이 순환적으로 정의되어 있다는 것에 착안하여야 한다.

  - 왼쪽이나 오른쪽 서브 트리를 방문하는 것은, 전체 트리를 방문하는 거나 다를 바가 없다.
    - 전체 트리를 방문한 함수를 다시 한 번 호출해주면 되는 것이다.
  - 다른 점은 함수의 매개변수가 달라지게 된다.
    - 서브 트리를 방문하는 경우에는 서브 트리의 루트 노드 포인터를 함수의 매개변수로 전달하면 된다.

  ```c
  // 중위 순회
  void inorder(TreeNode *root)
  {
      if(root != NULL){
          inorder(root->left);			// 왼쪽 서브 트리 순회
          printf("[%d]", root->data);		// 노드 방문
          inorder(root->right);			// 오른쪽 서브 트리 순회
      }
  }
  // 전위 순회
  void preorder(TreeNode *root)
  {
      if(root != NULL){
          printf("[%d]", root->data);		// 노드 방문
          preorder(root->left);			// 왼쪽 서브 트리 순회
          preorder(root->right);			// 오른쪽 서브 트리 순회
      }
  }
  // 후위 순회
  void postorder(TreeNode *root)
  {
      if(root != NULL){
          postorder(root->left);			// 왼쪽 서브 트리 순회
          postorder(root->right);			// 오른쪽 서브 트리 순회
          printf("[%d]", root->data);		// 노드 방문
      }
  }
  ```

### 전체 프로그램

[Tree_traversal](https://github.com/mgstyle97/TIL/blob/master/Data_structure/Tree/src/tree_traversal.c)

## 8.5 반복적 순회

- 반복을 이용한 순회에서는 스택을 사용하면 구현할 수 있다.
  - 순환 호출도 사실은 시스템 스텍을 사용하고 있는 것이기 때문에 별도의 스택을 사용하면 순환 호출을 흉내 낼 수 있는 것이다.
  - 실제로 이 방법은 인공지능에서 지능적인 탐색을 할 때 사용된다.

[Recursive_traversal](https://github.com/mgstyle97/TIL/blob/master/Data_structure/Tree/src/recursive_traversal.c)

## 8.6 레벨 순회

- **레벨 순회(level traversal)** : 각 노드를 레벨 순으로 검사하는 순회 방법이다.

  - 루트 노드의 레벨이 1이고 아래로 내려갈수록 레벨은 증가한다.
  - 동일한 레벨의 경우에는 좌에서 우로 방문한다.
  - 지금까지의 순회법이 스택을 사용했던 것에 비해, 레벨 순회는 큐를 사용하는 순회법이다.

  <img src="./8. 트리/level traversal.PNG">

  - 레벨 순회 코드는 큐에 하나라도 노드가 있으면 계속 반복하는 코드로 이루어져 있다.
    - 큐에 있는 노드를 꺼내어 방문한 다음, 그 노드의 자식 노드를 큐에 삽입하는 것으로 한번의 반복을 끝낸다. 이러한 반복을 큐에 더 이상의 노드가 없을 때까지 계속한다.

  ```
  level_order(root):
  1. initialize queue;
  2. if(root == null) then return;
  3. enqueue(queue, root);
  4. while is_empty(queue) != TRUE do
  5.     x <- dequeue(queue);
  6.     print x-> data;
  7.     if(x->left != NULL) then
  8.         enqueue(queue, x->left);
  9.     if(x->right != NULL) then
  10.        enqueue(queue, x->right);
  ```

[Level_traversal](https://github.com/mgstyle97/TIL/blob/master/Data_structure/Tree/src/level_order.c)

### 어떤 순회를 선택하여야 할까?

- 순서는 중요치 않고 노드를 전부 방문하게 된다면 3가지의 방법 중에 어느 것을 사용하여도 된다.
  - 자식 노드를 처리한 다음에 부모 노드를 처리해야 한다면 후위순회를 사용하여야 하고, 부모 노드를 처리한 다음에 자식 노드를 처리해야 한다면 전위순회를 사용하여야 한다.



## 8.7 트리의 응용: 수식 트리 처리

- 이진 트리는 수식 트리(expression tree)를 처리하는데 사용될 수 있다.

- 수식 트리는 산술 연산 자와 피연산자로 만들어 진다.

  - 피연산자들은 단말노드가 되며 연산자는 비단말 노드가 된다.

  <img src="./8. 트리/expression traversal.PNG">

  - 이 수식 트리들을 전위, 중위, 후위의 순회 방법으로 읽으면 각각 전위 표기 수식, 중위 표기 수식, 후위 표기 수식이 된다.

  |   수식   | a+b  | a-(b * c) | (a<b) or (c<d) |
  | :------: | :--: | :-------: | :------------: |
  | 전위순회 | +ab  |   -a*bc   |  or < ab < cd  |
  | 중위순회 | a+b  |  a-(b*c)  | (a<b) or (c<d) |
  | 후위순회 | ab+  |   abc*-   |    ab<cd<or    |

  - 수식 트리의 루트 노드는 연산자이고 따라서 이 연산자의 피연산자인 자식 노드들만 계산되면 전체 수식을 계산할 수 있다.
    - 루트보다 자식 노드들이 먼저 방문되는 순회 방법을 사용하여야 수식의 값을 계산할 수 있다.
    - 루트 노드보다 자식 노드를 먼저 방문하는 순회 방법은 후위 순회이다.

  <img src="./8. 트리/post expression.PNG">

  - **수식 트리의 계산 알고리즘 유사코드**

  ```
  evaluate(exp):
  
  1. if exp == NULL // 만약 수식 트리가 공백 상태이면
  2.     then return 0; // 그냥 복귀한다.
  3.     else x<-evaluate(exp.left); // 왼쪽 서브 트리를 계산하기 위해 evaluate(left)를 호출
  4.          x<-evaluate(exp.right);// 같은 방식으로 evaluate(right)를 계산한다.
  5.          op<-exp.data; // 루트 노드의 데이터 필드에서 연산자를 추출한다.
  6.          return (x op y); // 추출된 연산자를 가지고 연산을 수행해서 반복한다.
  ```

[Traversal_expression](https://github.com/mgstyle97/TIL/blob/master/Data_structure/Tree/src/traversal_expression.c)

## 8.8 트리의 응용: 디렉토리 용량 계산

- 이진 트리 순회는 컴퓨터 디렉토리의 용량을 계산하는데도 사용될 수 있다.

  - 단, 이진 트리를 사용하기 때문에 하나의 디렉토리 안에 다른 디렉토리가 2개를 초과하면 안된다.

  <img src="./8. 트리/directory size.PNG">

  - 하나의 디렉토리 안에 다른 디렉토리가 있을 수 있으므로 먼저 서브 디렉토리의 용량을 모두 계산한 다음에 루트 디렉토리의 용량을 계산하여야 할 것이다.
    - 따라서 후위 순회를 사용하여야 한다.
    - 후위 순회를 사용하되 순환 호출되는 순회 함수가 용량을 반환하도록 만들어야 한다.

[Directory_size](https://github.com/mgstyle97/TIL/blob/master/Data_structure/Tree/src/directory_size.c)

## 8.9 이진 트리의 추가 연산

### 노드의 개수

- 탐색 트리안의 노드의 개수를 세어 표시한다.

  - 노드의 개수를 세기 위해서는 트리안의 노드들을 전체적으로 순회하여야 한다.
  - 각각의 서브 트리에 대하여 순환 호출한 다음, 반환되는 값에 1을 더하여 반환하면 된다.
  - **노드 개수 알고리즘 유사코드**

  ```
  get_node_count(x):
  
  if x != NULL then
  	return 1 + get_node_count(x.left) + get_node_count(x.right);
  ```

  ```c
  int get_node_count(TreeNode *node)
  {
      int count = 0;
      
      if(node != NULL){
          count = 1 + get_node_count(node->left) + get_node_count(node->right);
      }
      
      return count;
  }
  ```



### 단말 노드의 개수 구하기

- 단말 노드의 개수를 세기 위해서는 트리안의 노드들을 전체적으로 순회하여야 한다.

  - 순회하면서 만약 왼쪽 자식과 오른쪽 자식이 동시에 0이 되면 단말 노드이므로 1을 반환한다.
  - 그렇지 않으면 비단말 노드이므로 각각의 서브 트리에 대하여 순환 호출한 다음, 반환되는 값을 서로 더하면 된다.
  - **단말 노드 개수 구하는 알고리즘 유사코드**

  ```
  get_leaf_count(T):
  
  if T != NULL then
  	if T.left == NULL and T.right == NULL
  		then return 1;
  		else return get_leaf_count(T.left) + get_leaf_count(T.right);
  ```

  ```c
  int get_leaf_count(TreeNode *node)
  {
      int count = 0;
      
      if(node != NULL){
          if(node->left == NULL && node->right == NULL)
              return 1;
          else
          	count = get_leaf_count(node->left) + get_leaf_count(node->right);
      }
      return count;
  }
  ```



### 높이 구하기

- 트리의 높이를 구하는 알고리즘이 가장 까다롭다.

  - 각 서브 트리에 대하여 순환 호출을 하여야 한다.
  - 순환 호출을 하여 밥법은 값을 더하는 것이 아닌 반환된 값들 중에 가장 최대인 값을 구하여 반환하여야 한다.

  <img src="./8. 트리/tree height.PNG">

  - **트리의 높이 구하는 알고리즘 유사코드**

  ```
  get_height(T):
  
  if T != NULL
  	return 1 + max(get_height(T.left) + get_height(T.right));
  ```

  ```c
  int get_height(TreeNode *node)
  {
      int height = 0;
      if(node != NULL)
          height = 1 + max(get_height(node->left), get_height(node->right));
      return height;
  }
  ```



## 8.10 스레드 이진 트리

- 이진 트리 순회는 순환 호출을 사용한다.

  - 순환 호출은 함수를 호출해야 하므로 상당히 비효율적일 수가 있다.
  - 이진 트리 순회도 노드의 개수가 많아지고 트리의 높이가 커지게 되면 상당히 비효율적일 수가 있다.

- 트리의 노드 개수가 n개이면 링크의 총 개수는 2n개 이다.

  - 노드와 노드를 연결시키는 링크는 n-1개 이며, 나머지 n+1개의 링크는 NULL이다.
  - NULL 링크에 중위 순회 시에 선행 노드인 중위 선행자(inoerder predecessor)나 중위 순회시에 후속 노드인 중위 후속자(inorder successor)를 저장시켜 놓은 트리가 **스레드 이진 트리(thread binary tree)**이다.
  - 스레드(thread), 즉 실을 이용하여 노드들은 순회 순서대로 연결시켜 놓은 트리이다.
  - NULL 링크에 스레드가 저장되면 링크에 자식을 가리키는 포인터가 저장되어 있는지 아니면 NULL이 저장되어 있는지를 구별해주는 태그 필드가 필요하다.

  ```c
  typedef struct _TreeNode{
      int data;
      struct _TreeNode *left, *right;
      int is_thread;	// 만약 오른쪽 링크가 스레드이면 TRUE
  }TreeNode;
  ```

  - is_thread가 true이면 right는 중위 후속자이고, is_thread가 false이면 오른쪽 자식을 가리키는 포인터가 된다.
    - is_thread가 true로 되어 있으면 바로 오른쪽 자식이 중위 후속자가 되므로 오른쪽 자식을 반환한다.
    - 오른쪽 자식이 NULL이면 더 이상 후속자가 없다는 것이므로 NULL을 반환한다.
    - is_thread가 false이면 서브 트리의 가장 왼쪽 노드로 가야한다.

  ```c
  TreeNode* find_successor(TreeNode *node)
  {
      // p는 node의 오른쪽 포인터
      TreeNode *p = node->right;
      // 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
      if(p == NULL || node->is_thread == TRUE)
          return p;
      // 만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
      while(p->left)
          p = p->left;
      return p;
  }
  ```

  ```c
  void thread_inorder(TreeNode *node)
  {
      TreeNode *p = node;
      while(p->left)		// 가장 왼쪽 노드로 간다.
          p = p->left;
      do{
          printf("%c", p->data);	// 데이터 출력
          p = find_successor(p);	// 후속자 함수 호출
      }while(p);					// NULL이 아니면
  }
  ```

[Thread_binary_tree](https://github.com/mgstyle97/TIL/blob/master/Data_structure/Tree/src/thread_binary_tree.c)

## 8.11 이진 탐색 트리

- **이진 탐색 트리(binary search tree)** : 이진 트리 기반의 탐색을 위한 자료 구조이다.

  - **탐색(search)**은 가장 중요한 컴퓨터 응용의 하나이다.

    > - 탐색은 우리 일상생활과 컴퓨터 프로그램에서 많이 사용되며, 가장 시간이 많이 걸리는 작업 중의 하나이므로 탐색을 효율적으로 수행하는 것은 무척 중요하다.
    > - 컴퓨터 프로그램에서 탐색은 레코드(record)의 집합에서 특정한 레코드를 찾아내는 작업을 의미한다.
    > - 레코드는 하나 이상의 필드(field)로 구성된다.
    >   - 일반적으로 레코드들의 집합을 테이블(table)이라고 한다.
    >   - 레코드들은 보통 키(key)라고 불리는 하나의 필드에 의해 식별할 수 있다.
    >   - 일반적으로 어떤 키는 다른 키와 중복되지 않는 고유한 값을 가지며 이러한 키를 사용하면 각각의 레코드들을 구별할 수 있을 것이다.
    >     - 이러한 키를 주요키(primary key)라고 부른다.
    >
    > 이진 탐색 트리는 이러한 탐색 작업을 효율적으로 하기 위한 자료 구조 이다.

  <img src="./8. 트리/search terms.PNG">

### 이진 탐색 트리의 정의

- **이진 탐색 트리**

  > - 모든 원소의 키는 유일한 키를 가진다.
  > - 왼쪽 서브 트리 키들은 루트 키보다 작다.
  > - 오른쪽 서브 트리의 키들은 루트의 키보다 크다.
  > - 왼쪽과 오른쪽 서브 트리도 이진 탐색 트리이다.

  <img src="./8. 트리/BST.PNG">

  - 찾고자 하는 키값이 이진트리의 루트 노드의 키값과 비교하여 루트 노드보다 작으면 원하는 키값은 왼쪽 서브 트리에 있고, 루트 노드보다 크면 원하는 키값은 오른쪽 서브 트리에 있음을 알 수 있다.

  <img src="./8. 트리/exp bst.PNG">



### 순환적인 탐색 연산

- 이진 탐색 트리에서 특정한 키값을 가진 노드를 찾기 위해서는 먼저 주어진 탐색키 값과 루트 노드의 키값을 비교한다.

  - 비교한 결과가 같으면 탐색이 성공적으로 끝난다.
  - 비교한 결과가, 주어진 키 값이 루트 노드의 키값보다 작으면 탐색은 이 루트 노드의 왼쪽 자식을 기준으로 다시 시작한다.
  - 비교한 결과가, 주어진 키 값이 루트 노드의 키값보다 크면 탐색은 이 루트 노드의 오른쪽 자식을 기준으로 다시 시작한다.
  - **BST 탐색 알고리즘 유사코드(순환적)**

  ```
  search(root, key):
  
  if root == NULL
  	then return NULL;
  if key == KEY(root)
  	then return root;
  	else if key < KEY(root)
  		then return search(LEFT(root), key);
  		else return search(RIGHT(root), key);
  ```

  <img src="./8. 트리/search operator.PNG">

  ```C
  TreeNode* search(TreeNode *root, int key)
  {
      if(node == NULL)
          return NULL;
      if(key == root->data)
          return root;
      else if(key < root->data)
          return search(root->left, key);
      else
          return search(root->right, key);
  }
  ```



### 반복적인 탐색 연산

- 효율적인 측면에서 반복적인 연산이 순환적인 연산보다 훨씬 우수하다.

  ```c
  TreeNode* search(TreeNode *root, int key)
  {
      TreeNode *node = root;
      while(node != NULL){
          if(key == node->data)
              return node;
      	else if(key < node->data)
              node = node->left;
      	else
              node = node->right;
      }
      return NULL;
  }
  ```



### 이진 탐색 트리에서 삽입 연산

- 이진 트리에서 원소를 삽입하기 위해서는 먼저 탐색을 수행하는 것이 필요하다.

  - 이진 탐색 트리에서는 같은 키값을 갖는 노드가 없어야 하기 때문이고 탐색에 실패한 위치가 바로 새로운 노드를 삽입하는 위치가 되기 때문이다.

  <img src="./8. 트리/insert operator.PNG">

  - 새로운 노드는 항상 단말 노드에 추가된다.
  - 단말 노드를 발견할 때까지 루트에서 키를 검색하기 시작한다. 단말 노드가 발견되면 새로운 노드가 단말 노드의 하위 노드로 추가된다.
  - **이진 탐색 트리 삽입 연산 알고리즘 유사코드**

  ```
  insert(root, n):
  
  if KEY(n) == KEY(root)
  	then return;
  else if KEY(n) < KEY(root) then
  	if LEFT(root) == NULL
  		then LEFT(root) <- n;
  		else insert(LEFT(root), n);
  else
  	if RIGHT(root) == NULL
  		then RIGHT(root) <- n;
  		else insert(RIGHT(root), n);
  ```

  ```c
  TreeNode* insert(TreeNode *root, int key)
  {
      TreeNode *node = root;
      // 트리가 공백이면 새로운 노드를 반환한다.
      if(node == NULL)
          return new_node(key);
      // 그렇지 않으면 순환적으로 트리를 내려간다.
      if(key < node->data)
          node->left = insert(node->left, key);
      else if(key > node->data)
          node->right = insert(node->right, key);
      
      // 변경된 루트 포인터를 반환한다.
      return node;
          
  }
  ```

### 이진 탐색 트리에서 삭제 연산

- 노드를 삭제하는 것은 이진 탐색 트리에서 가장 복잡한 연산이다.

  - 노드를 삭제하기 위해서 트리를 탐색하여야 한다는 것은 삽입과 마찬가지이다.
  - 삭제하려고 하는 키값이 트리 안에 어디 있는지를 알아야 한다.

    1. 삭제하려는 노드가 단말 노드일 경우
    2. 삭제하려는 노드가 하나의 왼쪽이나 오른쪽 서브 트리중 하나만 가지고 있는 경우
    3. 삭제하려는 노드가 두 개의 서브 트리 모두 가지고 있는 경우

#### 첫 번째 경우 : 삭제하려는 노드가 단말 노드일 경우

- 삭제할 노드가 단말 노드일 경우 노드 아래에 더 이상 노드가 없으므로 가장 쉽게 삭제할 수 있다.

  - 단말 노드를 삭제한다는 것은 단말 노드의 부모 노드를 찾아서 부모 노드 안에 링크 필드를 NULL로 만들어서 연결을 끊으면 된다.

  <img src="./8. 트리/leaf delete.PNG">



#### 두 번째 경우 : 삭제하려는 노드가 하나의 서브 트리만 가지고 있는 경우

- 삭제되는 노드가 왼쪽이나 오른족 서브 트리중 하나만 가지고 있는 경우에는 자기 노드는 삭제하고 서브 트리는 자기 노드의 부모 노드에 붙여주면 된다.

  <img src="./8. 트리/one sub delete.PNG">



#### 세 번째 경우 : 삭제하려는 노드가 두 개의 서브 트리를 가지고 있는 경우

- 가장 중요한 문제는 서브 트리에 있는 어떤 노드를 삭제 노드 위치로 가져올 것인가 이다.

  - 삭제하려는 노드의 자식 노드를 그대로 가져오게 되면 이진 탐색 트리에 맞지 않는 트리가 된다.
    - 그렇기 때문에 삭제하려는 노드와 가장 비슷한 값을 가지는 노드로 대체하여야 한다. 
    - 따라서 가장 적합한 노드는 왼쪽 서브 트리에서 가장 큰 값이거나 오른쪽 서브 트리에서 가장 작은 값으로 대체하여야 한다.
  - 이들 노드는 이진 탐색 트리를 중위 순회하였을 경우, 각각 선행 노드와 후속 노드에 해당한다.
  
<img src="./8. 트리/successor node.PNG">
  
  <img src="./8. 트리/example delete.PNG">

<img src="./8. 트리/teo sub delete.PNG">

```C
// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
// 새로운 루트 노드를 반환한다.
TreeNode* delete_node(TreeNode *root, int key)
{
    if(root == NULL)
        return root;
    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if(key < root->data)
        root->left = delete_node(root->left, key);
    // 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
    else if(key > root->data)
        root->right = delete_node(root->right, key);
    // 키가 루트와 같으면 이 노드를 삭제하면 된다.
    else{
        // 첫 번째나 두 번째의 경우
        if(root->left == NULL){
            TreeNode *tmep = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // 세 번째 경우
        TreeNode *temp = min_value_node(root->right);
        // 중위 순회시 후계 노드를 복사한다.
        root->data = temp->data;
        // 중위 순회시 후계 노드를 삭제한다.
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}
```

```c
TreeNode* min_value_node(TreeNode *node)
{
    TreeNode *current = node;
    
    while(current->left)
        current = current->left;
    
    return current;
}
```



### 이진 탐색 트리의 분석

- 이진 탐색 트리에서의 탐색, 삽입, 삭제 연산의 시간 복잡도는 트리의 높이를 h라고 했을 때 O(h)가 된다.

  - n개의 노드를 가지는 이진 탐색 트리의 경우, 일반적인 이진 트리의 높이는 [log<sub>2</sub>n]이므로 이진 탐색 트리 연산의 평균적인 경우의 시간 복잠도는 O(log<sub>2</sub>n)이다.

  <img src="./8. 트리/Time complexity.PNG">

  - 그러나 이는 좌우의 서브 트리가 균형을 이룰 경우이고 최악의 경우에는 한쪽으로 치우치는 경사 트리가 되어서 트리의 높이가 n이 된다. 이 경우에는 탐색, 삭제, 삽입 시간이 거의 선형 탑색과 같이 O(n)이 된다.

  <img src="./8. 트리/Slanted Binary Tree.PNG">

  - 선형 탐색에 비하여 전혀 시간적으로 이득이 없다.
    - 이러한 최악의 경우를 방지하기 위하여 트리의 높이를 [log<sub>2</sub>n]으로 한정시키는 균형 기법이 필요하다.
    - 트리를 균형지게 만드는 기법으로 AVI 트리를 비롯한 여러 기법들이 개발되었다. 