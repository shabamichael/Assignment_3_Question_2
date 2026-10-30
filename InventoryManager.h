#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <vector>
#include <iostream>

using namespace std;

namespace StoreManagement {

    /**
     * @class InventoryManager
     * @brief Generic Template Class to manage dynamic collections (Savitch Chapter 17).
     */
    template <typename T>
    class InventoryManager {
    public:
        // Purpose: Adds an item to internal vector collection
        void add_item(T item) {
            items.push_back(item);
        }

        // Purpose: Returns element count
        size_t size() const {
            return items.size();
        }

        // Purpose: Subscript operator overload for element access
        T operator[](size_t index) const {
            return items[index];
        }

        // Purpose: Displays all items using overloaded stream insertion operator
        void display_all(ostream& out) const {
            for (const auto& item : items) {
                out << *item; // Calls overloaded operator<< polymorphically
            }
        }

    private:
        vector<T> items;
    };

} // namespace StoreManagement

#endif