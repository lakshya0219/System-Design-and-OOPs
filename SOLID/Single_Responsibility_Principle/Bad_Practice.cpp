// Single Responsibility Principle:
//  It states that a class should have only one reason to change.
//  A class should do only one thing.
#include<iostream>
#include<vector>
using namespace std;
class Product{
    public:
     string name;
     double price;
     Product(string name, double price)
     {
        this->name=name;
        this->price=price;
     }
};
//Violating SRP: ShoppingCart is handling multiple responsibility
class ShoppingCart{
    private:
    vector<Product*> products;
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
            total+=p->price;
        }
     }
     //2. Violating SRP - Prints invoice (Should be in a separate class)
     void printInvoice()
     {
        cout<<"Shopping cart invoice:\n";
        for(auto p: products){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
     }
     //3. Violating SRP - Save to DB (Should be in a separate class)
     void saveToDatabase()
     {
        cout<<"Saving shopping cart to database..."<<endl;
     }
};
int main()
{
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",100));
    cart->addProduct(new Product("Keyboard",500));
    cart->printInvoice();
    cart->saveToDatabase();
    return 0;
}