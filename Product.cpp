//Implemetation of the Product
#include "Product.h"
#include <iomanip>
using namespace storeManagement;

Product::Product():
    productId("Unknown"),
    productName("Unknown"),
    category("General"),
    basePrice (0.0),
    warrantyCost(0.0),
    discountPercentage(0.0),
    warrantyPurchased(false),
    discountAmount(0.0){}
// Default constructor initialises all members to safe default values

Product::Product(const string& id, const string& name, const string& cat, 
    double price, double warranty, double dRate , bool hasWarranty):
    productId(id),
    productName(name),
    category(cat),
    basePrice(price),
    warrantyCost(warranty),
    discountPercentage(dRate),
    warrantyPurchased(warrantyCost > 0.0),
    discountAmount((discountPercentage/ 100.0) * basePrice){}
// Overloaded constructor implementation


// --- Accessors (Getters) ---

string Product::getName() const { return this->productName;}
string Product::getCategory() const { return this->category; }
double Product::getPrice() const { return this->basePrice;}
double Product::getWarranty() const { return this->warrantyCost;}
double Product::getDiscountPercentage() const { return this->discountPercentage;}
string Product::getProductId() const { return this->productId;}
bool Product::hasWarranty() const { return warrantyPurchased;}


// --- Setters ---

void Product::setPrice(double price) { if (price >= 0.0) this->basePrice = price;}
void setWarrantyValue(double warranty);

void Product::setDiscountRate(double discountPct){}
// Sets discount rate

void setName(const string& name);
// Set product name

void setCategory(const string& category);
// Set product category

void Product::setPrice(double p) { if (p >= 0) price = p; }
void Product::setWarrantyValue(double w) { if (w >= 0) warrantyValue = w; }
void Product::setDiscountRate(double d) { if (d >= 0 && d <= 100) discountRate = d; }

// PURPOSE: Calculates discount in Rands from percentage
double Product::calculateDiscountAmount() const {
    return price * (discountRate / 100.0);
}

// PURPOSE: Price + Warranty without discount
double Product::getPriceWithWarrantyNoDiscount() const {
    return price + warrantyValue;
}

// PURPOSE: Price + Warranty WITH discount - This is the special offer
double Product::getPriceWithWarrantyAndDiscount() const {
    return (price - calculateDiscountAmount()) + warrantyValue;
}

// PURPOSE: General final price logic
double Product::getFinalPrice(bool withWarranty) const {
    if (withWarranty) {
        // Criterion for discount met
        return getPriceWithWarrantyAndDiscount();
    }
    else {
        return price; // no warranty, no discount
    }
}

// PURPOSE: Display product summary
void Product::display(ostream& out) const {
    out << fixed << setprecision(2);
    out << "ID: " << productId << " | " << name << " [" << category << "]" << endl;
    out << " Base Price: R" << price << endl;
    out << " Warranty Plan: R" << warrantyValue << endl;
    out << " Discount (if warranty taken): " << discountRate << "% (R" << calculateDiscountAmount() << ")" << endl;
    out << " -> Price incl. warranty (NO discount): R" << getPriceWithWarrantyNoDiscount() << endl;
    out << " -> Price incl. warranty (WITH discount): R" << getPriceWithWarrantyAndDiscount() << endl;
    out << "--------------------------------------------------" << endl;
}
