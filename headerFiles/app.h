



                //  Function Prototype


string inputString(); // Function to take input

void printHeader(int headerX, int headerY);                     // Functoin to print header
void resizeConsoleToMaxScreenSize();                            // Function to Set the size of console
void gotoxy(int x, int y);                                      // Functiom to place cusor on desire place
void emptyBox(int emptyBoxX, int emptyBoxY);                    // Function to print empty box
void printBoxes(int emptyBoxX[], int emptyBoxY[], int noOfBox); // Function to print input grid boxes

void printNo(string value, string base, int emptyBoxX[], int emptyBoxY[], int noOfBox); // Function to print No
void printYes(string value, string base, int emptyBoxX[], int emptyBoxY[], int noOfBox);// Function to print Yes
void eraseWrongInput(string value, string base, int emptyBoxX[], int emptyBoxY[], int noOfBox);// Function to Erase Wrong inputs

void errorMessage(); // Display error message
void correctMessage(); // Display correct message
void emptyLine(); // Remove a line

void printAllDataPage(int headerX, int headerY, int textX, int textY, string binary[], string octal[], string decimal[], string hexaDecimal[], int dataIndex);// Print see data page
void printTableHeader(int textX, int textY); // print table header
void printTableData(int textX, int textY, string binary[], string octal[], string decimal[], string hexaDecimal[], int dataIndex); //Print all data

void mainMenu(int menuX, int menuY);// Function to print main menu

void cursor_show();// Function to show cursor
void cursor_hide();// Function to hide cursor


// Functon Defination


void cursor_hide()
{
    /*
        For Removing Blinking Cursor on Screen
    */
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

void cursor_show()
{
    /*
        For Removing Blinking Cursor on Screen
    */
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}



// Function to bring cusor at certain location
void gotoxy(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

// To set the console size
void resizeConsoleToMaxScreenSize()
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    COORD coord;
    coord.X = screenWidth / 8;
    coord.Y = screenHeight / 16;

    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = coord.X - 1;
    rect.Bottom = coord.Y - 1;

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);

    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);
}

// Print no if input format not match
void printNo(string value, string base, int emptyBoxX[], int emptyBoxY[], int noOfBox)
{
    if (!checkBinary(value, base))
    {
        gotoxy(emptyBoxX[2] + 19, emptyBoxY[2] + 2);
        errorMessage();
    }
    if (!checkOctal(value, base))
    {
        gotoxy(emptyBoxX[3] + 18, emptyBoxY[3] + 2);
        errorMessage();
    }
    if (!checkDecimal(value, base))
    {
        gotoxy(emptyBoxX[4] + 20, emptyBoxY[4] + 2);
        errorMessage();
    }
    if (!checkHexaDecimal(value, base))
    {
        gotoxy(emptyBoxX[5] + 24, emptyBoxY[5] + 2);
        errorMessage();
    }
}

// Print yes if input format is match
void printYes(string value, string base, int emptyBoxX[], int emptyBoxY[], int noOfBox)
{
    if (checkBinary(value, base))
    {
        gotoxy(emptyBoxX[2] + 19, emptyBoxY[2] + 2);
        correctMessage();
    }
    else if (checkOctal(value, base))
    {
        gotoxy(emptyBoxX[3] + 18, emptyBoxY[3] + 2);
        correctMessage();
    }
    else if (checkDecimal(value, base))
    {
        gotoxy(emptyBoxX[4] + 20, emptyBoxY[4] + 2);
        correctMessage();
    }
    else if (checkHexaDecimal(value, base))
    {
        gotoxy(emptyBoxX[5] + 24, emptyBoxY[5] + 2);
        correctMessage();
    }
}

// Function to Erase Wrong inputs
void eraseWrongInput(string value, string base, int emptyBoxX[], int emptyBoxY[], int noOfBox)
{
    gotoxy(emptyBoxX[0] + 30, emptyBoxY[0] + 2);
    emptyLine();
    gotoxy(emptyBoxX[1] + 43, emptyBoxY[1] + 2);
    emptyLine();
    gotoxy(emptyBoxX[2] + 19, emptyBoxY[2] + 2);
    emptyLine();
    gotoxy(emptyBoxX[3] + 18, emptyBoxY[3] + 2);
    emptyLine();
    gotoxy(emptyBoxX[4] + 20, emptyBoxY[4] + 2);
    emptyLine();
    gotoxy(emptyBoxX[5] + 24, emptyBoxY[5] + 2);
    emptyLine();

    // For Incorrect Inputs
    gotoxy(emptyBoxX[1] + 30, emptyBoxY[1] + 8);
    emptyLine();
    gotoxy(emptyBoxX[1] + 30, emptyBoxY[1] + 11);
    emptyLine();
}

// Print empty box
void emptyBox(int emptyBoxX, int emptyBoxY)
{
    gotoxy(emptyBoxX, emptyBoxY);
    cout << "\e[1;34m.------------------------------------------------------------------.";
    gotoxy(emptyBoxX, emptyBoxY + 1);
    cout << "|                                                                  |";
    gotoxy(emptyBoxX, emptyBoxY + 2);
    cout << "|                                                                  |";
    gotoxy(emptyBoxX, emptyBoxY + 3);
    cout << "|                                                                  |";
    gotoxy(emptyBoxX, emptyBoxY + 4);
    cout << "'------------------------------------------------------------------'\e[0;33m";
}

// Remove a line
void emptyLine()
{
    cout << "                                ";
}

