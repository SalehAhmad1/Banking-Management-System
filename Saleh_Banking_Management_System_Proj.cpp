#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;
class Address
{
    string City,Country;

    public:
    Address():City(),Country() { }
    Address(string city, string country): City(city), Country(country) { }
    string get_city(){return City;}
    string get_country(){return Country;}
    friend ostream& operator<<(ostream& out, Address &temp)
    {
        out<<temp.City<<" "<<temp.Country;
        return out;
    } 
    void operator=(Address &temp)
    {
        City = temp.City;
        Country = temp.Country;
    }
    void setCity(string CITY)
    {
        City = CITY;
    }
    void setCountry(string Country)
    {
        this->Country = Country;
    }
};
class Bank
{
    string Name,ManagerName;
    Address Location;
    int Code;

    public:
    Bank():Name(nullptr),ManagerName(nullptr),Location(nullptr,nullptr), Code(0) { }
    Bank(string name, string ManagerName, string city, string country, int code): Name(name), ManagerName(ManagerName),Location(city, country),Code(code)  { }
    friend ostream& operator<<(ostream &out,Bank &temp)
    {
        out<<"Name of Bank: "<<temp.Name<<", Manager Name: "<<temp.ManagerName<<", Location-> City: "<<temp.Location.get_city()<<" Country: "<<temp.Location.get_country()<<" "<<temp.Code<<endl;
        return out;
    }
};
class transactions
{
    double *Arr;
    int amount;

    public:
    transactions() {amount = 0;}
    transactions(int amount)
    { 
        this->amount = amount;
        Arr = new double[amount];
    }
    friend ostream& operator<<(ostream &out, transactions &temp)
    {
        if(temp.amount > 0)
        {
            for(int j = 0; j < temp.amount; ++j)
            out<<temp.Arr[j]<<" ";
        }
        else    
        cout<<"No Transactions Done at the Moment";
        return out;
    }
    int getAmount() const 
    {
		return amount;
	}
	void setAmount(int amount) 
    {
		this->amount = amount;
        this->Arr = new double[amount];
	}
	double* getArr() const 
    {
		return Arr;
	}
	void setArr(double *arr) 
    {
		Arr = arr;
	}
    double operator[](int index)
    {
        return Arr[index];
    }   
    void addTransaction(long double value)
    {
        if(this->amount == 0)
        {
            delete[] Arr;
            amount++;
            Arr = new double[amount];
            Arr[0] = value;
        }
        else
        {
            transactions tmp(amount);
            for(int i = 0; i < amount; ++i)
            tmp.Arr[i] = Arr[i];
            
            amount++;
            delete[] Arr;
            Arr = new double[amount];
            for(int i = 0; i < amount-1; ++i)
            Arr[i] = tmp.Arr[i];
            Arr[amount-1] = value;
        }
    }
    void WriteIntoFile()
    {
        ofstream ofs;
        ofs.open("Transactions.txt",ios::app);
        for(int i = 0; i < amount; ++i)
        ofs<<Arr[i]<<"\n";
    }
    void operator=(transactions &temp)
    {
        this->amount = temp.amount;
        Arr = new double[amount];
        for(int i = 0; i < amount; ++i)
        Arr[i] = temp.Arr[i];
    }
    void operator()(int index,double value)
    {
        Arr[index] = value;
    }
};
class Finances
{
    long double amount;
    public:
    Finances( ){amount = 0.0; }
    Finances(long double Amount): amount(Amount) { }
    friend ostream& operator<<(ostream &out, Finances &temp)
    {
        out<<temp.amount;
        return out;
    }
    long double getAmount() const
    {
        return amount;
    }
    void WithdrawAmount(long double sum)
    {
        amount -= sum;
    }
    void DepositAmount(long double sum)
    {
        amount += sum;
    }
    void operator=(Finances &temp)
    {
        amount = temp.amount;
    }
    void setFinances(double amount)
    {
        this->amount = amount;
    }
};
class BioData
{
    string Name,ID_Card;
    int age;
    Address address;

