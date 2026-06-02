#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Вставка в BST
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Пошук
bool search(Node* root, int value) {
    if (!root) return false;
    if (root->data == value) return true;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Глибина дерева
int depth(Node* root) {
    if (!root) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

// Розділення на парні/непарні
void splitTree(Node* root, Node*& evenTree, Node*& oddTree) {
    if (!root) return;

    if (root->data % 2 == 0)
        evenTree = insert(evenTree, root->data);
    else
        oddTree = insert(oddTree, root->data);

    splitTree(root->left, evenTree, oddTree);
    splitTree(root->right, evenTree, oddTree);
}

// Вивід (inorder)
void print(Node* root) {
    if (!root) return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

// Очищення пам'яті
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    srand(time(0));

    Node* root = nullptr;
    int n, a, b;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter range [a, b]: ";
    cin >> a >> b;

    if (n > (b - a + 1)) {
        cout << "Error: too many nodes for range\n";
        return 1;
    }

    // Генерація
    while (true) {
        int val = rand() % (b - a + 1) + a;
        if (!search(root, val))
            root = insert(root, val);

        if (depth(root) >= n) break;
    }

    cout << "Tree: ";
    print(root);
    cout << endl;

    Node* evenTree = nullptr;
    Node* oddTree = nullptr;

    splitTree(root, evenTree, oddTree);

    cout << "Even tree: ";
    print(evenTree);
    cout << endl;

    cout << "Odd tree: ";
    print(oddTree);
    cout << endl;

    cout << "Depth main: " << depth(root) << endl;
    cout << "Depth even: " << depth(evenTree) << endl;
    cout << "Depth odd: " << depth(oddTree) << endl;

    freeTree(root);
    freeTree(evenTree);
    freeTree(oddTree);

    return 0;
}