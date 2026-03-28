struct date{
  int day;
  int month;
  int year;
};

class  account{
private:
  //attributes
  string acc_id;
  string acc_holder;
  double acc_balance;
  date acc_date_joined;

  //private only - anyone in the main() function could write myAccount.notify("You have 1 million dollars!"); and spoof a bank message!
  //as notify() is also called from a const method: a const method is only allowed to call other const methods.
  void notify const(string message){
    cout<<message<<endl;
  }

public:
  //constructor: types - default | parameterized | copy
  //default constructor
  account(){
    acc_id = "A00000";
    acc_holder = "Pending";
    acc_balance = 0.00;
    acc_date_joined = {1,1,2026};
    cout<<"dummy account created with id: "<<acc_id<<endl;
  }

  //parameterized constructor
  account(string id, string holder, double balance, date date_joined){
    acc_id = id;
    acc_holder = holder;
    acc_balance = balance;
    acc_date_joined = date_joined; 
    cout<<"Specific account created with id: "<<acc_id<<endl;
  }

  //copy constructor: 
/*The Ampersand (&) — "Pass by Reference"
Normally, when you pass a variable into a function in C++, the computer makes a temporary copy of that variable to work with.
However, if we tell the Copy Constructor to make a temporary copy of an account so that it can copy it, the computer has to call the Copy Constructor to make that temporary copy... which means it has to make another copy, which calls the constructor again, and again, forever. It's an infinite loop that crashes the program!
Using & tells the computer: "Don't make a copy! Just look directly at the original existing_account sitting in memory."

The const Keyword — "Look, but don't touch"
Since we are looking directly at the original account in memory, we want to be absolutely sure we don't accidentally ruin it while copying it. const locks the existing_account. If you accidentally typed existing_account.acc_balance = 0; inside this constructor, the compiler would throw an error and stop you from accidentally wiping out the original account's money.
*/
  account(const account &existing_acc){
    acc_id = existing_acc.acc_id + "_copy";
    acc_holder = existing_acc.acc_holder + "_copy";
    acc_balance = existing_acc.acc_balance;
    acc_date_joined = existing_acc.acc_date_joined; 
    cout<<"Copy account created with id: "<<acc_id<<endl;
  }

//METHODS
  bool deposit(double amount){
    if(amount <= 0.00){
      notify("Invalid amount");
      return false;
    }
    acc_balance += amount;
    string message = "Successfully credited ₹ " + to_string(amount) + " to your account";
    notify(message);
    return true;
  }

  bool withdraw(double amount){
    //assumption the amount withdrawn must be positive
    if(amount <= 0.00){
      notify("Invalid amount");
      return false;
    }
    if(acc_balance - amount < 0.00){
      notify("Insufficient balance");
      return false;
    }
    acc_balance -= amount;
    string message = "Successfully debited ₹ " + to_string(amount) + " from your account";
    notify(message);
    return true;    
  }

  /* When a method only reads data and doesn't change anything (like checking a balance), it's a great to put the word const
  at the end of the method signature. It tells the compiler - this function won't accidentally alter the account.
  */
  double get_balance() const{
    notify("Your cuurent balance is: ₹ " + to_string(acc_balance));
    return acc_balance;
  }

};
