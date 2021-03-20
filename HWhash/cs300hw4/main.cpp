//
//  main.cpp
//  cs300hw4
//
//  Created by Okan Sarp Kaya on 22.12.2020.
//
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


//define file name here
#define filename "inputs1.txt"






using namespace std;
unordered_map<int, string> city_p(){
    unordered_map<int, string> jfk;
    ifstream input;
    input.open(filename);
    string line;
    getline(input,line);
    stringstream city_line(line);
    string temp;
    int hola=0;
    while(city_line>>temp)
    {
        jfk[hola]=temp;
        hola++;
    }
    input.close();
    return jfk;
}
unordered_map<string, int> cityr_p(){
    unordered_map<string, int> jfk;
    ifstream input;
    input.open(filename);
    string line;
    getline(input,line);
    stringstream city_line(line);
    string temp;
    int hola=0;
    while(city_line>>temp)
    {
        jfk[temp]=hola;
        hola++;
    }
    input.close();
    return jfk;
}
class BST {
    
    struct node {
        int data;
        string block;
        node* left;
        node* right;
    };
    node* root;
    unordered_map<string, int> cityrp = cityr_p();
    unordered_map<int, string> cityp = city_p();
    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    node* insert(int x,string block, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->block = block;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x,block, t->left);
        else if(x > t->data)
            t->right = insert(x, block,t->right);

        else if(x == t->data && cityrp[block] > cityrp[t->block])
            t->right = insert(x,block, t->right);
        else if(x == t->data && cityrp[block] < cityrp[t->block])
            t->left = insert(x, block,t->left);
        return t;
    }
    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    node* remove(int x,string block ,node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x,block ,t->left);
        else if(x > t->data)
            t->right = remove(x, block,t->right);
        
        else if(x == t->data && cityrp[block] < cityrp[t->block])
        {
            t->left = remove(x,block ,t->left);
        }
        else if(x == t->data && cityrp[block] > cityrp[t->block])
        {
            t->right = remove(x, block,t->right);
        }

        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->block =block;
            t->right = remove(t->data, block,t->right);
        }
        else if (x == t->data && cityrp[block] == cityrp[t->block])
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }
    node* find(node* t, int x,string block) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x,block);
        else if(x > t->data)
            return find(t->right, x , block);
        
        else if(x == t->data && cityrp[block] < cityrp[t->block] )
        {
            return find(t->right, x, block );
        }
        else if(x == t->data && cityrp[block] > cityrp[t->block] )
            return find(t->left, x , block);
        else
            return t;
    }
public:
    BST() {
        root = NULL;
    }
    ~BST() {
        root = makeEmpty(root);
    }
    void insert(int x,string block) {
        root = insert(x, block,root);
    }
    void remove(int x,string block) {
        root = remove(x, block ,root);
    }
    void search(int x, string block) {
        root = find(root, x,block);
    }
    node* findm()
    {
        node *t = root;
        if(t == NULL)
        {
            node x;
            x.block=cityp[0];
            x.data=0;
            node* tt = &x;
            return tt;
        }
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
};

string itoa(int n)
{
    ostringstream output;
    output << n;
    return output.str();
}

struct data1{
    unordered_map<string,int> ptr;
    int val;
    string block;
    
};

void file(vector<string> & row_name, vector<string> & city, int & num ,ifstream & input, unordered_map<string, vector<data1>> & rows ,unordered_map<string, int> & set,unordered_map<string, BST> & forest)
{
    input.open(filename);
    string line;
    getline(input,line);
    stringstream city_line(line);
    string temp;
    int hola=0;
    while(city_line>>temp)
    {
        set[temp] =hola;
        hola++;
        city.push_back(temp);
        
    }
    getline(input,line);
    stringstream row(line);

    getline(input,line);
    stringstream n(line);
    n>>num;
    while(row>>temp)
    {
        row_name.push_back(temp);
        vector<data1> vec;
        forest[temp];
        for (int i = 0 ; i <city.size() ; i++ )
        {
            data1 tt;
            tt.block=city[i];
            tt.val=0;
            tt.ptr = set;
            vec.push_back(tt);
            forest[temp].insert(0, city[i]);
        }
        rows[temp]=vec;
    }
    
}

