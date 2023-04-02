

#include "quadtree.hpp"
#include<cmath>
using namespace std;


quadtree::quadtree()
{
    root=NULL;
}

void quadtree::makeempty(node*&rott){
	if(rott!=NULL){
		
		makeempty(rott->se);
		makeempty(rott->sw);
		makeempty(rott->ne);
		makeempty(rott->nw);
		delete rott;
		
     }
	rott=NULL;
}
quadtree::~quadtree()
{
  makeempty(root);
}

void quadtree:: printree(node*& t){
    if(t != NULL){
        cout<<t->cname<<endl;
        printree(t->se);
        printree(t->sw);
        printree(t->ne);
        printree(t->nw);
    }
}


void quadtree::prettyprint(){
    printree(root);
    }


bool quadtree::equalcord( const int & xc, const int & yc,const string &cn ,  node* & b)
{
    // ıf 2 nodes cordinates or city are same returns true
    if( ((xc == b->XCOORD) &&(yc == b->YCOORD) )|| (cn == b->cname) ){
        return true;
    }
    return false;
}

 string quadtree::compare(const int & xc, const int & yc, node *&d) {

    if(xc < d->XCOORD){
        if(yc < d->YCOORD){
            return "sw";
        }
        else{
            return "nw";
        }
    }
    else if(yc < d->YCOORD){
        return "se";
    }
    else{
        return "ne";
    }

}

void quadtree::insert(const int & xc, const int &yc , const string& cn, node * &t)
{

    //node *nextn=new node(xc,yc,cn,nullptr,nullptr,nullptr,nullptr);


        if(t==NULL)
        {
            t=new node(xc,yc,cn,nullptr,nullptr,nullptr,nullptr);
           

        }
        else if(!equalcord(xc,yc,cn,t) && (compare( xc, yc, t) == "sw"))
        {
               insert(xc,yc,cn,t->sw);
        }
        else if(!equalcord(xc,yc,cn,t) && (compare(xc, yc, t) == "nw"))
        {
            insert(xc,yc,cn,t->nw);
        }
        else if(!equalcord(xc,yc,cn,t) && (compare(xc, yc,t) == "se"))
        {
            insert(xc,yc,cn,t->se);
        }
        else if(!equalcord(xc,yc,cn,t) && (compare(xc, yc, t) == "ne"))
        {
            insert(xc,yc,cn,t->ne);
        }
        


}



void  quadtree::insertp( const int &xc, const int &yc,  const string &cn) {
     insert( xc,yc, cn , root);
}




string quadtree::findquadrant(const int & xcoo, const int &ycoo , const int& radi, node * &rot){
    
    if( ( pow(((rot->XCOORD)-xcoo),2) + pow(((rot->YCOORD)-ycoo),2) )<= pow(radi,2)  ){ //13
        return "All";
        
    }
    else if( ( rot->XCOORD <= (xcoo+radi)    && rot->XCOORD >(xcoo-radi) ) && (rot->YCOORD> (ycoo + radi) ) ){  //2
        return "se,sw";
        
    }
    else if((rot->XCOORD<=(xcoo-radi)) && (rot->YCOORD>(ycoo+radi))){  //1
        return"se";
    }
    else if( (rot->XCOORD>(xcoo+radi))&&( rot->YCOORD >(ycoo+radi)) ){ //3
        return "sw";
    }
    else if( ( rot->XCOORD<(xcoo-radi) &&    rot->YCOORD <= (ycoo+radi)  && rot->YCOORD >(ycoo-radi) ) || ( rot->XCOORD==(xcoo-radi)  && ( ( rot->YCOORD < ycoo && rot->YCOORD >(ycoo-radi) ) || (   rot->YCOORD  <= (ycoo+radi)   && rot->YCOORD>ycoo) ) ) ) //4
	{ 
        return "se,ne";
    }
    else if( (rot->XCOORD>(xcoo+radi)) &&( rot->YCOORD <= (ycoo+radi) && rot->YCOORD>(ycoo-radi) ) ){ //5
        return "sw,nw";
    }
    else if((rot->XCOORD<=(xcoo-radi)) &&( rot->YCOORD<=(ycoo-radi))){  //6
        return "ne";
    }
    else if( ( (rot->YCOORD<(ycoo-radi)) && ( rot->XCOORD <=(xcoo+radi)  && rot->XCOORD>(xcoo-radi) ) )  || ( (rot->YCOORD==(ycoo-radi))  && ( ( rot->XCOORD <xcoo  &&  rot->XCOORD>(xcoo-radi)) || ( rot->XCOORD <= (xcoo+radi)  && rot->XCOORD>xcoo)))     ){  //7
        return "ne,nw";
    }
    else if ((rot->XCOORD>(xcoo+radi) )&& (rot->YCOORD<= (ycoo-radi))){  //8
        return "nw";
    }
    else if( !( ( pow(((rot->XCOORD)-xcoo),2) + pow(((rot->YCOORD)-ycoo),2) )<= pow(radi,2))  &&
            ( (  rot->XCOORD <= (xcoo+radi) &&  rot->XCOORD>xcoo) && ( rot->YCOORD <= (ycoo+radi) &&  rot->YCOORD>ycoo)) ){ //10
        return"se,sw,nw";
        
    }
    else if( !( (pow(((rot->XCOORD)-xcoo),2) + pow(((rot->YCOORD)-ycoo),2)) <= pow(radi,2))  &&
            ( ( rot->XCOORD< xcoo   && rot->XCOORD>(xcoo-radi)) &&   (   rot->YCOORD <= (ycoo+radi)    && rot->YCOORD>ycoo))   ){  //9
        return"se,sw,ne";
        
    }
   else if(  !( (pow(((rot->XCOORD)-xcoo),2) + pow(((rot->YCOORD)-ycoo),2)) <= pow(radi,2))  &&
           ( (rot->XCOORD < xcoo  &&  rot->XCOORD>(xcoo-radi)) && (rot->YCOORD <ycoo && rot->YCOORD>(ycoo-radi)))   ){ //11
       return "se,ne,nw";
    }
   else if(!( (pow(((rot->XCOORD)-xcoo),2) + pow(((rot->YCOORD)-ycoo),2)) <= pow(radi,2))  &&
         ( ( rot->XCOORD <=(xcoo+radi)  &&  rot->XCOORD>xcoo) &&   (rot->YCOORD < ycoo  && rot->YCOORD>(ycoo-radi)))  ){ //12
       return"sw,ne,nw";
   }
    
   else
       return "no";
   
}







