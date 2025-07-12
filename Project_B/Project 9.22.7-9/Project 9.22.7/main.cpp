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
    
    //ADDED: 9.22.9
    double get_sales_total() const;
    int get_sales_count() const;
    void reset_sales();
    
private:
    
    //vector contains ALL item prices
    vector<double> price_list;
    
    double total_cost = 0;
    
    //ADDED: 9.22.8
    double tax_rate;
    double total_tax;
    
    //ADDED: 9.22.9
    double total_amount_sales = 0;
    int sales = 0;
};



//ADDED: 9.22.8 - Constructor that assigns tax rate
CashRegister::CashRegister(double tax)
{
    tax_rate = tax;
}

//ADDED 9.22.8
double CashRegister::get_total_tax() const
{
    return total_tax*100;
}


//ADDED 9.22.8
void CashRegister::add_taxable_item(double price)
{
    double tax = price*tax_rate;
    
    double taxed_price = price + tax;
    
    //increases total cost and total tax
    total_cost += taxed_price;
    total_tax += tax;
    
    //adds the taxed price of item to the price_list vector
    price_list.push_back(taxed_price);
    
    //add taxed prince to total amount in sales
    total_amount_sales += taxed_price;
}

//ADDED: 9.22.9
double CashRegister::get_sales_total() const
{
    return total_amount_sales;
}

//ADDED: 9.22.9
int CashRegister::get_sales_count() const
{
    //Defining sale as anytime the clear() member function is called
    //As in each time the cost is payed and the total owed is 0.
    return sales;
}

//ADDED: 9.22.9
void CashRegister::reset_sales()
{
    total_amount_sales = 0;
    sales = 0;
}


void CashRegister::clear()
{
    //loops through vector and removes all items/prices from it
    while(!price_list.empty())
    {
        price_list.pop_back();
    }
    
    total_cost = 0;
    total_tax = 0;
    
    //Defining sale as anytime the clear() member function is called
    //As in each time the cost is payed and the total cost is 0.
    sales++;
    
}

//adds new item price to end of vector
void CashRegister::add_item(double price)
{
    price_list.push_back(price);
    total_cost += price;
    total_amount_sales += price;
}

//reimplemented this function to return cost as an integer
int CashRegister::get_total() const
{
    return total_cost*100;
}

//returns number of items rung up on cash register
int CashRegister::get_count() const
{
    return price_list.size();
}


//Displays the item number, with its price (taxed)
void CashRegister::display_all()
{
    for(int k = 0; k < price_list.size(); k++)
    {
        cout << "Item " << k + 1 << ": $" << price_list[k] << endl;
    }
}



int main(int argc, const char * argv[]) {
    CashRegister c1(0.1);
    
    c1.add_item(2.00);
    c1.add_item(5.00);
    c1.add_item(3.00);
    c1.add_item(3.32);
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
    
    c1.add_item(3.32);
    c1.add_taxable_item(5);
    c1.add_taxable_item(3);
    
    cout << "You have " << c1.get_count() << " items in your cart!" << endl;
    cout << endl;
    
    cout << "Here are all the prices of the items:" << endl;
    c1.display_all();
    cout << endl;
    
    cout << "The total price is: " << c1.get_total() << " cents" << endl;
    
    cout << "The tax is: " << c1.get_total_tax() << " cents" << endl;
    
    c1.clear();
    
    cout << "You now have " << c1.get_count() << " items in your cart. You owe " << c1.get_total() << " cents" << endl;
    
    cout << endl;
    
    cout << "-------------------------------" << endl;
    
    cout << "END OF DAY!" << endl;
    cout << "Total Number of sales: " << c1.get_sales_count() << endl;
    cout << "Total Amount of Sales: $" << c1.get_sales_total() << endl;
    
    
    
    
    return 0;
}
