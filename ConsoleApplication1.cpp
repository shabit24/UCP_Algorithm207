#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string productName;
    int productNumber;
    string productType;
    Node* next;

    Node(string name, int number, string type) {
        productName = name;
        productNumber = number;
        productType = type;
        next = NULL;
    }
};

class ProductManagement {
private:
    Node* head;

public:
    ProductManagement() {
        head = NULL;
    }

    void addProduct() {
        string name;
        int number;
        string type;

        cout << "========== ADD PRODUCT ==========" << endl;
        cout << "Product Name: ";
        getline(cin, name);
        cout << "Number of products: ";
        cin >> number;
        cin.ignore(); // Clears the input buffer
        cout << "Product Type: ";
        getline(cin, type);

        Node* newNode = new Node(name, number, type);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Product added successfully!" << endl;
    }

    void showAllProducts() {
        cout << "========== ALL PRODUCT DATA ==========" << endl;
        if (head == NULL) {
            cout << "No product data has been saved yet." << endl;
        }
        else {
            Node* current = head;
            while (current != NULL) {
                cout << "Product Name: " << current->productName << endl;
                cout << "Product Number: " << current->productNumber << endl;
                cout << "Product Type: " << current->productType << endl;
                cout << "----------------------" << endl;
                current = current->next;
            }
        }
    }

    void findProductByName() {
        cout << "========== SEARCH PRODUCT BY NAME ==========" << endl;
        if (head == NULL) {
            cout << "No product data has been saved yet." << endl;
        }
        else {
            string targetName;
            cout << "The product name you are looking for: ";
            getline(cin, targetName);
            Node* current = head;
            int position = 0;
            bool found = false;
            while (current != NULL) {
                position++;
                if (current->productName == targetName) {
                    cout << "Product found at position: " << position << endl;
                    cout << "Product Name: " << current->productName << endl;
                    cout << "Product Number: " << current->productNumber << endl;
                    cout << "Product Type: " << current->productType << endl;
                    found = true;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                cout << "Product name \"" << targetName << "\" NOT FOUND" << endl;
            }
        }
    }

    void sortByNumberProducts() {
        if (head == NULL || head->next == NULL) {
            return; // No need for sorting if there are only 0 or 1 nodes
        }

        Node* current = head;
        Node* nextNode = NULL;
        int tempNumber;
        string tempName;
        string tempType;

        while (current != NULL) {
            nextNode = current->next;
            while (nextNode != NULL) {
                if (current->productNumber > nextNode->productNumber) {
                    tempNumber = current->productNumber;
                    tempName = current->productName;
                    tempType = current->productType;

                    current->productNumber = nextNode->productNumber;
                    current->productName = nextNode->productName;
                    current->productType = nextNode->productType;

                    nextNode->productNumber = tempNumber;
                    nextNode->productName = tempName;
                    nextNode->productType = tempType;
                }
                nextNode = nextNode->next;
            }
            current = current->next;
        }

        cout << "Product data sorted by quantity." << endl;
    }
};

int main() {
    ProductManagement productManagement;
    int option;

    do {
        cout << "========== PRODUCT DATA MANAGEMENT APPLICATION ==========" << endl;
        cout << "1. Add product" << endl;
        cout << "2. Show all products" << endl;
        cout << "3. Search product by name" << endl;
        cout << "4. Sort product by quantity" << endl;
        cout << "5. Exit" << endl;
        cout << "Options: ";
        cin >> option;
        cin.ignore();

        switch (option) {
        case 1:
            productManagement.addProduct();
            break;
        case 2:
            productManagement.showAllProducts();
            break;
        case 3:
            productManagement.findProductByName();
            break;
        case 4:
            productManagement.sortByNumberProducts();
            break;
        case 5:
            cout << "Thank you! The program is finished." << endl;
            break;
        default:
            cout << "Invalid selection. Please try again." << endl;
            break;
        }

        cout << endl;
    } while (option != 5);

    return 0;
}