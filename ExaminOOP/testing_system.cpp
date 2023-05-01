#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "testing_system.h"

void printOptions() {
    std::cout << "�������� �����:" << std::endl;
    std::cout << "1. ��������������� ������ ������������." << std::endl;
    std::cout << "2. �����." << std::endl;
    std::cout << "3. ������ ������������." << std::endl;
    std::cout << "4. ���������� ���������� �����." << std::endl;
    std::cout << "5.�����." << std::endl;
}

void saveUserDatabase(/*const std::unordered_map<std::string,*/ UserInfo& userDatabase) 
{
    std::ofstream fout("user_database.txt");
    fout << userDatabase.username << " " << userDatabase.address<<" " << userDatabase.password<<" " << userDatabase.phoneNumber<<" ";
    /*for (const auto& user : userDatabase) {
        fout << user.first << " " << user.second.fullName << " " << user.second.homeAddress << " " << user.second.phoneNumber << " " << user.second.password << std::endl;
    }*/
    fout.close(); // ��������� ���� ����� ������
}

void saveAdminDatabase(/*const std::unordered_map<std::string,*/ UserInfo& adminDatabase) {
    std::ofstream fout("admin_database.txt"); 
   fout << adminDatabase.fullName << " " << adminDatabase.category <<" ";
        /*{
        fout << admin.first << " " << admin.second.fullName << " " << admin.second.homeAddress << " " << admin.second.phoneNumber << " " << admin.second.password << std::endl;
    }*/
    fout.close(); // ��������� ���� ����� ������
}

void TestingSystem::registerUser(const std::string& username, const UserInfo& info, const std::string& password) {
    if (validateUsername(username)) {
        UserInfo newUser = info;
        newUser.password = password;
        m_userDatabase[username] = newUser;
    }
    else {
        std::cout << "��� ������������ ��� ������. ����������, �������� ������ ��� ������������." << std::endl;
    }
}


void TestingSystem::logoutUser() {
    m_currentUser = "";
    std::cout << "����� �������." << std::endl;
}

bool TestingSystem::loginUser(const std::string& username, const std::string& password) {
    auto user = m_userDatabase.find(username);

    if (user != m_userDatabase.end() && user->second.password == password) {
        m_currentUser = username;
        std::cout << "����������� �������." << std::endl;
        return true;
    }
    else {
        std::cout << "�������� ��� ������������ ��� ������. ����������, ���������� ��� ���." << std::endl;
        return false;
    }
}
void TestingSystem::startTesting(const std::string& category) {
    if (m_currentUser.empty()) {
        std::cout << "�� ������ ��������������, ����� ������ ����." << std::endl;
        return;
    }


    std::cout << "��������� ���� � ��������� " << category << "..." << std::endl;

    
        int score = 0;
    m_testResults.push_back(TestResult{ category, score });
}

void TestingSystem::viewTestResults() {
    if (m_currentUser.empty()) {
        std::cout << "�� ������ ����� � �������, ����� ����������� ���������� �����." << std::endl;
        return;
    }

    std::cout << "���������� ����� ��� ������������ " << m_currentUser << ":" << std::endl;

    for (const auto& result : m_testResults) {
        std::cout << "���������: " << result.category << ", ����: " << result.score << std::endl;
    }
}

bool TestingSystem::validateUsername(const std::string& username) const {
    return m_userDatabase.find(username) == m_userDatabase.end();
}


