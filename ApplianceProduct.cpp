#include "Product.h"
#include "ApplianceProduct.h"
#include <iomanip>


// ========================================================
// Derived Class 2: ApplianceProduct Implementation
// ========================================================

ApplianceProduct::ApplianceProduct(): 
    Product("Generic Appliance", "Appliances", 0.0, 0.0, 0.0), delivery_fee(0.0) {}

ApplianceProduct::ApplianceProduct
(string name, double basePrice, double warrantyCost, double discountPct, double deliveryFee): 
    Product(name, "Appliances", basePrice, warrantyCost, discountPct), delivery_fee(deliveryFee) {}

// Purpose: Polymorphic price calculation including delivery fee (Base + Warranty + Delivery)
double ApplianceProduct::calculate_price_no_discount() const 
{
    return get_base_price() + warranty_cost + delivery_fee;
}

// Purpose: Polymorphic price calculation with discount and delivery fee
double ApplianceProduct::calculate_price_with_discount() const 
{
    return (get_base_price() - calculate_discount_amount()) + warranty_cost + delivery_fee;
}

double ApplianceProduct::get_delivery_fee() const 
{ 
    return delivery_fee; 
}

// Purpose: Formatted output for Home Appliance details
void ApplianceProduct::display_product_summary(ostream& out) const 
{
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