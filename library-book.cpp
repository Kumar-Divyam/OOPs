class book{
private:
  string id;
  string title;
  string author;
  string genre;
  bool is_available;
  void update(string message) const{
    cout<<message<<endl;
  }

public:
  //deafult
  book(){
    id = "AAA000";
    title = "NA";
    author = "Unknown";
    genre = "NA";
    is_available = false;
    update("Book: " + title + " added to inventory successfully");
  }

  //parameterized
  book(string new_id, string new_title, string new_author, string new_genre, bool new_is_available){
    id = new_id;
    title = new_title;
    author = new_author;
    genre = new_genre;
    is_available = new_is_available;
    update("Book: " + title + " added to inventory successfully");
  }

  //copy
  book(const book &existing_book){
    id = existing_book.id + "_copy";
    title = existing_book.title;
    author = existing_book.author;
    genre = existing_book.genre;
    is_available = existing_book.is_available;
    update("Copy of Book: " + existing_book.title + " added to inventory successfully");
  }

  bool borrow_book(){
    if(is_available){
      is_available = false;
      update("Book: " + title + " is allotted successfully");
      return true;
    }
    update("Book: " + title + "is unavailable");
    return false;
  }

  void return_book(){
    if(is_available){
      update("Error - Book: " + title + "is already present");
      return;
    }
    is_available = true;
    update("Book: " + title + "is returned successfully");
  }

  void display_info() const{
    cout<<"ID: "<<id<<"\n"<<"Title: "<<title<<"\n"<<"Author: "<<author<<"\n"<<"Genre: "<<genre<<"\n";
    cout<<"Available: "<<if(is_available ? "Yes" : "No")<<endl;
  }

};
