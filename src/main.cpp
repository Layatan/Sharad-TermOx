#include <iostream>
#include <vector>
#include <string>

#include <ox/ox.hpp>
#include <signals_light/signal.hpp>

#include "./components/ui/ascii_art.hpp"
#include "./components/menu_logic.hpp"

using namespace ox;

class Sharad : public Widget {
private:
    enum class PAGE { MAIN_MENU, IN_GAME };
    PAGE currentPage = PAGE::MAIN_MENU;

    Point location = {0,0};
    Area minWindow = {190, 50};

public:
    Sharad() : Widget{FocusPolicy::Strong, SizePolicy::flex()}{
        std::cout << "Game logic here\n";
    }

    void key_press(Key k) override {
        switch (k) {
        default:{
            if (currentPage == PAGE::MAIN_MENU) currentPage = PAGE::IN_GAME;
            else currentPage = PAGE::MAIN_MENU;
        }
        break;
        }
    }

    void paint(Canvas c) {
        if (this->size.width < minWindow.width || this->size.height < minWindow.height) {
            std::u32string tmpErr = U"Terminal window is too small! Zoom Out [ctrl -/+]";
            Painter{c}[{.x=(this->size.width - (int)tmpErr.size())/2, .y=(this->size.height/2)-1}] << (tmpErr | Brush{.background = XColor::BrightRed} | Trait::Blink );
            return;
        }


        switch (currentPage){
        case PAGE::MAIN_MENU:{
            Painter{c}[{.x = this->size.width - 10, .y = this->size.height - 1}] << "Main Menu"; //for debugging

            auto art = asciiArt::logo.artwork; location = {0, 0};
            for (auto nl_at = art.find('\n'); nl_at != std::string::npos; nl_at = art.find('\n')) {
                Painter{c}[{location}] << (art.substr(0, nl_at) | Trait::Dim);
                art = art.substr(nl_at + 1);
                location.y += 1;
            }
            art = asciiArt::title.artwork; location = {this->size.width-asciiArt::title.width-10, 5};
            for (auto nl_at = art.find('\n'); nl_at != std::string::npos; nl_at = art.find('\n')) {
                Painter{c}[{location}] << (art.substr(0, nl_at) | Trait::Dim);
                art = art.substr(nl_at + 1);
                location.y += 1;
            }
        } break;
        
        case PAGE::IN_GAME:{
                Painter{c}[{.x = this->size.width - 10, .y = this->size.height - 1}] << "In Game";
        } break;
        }
    }
};

int main() {
    auto head = Sharad{};

    return Application{head}.run();
}