    public:
    BioData() {  }
    BioData(string name, string idcard, int age, string City,string Country): Name(name),ID_Card(idcard),age(age),address(City,Country) { }
    friend ostream& operator<<(ostream& out, BioData &temp)
    {
        out<<temp.Name<<" "<<temp.address<<" "<<temp.age<<" "<<temp.ID_Card;
        return out;
    } 
    void operator=(BioData& temp)
    {
        Name = temp.Name;
        ID_Card = temp.ID_Card;
        age = temp.age;
        address.operator=(temp.address);
    }
    void setName(string name)
    {
        Name = name;
    }
    void setID(string id)
    {
        ID_Card = id;
    }
    void setAge(int Age)
    {
        age = Age;
    }
    void setAddress(string CITY, string COUNTRY)
    {
        address.setCity(CITY);
        address.setCountry(COUNTRY);
    }
    Address getAddress()
    {
		return address;
	}
	int getAge()
    {
		return age;
	}
	string& getIdCard()
    {
		return ID_Card;
	}
	string& getName()
    {
		return Name;
	}
};
class Account
{
    protected:
    string type,ownerName;
    int accountID;
    Finances finances;
    transactions Transactions;

    public:
    Account():finances(0),Transactions() { }
    Account(string type, string name,int ID,double amount):ownerName(name), accountID(ID),finances(amount),type(type) { }
    friend ostream& operator<<(ostream& out, Account &temp)
    {
        out<<temp.type<<" "<<temp.ownerName<<" "<<temp.accountID<<" "<<temp.finances<<" "<<temp.Transactions;
        return out;
    }
    void operator=(Account &temp)
    {
        type = temp.type;
        ownerName = temp.ownerName;
        accountID = temp.accountID;
        finances = temp.finances;
        Transactions = temp.Transactions;
    }
    int getAccountId() const 
    {
		return accountID;
	}
	void setAccountId(int accountId) 
    {
		accountID = accountId;
	}
	Finances& getFinances()
    {
		return finances;
	}
    void setAmount(int num)
    {
        Transactions.setAmount(num);
    }
	void setFinances(double finances) 
    {
		this->finances.setFinances(finances);
	}
	string getOwnerName() const 
    {
		return ownerName;
	}
	void setOwnerName(string ownerName) 
    {
		this->ownerName = ownerName;
	}
	transactions& getTransactions()
    {
		return this->Transactions;
	}
	void setTransactions(transactions &ttransactions) 
    {
		Transactions.operator=(ttransactions);
	}
	string getType() const 
    {
		return type;
	}
	void setType(string type) 
    {
		this->type = type;
	}
    void WithdrawAmount(long double amount)
    {
        while(amount <= 0)
        {
            cout<<"Withdraw amount cannot be less than or equal to 0. Input again: ";
            cin>>amount;
        }
        Transactions.addTransaction(-amount);
        finances.WithdrawAmount(amount);
    }
    void DepositAmount(long double amount)
    {
        while(amount <= 0)
        {
            cout<<"Withdraw amount cannot be less than or equal to 0. Input again: ";
            cin>>amount;
        }
        Transactions.addTransaction(+amount);
        finances.DepositAmount(amount);
    }
};
class CurrentAccount: public Account
{
    protected:

    public:
    CurrentAccount() {}
    CurrentAccount(string name, int ID,long double amount):Account("Current",name,ID,amount) { }
    void operator=(CurrentAccount &temp)
    {
        type = temp.type;
        ownerName = temp.ownerName;
        type = temp.type;
        accountID = temp.accountID;
        finances.operator=(temp.finances);
        Transactions.operator=(temp.Transactions);
    }
    friend ostream& operator<<(ostream&out, CurrentAccount &temp)
    {
        out<<"Owner Name: "<<temp.ownerName<<" Type: "<<temp.type<<" Account Id: "<<temp.accountID<<" Finances(Net Amount): "<<temp.finances<<" Transactions -> "<<temp.Transactions<<" ";
        return out;
    }
};
class SavingsAccount: public Account
{
    protected:

