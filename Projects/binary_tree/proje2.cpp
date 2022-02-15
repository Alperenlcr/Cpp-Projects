#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream> 
#include<stack>
#include<queue>
#include<string>

using namespace std;

struct Node
{
	int num;
	char ad[30];
	char soyad[30];
	struct Node *left, *right;
};

void Preorder(Node* node);
void Inorder(Node* root);
void Postorder(Node* node);
void dosyaya_yazma(Node* root, ofstream &myfile);
Node* ekle(Node* root, int num, char ad[30], char soyad[30]);
Node* agacKur(int secim);
void ilkGenislikAra(Node* root, int key);
void ilkDerinlikAra(Node* root, int key);
Node* ogrenciSil(Node* root, int key);
Node* en_sol(Node* node);

int main()
{
	int dosya_no, sec3, numara;
	bool cikis = true;
	char sec, sec2;
	Node* root = NULL;
	while (cikis)
	{
		cout << "\nAsagidaki islemlerden birini seciniz.\n";
		cout << "\nArama yapmak icin : A";
		cout << "\nListeyi ekrana yazdirmak icin : L";
		cout << "\nOgrenci silmek icin : S";
		cout << "\nDosyaya yazmak icin : Y";
		cout << "\nCikis icin : C\n";
		cin>>sec;

		if (sec == 'A' || sec == 'a')
		{
			cout << "Arama yolunu seciniz. depth first search icin 1, breath first search icin 2 giriniz : ";
			cin >> sec3;
			cout << "Arama yapilacak listeyi seciniz.";
			do
			{
				cout << "\ndata1.txt icin 1\ndata2.txt icin 2\ndata3.txt icin 3\n giriniz.\n";
				cin>>dosya_no;
			} while (dosya_no > 3 || dosya_no < 1);
			root = NULL;
			root = agacKur(dosya_no);
			cout << "Aranacak ogrencinin numarasini giriniz : ";
			cin >> numara;
			if (sec3 == 1)
			{
				Node* temp = root;
				ilkDerinlikAra(temp, numara);
			}
			else
				ilkGenislikAra(root, numara);
		}
		else if (sec == 'L' || sec == 'l')
		{
			cout << "\nPreorder listeleme yapmak icin : R";
			cout << "\nInorder listeleme yapmak icin : I";
			cout << "\nPostorder listeleme yapmak icin : O\n";
			cin>>sec2;
			if (sec2 == 'R' || sec2 == 'r')
			{
				cout << "Preorder listelenecek listeyi seciniz.";
				do
				{
					cout << "\ndata1.txt icin 1\ndata2.txt icin 2\ndata3.txt icin 3\n giriniz.\n";
					cin>>dosya_no;
				} while (dosya_no > 3 || dosya_no < 1);
				root = NULL;
				root = agacKur(dosya_no);
				Preorder(root);
			}
			else if (sec2 == 'I' || sec2 == 'i')
			{
				cout << "Inorder listelenecek listeyi seciniz.";
				do
				{
					cout << "\ndata1.txt icin 1\ndata2.txt icin 2\ndata3.txt icin 3\n giriniz.\n";
					cin>>dosya_no;
				} while (dosya_no > 3 || dosya_no < 1);
				root = NULL;
				root = agacKur(dosya_no);
				Inorder(root);
			}
			else
			{
				cout << "Postorder listelenecek listeyi seciniz.";
				do
				{
					cout << "\ndata1.txt icin 1\ndata2.txt icin 2\ndata3.txt icin 3\n giriniz.\n";
					cin>>dosya_no;
				} while (dosya_no > 3 || dosya_no < 1);
				root = NULL;
				root = agacKur(dosya_no);
				Postorder(root);
			}
		}
		else if (sec == 'S' || sec == 's')
		{
			cout << "Silinecek listeyi seciniz.\n";
			do
			{
				cout << "\ndata1.txt icin 1\ndata2.txt icin 2\ndata3.txt icin 3\n giriniz.\n";
				cin>>dosya_no;
			} while (dosya_no > 3 || dosya_no < 1);
			root = NULL;
			root = agacKur(dosya_no);
			cout << "Silinecek ogrencinin numarasini giriniz : ";
			cin >> numara;
			root = ogrenciSil(root, numara);
		}
		else if (sec == 'Y' || sec == 'y')
		{
			char dosyalar[3][20] = {"data1.txt", "data2.txt", "data3.txt"};
			ofstream myfile(dosyalar[dosya_no-1]);
			if ( ! myfile.is_open())
				cout<<"\ndosya acilamadi\n";
			else
			{
				dosyaya_yazma(root, myfile);
				myfile.close();
				cout << "\nBasari ile dosyaya yazilmistir.";
			}
		}
		else
			cikis = false;
	}
	return 0;
}

