#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    int code;
    string name;
    double price;
    Node* left;
    Node* right;

    Node(int c, string n, double p)
        : code(c), name(n), price(p), left(nullptr), right(nullptr) {}
};

// Вставка
Node* insert(Node* root, int code, string name, double price) {
    if (!root) return new Node(code, name, price);

    if (code < root->code)
        root->left = insert(root->left, code, name, price);
    else
        root->right = insert(root->right, code, name, price);

    return root;
}

// Середня ціна
void calcAvg(Node* root, double& sum, int& count) {
    if (!root) return;

    sum += root->price;
    count++;

    calcAvg(root->left, sum, count);
    calcAvg(root->right, sum, count);
}

// Кількість вузлів на рівнях
void countLevels(Node* root, int level, int arr[]) {
    if (!root) return;

    arr[level]++;
    countLevels(root->left, level + 1, arr);
    countLevels(root->right, level + 1, arr);
}

// Пошук і видалення піддерева
Node* deleteSubtree(Node* root, int code) {
    if (!root) return nullptr;

    if (root->code == code) {
        return nullptr; // видаляємо все піддерево
    }

    root->left = deleteSubtree(root->left, code);
    root->right = deleteSubtree(root->right, code);

    return root;
}

// Вивід
void print(Node* root) {
    if (!root) return;

    print(root->left);
    cout << root->code << " " << root->name << " " << root->price << endl;
    print(root->right);
}

// Очистка
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ifstream file("input.txt");

    Node* root = nullptr;
    int code;
    string name;
    double price;

    while (file >> code >> name >> price) {
        root = insert(root, code, name, price);
    }

    double sum = 0;
    int count = 0;

    calcAvg(root, sum, count);
    cout << "Average price: " << sum / count << endl;

    int levels[100] = {0};
    countLevels(root, 0, levels);

    cout << "Nodes per level:\n";
    for (int i = 0; i < 100; i++) {
        if (levels[i] == 0) break;
        cout << "Level " << i << ": " << levels[i] << endl;
    }

    int delCode;
    cout << "Enter code to delete subtree: ";
    cin >> delCode;

    root = deleteSubtree(root, delCode);

    cout << "Tree after deletion:\n";
    print(root);

    freeTree(root);
    return 0;
}