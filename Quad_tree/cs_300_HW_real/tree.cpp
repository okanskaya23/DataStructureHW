//
//  tree.cpp
//  cs 300 hw2
//
//  Created by Okan Sarp Kaya on 20.11.2020.
//

#include "tree.hpp"
#include <cstdlib>
#include <cmath>
#include <iostream>


using namespace std;

bool intrsect(double ax, double ay, double bx, double by, double cx, double cy, double r)
{
    

double lx = bx-ax;
    double ly = by-ay;
    

    double kx = ax-cx;
    double ky = ay-cy;
    
    
    double a = lx*lx + ly*ly;
    double b = 2*(kx*lx + ky*ly);
    double c = kx*kx + ky*ky - r*r;
    

    double disc = b*b - 4*a*c;
    

    if (disc<0)
        return false;
    else
    {
        disc = sqrt(disc);
        double p1 = (-b - disc)/(2*a);
        double p2 = (-b + disc)/(2*a);
        
        if (p1>=0 && p1<=1)
            return true;
        else if (p2>=0 && p2<=1)
            return true;
        else
            return false;
    }
}



//it is a fuction that control given point in the given circle or not
bool is_in_circle(int center_x, int center_y, int x2, int y2, double radius)
{
    double distance= (sqrt(pow(x2 - center_x, 2) + pow(y2 - center_y, 2) * 1.0));
    
    if(distance < radius)
        return  true;
    else
        return false;
}




//funtion calculate points direction to another point
string where(int x2 ,  int y2 , int x0 , int y0)
{
    if(x2 < x0 && y2 < y0)
    {
        return "NE";
    }
    else if(x2 > x0 && y2 > y0)
    {
        return "SW";
    }
    else if (x2 < x0 && y2 > y0)
    {
        return "SE";
    }
    else if((x2 > x0 && y2 < y0))
    {
        return "NW";
    }

    else if((x2 > x0 && y2 == y0))
    {
        return "NW";
    }
    else if (x2 < x0 && y2 == y0)
    {
        return "NE";
    }
    else if (x2 == x0 && y2 > y0)
    {
        return "SE";
    }
    else if((x2 == x0 && y2 < y0))
    {
        return "NE";
    }
    else
    {
        return "problem";
    }
}



tree::tree()
{
    root = nullptr;
}



