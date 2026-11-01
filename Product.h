#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

// Custom namespace for modularity and preventing global name collisions
namespace StoreManagement 
{

    // Abstract Base Class: Product (ADT)
    class Product 
    {
    public:
        // Default Constructor: Initializes default values and allocates dynamic memory
        Product();

        // Parameterized Constructor: Sets initial properties
        Product(string name, string category, double basePrice, double warrantyCost, double discountPct);

        // Virtual Destructor: Ensures proper polymorphic dynamic memory cleanup
        virtual ~Product();

        // Copy Constructor: Performs deep copy for dynamically allocated members
        Product(const Product& other);

        // Overloaded Assignment Operator: Manages deep assignment between objects
        Product& operator=(const Product& other);

        // Accessor Functions (Getters)
        string get_name() const;
        string get_category() const;
        double get_base_price() const;
        double get_warranty_cost() const;
        double get_discount_percentage() const;

        // Mutator Functions (Setters)
        void set_name(const string& name);
        void set_category(const string& category);
        void set_base_price(double basePrice);
        void set_warranty_cost(double warrantyCost);
        void set_discount_percentage(double discountPct);

        // Pure Virtual Functions (Polymorphism & Abstract Data Type enforcement)
        virtual double calculate_price_no_discount() const = 0;
        virtual double calculate_price_with_discount() const = 0;
        virtual void display_product_summary(ostream& out) const = 0;

        // Helper Member Function: Calculates the discount value in Rands
        double calculate_discount_amount() const;

        // Overloaded Operators
        double operator+(const Product& rightOperand) const; // Adds base prices of two products
        bool operator==(const Product& rightOperand) const;   // Equality comparison

        // Friend Function: Stream insertion operator overload for direct output stream printing
        friend ostream& operator<<(ostream& out, const Product& prod);

    protected:
        string name;
        string category;
        double* base_price;          // Dynamic memory pointer demonstration
        double warranty_cost;       // Warranty plan value in Rands (R)
        double discount_percentage; // Special discount rate %
    };   

} // namespace StoreManagement

#endif