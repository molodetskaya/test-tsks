#pragma once
#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

class Note {
  public:
    Note();
    Note(std::string title, std::string text, std::vector<std::string> tags);

    int GetId() const;
    const std::string& GetTitle() const;
    const std::string& GetText() const;
    const std::vector<std::string>& GetTags() const;

  private:
    int mId;
    std::string mTitle;
    std::string mText;
    std::vector<std::string> mTags;
};

class StoryBoard {
  public:
    typedef std::unordered_multimap<std::string, std::shared_ptr<Note>> unordered_multimap;
    typedef unordered_multimap::iterator iterator;

    void AddNote(std::shared_ptr<Note> note);
    void DeleteNote(std::shared_ptr<Note> note);
    std::pair<iterator, iterator> SearchTitle (std::string search);
    std::pair<iterator, iterator> SearchText (std::string search);
    std::pair<iterator, iterator> SearchTags (std::string search);
  
  private:
    void DeleteNoteFromConcreteMap(unordered_multimap & map, const std::string& searchStr, int id);    
  
  private:
    unordered_multimap mStoryTitle;
    unordered_multimap mStoryText;
    unordered_multimap mStoryTags;
};
