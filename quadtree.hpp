
#ifndef H1_QUADTREE_H
#define H1_QUADTREE_H

#include <string>
#include<iostream>
#include <vector>

using namespace std;

struct node{

    node *nw;
    node *ne;
    node *sw;
    node *se;
    int XCOORD;
    int YCOORD;
    string cname;

    node ()
    {}

    node ( const int & x,  const int & y ,const string & n ,node * northw , node *nourthe , node *southw , node *southe)
            : XCOORD(x), YCOORD(y),cname(n) ,nw(northw) ,ne(nourthe),sw(southw),se(southe)
    {
      
        nw=nullptr;
        ne=nullptr;
        sw=nullptr;
        se=nullptr;
        
    }

};



class quadtree {

private:
    node *root;
    void printree(node* &t);
    void insert( const int &xc, const  int& yc , const string& cn ,node * &t);
    void search( const int & xco, const  int &yco ,const  int &rad,vector<string>&f,vector<string>&ontw,node* & r);
	void makeempty( node*&rott);


public:
    quadtree();
    ~quadtree();
    string compare(const int & xc, const int & yc, node* &d);
    bool equalcord( const int & xc, const int & yc,const string &cn,  node* & b);
    void prettyprint();
    void insertp(const int & xc, const int &yc ,  const string &cn);
    void searchp( const int & xco,  const int &yco , const  int &rad,vector<string>&f,vector<string>&ontw);
    string findquadrant(const int & xcoo, const int &ycoo , const int& radi, node * &rot);



};

#endif //H1_QUADTREE_H
