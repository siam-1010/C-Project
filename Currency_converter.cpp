#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

void showMenu();
double convertCurrency(double amount, string from, string to, map<string, double> &rates);

int main() {
    map<string, double> exchangeRates = {
        {"USD", 1.0},      // Base currency
        {"EUR", 0.91},     // 1 USD = 0.91 EUR
        {"GBP", 0.78},     // 1 USD = 0.78 GBP
        {"JPY", 136.5},    // 1 USD = 136.5 JPY
        {"INR", 83.2},     // 1 USD = 83.2 INR
        {"BDT", 108.6},    // 1 USD = 108.6 BDT
        {"PKR", 284.7},    // 1 USD = 284.7 PKR
        {"SAR", 3.75}      // 1 USD = 3.75 SAR
    };

    string fromCurrency, toCurrency;
    double amount;

    showMenu();

    cout << "Enter the currency you have (USD, EUR, GBP, JPY, INR, BDT, PKR, SAR): ";
    cin >> fromCurrency;
    cout << "Enter the currency you want to convert to: ";
    cin >> toCurrency;
    cout << "Enter amount: ";
    cin >> amount;

    if (exchangeRates.find(fromCurrency) == exchangeRates.end() || exchangeRates.find(toCurrency) == exchangeRates.end()) {
        cout << "Invalid currency code. Please try again." << endl;
        return 1;
    }

    double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency, exchangeRates);

    cout << fixed << setprecision(2);
    cout << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << endl;

    return 0;
}

void showMenu() {
    cout << "******** Currency Converter ********" << endl;
    cout << "Available Currencies: USD, EUR, GBP, JPY, INR, BDT, PKR, SAR" << endl;
    cout << "************************************" << endl;
}

double convertCurrency(double amount, string from, string to, map<string, double> &rates) {
    double usdAmount = amount / rates[from]; // Convert to USD first
    return usdAmount * rates[to];           // Convert from USD to target currency
}