void tree::insert(string name, double x , double y , node *ptr)
{
    
    if(where(ptr->x_cor , ptr ->y_cor , x,y ) == "NE")
    {
        if(ptr->NE != nullptr)
        {
            insert(name, x , y , ptr->NE);
        }
        else
        {
//        checked 1 2 3 4 5 6
            ptr->NE = new node;
            ptr->NE->name = name;
            
            ptr->NE->x_cor = x;
            ptr->NE->y_cor = y;
            
            
            ptr->NE->east_line.x1 = x;
            ptr->NE->east_line.y1 = y;
            
            ptr->NE->west_line.x1 = x;
            ptr->NE->west_line.y1 =y;
            
            ptr->NE->south_line.x1 =x;
            ptr->NE->south_line.y1 =y;
            
            ptr->NE->north_line.x1 =x;
            ptr->NE->north_line.y1 =y;
            
            
            ptr->NE->east_line.x2 = ptr->east_line.x2;
            ptr->NE->east_line.y2 = y;
            
            ptr->NE->west_line.x2 = ptr->east_line.x1;
            ptr->NE->west_line.y2 = y;
            
            ptr->NE->south_line.x2 = x;
            ptr->NE->south_line.y2 = ptr->east_line.y1;
            
            ptr->NE->north_line.x2 = x;
            ptr->NE->north_line.y2 = ptr->north_line.y2;
            
            
            
            ptr->NE->NE = nullptr;
            ptr->NE->NW = nullptr;
            ptr->NE->SE = nullptr;
            ptr->NE->SW = nullptr;
            
            
            
        }
    }
    else if(where(ptr->x_cor , ptr ->y_cor , x,y ) == "NW")
    {
        if(ptr->NW != nullptr)
        {
            insert(name, x , y , ptr->NW);
        }
        else
        {
            //        checked
            ptr->NW = new node;
            ptr->NW->name = name;
            ptr->NW->x_cor = x;
            ptr->NW->y_cor = y;
            
            ptr->NW->east_line.x1 = x;
            ptr->NW->east_line.y1 = y;
            
            ptr->NW->west_line.x1 = x;
            ptr->NW->west_line.y1 =y;
            
            ptr->NW->south_line.x1 =x;
            ptr->NW->south_line.y1 =y;
            
            ptr->NW->north_line.x1 =x;
            ptr->NW->north_line.y1 =y;
            
            
            ptr->NW->east_line.x2 = ptr->east_line.x1;
            ptr->NW->east_line.y2 = y;
            
            ptr->NW->west_line.x2 = ptr->west_line.x2;
            ptr->NW->west_line.y2 = y;
            
            ptr->NW->south_line.x2 = x;
            ptr->NW->south_line.y2 = ptr->east_line.y1;
            
            ptr->NW->north_line.x2 = x;
            ptr->NW->north_line.y2 = ptr->north_line.y2;
            
            
            ptr->NW->NE = nullptr;
            ptr->NW->NW = nullptr;
            ptr->NW->SE = nullptr;
            ptr->NW->SW = nullptr;
        }
    }
    else if(where(ptr->x_cor , ptr ->y_cor , x,y ) == "SE")
    {
        if(ptr->SE != nullptr)
        {
            insert(name, x , y , ptr->SE);
        }
        else
        {
            //        checked
            ptr->SE = new node;
            ptr->SE->name = name;
            ptr->SE->x_cor = x;
            ptr->SE->y_cor = y;
            
            ptr->SE->east_line.x1 = x;
            ptr->SE->east_line.y1 = y;
            
            ptr->SE->west_line.x1 = x;
            ptr->SE->west_line.y1 =y;
            
            ptr->SE->south_line.x1 =x;
            ptr->SE->south_line.y1 =y;
            
            ptr->SE->north_line.x1 =x;
            ptr->SE->north_line.y1 =y;
            
            
            ptr->SE->east_line.x2 = ptr->east_line.x2;
            ptr->SE->east_line.y2 = y;
            
            ptr->SE->west_line.x2 = ptr->west_line.x1;
            ptr->SE->west_line.y2 = y;
            
            ptr->SE->south_line.x2 = x;
            ptr->SE->south_line.y2 = ptr->south_line.y2;
            
            ptr->SE->north_line.x2 = x;
            ptr->SE->north_line.y2 = ptr->north_line.y1;
            
            
            ptr->SE->NE = nullptr;
            ptr->SE->NW = nullptr;
            ptr->SE->SE = nullptr;
            ptr->SE->SW = nullptr;
            
        }
    }
    else if(where(ptr->x_cor , ptr ->y_cor , x,y ) == "SW")
    {
        if(ptr->SW != nullptr)
        {
            insert(name, x , y , ptr->SW);
        }
        else
        {
            //        checked
            ptr->SW = new node;
            ptr->SW->name = name;
            ptr->SW->x_cor = x;
            ptr->SW->y_cor = y;
            
            ptr->SW->east_line.x1 = x;
            ptr->SW->east_line.y1 = y;
            
            ptr->SW->west_line.x1 = x;
            ptr->SW->west_line.y1 =y;
            
            ptr->SW->south_line.x1 =x;
            ptr->SW->south_line.y1 =y;
            
            ptr->SW->north_line.x1 =x;
            ptr->SW->north_line.y1 =y;
            
            
            ptr->SW->east_line.x2 = ptr->east_line.x1;
            ptr->SW->east_line.y2 = y;
            
            ptr->SW->west_line.x2 = ptr->west_line.x2;
            ptr->SW->west_line.y2 = y;
            
            ptr->SW->south_line.x2 = x;
            ptr->SW->south_line.y2 = ptr->south_line.y2;
            
            ptr->SW->north_line.x2 = x;
            ptr->SW->north_line.y2 = ptr->north_line.y1;
            
            
            ptr->SW->NE = nullptr;
            ptr->SW->NW = nullptr;
            ptr->SW->SE = nullptr;
            ptr->SW->SW = nullptr;
        }
    }
    else if (where(ptr->x_cor , ptr ->y_cor , x,y ) == "problem")
    {
        cout<<"problem came to insert function"<<endl;
        exit(1);
        
    }
    
}

