//
//  main.cpp
//  cs 300 hw2
//
//  Created by Okan Sarp Kaya on 19.11.2020.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "tree.hpp"
using namespace std;



void pretty_print (node * root)
{
    if(root != nullptr )
    {
        cout<<root->name<<endl;
        pretty_print(root->SE); // recursively print
        pretty_print(root->SW); // recursively print
        pretty_print(root->NE); // recursively print
        pretty_print(root->NW); // recursively print
    
    }
}



int main(){
    ifstream cities ;
    cities.open("cities.txt");
    string line;
    double x_cor_of_upper_righ, y_cor_of_upper_righ;
    getline(cities,line);
    stringstream cord_of_plane(line);
    cord_of_plane >> x_cor_of_upper_righ >> y_cor_of_upper_righ;
    
    tree tree;
    while(getline(cities,line)){
        double x, y;
        string  city_name;
        stringstream cordinates(line);
        cordinates >> city_name >> x >> y;
//        cout<<endl<<"------------"<<city_name<<" "<<x<<" "<<y<<endl;
        tree.insert( x, y, city_name , x_cor_of_upper_righ , y_cor_of_upper_righ);
        
    }
    pretty_print(tree.root_taker());
    cout<<endl<<"*****************"<<endl<<endl<<endl;
    ifstream queries ;
    queries.open("queries7.txt");
    string line2;
    double x_cord, y_cord;
    double rad;
    string em,em1;
    cout<<"search part: "<<endl<<"------------------"<<endl;
    while(getline(queries,line2))
    {
        stringstream circels(line2);
        circels >> x_cord >>em>> y_cord >>em1>> rad;
//        tree.search(x_cord , y_cord, rad , tree.root_taker());
        string path = tree.root_taker()->name + " ";
        tree.search2(x_cord , y_cord, rad , tree.root_taker(),path);
        cout<<endl<<path<<endl;
        cout<<endl<<"---------------"<<endl;
//        cout<<x_cord<<" "<<y_cord<<" "<<rad<<endl;
    }
    return 0;
}

