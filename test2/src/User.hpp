#pragma once
#include <string>
#include <set>

enum Gender {
  Mail,
  Femail
};

class User {
  public:
    User();
    User(int mId, std::string name, int age, int height, Gender gender, std::set<std::string> hobbies);

    int GetId() const;
    const std::string& GetName() const;
    int GetAge() const;
    int GetHeight() const;
    const std::set<std::string>& GetHobbies() const;
    const std::set<int>& GetFriends() const;
    void AddFriend(int id);
    void DeleteFriend(int id);

  private:
    int mId;
    std::string mName;
    int mAge;
    int mHeight;
    Gender mGender;
    std::set<std::string> mHobbies;
    std::set<int> mFriends;
};