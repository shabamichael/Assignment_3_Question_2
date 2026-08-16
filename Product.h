#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

// Custom namespace to encapsulate domain-specific entities
namespace StoreManagement
{

	/**
	 * @class Product
	 * @brief Represents a retail product with pricing, warranty, and discount calculations.


	 */
	class Product {
		/**
		 * @param basePrice The pre-discount price of the product.
		 * @param hasWarranty Whether the customer purchased the warranty plan.
		 * @param name - product name e.g. "Dell Laptop"
		 * @param category - product category/type e.g. "Electronics"
		 * @param price - base price in Rands
		 * @param warrantyValue - cost of warranty plan in Rands
		 * @param discountRate - discount rate as percentage (0-100). Applied ONLY if warranty is purchased
		 * @param productId - unique identifier
		 * @return The final price after applying applicable discounts.
		 */

	public:
		Product();
		// Default constructor initializing product attributes to default values

		Product(string name, string category, double price, double warranty, double dRate, string id);
		// Overloaded constructor initializing product name, category, base price, warranty, and discount rate


		// --- Accessors (Getters) ---

		string getName() const;
		// Returns product name

		string getCategory() const;
		// Returns product category

		double getPrice() const;
		// Returns product base price 

		double getWarranty() const;
		// Returns warranty plan cost 

		double getDiscountPercentage() const;
		//Returns discount percentage rate

		string getProductId() const;
		// Returns product ID

		bool hasWarranty() const;
		// Returns true if the customer purchased warranty plan.


		// --- Mutators (Setters) ---

		void setPrice(double price);
		// Sets base price

		void setWarrantyValue(double warranty);
		// Sets warranty value

		void setDiscountRate(double discountPct);
		// Sets discount rate

		void setName(const string& name);
		// Set product name

		void setCategory(const string& category);
		// Set product category

		// --- Core Business Logic ---

		double calculatePriceNoDiscount() const;
		// Calculate price including warranty WITHOUT applying the discount

		double calculatePriceWithDiscount() const;
		// Calculate final price WITH warranty discount applied to base price

		double calculateDiscountAmount() const;
		// Calculate the exact discount value in Rands

		void displayProductSummary(ostream& out) const;
		// Display product properties and both total prices to output stream


		double getFinalPrice(bool withWarranty) const;
		// Determines final price based on whether warranty is taken
		// @param withWarranty - true if warranty is purchased, false otherwise

		double getPriceWithWarrantyAndDiscount() const;
		// Calculates final price including warranty and WITH discount applied
		// Criterion: Discount is only given if buyer agrees to purchase warranty plan
		// Formula: (base price - discount) + warranty


	private:
		string productId;
		string productName;
		string category;
		double basePrice;
		double warrantyCost;
		double discountPercentage;
		bool warrantyPurchased;
		double discountAmount;

	};

} // namespace StoreManagement

#endif