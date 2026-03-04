#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

class Product {
public:
    int id; 
    string name;
    double price;

    Product(int P_id ,string P_name,double P_price) {
        id = P_id;
        name = P_name;
        price = P_price;
    }
    void displayProduct() const {
        std::cout << "ID: " << left << setw(5) << id
                  << "| " << setw(30) << name //you
                  << "| Price: " << fixed << setprecision(2) << price << " Bath\n";
    }
    static void showAllProduct(const vector<Product>& vecProduct) {
        cout << "================== STORE INVENTORY ==================" << endl;
        for (const auto& item : vecProduct) {
            item.displayProduct();
        }
        cout << "=====================================================\n";
    }
};

class Cart {
    public:
    vector<Product> cartItems;

    void addProduct(Product p) {
        cartItems.push_back(p);
        cout << ">> Added --> [" << p.name << "] to cart!\n";
    }

    void removeProduct(int productId) {
        for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
            if (it->id == productId) {
                cout << ">> remove --> [" << it->name << "] form cart!\n";
                cartItems.erase(it);
                return;
            }
        }
        cout << ">> Cart is empty or Product not found in cart\n";
    }

    void showCart() {
        if (cartItems.empty()) {
            cout << ">> Cart is empty\n";
            return;
        }
        cout << "\n================== CART ==================\n";
        for (int i = 0; i < (int)cartItems.size(); i++) {
            cout <<"ID: "<< cartItems[i].id <<" - " << cartItems[i].name << " (" << cartItems[i].price << " Bath)\n";
        }
        cout << "============================================\n";
    }
};

class Admin {
private:
    string username = "admin";
    string password = "1234";

public:
    bool login(string u, string p) {
        if (u == username && p == password) {
            return true;
        }
        return false;
    }
};


