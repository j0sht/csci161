class Flag {
 public:
    // Create a Flag object
    Flag(int width, int height, char symbol);
    // Create a Flag object with wide = height = 1 and symbol = '*'
    Flag();
    // Properly destroy a flag
    ~Flag();
    // Get width of Flag object
    int getWidth();
    // Get height of Flag object
    int getHeight();
    // Get the display symbol of the flag object
    char getSymbol();
    void resize(int newWidth, int newHeight);
    void changeSymbol(char newSymbol);
    // Calculate the number of characters needed
    //  to draw this flag
    int calculate();
    // Draw the flag
    void draw();
    // Return true if this Flag object uses more than 25
    //  characters to draw, otherwise return false
    bool bigFlag();
 private:
    int width, height;
    char symbol;
};
