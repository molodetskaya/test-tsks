#include <iostream>
#include "TestSocialNetwork.hpp"
#include "SocialNetwork.hpp"
#include "User.hpp"

void PrintUsers(std::vector<User> & list) {
    for (auto user: list) {
        std::cout<<user.GetId()<<" - "<<user.GetName()<<" - "<<user.GetAge()<<" - "<<user.GetHeight()<<" - ";
        for (const auto& hobby: user.GetHobbies()) {
            std::cout<<hobby<<" - ";
        }
        std::cout<<std::endl;
    }
}
void TestSocialNetwork::Run() {
    User user1(1, "User1", 10, 100, Gender::Femail, {"hobby1", "hobby3", "hobby2"});
    User user2(2, "User2", 10, 200, Gender::Mail, {"hobby2", "hobby3", "hobby5"});
    User user3(3, "User3", 11, 300, Gender::Mail, {"hobby1", "hobby3"});
    User user4(4, "User4", 10, 100, Gender::Femail, {"hobby1", "hobby5"});
    User user5(5, "User4", 10, 100, Gender::Mail, {"hobby1", "hobby3", "hobby5"});
    User user6(6, "", 10, 100, Gender::Mail, {"hobby1", "hobby3", "hobby5"});

    SocialNetwork sn;
    sn.AddUser(user1);
    sn.AddUser(user2);
    sn.AddUser(user3);
    sn.AddUser(user4);
    sn.AddUser(user5);
    if (sn.AddUser(user6)) {
      std::cout<<"Add user with empty name - Error occured"<<std::endl;
    }

    sn.MakeFriends(1, 2);
    sn.MakeFriends(1, 3);
    sn.MakeFriends(1, 4);
    sn.MakeFriends(1, 5);
    sn.MakeFriends(4, 2);
    sn.MakeFriends(4, 3);

    auto list = sn.SearchUserByAge(10);
    std::cout<<"SearchUserByAge 10"<<std::endl;
    PrintUsers(list);
    if (list.size() != 4) {
       std::cout<<"Error occured"<<std::endl;
    }
    auto list2 = sn.SearchUserByHobbies({"hobby1", "hobby3"});
    std::cout<<"\nSearchUserByHobbies hobby1 and hobby3"<<std::endl;
    PrintUsers(list2);
    if (list2.size() != 3) {
       std::cout<<"Error occured"<<std::endl;
    }
    auto list1 = sn.SearchUserByName("User4");
    std::cout<<"\nSearchUserByName User4"<<std::endl;
    PrintUsers(list1);
    if (list1.size() != 2) {
       std::cout<<"Error occured"<<std::endl;
    }
    int id = list1.begin()->GetId();
    sn.DeleteUser(*list1.begin());
    sn.DeleteUser(*list1.begin());
    
    auto list3 = sn.SearchUserByName("User4");
    std::cout<<"\nSearchUserByName User4"<<std::endl;
    PrintUsers(list3);
    if (list3.size() != 1) {
       std::cout<<"Error occured"<<std::endl;
    }

    auto friends = sn.GetFriendsOfUser(1);
    std::cout<<"\nGetFriendsOfUser 1"<<std::endl;
    for (const auto& pos: friends) {
        std::cout<<pos<<" - ";
    }
    std::cout<<std::endl;
    if (friends.size() != 3) {
       std::cout<<"Error occured"<<std::endl;
    }
    if (friends.find(id) != friends.end()) {
       std::cout<<"Error occured"<<std::endl;
    }

}