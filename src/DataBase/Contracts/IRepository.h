//
// Created by alro on 25‏/11‏/2020.
//

#ifndef MYPROJECT_IREPOSITORY_H
#define MYPROJECT_IREPOSITORY_H
#include <vector>
#include <optional>
#include <Shared/CustomError.h>
#include <memory>
using namespace std;

template<class Entity>
class IRepository {
public:
    [[nodiscard]] virtual const string & get_table_name() const = 0;
    virtual bool save(const Entity&) = 0;
    virtual bool delete_by_id(unsigned int id) = 0;
    virtual optional<unique_ptr<Entity>> get_by_id(unsigned  int id) = 0;
    virtual vector<unique_ptr<Entity>> get_all() = 0;
};



#endif //MYPROJECT_IREPOSITORY_H
