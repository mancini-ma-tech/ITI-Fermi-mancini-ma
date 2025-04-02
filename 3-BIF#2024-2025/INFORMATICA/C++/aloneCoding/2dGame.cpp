#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <conio.h> // Per _kbhit() e _getch() su Windows
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif
using namespace std;

class GameEngine2D
{
protected:
    bool isRunning;
    int screenWidth, screenHeight;
    vector<string> screenBuffer;

public:
    GameEngine2D(int width, int height) : screenWidth(width), screenHeight(height), isRunning(false)
    {
        screenBuffer.resize(screenHeight, string(screenWidth, ' '));
    }

    void start()
    {
        isRunning = true;
        while (isRunning)
        {
            this->handleInput(); // Explicitly call the method
            update();
            render();
            this_thread::sleep_for(chrono::milliseconds(16)); // ~60 FPS
        }
    }

    void stop()
    {
#ifdef _WIN32
        if (_kbhit())
        {
            char key = _getch();
#else
        int key = -1;
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
        key = getchar();
        tcsetattr(STDIN_FILENO, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, flags);
        if (key != EOF)
#endif
            {
                isRunning = false;
            }
        }

        virtual void handleInput()
        {
            // Default implementation for base class
        }

        virtual void update()
        {
            // Logica di gioco
        }

        virtual void render()
        {
            clearConsole(); // Pulisce la console
            for (const auto &line : screenBuffer)
            {
                cout << line << '\n';
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

    private:
        void clearConsole()
        {
            // Alternativa a system("cls") per Dev-C++
            cout << "\033[2J\033[1;1H"; // Sequenza ANSI per pulire la console
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
            // Mantieni il giocatore nei limiti
            if (playerX < 0)
                playerX = 0;
            if (playerX >= screenWidth)
                playerX = screenWidth - 1;
            if (playerY < 0)
                playerY = 0;
            if (playerY >= screenHeight)
                playerY = screenHeight - 1;

            // Muovi l'ostacolo
            obstacleY++;
            if (obstacleY >= screenHeight)
            {
                spawnObstacle();
                score++; // Incrementa il punteggio quando l'ostacolo viene evitato
            }

            // Controlla collisione
            if (playerX == obstacleX && playerY == obstacleY)
            {
                cout << "Game Over! Final Score: " << score << "\n";
                stop();
            }

            // Incrementa il timer
            timer++;
        }

        void render() override
        {
            clearScreen();
            draw(playerX, playerY, '@');     // Disegna il giocatore
            draw(obstacleX, obstacleY, '#'); // Disegna l'ostacolo
            GameEngine2D::render();
            cout << "Score: " << score << " | Timer: " << timer / 60 << "s\n";
        }

    private:
        void spawnObstacle()
        {
            obstacleX = rand() % screenWidth;
            obstacleY = 0; // Inizia dalla parte superiore dello schermo
        }
    };

    int main()
    {
        My2DGame game(40, 20);
        game.start();
        return 0;
    }