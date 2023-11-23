#include<iostream>
using namespace std;

template<typename X>
struct node{
    X data;
    node* left;
    node* right;
};

template<typename X>
class BST{
        node<X> *root;
    private:
        node<X>* actualInsert(node<X> *root,X data);
        node<X>* actualDelete(node<X> *root,X data);
        void actualPreorder(node<X>* root);
        void actualInorder(node<X> *root);
        void actualPostorder(node<X> *root);
    public:
        BST();
        bool isEmpty();
        void insert(X data);
        node<X> *search(int);
        node<X> *deleteNode(X data);
        void inorder();
        void preorder();
        void postorder();
        ~BST();
};

template<typename X>BST<X>::BST(){
    root = nullptr;
}

template<typename X> bool BST<X>::isEmpty(){
    bool flag = false;
    if(root == nullptr){
        flag = true;
    }
    return flag;
}

template<typename X>void BST<X>::insert(X data){
        root = actualInsert(root,data);
}

template<typename X> node<X>* BST<X>::actualInsert(node<X> *root,X data){
    if(root == nullptr){
        node<X> *temp = new node<X> ;
        temp->data = data;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }
    if(data == root->data){
        return root;
    }
    if(data < root->data){
        root->left = actualInsert(root->left,data);
        return root;
    }
    else if(data > root->data){
        root->right = actualInsert(root->right,data);
        return root;
    }
}

template<typename X>void BST<X>::inorder(){
    actualInorder(root);
}

template<typename X>void BST<X>::actualInorder(node<X> *r){
    if(r){
        actualInorder(r->left);
        cout<<r->data<<" ";
        actualInorder(r->right);
    }
}

template<typename X>void BST<X>::preorder(){
    actualPreorder(root);
}

template<typename X>void BST<X>::actualPreorder(node<X>* r){
    if(r){
        cout<<r->data<<" ";
        actualPreorder(r->left);
        actualPreorder(r->right);
    }
}

template<typename X>void BST<X>::postorder(){
    actualPostorder(root);
}

template<typename X>void BST<X>::actualPostorder(node<X> *r){
    if(r){
        actualPostorder(r->left);
        actualPostorder(r->right);
        cout<<r->data<<" ";
    }
}

template<typename X>node<X> *BST<X> :: actualDelete(node<X>* root,X data){
    if(root){
        if(data < root->data){
            root->left = actualDelete(root->left,data);
        }
        else if(data > root->data){
            root->right = actualDelete(root->right,data);
        }
        else if(data == root->data){
        //if both the childs are present
            if(root->left && root->right){
                node<X> *tempPrev = root;
                node<X> *temp = root->left;
                
                if(temp->right){
                    while(temp->right){
                        tempPrev = temp;
                        temp = temp->right;
                    }
                    root->data = temp->data;
                    tempPrev->right = actualDelete(temp,temp->data);
                }
                else{
                    root->data = temp->data;
                    tempPrev->left = actualDelete(temp,temp->data);
                }
                return root;
            }
            //only left or only right child is present
            else if(root->left){
                node<X>* temp = root->left;
                delete root;
                return temp;
            }else if(root->right){
                node<X>* temp = root->right;
                delete root;
                return temp;
            }
            //no child is present
            else{
                delete root;
                root = nullptr;
            }

        }
        return root;
    }
    else{
        return nullptr;
    }
}

template<typename X>node<X>* BST<X> :: deleteNode(X data){
    root = actualDelete(root,data);
}

template<typename X>node<X>* search(node<X>* root,int data){
    node<X>* temp;
        if(root == nullptr){
            temp = nullptr;
        }else if(root->data > data){
            temp = search(root->left,data);
        }else if(root->data < data){
            temp = search(root->right,data);
        }else{
            temp = root;
        }
        return temp;
}

template<typename X>BST<X>:: ~BST(){
    while(root){
        deleteNode(root->data);
    }
}
