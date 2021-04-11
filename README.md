# arduino-calculator
Калькулятор на Ардуино (Keypad_I2C, LiquidCrystal_I2C)

# Зависимости

Исходный код  
https://github.com/FlyingDaniil/calculator-keypad-lcd-i2c

Библиотека для пленочной клавиатуры (Keypad_I2C - PCF8574, PCF8574A and PCF8575)  
https://github.com/joeyoung/arduino_keypads


# Компоненты

В качестве платы для датчиков используется YFRobot Sensor Shield:

![image](https://user-images.githubusercontent.com/4146998/114298374-c08f1b80-9abe-11eb-81ff-a05ada86b761.png)

Она к сожалению малоизвестная и не ясно где ее описание.

Кратко о ней:

COM это RS232-порт. Довольно малоинтересная штука.  
Пины A6 и A7 достались от Arduino Nano.  
Разъем питания пока не ясный, для входа или вывода...  
IIC это шина I2C. Набор пинов произвольный к сожалению (стандарта нет).  
SD это разъем для подключения SD-карт ридера.  
APC220 разъем для подключения модуля беспроводной связи.  

Вот картинка другого подобного шилда:

![image](https://user-images.githubusercontent.com/4146998/114298430-0b109800-9abf-11eb-8a96-bddfe1072094.png)
