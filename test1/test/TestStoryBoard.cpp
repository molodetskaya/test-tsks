#include "TestStoryBoard.hpp"
#include <memory>

void TestStoryBoard::PrintNotes(std::pair<StoryBoard::iterator, StoryBoard::iterator>& list) {
    for (auto obj = list.first; obj != list.second; ++obj){
        std::cout<<"\nId   : "<<obj->second->GetId()<<"\n"<<
                   "Title: "<<obj->second->GetTitle()<<"\n"<<
                   "Text:  "<<obj->second->GetText()<<std::endl;
        std::cout<<"Tags:  ";
        for (auto& tag : obj->second->GetTags()) {
            std::cout<<tag<<", ";
        }
        std::cout<<std::endl;
    }
}

void TestStoryBoard::Run() {
    GenerateNotes();

    auto listDelete = storyBoard.SearchText(std::string("Text2"));
    auto ptr = listDelete.first->second;
    storyBoard.DeleteNote(ptr);
    storyBoard.DeleteNote(ptr);

    auto listTitle = storyBoard.SearchTitle(std::string("Title3"));
    std::cout<<"\nSearch Result Title"<<std::endl;
    if(std::distance(listTitle.first, listTitle.second) != 1) {
        std::cout<<"Error occured"<<std::endl;
    }
    PrintNotes(listTitle);

    auto listTitle1 = storyBoard.SearchTitle(std::string("Title2"));
    std::cout<<"\nSearch Result Title1"<<std::endl;
    if(std::distance(listTitle1.first, listTitle1.second) != 0) {
        std::cout<<"Error occured"<<std::endl;
    }
    PrintNotes(listTitle1);

    auto listText = storyBoard.SearchText(std::string("Text2"));
    std::cout<<"\nSearch Result Text"<<std::endl;
    if(std::distance(listText.first, listText.second) != 0) {
        std::cout<<"Error occured"<<std::endl;
    }
    PrintNotes(listText);

    auto listTags = storyBoard.SearchTags(std::string("tag2"));
    std::cout<<"\nSearch Result Tags"<<std::endl;
    if(std::distance(listTags.first, listTags.second) != 3) {
        std::cout<<"Error occured"<<std::endl;
    }
    PrintNotes(listTags);
}

void TestStoryBoard::GenerateNotes() {

    storyBoard.AddNote(std::make_shared<Note>("Title", "Text", std::vector<std::string>({"tag1", "tag2"})));
    storyBoard.AddNote(std::make_shared<Note>("Title1", "Text1", std::vector<std::string>({"tag1", "tag3", "tag2"})));
    storyBoard.AddNote(std::make_shared<Note>("Title2", "Text2", std::vector<std::string>({"tag11", "tag2"})));
    storyBoard.AddNote(std::make_shared<Note>("Title3", "Text3", std::vector<std::string>({"tag1", "tag11", "tag3"})));
    storyBoard.AddNote(std::make_shared<Note>("Title4", "Text4", std::vector<std::string>({"tag4", "tag2"})));

    std::cout<<"sizeof(Story)"<<"--"<<sizeof(Note)<<"--\n";
    std::cout<<"sizeof(StoryBoard)"<<"--"<<sizeof(StoryBoard)<<"--\n";
    std::cout<<"sizeof(storyBoard)"<<"--"<<sizeof(storyBoard)<<"--\n";
    // std::cout<<"sizeof(storyBoard.mStoryTitle)"<<"--"<<sizeof(storyBoard.mStoryTitle)<<"--\n";
    // std::cout<<"sizeof(storyBoard.mStoryTags)"<<"--"<<sizeof(storyBoard.mStoryTags)<<"--\n";
}