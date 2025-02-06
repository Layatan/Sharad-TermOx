#include <iostream>
#include <vector>
#include <string>

#include <ox/ox.hpp>
#include <signals_light/signal.hpp>

class nav_Menu : public ox::Column<std::vector<ox::Label>> {
public:
    sl::Signal<void(int)> clicked;
    int currHighlight = 0;

    nav_Menu(std::vector<std::string> MenuItems = {}){
        for (auto const item : MenuItems) {
            children.push_back(ox::Label{{
                            .text = "  " + item,
                            .align = ox::Label::Align::Left,
                        }} | ox::SizePolicy::fixed(2));
        }
    };
};