int main() {

    setlocale(LC_ALL, "Russian");

    TestingSystem testingSystem;

    int mode = 0;




    while (true) {
        if (mode == 0) {
            std::cout << "�������� �����:" << std::endl;
            std::cout << "1. �����." << std::endl;
            std::cout << "2. �����������e." << std::endl;

            int choice = 0;
            std::cin >> choice;

            if (choice == 1) {
                mode = 1;
                continue;
            }
            else if (choice == 2) {
                mode = 2;
                continue;
            }
            else {
                std::cout << "�������� �����. ����������, ���������� ��� ���." << std::endl;
                continue;
            }
        }

        if (mode == 1) {
            std::string username, password;
            std::cout << "������� ��� ��������������: ";
            std::cin >> username;
            std::cout << "������� ������ ��������������: ";
            std::cin >> password;

            if (username == "1" && password == "2") {
                int choice = 0;
                while (true) {
                    printOptions();
                    std::cin >> choice;

                    if (choice == 1) {
                        std::string fullName, homeAddress, phoneNumber, username, password;
                        std::cout << "������� ������ ���: ";
                        std::getline(std::cin >> std::ws, fullName);
                        std::cout << "������� �������� �����: ";
                        std::getline(std::cin >> std::ws, homeAddress);
                        std::cout << "������� ����� ��������: ";
                        std::getline(std::cin >> std::ws, password);
                        std::cout << "������� ��� ������������: ";
                        std::getline(std::cin >> std::ws, username);
                        std::cout << "������� ������: ";
                        std::getline(std::cin >> std::ws,phoneNumber);

                        std::string category;
                        UserInfo in = {homeAddress,username,password,phoneNumber  };
                        UserInfo on = {fullName,password,category };
                        testingSystem.registerUser( username, in, phoneNumber);
                        saveUserDatabase(in);
                        saveAdminDatabase( on);
                        //!!!! ����� �������� ��� ������ 
                        //testingSystem.registerUser(fullName, username, password);

                    }
                    else if (choice == 2) {
                        std::string username, password;
                        std::cout << "������� ��� ������������: ";
                        std::getline(std::cin >> std::ws, username);
                        std::cout << "������� ������: ";
                        std::getline(std::cin >> std::ws, password);

                        testingSystem.loginUser(username, password);
                    }
                    else if (choice == 3) {
                        std::string category;
                        std::cout << "������� ���������: ";
                        std::getline(std::cin >> std::ws, category);

                        testingSystem.startTesting(category);
                    }
                    else if (choice == 4) {
                        // View test results
                        std::cout << "�������� ����������� �����..." << std::endl;
                        testingSystem.viewTestResults();
                    }
                    else if (choice == 5) {
                        break;
                    }
                    else {
                        std::cout << "�������� �����. ����������, ���������� ��� ���." << std::endl;
                        continue;
                    }
                }
            }
            else {
                std::cout << "�������� ��� ������������ ��� ������. ����������, ���������� ��� ���." << std::endl;
                continue;
            }
        }
        else if (mode == 2) {
            int choice = 0;
            while (true) {
                printOptions();
                std::cin >> choice;

                if (choice == 1) {
                    std::cout << "��� ����� �������� ������ ��� ���������������." << std::endl;
                    continue;
                }
                else if (choice == 2) {
                    std::string username, password;
                    std::cout << "������� ��� ������������: ";
                    std::getline(std::cin >> std::ws, username);
                    std::cout << "������� ������: ";
                    std::getline(std::cin >> std::ws, password);

                    testingSystem.loginUser(username, password);
                }
                else if (choice == 3) {
                    std::string category;
                    std::cout << "������� ���������: ";
                    std::getline(std::cin >> std::ws, category);

                    testingSystem.startTesting(category);
                }
                else if (choice == 4) {
                    // View test results
                    std::cout << "�������� ����������� �����..." << std::endl;
                    testingSystem.viewTestResults();
                }
                else if (choice == 5) {
                    break;
                }
                else {
                    std::cout << "�������� �����. ����������, ���������� ��� ���." << std::endl;
                    continue;
                }
            }
        }
    }




    return 0;

}











//#include "testing_system.h"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
////using namespace std;
//
//int main() {
//    TestingSystem testingSystem;
//    testingSystem.registerUser("John Smith", "123 Main Street", "555-1234", "jsmith", "password");
//    testingSystem.loginUser("jsmith", "password");
//    testingSystem.startTesting("Math");
//    return 0;
//}
//
//void TestingSystem::registerUser(std::string name, std::string address, std::string phone_number, std::string login, std::string password) {
//    if (isLoginUnique(login)) {
//        User newUser(name, address, phone_number, login, password);
//        users_.push_back(newUser);
//        std::cout << "User successfully registered." << std::endl;
//    }
//    else {
//        std::cout << "Login already exists. Please choose a different login." << std::endl;
//    }
//}
//
//bool TestingSystem::isLoginUnique(std::string login) const {
//    for (const auto& user : users_) {
//        if (user.getLogin() == login) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void TestingSystem::loginUser(std::string login, std::string password) {
//    for (const auto& user : users_) {
//        if (user.getLogin() == login && user.getPassword() == password) {
//            loggedInUsers_[login] = password;
//            std::cout << "User logged in." << std::endl;
//            return;
//        }
//    }
//    std::cout << "Invalid login or password." << std::endl;
//}
//
//void TestingSystem::startTesting(std::string category) {
//    if (loggedInUsers_.empty()) {
//       std::cout << "Please log in to start testing." << std::endl;
//        return;
//    }
//    if (testCategories_.count(category) == 0) {
//        std::cout << "Invalid category. Please choose a different category." << std::endl;
//        return;
//    }
//    for (const auto& test : testCategories_[category]) {
//        std::string answer;
//        std::cout << test.getQuestion() << std::endl;
//        std::cin >> answer;
//        if (answer == test.getAnswer()) {
//            std::cout << "Correct answer!" << std::endl;
//        }
//        else {
//            std::cout << "Incorrect answer." << std::endl;
//        }
//    }
//}
