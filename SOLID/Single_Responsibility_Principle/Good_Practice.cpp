#include<iostream>
#include<vector>
using namespace std;
class Product{
    public:
    string name;
    int price;
    Product(string name, int price)
    {
        this->name=name;
        this->price=price;
    }
};
//1. ShoppingCart: Only responsible for Cart related business logic
class ShoppingCart{
    private:
    vector<Product*> products; //Store heap-allocated products;
    public:
    void addProduct(Product* p)
    {
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }
    //Calculates total price in cart
    double calculateTotal(){
        double total=0;
        for(auto p: products)
        {
            total+= p->price;
        }
        return total;
    }
};

//2. ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter{
    private:
    ShoppingCart* cart;
    public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }
    void printInvoice(){
        cout<<"Shopping Cart Invoice:\n";
        for(auto p: cart->getProducts()){
            cout<<p->name<<" -$"<<cart->calculateTotal()<<endl;
        }
    }
};
//3.ShoppingCartStorage: Only Responsible for saving cart to DB
class ShoppingCartStorage{
    private:
    ShoppingCart* cart;

    public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart=cart;
    }
    void saveToDatabase(){
        cout<<"Saving shopping cart to database..."<<endl;
    }
};
int main()
{
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",500));
    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();
    return 0;
}