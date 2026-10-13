# Grocery Item Management System

## Project Overview
The Grocery Item Management System is a menu-driven C++ project that manages grocery inventory using a **Singly Linked List**. It allows users to add, display, search, update, and delete grocery items and calculate the total inventory value.

## Technologies Used
- Programming Language: C++
- Data Structure: Singly Linked List
- Concepts: Dynamic Memory Allocation, Insertion, Traversal, Searching, Updating, and Deletion

## Features
1. **Add Grocery Item** – Adds a new grocery item with a unique ID, name, quantity, and price.
2. **Display All Items** – Displays all grocery items stored in the inventory.
3. **Search Item** – Searches for a grocery item using its ID.
4. **Update Item** – Updates the quantity and price of an existing item.
5. **Delete Item** – Removes an item from the inventory.
6. **Calculate Total Inventory Value** – Calculates the total value of all items in stock.
7. **Duplicate ID Validation** – Prevents adding items with an existing ID.
8. **Input Validation** – Rejects negative quantities and prices when adding an item.

## Data Structure Used

### Singly Linked List
Each node contains:
- Item ID
- Item name
- Quantity
- Price per item
- Pointer to the next node

The `head` pointer stores the address of the first node. Each node points to the next node in the list.

## Inventory Value Calculation

**Formula:**

Total Inventory Value = Sum of (Quantity × Price per Item)

The program calculates the total value of all grocery items currently stored in the linked list.

## Applications
- Grocery shop inventory management
- Stock quantity tracking
- Item price management
- Searching and maintaining product records
- Calculating the total value of available stock


