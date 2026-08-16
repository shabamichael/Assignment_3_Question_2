#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

// Custom namespace to encapsulate domain-specific entities
namespace storeManagement
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

	private:
		string productId;
		string productName;
		string category;
		double basePrice;
		double warrantyCost;
		double discountPercentage;
		bool warrantyPurchased;
		double discountAmount;

		double monthlySales[12];
		double* priceHistory;
		int historyCount;
		int historyCapacity;


	protected:




	public:

		static const int HISTORY_SIZE = 3;

		Product();
		// Default constructor initializing product attributes to default values


		Product(
			const string& id, 
			const string& name, 
			const string& category, 
			double price, 
			double warranty, 
			double dRate, 
			bool hasWarranty=false);
		// Parameterized Constructor: Sets initial properties
		
		Product(const Product& other);
		// Copy constructor - required for dynamic array deep copy


		virtual ~Product();
		// Virtual Destructor to ensures safe  polymorphic


		// --- Accessors (Getters) ---

		string getId() const;
		// Returns product ID

		string getName() const;
		// Returns product name

		string getCategory() const;
		// Returns product category

		double getPrice() const;
		// Returns product base price 

		double getWarranty() const;
		// Returns warranty plan cost 

		double getDiscountRate() const;
		//Returns discount percentage rate
		
		bool hasWarranty() const;
		// Returns true if the customer purchased warranty plan.


		// --- Mutators (Setters) ---

		void setPrice(double newPrice);
		// Sets base price

		void setWarrantyValue(double newWarranty);
		// Sets warranty value

		void setWarrntyPurchase(bool purchased);

		void setDiscountRate(double discountPct);
		// Sets discount rate

		void setName(const string& name);
		// Set product name

		void setCategory(const string& category);
		// Set product category


		// --- Core Business Logic ---

		double calculatePriceWithOutDiscount() const;
		// Calculate price including warranty WITHOUT applying the discount

		double calculatePriceWithDiscount() const;
		// Calculate final price WITH warranty discount applied to base price

		double calculateDiscountAmount() const;
		// Calculate the exact discount value in Rands

		friend void displayProductSummary(std::ostream& out) const;
		// Display product properties and both total prices to output stream


		double getFinalPrice(bool withWarranty) const;
		// Determines final price based on whether warranty is taken
		// @param withWarranty - true if warranty is purchased, false otherwise

		double getPriceWithWarrantyAndDiscount() const;
		// Calculates final price including warranty and WITH discount applied
		// Criterion: Discount is only given if buyer agrees to purchase warranty plan
		// Formula: (base price - discount) + warranty

		void recordPriceChange(double newPrice);
		// Records a new price into the fixed-size price_history array
		// (shifting older values along once full), and updates 'price'.

		void displayPriceHistory(ostream& out) const;
		// Displays the recorded price history.

		friend ostream& operator<<(ostream& out, const Product& product);
		// Allows a Product object to be displayed

		friend bool operator==(const Product& first, const Product& second) ;
		// Compares two Product objects based on their IDs.

		friend std::istream& operator>>(std::istream& in, Product& p);
		friend bool operator==(const Product& p1, const Product& p2);
		friend Product operator+(const Product& p1, const Product& p2);
	};

} // namespace StoreManagement

#endif