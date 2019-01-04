#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "Student.h"

struct Node
{
    Student student;
    Node* left;
    Node* right;
};

class BinaryTree
{
private:
    Node* root;
    void deleteTree(Node*) const;
    void printFromNode(const Node*) const;
    void print() const;
    Node* isMember(unsigned long long, Node*);
    void addNode(Node*&, const Student&);
    void findSt(Node*,unsigned long long);
    void traverseSt(Node*);
    void deleteSt(Node*&,unsigned long long);

public:
    BinaryTree();
    ~BinaryTree();
    void insert();
    void deleteStudent();
    void find();
    void traverse();
};

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    deleteTree(root);
}

void BinaryTree::deleteTree(Node* root) const
{
    if(!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

Node* BinaryTree::isMember(unsigned long long fn, Node* root)
{
    if(!root)
        return nullptr;
    if(fn == root->student.getFN())
        return root;
    if(fn < root->student.getFN())
        return isMember(fn, root->left);
    return isMember(fn, root->right);
}

void BinaryTree::printFromNode(const Node* node) const
{
    if(!node)
        return;
    printFromNode(node->left);
    cout << node->student;
    printFromNode(node->right);
}

void BinaryTree::print() const
{
    printFromNode(root);
}

void BinaryTree::addNode(Node*& root, const Student& st)
{
    if(!root)
    {
        root = new Node;
        root->student = st;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if(st < root->student)
    {
        addNode(root->left, st);
    }
    else
    {
        addNode(root->right, st);
    }
}

void BinaryTree::insert()
{
    Student st;
    cin >> st;

    Node* stPtr = isMember(st.getFN(), root);
    if(!stPtr)
    {
        addNode(root,st);
    }
    else
    {
        stPtr->student = st;
    }
    //print();
    cout << "Record inserted!\n";
    return;
}

void BinaryTree::findSt(Node* root, unsigned long long studentsFN)
{
    if(!root)
    {
        cout << "Record not found!\n";
        return;
    }
    if(root->student.getFN() > studentsFN)
    {
        findSt(root->left, studentsFN);
    }
    else if(root->student.getFN() < studentsFN)
    {
        findSt(root->right, studentsFN);
    }
    else //(root->student.getFN() == studentsFN)
    {
        cout << root->student;
    }
}

void BinaryTree::find()
{
    unsigned long long facultyNumber;
    cin >> facultyNumber;
    findSt(root, facultyNumber);
}

void BinaryTree::traverseSt(Node* root)
{
    if(root->left)
    {
        traverseSt(root->left);
        cout << ", ";
    }
    cout << root->student.getFN();
    if(root->right)
    {
        cout << ", ";
        traverseSt(root->right);
    }
}

void BinaryTree::traverse() {
  traverseSt(root);
}

void BinaryTree::deleteSt(Node*& root, unsigned long long studentsFN)
{
    if(!root)
    {
        cout << "Record not found!\n";
        return;
    }
    if(studentsFN < root->student.getFN())
    {
        deleteSt(root->left, studentsFN);
    }
    else if(studentsFN > root->student.getFN())
    {
        deleteSt(root->right, studentsFN);
    }
    else
    {
        if(!(root->left) && !(root->right))
        {
            root = nullptr;
            cout << "Record deleted!\n";
            return;
        }
        else if(!(root->left))
        {
            Node* temp = root;
            root = root->right;
            delete temp;
            cout << "Record deleted!\n";
            return;
        }
        else if(!(root->right))
        {
            Node* temp = root;
            root = root->left;
            delete temp;
            cout << "Record deleted!\n";
            return;
        }
        else
        {
            Node* temp = root->right;
            while(temp->left)
            {
                temp = temp->left;
            }
            root->student = temp->student;
            deleteSt(root->right, temp->student.getFN());
        }
    }
}

void BinaryTree::deleteStudent()
{
    unsigned long long facultyNumber;
    cin >> facultyNumber;
    deleteSt(root, facultyNumber);
    return;
}

#endif // BINARYTREE_H_INCLUDED
