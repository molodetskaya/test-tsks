#include "User.hpp"
#include <iostream>
User::User(): mId(0) {

}
User::User(int id, std::string name, int age, int height, Gender gender, std::set<std::string> hobbies)
    : mId(id), mName(name), mAge(age), mHeight(height),
    mGender(gender), mHobbies(hobbies), mFriends() {

}
int User::GetId() const {
    return mId;
}
const std::string& User::GetName() const {
    return mName;
}
int User::GetAge() const {
    return mAge;
}
int User::GetHeight() const {
    return mHeight;
}
const std::set<std::string>& User::GetHobbies() const {
    return mHobbies;
}
const std::set<int>& User::GetFriends() const {
    return mFriends;
}
void User::AddFriend(int id) {
    mFriends.emplace(id);
}
void User::DeleteFriend(int id) {
    mFriends.erase(id);
}
