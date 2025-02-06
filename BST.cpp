#include "BST.h"
#include <iostream>

using namespace std;
BST::BST()
{
    //ctor
    this->root=nullptr;
}

BST::~BST()
{
    //dtor thakltklasdhflas
}
bool BST::InsertNode(Node* n){
    Node *p=this->root;
    Node *T;
    if(root==nullptr)
    {
        this->root=n;
        return true;
    }
    while(p!=nullptr){
        T=p;

        if(p->Getkey()>n->Getkey())
            p=p->Getleft();
    else
        if(p->Getkey()<n->Getkey())
            p=p->Getright();
    else
        if(p->Getkey()==n->Getkey())
            return false;
    }
    if(T->Getkey()>n->Getkey())
        T->Setleft(n);
    else T->Setright(n);
    return true;

}
bool BST::InsertNodeRe(Node* root,Node*p){
    if(root==nullptr){
        root=p;
        return true;
    }
    if(root->Getkey()==p->Getkey())
            return false;
    else if(root->Getkey()>p->Getkey())
            return InsertNodeRe(root->Getleft(),p);
            else return InsertNodeRe(root->Getright(),p);
}
void BST::NLR(Node*r){
    if(r!=nullptr){
        cout<<r->Getkey()<<"\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}
void BST::LNR(Node*r){
     if (r!=nullptr){
     	LNR(r->Getleft());
     	cout <<r->Getkey()<<"\n";
     	LNR(r->Getright());
	 }
}
void BST::LRN(Node*r){
    if(r!=nullptr){
    	LRN(r->Getleft());
    	LRN(r->Getright());
    	cout<<r->Getkey()<<"\n";
	}
}
void BST::TravelNLR(){
    NLR(this->root);
}
void BST::TravelLNR(){
    LNR(this -> root);
}
void BST::TravelLRN(){
     LRN(this-> root);
}
Node* BST::search_x(int k){
     Node* p=this->root;
     while(p!=nullptr){
     	if(p->Getkey() == k)
     		return p;
     	else if (p->Getkey()>k)
     		p=p->Getleft();
     	else 
     		p=p->Getright();
	 }
}
void BST::deleteNode(Node* n){
    Node* p;
    if(p->Getleft()==nullptr&&n->Getright()==nullptr)
        delete n;
    else{
        if(p->Getright()!=nullptr){
            while(p->Getleft()!=nullptr)//
                p=p->Getleft();
            n->Setkey(p->Getkey());
            delete p;
        }else{
        	p=p->Getleft();
            while(p->Getright()!=nullptr)//
                 p=p->Getright();
            n->Setkey(p->Getkey());
            delete p;
        }
    }
}

