#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

const int width = 800;
const int height = 600;
const int blockSize = 20;

struct SnakeSegment {
    int x, y;
    SnakeSegment(int x, int y) : x(x), y(y) {}
};

class Snake {
private:
    std::vector<SnakeSegment> body;
    int dirX = 1, dirY = 0;

public:
    Snake() {
        body.emplace_back(width / 2, height / 2);
    }

    void move() {
        for (int i = body.size() - 1; i > 0; --i)
            body[i] = body[i - 1];
        body[0].x += dirX * blockSize;
        body[0].y += dirY * blockSize;
    }

    void grow() {
        body.push_back(body.back());
    }

    void changeDirection(int x, int y) {
        if (dirX != -x && dirY != -y) {
            dirX = x;
            dirY = y;
        }
    }

    void draw(sf::RenderWindow& window) {
        sf::RectangleShape segmentShape(sf::Vector2f(blockSize - 2, blockSize - 2));
        segmentShape.setFillColor(sf::Color::Green);
        for (auto& seg : body) {
            segmentShape.setPosition(seg.x, seg.y);
            window.draw(segmentShape);
        }
    }

    bool checkCollision() {
        for (int i = 1; i < body.size(); ++i)
            if (body[0].x == body[i].x && body[0].y == body[i].y)
                return true;
        return body[0].x < 0 || body[0].y < 0 || body[0].x >= width || body[0].y >= height;
    }

    bool isOnBody(int x, int y) {
        for (auto& seg : body)
            if (seg.x == x && seg.y == y)
                return true;
        return false;
    }

    sf::Vector2i getHeadPosition() {
        return { body[0].x, body[0].y };
    }
};

sf::Vector2i generateSafeFood(Snake& snake) {
    sf::Vector2i foodPos;
    do {
        foodPos = sf::Vector2i(
            (1 + rand() % ((width / blockSize) - 2)) * blockSize,
            (1 + rand() % ((height / blockSize) - 2)) * blockSize
        );
    } while (snake.isOnBody(foodPos.x, foodPos.y));
    return foodPos;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(width, height), "Snake Game");
    window.setFramerateLimit(10);

    Snake snake;
    sf::Vector2i food = generateSafeFood(snake);

    sf::RectangleShape foodShape(sf::Vector2f(blockSize - 2, blockSize - 2));
    foodShape.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    snake.changeDirection(0, -1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  snake.changeDirection(0, 1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  snake.changeDirection(-1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) snake.changeDirection(1, 0);

        snake.move();

        if (snake.getHeadPosition().x == food.x && snake.getHeadPosition().y == food.y) {
            snake.grow();
            food = generateSafeFood(snake);
        }

        if (snake.checkCollision())
            window.close();

        window.clear();
        snake.draw(window);

        foodShape.setPosition(food.x, food.y);
        window.draw(foodShape);

        window.display();
    }

    return 0;
}
