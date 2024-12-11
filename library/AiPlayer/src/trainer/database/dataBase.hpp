#ifndef DATABASE_HPP
#define DATABASE_HPP

class DataBase {
  private:
      
  public:
    DataBase();
    int save();
    int load();
    ~DataBase() = default;
};

#endif // DATABASE_HPP
