#ifndef ELECTRONICS_PRODUCT_H
#define ELECTRONICS_PRODUCT_H
#include "Product.h"

using namespace StoreManagement;

// Derived Class 1: ElectronicsProduct (Inheritance)
class ElectronicsProduct : public Product {
public:
    ElectronicsProduct();
    ElectronicsProduct(string name, double basePrice, double warrantyCost, double discountPct, int guaranteeMonths);

    // Overridden Pure Virtual Functions (Polymorphism)
    double calculate_price_no_discount() const override;
    double calculate_price_with_discount() const override;
    void display_product_summary(ostream& out) const override;

    int get_guarantee_months() const;

private:
    int guarantee_months;
};

#endif
