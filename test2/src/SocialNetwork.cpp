#include "SocialNetwork.hpp"
#include <iostream>
#include <list>
#include <memory>
#include <algorithm>

bool SocialNetwork::AddUser(User user) {
    if(user.GetName() != "" && mUsers.emplace(user.GetId(), user).second) {
        mUserAges.emplace(user.GetAge(), user.GetId());
        mUserNames.emplace(user.GetName(), user.GetId());
        for (const auto & hobby: user.GetHobbies()) {
            mUserHobbies.emplace(hobby, std::set<int>());
            mUserHobbies.find(hobby)->second.emplace(user.GetId());
        }
        return true;
    }
    return false;
}
template<typename T>
void DeleteUserFromMap(std::unordered_multimap<T, int> & map, const T& searchStr, int id) {
    size_t count = map.count(searchStr);
    if (count<=1){
        map.erase(searchStr);
    } else {
        auto list = map.equal_range(searchStr);
        auto pos = std::find_if(list.first, list.second,
                                [&](std::pair<T, int> i){
                                    return bool(i.second == id);
                                });
        map.erase(pos);
    }
}
void SocialNetwork::DeleteUser(User user) {
    if (mUsers.erase(user.GetId())) {
        for (auto id: user.GetFriends()){
            SearchUserById(id).DeleteFriend(user.GetId());
        }
        DeleteUserFromMap(mUserAges, user.GetAge(), user.GetId());
        DeleteUserFromMap<std::string>(mUserNames, user.GetName(), user.GetId());
        for (const auto & hobby: user.GetHobbies()) {
            mUserHobbies.find(hobby)->second.erase(user.GetId());
        }
    }
}
User& SocialNetwork::SearchUserById(int id) {
    return mUsers.find(id)->second;
}
std::vector<User> SocialNetwork::SearchUserByName(std::string name) {
    auto list = mUserNames.equal_range(name);
    std::vector<User> users;
    for(auto pos = list.first; pos != list.second; pos++) {
        users.push_back(SearchUserById(pos->second));
    }
    return users;
}
std::vector<User> SocialNetwork::SearchUserByAge(int age) {
    auto list = mUserAges.equal_range(age);
    std::vector<User> users(mUserAges.count(age));
    int i=0;
    for(auto pos = list.first; pos != list.second; pos++, i++) {
        users[i] = SearchUserById(pos->second);
    }
    return users;
}
std::vector<User> SocialNetwork::SearchUserByHobbies(std::vector<std::string> hobbies) {
    std::vector<int> users_1;
    auto list1 = mUserHobbies.find(*hobbies.begin())->second;
    std::vector<int> users_2(list1.begin(), list1.end());
    auto start = hobbies.begin() + 1;
    for (auto pos = start; pos != hobbies.end(); ++pos) {
        std::sort(users_2.begin(), users_2.end());
        std::set<int> list2 = mUserHobbies.find(*pos)->second;
        std::set_intersection(users_2.begin(), users_2.end(), list2.begin(), list2.end(), std::back_inserter(users_1));
        std::swap(users_1, users_2);
        users_1.clear();
    }
    std::vector<User> users;
    for (auto pos: users_2) {
        users.push_back(SearchUserById(pos));
    }
    return users;
}
const std::set<int>& SocialNetwork::GetFriendsOfUser(int id) {
    return mUsers.find(id)->second.GetFriends();
}
void SocialNetwork::MakeFriends(int fr1, int fr2){
    SearchUserById(fr1).AddFriend(fr2);
    SearchUserById(fr2).AddFriend(fr1);
}