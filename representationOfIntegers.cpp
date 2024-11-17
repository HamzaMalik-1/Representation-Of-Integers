#include"./headerFiles/calculation.h"
#include"./headerFiles/app.h"


// Main FUnction
main()
{
    cursor_hide();
    string value = "";
    string base = "";
    string hexaDecimal[10] = {""}, decimal[10] = {""}, octal[10] = {""}, binary[10] = {""};
    int dataIndex = 0;
    bool loopState = true, mainLoopState = true, selectionLoopState = true;
    int emptyBoxX[6] = {10, 10, 90, 90, 90, 90}, emptyBoxY[6] = {18, 24, 18, 24, 29, 34}, noOfBox = 6;
    int headerX = 45, headerY = 2;
    int menuX = 75, menuY = 20;
    string option = "";
    resizeConsoleToMaxScreenSize();
    // for printAllDataPage
    int textX = 30, textY = 20;
    while (mainLoopState)
    {
        loopState = true, mainLoopState = true, selectionLoopState = true;
        while (selectionLoopState)
        {
            system("cls");
            printHeader(headerX, headerY);
            mainMenu(menuX, menuY);
            gotoxy(menuX, menuY + 8);
            emptyLine();
            gotoxy(menuX, menuY + 8);
            cout << "\e[1;34mSelect an option : \e[1;32m";
            gotoxy(menuX + 19, menuY + 8);
            option = inputString();
            // cout<<"\e[0;33m";
            if (option < "1" && option > "3")
            {
                gotoxy(menuX, menuY + 8);
                cout << "Select Correct Option!";
            }
            else
            {
                selectionLoopState = false;
            }
        }
        system("cls");
        if (option == "1")
        {
            printHeader(headerX, headerY);
            printBoxes(emptyBoxX, emptyBoxY, noOfBox);

            while (loopState)
            {
                cout << "\e[1;32m";
                gotoxy(emptyBoxX[0] + 30, emptyBoxY[0] + 2);
                value = inputString();
                cout << "\e[1;32m";
                gotoxy(emptyBoxX[1] + 43, emptyBoxY[1] + 2);
                base = inputString();

                printNo(value, base, emptyBoxX, emptyBoxY, noOfBox);
                printYes(value, base, emptyBoxX, emptyBoxY, noOfBox);

                if (checkBinary(value, base) || checkOctal(value, base) || checkDecimal(value, base) || checkHexaDecimal(value, base))
                {
                    gotoxy(emptyBoxX[1] + 30, emptyBoxY[1] + 8);
                    cout << "\e[1;34mCorrect Input!\e[0;33m";
                    gotoxy(emptyBoxX[1] + 30, emptyBoxY[1] + 11);
                    cout << "\e[1;34mPress Any key to move back\e[0;33m";
                    getch();
                    eraseWrongInput(value, base, emptyBoxX, emptyBoxY, noOfBox);
                    loopState = false;
                    selectionLoopState = true;
                    // Calculation
                    // Pointer implementation is good for this piece of code as it help to do it in separate function
                    if (base == "2")
                    {
                        decimal[dataIndex] = convertToDecimal(value, stoi(base));
                    }
                    else if (base == "8")
                    {
                        decimal[dataIndex] = convertToDecimal(value, stoi(base));
                    }
                    else if (base == "16")
                    {
                        decimal[dataIndex] = convertToDecimal(value, stoi(base));
                    }
                    // when base== "10"
                    else
                    {
                        decimal[dataIndex] = value;
                    }

                    if (checkBinary(value, base))
                    {
                        binary[dataIndex] = value;
                        octal[dataIndex] = decimalToOtherBase(decimal[dataIndex], 8);
                        hexaDecimal[dataIndex] = decimalToOtherBase(decimal[dataIndex], 16);
                    }
                    else if (checkOctal(value, base))
                    {
                        binary[dataIndex] = decimalToOtherBase(decimal[dataIndex], 2);
                        octal[dataIndex] = value;
                        hexaDecimal[dataIndex] = decimalToOtherBase(decimal[dataIndex], 16);
                    }
                    else if (checkDecimal(value, base))
                    {
                        binary[dataIndex] = decimalToOtherBase(decimal[dataIndex], 2);
                        octal[dataIndex] = decimalToOtherBase(decimal[dataIndex], 8);
                        hexaDecimal[dataIndex] = decimalToOtherBase(decimal[dataIndex], 16);
                    }
                    else if (checkHexaDecimal(value, base))
                    {
                        binary[dataIndex] = decimalToOtherBase(decimal[dataIndex], 2);
                        octal[dataIndex] = decimalToOtherBase(decimal[dataIndex], 8);
                        hexaDecimal[dataIndex] = value;
                    }
                    dataIndex = dataIndex + 1;
                }
                else
                {
                    gotoxy(emptyBoxX[1] + 30, emptyBoxY[1] + 8);
                    cout << "\e[0;31mIncorrect Input!\e[0m";
                    gotoxy(emptyBoxX[1] + 30, emptyBoxY[1] + 11);
                    cout << "\e[0;31mPress Any key to input again.\e[0m";
                    getch();
                    eraseWrongInput(value, base, emptyBoxX, emptyBoxY, noOfBox);
                }
            }
        }
        system("cls");

        if (option == "2")
        {
            system("cls");
            printAllDataPage(headerX, headerY, textX, textY, binary, octal, decimal, hexaDecimal, dataIndex);
            selectionLoopState = true;
            
        }

        // To terminate the program
        if (option == "3")
        {
            return 0;
        }
    }
    getch();
}