    public:
    SavingsAccount() {}
    SavingsAccount(string name, int ID,long double amount):Account("Savings",name,ID,amount){ }
    void operator=(SavingsAccount &temp)
    {
        type = temp.type;
        ownerName = temp.ownerName;
        type = temp.type;
        accountID = temp.accountID;
        finances.operator=(temp.finances);
        Transactions.operator=(temp.Transactions);
    }
    friend ostream& operator<<(ostream&out, SavingsAccount &temp)
    {
        out<<"Owner Name: "<<temp.ownerName<<" Type: "<<temp.type<<" Account Id: "<<temp.accountID<<" Finances(Net Amount): "<<temp.finances<<" Transactions -> "<<temp.Transactions<<" ";
        return out;
    }
};
class Person
{
    public:
    BioData Bio_Data;
    Account *account;

    public:
    Person():account(new Account),Bio_Data() { }
    Person(string name, string idcard, int age, string City, string Country,string type,int Id,double amount):Bio_Data(name,idcard,age,City,Country) { account = new Account(type,name,Id,amount); }
    Account& getAccount()
    {
		return *account;
	}
	const BioData& getBioData() const 
    {
		return Bio_Data;
	}
};
class Customer: public Person
{
    public:
    Customer() { }
    Customer(string name, string idcard, int age, string City, string Country,string type, int Id, long double amount):Person(name,idcard,age,City,Country,type,Id,amount) { }
    friend ostream& operator<<(ostream& out,Customer &temp)
    {
        out<<temp.Bio_Data<<endl;
        out<<*(temp.account)<<endl;
        return out;
    }
    void operator=(Customer &temp)
    {
        Bio_Data.operator=(temp.Bio_Data);
        account->operator=(*(temp.account));
    }
    void setBioData(string name, string id, int age, string city, string country)
    {
        Bio_Data.setAge(age);
        Bio_Data.setName(name);
        Bio_Data.setID(id);
        Bio_Data.setAddress(city,country);
    }
    void setAccount(string name, string type, int id, double amount)
    {
        account->setOwnerName(name);
        account->setType(type);
        account->setAccountId(id);
        account->setFinances(amount);
    }
    void WriteIntoFile()
    {
        ofstream ofs;
        ofs.open("CustomersData.txt",ios::app);
        ofs<<Bio_Data.getName()<<","<<Bio_Data.getIdCard()<<","<<Bio_Data.getAge()<<","<<Bio_Data.getAddress().get_city()<<","<<Bio_Data.getAddress().get_country()<<",";
        ofs<<account->getType()<<","<<account->getOwnerName()<<","<<account->getAccountId()<<","<<account->getFinances().getAmount()<<",";
        if(account->getTransactions().getAmount() > 0)
        {
            for(int i = 0; i < account->getTransactions().getAmount(); ++i)
            ofs<<account->getTransactions().operator[](i)<<",";
        }
        ofs<<"--,";
    }
};
class All_Accounts
{
    protected:
    Account **All_Arr;//Array of pointers
    int size;