struct no{
    bool reserve;
    string block;
    string row;
    string num;
    bool get=false;
};
struct Comp
{
   bool operator()( data1 & a, data1 & b)
   {
       if(  a.val == b.val)
           return a.ptr[a.block] > b.ptr[b.block];
       return a.val < b.val;
   }
};
int main()
{
    ofstream out;
    out.open("output.txt");
    unordered_map<string, BST> forest;
    unordered_map<string,no> reservation;
    unordered_map<string,string> stad;
    unordered_map<string,vector<data1>> rows;
    unordered_map<string, int> set;
    vector<string> row_name;
    vector<string> city;
    int len;
    ifstream input;
    file(row_name,city,len,input,rows,set,forest);
    string line,func_name,name,row,city_name,seat_num;
    while(getline(input,line))
    {
        stringstream x(line);
        x>>func_name>>name>>city_name>>row>>seat_num;
        if(func_name == "reserve_seat")
        {
            if(reservation.find(name) == reservation.end() && stad.find(city_name + row + seat_num) == stad.end() )
            {
                reservation[name].reserve=true;
                reservation[name].row=row;
                reservation[name].num=seat_num;
                reservation[name].block=city_name;
                stad[reservation[name].block+row+seat_num]=name;
                out<< name<<" has reserved "<<city_name<<" "<<row<<"-"<<seat_num<<endl;
                int j = rows[row][set[city_name]].val;
                forest[row].remove( j,city_name);
                j++;
                forest[row].insert(j,city_name);
                rows[row][set[city_name]].val++;
                
            }
            else
            {
                out<< name<<" could not reserve a seat!"<<endl;
            }
        }
        else if (func_name == "print")
        {
            string temp;
            for(int i = 0 ; i < city.size() ; i++)
            {
                out<<endl<<city[i]<<endl<<"~~~~~~~"<<endl;
                for(int j = 0 ; j < row_name.size() ; j++)
                {
                    out<<row_name[j]<<" : ";
                    for(int k = 0 ; k < len ; k++)
                    {
                        temp = itoa(k);
                        if(stad.find(city[i]+row_name[j]+temp) != stad.end())
                        {
                            out<<stad[city[i]+row_name[j]+temp].substr(0,3)<<" ";
                        }
                        else
                        {
                            out<<"---"<<" ";
                        }
                        
                    }
                    out<<endl;
                }
                out<<"======="<<endl;
            }

            out<<endl;
        }
        else if (func_name == "cancel_reservation")
        {
            if(reservation.find(name) != reservation.end())
            {
                int j = rows[reservation[name].row][set[reservation[name].block]].val;
                forest[reservation[name].row].remove(j,reservation[name].block);
                j--;
                forest[reservation[name].row].insert(j,reservation[name].block);
                rows[reservation[name].row][set[reservation[name].block]].val--;
                stad.erase(reservation[name].block + reservation[name].row + reservation[name].num);
                reservation.erase(name);
                out<<"Cancelled the reservation of "<<name<<endl;
            }
            else
            {
                out<<"Could not cancel the reservation for "<<name<<"; no reservation found!"<<endl;
            }
        }
        else if (func_name == "get_seat")
        {
            if(reservation.find(name) != reservation.end())
            {
                stad[reservation[name].block+row+seat_num]=name;
                reservation[name].get=true;
                out<<"Found that "<<name<<" has a reservation in "<<reservation[name].block<<" "<<reservation[name].row<<"-"<<reservation[name].num<<endl;
            }
            else
            {
                out<<"There is no reservation made for "<<name<<"!"<<endl;
            }
        }
        else if (func_name == "reserve_seat_by_row")
        {
            
            
            vector<int> x;
            if(reservation.find(name) == reservation.end())
            {
                int minval =forest[city_name].findm()->data;
                string minname =forest[city_name].findm()->block;
                forest[city_name].remove(minval,minname);
                int yp =minval;
                forest[city_name].insert(++yp,minname);

                for(int i = 0 ;i < len ; i++)
                {
                    if(stad.find(minname + city_name + itoa(i)) == stad.end())
                    {
                        stad[minname + city_name + itoa(i)] = name;
                        out<<name<<" has reserved "<<minname<<" "<< city_name <<"-"<<itoa(i)<<" by emptiest block"<<endl;
                        reservation[name].reserve=true;
                        reservation[name].row=city_name;
                        reservation[name].num=itoa(i);
                        reservation[name].block=minname;
                        rows[city_name][set[minname]].val++;
                        i=len+1;
                    }
                    else if(i == len-1)
                        out<<name<<" could not reserve a seat!"<<endl;
                }
            }
            else
            {
                out<< name<<" could not reserve a seat!"<<endl;
            }
        }
        func_name="null";
    }

    return 0;
}
