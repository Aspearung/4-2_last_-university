
#include <stdio.h>
#include <stdlib.h>
#define datatype int

//이진 트리 노드 구조 정의
typedef struct tnode{
    struct tnoe *left;
    datatype data;
    struct tnode *right;
}tnode;
//이진 트리 노드의 기본 구조인 왼쪽, 데이터, 오른쪽을 만든다.


//이진 트리의 헤드 노드 구조 정의
typedef struct linkedbt{
    tnode *root;
}linkedbt;
//노드들을 방문해야 하기에 주소를 따라갈 수 있는
//구조체도 하나 만들어 준다.


//후위 순회를 이용한 식 트리 계산
int evaluate_tree(tnode *root){
    if(!root){
        return 0;
    }
    //만약 루트가 없다면 즉, null이라면 종료한다.
    if(!root->left && !root->right){
        return root->data; //피연산자 노드
    }
    //만약 왼쪽도 없고, 오른쪽도 없다면 단말노드이므로
    //그 노드의 데이터를 리턴한다.
    else{//연산자 노드
        int opd1 = evaluate_tree(root->left);
        //왼쪽 연산자 노드를 opd1이라고 칭한다.
        int opd2 = evaluate_tree(root->right);
        //오른쪽 연산자 노드를 opd2라고 칭한다.
        switch(root->data){
            //루트의 데이터값을 조회한다.
            //어떤 연산을 할지 정하는 것이다.
        case '+':
            printf("%c\n",root->data);
            printf("%d %c %d \n",opd1,root->data,opd2);
            return opd1 + opd2;
            //왼쪽노드와 오른쪽노드를 덧셈 한다.
        case '-':
            printf("%c\n",root->data);
            printf("%d %c %d \n",opd1,root->data,opd2);
            return opd1 - opd2;
            //왼쪽노드와 오른쪽노드를 뺄셈  한다.
        case '*':
            printf("%c\n",root->data);
            printf("%d %c %d \n",opd1,root->data,opd2);
            return opd1 * opd2;
            //왼쪽노드와 오른쪽노드를 곱셈  한다.
        case '/':
            printf("%c\n",root->data);
            printf("%d %c %d \n",opd1,root->data,opd2);
            return opd1 / opd2;
            //왼쪽노드와 오른쪽노드를 나눗셈하여 몫을 구한다.
        case '%':
            printf("%c\n",root->data);
            printf("%d %c %d \n",opd1,root->data,opd2);
            return opd1 % opd2;
            //왼쪽노드와 오른쪽노드를 나눗셈하여 나머지를 구한다.
        }
    }
    //파악하기 편하도록 연산자와 계산하는 값들을 나타내주었다.
}

int main(void){
    tnode node1 = { NULL, 10, NULL};
    tnode node2 = { NULL, 5, NULL};
    tnode node3 = { &node1, '-', &node2};
    tnode node4 = { NULL, 4, NULL};
    tnode node5 = { &node3, '*', &node4};
    tnode node6 = { NULL, 40, NULL};
    tnode node7 = { NULL, 8, NULL};
    tnode node8 = { &node6, '/', &node7};
    tnode node9 = { &node5, '+', &node8};
    //트리를 만들어 주고
    linkedbt expr;
    //그것을 읽을 헤드를 만들어준다.
    expr.root = &node9;
    //그 헤드의 주소를 node9의 주소로 주고
    printf("%d\n",evaluate_tree(expr.root));
    //후위 순회를 시작한다.
}