Node* ekle(Node* root, int num, char ad[30], char soyad[30])
{
	Node* newnode = new Node;
	newnode->num = num;
	strcpy(newnode->ad, ad);
	strcpy(newnode->soyad, soyad);
	newnode->left = NULL;
	newnode->right = NULL;

	Node* x = root;
	Node* y = NULL;

	while (x != NULL) {
		y = x;
		if (num < x->num)
			x = x->left;
		else
			x = x->right;
	}

	if (y == NULL)
		y = newnode;

	else if (num < y->num)
		y->left = newnode;

	else
		y->right = newnode;

	return y;
}

void Preorder(Node* node)
{
	if (node == NULL)
		return;
	cout << node->num << " "<< node->ad << " "<< node->soyad << "\n";
	Preorder(node->left);
	Preorder(node->right);
}

void Inorder(Node* root)
{
	if (root == NULL)
		return;
	else
	{
		Inorder(root->left);
		cout << root->num << " "<< root->ad << " "<< root->soyad << "\n";
		Inorder(root->right);
	}
}

void Postorder(Node* node)
{
	if (node == NULL)
		return;
	Postorder(node->left);
	Postorder(node->right);
	cout << node->num << " "<< node->ad << " "<< node->soyad << "\n";
}

Node* agacKur(int secim)
{
	char dosyalar[3][20] = {"data1.txt", "data2.txt", "data3.txt"};
	Node* root = NULL;
	int first = 1;
	char ogrno[15],ad[30],soyad[30],satirAl[75];
	int num;
	char *ptr;
	ifstream dosya1(dosyalar[secim-1]);			//ifstream ile "data1.txt" dosyasını okumak için dosyayı açma
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

void dosyaya_yazma(Node* root, ofstream &myfile)
{
	string str;
	if (root == NULL)
		return;
	else
	{
		dosyaya_yazma(root->left, myfile);
		str = to_string(root->num);
		myfile << str << "\t" << root->ad << " " << root->soyad << "\n";
		dosyaya_yazma(root->right, myfile);
	}
}

Node* copy(Node *root)
{
    Node *new_root;
    if(root!=NULL)
	{
        new_root=new Node;
        new_root->num=root->num;
		strcpy(new_root->ad, root->ad);
		strcpy(new_root->soyad, root->soyad);
        new_root->left=copy(root->left);
        new_root->right=copy(root->right);
    }
	else
		return NULL;
    return new_root;
 }

void ilkDerinlikAra(Node* root, int key)
{
    // recursive'lik sayesinde memory'de stack yapisinda oluyor.
    bool found = false;
    Node* node = NULL;
    node = copy(root);
    stack <Node*> s;
    // stack e rootu ekleme
	s.push(node);
    // stack bosalana kadar dongu
    while (!s.empty())
    {
        node = s.top();
        // node un sagindaki null olmayana kadar ilerleme ve nodu guncelleme, stack e ekleme
        if (node->right != NULL)
        {
	        s.push(node->right);
			node->right = NULL; // node cikarirken agactaki bagi da kesmek icin
        }
        // node un sagindaki null ise node un solundaki null olmayana kadar ilerleme ve nodu guncelleme, stack e ekleme
        else if(node->left != NULL)
        {
	        s.push(node->left);
			node->left = NULL; // node cikarirken agactaki bagi da kesmek icin
        }
        // node un cocugu kalmadiysa stackten cikarma ve istenilen deger mi diye bakma
        else
        {
            if (node->num == key)
            {
                found = true;
			    cout << "\n" << node->num << " " << node->ad << " " << node->soyad << "\n";
            }
            s.pop();
        }
    }
    if (!found)
		cout << "\nAranan ogrenci bulunamadi.\n";
}

void ilkGenislikAra(Node* root, int key)
{
	bool found = false;
	queue<Node*> q;
	if (root)
	{
		q.push(root);
		if (key == root->num)
		{
			found = true;
			cout << root->num << " " << root->ad << " " << root->soyad << "\n";
		}
	}

	while (!q.empty())
	{
		const Node * const temp_node = q.front(); 
		q.pop();

		if (temp_node->left)
		{
			q.push(temp_node->left);
			if (key == temp_node->left->num)
			{
				found = true;
				cout << temp_node->left->num << " " << temp_node->left->ad << " " << temp_node->left->soyad << "\n";
			}
		}

		if (temp_node->right)
		{
			q.push(temp_node->right);
			if (key == temp_node->right->num)
			{
				found = true;
				cout << temp_node->right->num << " " << temp_node->right->ad << " " << temp_node->right->soyad << "\n";
			}
		}
	}
	if (!found)
		cout << "\nAranan ogrenci bulunamadi.\n";
}

Node* en_sol(Node* node)
{
	Node* current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

Node* ogrenciSil(Node* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->num)
		root->left = ogrenciSil(root->left, key);

	else if (key > root->num)
		root->right = ogrenciSil(root->right, key);

	else
	{
		// tek veya sifir cocuklu node
		if (root->left == NULL)
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			free(root);
			return temp;
		}

		// iki cocuklu node
		Node* temp = en_sol(root->right);

		root->num = temp->num;
		strcpy(root->ad, temp->ad);
		strcpy(root->soyad, temp->soyad);

		root->right = ogrenciSil(root->right, temp->num);
	}
	return root;
}
