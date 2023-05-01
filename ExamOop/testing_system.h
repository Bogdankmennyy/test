#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include <string>
#include <vector>
#include <unordered_map>

struct Test {
    std::string question;
    std::vector<std::string> options;
    int correct_answer;
};

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& name, const std::string& address, const std::string& phone_number);

    const std::string& get_username() const;
    const std::string& get_password() const;
    const std::string& get_name() const;
    const std::string& get_address() const;
    const std::string& get_phone_number() const;

private:
    std::string username_;
    std::string password_;
    std::string name_;
    std::string address_;
    std::string phone_number_;
};

class Admin {
public:
    Admin(const std::string& username, const std::string& password);

    void add_user(const User& user);
    void remove_user(const std::string& username);
    void modify_user(const User& user);

    void add_category(const std::string& category);
    void remove_category(const std::string& category);

    void add_test(const std::string& category, const Test& test);
    void remove_test(const std::string& category, int test_number);

    void export_tests(const std::string& filename);
    void import_tests(const std::string& filename);

    void export_statistics(const std::string& filename);

private:
    std::string username_;
    std::string password_;

    std::unordered_map<std::string, User> users_;
    std::unordered_map<std::string, std::vector<Test>> categories_;
};

class TestSystem {
public:
    TestSystem();

    bool login(const std::string& username, const std::string& password);
    void logout();

    const std::vector<std::string>& get_categories() const;
    const std::vector<Test>& get_tests(const std::string& category) const;

    void start_test(const std::string& category);
    bool answer_question(int answer);
    void end_test();

    bool is_logged_in() const;
    const std::string& get_username() const;
    const User& get_user() const;
    const std::vector<std::pair<std::string, int>>& get_test_results() const;

private:
    std::string username_;
    User user_;
    std::vector<std::pair<std::string, int>> test_results_;

    bool is_logged_in_;
    bool is_admin_;
    Admin admin_;

    std::vector<std::string> categories_;
    std::unordered_map<std::string, std::vector<Test>> tests_;
    std::unordered_map<std::string, std::vector<bool>> answers_;
    std::string current_category_;
    int current_question_;
};

#endif // TEST_SYSTEM_H
