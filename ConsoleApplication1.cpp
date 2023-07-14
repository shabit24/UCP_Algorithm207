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

//2.
// Based on the given information that the front value is 10 at index 3 and the rear value is 15 at index 4, it indicates the use of a Queue data structure to manage data in the case study.

// A Queue is a data structure that follows the First-In-First-Out (FIFO) principle, where elements are added to the rear of the queue and removed from the front. In the context of the case study, the front and rear values indicate the current positions of the front and rear elements in the queue.

//3.
// To solve the problem using a queue algorithm with arrays, we can follow these steps based on the given front and rear values:

// *. Initialize the queue: Create an array of a fixed size to store the elements of the queue. Additionally, initialize the front and rear variables with their respective indices. In this case, front = 10 at index 3 and rear = 15 at index 4.

// *. Enqueue operation: To add elements to the queue, increment the rear index by one and store the new element at that index in the array. In this case, we would enqueue new elements by incrementing the rear index to index 5 and storing the element 15 at that position.

// *. Dequeue operation: To remove elements from the queue, increment the front index by one, effectively "removing" the element at that index. In this case, we would increment the front index from index 3 to index 4, indicating the removal of the element 10 from the front of the queue.

// *. Handle circular behavior: Since the array is of a fixed size, we need to handle cases where the front or rear indices exceed the array boundaries. For example, if the rear index reaches the end of the array, we can wrap it around to the beginning by setting rear = (rear + 1) % arraySize. This ensures the circular behavior of the queue.

// By following these steps and implementing the necessary operations with the given front and rear values, we can effectively solve the problem using a queue algorithm with arrays. This allows us to manage the queue, add new elements at the rear, remove elements from the front, and handle circular behavior when necessary.

//4.
// The given front and rear values (front = 10 at index 3 and rear = 15 at index 4) do not align with the typical usage of a Stack data structure. A Stack follows the Last-In-First-Out (LIFO) principle, where elements are added and removed from the same end of the stack.

// In the case of the given front and rear values, they do not represent a valid configuration for a Stack. The front and rear values suggest a linear data structure rather than a stack-like behavior.

// However, if we still wish to explore the usage of a stack algorithm with the provided values, we can consider the following approach:

// *. Initialize the stack: Create an array of a fixed size to hold the elements of the stack. Initialize the stack with the given values of front and rear.

// *. Push operation: To add elements to the stack, increment the rear index by one and store the new element at that index in the array. In this case, we would push new elements by incrementing the rear index to index 5 and storing the element 15 at that position.

// *. Pop operation: To remove elements from the stack, decrement the rear index by one, effectively "removing" the element at that index. In this case, we would decrement the rear index from index 4 to index 3, indicating the removal of the element 15 from the stack.


//5.
//a
// Based on the given sequence of numbers,  the depth of the resulting tree will be 5. The depth of a BST is determined by the longest path from the root to any leaf node.


//b.
// To read the tree structure shown above, we can use one of the traversal methods: Inorder, Preorder, or Postorder. Let's consider the Preorder traversal method to read the tree:

// Preorder Traversal:
// 1. Visit the current node.
// 2. Recursively traverse the left subtree.
// 3. Recursively traverse the right subtree.
//The Preorder traversal provides a sequence that visits the nodes in the order they would be encountered when traversing the tree in a depth-first manner.
