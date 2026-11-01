#include "Product.h"
#include <iomanip>

using namespace std;
using namespace StoreManagement;
namespace StoreManagement {

    // ========================================================
    // Abstract Base Class: Product Implementation
    // ========================================================

    // Purpose: Default Constructor - allocates dynamic memory on the heap
    Product::Product(): 
        name("Unknown"), category("General"), warranty_cost(0.0), discount_percentage(0.0) 
    {
        base_price = new double(0.0);
    }

    // Purpose: Parameterized Constructor - initializes attributes and allocates dynamic memory
    Product::Product(string name, string category, double basePrice, double warrantyCost, double discountPct): 
        name(name), category(category), warranty_cost(warrantyCost), discount_percentage(discountPct) 
    {
        base_price = new double((basePrice >= 0) ? basePrice : 0.0);
    }

    // Purpose: Virtual Destructor - deallocates heap memory safely
    Product::~Product() {
        delete base_price;
        base_price = nullptr;
    }

    // Purpose: Copy Constructor - performs deep copying of dynamically allocated members
    Product::Product(const Product& other): 
        name(other.name), category(other.category), 
        warranty_cost(other.warranty_cost), 
        discount_percentage(other.discount_percentage) 
    {
        base_price = new double(*(other.base_price));
    }

    // Purpose: Overloaded Assignment Operator - ensures deep assignment and avoids memory leaks
    Product& Product::operator=(const Product& other) 
    {
        if (this != &other) 
        {
            name = other.name;
            category = other.category;
            warranty_cost = other.warranty_cost;
            discount_percentage = other.discount_percentage;

            delete base_price;
			base_price = nullptr;

            base_price = new double(*(other.base_price));
        }
        return *this;
    }

    // Getters 
    string Product::get_name() const 
    { 
        return name; 
    }
    string Product::get_category() const 
    { 
        return category; 
    }
    double Product::get_base_price() const 
    { 
        return *base_price; 
    }
    double Product::get_warranty_cost() const 
    { 
        return warranty_cost; 
    }
    double Product::get_discount_percentage() const 
    { 
        return discount_percentage; 
    }

    // Setters
    void Product::set_name(const string& n) 
    { 
        name = n; 
    }
    void Product::set_category(const string& c) 
    { 
        category = c; 
    }
    void Product::set_base_price(double basePrice) 
    { 
        *base_price = (basePrice >= 0) ? basePrice : 0.0; 
    }
    void Product::set_warranty_cost(double warrantyCost) 
    { 
        warranty_cost = (warrantyCost >= 0) ? warrantyCost : 0.0; 
    }
    void Product::set_discount_percentage(double discountPct) 
    { 
        discount_percentage = (discountPct >= 0) ? discountPct : 0.0; 
    }

    // Purpose: Calculates discount value in Rands
    double Product::calculate_discount_amount() const 
    {
        return (*base_price) * (discount_percentage / 100.0);
    }

    // Purpose: Overloaded '+' Operator - calculates combined base price of two products
    double Product::operator+(const Product& rightOperand) const 
    {
        return (*this->base_price) + (*rightOperand.base_price);
    }

    // Purpose: Overloaded '==' Operator - tests equality between two products by name and price
    bool Product::operator==(const Product& rightOperand) const 
    {
        return (this->name == rightOperand.name && (*this->base_price) == (*rightOperand.base_price));
    }

    // Purpose: Friend function output stream operator overload
    ostream& operator<<(ostream& out, const Product& prod) 
    {
        prod.display_product_summary(out);
        return out;
    }   

} // namespace StoreManagement