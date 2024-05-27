# Restaurant Order Management System

**Description**

This C program simulates a restaurant order management system catering to waiters, chefs, and admins. It allows waiters to take orders, chefs to prepare and mark orders as complete, and admins to view order history, change passwords for all roles, and clear order history.

**System Roles:**

- **Waiter:** Takes orders from customers, entering item codes and quantities.
- **Chef:** Pulls orders, displays order details, marks completed orders as done, and confirms completion.
- **Admin:** Views order history, changes passwords for all roles, and clears order history (use cautiously for testing).

**Functionality Overview:**

- The system displays a clear menu for each role.
- Waiters can add orders with item codes and quantities.
- The system calculates the total order amount.
- Waiters can confirm payment and place the order.
- Chefs can pull orders, view details, and mark completed orders as done.
- Admins can view order history, change passwords for all roles, and clear order history (use cautiously for testing).
- Password protection is implemented for each role.
- User input is validated for error handling.

**Building and Running**

1. **Prerequisites:**
   - A C compiler (e.g., GCC, Clang)
2. **Compilation:**
   ```bash
   gcc main.c headers.c -o restaurant_order_system
   ```
3. **Execution:**
   ```bash
   ./restaurant_order_system
   ```

**Disclaimer**

- This is a simplified simulation and may not reflect all aspects of a real-world restaurant order management system.

**Code Structure**

- **Header inclusions:** Necessary standard C libraries for input/output, memory management, time, console interaction, and file operations.
- **Structure definitions:**
    - `node`: Represents a node in the queue, used for managing orders.
    - `order`: Stores details of a customer's order, including the number of items, item codes, item quantities, and total amount.
    - `passwords`: Stores passwords for each role (waiter, chef, admin).
- **Global variables:**
    - `ordernum`: Tracks the current order number.
    - `i`: Used for looping purposes.
    - `numberoforders`: Counts the number of pending orders.
- **Function declarations:** Grouped by functionality for waiters, cooks, admins, and backend operations.
- **Waiter and cook functions:**
    - `addorder`: Adds a new order taken by a waiter.
    - `delorder`: Removes a completed order from the queue (handled by chef).
    - `waiter`: Handles waiter interactions, including taking orders and displaying the waiter menu.
    - `cook`: Handles chef interactions, including pulling orders, displaying order details, marking orders as done, and displaying the cook menu.
    - `display`: Displays details of pending orders (used by both waiter and cook).
- **Admin functions:**
    - `changepassword`: Allows the admin to change passwords for all roles.
    - `orderhistory`: Displays the complete order history with order details and total collections.
    - `deletehistory`: Clears the order history.
- **Backend functions:**
    - `delay`: Provides a simple delay mechanism for visual effects.
    - `delay_print`: Prints characters with a delay for a more visually appealing output.
    - `about`: Displays program information and copyright.
    - `writee`: Writes order and password data to files for persistence.
    - `readd`: Reads order and password data from files at program startup.

**Explanation of Key Functions**

- `addorder`:
    - Prompts the waiter for confirmation if there are no pending orders.
    - Allows the waiter to add multiple items to an order.
    - Validates entered item codes to ensure they are within the valid range.
    - Calculates the total cost of the order as items are added.
    - Enqueues the newly created `order` structure in a queue.
    - Increments the `numberoforders` counter.
- `delorder`:
    - Dequeues the first order from the queue (implementation not shown).
    - Decrements the `numberoforders` counter.
    - Marks the order as complete.
- `waiter`:
    - Provides a menu for the waiter to choose actions: take order, display order queue, or exit.
    - Calls the `addorder` function to take a new order.
    - Calls the `display` function to show details of pending orders, including order number, total items, and total amount.
- `cook`:
    - Provides a menu for the cook to choose actions: pull order, display order details, mark order as complete, or exit.
    - If no orders are pending, displays a message and exits the cook menu.
    - Calls the `delorder` function to mark an order as complete.
    - Calls the `display` function to show details of an order before marking it complete.
- `display`:
    - Checks if there are any pending orders.
    - Iterates through the queue (implementation not shown) and displays order details for each pending order, including order number, number of items, and total amount.
- `orderhistory`:
    - Opens the order history file for reading.
    - Reads the stored order data into the `s` array.
    - Calculates the total collections across all orders.
    - Displays a table with order number, number of items, and total amount for each order.
    - Shows the total collections earned from all orders.
