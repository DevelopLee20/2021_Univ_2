#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100
int list[MAX_SIZE];
int n;
typedef int element;
typedef struct TreeNode {
   element key;
   struct TreeNode* left, * right;
} TreeNode;

// 순환적인 탐색 함수
TreeNode* search(TreeNode* node, int key)
{
   if (node == NULL) return NULL;
   if (key == node->key) return node;
   else if (key < node->key)
      return search(node->left, key);
   else
      return search(node->right, key);
}
TreeNode* new_node(int item)
{
   TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}
TreeNode* insert_node(TreeNode* node, int key)
{
   // 트리가 공백이면 새로운 노드를 반환한다. 
   if (node == NULL) return new_node(key);

   // 그렇지 않으면 순환적으로 트리를 내려간다. 
   if (key < node->key)
      node->left = insert_node(node->left, key);
   else if (key > node->key)
      node->right = insert_node(node->right, key);

   // 변경된 루트 포인터를 반환한다. 
   return node;
}
TreeNode* min_value_node(TreeNode* node)
{
   TreeNode* current = node;

   // 맨 왼쪽 단말 노드를 찾으러 내려감
   while (current->left != NULL)
      current = current->left;

   return current;
}
// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
// 새로운 루트 노드를 반환한다. 
TreeNode* delete_node(TreeNode* root, int key)
{
   if (root == NULL) return root;

   // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
   if (key < root->key)
      root->left = delete_node(root->left, key);
   // 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
   else if (key > root->key)
      root->right = delete_node(root->right, key);
   // 키가 루트와 같으면 이 노드를 삭제하면 됨
   else {
      // 첫 번째나 두 번째 경우
      if (root->left == NULL) {
         TreeNode* temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL) {
         TreeNode* temp = root->left;
         free(root);
         return temp;
      }
      // 세 번째 경우
      TreeNode* temp = min_value_node(root->right);

      // 중외 순회시 후계 노드를 복사한다. 
      root->key = temp->key;
      // 중외 순회시 후계 노드를 삭제한다. 
      root->right = delete_node(root->right, temp->key);
   }
   return root;
}

// 중위 순회
void inorder(TreeNode* root) {
   int arr[MAX_SIZE];
   if (root) {
      inorder(root->left);// 왼쪽서브트리 순회
      printf("[%d] ", root->key);  // 노드 방문
      // ordered(root, arr);
      inorder(root->right);// 오른쪽서브트리 순회
   }
}
void ordered(TreeNode* root, int list[]) {
   for (int i = 0; i < n; i++) {
      list[i] = root->key;
      printf("%d ", list[i]);
   }
}

int main(void)
{
   TreeNode* root = NULL;
   int key;

   printf("정수 개수: ");
   scanf("%d",&n);

   srand(time(NULL));
   for (int i = 0; i < n; i++) {
      key = rand() % MAX_SIZE + 1;
      list[i] = key;
      printf("%d ", key);
      for (int j = 0; j < i; j++) {
         if (key == list[j]) {
            i--;
            break;
         }
      }
   }

   for (int i = 0; i < n; i++) {
      root = insert_node(root, list[i]);
   }
   printf("\n이진 탐색 트리 정렬 결과 \n");
   inorder(root);
   printf("\n\n");
   return 0;
}