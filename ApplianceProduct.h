#ifndef APPLICANCE_PRODUCT_H
#define APPLICANCE_PRODUCT_H
#include "Product.h"

using namespace StoreManagement;

// Derived Class 2: ApplianceProduct (Inheritance)
class ApplianceProduct : public Product 
{
public:
    ApplianceProduct();
    ApplianceProduct(string name, double basePrice, double warrantyCost, double discountPct, double deliveryFee);

    // Overriden Pure Virtual Functions (Polymorphism)
    double calculate_price_no_discount() const override;
    double calculate_price_with_discount() const override;
    void display_product_summary(ostream& out) const override;

    double get_delivery_fee() const;

private:
    double delivery_fee;
};
#endif