void tree::insert(double x_cor , double y_cor , string name , double x_cor_of_upper_righ , double y_cor_of_upper_righ)
{
    if(x_cor > x_cor_of_upper_righ || x_cor < 0 || y_cor > y_cor_of_upper_righ || y_cor < 0 )
    {
//        cout<<"cordinat not in the given plane "<<endl;
//        exit(0);
        return;
    }
    if(root != nullptr)
    {
        insert(name, x_cor , y_cor ,root);
    }
    else
    {
        root = new node;
        root->name = name;
        root->x_cor = x_cor;
        root->y_cor = y_cor;
        
        root->north_line.x1 = x_cor;
        root->north_line.y1 = y_cor;
        
        root->east_line.x1 = x_cor;
        root->east_line.y1 = y_cor;
        
        root->south_line.x1 = x_cor;
        root->south_line.y1 = y_cor;
        
        root->west_line.x1 = x_cor;
        root->west_line.y1 = y_cor;
        
        
        
        root->north_line.x2 = x_cor;
        root->north_line.y2 = y_cor_of_upper_righ;
        
        root->east_line.x2 = x_cor_of_upper_righ;
        root->east_line.y2 = y_cor;
        
        root->south_line.x2 = x_cor;
        root->south_line.y2 = 0;
        
        root->west_line.x2 = 0;
        root->west_line.y2 = y_cor;
        
        
        root->NE = nullptr;
        root->NW = nullptr;
        root->SE = nullptr;
        root->SW = nullptr;
    }
}
void tree::deconstract(node *ptr)
{
    if(ptr != nullptr){
        deconstract(ptr->NE);
        deconstract(ptr->NW);
        deconstract(ptr->SE);
        deconstract(ptr->SW);
        delete ptr;
    }
}
void tree::search(int centerx, int centery, double radius, node * ptr)
{
    if(ptr!=nullptr)
    {
        if(is_in_circle(ptr->x_cor , ptr->y_cor , centerx, centery, radius))
            cout<<ptr->name<<" ";
        if(ptr->SE != nullptr)
            search(centerx , centery , radius , ptr->SE);
        if(ptr->SW != nullptr)
            search(centerx , centery , radius , ptr->SW);
        if(ptr->NE != nullptr)
            search(centerx , centery , radius , ptr->NE);
        if(ptr->NW != nullptr)
            search(centerx , centery , radius , ptr->NW);

    }
}
void tree::search2(double centerx , double centery , double radius, node *ptr ,string & path)
{
    if(ptr != nullptr)
    {
        bool east = intrsect(ptr->east_line.x1, ptr->east_line.y1 ,ptr->east_line.x2, ptr->east_line.y2, centerx,centery,radius);
//        if(!east)
//            cout<<"here"<<endl;
        bool west = intrsect(ptr->west_line.x1, ptr->west_line.y1 ,ptr->west_line.x2, ptr->west_line.y2, centerx,centery,radius);
        bool north = intrsect(ptr->north_line.x1, ptr->north_line.y1 ,ptr->north_line.x2, ptr->north_line.y2, centerx,centery,radius);
        bool south = intrsect(ptr->south_line.x1, ptr->south_line.y1 ,ptr->south_line.x2, ptr->south_line.y2, centerx,centery,radius);
//        if(is_in_circle(ptr->x_cor , ptr->y_cor , centerx, centery, radius))
        if(is_in_circle(centerx , centery , ptr->x_cor, ptr->y_cor, radius))
        {
            cout<<ptr->name<<" ";
            if(ptr ->SE != nullptr)
            {
                path = path + ptr->SE->name + " ";
                search2(centerx , centery , radius , ptr ->SE , path );
            }
            if(ptr ->SW != nullptr)
            {
                path = path + ptr->SW->name + " ";
                search2(centerx , centery , radius , ptr ->SW, path);
            }
            if(ptr->NE != nullptr)
            {
                path = path + ptr->NE->name + " ";
                search2(centerx , centery , radius , ptr ->NE, path);
            }
            if(ptr ->NW != nullptr)
            {
                path = path + ptr->NW->name + " ";
                search2(centerx , centery , radius , ptr ->NW, path);
            }
        }
        else if(!east && !west && !south && !north)
        {
            string loc=where(ptr->x_cor, ptr-> y_cor, centerx, centery);
            if(loc == "SE")
            {
                if(ptr ->SE != nullptr)
                {
                    path = path + ptr->SE->name + " ";
                    search2(centerx , centery , radius , ptr ->SE , path );
                }
            }
            else if(loc == "SW")
            {
                if(ptr ->SW != nullptr)
                {
                    path = path + ptr->SW->name + " ";
                    search2(centerx , centery , radius , ptr ->SW, path);
                }
            }
            else if(loc == "NE")
            {
                if(ptr ->NE != nullptr)
                {
                    path = path + ptr->NE->name + " ";
                    search2(centerx , centery , radius , ptr ->NE, path);
                }
            }
            else if(loc == "NW")
            {
                if(ptr ->NW != nullptr)
                {
                    path = path + ptr->NW->name + " ";
                    search2(centerx , centery , radius , ptr ->NW, path);
                }
            }
            else if (loc == "problem")
            {
                cout<<"problem came to search 2 parts no intersection condition"<<endl;
                exit(26);
            }
        }
        else if(east && !west && !south && !north)
        {
            if(ptr ->SE != nullptr)
            {
                path = path + ptr->SE->name + " ";
                search2(centerx , centery , radius , ptr ->SE , path );
            }
            if(ptr->NE != nullptr)
            {
                path = path + ptr->NE->name + " ";
                search2(centerx , centery , radius , ptr ->NE, path);
            }
        }
        else if(!east && west && !south && !north)
        {
            if(ptr ->SW != nullptr)
            {
                path = path + ptr->SW->name + " ";
                search2(centerx , centery , radius , ptr ->SW, path);
            }
            if(ptr ->NW != nullptr)
            {
                path = path + ptr->NW->name + " ";
                search2(centerx , centery , radius , ptr ->NW, path);
            }
        }
        else if(!east && !west && south && !north)
        {
            if(ptr ->SE != nullptr)
            {
                path = path + ptr->SE->name + " ";
                search2(centerx , centery , radius , ptr ->SE , path );
            }
            if(ptr ->SW != nullptr)
            {
                path = path + ptr->SW->name + " ";
                search2(centerx , centery , radius , ptr ->SW, path);
            }
        }
        else if(!east && !west && !south && north)
        {
            if(ptr ->NE != nullptr)
            {
                path = path + ptr->NE->name + " ";
                search2(centerx , centery , radius , ptr ->NE , path );
            }
            if(ptr->NW != nullptr)
            {
                path = path + ptr->NW->name + " ";
                search2(centerx , centery , radius , ptr ->NW, path);
            }
        }
        else if(east && !west && !south && north)
        {
            if(ptr ->SE != nullptr)
            {
                path = path + ptr->SE->name + " ";
                search2(centerx , centery , radius , ptr ->SE , path );
            }
            if(ptr->NE != nullptr)
            {
                path = path + ptr->NE->name + " ";
                search2(centerx , centery , radius , ptr ->NE, path);
            }
            if(ptr ->NW != nullptr)
            {
                path = path + ptr->NW->name + " ";
                search2(centerx , centery , radius , ptr ->NW, path);
            }
            
        }
        else if(!east && west && !south && north)
        {
            if(ptr ->SW != nullptr)
            {
                path = path + ptr->SW->name + " ";
                search2(centerx , centery , radius , ptr ->SW, path);
            }
            if(ptr->NE != nullptr)
            {
                path = path + ptr->NE->name + " ";
                search2(centerx , centery , radius , ptr ->NE, path);
            }
            if(ptr ->NW != nullptr)
            {
                path = path + ptr->NW->name + " ";
                search2(centerx , centery , radius , ptr ->NW, path);
            }

        }
        else if(east && !west && south && !north)
        {
            if(ptr ->SE != nullptr)
            {
                path = path + ptr->SE->name + " ";
                search2(centerx , centery , radius , ptr ->SE , path );
            }
            if(ptr ->SW != nullptr)
            {
                path = path + ptr->SW->name + " ";
                search2(centerx , centery , radius , ptr ->SW, path);
            }
            if(ptr->NE != nullptr)
            {
                path = path + ptr->NE->name + " ";
                search2(centerx , centery , radius , ptr ->NE, path);
            }
        }
        else if(!east && west && south && !north)
        {
            if(ptr ->SE != nullptr)
            {
                path = path + ptr->SE->name + " ";
                search2(centerx , centery , radius , ptr ->SE , path );
            }
            if(ptr ->SW != nullptr)
            {
                path = path + ptr->SW->name + " ";
                search2(centerx , centery , radius , ptr ->SW, path);
            }
            if(ptr ->NW != nullptr)
            {
                path = path + ptr->NW->name + " ";
                search2(centerx , centery , radius , ptr ->NW, path);
            }

        }
//        else if((east && west && !south && !north) || (!east && !west && south && north  ))
//        {
//            cout<<"imposible intersection debug it"<<endl;
//            exit(13);
//        }
        else
        {
            if(ptr ->SE != nullptr)
            {
                path = path + ptr->SE->name + " ";
                search2(centerx , centery , radius , ptr ->SE , path );
            }
            if(ptr ->SW != nullptr)
            {
                path = path + ptr->SW->name + " ";
                search2(centerx , centery , radius , ptr ->SW, path);
            }
            if(ptr->NE != nullptr)
            {
                path = path + ptr->NE->name + " ";
                search2(centerx , centery , radius , ptr ->NE, path);
            }
            if(ptr ->NW != nullptr)
            {
                path = path + ptr->NW->name + " ";
                search2(centerx , centery , radius , ptr ->NW, path);
            }


        }
        
        
        
        
    }
}
node * tree:: root_taker()
{
    return root;
}

