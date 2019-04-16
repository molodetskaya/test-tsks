#pragma once
#include <unordered_map>
#include <string>
#include <set>
#include <vector>
#include "User.hpp"

class SocialNetwork {
  public:
    bool AddUser(User user);
    void DeleteUser(User user);
    User& SearchUserById(int id);
    std::vector<User> SearchUserByName(std::string name);
    std::vector<User> SearchUserByAge(int age);
    std::vector<User> SearchUserByHobbies(std::vector<std::string> hobbies);
    const std::set<int>& GetFriendsOfUser(int id);
    void MakeFriends(int fr1, int fr2);
  private:
    std::unordered_map<int, User> mUsers;
    std::unordered_multimap<int, int> mUserAges;
    std::unordered_multimap<std::string, int> mUserNames;
    std::unordered_map<std::string, std::set<int>> mUserHobbies;
};