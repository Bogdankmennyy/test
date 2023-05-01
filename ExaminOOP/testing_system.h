
#ifndef TESTING_SYSTEM_H
#define TESTING_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct UserInfo { 
    std::string fullName;
    std::string address;
    std::string phone;
    std::string password;
    std::string homeAddress;
    std::string phoneNumber;
    std::string category;
    std::string username;
};



struct TestResult {
    std::string category;
    int score;
};

class TestingSystem {
public:
    void registerUser(const std::string& username, const UserInfo& info, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    void logoutUser();
    void startTesting(const std::string& category);
    void viewTestResults();

    /*void addCategory(const std::string& category);
    void addTest(const std::string& category, const std::string& testName);
    void addQuestion(const std::string& category, const std::string& testName, const std::string& question, const std::vector<std::string>& options, int correctOptionIndex);
    void importTestsFromFile(const std::string& filename);
    void exportTestsToFile(const std::string& filename);*/

private:
    std::unordered_map<std::string, UserInfo> m_userDatabase;
    std::string m_currentUser;
    std::vector<TestResult> m_testResults;
    bool validateUsername(const std::string& username) const;

    /*struct Test {
        std::vector<std::string> questions;
        std::vector<std::vector<std::string>> options;
        std::vector<int> correctAnswers;*/
    //};
   /* std::unordered_map<std::string, std::vector<Test>> m_testsByCategory;*/

};


struct Question {
    std::string text;
    std::vector<std::string> choices;
    int correctChoiceIndex;
};

#endif








//#pragma once
//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <vector>
//
//class TestingSystem {
//public:
//    bool registerUser(const std::string& fullName, const std::string& homeAddress, const std::string& phoneNumber, const std::string& username, const std::string& password);
//    bool loginUser(const std::string& username, const std::string& password);
//    void startTesting(const std::string& category);
//
//private:
//    struct User {
//        std::string fullName;
//        std::string homeAddress;
//        std::string phoneNumber;
//        std::string password;
//    };
//    std::unordered_map<std::string, User> users;
//    std::string currentUser;
//};
//
//bool TestingSystem::registerUser(const std::string& fullName, const std::string& homeAddress, const std::string& phoneNumber, const std::string& username, const std::string& password) {
//    if (users.count(username) > 0) {
//        std::cout << "User with username '" << username << "' already exists." << std::endl;
//        return false;
//    }
//    User user;
//    user.fullName = fullName;
//    user.homeAddress = homeAddress;
//    user.phoneNumber = phoneNumber;
//    user.password = password;
//    users[username] = user;
//    std::cout << "User with username '" << username << "' registered successfully." << std::endl;
//    return true;
//}
//
//bool TestingSystem::loginUser(const std::string& username, const std::string& password) {
//    if (users.count(username) == 0) {
//        std::cout << "User with username '" << username << "' does not exist." << std::endl;
//        return false;
//    }
//    if (users[username].password != password) {
//        std::cout << "Incorrect password." << std::endl;
//        return false;
//    }
//    currentUser = username;
//    std::cout << "User with username '" << username << "' logged in successfully." << std::endl;
//    return true;
//}
//
//void TestingSystem::startTesting(const std::string& category) {
//    if (currentUser.empty()) {
//        std::cout << "Please log in first." << std::endl;
//        return;
//    }
//    std::cout << "Starting test in category: " << category << std::endl;
//    // Perform testing logic here
//}
//
//







//#ifndef TESTING_SYSTEM_H
//#define TESTING_SYSTEM_H
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//class User {
//public:
//    User(std::string name, std::string address, std::string phone_number, std::string login, std::string password)
//        : name_(name), address_(address), phone_number_(phone_number), login_(login), password_(password) {}
//
//    std::string getName() const { return name_; }
//    std::string getAddress() const { return address_; }
//    std::string getPhoneNumber() const { return phone_number_; }
//    std::string getLogin() const { return login_; }
//    std::string getPassword() const { return password_; }
//
//private:
//    std::string name_;
//    std::string address_;
//    std::string phone_number_;
//    std::string login_;
//    std::string password_;
//};
//
//class Test {
//public:
//    Test(std::string category, std::string question, std::string answer)
//        : category_(category), question_(question), answer_(answer) {}
//
//    std::string getCategory() const { return category_; }
//    std::string getQuestion() const { return question_; }
//    std::string getAnswer() const { return answer_; }
//
//private:
//    std::string category_;
//    std::string question_;
//    std::string answer_;
//};
//
//class TestingSystem {
//public:
//    void registerUser(std::string name, std::string address, std::string phone_number, std::string login, std::string password);
//    void loginUser(std::string login, std::string password);
//    void startTesting(std::string category);
//
//private:
//    std::vector<User> users_;
//    std::map<std::string, std::string> loggedInUsers_;
//    std::vector<Test> tests_;
//    std::map<std::string, std::vector<Test>> testCategories_;
//
//    bool isLoginUnique(std::string login) const;
//};
//
//#endif // TESTING_SYSTEM_H
//    