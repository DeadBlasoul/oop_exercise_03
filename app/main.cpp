#include <iostream>
#include <string>
#include <utility>
#include <memory>

#include <point.hpp>
#include <figure.hpp>

template<typename _Callable, class... Args>
void action(_Callable callable, Args&&... args) {
    callable(std::forward<Args>(args)...);
}

void to_upper(std::string& str) {
    for (auto& c : str) {
        c = ::toupper(c);
    }
}

int main() {
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    auto constexpr get    = "GET";
    auto constexpr insert = "INSERT";
    auto constexpr print  = "PRINT";
    auto constexpr remove = "REMOVE";
    auto constexpr exit   = "EXIT";

    using figure2d = figure<point2d>;

    std::vector<figure2d*> figures;
    figures.emplace_back(new hexagon{ {0, 0}, 3 });
    figures.emplace_back(new pentagon{ {0, 0}, 3 });
    figures.emplace_back(new rhombus{ {0,0}, 2, 4 });

    string input;
    while (cin >> input) {
        to_upper(input);

        if (input == get) {
            size_t ix;
            cin >> ix;
            if (ix >= figures.size()) {
                cout << "out of range" << endl;
                continue;
            }

            cout << *figures[ix] << endl;
        }
        else if (input == insert) {
            auto constexpr pentagon_type = "PENTAGON";
            auto constexpr hexagon_type = "HEXAGON";
            auto constexpr rhombus_type = "RHOMBUS";

            size_t ix;
            string type;
            cin >> ix >> type;
            if (ix > figures.size()) {
                cout << "out of range" << endl;
                continue;
            }
            to_upper(type);


            if (type == pentagon_type) {
                auto fig = new pentagon;
                cin >> *fig;
                figures.emplace(figures.begin() + ix, fig);
            }
            else if (type == hexagon_type) {
                auto fig = new hexagon;
                cin >> *fig;
                figures.emplace(figures.begin() + ix, fig);
            }
            else if (type == rhombus_type) {
                auto fig = new hexagon;
                cin >> *fig;
                figures.emplace(figures.begin() + ix, fig);
            }
            else {
                cout << "unknown type" << endl;
            }
        }
        else if (input == print) {
            for (size_t i = 0; i < figures.size(); ++i) {
                cout << '[' << i << "] " << *figures[i] << endl;
            }
        }
        else if (input == remove) {
            size_t ix;
            cin >> ix;
            if (ix >= figures.size()) {
                cout << "out of range" << endl;
                continue;
            }

            delete figures[ix];
            figures.erase(figures.begin() + ix);
        }
        else if (input == exit) {
            break;
        }
        else {
            cout << "unknown command" << endl;
        }
    }

    for (auto& ptr : figures) {
        delete ptr;
    }

    return 0;
}