    public:
    All_Accounts():All_Arr(nullptr),size(0) { }
    All_Accounts(int size,Account *temp)
    {
        All_Arr = new Account*[size];
        All_Arr[0] = temp;
        this->size = size;
    }
    void Display_All_Account_Details()
    {
        cout<<endl<<*this<<endl;
    }
    friend ostream& operator<<(ostream&out, All_Accounts &temp)
    {
        for(int i = 0; i < temp.size; ++i)
        out<<*(temp.All_Arr[i])<<endl;
        return out;
    }
    Account& get_Account()
    {
        return **All_Arr;
    }
};
Customer OpenAccount()
{
    Customer customer("Wadood","1010-21",20,"Islamabad","Pakistan","Current",1,1000);
    // cout<<endl<<customer<<endl;
    return customer;
}
int display_menu()
{
    int choice = 0;
    cout<<"1) Account Opening 2) Amount Withdrawl 3) Amount Deposit 4) Transactions Recepit 5) Account Deletion 6) Exit:\n";
    cin>>choice;
    while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
    {
        cout<<"Enter [1/2/3/4/5/6]: ";
        cin>>choice;
    }
    return choice;
}
void FillCharArray(char name[], string Name)
{
    for(int i = 0; i < Name.length(); ++i)
    name[i] = Name[i];
}
void ReadPreviousCustomersNum(int &count)
{
    ifstream ifs;
    ifs.open("NumCustomers.txt");
    if(ifs.is_open())
    {
        while(!ifs.eof())
        {
            ifs>>count;
            break;
        }
        ifs.close();
    }
    else
    {
        ofstream ofs;
        ofs.open("NumCustomers.txt",ios::trunc);
        ofs<<0;
        ofs.close();
    }
}
void ReadDataPreviousCustomers(Customer *customer,int &count)
{
    ifstream ifs;
    ifs.open("CustomersData.txt");
    int index = 0;
    while(!ifs.eof())
    {
        if(index == count)
        break;

        else
        {
            int age = 0;
            char comma;
            string data_Bio[4];
            getline(ifs,data_Bio[0],','); //Name
            getline(ifs,data_Bio[1],','); //Id
            ifs>>age; //Age
            ifs.get(comma); //comma
            getline(ifs,data_Bio[2],','); //City
            getline(ifs,data_Bio[3],','); //Country
            customer[index].setBioData(data_Bio[0],data_Bio[1],age,data_Bio[2],data_Bio[3]);

            string data_accounts[2];
            int id;
            double amount;
            char temp;
            getline(ifs,data_accounts[0],',');//Type
            getline(ifs,data_accounts[1],',');//Owner Name
            ifs>>id; //id
            ifs>>temp; //comma
            ifs>>amount; //amount

            string get = " ";
            ofstream ofs;
            static int numTransactions = 0;
            ofs.open("Transactions.txt",ios::app);
            getline(ifs,get,',');
            while(get != "--")
            {
                getline(ifs,get,',');

                if(get == "--")
                break;

                else
                {
                    ofs<<get<<endl;
                    numTransactions++;
                }
            }
            // if(get == "--")
            // ofs<<"-----------"<<endl;

            customer[index].setAccount(data_accounts[0],data_accounts[1],id,amount);

            ifstream ifss;
            ifss.open("Transactions.txt");
            double trans = 0;
            int subscript = 0, lines = 0;
            
            customer[index].getAccount().getTransactions().setAmount(numTransactions);
            while(lines < numTransactions)
            {
                ifss>>trans;
                lines++;
                customer[index].getAccount().getTransactions().operator()(subscript,trans);
                subscript++;
            }
            getline(ifss,get);
            cout<<endl;
            numTransactions = 0;
            index++;
        }
    }
    ifs.close();
}
void createNewAccount(Customer *customer, int &count)
{
    string name;
    string id;
    int age;
    string city;
    string country;
    string account_type;
    int acountID;
    double initialAmount;

    cout<<"\nEnter name of the customer: ";
    cin.ignore();
    getline(cin,name);

    cout<<"Enter id of "<<name<<" : ";
    cin>>id;

    cout<<"Enter age of "<<name<<" : ";
    cin>>age;

    cout<<"Enter city of "<<name<<" : ";
    cin>>city;
    
    cout<<"Enter country of "<<name<<" : ";
    cin>>country;
    
    cout<<"Enter account type of "<<name<<" : ";
    cin>>account_type;

    cout<<"Enter initial deposit amount of "<<name<<" : ";
    cin>>initialAmount;
    
    Customer temp(name,id,age,city,country,account_type,count+1,initialAmount);
    Customer *temp_arr;
    if(count > 0)
    {
        temp_arr = new Customer[count];
        for(int i = 0; i < count; ++i)
        temp_arr[i].operator=(customer[i]);
    }

    customer = new Customer[++count];
    cout<<"\nNum of Customers after new Account opening: "<<count<<endl<<endl;

    for(int i = 0; i < (count-1); ++i)
    customer[i].operator=(temp_arr[i]);
    customer[count-1].operator=(temp);

    for(int i = 0; i < count; ++i)
    cout<<endl<<customer[i]<<endl<<endl;

    ofstream ofs;
    ofs.open("NumCustomers.txt",ios::trunc);
    ofs<<count;
    ofs.close();

    ofs.open("CustomersData.txt",ios::trunc);
    ofs.close();
    for(int i = 0; i < count; ++i)
    customer[i].WriteIntoFile();
}
int main()
{
    Bank B("Wells Fargo","Saleh Ahmad","Las Vegas","USA", 1);
    cout<<B<<endl;

    int count = 0;
    ReadPreviousCustomersNum(count);

    Customer *customer = new Customer[count];

    if(count > 0)
    ReadDataPreviousCustomers(customer,count);
    else
    cout<<"\nCannot create array because there is no data of customers in data-base\n\n";
    
    int choice = display_menu();
    cout<<endl;
    switch(choice)
    {
        case 1: //Create account
        {
            createNewAccount(customer,count);
            break;
        }

        case 2: //Withdraw amount from a customers bank acount
        {
            int id;
            cout<<"Enter your account id: ";
            cin>>id;
            double amount;
            cout<<"How much amount do you want to withdraw? ";
            cin>>amount;
            bool check = 0;
            for(int i = 0; i < count; ++i)
            {
                if(customer[i].getAccount().getAccountId() == id)
                {
                    customer[i].getAccount().WithdrawAmount(amount);
                    cout<<"Amount has been withdrawn\n";
                    check = 1;
                    break;
                }
            }
            if(check == 0)
            cout<<"No such account found\n";

            ofstream ofs;
            ofs.open("CustomersData.txt",ios::trunc);
            ofs.close();

            for(int i = 0; i < count; ++i)
            customer[i].WriteIntoFile();
            
            ofs.open("Transactions.txt",ios::trunc);
            ofs.close();

            for(int i = 0; i < count; ++i)  
            customer[i].getAccount().getTransactions().WriteIntoFile();
            break;
        }

        case 3: //Deposit amount to a customers bank account
        {
            int id;
            cout<<"Enter your account id: ";
            cin>>id;
            double amount;
            cout<<"How much amount do you want to Deposit? ";
            cin>>amount;
            bool check = 0;
            for(int i = 0; i < count; ++i)
            {
                if(customer[i].getAccount().getAccountId() == id)
                {
                    customer[i].getAccount().DepositAmount(amount);
                    cout<<"Amount has been Deposited\n";
                    check = 1;
                    break;
                }
            }
            if(check == 0)
            cout<<"No such account found\n";

            ofstream ofs;
            ofs.open("CustomersData.txt",ios::trunc);
            ofs.close();

            for(int i = 0; i < count; ++i)
            customer[i].WriteIntoFile();

            ofs.open("Transactions.txt",ios::trunc);
            ofs.close();

            for(int i = 0; i < count; ++i)  
            customer[i].getAccount().getTransactions().WriteIntoFile();
            break;
        }

        case 4: //Show transactions of a customer
        {
            int index;
            cout<<"Enter the customer's account id: ";
            cin>>index;
            for(int i = 0; i < count; ++i)
            {
                if(index == customer[i].getAccount().getAccountId())
                {
                    for(int j = 0; j < customer[i].getAccount().getTransactions().getAmount(); ++j)
                    {
                        double res;
                        res = customer[i].getAccount().getTransactions().operator[](j);
                        if(res < 0)
                        cout<<"Amount was Withdrawn: "<<res<<endl;
                        if(res > 0)
                        cout<<"Amount was Deposited: "<<res<<endl;   
                    }
                    break;
                }
            }
            break;
        }

        default:
        {
            cout<<"Exiting Menu\n";
            exit(0);
        }
    }
return 0;
}