tree::~tree()
{
    deconstract(root);
}

//string where(int x0 ,  int y0 , int x2 , int y2)
//{
//    if(x0 < x2 && y0 < y2)
//    {
//        return "NE";
//    }
//    else if(x0 > x2 && y0 > y2)
//    {
//        return "SW";
//    }
//    else if (x0 < x2 && y0 > y2)
//    {
//        return "SE";
//    }
//    else if((x0 > x2 && y0 < y2))
//    {
//        return "NW";
//    }
//    else if((x0 == x2 && y0 <= y2))
//    {
//        return "SE";
//    }
//    else if((x0 >= x2 && y0 == y2))
//    {
//        return "NE";
//    }
//    else if (x0 <= x2 && y0 == y2)
//    {
//        return "NW";
//    }
//    else if (x0 == x2 && y0 >= y2)
//    {
//        return "NE";
//    }
//
//    //    look afte office hour*******************
//    else
//    {
//        return "problem";
//    }
//}
//string where(int x0 ,  int y0 , int x2 , int y2)
//{
//    if(x0 < x2 && y0 < y2)
//    {
//        return "NE";
//    }
//    else if(x0 > x2 && y0 > y2)
//    {
//        return "SW";
//    }
//    else if (x0 < x2 && y0 > y2)
//    {
//        return "SE";
//    }
//    else if((x0 > x2 && y0 < y2))
//    {
//        return "NW";
//    }
//
//    else if((x0 > x2 && y0 == y2))
//    {
//        return "NE";
//    }
//    else if (x0 < x2 && y0 == y2)
//    {
//        return "NW";
//    }
//    else if (x0 == x2 && y0 > y2)
//    {
//        return "NE";
//    }
//    else if((x0 == x2 && y0 < y2))
//    {
//        return "SE";
//    }
//
//    //    look afte office hour*******************
//    else
//    {
//        return "problem";
//    }
//}