int main() {
    vector<Product> storeProducts = {
        Product(1, "MacBook Air M2", 34900.0),
        Product(2, "iPad Pro 11-inch", 32900.0),
        Product(3, "Logitech MX Master 3S", 4390.0),
        Product(4, "Keychron K2 Keyboard", 3890.0),
        Product(5, "Sony WH-1000XM5", 11900.0),
        Product(6, "Samsung Odyssey G7", 18500.0),
        Product(7, "Seagate External HDD 2TB", 2150.0),
        Product(8, "WD Black SN850X SSD 1TB", 4590.0),
        Product(9, "Elgato Stream Deck MK.2", 5990.0),
        Product(10, "Blue Yeti Microphone", 5400.0),
        Product(11, "Razer DeathAdder V3 Pro", 5690.0),
        Product(12, "ASUS RT-AX88U Router", 9800.0),
        Product(13, "Anker 737 Power Bank", 4990.0),
        Product(14, "Dell Docking Station WD19", 7500.0),
        Product(15, "SteelSeries Arctis Nova 7", 6900.0)
    };

    Cart myCart;

    int choice;
    while (true) {
        cout << "\n================== SHOP MENU ==================\n";
        cout << "1. View product\n";
        cout << "2. Cart menu\n";
        cout << "3. Checkout\n";
        cout << "4. Admin menu\n";
        cout << "0. Exit\n";
        cout << "Select menu : ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ">> Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            Product::showAllProduct(storeProducts);

        } else if (choice == 2) {

            while (true) {
                Product::showAllProduct(storeProducts);
                myCart.showCart();

                int shopChoice;
                cout << "\n[1] add  [2] remove  [0] back\n";
                cout << "Select menu : ";
                cin >> shopChoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << ">> Invalid input! Please enter a number.\n";
                    continue;
                }

                if (shopChoice == 1) {
                    int p_id;
                    cout << ">> Enter product ID: ";
                    cin >> p_id;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << ">> Invalid ID! Please enter a number.\n";
                        continue;
                    }

                    bool found = false;
                    for (int i = 0; i < (int)storeProducts.size(); i++) {
                        if (storeProducts[i].id == p_id) {
                            myCart.addProduct(storeProducts[i]);
                            found = true; break;
                        }
                    }
                    if (!found) cout << ">> There is no product code for this product\n";

                } else if (shopChoice == 2) {
                    if (myCart.cartItems.empty()) {
                        cout << ">> The basket is empty; there are no items to remove\n";
                    } else {
                        int p_id;
                        cout << ">> Enter remove product : ";
                        cin >> p_id;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << ">> Invalid ID! Please enter a number.\n";
                            continue;
                        }
                        myCart.removeProduct(p_id);
                    }

                } else if (shopChoice == 0) {
                    cout << ">> Back...\n";
                    break;
                } else {
                    cout << ">> Please select the correct item\n";
                }
            }

        } else if (choice == 3) {
            // Cream and carrot ทำตรงนี้ <<---
            cout << ">> Checkout system coming soon...\n";

        } else if (choice == 4) {
            Admin admin;
            string u, p;

            cout << "\n========== ADMIN LOGIN ==========\n";
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;

            if (admin.login(u, p)) {
                cout << ">> Login successful! Welcome Admin.\n";
                bool adminRunning = true;
                while (adminRunning) {
                    cout << "\n[1] Random discount code\n";
                    cout << "[2] Delete discount code\n";
                    cout << "[3] View all discount codes\n";
                    cout << "[0] Lockout\n";

                    int adminChoice = -1;
                    while (true) {
                        cout << "Select menu: ";
                        string inputStr;
                        cin >> inputStr;

                        bool isValid = !inputStr.empty();
                        for (char c : inputStr) {
                            if (!isdigit(c)) { isValid = false; break; }
                        }

                        if (!isValid) {
                            cout << ">> verify the number only!\n";
                            cout << "--------------------------\n";
                            continue;
                        }

                        adminChoice = stoi(inputStr);
                        if (adminChoice < 0 || adminChoice > 3) {
                            cout << ">> verify the number only 0 - 3!\n";
                            continue;
                        }
                        break;
                    }

                    if (adminChoice == 1) {
                        srand(time(0));
                        int discountPercent;
                        string inputStr;

                        while (true) {
                            cout << "enter the discount percentage: ";
                            cin >> inputStr;

                            bool isValidNumber = !inputStr.empty();
                            for (char c : inputStr) {
                                if (!isdigit(c)) {
                                    isValidNumber = false;
                                    break;
                                }
                            }

                            if (!isValidNumber) {
                                cout << ">> verify the number only!\n";
                                continue;
                            }

                            discountPercent = stoi(inputStr);

                            if (discountPercent < 1 || discountPercent > 100) {
                                cout << ">> verify the number only 1 - 100!\n";
                                continue;
                            }

                            break;
                        }

                        int randomNumber = rand() % 10000;
                        string discountCode = "SAVE" + to_string(discountPercent) + to_string(randomNumber);

                        cout << "\n====== DISCOUNT CODE GENERATED ======\n";
                        cout << "CODE: " << discountCode << endl;
                        cout << "Discount: " << discountPercent << "%\n";
                        cout << "=====================================\n";

                        ofstream file("discount_codes.txt", ios::app);
                        if (file.is_open()) {
                            file << discountCode << "," << discountPercent << "\n";
                            file.close();
                            cout << ">> Saved to discount_codes.txt successfully!\n";
                        } else {
                            cout << ">> Error opening file!\n";
                        }

                    } else if (adminChoice == 2) {
                        bool deletingMore = true;
                        while (deletingMore) {
                            ifstream fileIn("discount_codes.txt");
                            if (!fileIn.is_open()) {
                                cout << ">> No discount codes found!\n";
                                break;
                            }

                            vector<string> lines;
                            string line;

                            cout << "\n====== DISCOUNT CODES LIST ======\n";
                            int i = 1;
                            while (getline(fileIn, line)) {
                                int commaPos = line.find(',');
                                if (commaPos != (int)string::npos) {
                                    string code = line.substr(0, commaPos);
                                    string percent = line.substr(commaPos + 1);
                                    cout << "[" << i++ << "] Code: " << code << " | Discount: " << percent << "%\n";
                                } else {
                                    cout << "[" << i++ << "] " << line << "\n";
                                }
                                lines.push_back(line);
                            }
                            fileIn.close();

                            if (lines.empty()) {
                                cout << ">> No discount codes available.\n";
                                break;
                            }

                            cout << "=================================\n";

                            int delChoice = -1;
                            while (true) {
                                cout << "Enter line number to delete (0 to cancel): ";
                                string inputStr;
                                cin >> inputStr;

                                bool isValid = !inputStr.empty();
                                for (char c : inputStr) {
                                    if (!isdigit(c)) { isValid = false; break; }
                                }

                                if (!isValid) {
                                    cout << ">> verify the number only!\n";
                                    continue;
                                }

                                delChoice = stoi(inputStr);
                                if (delChoice < 0 || delChoice > (int)lines.size()) {
                                    cout << ">> verify the number only 0 - " << lines.size() << "!\n";
                                    continue;
                                }
                                break;
                            }

                            if (delChoice >= 1 && delChoice <= (int)lines.size()) {
                                lines.erase(lines.begin() + delChoice - 1);
                                ofstream fileOut("discount_codes.txt");
                                if (fileOut.is_open()) {
                                    for (const string& l : lines) fileOut << l << "\n";
                                    fileOut.close();
                                    cout << ">> Discount code deleted successfully!\n";
                                } else {
                                    cout << ">> Error writing to file!\n";
                                    break;
                                }
                                if (lines.empty()) {
                                    cout << ">> No more discount codes available.\n";
                                    break;
                                }

                                int continueChoice = -1;
                                while (true) {
                                    cout << "\n[1] Delete another code\n[0] Back\nSelect: ";
                                    string inputStr;
                                    cin >> inputStr;

                                    bool isValid = !inputStr.empty();
                                    for (char c : inputStr) {
                                        if (!isdigit(c)) { isValid = false; break; }
                                    }

                                    if (!isValid) {
                                        cout << ">> verify the number only!\n";
                                        continue;
                                    }

                                    continueChoice = stoi(inputStr);
                                    if (continueChoice != 0 && continueChoice != 1) {
                                        cout << ">> verify the number only 1 or 0!\n";
                                        continue;
                                    }
                                    break;
                                }

                                if (continueChoice != 1) deletingMore = false;

                            } else if (delChoice == 0) {
                                cout << ">> Cancelled.\n";
                                deletingMore = false;
                            } else {
                                cout << ">> Invalid selection.\n";
                            }
                        }

                    } else if (adminChoice == 3) {
                        ifstream fileIn("discount_codes.txt");
                        if (!fileIn.is_open()) {
                            cout << ">> No discount codes found!\n";
                        } else {
                            vector<string> lines;
                            string line;
                            while (getline(fileIn, line)) lines.push_back(line);
                            fileIn.close();

                            if (lines.empty()) {
                                cout << ">> No discount codes available.\n";
                            } else {
                                cout << "\n====== ALL DISCOUNT CODES ======\n";
                                for (int i = 0; i < (int)lines.size(); i++) {
                                    int commaPos = lines[i].find(',');
                                    if (commaPos != (int)string::npos) {
                                        string code = lines[i].substr(0, commaPos);
                                        string percent = lines[i].substr(commaPos + 1);
                                        cout << "[" << i+1 << "] Code: " << code << " | Discount: " << percent << "%\n";
                                    } else {
                                        cout << "[" << i+1 << "] " << lines[i] << "\n";
                                    }
                                }
                                cout << "================================\n";
                            }

                            while (true) {
                                cout << "\n[0] Back\nSelect: ";
                                string inputStr;
                                cin >> inputStr;

                                bool isValid = !inputStr.empty();
                                for (char c : inputStr) {
                                    if (!isdigit(c)) { isValid = false; break; }
                                }

                                if (!isValid) {
                                    cout << ">> verify the number only!\n";
                                    continue;
                                }

                                int viewChoice = stoi(inputStr);
                                if (viewChoice != 0) {
                                    cout << ">> verify the number only 0!\n";
                                    continue;
                                }
                                break;
                            }
                        }

                    } else if (adminChoice == 0) {
                        cout << ">> Exit successful!\n";
                        adminRunning = false;
                    }
                }
            } else {
                cout << ">> Login failed! Incorrect username or password.\n";
            }

        } else if (choice == 0) {
            cout << ">> Close program...\n";
            break;
        } else {
            cout << ">> Please select the correct menu !!\n";
        }
    }
    return 0;
}