#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//210119K

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL) {
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (root == NULL) {
    struct node *nodeNew = new node;
    nodeNew->key = key;
    nodeNew->left = NULL;
    nodeNew->right = NULL;
    return nodeNew;
  }
  if (key < root->key) {
    root->left = insertNode(root->left, key);
  } else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    return root;
  }
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL) {
      struct node *temporary = root->right;
      delete root;
      return temporary;
    } else if (root->right == NULL) {
      struct node *temporary = root->left;
      delete root;
      return temporary;
    }
    struct node *minRight = root->right;
    while (minRight->left != NULL) {
      minRight = minRight->left;
    }
    root->key = minRight->key;
    root->right = deleteNode(root->right, minRight->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  cout << endl;
  return 0;
}
