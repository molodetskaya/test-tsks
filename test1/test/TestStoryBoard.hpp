#pragma once
#include <utility>
#include "StoryBoard.hpp"

class TestStoryBoard {
  public:
    void Run();
  private:
    void GenerateNotes();
    void PrintNotes(std::pair<StoryBoard::iterator, StoryBoard::iterator>& list);

    StoryBoard storyBoard;
};