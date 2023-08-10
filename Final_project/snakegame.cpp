#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Snake{
    private:
        bool gameOver;
        const int width = 60;
        const int height = 20;
        int x, y, fruitX, fruitY, score;
        int tailX[100], tailY[100];
        int ntail;
        string fruit;
        enum eDirection {STOP = 0,LEFT, RIGHT, UP, DOWN};
        eDirection dir;
    public:
        Snake();
        void Start();
        void Draw();
        void Input();
        void Logic();
        void Setup();
};

Snake :: Snake(){
    fruit = "*";
}

void Snake::Start(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
}

void Snake::Setup(){
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Snake::Draw(){
    cout << " -> Welcome to snake Game <- " << endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos;
    cursorPos.X = 0;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(hConsole, cursorPos);

    for (int i = 0; i < width +2 ; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height ; i++){
        for (int j = 0 ; j < width ; j++)
        {
          if (j == 0)
            cout << "#";

          if (i == y && j == x)
            cout << "O";

          else if (i == fruitY && j == fruitX)
            cout << fruit;

          else{
            bool print = false;
            for (int k = 0; k < ntail; k++){
              if (tailX[k] == j && tailY[k] == i){
                cout << "O";
                print = true;
              }
            }
            if(!print)
                cout<<" ";
        }

          if (j == width - 1)
            cout << "#";
          }
            cout << endl;
        }
    for (int i = 0; i < width + 2; i++){
            cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void Snake::Input() {
  // Check if a key has been pressed.
  if (_kbhit()) {
    // Get the key that was pressed.
    int c = _getch();

    // Switch on the key that was pressed.
    switch (c) {
      case KEY_LEFT:
        // Move the snake left.
        dir = LEFT;
        break;
      case KEY_RIGHT:
        // Move the snake right.
        dir = RIGHT;
        break;
      case KEY_UP:
        // Move the snake up.
        dir = UP;
        break;
      case KEY_DOWN:
        // Move the snake down.
        dir = DOWN;
        break;
      case 'x':
        // Exit the game.
        gameOver = true;
        break;
    }
  };[p-]
}


void Snake::Logic(){
    // The previous x and y coordinates of the snake's head.
  int prevX = tailX[0];
  int prevY = tailY[0];

  // The previous x and y coordinates of the second tail segment.
  int prev2X, prev2Y;

  // Update the x and y coordinates of the snake's head.
  tailX[0] = x;
  tailY[0] = y;

  // For each tail segment after the first one...
  for (int i = 1; i < ntail; i++) {
    // Set the x and y coordinates of the tail segment to the previous x and y coordinates of the head.
    prev2X = tailX[i];
    prev2Y = tailY[i];

    // Set the x and y coordinates of the head to the previous x and y coordinates of the tail segment.
    tailX[i] = prevX;
    tailY[i] = prevY;

    // Set the previous x and y coordinates of the head to the previous x and y coordinates of the second tail segment.
    prevX = prev2X;
    prevY = prev2Y;
  }

  // Move the snake's head in the specified direction.
  switch (dir) {
    case LEFT:
      x--;
      break;
    case RIGHT:
      x++;
      break;
    case UP:
      y--;
      break;
    case DOWN:
      y++;
      break;
    default:
      break;
  }

  // Check if the snake has hit the edge of the screen.
  if (x >= width) x = 0; else if (x < 0) x = width - 1;
  if (y >= height) y = 0; else if (y < 0) y = height - 1;

  // Check if the snake has hit its own tail.
  for (int i = 0; i < ntail; i++) {
    if (tailX[i] == x && tailY[i] == y) {
      gameOver = true;
    }
  }

  // Check if the snake has eaten the fruit.
  if (x == fruitX && y == fruitY) {
    score += 10;
    fruitX = rand() % width;
    fruitY = rand() % height;
    ntail++;
  }
}

int main(){
    Snake snake;
    snake.Start();
    return 0;
}
