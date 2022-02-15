#include<iostream>
#include<fstream>
#include<string.h>
#include <bits/stdc++.h>


using namespace std;

// BST Node for data1
struct Node {
	int num;
	char ad[30];
	char soyad[30];
    struct Node *left, *right;
};

Node* newNode(int num, char ad[30], char soyad[30])
{
    Node* temp = new Node;

    temp->num = num;
	strcpy(temp->ad, ad);
	strcpy(temp->soyad, soyad);

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* ekle(Node* root, int num, char ad[30], char soyad[30])
{
    // Create a new Node containing
    // the new element
    Node* newnode = newNode(num, ad, soyad);

    // Pointer to start traversing from root and
    // traverses downward path to search
    // where the new node to be inserted
    Node* x = root;

    // Pointer y maintains the trailing
    // pointer of x
    Node* y = NULL;

    while (x != NULL) {
        y = x;
        if (num < x->num)
            x = x->left;
        else
            x = x->right;
    }

    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        y = newnode;

    // If the new key is less then the leaf node key
    // Assign the new node to be its left child
    else if (num < y->num)
        y->left = newnode;

    // else assign the new node its right child
    else
        y->right = newnode;

    // Returns the pointer where the
    // new node is inserted
    return y;
}

Node* agacKur()
{
	Node* root = NULL;
	int first = 1;
	char ogrno[15],ad[30],soyad[30],satirAl[75];
	int num;
	char *ptr;
	ifstream dosya1("data3.txt");			//ifstream ile "data1.txt" dosyasını okumak için dosyayı açma
	dosya1.getline(satirAl,75);			
	for(int i=0;i<75;i++){				//satır sonundaki '\r' karakterini, '\0' karakteri ile değiştirme
		if(satirAl[i]=='\r')	
			satirAl[i]='\0';
		}
	while(dosya1){					//while döngüsü içinde dosyayı sonuna kadar satır satır okuma ve okunan satırları boşluklara göre parçalayıp, 
		ptr=strtok(satirAl,"\t");		//	j sayacının değerine göre değişkenlere atama
		int j=0;
		while(ptr!=NULL){
			if(j==0)
				strcpy(ogrno,ptr);
			if(j==1)
				strcpy(ad,ptr);
			if(j==2)
				strcpy(soyad,ptr);
			if(j==3){			//bir ad ve bir soyad okunmasına rağmen satır sonu gelmedi ise öğrencinin iki adı var demektir,
				strcat(ad," ");		//	bu iki ad arada bir boşluk bırakılarak öğrenci değişkenine atanır ve soyadı tekrar okunur
				strcat(ad,soyad);
				strcpy(soyad,ptr);
				}
			ptr=strtok(NULL," ");						
			j++;
			}
		num = atoi(ogrno);
		if (first)
		{
			root = ekle(root, num, ad, soyad);
			first = 0;
		}
		else
			ekle(root, num, ad, soyad);
		//cout << ogrno << "--" << ad << "--" << soyad << endl;
		dosya1.getline(satirAl,75);
		for(int i=0;i<75;i++){
			if(satirAl[i]=='\r')	
				satirAl[i]='\0';
			}
		}
	dosya1.close();
	return root;
}

void deletDeepest(struct Node* root, struct Node* d_node)
{
    queue<struct Node*> q;
    q.push(root);
 
    // Do level order traversal until last node
    struct Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
Node* deletion(struct Node* root, int key)
{
    if (root == NULL)
        return NULL;
 
    if (root->left == NULL && root->right == NULL) {
        if (root->num == key)
            return NULL;
        else
            return root;
    }
 
    queue<struct Node*> q;
    q.push(root);
 
    struct Node* temp;
    struct Node* key_node = NULL;
 
    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty()) {
        temp = q.front();
        q.pop();
 
        if (temp->num == key){
            key_node = temp;
			break;
		}
        if (temp->left)
            q.push(temp->left);
 
        if (temp->right)
            q.push(temp->right);
    }
    if (key_node != NULL) {
        int x = temp->num;
		char y[30];
		char z[30];
		strcpy(y, temp->ad);
		strcpy(z, temp->soyad);
        deletDeepest(root, temp);
        key_node->num = x;
		strcpy(key_node->ad, y);
		strcpy(key_node->soyad, z);
    }
    return root;
}
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
	cout << node->num << " "<< node->ad << " "<< node->soyad << "\n";
 
    /* then recur on left sutree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}
void Inorder(Node* root)
{
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        cout << root->num << " "<< root->ad << " "<< root->soyad << "\n";
        Inorder(root->right);
    }
}
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
	cout << node->num << " "<< node->ad << " "<< node->soyad << "\n";
}
 
int main()
{
	Node* root = NULL;
    //Node2* root2 = NULL;
    //Node3* root3 = NULL;
	root = agacKur();
	//Inorder(root);
	//root = deletion(root, 1001064);
	
	//root = deletion(root, 1001064);


	cout<<endl<<endl;
	Inorder(root);
	cout<<endl<<endl;

	printPostorder(root);
	cout<<endl<<endl;

	printPreorder(root);

	return 0;
}
	


/*

// BST node2 for data2
struct Node2 {
	int num;
	char ad[30];
	char soyad[30];
    struct Node2 *left, *right;
};

// BST node3 for data1
struct Node3 {
	int num;
	char ad[30];
	char soyad[30];
    struct Node3 *left, *right;
};

Node2* newNode2(int num, char ad[30], char soyad[30])
{
    Node2* temp = new Node2;
 
    temp->num = num;
	strcpy(temp->ad, ad);
	strcpy(temp->soyad, soyad);

    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}
Node3* newNode3(int num, char ad[30], char soyad[30])
{
    Node3* temp = new Node3;
 
    temp->num = num;
	strcpy(temp->ad, ad);
	strcpy(temp->soyad, soyad);
	
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}

*/