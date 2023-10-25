#include <iostream>
#include <string>

// Define a structure to represent a product
struct Product {
    std::string name;
    int quantity;
    double price;
    std::string brand;
};

// Maximum number of products in the array
const int maxProducts = 10;

// Global array to store product information
Product products[maxProducts];
int productCount = 0;  // Keeps track of the number of products in the array

// Function to add a product to the array
void addProduct(const std::string& name, int quantity, double price, const std::string& brand) {
    if (productCount < maxProducts) {
        products[productCount].name = name;
        products[productCount].quantity = quantity;
        products[productCount].price = price;
        products[productCount].brand = brand;
        productCount++;
    } else {
        std::cout << "Array is full. Cannot add more products." << std::endl;
    }
}

// Function to print the array of products
void printProducts() {
    std::cout << "Product List:" << std::endl;
    for (int i = 0; i < productCount; i++) {
        std::cout << "Product Name: " << products[i].name << std::endl;
        std::cout << "Quantity: " << products[i].quantity << std::endl;
        std::cout << "Price: $" << products[i].price << std::endl;
        std::cout << "Brand: " << products[i].brand << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

int main() {
    // Add some sample products to the array
    addProduct("Laptop", 5, 799.99, "Dell");
    addProduct("Smartphone", 10, 499.99, "Samsung");
    addProduct("Headphones", 20, 49.99, "Sony");

    // Print the product array
    printProducts();

    return 0;
}
