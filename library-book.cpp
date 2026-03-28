class book{
private:
  string id;
  string title;
  string author;
  string genre;
  bool is_available;
  void update const(string message){
    cout<<message<<endl;
  }

public:
  //deafult
  book(){
    id = "AAA000";
    title = "NA";
    author = "Unknown";
    genre = "NA";
    is_available = "false";
    update("Book: " + title + " added to inventory");
  }

  //parameterized
  book(string new_id, string new_title, string new_author, string new_genre, bool new_is_available){
    id = new_id;
    title = new_title;
    author = new_author;
    genre = new_genre;
    is_available = new_is_available;
    update("Book: " + title + " added to inventory");
  }

  //copy
  book(const book &existing_book){
    id = existing_book.id + "_copy";
    title = existing_book.title;
    author = existing_book.author;
    genre = existing_book.genre;
    is_available = existing_book.is_available;
    update("Copy of Book: " + existing_book.title + " added to inventory");
  }

  bool borrow_book(book){
    if(book.is_available){
      book.is_available = false;
      update("Book: " + book.title + "is allotted");
      return true;
    }
    update("Book: " + book.title + "is unavailable");
    return fasle;
  }

  bool return_book(book){
    


}
