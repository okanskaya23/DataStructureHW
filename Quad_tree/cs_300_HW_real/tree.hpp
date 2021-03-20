//
//  tree.hpp
//  cs 300 hw2
//
//  Created by Okan Sarp Kaya on 20.11.2020.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <string>
using namespace std;
struct line
{
    double x1,y1,x2,y2;
    
};
struct node
{
    double x_cor;
    double y_cor;
    string name;
    line north_line;
    line west_line;
    line south_line;
    line east_line;
    node *SE;
    node *SW;
    node *NE;
    node *NW;
    
};

class tree{
private:
     node * root;
public:
    tree();
    ~tree();
    void insert(string name, double x , double y , node *ptr);
    void insert (double x_cor , double y_cor , string name , double x_cor_of_upper_righ , double y_cor_of_upper_righ);
    void deconstract(node * ptr);
    void search(int centerx , int centery , double radius, node *ptr);
    void search2(double centerx , double centery , double radius, node *ptr , string & path);
    node * root_taker();
    

    
};

#endif /* tree_hpp */
