#include "Product.h"
#include <iomanip>

using namespace std;

namespace StoreManagement {

    // ========================================================
    // Abstract Base Class: Product Implementation
    // ========================================================

    // Purpose: Default Constructor - allocates dynamic memory on the heap
    Product::Product()
        : name("Unknown"), category("General"), warranty_cost(0.0), discount_percentage(0.0) {
        base_price = new double(0.0);
    }

    // Purpose: Parameterized Constructor - initializes attributes and allocates dynamic memory
    Product::Product(string name, string category, double basePrice, double warrantyCost, double discountPct)
        : name(name), category(category), warranty_cost(warrantyCost), discount_percentage(discountPct) {
        base_price = new double((basePrice >= 0) ? basePrice : 0.0);
    }

    // Purpose: Virtual Destructor - deallocates heap memory safely
    Product::~Product() {
        delete base_price;
        base_price = nullptr;
    }

    // Purpose: Copy Constructor - performs deep copying of dynamically allocated members
    Product::Product(const Product& other)
        : name(other.name), category(other.category), warranty_cost(other.warranty_cost), discount_percentage(other.discount_percentage) {
        base_price = new double(*(other.base_price));
    }

    // Purpose: Overloaded Assignment Operator - ensures deep assignment and avoids memory leaks
    Product& Product::operator=(const Product& other) {
        if (this != &other) {
            name = other.name;
            category = other.category;
            warranty_cost = other.warranty_cost;
            discount_percentage = other.discount_percentage;

            delete base_price;
            base_price = new double(*(other.base_price));
        }
        return *this;
    }

    // Getters & Setters
    string Product::get_name() const { return name; }
    string Product::get_category() const { return category; }
    double Product::get_base_price() const { return *base_price; }
    double Product::get_warranty_cost() const { return warranty_cost; }
    double Product::get_discount_percentage() const { return discount_percentage; }

    void Product::set_name(const string& n) { name = n; }
    void Product::set_category(const string& c) { category = c; }
    void Product::set_base_price(double basePrice) { *base_price = (basePrice >= 0) ? basePrice : 0.0; }
    void Product::set_warranty_cost(double warrantyCost) { warranty_cost = (warrantyCost >= 0) ? warrantyCost : 0.0; }
    void Product::set_discount_percentage(double discountPct) { discount_percentage = (discountPct >= 0) ? discountPct : 0.0; }

    // Purpose: Calculates discount value in Rands
    double Product::calculate_discount_amount() const {
        return (*base_price) * (discount_percentage / 100.0);
    }

    // Purpose: Overloaded '+' Operator - calculates combined base price of two products
    double Product::operator+(const Product& rightOperand) const {
        return (*this->base_price) + (*rightOperand.base_price);
    }

    // Purpose: Overloaded '==' Operator - tests equality between two products by name and price
    bool Product::operator==(const Product& rightOperand) const {
        return (this->name == rightOperand.name && (*this->base_price) == (*rightOperand.base_price));
    }

    // Purpose: Friend function output stream operator overload
    ostream& operator<<(ostream& out, const Product& prod) {
        prod.display_product_summary(out);
        return out;
    }

    // ========================================================
    // Derived Class 1: ElectronicsProduct Implementation
    // ========================================================

    ElectronicsProduct::ElectronicsProduct()
        : Product("Generic Electronics", "Electronics", 0.0, 0.0, 0.0), guarantee_months(12) {
    }

    ElectronicsProduct::ElectronicsProduct(string name, double basePrice, double warrantyCost, double discountPct, int guaranteeMonths)
        : Product(name, "Electronics", basePrice, warrantyCost, discountPct), guarantee_months(guaranteeMonths) {
    }

    // Purpose: Polymorphic price calculation without discount (Base + Warranty)
    double ElectronicsProduct::calculate_price_no_discount() const {
        return get_base_price() + warranty_cost;
    }

    // Purpose: Polymorphic price calculation with discount (Base - Discount + Warranty)
    double ElectronicsProduct::calculate_price_with_discount() const {
        return (get_base_price() - calculate_discount_amount()) + warranty_cost;
    }

    int ElectronicsProduct::get_guarantee_months() const { return guarantee_months; }

    // Purpose: Formatted output for Electronics details
    void ElectronicsProduct::display_product_summary(ostream& out) const {
        out << fixed << setprecision(2);
        out << "--------------------------------------------------------\n"
            << "Type                   : Electronics\n"
            << "Product Name           : " << name << "\n"
            << "Guarantee Period       : " << guarantee_months << " Months\n"
            << "Base Price             : R " << get_base_price() << "\n"
            << "Warranty Plan Value    : R " << warranty_cost << "\n"
            << "Discount Rate          : " << discount_percentage << "%\n"
            << "Price incl. Warranty (NO discount)   : R " << calculate_price_no_discount() << "\n"
            << "Price incl. Warranty (WITH discount) : R " << calculate_price_with_discount() << "\n";
    }

    // ========================================================
    // Derived Class 2: ApplianceProduct Implementation
    // ========================================================

    ApplianceProduct::ApplianceProduct()
        : Product("Generic Appliance", "Appliances", 0.0, 0.0, 0.0), delivery_fee(0.0) {
    }

    ApplianceProduct::ApplianceProduct(string name, double basePrice, double warrantyCost, double discountPct, double deliveryFee)
        : Product(name, "Appliances", basePrice, warrantyCost, discountPct), delivery_fee(deliveryFee) {
    }

    // Purpose: Polymorphic price calculation including delivery fee (Base + Warranty + Delivery)
    double ApplianceProduct::calculate_price_no_discount() const {
        return get_base_price() + warranty_cost + delivery_fee;
    }

    // Purpose: Polymorphic price calculation with discount and delivery fee
    double ApplianceProduct::calculate_price_with_discount() const {
        return (get_base_price() - calculate_discount_amount()) + warranty_cost + delivery_fee;
    }

    double ApplianceProduct::get_delivery_fee() const { return delivery_fee; }

    // Purpose: Formatted output for Home Appliance details
    void ApplianceProduct::display_product_summary(ostream& out) const {
        out << fixed << setprecision(2);
        out << "--------------------------------------------------------\n"
            << "Type                   : Home Appliance\n"
            << "Product Name           : " << name << "\n"
            << "Delivery Fee           : R " << delivery_fee << "\n"
            << "Base Price             : R " << get_base_price() << "\n"
            << "Warranty Plan Value    : R " << warranty_cost << "\n"
            << "Discount Rate          : " << discount_percentage << "%\n"
            << "Price incl. Warranty (NO discount)   : R " << calculate_price_no_discount() << "\n"
            << "Price incl. Warranty (WITH discount) : R " << calculate_price_with_discount() << "\n";
    }

} // namespace StoreManagement