void quadtree::search(const int & xco, const int &yco , const int& rad,vector<string>&f,vector<string>&ontw, node * &r){
    
    if(r!=NULL)
	{
		if(pow(((r->XCOORD)-xco),2) + pow(((r->YCOORD)-yco),2) <= pow(rad,2))
		{
        f.push_back(r->cname);
   
		}
        ontw.push_back(r->cname);
    }
  

    if( r!=NULL && findquadrant(xco,yco,rad,r)== "All"){
        search(xco,yco,rad,f,ontw,r->se);
        search(xco,yco,rad,f,ontw,r->sw);
        search(xco,yco,rad,f,ontw,r->ne);
        search(xco,yco,rad,f,ontw,r->nw);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "se,sw"){
        search(xco,yco,rad,f,ontw,r->se);
        search(xco,yco,rad,f,ontw,r->sw);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "se"){
        search(xco,yco,rad,f,ontw,r->se);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "sw"){
        search(xco,yco,rad,f,ontw,r->sw);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "se,ne"){
        search(xco,yco,rad,f,ontw,r->se);
        search(xco,yco,rad,f,ontw,r->ne);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "sw,nw"){
        search(xco,yco,rad,f,ontw,r->sw);
        search(xco,yco,rad,f,ontw,r->nw);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "ne"){
        search(xco,yco,rad,f,ontw,r->ne);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "ne,nw"){
        search(xco,yco,rad,f,ontw,r->ne);
        search(xco,yco,rad,f,ontw,r->nw);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "nw"){
        search(xco,yco,rad,f,ontw,r->nw);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "se,sw,nw"){
        search(xco,yco,rad,f,ontw,r->se);
        search(xco,yco,rad,f,ontw,r->sw);
        search(xco,yco,rad,f,ontw,r->nw);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "se,sw,ne"){
        search(xco,yco,rad,f,ontw,r->se);
        search(xco,yco,rad,f,ontw,r->sw);
        search(xco,yco,rad,f,ontw,r->ne);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "se,ne,nw"){
        search(xco,yco,rad,f,ontw,r->se);
        search(xco,yco,rad,f,ontw,r->ne);
        search(xco,yco,rad,f,ontw,r->nw);
    }
    else if( r!=NULL &&findquadrant(xco,yco,rad,r)== "sw,ne,nw"){
        search(xco,yco,rad,f,ontw,r->sw);
        search(xco,yco,rad,f,ontw,r->ne);
        search(xco,yco,rad,f,ontw,r->nw);
    }
    
    
    
}







void  quadtree::searchp(const int &xco,const  int &yco, const int &rad,vector<string>&f,vector<string>&ontw) {
     search( xco,yco, rad ,f,ontw, root);
}
