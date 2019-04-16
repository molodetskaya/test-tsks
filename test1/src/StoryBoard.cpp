#include "StoryBoard.hpp"


Note::Note(){
    static int autoincrement = 0;
    mId = ++autoincrement;
}

Note::Note(std::string title, std::string text, std::vector<std::string> tags)
    : Note() {
    mTitle = title;
    mText = text;
    mTags = tags;
}

int Note::GetId() const {
    return mId;
}

const std::string& Note::GetTitle() const {
    return mTitle;
}

const std::string& Note::GetText() const {
    return mText;
}

const std::vector<std::string>& Note::GetTags() const {
    return mTags;
}

void StoryBoard::AddNote(std::shared_ptr<Note> note) {
    mStoryTitle.emplace(note->GetTitle(), note);
    mStoryText.emplace(note->GetText(), note);
    for (auto& tag: note->GetTags()) {
        mStoryTags.emplace(tag, note);
    }
}

void StoryBoard::DeleteNoteFromConcreteMap(unordered_multimap & map, const std::string& searchStr, int id) {
    size_t count = map.count(searchStr);
    if (count<=1){
        map.erase(searchStr);
    } else {
        auto list = map.equal_range(searchStr);
        auto pos = std::find_if(list.first, list.second,
                                [&](std::pair<std::string, std::shared_ptr<Note>> i){
                                    return bool(i.second->GetId() == id);
                                });
        if (pos!=list.second) {
            map.erase(pos);
        }
    }
}

void StoryBoard::DeleteNote(std::shared_ptr<Note> note) {
    DeleteNoteFromConcreteMap(mStoryTitle, note->GetTitle(), note->GetId());
    DeleteNoteFromConcreteMap(mStoryText, note->GetText(), note->GetId());
    for (auto& tag: note->GetTags()) {
        DeleteNoteFromConcreteMap(mStoryTags, tag, note->GetId());
    }
}

std::pair<StoryBoard::iterator, StoryBoard::iterator> StoryBoard::SearchTitle (std::string search) {
    return mStoryTitle.equal_range(search);
}

std::pair<StoryBoard::iterator, StoryBoard::iterator> StoryBoard::SearchText (std::string search) {
    return mStoryText.equal_range(search);
}

std::pair<StoryBoard::iterator, StoryBoard::iterator> StoryBoard::SearchTags (std::string search) {
    return mStoryTags.equal_range(search);
}