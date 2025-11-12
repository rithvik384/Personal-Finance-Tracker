#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Transaction
{
    string type;
    string category;
    double amount;
};

void addTransaction(vector<Transaction>& transactions);
void viewTransactions(const vector<Transaction>& transactions);
void viewSummary(const vector<Transaction>& transactions);
void sortByCategory(vector<Transaction>& transactions);

int main()
{
    vector<Transaction> transactions;
    int choice;

    do
    {
        cout<<"\n=== Personal Finance Tracker ===\n";
        cout<<"1. Add Transaction\n";
        cout<<"2. View All Transactions\n";
        cout<<"3. View Summary\n";
        cout<<"4. Sort by Category\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                addTransaction(transactions);
                break;
            case 2:
                viewTransactions(transactions);
                break;
            case 3:
                viewSummary(transactions);
                break;
            case 4:
                sortByCategory(transactions);
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}

void addTransaction(vector<Transaction>& transactions)
{
    Transaction t;
    cout<<"Enter type (Income/Expense): ";
    cin>>t.type;
    cout<<"Enter category: ";
    cin>>t.category;
    cout<<"Enter amount: ";
    cin>>t.amount;

    transactions.push_back(t);
    cout<<"Transaction added successfully!\n";
}

void viewTransactions(const vector<Transaction>& transactions)
{
    if(transactions.empty())
    {
        cout << "No transactions to show.\n";
        return;
    }
    cout<<"\nAll Transactions:\n";
    cout<<"Type\tCategory\tAmount\n";
    cout<<"--------------------------------\n";
    for(const auto& t : transactions)
    {
        cout << t.type << "\t" << t.category << "\t\t" << t.amount << "\n";
    }
}

void viewSummary(const vector<Transaction>& transactions)
{
    double totalIncome = 0, totalExpense = 0;
    for(const auto& t : transactions)
    {
        if(t.type == "Income" || t.type == "income") totalIncome += t.amount;
        else if(t.type == "Expense" || t.type == "expense") totalExpense += t.amount;
    }
    cout << "\n=== Summary ===\n";
    cout << "Total Income: " << totalIncome << "\n";
    cout << "Total Expense: " << totalExpense << "\n";
    cout << "Balance: " << totalIncome - totalExpense << "\n";
}

void sortByCategory(vector<Transaction>& transactions)
{
    sort(transactions.begin(), transactions.end(), [](const Transaction& a, const Transaction& b)
    {
        return a.category < b.category;
    });
    cout << "Transactions sorted by category.\n";
}