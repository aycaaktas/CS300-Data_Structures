#include <iostream>
#include<fstream>
#include<sstream>
#include "quadtree.hpp"



using namespace std;



int main() {


    ifstream in;

    string fName="cities.txt";

    in.open(fName.c_str());
    string line,linet;
    string cn;
    int xc,yc;
    quadtree quad;
    getline(in,linet);
    while(!in.eof())
    {
        getline(in, line);
        stringstream ss(line);
        ss>>cn>>xc>>yc;
        quad.insertp(xc,yc,cn);

    }
    quad.prettyprint();
    
    

    cout<<endl<<endl;
    
    in.clear();
    in.close();
    
	ifstream input;
    string filename="queries.txt";

    input.open(filename.c_str());
	string lines;
     int radius;
     int xco,yco;
	 string v1,v2;
   
 
   
    while(!input.eof())
    {
		
        vector<string>found;
        vector<string>ontheway;
        getline(input, lines);
        stringstream sss(lines);
        sss>>xco>>v1>>yco>>v2>>radius;
        quad.searchp(xco,yco,radius,found,ontheway);
        
        if(found.empty()){
            cout<<"<None>"<<endl;
        }
        else{
            for(int i=0;i<found.size()-1;i++){
                cout<<found.at(i)<<",";
            }
            cout<<found.at(found.size()-1)<<endl;
        }
        
        for(int j=0;j<ontheway.size()-1;j++){
            cout<<ontheway.at(j)<<",";
        }
        cout<<ontheway.at(ontheway.size()-1)<<endl;
		cout<<endl<<endl;
    }

    
	
    return 0;
}


