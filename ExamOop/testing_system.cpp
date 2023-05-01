#include "testing_system.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <cstring>
#include <openssl/evp.h>

// User implementation

User::User(const std::string& username, const std::string& password, const std::string& name, const std::string& address, const std::string& phone_number)
    : username_(username), name_(name), address_(address), phone_number_(phone_number) {
    // Encrypt password using SHA256 hash function
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(mdctx, password.c_str(), password.length());
    EVP_DigestFinal_ex(mdctx, hash, &hash_len);
    EVP_MD_CTX_free(mdctx);

    std::stringstream ss;
    for (unsigned int i = 0; i < hash_len; i++) {
        ss << std::hex << static_cast<int>(hash[i]);
    }
    password_ = ss.str();
}

const std::string& User::get_username() const {
    return username_;
}

const std::string& User::get_password() const {
    return password_;
}

const std::string& User::get_name() const {
    return name_;
}

const std::string& User::get_address() const {
    return address_;
}

const std::string& User::get_phone_number() const {
    return phone_number_;
}

// Admin implementation

Admin::Admin(const std::string& username, const std::string& password)
    : username_(username) {
    // Encrypt password using SHA256 hash function
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(mdctx, password.c_str(), password.length());
    EVP_DigestFinal_ex(mdctx, hash, &hash_len);
    EVP_MD_CTX_free(mdctx);

    std::stringstream ss;
    for (unsigned int i = 0; i < hash_len; i++) {
        ss << std::hex << static_cast<int>(hash[i]);
    }
    password_ = ss.str();
}

void Admin::add_user(const User& user) {
    users_[user.get_username()] = user;
}

void Admin::remove_user(const std::string& username) {
    users_.erase(username);
}

void Admin::modify_user(const User &
