#include "ElectronicsProduct.h"
#include <iomanip>

// ========================================================
// Derived Class 1: ElectronicsProduct Implementation
// ========================================================

ElectronicsProduct::ElectronicsProduct(): 
    Product("Generic Electronics", "Electronics", 0.0, 0.0, 0.0), guarantee_months(12) {}

ElectronicsProduct::ElectronicsProduct
(string name, double basePrice, double warrantyCost, double discountPct, int guaranteeMonths): 
    Product(name, "Electronics", basePrice, warrantyCost, discountPct), guarantee_months(guaranteeMonths) {}

// Purpose: Polymorphic price calculation without discount (Base + Warranty)
double ElectronicsProduct::calculate_price_no_discount() const 
{
    return get_base_price() + warranty_cost;
}

// Purpose: Polymorphic price calculation with discount (Base - Discount + Warranty)
double ElectronicsProduct::calculate_price_with_discount() const 
{
    return (get_base_price() - calculate_discount_amount()) + warranty_cost;
}

int ElectronicsProduct::get_guarantee_months() const 
{ 
    return guarantee_months; 
}

// Purpose: Formatted output for Electronics details
void ElectronicsProduct::display_product_summary(ostream& out) const 
{
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
