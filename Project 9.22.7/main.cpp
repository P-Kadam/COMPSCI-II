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
    CashRegister(double tax);
    void clear();
    void add_item(double price);
    
    int get_total() const;
    int get_count() const;
    void display_all();
    
    //ADDED: 9.22.8
    void add_taxable_item(double price);
    double get_total_tax() const;
    
private:
    
    //vector contains ALL item prices
    vector<double> price_list;
    
    //vector contains taxable item prices
    vector<double> tax_price_list;
    
    int total_cost = 0;
    
    //ADDED: 9.22.8
    double tax_rate;
};


//ADDED: 9.22.8 - Constructor that assigns tax rate
CashRegister::CashRegister(double tax)
{
    tax_rate = tax;
}

//ADDED 9.22.8
double CashRegister::get_total_tax() const
{
    //stores the total tax amount
    double total_tax = 0;
    
    //iterates through taxable items vector and totals tax
    for(int k = 0; k < tax_price_list.size(); k++)
    {
        total_tax += tax_price_list[k]*tax_rate;
    }
    
    return total_tax*100;
    
}


//ADDED 9.22.8
void CashRegister::add_taxable_item(double price)
{
    //appends the new item to both the taxable items vector and total items vector
    tax_price_list.push_back(price);
    price_list.push_back(price);
    
    total_cost += price*100;
}

void CashRegister::clear()
{
    //loops through vector and removes all items/prices from it
    while(!price_list.empty())
    {
        price_list.pop_back();
        total_cost = 0;
    }
    
    while(!tax_price_list.empty())
    {
        tax_price_list.pop_back();
    }
    
}

//adds new item price to end of vector
void CashRegister::add_item(double price)
{
    price_list.push_back(price);
    total_cost += price*100;
}

//reimplemented this function to store cost as an integer
int CashRegister::get_total() const
{
    return total_cost + this->get_total_tax();
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
    CashRegister c1(0.1);
    
//    c1.add_item(2.00);
//    c1.add_item(5.00);
//    c1.add_item(3.00);
//    c1.add_item(3.32);
    c1.add_taxable_item(10);
    c1.add_taxable_item(10);
    
    
    cout << "You have " << c1.get_count() << " items in your cart!" << endl;
    cout << endl;
    
    cout << "Here are all the prices of the items:" << endl;
    c1.display_all();
    cout << endl;
    
    cout << "The total price is: " << c1.get_total() << " cents" << endl;
    
    cout << "The tax is: " << c1.get_total_tax() << " cents" << endl;
    
    c1.clear();
    cout << "You now have " << c1.get_count() << " items in your cart. You owe " << c1.get_total() << " cents" << endl;
    
    return 0;
}
