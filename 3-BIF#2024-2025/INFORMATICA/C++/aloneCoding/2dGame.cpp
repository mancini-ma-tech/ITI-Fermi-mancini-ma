#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

class GameEngine2D
{
protected:
    bool isRunning;
    int screenWidth, screenHeight;
    std::vector<std::string> screenBuffer;

public:
    GameEngine2D(int width, int height) : screenWidth(width), screenHeight(height), isRunning(false)
    {
        screenBuffer.resize(screenHeight, std::string(screenWidth, ' '));
    }

    void start()
    {
        isRunning = true;
        while (isRunning)
        {
            handleInput();
            update();
            render();
            std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS
        }
    }

    void stop()
    {
        isRunning = false;
    }

protected:
    virtual void handleInput()
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'q')
                stop(); // Press 'q' to quit
        }
    }

    virtual void update()
    {
        // Game logic goes here
    }

    virtual void render()
    {
        system("cls"); // Clear console (Windows-specific)
        for (const auto &line : screenBuffer)
        {
            std::cout << line << '\n';
        }
    }

    void draw(int x, int y, char ch)
    {
        if (x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
        {
            screenBuffer[y][x] = ch;
        }
    }

    void clearScreen()
    {
        for (auto &line : screenBuffer)
        {
            line.assign(screenWidth, ' ');
        }
    }
};

class My2DGame : public GameEngine2D
{
private:
    int playerX, playerY;
    int score;
    int obstacleX, obstacleY;
    int timer;

public:
    My2DGame(int width, int height)
        : GameEngine2D(width, height), playerX(width / 2), playerY(height / 2), score(0), timer(0)
    {
        srand(static_cast<unsigned>(time(0)));
        spawnObstacle();
    }

protected:
    void handleInput() override
    {
        if (_kbhit())
        {
            char key = _getch();
            switch (key)
            {
            case 'w':
                playerY--;
                break;
            case 's':
                playerY++;
                break;
            case 'a':
                playerX--;
                break;
            case 'd':
                playerX++;
                break;
            case 'q':
                stop();
                break;
            }
        }
    }

    void update() override
    {
        // Keep player within bounds
        if (playerX < 0)
            playerX = 0;
        if (playerX >= screenWidth)
            playerX = screenWidth - 1;
        if (playerY < 0)
            playerY = 0;
        if (playerY >= screenHeight)
            playerY = screenHeight - 1;

        // Move obstacle
        obstacleY++;
        if (obstacleY >= screenHeight)
        {
            spawnObstacle();
            score++; // Increment score when the obstacle is avoided
        }

        // Check collision
        if (playerX == obstacleX && playerY == obstacleY)
        {
            std::cout << "Game Over! Final Score: " << score << "\n";
            stop();
        }

        // Increment timer
        timer++;
    }

    void render() override
    {
        clearScreen();
        draw(playerX, playerY, '@');     // Draw player
        draw(obstacleX, obstacleY, '#'); // Draw obstacle
        GameEngine2D::render();
        std::cout << "Score: " << score << " | Timer: " << timer / 60 << "s\n";
    }

private:
    void spawnObstacle()
    {
        obstacleX = rand() % screenWidth;
        obstacleY = 0; // Start at the top of the screen
    }
};

int main()
{
    My2DGame game(40, 20);
    game.start();
    return 0;
}