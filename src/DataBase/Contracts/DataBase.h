//
// Created by alro on 28‏/11‏/2020.
//

#ifndef MYPROJECT_DATABASE_H
#define MYPROJECT_DATABASE_H

#include <sqlite3.h>
#include <memory>
#include <string_view>
#include <vector>
#include <map>
#include <functional>
using namespace std;

typedef map<string, string> string_map;
typedef pair<string, string> string_pair;

class DataBase {
private:

    string db_path;

    bool is_db_initialised;

    unique_ptr<sqlite3 *> db;

    vector<string> tables_creation_sql;

    bool create_table_from_sql(string_view sql);

    bool activate_foreign_keys();

    [[nodiscard]] string get_insert_sql(string_view table_name, const string_map &map) const;

    static string get_update_sql(string_view table_name, const string_pair &feature, const string_map &map);

    bool
    execute_sql(string_view sql, string_view success_msg, const function<bool(string_view)> &do_if_error,
                const function<bool(const string_map&)> &callback);

public:

    explicit DataBase(string_view dbPath);

    string_view get_db_path();

    virtual ~DataBase();

    bool insert_into_table(string_view table_name, const string_map &map);

    bool update_into_table(string_view table_name, const string_pair &select_feature, const string_map &map);

    bool delete_by_feature(string_view table_name, const string_pair &feature);

    bool init_db();

    bool begin_transaction();

    bool end_transaction();

    void add_table_creation_sql(string_view sql);

    string_map get_by_id(string_view table_name, string_view id);

    time_t string_to_time_t(string_view string);

    vector<string_map> get_all_by_feature(string_view table_name, const string_pair &feature);

    vector<string_map> get_all(string_view table_name);

    static string to_sql_string(string_view s);

    static string to_sql_date_time(time_t t);



};








#endif //MYPROJECT_DATABASE_H
