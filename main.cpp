#include <iostream>
#include <fstream>
#include "Product.h"
#include "InventoryManager.h"
#include "ApplianceProduct.h"
#include "ElectronicsProduct.h"

using namespace std;
using namespace StoreManagement;

int main() {
    // Generic Template Instance managing Base Class Pointers (Polymorphism & Vector)
    InventoryManager<Product*> storeInventory;

    // Dynamically Allocate Polymorphic Objects
    storeInventory.add_item(new ElectronicsProduct("4K Smart TV", 8500.00, 750.00, 12.5, 24));
    storeInventory.add_item(new ApplianceProduct("Double Door Refrigerator", 12000.00, 1200.00, 15.0, 350.00));
    storeInventory.add_item(new ElectronicsProduct("Gaming Laptop", 18500.00, 1500.00, 10.0, 12));
    storeInventory.add_item(new ApplianceProduct("Microwave Oven", 2200.00, 250.00, 8.0, 100.00));

    cout << "========================================================\n";
    cout << "        WALTER SAVITCH OOP CONCEPTS DEMONSTRATION       \n";
    cout << "========================================================\n\n";

    // 1. Console Output Stream (I/O Streams & Polymorphism)
    cout << "--- PRINTING INVENTORY TO CONSOLE STREAM ---\n";
    storeInventory.display_all(cout);

    // 2. Overloaded Operator (+) Demonstration
    cout << "\n--- DEMONSTRATING OVERLOADED + OPERATOR ---\n";
    double combinedBasePrice = (*storeInventory[0]) + (*storeInventory[1]);
    cout << "Combined Base Price (" << storeInventory[0]->get_name()
        << " + " << storeInventory[1]->get_name() << "): R " << combinedBasePrice << "\n\n";

    // 3. Overloaded Operator (==) Demonstration
    cout << "--- DEMONSTRATING OVERLOADED == OPERATOR ---\n";
    ElectronicsProduct copyTv("4K Smart TV", 8500.00, 750.00, 12.5, 24);
    if (*storeInventory[0] == copyTv) {
        cout << "Match Found: " << storeInventory[0]->get_name() << " is equal to copyTv.\n\n";
    }

    // 4. File I/O Stream Output
    ofstream outFile("InventoryReport.txt");
    if (outFile.is_open()) {
        outFile << "========================================================\n";
        outFile << "            STORE INVENTORY REPORT FILE                 \n";
        outFile << "========================================================\n\n";

        // Output all inventory data directly to external file
        storeInventory.display_all(outFile);

        outFile.close();
        cout << "Success: Inventory report written to 'InventoryReport.txt'.\n";
    }
    else {
        cerr << "Error: Failed to open file for writing.\n";
    }

    // Cleanup dynamically allocated memory (Pointers / Destructors)
    for (size_t i = 0; i < storeInventory.size(); ++i) {
        delete storeInventory[i];
    }

    return 0;
}