#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Product { //class สินค้า
public:
    int id;
    string name;
    double price;

    Product(int P_id ,string P_name,double P_price) {
        id = P_id;
        name = P_name;
        price = P_price;
    }
    void displayProduct() const { // เอาไว้โชว์ 1 ชิ้น
        std::cout << "ID: " << left << setw(5) << id
                  << "| " << setw(30) << name
                  << "| Price: " << fixed << setprecision(2) << price << " Bath\n";
    }
    static void showAllProduct(const vector<Product>& vecProduct) { // // เอาไว้โชว์ทุกอัน
        cout << "================== STORE INVENTORY ==================" << endl;
        for (const auto& item : vecProduct) {
            item.displayProduct();
        }
        cout << "=====================================================\n";
    }
};

class Cart {
    public:
    vector<Product> cartItems; // vector จะคล้าย array อันนี้ getter มาจาก product

    void addProduct(Product p) { // for add ไอเทม
        cartItems.push_back(p);
        cout << ">> Added --> [" << p.name << "] to cart!\n";
    }

    void removeProduct(int productId) { //for remove
        for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
            if (it->id == productId) {
                cout << ">> remove --> [" << it->name << "] form cart!\n";
                cartItems.erase(it);
                return;
            }
        }
        cout << ">> Cart is empty\n";
    }

    void showCart() { // show item in cart
        if (cartItems.empty()) {
            cout << ">> Cart is empty\n";
            return;
        }
        cout << "\n================== CART ==================\n";
        for (int i = 0; i < cartItems.size(); i++) {
            cout <<"ID: "<< cartItems[i].id <<" - " << cartItems[i].name << " (" << cartItems[i].price << " Bath)\n";
        }
        cout << "=====================================================\n";
    }


};

//Class Admin สร้างตรงนี้

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
    // Product::showAllProduct(storeProduct); <<- เอาไว้โชว์ item ทุกชิ้น

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
        if (choice == 1) {
            Product::showAllProduct(storeProducts);
        } else if (choice==2) {

            while (true) {

                Product::showAllProduct(storeProducts);

                myCart.showCart();

                int shopChoice;
                cout << "\n[1] add  [2] remove  [0] back\n";
                cout << "Select menu : ";
                cin >> shopChoice;

                if (shopChoice == 1) {
                    int p_id;
                    cout << ">> Enter product ID: ";
                    cin >> p_id;

                    bool found = false;
                    for (int i = 0; i < storeProducts.size(); i++) {
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
                        myCart.removeProduct(p_id);
                    }

                } else if (shopChoice == 0) {
                    cout << ">> Back...\n";
                    break;
                } else {
                    cout << ">> Please select the correct item\n";
                }
            }

        } else if (choice==3) {

        } else if (choice==4) {
            //Crad ใส่ตรงนี้ อั้นนี้ของ Card!!! ดีจ้าาาาาthai
        } else if (choice==5) {

        } else if (choice==0) {
            cout << ">> Close program...\n";
            break;
        } else {
            cout << ">> Please select the correct menu !!\n";
        }
    }

}