#include <SFML/Graphics.hpp>
#include <iostream>
#include <span>
#include <string>
#include <vector>

namespace {
void run([[maybe_unused]] std::span<std::string_view const> args) {
	auto window = sf::RenderWindow{
		sf::VideoMode{1280, 720},
		"Hello Window",
	};

	auto circle = sf::CircleShape{50.0f, 60};
	auto window_extent = sf::Vector2f{static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)};
	circle.setPosition(window_extent * 0.5f);
	circle.setFillColor(sf::Color::Yellow);
	circle.setOrigin({circle.getRadius(), circle.getRadius()});

	while (window.isOpen()) {
		auto event = sf::Event{};
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed: return;
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape) { return; }
				break;
			}
			default: break;
			}
		}

		// tick scene

		// draw scene
		window.clear();
		window.draw(circle);
		window.display();
	}
}
} // namespace

int main(int argc, char** argv) {
	auto vec = std::vector<std::string_view>{};
	for (int i = 0; i < argc; ++i) { vec.push_back(argv[i]); }
	run(vec);
}
