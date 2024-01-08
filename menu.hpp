#pragma once
#include <string>
#include <vector>
#include <functional>

class MenuOption {
public:
    std::string name;
    std::function<void()> action;

    MenuOption(std::string name, std::function<void()> action)
        : name(std::move(name)), action(std::move(action)) {}
};

class Menu {
private:
    std::string title;
    std::vector<MenuOption> options;
    bool is_open;

public:
    Menu(std::string title) : title(std::move(title)), is_open(false) {}

    void add_option(MenuOption option) {
        options.push_back(std::move(option));
    }

    void open() {
        is_open = true;
        while (is_open) {
            std::cout << title << std::endl;
            for (size_t i = 0; i < options.size(); ++i) {
                std::cout << (i + 1) << ". " << options[i].name << std::endl;
            }
            std::cout << "Select an option: ";
            int choice;
            std::cin >> choice;
            if (choice > 0 && choice <= static_cast<int>(options.size())) {
                options[choice - 1].action();
            } else {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    }

    void close() {
        is_open = false;
    }
};