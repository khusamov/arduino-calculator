//библиотеки
#include <LiquidCrystal_I2C.h>
#include <Keypad_I2C.h>
#include <Keypad.h>
#include <Wire.h>
#include <String.h>

const uint8_t KEYPAD_ADDRESS = 0x20;

//ряды и столбцы клавиатуры
const byte ROWS = 4; 
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//пины клавиатуры

byte rowPins[ROWS] = {0, 1, 2, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad

//обьявляем клавиатуру и экран
Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, KEYPAD_ADDRESS ); //  Create the Keypad
LiquidCrystal_I2C lcd(0x27, 16, 2);

long Num1, Num2, Number;
char key, action;
boolean result = false;

void setup() {
  Wire.begin( );                // GDY200622
  kpd.begin( );        // GDY120705
  //включаем экран
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  //ждём и обрабатываем кнопки
  key = kpd.getKey(); //storing pressed key value in a char
  if (key != NO_KEY) DetectButtons();
  if (result == true) CalculateResult();
  //выводим результат
  DisplayResult();
}

//распознавание кнопки
void DetectButtons()
{
  lcd.clear(); 
  if (key == '*') 
  {
    Serial.println ("Button Cancel");
    Number = Num1 = Num2 = 0;
    result = false;
  }

  if (key == '1') 
  { Serial.println ("Button 1");
    if (Number == 0)
      Number = 1;
    else
      Number = (Number * 10) + 1; 
  }

  if (key == '4') 
  { Serial.println ("Button 4");
    if (Number == 0)
      Number = 4;
    else
      Number = (Number * 10) + 4;
  }

  if (key == '7') 
  { Serial.println ("Button 7");
    if (Number == 0)
      Number = 7;
    else
      Number = (Number * 10) + 7; 
  }


  if (key == '0')
  { Serial.println ("Button 0"); 
    if (Number == 0)
      Number = 0;
    else
      Number = (Number * 10) + 0; 
  }

  if (key == '2') 
  { Serial.println ("Button 2");
    if (Number == 0)
      Number = 2;
    else
      Number = (Number * 10) + 2; 
  }

  if (key == '5')
  { Serial.println ("Button 5");
    if (Number == 0)
      Number = 5;
    else
      Number = (Number * 10) + 5;
  }

  if (key == '8')
  { Serial.println ("Button 8");
    if (Number == 0)
      Number = 8;
    else
      Number = (Number * 10) + 8; 
  }


  if (key == '#')
  { Serial.println ("Button Equal");
    Num2 = Number;
    result = true;
  }

  if (key == '3')
  { Serial.println ("Button 3");
    if (Number == 0) Number = 3;
    else Number = (Number * 10) + 3; 
  }

  if (key == '6')
  { Serial.println ("Button 6");
    if (Number == 0) Number = 6;
    else Number = (Number * 10) + 6; 
  }

  if (key == '9')
  { 
    Serial.println ("Button 9");
    if (Number == 0) Number = 9;
    else Number = (Number * 10) + 9; 
  }

  if (key == 'A' || key == 'B' || key == 'C' || key == 'D') 
  {
    Num1 = Number;
    Number = 0;
    if (key == 'A')
    {
      Serial.println ("Суммирование");
      action = '+';
    }
    if (key == 'B')
    {
      Serial.println ("Разность");
      action = '-';
    }
    if (key == 'C')
    {
      Serial.println ("Множение");
      action = '*';
    }
    if (key == 'D')
    {
      Serial.println ("Деление");
      action = '/';
    }

    delay(100);
  }

}

//считаем результат
void CalculateResult()
{
  if (action == '+') Number = Num1 + Num2;

  if (action == '-') Number = Num1 - Num2;

  if (action == '*') Number = Num1 * Num2;

  if (action == '/' && Num2 !=0) Number = Num1 / Num2;
}

//фуркция вывода результата
void DisplayResult()
{
  lcd.setCursor(0, 0);   
  lcd.print(Num1); lcd.print(action); lcd.print(Num2);

  if (result == true)
  {
    lcd.print(" ="); 
    lcd.print(Number);
  }

  lcd.setCursor(0, 1);   
  lcd.print(Number); 
}
