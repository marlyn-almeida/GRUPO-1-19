#include "graphics.h"
#include <stdio.h>//
#include <time.h> //
#include <iostream>//
#include <math.h>//
using namespace std;
void circle( int x, int y, int radius );

int radius = 20;
int h = 25;

class Node 
{
    public:
    int data;
    Node *left;
    Node *right;
}; 

class Tree 
{
    public:
    Node *root;
    Node* Insert(Node* node, int data);
    bool Search(Node* node, int data);
    void Delete(int data);
    void Inorder(Node *node, int topH, int Hor);
    void graph(int i, int Y, int X, int data);
};


// crear metodo para graficar el arbol.
void Tree::graph(int i, int Y, int X, int data)
{
	
	if(i==0)
	{
		circle(X/2,Y,radius);
		char dataCon[2];
		settextstyle(1,0,2);
		sprintf(dataCon, "%d", data); 
		outtextxy(X/2-16,Y-15,dataCon);
	}
	
}
int diff = 50;
int i = 10;
void Tree::Inorder(Node * node, int topH, int Hor) 
{
    if(node == NULL) 
    {
        return;
    }
    
    i-- ;
    if(node->left !=NULL)
    	line(Hor/2-radius/1.41,topH+radius/1.41,(Hor-100-diff*i)/2+radius/1.41,topH+80-radius/1.41);
    Inorder(node->left,topH+80,Hor-100-diff*i); 
    graph(0,topH,Hor,node->data);	if(node->right !=NULL)
    	line(Hor/2+radius/1.41,topH+radius/1.41,(Hor+120+diff*i)/2-radius/1.41,topH+80-radius/1.41);
    Inorder(node->right,topH+80,Hor+120+diff*i);
	}

//metodo para agregar datos al arbol
Node* Tree::Insert(Node* node, int data) 
{ 
    /* 1.  If the tree is empty, return a new, 
        single node */
    if (node == NULL)  {
    	node = new Node();
    	node->data = data;
    	node->left = NULL;
    	node->right = NULL;
    	return node;
    }
    else
    {
        Node* temp;
         
        /* 2. Otherwise, recur down the tree */
        if (data <= node->data) 
        {
             temp = Insert(node->left, data);
             node->left  = temp;                
        }
        else
        {
            temp = Insert(node->right, data);
            node->right = temp;
                
        }
         
        /* return the (unchanged) node pointer */
        return node;
    }
}

// metodo para buscar en el arbol, en cada nodo se realizan las comparaciones.
bool Tree::Search(Node* node, int data) 
{ 
    if(node == NULL) 
    {
        return false;
    }
    
    if(node->data == data) 
    {
        return true;
    }
    
    if(node->data <= data+1) 
    {
        return Search(node->left,data);
    }
    else
    {
        return Search(node->right,data);
    }
}

//metodo para eliminar datos del arbol
void Tree::Delete(int data)
{
	Node *node = root;
	Node *parent = NULL;
	
	while(node != NULL && node->data != data)
	{
		parent = node;
		
		if(data < node->data)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	
	if(node == NULL)
	{
		return;
	}
	
	if(node->left == NULL && node->right == NULL)
	{
		if(parent->left == node)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
		
		delete node;
	}
	else if(node->left == NULL && node->right != NULL)
	{
		if(parent->left == node)
		{
			parent->left = node->right;
		}
		else
		{
			parent->right = node->right;
		}
		
		delete node;
	}
	else if(node->left != NULL && node->right == NULL)
	{
		if(parent->left == node)
		{
			parent->left = node->left;
		}
		else
		{
			parent->right = node->left;
		}
		
		delete node;
	}
	else
	{
		Node *aux = node->right;
		Node *aux_parent = node;
		
		while(aux->left != NULL)
		{
			aux_parent = aux;
			aux = aux->left;
		}
		
		node->data = aux->data;
		
		if(aux->right != NULL)
		{
			aux_parent->left = aux->right;
		}
		else
		{
			aux_parent->left = NULL;
		}
		
		delete aux;
	}
}


int main(int argc, char *argv[])
{
	//int gd = DETECT, gm;
	initwindow(1400,1400,"arbol Ronald");
	Tree arbol;
	arbol.root = NULL;
       do{//menu del arbol
       	int data, valor, op;
       	cout<<"1) Insertar"<<endl;
       	cout<<"2) Buscar"<<endl;
       	cout<<"3) Eliminar"<<endl;
       	cout<<"4) Mostrar"<<endl;
       	cout<<"5) Salir"<<endl;
       	cin>>op;	
       	switch(op){
       		case 1:
       			cout<<"Introduzca el dato: ";
       			cin>>data;
       			arbol.root = arbol.Insert(arbol.root,data);
       		break;
       		case 2:
       			cout<<"Introduzca el dato a buscar: ";
       			cin>>valor;
       			if(arbol.Search(arbol.root,valor) == true)
       			{
       				cout<<"El dato se encuentra en el arbol."<<endl;
       			}
       			else
       			{
       				cout<<"El dato no se encuentra en el arbol."<<endl;
       			}
       		break;
       		case 3:
       			cout<<"Introduzca el dato a eliminar: ";
       			cin>>data;
       			arbol.Delete(data);
       		break;
       		case 4:
       			arbol.Inorder(arbol.root,h,1400);
       		break;
       		case 5:
       		exit(0);
       		break;
       		default:
       			cout<<"Opcion no valida."<<endl;
       		break;
       	}
       	
       	delay(1000);
       	cleardevice();
       	
       }while(true);
       getch();
	return 0;
}