// Print input grid 
void printBoxes(int emptyBoxX[], int emptyBoxY[], int noOfBox)
{
    //    int emptyBoxX[6] = {10,10,90, 90, 90, 90}, emptyBoxY[6] = { 18,24,18, 24, 29,34};
    emptyBox(emptyBoxX[0], emptyBoxY[0]);
    gotoxy(emptyBoxX[0] + 3, emptyBoxY[0] + 2);
    cout << "Enter some Integer value : ";
    emptyBox(emptyBoxX[1], emptyBoxY[1]);
    gotoxy(emptyBoxX[1] + 3, emptyBoxY[1] + 2);
    cout << "Enter the base of given Integer value : ";
    emptyBox(emptyBoxX[2], emptyBoxY[2]);
    gotoxy(emptyBoxX[2] + 3, emptyBoxY[2] + 2);
    cout << "Binary Format : ";
    emptyBox(emptyBoxX[3], emptyBoxY[3]);
    gotoxy(emptyBoxX[3] + 3, emptyBoxY[3] + 2);
    cout << "Octal Format : ";
    emptyBox(emptyBoxX[4], emptyBoxY[4]);
    gotoxy(emptyBoxX[4] + 3, emptyBoxY[4] + 2);
    cout << "Decimal Format : ";
    emptyBox(emptyBoxX[5], emptyBoxY[5]);
    gotoxy(emptyBoxX[5] + 3, emptyBoxY[5] + 2);
    cout << "HexaDecimal Format : ";
}

// Print Header
void printHeader(int headerX, int headerY)
{
    gotoxy(headerX, headerY);
    cout << "\e[1;34m#########################################################################";
    gotoxy(headerX, headerY + 1);
    cout << "#                                                                       #";
    gotoxy(headerX, headerY + 2);
    cout << "#                                                                       #";
    gotoxy(headerX, headerY + 3);
    cout << "#   \e[1;32m           __ __  __ ______  ____   ___   ____ ____               \e[1;34m  #";
    gotoxy(headerX, headerY + 4);
    cout << "#   \e[1;32m           || ||\\ || | || | ||     // \\\\ ||    || \\\\           \e[1;34m     #";
    gotoxy(headerX, headerY + 5);
    cout << "#   \e[1;32m           || ||\\\\||   ||   ||==  (( ___ ||==  ||_//              \e[1;34m  #";
    gotoxy(headerX, headerY + 6);
    cout << "#   \e[1;32m           || || \\||   ||   ||___  \\\\_|| ||___ || \\\\           \e[1;34m     #";
    gotoxy(headerX, headerY + 7);
    cout << "#   \e[1;32m                                                                   \e[1;34m #";
    gotoxy(headerX, headerY + 8);
    cout << "#   \e[1;32m    ___   ___   __  __ __ __  ____ ____   __  __   ___   __  __     \e[1;34m#";
    gotoxy(headerX, headerY + 9);
    cout << "#   \e[1;32m   //    // \\\\  ||\\ || || || ||    || \\\\ (( \\ ||  // \\\\  ||\\ ||  \e[1;34m   #";
    gotoxy(headerX, headerY + 10);
    cout << "#  \e[1;32m   ((    ((   )) ||\\\\|| \\\\ // ||==  ||_//  \\\\  || ((   )) ||\\\\||  \e[1;34m   #";
    gotoxy(headerX, headerY + 11);
    cout << "#  \e[1;32m    \\\\__  \\\\_//  || \\||  \\V/  ||___ || \\\\ \\_)) ||  \\\\_//  || \\||\e[1;34m     #";
    gotoxy(headerX, headerY + 12);
    cout << "#                                                                       #";
    gotoxy(headerX, headerY + 13);
    cout << "#                                                                       #";
    gotoxy(headerX, headerY + 14);
    cout << "#########################################################################\033[0m";
}


// To input a string
string inputString()
{
    cursor_show();
    string value = "";
    getline(cin, value);
    cursor_hide();
    return value;
}



// Display No
void errorMessage()
{
    cout << "\e[0;31mNo\e[0m";
}
// Display Yes
void correctMessage()
{
    cout << "\e[1;32mYes\e[0m";
}

// SHow data page
void printAllDataPage(int headerX, int headerY, int textX, int textY, string binary[], string octal[], string decimal[], string hexaDecimal[], int dataIndex)
{
    printHeader(headerX, headerY);
    printTableHeader(textX, textY);
    printTableData(textX, textY, binary, octal, decimal, hexaDecimal, dataIndex);
    gotoxy(textX+40, textY + 15);
    cout << "\e[1;34mPress Any kesy to move Back\e[0m";
    getch();
}

// To print table Header
void printTableHeader(int textX, int textY)
{
    int width=32;
    gotoxy(textX, textY);
    cout << setw(width) << left << "  \e[0;33mBinary" << setw(width) << left << "       Octal" << setw(width) << left << "     Decimal" << setw(width) << left << "   HexaDecimal\e[0m";
}

// To print all data
void printTableData(int textX, int textY, string binary[], string octal[], string decimal[], string hexaDecimal[], int dataIndex)
{
    for (int counter = 0; counter < dataIndex; counter = counter + 1)
    {

        gotoxy(textX, textY + 2 + counter);
        cout << "\e[1;34m  " << setw(30) << left << binary[counter] << setw(30) << left << octal[counter] << setw(30) << left << decimal[counter] << setw(30) << left << hexaDecimal[counter] << "\e[0m";
    }
}

// to print main menu
void mainMenu(int menuX, int menuY)
{
    gotoxy(menuX, menuY);
    cout << "1.\e[0;33m Input Page.\e[0m";

    gotoxy(menuX, menuY + 2);
    cout << "2. \e[0;33mOutput Page.\e[0m";

    gotoxy(menuX, menuY + 4);
    cout << "3.\e[0;33m Exit.\e[0m";
}