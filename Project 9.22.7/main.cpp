//
//  main.cpp
//  Project 9.22.7
//
//  Created by Pradnya Kadam on 7/9/25.
//

#include <iostream>
#include <vector>

using namespace std;

//CashRegister class implementation
class CashRegister
{
public:
   void clear();
   void add_item(double price);

   int get_total() const;
   int get_count() const;
   void display_all();

private:
    vector<double> price_list;
};


void CashRegister::clear()
{
    //loops through vector and removes all items/prices from it
    while(!price_list.empty())
    {
        price_list.pop_back();
    }
    
}

//adds new item price to end of vector
void CashRegister::add_item(double price)
{
    price_list.push_back(price);
}

//reimplemented this function to store cost as an integer
int CashRegister::get_total() const
{
    double cost = 0;
    
    for(int j = 0; j < price_list.size(); j++)
    {
        cost += price_list[j];
    }
    
    return cost*100;
}

int CashRegister::get_count() const
{
    return price_list.size();
}

void CashRegister::display_all()
{
    for(int k = 0; k < price_list.size(); k++)
    {
        cout << "Item " << k + 1 << ": $" << price_list[k] << endl;
    }
}



int main(int argc, const char * argv[]) {
    CashRegister c1;
    
    c1.add_item(2.00);
    c1.add_item(5.00);
    c1.add_item(3.00);
    
    cout << "You have " << c1.get_count() << " items in your cart!" << endl;
    cout << endl;
    
    cout << "Here are all the prices of the items:" << endl;
    c1.display_all();
    cout << endl;
    
    cout << "The total price is: " << c1.get_total() << " cents" << endl;
    
    c1.clear();
    cout << "You now have " << c1.get_count() << " items in your cart. You owe " << c1.get_total() << " cents" << endl;
    
    return 0;
}
